// MainFrm.h : CMainFrame ��Ľӿ�
//


#pragma once
class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// ����
public:
	UINT_PTR m_nTimer;

// ����
public:
	void InitVariables();//��ʼ������ֵ
	BOOL Init(void);// ��ʼ��
	void Release(void);//�ͷ���Դ

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
};


