#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define Wall 1
#define Road 0
#define Start 2
#define End 3
#define Esc 5
#define Up 1
#define Down 2
#define Left 3
#define Right 4
int map[100][39];
int path[1000];//0�ϣ�1�£�2��3��
int b[100][39];//����Ƿ���ʹ�

void gotoxy(int x,int y) //�ƶ�����
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void hidden()//���ع��
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=0;//��1Ϊ��ʾ����0Ϊ����
    SetConsoleCursorInfo(hOut,&cci);
}
void create(int x,int y) //��������Թ�
{
    int c[4][2]={0,1,1,0,-1,0,0,-1}; //���飬��Ӧ�������ң����ϣ������ĸ�����
    int i,j,t;
    //���������,�ĸ������ֵ��ǽ���
    for(i=0;i<4;i++)
    {
        j=rand()%4;
        t=c[i][0];c[i][0]=c[j][0];c[j][0]=t;
        t=c[i][1];c[i][1]=c[j][1];c[j][1]=t;
    }
    //printf("%d %d\n",x,y);
    map[x][y]=Road;
    for(i=0;i<4;i++){
        //printf("%d %d\n",c[i][0],c[i][1]);
        if(map[x+2*c[i][0]][y+2*c[i][1]]==Wall)//x,y��Ϊ��·��������ĸ��ڵĸ�����ǽ���������ĸ�����·
        {
            map[x+c[i][0]][y+c[i][1]]=Road;
            create(x+2*c[i][0],y+2*c[i][1]);//�����ĸ��ڵĸ���Ϊ������ٵݹ�
        }}
}
int get_key() //���հ���
{
    char c;
    while(c=getch())
    {
        if(c==27) return Esc; //Esc
        if(c!=-32)continue;
        c=getch();
        if(c==72) return Up; //��
        if(c==80) return Down; //��
        if(c==75) return Left; //��
        if(c==77) return Right; //��
    }
    return 0;
}

void paint(int x,int y) //���Թ�
{
    gotoxy(2*y-2,x-1);
    switch(map[x][y])
    {
        case Start:
        printf("��");break; //�����
        case End:
        printf("��");break; //������
        case Wall:
        printf("��");break; //��ǽ
        case Road:
        printf(" ");break; //��·
    }
}

void findpath()
{
    int x=2,y=1; //��ҵ�ǰλ�ã��տ�ʼ����ڴ�
    int c; //�������հ���
    int d = 0;
    while(1)
    {

        gotoxy(2*y-2,x-1);
        printf("��"); //������ҵ�ǰλ��
        if(map[x][y]==End) //�ж��Ƿ񵽴����
        {
            gotoxy(30,24);
            printf("�Զ�Ѱ·�����յ㣬�����������");
            getch();
            break;
        }
        ////////////////////////
        c=path[d++];
        Sleep(100);
        ////////////////////////
        if(c==Esc)
        {
            gotoxy(0,24);
            break;
        }
        switch(c)
        {
            case Up: //������
                if(map[x-1][y]!=Wall)
                {
                    paint(x,y);
                    x--;
                }
                break;
            case Down: //������
                if(map[x+1][y]!=Wall)
                {
                    paint(x,y);
                    x++;
                }
                break;
            case Left: //������
                if(map[x][y-1]!=Wall)
                {
                    paint(x,y);
                    y--;
                }
                break;
            case Right: //������
                if(map[x][y+1]!=Wall)
                {
                    paint(x,y);
                    y++;
                }
                break;
        }
    }
}

//1�ϣ�2�£�3��4��
int find(int x,int y,int d){//�Զ�Ѱ·
    //printf("%d %d %d\n",x,y,map[x][y]);
    b[x][y] = 1;
    if(map[x][y]==End)
        return 1;

    if((map[x-1][y] == Road || map[x-1][y] == End) && b[x-1][y] == 0){ path[d] = 1;if(find(x-1,y,d+1)==0)path[d] = 0;else return 1;}
    if((map[x+1][y] == Road || map[x+1][y] == End) && b[x+1][y] == 0){ path[d] = 2;if(find(x+1,y,d+1)==0)path[d] = 0;else return 1;}
    if((map[x][y-1] == Road || map[x][y-1] == End) && b[x][y-1] == 0){ path[d] = 3;if(find(x,y-1,d+1)==0)path[d] = 0;else return 1;}
    if((map[x][y+1] == Road || map[x][y+1] == End) && b[x][y+1] == 0){ path[d] = 4;if(find(x,y+1,d+1)==0)path[d] = 0;else return 1;}

    b[x][y] = 0;
   return 0;
}


void game()
{
int x=2,y=1; //��ҵ�ǰλ�ã��տ�ʼ����ڴ�
int c; //�������հ���
while(1)
{
gotoxy(2*y-2,x-1);
printf("��"); //������ҵ�ǰλ��
if(map[x][y]==End) //�ж��Ƿ񵽴����
{
gotoxy(30,24);
printf("�����յ㣬�����������");
getch();
break;
}
	c=get_key();
	if(c==Esc)
	{
		gotoxy(0,24);
		break;
	}
	switch(c)
	{
		case Up: //������
		if(map[x-1][y]!=Wall)
	{
	paint(x,y);
	x--;
	}
	break;
	case Down: //������
	if(map[x+1][y]!=Wall)
	{
		paint(x,y);
		x++;
	}
	break;
	case Left: //������
	if(map[x][y-1]!=Wall)
	{
	paint(x,y);
	y--;
	}
	break;
	case Right: //������
	if(map[x][y+1]!=Wall)
	{
	paint(x,y);
	y++;
	}
	break;
	}
	}
}

int main()
{

    int i,j;
    int Height=50,Width = 35;
    for(i=0;i<1000;i++){
        path[i] = 0;
    }
    for(i=0;i<100;i++){
       for(j=0;j<100;j++){
        b[i][j] = 0;
       }
    }
    srand((unsigned)time(NULL)); //��ʼ���漴����
    hidden(); //���ع��
    for(i=0;i<=Height+1;i++)
        for(j=0;j<=Width+1;j++)
            if(i==0||i==Height+1||j==0||j==Width+1) //��ʼ���Թ�//�������Height+1,����ֻ�� 1<-->Height �ڵ�
                map[i][j]=Road;
            else
                map[i][j]=Wall;

    //////////////////////////////
    create(2,2); //�����һ���㿪ʼ�����Թ����õ����ж�Ϊż��
    /////////////////////////////

    for(i=0;i<=Height+1;i++) //�߽紦��
    {
    map[i][0]=Wall;
    map[i][Width+1]=Wall;
    }

    for(j=0;j<=Width+1;j++) //�߽紦��
    {
    map[0][j]=Wall;
    map[Height+1][j]=Wall;
    }
    map[2][1]=Start; //�������
    map[Height-1][Width]=End; //��������
    for(i=1;i<=Height;i++)
    for(j=1;j<=Width;j++) //�����Թ�
    paint(i,j);

    ////////////////////////////////////
    find(2,1,0);
    findpath(); //�Զ�Ѱ·
    ////////////////////////////////////

    game(); //��ʼ��Ϸ
    getch();
    return 0;
}

