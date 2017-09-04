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