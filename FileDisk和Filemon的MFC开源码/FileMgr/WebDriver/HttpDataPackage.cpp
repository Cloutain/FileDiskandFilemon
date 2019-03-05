// HttpDataPackage.cpp : implementation file
//

#include "stdafx.h"
#include "HttpDataPackage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHttpDataPackage_Send

CHttpDataPackage_Send::CHttpDataPackage_Send()
{
	InitAllData();
}

CHttpDataPackage_Send::~CHttpDataPackage_Send()
{
	ReleaseAllData();
}

void CHttpDataPackage_Send::ReleaseAllData()
{
	m_strArrayContent_DataInfo_Item.FreeExtra();
	m_strArrayContent_DataInfo_Item.RemoveAll();
	m_strArrayContent_DataItem.FreeExtra();
	m_strArrayContent_DataItem.RemoveAll();
}

void CHttpDataPackage_Send::InitAllData()
{
	//------ Httpͷ -------------------------
	m_strHeader_DataOrigin = _T("1");//������Դ��1Ĭ��ΪRabo
	m_strHeader_DataLength = _T("");//�����ܳ���
	//��ȫУ����Ϣ
	m_strHeader_UserName = _T("");//�û���
	m_strHeader_Random = _T("");//�����
	m_strHeader_Cryptograph = _T("");//����
	//�汾У����Ϣ
	//m_strHeader_Version = _T("002");//Rabo�汾�ţ�Ĭ��
	m_strHeader_Version = _T("Lava001");//��Lava����ʱ�õİ汾��
	//�շ�У����Ϣ
	m_strHeader_BlogName = _T("");//������
	m_strHeader_Function = _T("");//���ܴ���
	//��Ϻõ�������Httpͷ
	m_strHeaders = _T("");;
	//------ Httpͷ -------------------------

	//------ Http���� -------------------------
	m_strContent_TransferType = _T("");//���ݴ������ͣ����� S ��ʾ�Ƿ��ͣ� P ��ʾ�Ƿ���������
	m_strContent_DataCRC = _T("");//��Ч��У����
	m_strContent_DataInfo_ItemCount = _T("0000");//������Ϣ������4λ��Ϊ������Ϣ�������ܺͣ� = n��

	ReleaseAllData();
	//��������
	m_strContent_DataAll = _T("");
	//------ Http���� -------------------------
}

//�� nFormat_BaseUnit ָ����λ���Գ��Ƚ����ַ���������100������ת��Ϊ"0100"
bool CHttpDataPackage_Send::SetHttp_Length_Format(CString& strLength, int nLength, 
												  int nFormat_BaseUnit)
{
	bool bRet = true;

	if(nLength <= 0)
	{
		strLength.Empty();
		for(int i=0; i<nFormat_BaseUnit; i++)
		{
			strLength += "0";
		}
	}
	else
	{
		strLength.Format(_T("%d"), nLength);
		switch(strLength.GetLength() % nFormat_BaseUnit)
		{
		case 0:
			break;

		case 1:
			strLength = _T("000") + strLength;
			break;
			
		case 2:
			strLength = _T("00") + strLength;
			break;
			
		case 3:
			strLength = _T("0") + strLength;
			break;

		default:
			{
				AfxMessageBox(ERROR_WEB_LENGTH_FORMAT, MB_ICONSTOP);
				bRet = false;
			}
			break;
		}
	}
	
	return bRet;
}

//��������ַ������г��ȵĸ�ʽ��������"Title"������ת��Ϊ"0005"
//����ַ������Ⱥܳ���������4λ������4λΪ�����������䣬����"0005 0010"
bool CHttpDataPackage_Send::SetHttp_StringLength_Format(CString strOldString, 
														   CString& strNewString)
{
	bool bRet = true;
	strNewString = _T("0000");

	int nOldString_Length =0;
	nOldString_Length = strOldString.GetLength();
	SetHttp_Length_Format(strNewString, nOldString_Length, DATA_INFO_BASEUNIT);

	return bRet;
}

bool CHttpDataPackage_Send::SetHttp_Compute_DataInfo_ItemCount(CStringArray* pstrArrayItem,
															   CString& strItemCount)
{
	bool bRet = true;
	strItemCount = _T("0000");
	int nItemCount = 0;

	nItemCount = (int)pstrArrayItem->GetSize();
	if(nItemCount > 0)
	{
		//������һ��
		int nLastItem_Length = pstrArrayItem->GetAt(nItemCount-1).GetLength();
		if(nLastItem_Length > DATA_INFO_BASEUNIT)
		{//���һ���4λ����ʾ������������ݳ��ȣ�����"0004 1002"
			nLastItem_Length = nLastItem_Length/DATA_INFO_BASEUNIT;
			nItemCount += nLastItem_Length-1;
		}
		if(nItemCount <= DATA_BASEUNIT_LENGTH_MAX)
		{
			SetHttp_Length_Format(strItemCount, nItemCount, DATA_INFO_BASEUNIT);
			bRet = true;
		}
		else
		{
			CString strError = ERROR_WEB_SEND_CONTENT_EXCEED;
			AfxMessageBox(strError);
			bRet = false;
		}
	}
	else
		bRet = true;

	return bRet;
}

