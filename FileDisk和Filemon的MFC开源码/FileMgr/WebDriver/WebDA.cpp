//----------------------------------------------------------------------------------------------------
//  �й�����������Ȩ���У���������
//
//  �ļ����ݣ�
//      ʵ�� CWebDA ��
//
//  �޸���ʷ��
//      Ѧ����		���������꣱���£�����	�½��ļ�
//----------------------------------------------------------------------------------------------------
#include "StdAfx.h"
#include ".\WebDA.h"

CWebDA::CWebDA(void)
{
	m_strUserName	= "";
	m_strPasswordMD5 = "";
	m_strBlogName = "0";
}

CWebDA::~CWebDA(void)
{
}

/*====================================================================================
//  ��������
//      �����û��� m_strUserName;
//
//  ����˵��
//      strUserName ��  �û���
//===================================================================================*/
void CWebDA::SetUserName(CString strUserName)
{
    m_strUserName = strUserName;
}

/*====================================================================================
//  ��������
//      �����û�MD5����    m_strPasswordMD5;
//
//  ����˵��
//      strPasswordMD5 ��  �û�����
//===================================================================================*/
void CWebDA::SetPasswordMD5(CString strPasswordMD5)
{
    m_strPasswordMD5 = strPasswordMD5;
}

/*====================================================================================
//  ��������
//      ���ò�����    m_strBlogName;
//
//  ����˵��
//      strBlogName ��  �û�������
//===================================================================================*/
void CWebDA::SetBlogName(CString strBlogName)
{
    m_strBlogName = strBlogName;
}

/*====================================================================================
//  ��������
//      ����ϵͳ����
//
//  ����˵��
//      funcode                 ��  Ҫ�����õ�ϵͳ������
//      pHttpData_Receive       ��  ��ŷ��������ص���Ϣ
//      pparam                  ��  HTTP��body�е�����
//      username                ��  �û���
//      password                ��  �û�����
//      rand                    ��  MD5�㷨�����������
//      blogname                ��  �û��Ĳ�����
//      pWnd                    ��  ���øú����Ĵ��ھ��
//      bIsShowErrorMessage     ��  �Ƿ���ʾ������ʾ��Ϣ
//      bIsAnalyzeServerReply   ��  �Ƿ�Է��������ص����ݽ��з���
//===================================================================================*/
HRESULT CWebDA::CallServerFun(
                        CString funcode,
                        CHttpDataPackage_Receive* pHttpData_Receive,
                        CStringArray* pparam,
                        LPCSTR username,
                        LPCSTR password,
                        LPCSTR rand,
                        LPCSTR blogname,
                        CWnd* pWnd, 
                        bool bIsShowErrorMessage,
                        bool bIsAnalyzeServerReply
                        )
{
    HRESULT hr = S_OK;

    CString strAgentName = _T("WebGrab");
	CHttpDataPackage_Send HttpData_Send;
	CHttpDataPackage_Receive HttpData_Receive;
	CMd5Encrypt md5;
	
	if(!m_strUserName.IsEmpty())
		md5.encrypt(m_strUserName, m_strPasswordMD5);

	// Http header
	if(blogname == NULL)
		blogname = m_strBlogName;

	if(username == NULL)
		username = m_strUserName;

	if(rand == NULL)
		rand = md5.GetRand_Function();

	if(password == NULL)
		password = md5.GetCryptograph_Fuction();

	HttpData_Send.SetHeader_BlogName(blogname);
	HttpData_Send.SetHeader_Cryptograph(password);
	HttpData_Send.SetHeader_Random(rand);
	HttpData_Send.SetHeader_UserName(username);
	HttpData_Send.SetHeader_Function(funcode);
	HttpData_Send.SetContent_TransferType("S");		
    //HttpData_Send.SetHeader_Version("1.0.3");

	// Call param
	if(pparam != NULL)
		HttpData_Send.SetContent_DataItem(pparam);
	if(pHttpData_Receive == NULL)
		pHttpData_Receive = &HttpData_Receive;

	//Call server function
	if (m_clsWebWrapper.PostCommand(
                                        HttpData_Send.GetHeaders(),
                                        HttpData_Send.GetContent_DataAll(),
                                        pHttpData_Receive,
                                        strAgentName,
                                        pWnd,
                                        bIsShowErrorMessage,
                                        bIsAnalyzeServerReply
                                        ))
    {
        hr = S_OK;
    }
    else
    {
        hr = S_FALSE;
    }

    return hr;
}

//====================================================================================
//  �������ܣ�
//      Ϊ�û�ע�� Lava-Lava GID
//  
//  ����˵��
//      strUserName     ��  BlogCN�û���
//      strPasswordMD5  ��  �û�����
//      strLavaGID      ��  ���Lava���������ص�GID
//===================================================================================//
HRESULT CWebDA::RegisterLavaUser(CString strUserName, CString strPasswordMD5, CString & strLavaGID)
{
    HRESULT hr = S_OK;

    //**********************************************************************************
    //��ʼȥ Lava-Lava ������ע��GID
    CInternetSession * interSession = new CInternetSession("Rabo", 1, INTERNET_OPEN_TYPE_DIRECT, NULL);
    CHttpConnection * phttpConnection = NULL;
    CHttpFile       * phttpFile = NULL;
    CString regURL = "";

    regURL = "lavaOEM/regOEMuser.php?oemid=507";
    regURL += "&nickname=";
    regURL += strUserName;
	regURL += "&oemaccount=";
	regURL += strUserName;
    regURL += "&password=";
    regURL += strPasswordMD5;

    phttpConnection = interSession->GetHttpConnection("www.lava-lava.com", (INTERNET_PORT)80);
    phttpFile = phttpConnection->OpenRequest(CHttpConnection::HTTP_VERB_GET, regURL);

    phttpFile->SendRequest();

    CString strContent = "";
	CString strResultTmp = "";

    DWORD nFileSize = (DWORD)phttpFile->GetLength();
    LPSTR lpstrBuf = strContent.GetBuffer(nFileSize);
    UINT uBytesRead = phttpFile->Read(lpstrBuf, nFileSize);
    lpstrBuf[nFileSize] = '\0';
    strResultTmp = lpstrBuf;
	strContent.ReleaseBuffer();
	
	strResultTmp.Trim(" ");

	int nIndex = strResultTmp.Find(',');
	if (strResultTmp.Left(nIndex) == REGISTER_LAVAGID_SUCCESS)
	{
		//18��ʾ�ɹ�
		strLavaGID = strResultTmp.Mid(nIndex + 1);
	}
	else if (strResultTmp.Left(nIndex) == REGISTER_LAVAGID_FAILED)
	{
		//Ӧ������ 17 ��λ���ҵ�����ʾʧ����
		CString strError = strResultTmp.Mid(nIndex + 1);
		int nErrorNum = atoi(strError);
		switch (nErrorNum)
		{
		case 1:
			hr = E_ERROR_OEMID;
			break;
		case 2:
			hr = E_ERROR_COMMOND;
			break;
		case 3:
			hr = E_ERROR_OTHER;
			break;
		default:
			hr = S_FALSE;
		}
	}
	else
	{
		hr = E_ERROR_OTHER;
	}

    if(phttpFile != NULL)
    {
        phttpFile->Close();
        delete phttpFile;
        phttpFile = NULL;
    }
    if(phttpConnection != NULL)
    {
        phttpConnection->Close();
        delete phttpConnection;
        phttpConnection = NULL;
    }
    if(interSession != NULL)
    {
        interSession->Close();
        delete interSession;
        interSession = NULL;
    }

    return hr;
}
