// FileMonView.h : CFileMonView ��Ľӿ�
//


#pragma once


class CFileMonView : public CView
{
protected: // �������л�����
	CFileMonView();
	DECLARE_DYNCREATE(CFileMonView)

// ����
public:
	CFileMonDoc* GetDocument() const;

	int m_nX;//��ʾ�ı���Ϣ����� X ����
	int m_nY;//��ʾ�ı���Ϣ����� Y ����
	int m_nCount;//��ǰ���м����ı���Ϣ
	CString m_strMsg;

private:
	BOOL m_bIsFileFilterMsg;//�Ƿ����ļ�����������������Ϣ

// ����
public:
	BOOL GetIsFileFilterMsg() { return m_bIsFileFilterMsg; } ;
	void SetIsFileFilterMsg(BOOL bIsFileFilterMsg) { m_bIsFileFilterMsg = bIsFileFilterMsg; } ;

	void DisplayFileFilterSystemMsg(CDC* pDC);//��ʾ�ļ�����������⵽���ļ�ϵͳ��Ϣ

	BOOL Init();//��ʼ��
	void Release();//�ͷ���Դ

// ��д
	public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CFileMonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // FileMonView.cpp �ĵ��԰汾
inline CFileMonDoc* CFileMonView::GetDocument() const
   { return reinterpret_cast<CFileMonDoc*>(m_pDocument); }
#endif