//�������е���Ч������ϳ�Ҫ���͵����ݰ�ͷ m_strHeaders
bool CHttpDataPackage_Send::SetHttp_SendHeaders()
{
	bool bRet = true;
	m_strHeaders.Empty();
	//�������Ϸ���
	if(m_strHeader_DataOrigin.IsEmpty() || m_strHeader_DataLength.IsEmpty() || 
		m_strHeader_UserName.IsEmpty() || m_strHeader_Random.IsEmpty() || 
		m_strHeader_Cryptograph.IsEmpty() || m_strHeader_Version.IsEmpty() || 
		m_strHeader_BlogName.IsEmpty() || m_strHeader_Function.IsEmpty())
	{
		CString strError = ERROR_WEB_SEND_INVALID_HEADERS;
		/*strError += _T("Origin:")		+ m_strHeader_DataOrigin;
		strError += _T("Length:")		+ m_strHeader_DataLength;
		strError += _T("UserName:")		+ m_strHeader_UserName;
		strError += _T("Random:")		+ m_strHeader_Random;
		strError += _T("Cryptograph:")	+ m_strHeader_Cryptograph;
		strError += _T("Version:")		+ m_strHeader_Version;
		strError += _T("BlogName:")		+ m_strHeader_BlogName;
		strError += _T("Function:")		+ m_strHeader_Function;//*/
		AfxMessageBox(strError);
		bRet = false;
	}
	else
	{
		//ͷ��Ϣ��ʽ���£� Name:Value\r\n ���� ����:ֵ �ټӻس�����
		m_strHeaders = 
		HTTPDATAPACKAGE_SEND_HEADERSNAME_DATAORIGIN  + m_strHeader_DataOrigin + _T("\r\n") + 
		HTTPDATAPACKAGE_SEND_HEADERSNAME_DATALENGTH  + m_strHeader_DataLength + _T("\r\n") +
		HTTPDATAPACKAGE_SEND_HEADERSNAME_USERNAME    + m_strHeader_UserName + _T("\r\n") + 
		HTTPDATAPACKAGE_SEND_HEADERSNAME_RANDOM		 + m_strHeader_Random + _T("\r\n") +
		HTTPDATAPACKAGE_SEND_HEADERSNAME_CRYPTOGRAPH + m_strHeader_Cryptograph + _T("\r\n") + 
		HTTPDATAPACKAGE_SEND_HEADERSNAME_VERSION	 + m_strHeader_Version + _T("\r\n") + 
		HTTPDATAPACKAGE_SEND_HEADERSNAME_BLOGNAME    + m_strHeader_BlogName + _T("\r\n") + 
		HTTPDATAPACKAGE_SEND_HEADERSNAME_FUNCTION    + m_strHeader_Function;// + "\r\n";
		bRet = true;
	}
	return bRet;
}

//�� SetHttp_Combine_SendContent() ���ã��������е� GetContent_DataInfo_ItemCount 
//GetContent_DataInfo_Item GetContent_DataItem ������ϳ�Ҫ���͵�
//���ݰ����� m_strContent_DataAll
bool CHttpDataPackage_Send::SetContent_DataAll()
{
	bool bRet = true;
	m_strContent_DataAll = m_strContent_TransferType 
						 + m_strContent_DataCRC;

	m_strContent_DataAll += m_strContent_DataInfo_ItemCount;
	int nDataCount = (int)m_strArrayContent_DataInfo_Item.GetSize();
	if(nDataCount > 0)
	{
		for(int i=0; i<nDataCount; i++)
		{
			m_strContent_DataAll += m_strArrayContent_DataInfo_Item.GetAt(i);
		}
		for(i=0; i<nDataCount; i++)
		{
			m_strContent_DataAll += m_strArrayContent_DataItem.GetAt(i);
		}
		bRet = true;
	}
	return bRet;
}//*/

