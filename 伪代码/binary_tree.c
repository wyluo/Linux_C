/*
 *二叉树的链式存储
 */
struct ElemType
{
	int value;
};

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//定义一颗空树
BiTree root = NULL;

//插入根节点
root = (BiTree) malloc(sizeof(BiTNode));
root->data = {1};
root->lchild = NULL;
root->rchild = NULL;

//插入新结点
BiTNode *p = (BiTNode *) malloc(sizeof(BiTNode));
p->data = {2};
p->lchild = NULL;
p->rchild = NULL;
root->lchild = p;//作为根节点的左孩子

//二叉树的结点（链式存储）
typedef struct BiTNode
{
	ElemType data;                      //数据域
	struct BiTNode *lchild, *rchild;    //左/右孩子指针
	struct BiTNode *parent;             //父节点指针---三叉链表，方便找父结点
}BiTNode, *BiTree;

/*
 *先序遍历
 *1.若二叉树为空，则什么都不做
 *2.若二叉树非空
 *   1）.访问根节点
 *   2）.先序遍历左子树
 *   3）.先序遍历右子树
 */
void PreOrder(BiTree T)
{
	if(T != NULL)
	{
		//若需要其他遍历方式---中序遍历---后序遍历，则调整以下的执行顺序
		visit(T);//访问根节点
		PreOrder(T->lchild);//递归遍历左子树
		PreOrder(T->rchild);//递归遍历右子树
	}
}

//求树的深度
int treeDepth(BiTree T)
{
	if(T == NULL)
	{
		return 0;
	}
	int l = treeDepth(T->lchild);
	int r = treeDepth(T->rchild);
	//树的深度=Max（左子树深度，右子树深度）+1
	return l > r ? l+1 : r+1;
}

/*
 *层序遍历
 *初始化一个辅助队列
 *根节点入队
 *若队列非空，则队头结点出队，访问该结点，并将其左，右孩子插入队尾（如果有的话）
 *重复上一步，直至队列为空
 */
//链式队列结点
typedef struct LinkNode
{
	BiTNode *data;
	struct LinkNode *next;
}LinkNode;

typedef struct
{
	LinkNode *front, *rear;//队头队尾
}LinkQueue;

void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q);//初始化辅助队列
	BiTree p;
	EnQueue(Q, T);//将根结点入队
	while(!IsEmpty(Q))//队列不空，则循环
	{
		DeQueue(Q, p);//队头结点出队
		visit(p);//访问队结点
		if(p->lchild != NULL)
		{
			EnQueue(Q, p->lchild);//左孩子入队
		}
		if(p->rchild != NULL)
		{
			EnQueue(Q, rchild);//右孩子入队
		}
	}
}