// ErrorMsgDlg.h : header file
//

#if !defined(AFX_ERRORMSGDLG_H__11EB699B_4EB5_4957_8D30_836BE43EC514__INCLUDED_)
#define AFX_ERRORMSGDLG_H__11EB699B_4EB5_4957_8D30_836BE43EC514__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CErrorMsgDlg dialog

class _COMMON_API CErrorMsgDlg : public CDialog
{
// Construction
public:
	CErrorMsgDlg(CWnd* pParent = NULL);	// standard constructor

public:
	BOOL Init(void);

	void SetBugManagerURL(CString strBugManagerURL="") { m_strBugManagerURL = strBugManagerURL; };
	void SetErrorMsg(CString strErrorMsg="") { m_strErrorMsg = strErrorMsg; };
	void SetIsSendError(BOOL bIsSendError=FALSE) { m_bIsSendError = bIsSendError; };
	//strErrorPos ������λ�ã�strPrefix ��������ǰ׺
	void SetLastErrorMsg(CString strErrorPos="", CString strPrefix="");

private:
	CString m_strBugManagerURL;//�Ѵ����͵������ߴ���BUG�ռ�URL��ַ
	CString m_strErrorMsg;// ��������ʱ����ʾ��Ϣ���������
	BOOL	m_bIsSendError;//�Ƿ��ʹ�����Ϣ�������ߴ�

// Dialog Data
	//{{AFX_DATA(CErrorMsgDlg)
	enum { IDD = IDD_ERRORMSG_DIALOG };
	CEdit	m_editErrorMsg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CErrorMsgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CErrorMsgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERRORMSGDLG_H__11EB699B_4EB5_4957_8D30_836BE43EC514__INCLUDED_)
