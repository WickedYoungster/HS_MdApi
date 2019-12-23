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
// 行情系统初始话
bool MdApiInit()
{
	
	
}

// 行情初始话后进行数据接收
char* depthInfo(char * exchange_type, char* stockCode)
{
	

}

// 行情初始话关闭
void depthInfoClose()
{

	
}
*/


