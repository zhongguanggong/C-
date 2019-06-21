#include <stdio.h>

#define MAX_VERTEX_NUM 101
#define INFINITY       10000
//prime算法从顶点入手
struct Edge{
    int  adjvex;//U中 到当前点(数组下标)最近的点名称
    int lowcost;//U中 点到当前点的最小代价
}closedge[MAX_VERTEX_NUM];//这里已经开辟了空间

void MinSpanTree_Prime(int G[MAX_VERTEX_NUM][MAX_VERTEX_NUM] ,int n){
    int sum=0;
    //用prime算法从第1个顶点(从哪个点出发无所谓)出发求网G的最小生成树，输出各边
    closedge[1].lowcost = -1;//将第0个顶点并入到U中

    for(int j=2;j<=n;j++){
        //更新除了1外的顶点，包括与U中最近的点及其代价

         if(G[j][1]<closedge[j].lowcost){
                closedge[j].adjvex  = 1;
                closedge[j].lowcost = G[j][1];
            }
    }
    for(int i=1;i<n;i++){//共n-1轮，每轮找出最小边输出，赋0更新

        int k = INFINITY;
         for(int j=1;j<=n;j++){//先找到一个非零的k
            if(closedge[j].lowcost!=-1){
                k = j;break;
            }
        }
        for(int j=1;j<=n;j++){//代价非零的元素中找最小元素,返下标
            if(closedge[j].lowcost!=-1)
                if(closedge[j].lowcost<closedge[k].lowcost)
                    k = j;
        }

        sum += closedge[k].lowcost;
        closedge[k].lowcost = -1;//选择一个最小的并进来
        //根据k结点更新数组元素代价
        for(int j=1;j<=n;j++){
            if(G[j][k]<closedge[j].lowcost){
                closedge[j].adjvex  = k;
                closedge[j].lowcost = G[j][k];
            }
        }
    }
    printf("%d",sum);
}


int main(){
    int n,m;
    int G[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//先用邻接矩阵,1000*1000会发生超内存
    //G先初始化为无穷

    for(int i=1;i<MAX_VERTEX_NUM;i++){
        for(int j=1;j<MAX_VERTEX_NUM;j++){
            G[i][j] = INFINITY;
        }
    }
    for(int i=0;i<MAX_VERTEX_NUM;i++){
        closedge[i].lowcost = INFINITY;
    }
    scanf("%d",&n);
    m = n*(n-1)/2;
    for(int i=0;i<m;i++){
        int t1,t2,t3,t4;
        scanf("%d",&t1);
        scanf("%d",&t2);
        scanf("%d",&t3);
        scanf("%d",&t4);
        if(t4==1)
            t3 = 0;
        G[t1][t2] = t3;
        G[t2][t1] = t3;
    }

    MinSpanTree_Prime(G,n);
    return 0;
}
