#pragma once

//_ZHANGMQ_EDIT_BEGIN_
//////////////////����༭��ʼ//////////////////////
//������    ZhangMQ
//��������  2005/07/18
//����Ŀ��  ������Ϣͷ�ļ�
//--------------�´��뿪ʼ-----------------------------------------------
#ifndef _ZHANGMQ_CHINESE_
#define	_ZHANGMQ_CHINESE_		TRUE
#endif

#ifdef _ZHANGMQ_CHINESE_

//--------------���粿����ʾ��Ϣ-----------------------------------------
#define ERROR_WEB_SEND_CONTENT_EXCEED			_T("���������У����͵��ַ������ȳ���Ŀǰ��Ƶ��ܳ��ȣ�")
#define ERROR_WEB_STRINGLENGTH_FORMAT_EXCEED	_T("�ַ������ȳ��� 9999��")
#define ERROR_WEB_LENGTH_FORMAT					_T("�Գ��Ƚ����ַ���ʱ����")

#define	ERROR_WEB_NO_SEND_HTTPDATAPACKAGE		_T("���ķ�������Ϊ�գ�")
#define	ERROR_WEB_NO_RECEIVE_HTTPDATAPACKAGE	_T("���Ľ�����������Ϊ�գ�")
//Httpͷ
#define	ERROR_WEB_SEND_INVALID_HEADERS			_T("���������У�Httpͷ���ݲ�������")
//���÷�������ͷ��Ϣ
#define	ERROR_WEB_SEND_INVALID_DATAHEADER		_T("���������У�����ͷ �������ܺ� �� ʵ�ʸ��ں�������������֮�� ��ͬ��")
//���÷�������������Ϣ
#define	ERROR_WEB_SEND_INVALID_DATAINFO			_T("���������У�������Ϣ �������ܺ� �� ʵ�ʸ��ں�������������֮�� ��ͬ��")
#define	ERROR_WEB_SEND_DATAITEM_NULL			_T("���������У���������Ϊ�գ���û���κ��������")

//��ȡ������������Ϣ
#define	ERROR_WEB_INVALID_WEBCONNECTION	        _T("û����Ч���������ӣ������Ի������磡")

//Http�����Զ��׳��Ĵ���ȫ��ͳһΪ������ʾ��Ϣ
#define	ERROR_WEB_FAILED_WEBCONNECTION	        _T("��������ʧ�ܣ������Ի������磡")

//��������������Ϣ
#define	ERROR_WEB_RECEIVE_INVALID_DATA	        _T("���������ص�������Ч�������ԣ�")
#define	ERROR_WEB_RECEIVE_EMPTY_HEADERS	        _T("���������ص�����ͷΪ�գ������ԣ�")
#define	ERROR_WEB_RECEIVE_EMPTY_CONTENT	        _T("���������ص���������Ϊ�գ������ԣ�")

//������ Http ���ӳ�����Ϣ
#define	ERROR_WEB_HTTP400		                _T("��Ч���󣡷���������ʧ�ܣ������ԣ�")
#define	ERROR_WEB_HTTP404		                _T("����ķ���û���ҵ��������ԣ�")
#define	ERROR_WEB_HTTP405		                _T("��������֧����������ʽ��")
#define	ERROR_WEB_HTTP500		                _T("����������ʧ�ܣ������ԣ�")
#define	ERROR_WEB_HTTP503		                _T("���������������Ժ����ԣ�")
#define	ERROR_WEB_HTTPUNKNOWN	                _T("δ֪HTTP���Ӵ������������������ԣ�")

//���÷������������ݰ���ͷ��Ϣ
#define	ERROR_WEB_RECEIVE_FUNCTION_UNKOWN		_T("δ֪��Rabo���ܣ�")

//���÷������������ݰ���������Ϣ
#define	ERROR_WEB_RECEIVE_CRC_FAILED			_T("�����յ�������CRC����ʧ�ܣ�")
#define	ERROR_WEB_RECEIVE_TRANSFERTYPE_UNKOWN	_T("δ֪��Rabo�������͹��ܣ�")

#endif
//--------------�´������-----------------------------------------------
//////////////////����༭����//////////////////////
//_ZHANGMQ_EDIT_END_