#if !defined(AFX_STRINGEX_H__BF77D132_BDF8_4EF6_87A0_28B744AC94B2__INCLUDED_)
#define AFX_STRINGEX_H__BF77D132_BDF8_4EF6_87A0_28B744AC94B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StringEx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStringEx window

class _COMMON_API CStringEx : public CString
{
// Construction
public:
	CStringEx();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStringEx)
	//}}AFX_VIRTUAL

// Implementation
public:
	bool IsIncludeHTML_Elements(CString strContent="");//����Ƿ����HTML��ǩ�ؼ���
	bool IsStringAllWhiteSpace(CString strContent="");//��� strContent �Ƿ��ǿ��ַ�
	virtual ~CStringEx();

	// Generated message map functions
protected:
	//{{AFX_MSG(CStringEx)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STRINGEX_H__BF77D132_BDF8_4EF6_87A0_28B744AC94B2__INCLUDED_)
