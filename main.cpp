#include <stdio.h>
#include <stdlib.h>
#include "listNode.h"
#include "linkedList.h"

void main(void)
{
	linkedList _linkedlist; //메모리 생성
	
	_linkedlist.SLL_PushBack(5);
	_linkedlist.SLL_PushBack(10);
	_linkedlist.SLL_PushBack(15);
	_linkedlist.SLL_PushBack(20);

	listNode* findNode = _linkedlist.SLL_GetNodeEqualValue(10);
	/*if (findNode){
		printf("findValue : %d", findNode->m_nValue);
	}
	else
	{
		printf("없어.");
	}*/
	//_linkedlist.SLL_Draw();
	_linkedlist.SLL_Push(findNode, 13);
	
	/*listNode* findNode = _linkedlist.SLL_GetNodeIndex(1);
	printf("find node : %d\n" ,findNode->m_nValue);*/

	//listNode* pDelNode = _linkedlist.SLL_GetNodeEqualValue(10);
	//_linkedlist.SLL_Erase(pDelNode);
	_linkedlist.SLL_Draw();
	printf("\n");
	printf("node cnt : %d\n ", _linkedlist.SLL_Size());

	listNode* findNode2 = _linkedlist.SLL_GetNodeIndex(4);
	printf("find node : %d\n", findNode2->m_nValue);
	/*_linkedlist.SLL_Draw();
	printf("\n");
	printf("node cnt : %d\n ", _linkedlist.SLL_Size());

	_linkedlist.SLL_EraseValue(15);
	_linkedlist.SLL_Draw();
	printf("\n");
	printf("node cnt : %d\n ", _linkedlist.SLL_Size());

	_linkedlist.SLL_EraseValue(5);
	_linkedlist.SLL_Draw();
	printf("\n");
	printf("node cnt : %d\n ", _linkedlist.SLL_Size());*/

	system("pause");
}