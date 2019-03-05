// ImageListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ImageListCtrl.h"
#include ".\imagelistctrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageListCtrl

CImageListCtrl::CImageListCtrl()
{
	InitData();
}

CImageListCtrl::~CImageListCtrl()
{
}

void CImageListCtrl::InitData()
{
	m_bIsSortAscending = true;//�Ƿ���������
	m_nSortedColumn = -1;//��ǰ�������
}

BEGIN_MESSAGE_MAP(CImageListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CImageListCtrl)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageListCtrl message handlers

int CImageListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	//CreateAndSetImageList(IDB_LISTCTRL);

	return 0;
}

int CImageListCtrl::GetCurSelectedItem()
{
	int nCurSelectedItem = -1;//û���κ�һ�б�ѡ��
	POSITION pos = GetFirstSelectedItemPosition();
	if(pos != NULL)
	{
		nCurSelectedItem = GetNextSelectedItem(pos);
	}
	else
	   TRACE0("No items were selected!\n");

	return nCurSelectedItem;
}

void CImageListCtrl::ClearupColumns()
{
	int nColumn = GetHeaderCtrl()->GetItemCount();
	for(int i=0; i<nColumn; i++)
	{
		DeleteColumn(0);
	}
}

bool CImageListCtrl::ClearupColumnAndItem()//�����������
{
	bool bRet = true;
	//������ǰ����ʾ����
	DeleteAllItems();
	ClearupColumns();
	return bRet;
}

bool CImageListCtrl::SetColumns(CStringArray* pstrArray_Columns)
{
	bool bRet = true;
	//�������ĺϷ���
	if(pstrArray_Columns == NULL)
	{
		AfxMessageBox("��ǰû�� ListCtrl �ؼ�Ҫ��ʾ��ͷ�����ַ���!\n\nAt CImageListCtrl::SetColumns()");
		bRet = false;
		return bRet;
	}
	//��ȡ ListCtrl ����ʾ�����С
	CRect rtArea;
	GetClientRect(rtArea);
	//ƽ������ ListCtrl ÿ���е���ʾ�����С
	int nHeaderCount = (int) pstrArray_Columns->GetSize();
	if(nHeaderCount > 0)
	{
		int nWidth = 0;
		nWidth = rtArea.Width()/nHeaderCount;
		//���� ListCtrl ͷ��������
		for(int i=0; i<nHeaderCount; i++)
		{
			InsertColumn(i, _T(pstrArray_Columns->GetAt(i)), LVCFMT_LEFT, nWidth);
		}
		if (m_clsSortHeader.GetSafeHwnd() != NULL)
			m_clsSortHeader.UnsubclassWindow();
		VERIFY(m_clsSortHeader.SubclassWindow(GetHeaderCtrl()->GetSafeHwnd()));
	}
	bRet = true;
	return bRet;
}

bool CImageListCtrl::AddOneItem(CStringArray* pstrArray_Item)
{
	bool bRet = true;
	//�������ĺϷ���
	if(pstrArray_Item == NULL)
	{
		AfxMessageBox("��ǰû�� ListCtrl �ؼ�Ҫ�����ʾ��1����¼�ַ���!\n\nAt CImageListCtrl::AddOneItem()");
		bRet = false;
		return bRet;
	}
	//��ǰ�ؼ����м���
	int nHeaderCount = GetHeaderCtrl()->GetItemCount();
	//Ҫ�����ؼ�����ַ����м���(����˵����)
	int nCurrentItem_TextCount = (int) pstrArray_Item->GetSize();
	if(nHeaderCount != nCurrentItem_TextCount)
	{
		CString strError= "";
		strError.Format("��ǰ ListCtrl �ؼ���%d��,��Ҫ�����ʾ��1����¼��%d���ַ���!\n2�߲���ȶ�����!", 
						nHeaderCount, nCurrentItem_TextCount);
		strError += "\n\nAt CImageListCtrl::AddOneItem()!";
		AfxMessageBox(strError);
		bRet = false;
		return bRet;
	}
	//��õ�ǰ�м�������(����˵������¼)
	int nItemCount = GetItemCount();
	//�ڿؼ����ݵ�ĩβ����µ�����(����˵��¼)
	InsertItem(nItemCount, _T(pstrArray_Item->GetAt(0)), 1);
	for(int i=1; i<nHeaderCount; i++)
	{
		SetItemText (nItemCount, i, _T(pstrArray_Item->GetAt(i)));
	}
	bRet = true;
	return bRet;
}

void CImageListCtrl::SelectAllItems()
{
	int nItemCount = GetItemCount();
	for(int i=0; i<nItemCount; i++)
	{
		SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);
	}
}

int CImageListCtrl::CreateAndSetImageList(UINT nIDResource)
{
	// load the tree images bitmap and add it to the image list.
	if(m_bitmap.LoadBitmap( nIDResource ) != 0)
	{
		if ( !m_imageList.Create( 16, 16, ILC_COLOR24 | ILC_MASK, 1, 1 ) )
		{
			TRACE0("Failed to create image list.\n");
			return -1;
		}
		m_imageList.Add( &m_bitmap, RGB( 0xff,0x00,0xff ) );
		SetImageList( &m_imageList, LVSIL_SMALL );
	}

	return 0;
}

bool CImageListCtrl::AddSubItem(int nItem, int nSubItem, CString strSubItemText)
{
	bool bRet = true;
	//----------- �������ĺϷ��� ��ʼ ---------------------
	if((nItem < 0) || (nSubItem < 0))
	{
		CString strError= "";
		strError.Format("ListCtrl �ؼ���ļ�¼�������ܸ���!\nItem:%d  Sub Item:%d", 
						nItem, nSubItem);
		strError += "\n\nAt CImageListCtrl::AddSubItem()!";
		AfxMessageBox(strError);
		bRet = false;
		return bRet;
	}
	//��ǰ�ؼ����м���
	int nHeaderCount = GetHeaderCtrl()->GetItemCount();
	if(nSubItem >= nHeaderCount)//Ҫ���������������е�����
	{
		CString strError= "";
		strError.Format("��ǰ ListCtrl �ؼ���%d��,����Ҫ�����ʾ������Ϊ��%d��!\n���ߴ���ǰ�߶�����!", 
						nHeaderCount, nSubItem+1);
		strError += "\n\nAt CImageListCtrl::AddSubItem()!";
		AfxMessageBox(strError);
		bRet = false;
		return bRet;
	}
	//----------- �������ĺϷ��� ���� ---------------------
	if(nSubItem == 0)
	{
		//��õ�ǰ�м�������(����˵������¼)
		int nItemCount = GetItemCount();
		if(nItem < nItemCount)
		{//��¼�Ѿ����ڣ�����ˢ������
			SetItemText(nItem, nSubItem, strSubItemText);
		}
		else
		{//�¼�¼
			//�ڿؼ����ݵ�ĩβ����µ�����(����˵��¼)
			InsertItem(nItemCount, strSubItemText, 1);
		}
	}
	else
	{
		SetItemText(nItem, nSubItem, strSubItemText);
	}
	return bRet;
}
