// FileMonDoc.cpp :  CFileMonDoc ���ʵ��
//

#include "stdafx.h"
#include "FileMon.h"

#include "FileMonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileMonDoc

IMPLEMENT_DYNCREATE(CFileMonDoc, CDocument)

BEGIN_MESSAGE_MAP(CFileMonDoc, CDocument)
END_MESSAGE_MAP()


// CFileMonDoc ����/����

CFileMonDoc::CFileMonDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CFileMonDoc::~CFileMonDoc()
{
}

BOOL CFileMonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CFileMonDoc ���л�

void CFileMonDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CFileMonDoc ���

#ifdef _DEBUG
void CFileMonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFileMonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFileMonDoc ����
