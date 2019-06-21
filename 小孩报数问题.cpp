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
    tmp->next=head->next;    //最后一个节点next指针指向第一个节点
    return 0;
}

int outline(int s,int w)
{
    struct Node *p,*q,*o;
 int i;
    p=head->next;
 for(i=1;i<s;i++)//你的代码没什么大的问题，就是这里可能失误写错了吧
  p=p->next;
 while(p->next!=p)
 {
  for(i=1;i!=w;i++)
  {
   q=p;
   p=p->next;
  }//要删除的就是现在的p
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