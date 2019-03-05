#pragma once

// Variables/definitions for the driver that performs the actual monitoring.
#define	SYS_FILEFILTER			_T("FileFilter.sys")
#define	FILEFILTER_NAME			_T("FileFilter")

// File Disk driver.
#define	SYS_FILEDISK			_T("FileDisk.sys")
#define	FILEDISK_NAME			_T("FileDisk")

// performance counter frequency
extern LARGE_INTEGER			g_PerfFrequency;

//Error Message Dialog
extern CErrorMsgDlg				g_dlgErrorMsg;

extern char						g_cDriveLetter;//�̷�
extern char						g_strAppPath[MAXPATHLEN];//Ӧ�ó�����������·��

//extern CString g_strAppPath;//Ӧ�ó�����������·��

extern CFileDisk_Driver			g_clsFileDisk_Driver;
extern CFileFilter_Driver		g_clsFileFilter_Driver;

// Handle to File System Filter device driver
extern HANDLE					g_hSys_FileFilter;

// Filter-related
extern FILTER					g_FilterDefinition;

extern POPEN_FILE_INFORMATION	g_pOpenFileInformation;

//�ñ�����ÿһλ��ʾ����Ӧ�������ޱ������ļ�����������
//ÿһλ��λ����Windows��ʾ���̵�λ��һ�£����Բο�GetLogicalDrives()�����İ���˵����
extern DWORD					g_dwCurDriveSet;// drives that are hooked

// Buffer into which driver can copy statistics
extern char						g_strStats[ LOGBUFSIZE ];
// Current fraction of buffer filled
extern DWORD					g_dwStatsLen;
