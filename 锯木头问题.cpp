#include<stdio.h>
#include<stdlib.h>
//#include<string.h>

#define unint unsigned int
#define OK 1
#define ERROR 0

typedef int Status;

typedef struct{
  int weight;
  int parent,lchild,rchild;
}HTNode;
typedef HTNode *HuffmanTree;

//typedef char * *HuffmanCode;

Status Select(HuffmanTree HT,int n,int &s1,int &s2)
{
	int i;
	if(n<=1) return ERROR;
	/*for(i=1;i<=n;i++)
	{
		if(HT[i].parent == 0)
		{
			s1 = i;
			break;
		}
	}
	for(i = i+1;i<=n;i++)
	{
		if(HT[i].parent == 0)
		{
			s2 = i;
			break;
		}
	}
	if(HT[s1].weight>HT[s2].weight)
	{
		j = s1;
		s1 = s2;
		s2 = j;
	}*/
	s1 = n-1;   
	s2 = n;
	for(i = 1;i<=n;i++)
	{
		if(HT[i].parent == 0)
		{
			if(HT[i].weight<HT[s1].weight) 
			{
				s1 = i;
			}
			if((HT[i].weight==HT[s1].weight)||(HT[i].weight>HT[s1].weight&&(HT[i].weight<HT[s2].weight))) s2 = i;
		}
	
	}
		//printf("%d %d\n",s1,s2);
	return OK;
}

Status HuffmanCoding(HuffmanTree &HT,int *w,int n,int &money){//n为字符数,w为权值数组,构造Huffman树HT,并求Huffman编码HC
	HuffmanTree p;
	int s1,s2,m,i;
	if(n<=1)return ERROR;
	m=2*n-1;//Huffman树的结点总数
 
	HT = (HTNode *) malloc ((m+1)*sizeof(HTNode));
																	//HT=new HTNode[m+1];//0单元不用,先存叶后分支
	for(p=HT+1,i=1;i<=n;++i,++p,++w) {
		p->weight = *w;
		p->lchild = 0;
		p->parent = 0;
		p->rchild = 0;
	}						//初始化叶子,代码要变
	for(i=n+1;i<=m;++i)
	{ 
		p->weight = 0;
		p->lchild = 0;
		p->parent = 0;
		p->rchild = 0; 
		++p;
	}//初始化分支结点,不确定先写0
	for(i=n+1;i<=m;++i){   //建Huffman树
	Select(HT,i-1,s1,s2);//在HT[1..i-1]中选择paren为0且权最 
                        //小的两结点，设下标分别为s1和s2
	HT[s1].parent=i;   HT[s2].parent=i;
	//HT[i]={HT[s1].weight+HT[s2].weight, 0 ,s1,s2};
		HT[i].weight = HT[s1].weight+HT[s2].weight;
		HT[i].lchild = s1;
		HT[i].parent = 0;
		HT[i].rchild = s2; 
	}
	 /*HC=(HuffmanCode)malloc((n+1)*sizeof(char*));//开辟n指针,各指向一编码串
	 cd=(char *)malloc(n*sizeof(char));//存编码的临时空间, 编码最长n-1
	 cd[n-1]=‘\0’; //作编码结束符，书中用”\0”
	 start=n-1;
	 for(i=1;i<=n;++i){ //逐个叶结点求其编码
	 for(f=HT[i].parent,c=i; f!=0;c=f,f=HT[f].parent)//叶到根逆向求编码
     if(HT[f].lchild==c)cd[--start]=‘0’;  else cd[--start]=‘1’;
	 HC[i]=(char *)malloc((n-start))*sizeof(char));
	 strcpy(HC[i],&cd[start]);//复制到HC的相应位置*/
	money = 0;
	for(i=n+1;i<=2*n-1;i++)
	{
		money = money + HT[i].weight;
		//money = money+(HT[i].weight * (2*n-1-HT[i].parent));
	}
	return OK;

 } 


int main()
{
	int *w,*p;
	int n;
	int i,money;
	HuffmanTree HT;
	scanf("%d",&n);
	w = (int *)malloc(n * sizeof(int));
	p = w;
	for(i = 0;i<n;++i)
	{
		p = w+i;
		scanf("%d",p);
	}
	HuffmanCoding(HT,w,n,money);
	printf("%d",money);
	return 0;
}
