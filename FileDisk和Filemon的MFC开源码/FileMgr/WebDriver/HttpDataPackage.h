#if !defined(AFX_HTTPDATAPACKAGE_H__5391DECF_8292_4D1C_AA45_65A647A90723__INCLUDED_)
#define AFX_HTTPDATAPACKAGE_H__5391DECF_8292_4D1C_AA45_65A647A90723__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HttpDataPackage.h : header file
//

#define BUFFER_SIZE 4095

//Send Data Package
#define HTTPDATAPACKAGE_SEND_HEADERSNAME_DATAORIGIN		_T("DON:")
#define HTTPDATAPACKAGE_SEND_HEADERSNAME_DATALENGTH		_T("DLH:")
#define HTTPDATAPACKAGE_SEND_HEADERSNAME_USERNAME		_T("UNE:")
#define HTTPDATAPACKAGE_SEND_HEADERSNAME_RANDOM			_T("RDM:")
#define HTTPDATAPACKAGE_SEND_HEADERSNAME_CRYPTOGRAPH	_T("CGH:")
#define HTTPDATAPACKAGE_SEND_HEADERSNAME_VERSION		_T("VSN:")
#define HTTPDATAPACKAGE_SEND_HEADERSNAME_BLOGNAME		_T("BNE:")
#define HTTPDATAPACKAGE_SEND_HEADERSNAME_FUNCTION		_T("FCN:")

//Receive Data Package
#define HTTPDATAPACKAGE_RECEIVE_HEADERSNAME_DATALENGTH	_T("DLH:")
#define HTTPDATAPACKAGE_RECEIVE_HEADERSNAME_FUNCTION	_T("FCN:")

//Data Base Unit
#define DATA_HEADER_BASEUNIT	3
#define DATA_INFO_BASEUNIT		4

#define DATA_BASEUNIT_LENGTH_MAX 9999
/////////////////////////////////////////////////////////////////////////////
// CHttpDataPackage_Send

class _WEBDRIVER_API CHttpDataPackage_Send : public CObject
{
// Construction
public:
	CHttpDataPackage_Send();
	virtual ~CHttpDataPackage_Send();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHttpDataPackage_Send)
	//}}AFX_VIRTUAL

private:
	//------ Httpͷ -------------------------
	CString m_strHeader_DataOrigin;//������Դ
	CString m_strHeader_DataLength;//�����ܳ��ȣ��� S001001002000...�ȵ��ܳ���
	//��ȫУ����Ϣ
	CString m_strHeader_UserName;//�û���
	CString m_strHeader_Random;//�����
	CString m_strHeader_Cryptograph;//����
	//�汾У����Ϣ
	CString m_strHeader_Version;//Rabo�汾��
	//�շ�У����Ϣ
	CString m_strHeader_BlogName;//������
	CString m_strHeader_Function;//���ܴ���
	//��Ϻõ�������Httpͷ
	CString m_strHeaders;
	//------ Httpͷ -------------------------

	//------ Http���� -------------------------
	CString m_strContent_TransferType;//���ݴ������ͣ����� S ��ʾ�Ƿ��ͣ� P ��ʾ�Ƿ���������
	CString m_strContent_DataCRC;//��Ч��У����
	//������Ϣ
	CString m_strContent_DataInfo_ItemCount;//������Ϣ������4λ��Ϊ������Ϣ�������ܺͣ� = n��
	//�������, m_strArrayContent_DataInfo_Item.GetAt(0) ��ʾ��1��������ĳ���
	//m_strArrayContent_DataInfo_Item.GetAt(1) ��ʾ��2��������ĳ��ȣ���������
	CStringArray m_strArrayContent_DataInfo_Item;
	//�������ݣ���������������һһ��Ӧ
	CStringArray m_strArrayContent_DataItem;
	//��������ͷ��Ϣ���������ݵ���������
	CString m_strContent_DataAll;//���е���������
	//------ Http���� -------------------------

// Implementation
public:
	//��������ַ������г��ȵĸ�ʽ��������"Title"������ת��Ϊ"0005"
	bool	SetHttp_StringLength_Format(CString strOldString, CString& strNewString);
	bool	SetHttp_Length_Format(CString& strLength, int nLength=0, 
									int nFormat_BaseUnit=DATA_INFO_BASEUNIT); 
private:
	//����strArrayItem�ж��ٸ���������һ�������N��4λ����ϣ���ǰ�涼ֻ����1��4λ
	//�������һ�������"0004 0013"
	bool	 SetHttp_Compute_DataInfo_ItemCount(CStringArray* pstrArrayItem, 
												CString& strItemCount);
	//�������е���Ч������ϳ�Ҫ���͵����ݰ�ͷ m_strHeaders
	bool	SetHttp_SendHeaders();
