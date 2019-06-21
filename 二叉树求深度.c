#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* ÊµÏÖÏ¸½ÚºöÂÔ */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

BinTree CreatBinTree()
{
	BinTree T;
	ElementType e;
	scanf("%c",&e);
	if(!e) return NULL;
	else{
		T = (BinTree)malloc(sizeof(struct TNode));
		if(!T)
	
	}
}

int GetHeight( BinTree BT )
{
	int depth;
	if(!BT) return 0;
	else{
		depth = (GetHeight(BT->Left)>GetHeight(BT->Right)? GetHeight(BT->Left):GetHeight(BT->Right))+1;
	}
	return depth;
}