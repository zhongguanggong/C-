#include<stdio.h>
#include<stdlib.h>
struct Node{
    char name[16];
    struct Node *next;
};

struct Node *head;
int creatlist(int n)
{
    struct Node *tmp,*p;
	int i=0;
	head=(struct Node *)malloc(sizeof(struct Node)); 
    p=head;
    for(i=1;i<=n;i++) 
    {
        tmp=(struct Node *)malloc(sizeof(struct Node));
		scanf("%s",tmp->name);
        p->next=tmp;
        p=tmp;
    }
    tmp->next=head->next;    //���һ���ڵ�nextָ��ָ���һ���ڵ�
    return 0;
}

int outline(int s,int w)
{
    struct Node *p,*q,*o;
 int i;
    p=head->next;
 for(i=1;i<s;i++)//��Ĵ���ûʲô������⣬�����������ʧ��д���˰�
  p=p->next;
 while(p->next!=p)
 {
  for(i=1;i!=w;i++)
  {
   q=p;
   p=p->next;
  }//Ҫɾ���ľ������ڵ�p
  o=p->next;
  q->next=p->next;
  printf("%s\n",p->name);
  free(p);
  p=o;
 }

printf("%s\n",p->name); 
    free(p);
    free(head); 
    return 0;
}

int main()
{
    int n,s,w;
    scanf("%d",&n);
 creatlist(n);
 scanf("%d,%d",&s,&w);
    outline(s,w);
 return 0;
 
}