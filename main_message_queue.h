/** @file
* ����Demo.��Ϣ����
* @author  �Ŵ���
* @author  �������ӹɷ����޹�˾
* @version 1.0
* @date    20160815
*/
#pragma once

#include <list>
#include <string>
using namespace std;

#include "MyThread.h"
#include "MyEvent.h"
using namespace HsHqSdkDemo;
#include "h5sdk.h"


/*
	��Ϣ����
*/
typedef enum {
	Command_KeyInput, //�ȴ���������
	Command_SdkCallback,//�ȴ�SDK�ص�
} MyCommandType;

typedef unsigned int UINT_PTR;
typedef unsigned long LONG_PTR;
typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM;

/*
	������������
*/

#define Key_Return '\n'

#define Key_Quit 'Q'


/*
	sdk�ص�����
*/
typedef enum {
	SdkCallback_none = 100,

	SdkCallback_Login,	//login
	SdkCallback_SpeedTest,	//�ٶȲ���
	SdkCallback_Market_Types,//�г�������Ϣ
	SdkCallback_Candle_By_Offset,//K��
	SdkCallback_Snapshot,	//�������
	SdkCallback_Trend,	//��ʱ
	SdkCallback_L2_Transcation,	//��ʳɽ�
	SdkCallback_L2_Order,	//���ί��
	SdkCallback_Server_Info,//��������Ϣ.�г���ʼ��.
	SdkCallback_Subscribe, //����.
	SdkCallback_Subscribe_L2_Transcation, //����.��ʳɽ�
	SdkCallback_Subscribe_L2_Order, //����.���ί��

	SdkCallback_Snapshot_Capability,	//�������.����
	SdkCallback_Candle_By_Offset_Cabability,//K��.����
} SdkCallbackType;

class MyMessage
{
public:
	MyCommandType	m_commandType;
	WPARAM			m_wParam;
	LPARAM			m_lParam;
public:
	MyMessage(MyCommandType status, WPARAM wParam, LPARAM lParam) : m_commandType(status), m_wParam(wParam), m_lParam(lParam) {}
	virtual ~MyMessage(){} //����ע���ͷ��ڴ�
};

class MyMessageQueue
{
public:
	list<MyMessage *>	m_listMessage;
	MyEvent				m_eventWait;	//�Ⱥ��ź�
	MyMutex				m_mutexData;	//������
public:
	~MyMessageQueue();

	MyMessage *Peek_Message(void);
	void Post_Message(MyCommandType status, WPARAM wParam, LPARAM lParam=0);
};

/*
	��������.�߳�
*/
class KeyboardInputThread : public MyThread
{
public:
	/*
		�߳����
	*/
	virtual int MainFun();
};