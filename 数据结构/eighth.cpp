#ifndef GRAPH_H
#define GRAPH_H
#include<queue>
#include <iostream>
using namespace std;
template <class T>
class edge
{
    public:
        edge(int i,int j,int w){
            vertex1=i; vertex2=j;weight=w;
        }
        edge(int i,int j){
            vertex1=i; vertex2=j;weight=1;
        }
        T vertex1;
        T vertex2;
        T weight;
};
template <class T>
class graph
{
    public:
        graph() {}
        ~graph() {}
        virtual int numberOfVertices()=0;     //返回图顶点数
        virtual int numberOfEdges()=0;        //返回图边数
        virtual bool existsEdge(int,int)=0;   //如果边（i,j）存在，返回true,否则返回false
        virtual void insertEdge(edge<T> theEdge)=0;   //插入边
        virtual void eraseEdge(int,int)=0;    //删除边
        virtual int degree(int)=0;            //返回顶点i的度，只用于无向图
        virtual int inDegree(int)=0;          //返回顶点i的入度
        virtual int outDegree(int)=0;         //返回顶点i的出度
        virtual bool directed()=0;            //若为有向图返回true
        virtual bool weighted()=0;            //若为加权图返回true
    protected:
    private:
};
template <class T>
class adjacencyWgraph : public graph<T> //加权图的邻接矩阵结构
{
    protected:
        int n;      //顶点个数
        int e;      //边的个数
        T **a;      //邻接数组
        T noEdge;   //表示不存的边
        T maxWeight;//最大权
    public:
        adjacencyWgraph(int numberOfVertices =0 , T theNoEdge=0 )
        {
            if(numberOfVertices <0 ){
                throw "number of vertices must be >=0";
                return; }
            n = numberOfVertices;
            e = 0;
            noEdge = theNoEdge;
            maxWeight=0;
            make2dArry(a,n+1,n+1);
        }
        ~adjacencyWgraph()
        {
            for(int i=0;i<=n;i++)
                delete [] a[i];
            delete [] a;
            a =NULL;
        }
        int numberOfVertices() {return n;}
        int numberOfEdges() {return e;}
        bool weighted() {return true;}
        bool directed() {return false;}
        bool existsEdge(int i,int j)
        {//返回值为真当且仅当（i,j）是图的一条边
            if (i<1 || j<1 || i>n || j>n || a[i][j]==noEdge)
                return false;
            else
                return true;
        }
        void insEdge(int i,int j,int w)
        {//插入边
            if(w>maxWeight) maxWeight=w;
            edge<int> ed(i,j,w);
            insertEdge(ed);
        }
        void eraseEdge(int i,int j)
        {//删除边（i,j）
            if(i>=1 && j>=1 && i<=n && j<=n && a[i][j]!=noEdge){
                a[i][j] = noEdge;
                a[j][i] = noEdge;
                e--;
            }
        }
        bool checkVertex(int theVertex)
        {//确定为有效顶点
            if(theVertex<1 || theVertex>n)  return false;
            else return true;
        }
        int degree(int theVertex){//返回顶点theVertex的度
            if(!checkVertex(theVertex)){
                cout<<"no vertex"<<theVertex<<endl;
                return -1;
            }
            int sum=0;
            for(int i=1;i<=n;i++)
                if(a[theVertex][i]!=noEdge)
                    sum++;
            return sum;
        }
        int inDegree(int theVertex)
        {
            cout<<"inDegree() undefined";
            return 0;
        }
        int outDegree(int theVertex)
        {
            cout<<"outDegree() undefined";
            return 0;
        }
        void output()
        {//输出邻接矩阵
            for(int i =1;i<=n;i++){
                for(int j =1;j<=n;j++)
                    cout<<a[i][j]<<" ";
                cout<<endl;
            }
        }
        void bfs(int v)
        {
            int reach[n+1];
            for(int i=1;i<=n;i++){reach[i]=0;}
            bfs1(v,reach,-1);
        }
        void dfs(int v)
        {
            int reach[n+1];
            for(int i=1;i<=n;i++){reach[i]=0;}
            dfs1(v,reach,-1);
        }
        void makeTree(int v)
        {//输出生成树
            adjacencyWgraph<int> awg0(n,noEdge);
            int reach[n+1];
            for(int i=1;i<=n;i++){reach[i]=0;}
            queue<int> *q=new queue<int>();
            reach[v] =-1;
            q->push(v);
            while(!q->empty()){
                int w =q->front();
                q->pop();
                for(int u=1;u<=n;u++)
                    if(a[w][u] !=noEdge && reach[u]==0){
                        awg0.insEdge(w,u,a[w][u]);
                        q->push(u);
                        reach[u]=-1;
                    }
            }
            cout<<"生成树邻接矩阵："<<endl;
            awg0.output();
            cout<<"生成树bfs："<<endl;
            awg0.bfs(v);cout<<endl;
        }
        void makeMinTree(int theVertex)
        {//输出最小生成
            adjacencyWgraph<int> awg1(n,noEdge);
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    awg1.a[i][j]=a[i][j];
            int **reach;
            make2dArry(reach,n+1,n+1);
            for(int k=1;k<=(e-n+1);k++){//删除多余的边
                awg1.findMaxWeight(maxWeight,reach,-1);}
            for(int h=0;h<=n;h++)
                delete [] reach[h];
            delete [] reach;
            reach =NULL;
            cout<<"最小生成树邻接矩阵："<<endl;
            awg1.output();
            cout<<"最小生成树bfs："<<endl;
            awg1.bfs(theVertex);
        }
        void findMaxWeight(int w,int **&reach,int lable)
        {//找到“最大权”，删除边
            int num=noEdge,row,col;
            for(int i=1;i<=n;i++) //找到“最大权”边
                for(int j=1;j<=n;j++){
                    if(a[i][j]>=num && reach[i][j]!=lable && a[i][j]<=w){
                        num=a[i][j];
                        row=i;col=j;
                    }
                }
            reach[row][col]=lable;
            reach[col][row]=lable;
            if(degree(row)<=1 || degree(col)<=1)//边不能删
                findMaxWeight(num,reach,lable);
            else    //删除边
                eraseEdge(row,col);
        }
    private:
        void make2dArry(T ** &x,int rows,int clos)
        {//创建二维数组
            x = new T *[rows];   //创建行指针
            for(int i=0;i<rows ;i++)  //为每一行分配空间
                x[i]=new T [clos];
            for(int j=0; j<rows;j++)  //初始化邻接矩阵
                for(int k=1;k<=clos;k++)
                    x[j][k] = noEdge;
        }
        void insertEdge(edge<T> theEdge)
        {//插入边，如果该边已存在，则修改权值
            int v1=theEdge.vertex1;
            int v2=theEdge.vertex2;
            if(v1<1 || v2<1 || v1>n || v2>n || v1==v2){
                cout <<"("<<v1<<","<<v2<<") is not a permissible edge";
                return;
            }
            if(a[v1][v2] == noEdge)//新的边
                e++;
            a[v1][v2] = theEdge.weight;
            a[v2][v1] = theEdge.weight;
        }
        void bfs1(int v,int reach[],int lable)
        {//广度先搜索，reach[i]用来标记所有邻接顶点v的可达到顶点
            queue<int> *q=new queue<int>();
            reach[v] =lable;
            q->push(v);
            while(!q->empty()){
                int w =q->front();
                q->pop();
                cout<<w<<" ";
                for(int u=1;u<=n;u++)
                    if(a[w][u] !=noEdge && reach[u]==0){
                        q->push(u);
                        reach[u]=lable;
                    }
            }
        }
        void dfs1(int v,int reach[],int lable)
        {
            reach[v]=lable;cout<<v<<" ";
            int i=1;
            while(a[v][i]==noEdge || reach[i]==lable) i++;
            if(i<n+1){
                v=i;
                dfs1(v,reach,lable);
            }
        }
};
#endif // GRAPH_H
int main()
{
    adjacencyWgraph<int> awg(8,0);
    awg.insEdge(1,2,5);
    awg.insEdge(1,3,4);
    awg.insEdge(1,4,10);
    awg.insEdge(2,5,30);
    awg.insEdge(3,5,25);
    awg.insEdge(4,6,2);
    awg.insEdge(4,7,60);
    awg.insEdge(5,8,13);
    awg.insEdge(6,8,14);
    awg.insEdge(7,8,17);
    cout<<"邻接矩阵："<<endl;
    awg.output();
    cout<<"bfs："<<endl;
    awg.bfs(2);cout<<endl;
    cout<<"dfs："<<endl;
    awg.dfs(3);cout<<endl;
    cout<<"生成树："<<endl;
    awg.makeTree(5);
    cout<<"最小生成树："<<endl;
    awg.makeMinTree(5);
    return 0;
}
