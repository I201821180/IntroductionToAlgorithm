#include <iostream>
#include <vector>
#include <string>

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
	binaryTree<int> bt{ 4, 1, 3, 2, 7, 5, 6, 9}; 
	bt.print();

	std::vector<int> v1{ 46,143,25,32,15,65,57 };
	binaryTree<int>* pbt = new binaryTree<int>(v1);
	pbt->print();
	
	int key = 32;
	int res = pbt->search(key);
	std::cout << "tree search " << key << ", result: " << res << std::endl;

	std::cout << "tree min: " << pbt->min() << ", tree max: " << pbt->max() << std::endl;

	int res1 = pbt->successor(res);
	std::cout << "tree Successor: " << key << "'s successor is " << res1 << std::endl;

	int res2 = pbt->preSuccessor(res);
	std::cout << "tree preSuccessor: " << key << "'s presuccessor is " << res2 << std::endl;

	pbt->insert(54);
	pbt->print();
	pbt->remove(65);
	pbt->print();
	delete pbt;
	
	std::shared_ptr<std::string> str = std::make_shared<std::string>("6666666");
	binaryTree<std::shared_ptr<std::string>> sbt{ str };
	sbt.print();
	//_CrtDumpMemoryLeaks(); // ��Ҫʹ���������������

}