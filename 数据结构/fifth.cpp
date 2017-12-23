#include <iostream>
using namespace std;
class Position
{
    friend bool FindPath(Position start,Position finish,int& PathLen,Position* &path);
    friend bool FindPath();
    friend void Q2();
    friend void Q3();
private:
    int row;
    int col;
};

template <class T>          //堆栈的定义
class Stack
{
public:
    Stack(int MaxStackSize=10);
    ~Stack(){delete []stack;}
    bool IsEmpty() const{return top==-1;}
    bool IsFull()const{return top==MaxTop;}
    T Top()const;
    Stack<T>& Add(const T& x);  //Push
    Stack<T>& Delete(T& x);  //Pop
private:
    int top;  //栈顶
    int MaxTop;//最大栈顶值
    T* stack;   //堆栈元素数组
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
Stack<T>&Stack<T>::Add(const T&x){
if(IsFull()){
 throw NoMem();
}
stack[++top]=x;
return *this;
}
template <class T>

Stack<T>&Stack<T>::Delete(T&x){
if (IsEmpty()){
 throw OutOfBounds();
}
x=stack[top--];
return *this;
}

template <class T>
Stack<T>::Stack(int MaxStackSize)
{
    MaxTop=MaxStackSize-1;
    top=-1;
    stack=new T[MaxStackSize];
}

// 迷宫老鼠方法
Stack<Position> *path;
int maze[10][10]=    //初始化
{

    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

//"1"
int m=8;
int n=8;
bool FindPath()
{

    path=new Stack<Position>(m*n-1);
    Position offset[4];
    offset[0].row=0;
    offset[0].col=1;  //右

    offset[1].row=1;   //下
    offset[1].col=0;

    offset[2].row=0;  //左
    offset[2].col=-1;

    offset[3].row=-1;  //上
    offset[3].col=0;

  //迷宫周围增加一层障碍物
    for(int i=0;i<=n+1;i++)
        maze[0][i]=maze[m+1][i]=1;
    for(int i=0;i<=m+1;i++)
        maze[i][0]=maze[i][n+1]=1;

    Position here;
    here.row=1;
    here.col=1;
    maze[1][1]=3;
    int option=0;
    int LastOption=3;

    while(here.row!=m||here.col!=n)
    {
        int r=0;
        int c=0;
        while(option<=LastOption)
        {
            r=here.row+offset[option].row;
            c=here.col+offset[option].col;
            if(maze[r][c]==0)
                break;
            option++;
        }//下一个选择
        if(option<=LastOption)//找到相邻位置了吗
        {
            path->Add(here);
            here.row=r;
            here.col=c;
            maze[r][c]=3;//防止返回入口
            option=0;
        }//没有可用位置，回溯
        else
        {
            if(path->IsEmpty())
                return false;
            Position next;
            path->Delete(next);
            if(here.row=next.row)
                option=2+next.col-here.col;
            else
                option=3+next.row-here.row;
            here=next;
        }
    }
    return true;//到达迷宫出口

}

void Q2()//成功返回true ,否则false
{
//
//    cout<<"输入一个12行10列的迷宫"<<endl;
//    for(int i=1;i<=m;i++)
//        for(int j=1;j<=n;j++)
//            cin>>maze[i][j];
    if(FindPath())
    {
        cout<<"路径是："<<endl;
        while(!path->IsEmpty())
        {
            Position next;
            path->Delete(next);
            maze[next.row][next.col]=2;
        }
        maze[m][n]=2;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
                if(maze[i][j]==2)
                    cout<<'*'<<" ";
                else if(maze[i][j]==3)
                    cout<<0<<" ";
                else
                    cout<<maze[i][j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"迷宫无通路"<<endl;
    }
}
int main()
{

 Q2();
 return 0;
}
