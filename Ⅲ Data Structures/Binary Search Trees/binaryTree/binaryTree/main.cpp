#include <iostream>
#include <vector>

#include "basic.h"
#include "binaryTree.h"

int main()
{
	/*ֻ�ü���һ��Ϳ��Լ���ڴ�й¶��*/
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(215);

	/**
	 * ͳһ��ʼ����
	 * ��bt = { ... }����ʽ����Ҫ������һ���������ٿ�����bt��
	 */
	binaryTree<int> bt{ 4, 1, 3, 2, 7, 5, 6, 9 }; 
	bt.print();

	std::vector<int> v1{ 46,143,25,32,15,65,57 };
	binaryTree<int>* pbt = new binaryTree<int>(v1);
	pbt->print();
	
	int key = 32;
	auto res = pbt->search(key);
	std::cout << "tree search " << key << ", result: " << res->key() << std::endl;

	std::cout << "tree min: " << pbt->min()->key() << ", tree max: " << pbt->max()->key() << std::endl;

	auto res1 = pbt->successor(res);
	std::cout << "tree Successor: " << key << "'s successor is " << res1->key() << std::endl;

	auto res2 = pbt->preSuccessor(res);
	std::cout << "tree preSuccessor: " << key << "'s presuccessor is " << res2->key() << std::endl;

	delete pbt;
	//_CrtDumpMemoryLeaks(); // ��Ҫʹ���������������

}