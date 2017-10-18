#include "linkedList.h"
#include "listNode.h"
#include <stdio.h>

void linkedList::SLL_PushBack(int _value) //������ ��忡 �ִ� �Լ�
{
	//���ο� ���
	listNode* pNewNode = new listNode; //value�� ���� ��带 �ϳ� ������
	pNewNode->m_nValue = _value; //�� ���� ���� ���ο� ��尡 ���� ��

	//top node�� null �̶��(�ƹ��� �����Ͱ� ���� ��)
	if (m_pNodeTop == nullptr)
	{
		m_pNodeTop = pNewNode;
		//���ο� ��尡 ž
	}
	else //��尡 �ִٸ�
	{
		listNode *pTailNode = m_pNodeTop;
		
		while (pTailNode->m_pNextNode != nullptr)
		{
			pTailNode = pTailNode->m_pNextNode;
			//��� �Ѿ�ٺ��� null�� ���� ��.
		}
		pTailNode->m_pNextNode = pNewNode;
	}
}

void linkedList::SLL_PushFront(int _value)
{

	listNode* pNewNode = new listNode;
	pNewNode->m_nValue = _value;

	pNewNode->m_pNextNode = m_pNodeTop;
	//���ο� ����� NextNode�� top��� �ּҸ�...
	m_pNodeTop = pNewNode;
}

void linkedList::SLL_Push(listNode * _currNode, int _value)
{
	//���ο� ��� 
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
			//ù��° ��尡 �������� ���� ���� ž���� �������ۿ�����
			if (pCurrNode == m_pNodeTop)// ���� ��尡 ž����� ���
			{
				m_pNodeTop = pCurrNode->m_pNextNode;
			}
			else
			{
				pPrevNode->m_pNextNode = pCurrNode->m_pNextNode;
				//curr ����� ���� �ؽ�Ʈ ���� �־��ְ�
			}
			delete pCurrNode; //�����
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
			//ù��° ��尡 �������� ���� ���� ž���� �������ۿ�����
			if (pCurrNode == m_pNodeTop)// ���� ��尡 ž����� ���
			{
				m_pNodeTop = pCurrNode->m_pNextNode;
			}
			else
			{
				pPrevNode->m_pNextNode = pCurrNode->m_pNextNode;
				//curr ����� ���� �ؽ�Ʈ ���� �־��ְ�
			}
			delete pCurrNode; //�����
			break;
		}
		pPrevNode = pCurrNode;
		pCurrNode = pCurrNode->m_pNextNode;
	}
}

void linkedList::SLL_Draw(void)
{
	listNode* pCurrNode = m_pNodeTop;

	while (pCurrNode) //�����Ͱ� �ִٸ�
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
	//ó������ ��� ã�ƾ���

	while (pCurrNode) //���� �ִٸ�
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
		//idx�� 0�� �Ǹ� pCurrNode
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
