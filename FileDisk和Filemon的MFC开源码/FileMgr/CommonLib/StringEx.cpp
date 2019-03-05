// StringEx.cpp : implementation file
//

#include "stdafx.h"
#include "commonlib.h"
#include "StringEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStringEx

CStringEx::CStringEx()
{
}

CStringEx::~CStringEx()
{
}

/////////////////////////////////////////////////////////////////////////////
// CStringEx message handlers

bool CStringEx::IsStringAllWhiteSpace(CString strContent)//��� strContent �Ƿ��ǿ��ַ�
{
	bool bRet = false;

	if(!strContent.IsEmpty())
	{
		strContent.TrimLeft(' ');
		strContent.TrimRight(' ');
		
		if(strContent.IsEmpty())
			bRet = true;
	}

	return bRet;
}

//����Ƿ����HTML��ǩ�ؼ���
bool CStringEx::IsIncludeHTML_Elements(CString strContent)
{
	bool bRet = false;

	if((strContent.Find("<html>") >= 0) || 
		(strContent.Find("</html>") >= 0) || 
		(strContent.Find("<head>") >= 0) || 
		(strContent.Find("</head>") >= 0) || 
		(strContent.Find("<body>") >= 0) || 
		(strContent.Find("</body>") >= 0) || 
		(strContent.Find("<script>") >= 0) || 
		(strContent.Find("</script>") >= 0))
	{
		bRet = true;
	}

	return bRet;
}