public:
	CString GetHeaders()
			{
				if(!SetHttp_SendHeaders())
				{
					m_strHeaders = _T("");
				}
				return m_strHeaders;
			};
	void	SetHeaders(CString strHeaders)
			{ m_strHeaders = strHeaders; };//*/

	/*CString GetHeader_DataOrigin() { return m_strHeader_DataOrigin; };
	void	SetHeader_DataOrigin(CString strHeader_DataOrigin)
			{ m_strHeader_DataOrigin = strHeader_DataOrigin; };//*/

	//CString GetHeader_DataLength() { return m_strHeader_DataLength; };
	void	SetHeader_DataLength(CString strHeader_DataLength)
			{ m_strHeader_DataLength = strHeader_DataLength; };//*/

	//CString GetHeader_UserName() { return m_strHeader_UserName; };
	void	SetHeader_UserName(CString strHeader_UserName)
			{ m_strHeader_UserName = strHeader_UserName; };

	//CString GetHeader_Random() { return m_strHeader_Random; };
	void	SetHeader_Random(CString strHeader_Random)
			{ m_strHeader_Random = strHeader_Random; };

	//CString GetHeader_Cryptograph() { return m_strHeader_Cryptograph; };
	void	SetHeader_Cryptograph(CString strHeader_Cryptograph)
			{ m_strHeader_Cryptograph = strHeader_Cryptograph; };

	CString GetHeader_Version() { return m_strHeader_Version; };
	void	SetHeader_Version(CString strHeader_Version)
			{ m_strHeader_Version = strHeader_Version; };

	//CString GetHeader_BlogName() { return m_strHeader_BlogName; };
	void	SetHeader_BlogName(CString strHeader_BlogName)
			{ m_strHeader_BlogName = strHeader_BlogName; };

	//CString GetHeader_Function() { return m_strHeader_Function; };
	void	SetHeader_Function(CString strHeader_Function)
			{ m_strHeader_Function = strHeader_Function; };

	//CString GetContent_TransferType() { return m_strContent_TransferType; };
	void	SetContent_TransferType(CString strContent_TransferType)
			{ m_strContent_TransferType = strContent_TransferType; };

	CString GetContent_DataCRC() { return m_strContent_DataCRC; };
	void	SetContent_DataCRC(CString strContent_DataCRC)
			{ m_strContent_DataCRC = strContent_DataCRC; };//*/

	CStringArray* GetContent_DataItem()
			{ return &m_strArrayContent_DataItem; };
	void	SetContent_DataItem(CStringArray* pstrArrayContent_DataItem)
			{
				m_strArrayContent_DataItem.RemoveAll();
				int nCount = (int)pstrArrayContent_DataItem->GetSize();
				if(nCount > 0)
				{
					for(int i=0; i<nCount; i++)
					{
						m_strArrayContent_DataItem.Add(
							pstrArrayContent_DataItem->GetAt(i));
					}
				}//*/
			};

private:
	//�� SetHttp_Combine_SendContent() ���ã��������е� GetContent_DataInfo_ItemCount 
	//GetContent_DataInfo_Item GetContent_DataItem ������ϳ�Ҫ���͵�
	//���ݰ����� m_strContent_DataAll
	bool	SetContent_DataAll();//*/
	//�������е���Ч������ϳ�Ҫ���͵����ݰ����� m_strContent_DataAll
	//������Httpͷ�е������ܳ��� SetHeader_DataLength()
	bool	SetHttp_Combine_SendContent();//*/

public:
	void ReleaseAllData();
	void InitAllData();
	CString GetContent_DataAll()
			{
				if(!SetHttp_Combine_SendContent())
				{
					m_strContent_DataAll = _T("");
				}
				return m_strContent_DataAll;
			};
	/*void	SetContent_DataAll(CString strContent_DataAll)
			{ m_strContent_DataAll = strContent_DataAll; };//*/

	// Generated message map functions
protected:
	//{{AFX_MSG(CHttpDataPackage_Send)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
};

//---------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////
// CHttpDataPackage_Receive

class _WEBDRIVER_API CHttpDataPackage_Receive : public CObject
{
// Construction
public:
	CHttpDataPackage_Receive();
	virtual ~CHttpDataPackage_Receive();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHttpDataPackage_Receive)
	//}}AFX_VIRTUAL

private:
	//------ Httpͷ -------------------------
	CString m_strHeader_DataLength;//�����ܳ��ȣ��� P001001002000...�ȵ��ܳ���
	CString m_strHeader_Function;//���ܴ���
	//------ Httpͷ -------------------------

	//------ Http���� -------------------------
	//���ݴ������ͣ����� S ��ʾ�Ƿ��ͣ� P ��ʾ�Ƿ��������صĳɹ����룬 
	//E ��ʾ�Ƿ��������صĳ������
	CString m_strContent_TransferType;
	CString m_strContent_DataCRC;//��Ч��У����
	//������Ϣ
	CString m_strContent_DataInfo_ItemCount;//������Ϣ������4λ��Ϊ������Ϣ�������ܺͣ� = n��
	//�������, m_strArrayContent_DataInfo_Item.GetAt(0) ��ʾ��1��������ĳ���
	//m_strArrayContent_DataInfo_Item.GetAt(1) ��ʾ��2��������ĳ��ȣ���������
	CStringArray m_strArrayContent_DataInfo_Item;
	//�������ݣ���������������һһ��Ӧ
	CStringArray m_strArrayContent_DataItem;
	//��������--//���е��������ݣ����������з�������ʱ�����ﱣ�淵�ص����ݣ�
	//�������ʱ�������ǳ������Ϣ
	CString m_strContent_DataAll;
	//------ Http���� -------------------------

