#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n,m,s,d;
    scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&s);
	scanf("%d",&d);
    int G[n][n];//建立矩阵表
    int num[n];
    int max[n];
    int pathnum[n];
    int INF = 100000;
    int D[n];//出发点 经过 选定点 到 当前[待定集合中的顶点] 的最短路
    int final[n];
    char str[500][500];

    for(int i=0;i<n;i++){
        final[i] = 0;
    }

    for(int i=0;i<n;i++){//输入救援队数量
        scanf("%d",&num[i]);
    }
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){//初始化道路长度
            G[a][b] = INF;
            G[b][a] = INF;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d",&a);//城市1
		scanf("%d",&b);//城市2
		scanf("%d",&c);//道路长度
        G[a][b] = c;
		G[b][a] = c;
    }
    //先求最短路径
    //初始化
    final[s] = 1;D[s] = 0;
    for(int v=0;v<n;v++){
        D[v] = G[s][v];
        if(D[v]<INF){
            max[v] = num[v] + num[s];
            pathnum[v] = 1;
            //路径初始化
            char tem[10];
            sprintf(tem,"%d",s);
            strcat(str[v],tem);
            strcat(str[v]," ");
            sprintf(tem,"%d",v);
            strcat(str[v],tem);
        }
    }
    for(int i=1;i<n;i++){

        int min = INF,v;
        for(int w=0;w<n;w++)
        if(final[w]==0&&D[w]<min){//找到最短点
            v = w;min = D[w];
        }

        final[v] = 1;//并入
        for(int w=0;w<n;w++){ //更新
            //printf("%d  %d  %d  %d-----\n",final[w],min,G[v][w],D[w]);
            if(final[w]==0&&(min+G[v][w]==D[w])){
                pathnum[w] = pathnum[v] + pathnum[w];
                if(max[w]<max[v]+num[w]){
                    max[w] = max[v] + num[w];
                    //更改路径
                char tem[10];
                strcpy(str[w],str[v]);
                strcat(str[w]," ");
                sprintf(tem,"%d",w);
                strcat(str[w],tem);

                }

            }
            if(final[w]==0&&(min+G[v][w]<D[w])){
                D[w] = min + G[v][w];
                pathnum[w] = pathnum[v];
                max[w] = max[v]+num[w];
                //更改路径
                char tem[10];
                strcpy(str[w],str[v]);
                strcat(str[w]," ");
                sprintf(tem,"%d",w);
                strcat(str[w],tem);
            }
        }
    }
    printf("%d ",pathnum[d]);
    printf("%d\n",max[d]);
    printf("%s",str[d]);
    return 0;
}