bool CHttpDataPackage_Send::SetHttp_Combine_SendContent()
{
	bool bRet = true;
	m_strContent_DataAll.Empty();
	m_strArrayContent_DataInfo_Item.RemoveAll();
	//�������Ϸ���
	int nDataCount = (int)m_strArrayContent_DataItem.GetSize();
	CString strDataItem = _T("");
	CString strDataItem_Length = _T("");
	for(int i=0; i<nDataCount; i++)
	{
		strDataItem = m_strArrayContent_DataItem.GetAt(i);
		if(!SetHttp_StringLength_Format(strDataItem, strDataItem_Length))
		{
			bRet = false;
			return bRet;
		}
		m_strArrayContent_DataInfo_Item.Add(strDataItem_Length);
	}
	if(!SetHttp_Compute_DataInfo_ItemCount(&m_strArrayContent_DataInfo_Item, 
		m_strContent_DataInfo_ItemCount))
	{
		bRet = false;
		return bRet;
	}
	if(!SetContent_DataAll())
	{
		bRet = false;
		return bRet;
	}
	strDataItem_Length.Empty();
	strDataItem_Length.Format(_T("%d"), m_strContent_DataAll.GetLength());
	SetHeader_DataLength(strDataItem_Length);
	bRet = true;
	return bRet;
}//*/

/////////////////////////////////////////////////////////////////////////////
// CHttpDataPackage_Send message handlers

//---------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////
// CHttpDataPackage_Receive

CHttpDataPackage_Receive::CHttpDataPackage_Receive()
{
	InitAllData();
}

CHttpDataPackage_Receive::~CHttpDataPackage_Receive()
{
	ReleaseAllData();
}

void CHttpDataPackage_Receive::ReleaseAllData()
{
	m_strArrayContent_DataInfo_Item.FreeExtra();
	m_strArrayContent_DataInfo_Item.RemoveAll();
	m_strArrayContent_DataItem.FreeExtra();
	m_strArrayContent_DataItem.RemoveAll();
}

void CHttpDataPackage_Receive::InitAllData()
{
	//------ Httpͷ -------------------------
	//m_strHeader_DataOrigin = _T("");//������Դ
	m_strHeader_DataLength = _T("");//�����ܳ���
	m_strHeader_Function = _T("");//���ܴ���
	//------ Httpͷ -------------------------

	//------ Http���� -------------------------
	m_strContent_TransferType = _T("");//���ݴ������ͣ����� S ��ʾ�Ƿ��ͣ� P ��ʾ�Ƿ���������
	m_strContent_DataCRC = _T("");//��Ч��У����
	//������Ϣ
	m_strContent_DataInfo_ItemCount = _T("0000");//������Ϣ������4λ��Ϊ������Ϣ�������ܺͣ� = n��

	ReleaseAllData();
	//��������
	m_strContent_DataAll = _T("");
	//------ Http���� -------------------------
}

/////////////////////////////////////////////////////////////////////////////
// CHttpDataPackage_Receive message handlers

//��strHttpContent_Receive ���ݽ��� CRC��=strHttpContent_CRC ����Ч�Լ���
//���� true ��ʾ�����������Ч
bool CHttpDataPackage_Receive::CRC_Http_ReceiveContent(CString strHttpContent_CRC, 
											CString& strHttpContent_Receive)
{
	bool bRet = true;
	return bRet;
}

//�� strHttpHeaders_Receive �и��� strHttp_Receive_HeaderName ָ����ͷ���ֲ���
//�����ֶ�Ӧ��ͷ��ֵ������Ϊ����ֵ
CString CHttpDataPackage_Receive::GetHttp_ReceiveHeader(CString strHttpHeaders_Receive, 
							  CString strHttp_Receive_HeaderName)
{
	CString strReceive_HeaderValue = _T("");
	int nHeaderName_Length = strHttp_Receive_HeaderName.GetLength();
	int nHeaderName_Pos = strHttpHeaders_Receive.Find(strHttp_Receive_HeaderName);
	strHttpHeaders_Receive = strHttpHeaders_Receive.Mid(nHeaderName_Pos);
	nHeaderName_Pos = strHttpHeaders_Receive.Find(_T("\r\n"));
	strReceive_HeaderValue = strHttpHeaders_Receive.Mid(nHeaderName_Length+1, 
										nHeaderName_Pos-nHeaderName_Length-1);

	return strReceive_HeaderValue;
}

