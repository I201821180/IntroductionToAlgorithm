#ifndef _BASIC_H_
#define _BASIC_H_

#define CHECK_MEMORY_LEAKS

#ifdef CHECK_MEMORY_LEAKS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define CHECK_MEMORY_LEAKS_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new CHECK_MEMORY_LEAKS_NEW
#endif

#endif

/*
���ߣ�vczh
���ӣ�https ://www.zhihu.com/question/63946754/answer/215606096
��Դ��֪��
����Ȩ���������У�ת������ϵ���߻����Ȩ��
*/