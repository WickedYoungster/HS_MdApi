#include "HengShengMdApi.h"

/*
	To test the library, include "HengShengMdApi.h" from an application project
	and call HengShengMdApiTest().
	
	Do not forget to add the library to Project Dependencies in Visual Studio.
*/


static int s_Test = 0;

extern "C" int HengShengMdApiTest();

int HengShengMdApiTest()
{
	return ++s_Test;
}
/*
// ����ϵͳ��ʼ��
bool MdApiInit()
{
	
	
}

// �����ʼ����������ݽ���
char* depthInfo(char * exchange_type, char* stockCode)
{
	

}

// �����ʼ���ر�
void depthInfoClose()
{

	
}
*/