//�� strHttpHeaders_Receive �е���Ч���ݷ�������֣�
//����д�����յ����ݰ�ͷ pHttpData_Receive ��ȥ
bool CHttpDataPackage_Receive::SetHttp_ReceiveHeaders(CString strHttpHeaders_Receive)
{
	bool bRet = false;
	if(!strHttpHeaders_Receive.IsEmpty())
	{
		CString strHeader_Value = GetHttp_ReceiveHeader(strHttpHeaders_Receive, 
									HTTPDATAPACKAGE_RECEIVE_HEADERSNAME_DATALENGTH);
		SetHeader_DataLength(strHeader_Value);

		strHeader_Value.Empty();
		strHeader_Value = GetHttp_ReceiveHeader(strHttpHeaders_Receive, 
			HTTPDATAPACKAGE_RECEIVE_HEADERSNAME_FUNCTION);
		SetHeader_Function(strHeader_Value);

		bRet = true;
	}
	else
	{
		CString strError = ERROR_WEB_RECEIVE_EMPTY_HEADERS;
		AfxMessageBox(strError);
		bRet = false;
	}
	return bRet;
}

//�� strHttpContent_Receive �е���Ч���ݷ����������д�����յ�
//���ݰ� m_strArrayContent_DataInfo_Item �� m_strArrayContent_DataItem ��ȥ
//bIsAnalyzeServerReply=true ��ʾ�����ݷ�������д�� m_strArrayContent_DataItem ��ȥ
bool CHttpDataPackage_Receive::SetHttp_ReceiveContent(CString& strHttpContent_Receive, 
													   bool bIsAnalyzeServerReply)
{
	bool bRet = false;
	int nData_Header_BaseUnit = DATA_HEADER_BASEUNIT;//�������� 3 λΪ��׼�����ģʽ
	int nData_Info_BaseUnit = DATA_INFO_BASEUNIT;//�������� 4 λΪ��׼�����ģʽ
	CString strContent_NotAnalysed = _T("");//��û�б��������ַ���
	CString strTemp = _T("");//��ʱ�ַ���

	if(!strHttpContent_Receive.IsEmpty())
	{
		SetContent_DataAll(strHttpContent_Receive);
		bRet = true;
		/*//����ķ���������ĵ� "Rabo��׼ͨѶ����.doc"
		//��1λ��ʾ�������ͣ�������������سɹ��Ļ��� P�����ش������ E
		SetContent_TransferType(strHttpContent_Receive.GetAt(0));
		strContent_NotAnalysed = strHttpContent_Receive.Mid(1);//��1λ�Ѿ�������ϣ�ȥ��
		//��Ч��У����
		strTemp = _T("");//strContent_NotAnalysed.Mid(0, nData_Header_BaseUnit);
		SetContent_DataCRC(strTemp);
		//��Ч��У��
		if(CRC_Http_ReceiveContent(strTemp, strHttpContent_Receive))
		{
			//CRCУ����ϣ�ȥ����ʾ CRC �� nData_Header_BaseUnit ��ô���λ
			//strContent_NotAnalysed = strContent_NotAnalysed.Mid(nData_Header_BaseUnit);
			//������Ϣ����
			strTemp = strContent_NotAnalysed.Mid(0, nData_Info_BaseUnit);
			SetContent_DataInfo_ItemCount(strTemp);
			int nData_Info_ItemCount = atoi(strTemp);
			//������Ϣ�����Ѿ�������ϣ�ȥ��
			strContent_NotAnalysed = strContent_NotAnalysed.Mid(nData_Info_BaseUnit);
			if(nData_Info_ItemCount > 0)
			{//������Ϣ ������
				for(int i=0; i< nData_Info_ItemCount; i++)
				{
					(GetContent_DataInfo_Item())->Add(
						strContent_NotAnalysed.Mid(0, nData_Info_BaseUnit));
					//�Ѿ��������һ�����ȥ��������
					strContent_NotAnalysed = strContent_NotAnalysed.Mid(nData_Info_BaseUnit);
				}
				//���ʣ�µľ�������������������Ϣ
				strHttpContent_Receive = strContent_NotAnalysed;
				SetContent_DataAll(strContent_NotAnalysed);
				if(bIsAnalyzeServerReply == true)
				{
					int nLength = 0;
					for(i=0; i<nData_Info_ItemCount; i++)
					{
						nLength = atoi(m_strArrayContent_DataInfo_Item.GetAt(i));
						m_strArrayContent_DataItem.Add(
							strContent_NotAnalysed.Mid(0, nLength));
						strContent_NotAnalysed = strContent_NotAnalysed.Mid(nLength);
					}
				}
			}
			else
			{//����û���κ� ������Ϣ ����
			}
			bRet = true;
		}
		else
		{//����У��ʧ�ܣ�������Ч
			strHttpContent_Receive = ERROR_WEB_RECEIVE_CRC_FAILED;
			bRet = false;
		}//*/
	}
	else
	{
		strHttpContent_Receive = ERROR_WEB_RECEIVE_EMPTY_CONTENT;
		bRet = false;
	}
	return bRet;
}
