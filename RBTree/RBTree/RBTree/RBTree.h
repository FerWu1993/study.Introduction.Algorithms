/*
	by 吴云飞 2017/08/18
	红黑树
	特性：
	1、每个节点都有确定的颜色，只能为 red或black 中的一个
	2、根节点是黑色
	3、叶节点是黑色NIL
	4、红节点的孩子必为黑色
	5、每个节点到所有后代叶子节点的路径上有同样多的黑色节点
	version
	2017/0818  ： 构建树的值的基类
	2017/08/18 ： 实现树的基本功能
	时间复杂度 ：insert log_n
	


*/
#ifndef _RBTREE_H_
#define _RBTREE_H_

#include "RBValue.h"

class CRBTree{
public:
	CRBTree() : Head() { }
private:
	RBValue* Head;
};

#endif