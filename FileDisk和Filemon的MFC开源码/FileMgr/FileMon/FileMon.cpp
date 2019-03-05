// FileMon.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "FileMon.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "FileMonDoc.h"
#include "FileMonView.h"
#include ".\filemon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileMonApp

BEGIN_MESSAGE_MAP(CFileMonApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

// CFileMonApp ����
CFileMonApp::CFileMonApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CFileMonApp ����
CFileMonApp theApp;

// ��ʼ������
BOOL CFileMonApp::Init(void)
{
	BOOL bRet = TRUE;
	// get NT version
	DWORD NTVersion = GetVersion();
	//if( NTVersion >= 0x80000000 )	g_bIsNT = FALSE;
	//else							g_bIsNT = TRUE;
	if( NTVersion >= 0x80000000 )
	{
		g_dlgErrorMsg.SetErrorMsg(ERRMSG_WINVER_FAILURE);
		g_dlgErrorMsg.DoModal();
		bRet = FALSE;
		return bRet;
	}
	else
	{
		//g_dlgErrorMsg.SetErrorMsg(ERRMSG_WINVER_SUCCESS);
		//g_dlgErrorMsg.SetLastErrorMsg(ERRMSG_WINVER_SUCCESS);
		//g_dlgErrorMsg.DoModal();
		TRACE0(ERRMSG_WINVER_SUCCESS);
		TRACE0("\n");
	}

	GetApplicationPath(theApp.m_hInstance, g_strAppPath);

	// determine performance counter frequency
	QueryPerformanceFrequency( &g_PerfFrequency );

	//��ʼ�������ĳ�ʼֵ
	g_cDriveLetter = 'a';
	g_hSys_FileFilter = INVALID_HANDLE_VALUE;
	g_dwCurDriveSet = 0;//GetLogicalDrives();

	return bRet;
}
// CFileMonApp ��ʼ��
BOOL CFileMonApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControls()�����򣬽��޷��������ڡ�
	InitCommonControls();

	CWinApp::InitInstance();

	if (!Init())
	{
		return FALSE;
	}

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)
	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_FileMonTYPE,
		RUNTIME_CLASS(CFileMonDoc),
		RUNTIME_CLASS(CChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(CFileMonView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);
	// ������ MDI ��ܴ���
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� MDI Ӧ�ó����У���Ӧ������ m_pMainWnd ֮����������
	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// �������ѳ�ʼ���������ʾ����������и���
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	return TRUE;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CFileMonApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}