// Implementation
public:
	void ReleaseAllData();
	void InitAllData();
	//��strHttpContent_Receive ���ݽ��� CRC��=strHttpContent_CRC ����Ч�Լ���
	//���� true ��ʾ�����������Ч
	bool	CRC_Http_ReceiveContent(CString strHttpContent_CRC, 
									CString& strHttpContent_Receive);

	//�� strHttpHeaders_Receive �и��� strHttp_Receive_HeaderName ָ����ͷ���ֲ���
	//�����ֶ�Ӧ��ͷ��ֵ������Ϊ����ֵ
	CString GetHttp_ReceiveHeader(CString strHttpHeaders_Receive, 
									CString strHttp_Receive_HeaderName);
	//�� strHttpContent_Receive �е���Ч���ݷ����������д�����յ����ݰ�ͷ strHttpHeaders_Receive ��ȥ
	bool	SetHttp_ReceiveHeaders(CString strHttpHeaders_Receive);
	//�� strHttpContent_Receive �е���Ч���ݷ����������д�����յ�
	//���ݰ� m_strArrayContent_DataInfo_Item �� m_strArrayContent_DataItem ��ȥ
	//bIsAnalyzeServerReply=true ��ʾ�����ݷ�������д�� m_strArrayContent_DataItem ��ȥ
	bool	SetHttp_ReceiveContent(CString& strHttpContent_Receive, 
									bool bIsAnalyzeServerReply=false);

	CString GetHeader_DataLength() { return m_strHeader_DataLength; };
	void	SetHeader_DataLength(CString strHeader_DataLength)
			{ m_strHeader_DataLength = strHeader_DataLength; };//*/

	CString GetHeader_Function() { return m_strHeader_Function; };
	void	SetHeader_Function(CString strHeader_Function)
			{ m_strHeader_Function = strHeader_Function; };//*/

	CString GetContent_TransferType() { return m_strContent_TransferType; };
	void	SetContent_TransferType(_TCHAR strContent_TransferType)
			{ m_strContent_TransferType = strContent_TransferType; };//*/

	CString GetContent_DataCRC() { return m_strContent_DataCRC; };
	void	SetContent_DataCRC(CString strContent_DataCRC)
			{ m_strContent_DataCRC = strContent_DataCRC; };//*/

	CString GetContent_DataInfo_ItemCount() { return m_strContent_DataInfo_ItemCount; };
	void	SetContent_DataInfo_ItemCount(CString strContent_DataInfo_ItemCount)
			{ m_strContent_DataInfo_ItemCount = strContent_DataInfo_ItemCount; };

	CStringArray* GetContent_DataInfo_Item()
			{ return &m_strArrayContent_DataInfo_Item; };
	void	SetContent_DataInfo_Item(CStringArray* pstrArrayContent_DataInfo_Item)
			{
				m_strArrayContent_DataInfo_Item.RemoveAll();
				int nCount = (int)pstrArrayContent_DataInfo_Item->GetSize();
				if(nCount <= 0)
					return;

				for(int i=0; i<nCount; i++)
				{
					m_strArrayContent_DataInfo_Item.Add(
						pstrArrayContent_DataInfo_Item->GetAt(i));
				}//*/
			};

	CStringArray* GetContent_DataItem()
			{ return &m_strArrayContent_DataItem; };
	void	SetContent_DataItem(CStringArray* pstrArrayContent_DataItem)
			{
				m_strArrayContent_DataItem.RemoveAll();
				int nCount = (int)pstrArrayContent_DataItem->GetSize();
				if(nCount > 0)
				{
					for(int i=0; i<nCount; i++)
					{
						m_strArrayContent_DataItem.Add(
							pstrArrayContent_DataItem->GetAt(i));
					}
				}
			};//*/

	CString GetContent_DataAll() { return m_strContent_DataAll; };
	void	SetContent_DataAll(CString strContent_DataAll)
			{ m_strContent_DataAll = strContent_DataAll; };

	//void	SetHttpDataPackage(CHttpDataPackage_Receive* pHttpDataPackage);

	// Generated message map functions
protected:
	//{{AFX_MSG(CHttpDataPackage_Receive)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
};
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTTPDATAPACKAGE_H__5391DECF_8292_4D1C_AA45_65A647A90723__INCLUDED_)
