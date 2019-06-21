#include <stdio.h>

#define MAX_VERTEX_NUM 101
#define INFINITY       10000
//prime�㷨�Ӷ�������
struct Edge{
    int  adjvex;//U�� ����ǰ��(�����±�)����ĵ�����
    int lowcost;//U�� �㵽��ǰ�����С����
}closedge[MAX_VERTEX_NUM];//�����Ѿ������˿ռ�

void MinSpanTree_Prime(int G[MAX_VERTEX_NUM][MAX_VERTEX_NUM] ,int n){
    int sum=0;
    //��prime�㷨�ӵ�1������(���ĸ����������ν)��������G����С���������������
    closedge[1].lowcost = -1;//����0�����㲢�뵽U��

    for(int j=2;j<=n;j++){
        //���³���1��Ķ��㣬������U������ĵ㼰�����

         if(G[j][1]<closedge[j].lowcost){
                closedge[j].adjvex  = 1;
                closedge[j].lowcost = G[j][1];
            }
    }
    for(int i=1;i<n;i++){//��n-1�֣�ÿ���ҳ���С���������0����

        int k = INFINITY;
         for(int j=1;j<=n;j++){//���ҵ�һ�������k
            if(closedge[j].lowcost!=-1){
                k = j;break;
            }
        }
        for(int j=1;j<=n;j++){//���۷����Ԫ��������СԪ��,���±�
            if(closedge[j].lowcost!=-1)
                if(closedge[j].lowcost<closedge[k].lowcost)
                    k = j;
        }

        sum += closedge[k].lowcost;
        closedge[k].lowcost = -1;//ѡ��һ����С�Ĳ�����
        //����k����������Ԫ�ش���
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
    int G[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�����ڽӾ���,1000*1000�ᷢ�����ڴ�
    //G�ȳ�ʼ��Ϊ����

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
