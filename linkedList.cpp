#include "linkedList.h"
#include "listNode.h"
#include <stdio.h>

void linkedList::SLL_PushBack(int _value) //마지막 노드에 넣는 함수
{
	//새로운 노드
	listNode* pNewNode = new listNode; //value를 갖는 노드를 하나 만들어라
	pNewNode->m_nValue = _value; //그 값을 갖는 새로운 노드가 생긴 것

	//top node가 null 이라면(아무런 데이터가 없을 때)
	if (m_pNodeTop == nullptr)
	{
		m_pNodeTop = pNewNode;
		//새로운 노드가 탑
	}
	else //노드가 있다면
	{
		listNode *pTailNode = m_pNodeTop;
		
		while (pTailNode->m_pNextNode != nullptr)
		{
			pTailNode = pTailNode->m_pNextNode;
			//계속 넘어가다보면 null이 나올 것.
		}
		pTailNode->m_pNextNode = pNewNode;
	}
}

void linkedList::SLL_PushFront(int _value)
{

	listNode* pNewNode = new listNode;
	pNewNode->m_nValue = _value;

	pNewNode->m_pNextNode = m_pNodeTop;
	//새로운 노드의 NextNode에 top노드 주소를...
	m_pNodeTop = pNewNode;
}

void linkedList::SLL_Push(listNode * _currNode, int _value)
{
	//새로운 노드 
	listNode* pNewNode = new listNode;
	pNewNode->m_nValue = _value;

	pNewNode->m_pNextNode = _currNode->m_pNextNode;
	_currNode->m_pNextNode = pNewNode;
}

void linkedList::SLL_EraseValue(int _value)
{
	listNode* pCurrNode = m_pNodeTop;
	listNode* pPrevNode = nullptr;

	while (pCurrNode)
	{
		if (pCurrNode->m_nValue == _value)
		{
			//첫번째 노드가 지워지면 현재 노드랑 탑노드랑 같을수밖에없지
			if (pCurrNode == m_pNodeTop)// 지울 노드가 탑노드일 경우
			{
				m_pNodeTop = pCurrNode->m_pNextNode;
			}
			else
			{
				pPrevNode->m_pNextNode = pCurrNode->m_pNextNode;
				//curr 지우기 전에 넥스트 값을 넣어주고
			}
			delete pCurrNode; //지우기
			break;
		}
		pPrevNode = pCurrNode;
		pCurrNode = pCurrNode->m_pNextNode;
	}
}

void linkedList::SLL_Erase(listNode * _delNode)
{
	listNode* pCurrNode = m_pNodeTop;
	listNode* pPrevNode = nullptr;

	while (pCurrNode)
	{
		if (pCurrNode == _delNode)
		{
			//첫번째 노드가 지워지면 현재 노드랑 탑노드랑 같을수밖에없지
			if (pCurrNode == m_pNodeTop)// 지울 노드가 탑노드일 경우
			{
				m_pNodeTop = pCurrNode->m_pNextNode;
			}
			else
			{
				pPrevNode->m_pNextNode = pCurrNode->m_pNextNode;
				//curr 지우기 전에 넥스트 값을 넣어주고
			}
			delete pCurrNode; //지우기
			break;
		}
		pPrevNode = pCurrNode;
		pCurrNode = pCurrNode->m_pNextNode;
	}
}

void linkedList::SLL_Draw(void)
{
	listNode* pCurrNode = m_pNodeTop;

	while (pCurrNode) //데이터가 있다면
	{
		printf("%d ", pCurrNode->m_nValue);

		pCurrNode = pCurrNode->m_pNextNode;
	}
}

void linkedList::SLL_Clear(void)
{
	listNode* pCurrNode = m_pNodeTop;
	listNode* pDelNode = nullptr;

	while (pCurrNode)
	{
		pDelNode = pCurrNode;
		pCurrNode = pCurrNode->m_pNextNode;

		delete pDelNode;
	}
}

listNode * linkedList::SLL_GetNodeEqualValue(int _value)
{
	listNode* pCurrNode = m_pNodeTop;
	//처음부터 모두 찾아야해

	while (pCurrNode) //값이 있다면
	{
		if (pCurrNode->m_nValue == _value)
		{
			return pCurrNode;
		}
		pCurrNode = pCurrNode->m_pNextNode;
	}

	return nullptr;
}

listNode * linkedList::SLL_GetNodeIndex(int _idx)
{
	listNode* pCurrNode = m_pNodeTop;

	while (pCurrNode)
	{
		if (_idx <= 0)
		{
			return pCurrNode;
		}
		_idx--;
		//idx가 0이 되면 pCurrNode
		pCurrNode = pCurrNode->m_pNextNode;
	}

	return nullptr;
}

int linkedList::SLL_Size(void)
{
	int nCnt = 0;
	listNode* pCurrNode = m_pNodeTop;

	while (pCurrNode)
	{
		nCnt++;
		pCurrNode = pCurrNode->m_pNextNode;
	}
	return nCnt;
}

linkedList::linkedList()
{
	m_pNodeTop = nullptr;
}


linkedList::~linkedList()
{
	SLL_Clear();
}
