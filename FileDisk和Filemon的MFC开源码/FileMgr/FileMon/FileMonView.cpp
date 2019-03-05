// FileMonView.cpp : CFileMonView ���ʵ��
//

#include "stdafx.h"
#include "FileMon.h"

#include "FileMonDoc.h"
#include "FileMonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define MAX_MSG_COUNT		10000	//��ʾ������Ϣ����
#define MAX_X_POSITION		50000	//�����ʾ����̫��ʱ�����Լ��������������޶�
#define MAX_Y_POSITION		50000
#define ROW_DISTANCE		20		//ÿ�����ֵļ������

// CFileMonView

IMPLEMENT_DYNCREATE(CFileMonView, CView)

BEGIN_MESSAGE_MAP(CFileMonView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFileMonView ����/����

CFileMonView::CFileMonView()
{
	// TODO: �ڴ˴���ӹ������
	Init();
}

CFileMonView::~CFileMonView()
{
	Release();
}

BOOL CFileMonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

BOOL CFileMonView::Init()//��ʼ��
{
	BOOL bRet = FALSE;

	m_nX = 0;
	m_nY = 0;
	m_nCount = 0;
	m_strMsg = "";
	m_bIsFileFilterMsg = FALSE;

	return bRet;
}

void CFileMonView::Release()//�ͷ���Դ
{
}

//��ʾ�ļ�����������⵽���ļ�ϵͳ��Ϣ
void CFileMonView::DisplayFileFilterSystemMsg(CDC* pDC)
{
	/*if ((m_nCount >= MAX_MSG_COUNT) || (m_nY >= MAX_Y_POSITION) )
	{
		Init();
	}
	m_nX = 0;
	m_nY = m_nCount*ROW_DISTANCE;
	pDC->TextOut(m_nX, m_nY, "��ʾ����");
	m_nCount ++;//*/

	BOOL		bIsDisplay = FALSE;
	PENTRY		ptr;
	CString		strMsg = "";
	char		*items[NUMCOLUMNS];
	int			itemcnt = 0;
	CRect		rtText;
	GetClientRect(&rtText);
	// display all items from Stats[] data
	for ( ptr = (PENTRY)g_strStats; (char *)ptr < min(g_strStats+g_dwStatsLen, g_strStats + sizeof (g_strStats)); )
	{
		//strMsg.Format("�����ݣ�%s\n", ptr->text);
		//m_strMsg += strMsg;
		//pDC->TextOut(m_nX, m_nY, m_strMsg);

		size_t len = strlen(ptr->text);
		// Split line into columns
		itemcnt = g_clsFileFilter_Driver.Split( ptr->text, '\t', items );
		if ( itemcnt <= 0 )
			return;
		// Determine Its a new request??
		if ( *items[0] )
		{
			// Its a new request.  Put at end.
			strMsg.Format(_T("Sequence number: %d -- "), ptr->seq );
			m_strMsg += strMsg;
			//strMsg.Format(_T("datatime: %d / perftime: %d / "), ptr->datetime, ptr->perftime );
			//m_strMsg += strMsg;
			// Sequence number if a new item
			if (itemcnt>0 && *items[0] )
			{
				strMsg.Format(_T("Process name: %s -- "), items[0] );
				m_strMsg += strMsg;
			}
			if (itemcnt>1 && *items[1])
			{
				strMsg.Format(_T("Request type: %s -- "), items[1] );
				m_strMsg += strMsg;
			}
			if (itemcnt>2 && *items[2])
			{
				strMsg.Format(_T("Path: %s -- "), items[2] );
				m_strMsg += strMsg;
			}
			if (itemcnt>3 && *items[3])
			{
				strMsg.Format(_T("Additional: %s -- "), items[3] );
				m_strMsg += strMsg;
			}
		}
		else
		{
			if (itemcnt>4 && *items[4])
			{
				strMsg.Format(_T("Result: %s"), items[4] );
				m_strMsg += strMsg;
			}
			m_strMsg += "\n";
		}
		len += 4; len &= 0xFFFFFFFC; // +1 for null-terminator +3 for 32bit alignment
		ptr = (PENTRY)(ptr->text + len);
		bIsDisplay = TRUE;
	}
	pDC->DrawText(m_strMsg, rtText, DT_LEFT | DT_TOP);
	// Empty the buffer
	if (bIsDisplay)
	{
		g_dwStatsLen = 0;
	}
	m_bIsFileFilterMsg = FALSE;
}

// CFileMonView ����
void CFileMonView::OnDraw(CDC* pDC)
{
	CFileMonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (m_bIsFileFilterMsg)
	{
		DisplayFileFilterSystemMsg(pDC);
	}
	else
	{
		CRect		rtText;
		GetClientRect(&rtText);
		pDC->DrawText(m_strMsg, rtText, DT_LEFT | DT_TOP | DT_WORDBREAK);
	}
}


// CFileMonView ��ӡ

BOOL CFileMonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFileMonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��ӡǰ��Ӷ���ĳ�ʼ��
}

void CFileMonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��ӡ������������
}


// CFileMonView ���

#ifdef _DEBUG
void CFileMonView::AssertValid() const
{
	CView::AssertValid();
}

void CFileMonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileMonDoc* CFileMonView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileMonDoc)));
	return (CFileMonDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileMonView ��Ϣ�������
