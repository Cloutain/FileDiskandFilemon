#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Are we running on NT or 9x?
//BOOL					g_bIsNT;

// performance counter frequency
LARGE_INTEGER			g_PerfFrequency;

//Error Message Dialog
CErrorMsgDlg			g_dlgErrorMsg;

char					g_cDriveLetter;//�̷�
char					g_strAppPath[MAXPATHLEN];//Ӧ�ó�����������·��

//CString					g_strAppPath;//Ӧ�ó�����������·��

CFileDisk_Driver		g_clsFileDisk_Driver;
CFileFilter_Driver		g_clsFileFilter_Driver;

// Handle to File System Filter device driver
HANDLE					g_hSys_FileFilter = INVALID_HANDLE_VALUE;

// Filter-related
FILTER					g_FilterDefinition;

POPEN_FILE_INFORMATION	g_pOpenFileInformation;

//�ñ�����ÿһλ��ʾ����Ӧ�������ޱ������ļ�����������
//ÿһλ��λ����Windows��ʾ���̵�λ��һ�£����Բο�GetLogicalDrives()�����İ���˵����
DWORD					g_dwCurDriveSet;// drives that are hooked

// Buffer into which driver can copy statistics
char					g_strStats[ LOGBUFSIZE ];
// Current fraction of buffer filled
DWORD					g_dwStatsLen;
