// FileMon.h : FileMon Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h�� 
#endif

#include "resource.h"       // ������


// CFileMonApp:
// �йش����ʵ�֣������ FileMon.cpp
//

class CFileMonApp : public CWinApp
{
public:
	CFileMonApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	// ��ʼ������
	BOOL Init(void);
};

extern CFileMonApp theApp;
