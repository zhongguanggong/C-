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
int GetHeight( BinTree BT )
{
    if(BT == NULL) return 0;
    int a = GetHeight(BT->Left);
    int b = GetHeight(BT->Right);
    if(a>b)
	{
        return a+1;
    }
	else
	{
        return b+1;
    }

}