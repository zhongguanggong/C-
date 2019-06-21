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

Status HuffmanCoding(HuffmanTree &HT,int *w,int n,int &money){//nΪ�ַ���,wΪȨֵ����,����Huffman��HT,����Huffman����HC
	HuffmanTree p;
	int s1,s2,m,i;
	if(n<=1)return ERROR;
	m=2*n-1;//Huffman���Ľ������
 
	HT = (HTNode *) malloc ((m+1)*sizeof(HTNode));
																	//HT=new HTNode[m+1];//0��Ԫ����,�ȴ�Ҷ���֧
	for(p=HT+1,i=1;i<=n;++i,++p,++w) {
		p->weight = *w;
		p->lchild = 0;
		p->parent = 0;
		p->rchild = 0;
	}						//��ʼ��Ҷ��,����Ҫ��
	for(i=n+1;i<=m;++i)
	{ 
		p->weight = 0;
		p->lchild = 0;
		p->parent = 0;
		p->rchild = 0; 
		++p;
	}//��ʼ����֧���,��ȷ����д0
	for(i=n+1;i<=m;++i){   //��Huffman��
	Select(HT,i-1,s1,s2);//��HT[1..i-1]��ѡ��parenΪ0��Ȩ�� 
                        //С������㣬���±�ֱ�Ϊs1��s2
	HT[s1].parent=i;   HT[s2].parent=i;
	//HT[i]={HT[s1].weight+HT[s2].weight, 0 ,s1,s2};
		HT[i].weight = HT[s1].weight+HT[s2].weight;
		HT[i].lchild = s1;
		HT[i].parent = 0;
		HT[i].rchild = s2; 
	}
	 /*HC=(HuffmanCode)malloc((n+1)*sizeof(char*));//����nָ��,��ָ��һ���봮
	 cd=(char *)malloc(n*sizeof(char));//��������ʱ�ռ�, �����n-1
	 cd[n-1]=��\0��; //������������������á�\0��
	 start=n-1;
	 for(i=1;i<=n;++i){ //���Ҷ����������
	 for(f=HT[i].parent,c=i; f!=0;c=f,f=HT[f].parent)//Ҷ�������������
     if(HT[f].lchild==c)cd[--start]=��0��;  else cd[--start]=��1��;
	 HC[i]=(char *)malloc((n-start))*sizeof(char));
	 strcpy(HC[i],&cd[start]);//���Ƶ�HC����Ӧλ��*/
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
