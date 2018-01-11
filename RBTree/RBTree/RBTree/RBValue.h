/*
	by 吴云飞 2017/08/22
		红黑树的节点类，不对外开放
	功能：提供红黑树的基本操作，可由
*/

#ifndef _RBVALUE_H_
#define _RBVALUE_H_
class RBValue{
public:
	struct RBResult{
		enum{
			ISHEAD = 1,
			SUCCESS = 0,
		};
	};
public:
	RBValue() : m_iValue(0),
		m_iBlack(0),
		m_nBlackHeight(-1),
		m_pPreNode(this),
		m_pNextNode(this),
		m_pParent(this),
		m_pLeftChild(this),
		m_pRightChild(this){}
	RBValue(int value) : m_iValue(value),
		m_iBlack(0),
		m_nBlackHeight(-1),
		m_pPreNode(this),
		m_pNextNode(this),
		m_pParent(this),
		m_pLeftChild(this),
		m_pRightChild(this){}
	int insert(RBValue*); 
	int check();
	virtual ~RBValue(){}
private:
	RBValue(const RBValue&);
	const RBValue& operator=(const RBValue&);				//暂时拒绝使用拷贝构造函数和赋值构造函数

	int ResetBlackHeight();									//将当前节点以及所有子节点的黑高置为-1，供check时使用
	int CalBlackHeight();									//通过动态规划，重新计算当前根下所有节点黑高

	int CheckHead();										//检查当前节点是否是头节点 --头节点判断方式为父节点为本身，是头节点返回1，不是返回0

private:
	int m_iValue;
	int m_iBlack;											//当black为1，节点为黑色，总黑色节点数目可通过树中所有的black节点计算得出
	int m_nBlackHeight;										//通过Check得出各个节点的BlackHeight，检验红黑树的特性5
	RBValue* m_pPreNode;
	RBValue* m_pNextNode;
	RBValue* m_pParent;
	RBValue* m_pLeftChild;
	RBValue* m_pRightChild;
};

bool operator >(const RBValue&, const RBValue&);
bool operator >=(const RBValue&, const RBValue&);
bool operator <(const RBValue&, const RBValue&);
bool operator <=(const RBValue&, const RBValue&);
bool operator ==(const RBValue&, const RBValue&);

#endif