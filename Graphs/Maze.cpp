/* Shortest path in a Binary Maze */

#include<cstdio>
#include<cstdlib>
#include<queue>
#include<vector>
#define ROW 9
#define COL 10

using namespace std;

struct Point
{
    int x;
    int y;
};

struct node {
    Point P;
    int distance;
};

int BFS(int A[][COL], bool visit[][COL],Point src,Point dest){
    
    queue<node> Q;
    
    if(A[src.x][src.y] == 0 ||  A[dest.x][dest.y] == 0) {
        return -1;
    }
    

    visit[src.x][src.y] = true;
    
    struct node N= {src,0};
    Q.push(N);
    
    while(!Q.empty()) {
        struct node temp = Q.front();
        struct Point pt = temp.P;
        
        printf("%d %d \n",pt.x,pt.y);
        
        if(pt.x == dest.x && pt.y == dest.y)
            return temp.distance;
        
        Q.pop();
        
        if((pt.x >= 0 && pt.y-1 >= 0 && pt.x < ROW && pt.y-1  < COL ) &&  A[pt.x][pt.y-1] == 1 && visit[pt.x][pt.y-1] == false ) {
            visit[pt.x][pt.y-1]  = true;
            struct node temp1 =  { {pt.x,pt.y-1},temp.distance+1};
            Q.push(temp1);
        }
        
        if((pt.x >= 0 && pt.y+1  >= 0 && pt.x < ROW && pt.y+1 < COL ) &&   A[pt.x][pt.y+1] == 1 && visit[pt.x][pt.y+1] == false ) {
            visit[pt.x][pt.y+1]  = true;
            struct node temp1 =  { {pt.x,pt.y+1},temp.distance+1};
            Q.push(temp1);
        }
        
        if((pt.x - 1 >= 0 && pt.y  >= 0 && pt.x - 1 < ROW && pt.y < COL ) &&   A[pt.x -1][pt.y] == 1 && visit[pt.x - 1][pt.y] == false ) {
            visit[pt.x - 1][pt.y]  = true;
            struct node temp1 =  { {pt.x - 1,pt.y},temp.distance+1};
            Q.push(temp1);
        }
        
        if((pt.x+1 >= 0 && pt.y  >= 0 && pt.x+1 < ROW && pt.y < COL ) &&   A[pt.x+1][pt.y] == 1 && visit[pt.x+1][pt.y] == false ) {
            visit[pt.x+1][pt.y]  = true;
            struct node temp1 =  { {pt.x+1,pt.y},temp.distance+1};
            Q.push(temp1);
        }
        
    }
    return -1;
}
int main()
{
    int A[ROW][COL]  = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    
    Point src = {0,0};
    Point dest = {3,4};
    
    bool visit[ROW][COL];
    memset(visit,false,sizeof(visit));
    printf("%d ", BFS(A,visit,src,dest));
}
