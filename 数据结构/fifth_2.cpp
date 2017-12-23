#include <iostream>
using namespace std;
//#include "LinkedQueue.h"
//���ж���
class Position
{
    friend bool FindPath(Position start,Position finish,int& PathLen,Position* &path);
    friend void Q3();
private:
    int row;
    int col;
};

template <class T>
class LinkedQueue;
template <class T>
class Node
{
    friend LinkedQueue<T>;
private:
    T data;
    Node<T>* link;
};
template <class T>
class LinkedQueue

{


public:
    LinkedQueue(){front=rear=NULL;}
    ~LinkedQueue();
    bool IsEmpty() const{return front==NULL;}
    bool IsFull() const;
    T First() const;
    T Last() const;
    LinkedQueue<T>& Add(const T& x);
    LinkedQueue<T>& Delete(T& x);
private:
    Node<T>* front;
    Node<T>* rear;

};



class OutOfBounds
{
public:
    OutOfBounds(){}
};
class NoMem
{
public:
    NoMem(){}
};
template <class T>
LinkedQueue<T>:: ~LinkedQueue()
{
    Node<T>* next;
    while(front)
    {
        next=front->link;
        delete front;
        front=next;
    }
}

template <class T>
bool LinkedQueue<T>:: IsFull() const
{
    try
    {
        Node<T>* p=new Node<T>;
        delete p;
        return false;
    }
    catch(NoMem())
    {
        return true;
    }
}

template <class T>
T LinkedQueue<T>:: First()const
{
    if(IsEmpty())
        throw OutOfBounds();
    return front->data;
}

template <class T>
T LinkedQueue<T>:: Last() const
{
    if(IsEmpty())
        throw OutOfBounds();
    return rear->data;
}

template <class T>
LinkedQueue<T>& LinkedQueue<T>:: Add(const T& x)
{
    Node<T>* p=new Node<T>;
    p->data=x;
    p->link=NULL;
    if(front==NULL)
        front=p;
    else
    {
        rear->link=p;
    }
    rear=p;
    return *this;
}

template <class T>
LinkedQueue<T>& LinkedQueue<T>:: Delete(T& x)
{
    if(IsEmpty())
        throw OutOfBounds();
    Node<T>* p=front;
    x=p->data;
    if(front==rear)
      front=rear=NULL;
    else
        front=front->link;
    delete p;
    return *this;

}

//��·���߷���
int grid[8][8]=
{
    {1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1},
    {1,1,0,0,0,1,0,1},
    {1,0,1,1,0,0,0,1},
    {1,0,0,0,1,1,0,1},
    {1,0,1,1,1,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1},
};
int m1=6;
bool FindPath(Position start,Position finish,int& PathLen,Position* &path)
{
    if((start.row==finish.row)&&(start.col==finish.col))
    {
        PathLen=0;
        return true;
    }
    for(int i=0;i<=m1+1;i++)//��ʼ�����������Χǽ
    {
        grid[0][i]=grid[m1+1][i]=1;
        grid[i][0]=grid[i][m1+1]=1;
    }
    Position offset[4];
    offset[0].row=0; offset[0].col=1;//��
    offset[1].row=1; offset[1].col=0;//��
    offset[2].row=0; offset[2].col=-1;//��
    offset[3].row=-1; offset[3].col=0;//��

    int NumOfNbr=4;//һ������λ�õ�����λ����
    Position here,nbr;
    here.row=start.row;
    here.col=start.col;

    grid[start.row][start.col]=2;

    LinkedQueue<Position> Q;

    do//��ǿɵ��������λ��
    {//�������λ��
        for(int i=0;i<NumOfNbr;i++)
        {
            nbr.row=here.row+offset[i].row;
            nbr.col=here.col+offset[i].col;
            if(grid[nbr.row][nbr.col]==0)
            {
                grid[nbr.row][nbr.col]=grid[here.row][here.col]+1;
                if((nbr.row==finish.row)&&(nbr.col==finish.col))
                    break;//���
                Q.Add(nbr);
            }
        }
        if((nbr.row==finish.row)&&(nbr.col==finish.col))
            break;

        if(Q.IsEmpty())
            return false;
        Q.Delete(here);
    }
    while(true);
    //����·��
    PathLen=grid[finish.row][finish.col]-2;
    path=new Position[PathLen];
    //������finish
    here=finish;
    for(int j=PathLen-1;j>=0;j--)
    {
        path[j]=here;
        //Ѱ��ǰһ��λ��
        for(int i=0;i<NumOfNbr;i++)
        {
            nbr.row=here.row+offset[i].row;
            nbr.col=here.col+offset[i].col;
            if(grid[nbr.row][nbr.col]==j+2)
                break;
        }
        here=nbr;//�ƶ���ǰһ��λ��
    }
    return true;
}
void Q3()
{

    Position start,finish;
    cout<<"��������к��кţ��յ��к��к�"<<endl;
    cin>>start.row>>start.col>>finish.row>>finish.col;
    int PathLen;
    Position* path;
    if(FindPath(start,finish,PathLen,path))
    {
        cout<<"���·����"<<endl;
        for(int i=0;i<PathLen;i++)
            grid[path[i].row][path[i].col]=-1;
        grid[start.row][start.col]=-1;
        for(int i=1;i<=m1;i++)
        {
            for(int j=1;j<=m1;j++)
                if(grid[i][j]==-1)
                    cout<<'*'<<" ";
                else if(grid[i][j]>1)
                    cout<<0<<" ";
                else
                    cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"�޲���·��"<<endl;
    }
}
int main(){
Q3();
return 0;
}

