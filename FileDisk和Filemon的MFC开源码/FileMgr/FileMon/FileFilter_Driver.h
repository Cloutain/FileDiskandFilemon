#pragma once

#include "driver_base.h"

class CFileFilter_Driver : public CDriver_Base
{
public:
	CFileFilter_Driver(void);
	~CFileFilter_Driver(void);

	BOOL InstallDriver( IN SC_HANDLE SchSCManager, IN LPCTSTR DriverName, IN LPCTSTR ServiceExe );
	BOOL StartDriver( IN SC_HANDLE SchSCManager, IN LPCTSTR DriverName );
	BOOL OpenDevice( IN LPCTSTR DriverName, HANDLE * lphDevice );
	BOOL StopDriver( IN SC_HANDLE SchSCManager, IN LPCTSTR DriverName );
	BOOL RemoveDriver( IN SC_HANDLE SchSCManager, IN LPCTSTR DriverName );
	BOOL UnloadDeviceDriver( LPCTSTR Name );
	BOOL LoadDeviceDriver( LPCTSTR Name, LPCTSTR Path, HANDLE * lphDevice, PDWORD Error );
	//�Զ�����FileFilter����
	BOOL AutoLoadAndStart(void);
	//���ض����̽����ļ�ϵͳ�Ĺ���
	DWORD HookDriver(DWORD dwNewDriveSet);
	//Ĭ�϶� FileDisk ����������̼����ļ������������й���
	BOOL DefaultHookDriver();

	/******************************************************************************
	*
	*	FUNCTION:	Split
	*
	*	PURPOSE:	Split a delimited line into components
	*
	******************************************************************************/
	int Split( char * line, char delimiter, char * items[] );
};
