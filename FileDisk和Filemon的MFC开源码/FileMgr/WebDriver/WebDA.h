//----------------------------------------------------------------------------------------------------
//  �й�����������Ȩ���У���������
//
//  �ļ����ݣ�
//      ���� CWebDA ��
//
//  �޸���ʷ��
//      Ѧ����		���������꣱���£�����	�½��ļ�
//----------------------------------------------------------------------------------------------------
#pragma once

class _WEBDRIVER_API CWebDA
{
public:
	CWebDA(void);
    ~CWebDA(void);

    /*====================================================================================
    //  ��������
    //      �����û��� m_strUserName;
    //
    //  ����˵��
    //      strUserName ��  �û���
    //===================================================================================*/
    void SetUserName(CString strUserName);

    /*====================================================================================
    //  ��������
    //      �����û�MD5����    m_strPasswordMD5;
    //
    //  ����˵��
    //      strPasswordMD5 ��  �û�����
    //===================================================================================*/
    void SetPasswordMD5(CString strPasswordMD5);

    /*====================================================================================
    //  ��������
    //      ���ò�����    m_strBlogName;
    //
    //  ����˵��
    //      strBlogName ��  �û�������
    //===================================================================================*/
    void SetBlogName(CString strBlogName);

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
    HRESULT CallServerFun(
                            CString funcode,
                            CHttpDataPackage_Receive* pHttpData_Receive = NULL,
                            CStringArray* pparam = NULL,
                            LPCSTR username = NULL,
                            LPCSTR password = NULL,
                            LPCSTR rand = NULL,
                            LPCSTR blogname = NULL,
                            CWnd* pWnd = NULL, 
                            bool bIsShowErrorMessage = true,
                            bool bIsAnalyzeServerReply = false
                            );

    //====================================================================================
    //  �������ܣ�
    //      Ϊ�û�ע�� Lava-Lava GID
    //  
    //  ����˵��
    //      strUserName     ��  BlogCN�û���
    //      strPasswordMD5  ��  �û�����
    //      strLavaGID      ��  ���Lava���������ص�GID
    //===================================================================================//
    HRESULT RegisterLavaUser(CString strUserName, CString strPasswordMD5, CString & strLavaGID);

private:
    CWebWrapper m_clsWebWrapper;
    CString     m_strUserName;
    CString     m_strPasswordMD5;
    CString     m_strBlogName;
};
