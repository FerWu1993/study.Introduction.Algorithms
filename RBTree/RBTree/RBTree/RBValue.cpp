#include "RBValue.h"

int RBValue::ResetBlackHeight()
{
	if (CheckHead() == RBResult::ISHEAD)
	{
		return 0;
	}
	m_nBlackHeight = -1;
	m_pLeftChild->ResetBlackHeight();
	m_pRightChild->ResetBlackHeight();
	return 0;
}

int RBValue::CheckHead()
{
	if (m_pParent == this)
	{
		return RBResult::ISHEAD;
	}
	else
	{
		return RBResult::SUCCESS;
	}
}
//RBValue::~RBValue()												//考虑到叶子节点的删除不需要我们处理
//{
//	if (m_pLeftChild->CheckHead() != RBResult::ISHEAD)				//如果是叶子节点 head，不delete其子树
//	{
//		delete m_pLeftChild;
//	}
//	if (m_pRightChild->CheckHead() != RBResult::ISHEAD)				//如果是叶子节点 head，不delete其子树
//	{
//		delete m_pRightChild;
//	}
//}