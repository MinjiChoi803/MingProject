#pragma once

//노드 관리
class listNode;
class linkedList
{
public:
	listNode* m_pNodeTop;
	listNode* m_pNodeBottom;

	void SLL_PushBack(int _value);
	void SLL_PushFront(int _value);
	void SLL_Push(listNode* _currNode, int _value);
	void SLL_EraseValue(int _value);
	void SLL_Erase(listNode* _delNode); //값이 아닌, 노드를 넘겨주면 노드의 주소를 검색하는
	void SLL_Draw(void);
	void SLL_Clear(void);
	listNode* SLL_GetNodeEqualValue(int _value);
	listNode* SLL_GetNodeIndex(int _idx);
	int SLL_Size(void);


	linkedList();
	~linkedList();
};

