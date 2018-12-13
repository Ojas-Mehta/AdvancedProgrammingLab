/*********************
Author: Ojas Mehta
Date: 8/09/2018
***************************/
#include <iostream>
using namespace std;
#define lim 6000
int t,n,m,dx,dy;
short city[lim][lim], visited[lim][lim]={};
typedef struct{
    short x,y,dist=0,mode;
} node;
int rear, front;
node st[lim][lim];
node *q;//
void qpush_back(node n){
    //pushes node into queue
    q[++rear]=n;
}
node qpop_front(){
    //pops node from the queue
    return q[++front];
}

int solve(){
    int x,y; 
    if(city[0][0]==0 || city[dx][dy]==0){
        //returns -1 if source or destination is black
        return -1;
    }
    st[0][0].mode=2;
    qpush_back(st[0][0]);
    visited[0][0]=1;
    
    int dist=0, mode=city[0][0]==2?3:2;
    node cur;
    while(front<rear){
        cur=qpop_front();
        x=cur.x;
        y=cur.y;
        dist=cur.dist;
        mode=cur.mode;
        if((x==dx && y==dy)){
            return cur.dist;
        }
        else {
           
            if(city[x][y]==2){//if encouters grey node
                    mode=5-mode;
            }
            if(mode==3){//if driving
                if(x+3<n && city[x+1][y]!=0 && city[x+2][y]!=0 && city[x+3][y]!=0 && visited[x+3][y]<=1 && (visited[x+3][y]!=1 || st[x+3][y].mode!=mode)){
                    st[x+3][y].mode=mode;
                    st[x+3][y].dist=dist+1;
                    visited[x+3][y]++;
                    qpush_back(st[x+3][y]);
            }
                
                
            if(y+3<m && city[x][y+1]!=0 && city[x][y+2]!=0 && city[x][y+3]!=0 && visited[x][y+3]<=1 && (visited[x][y+3]!=1 || st[x][y+3].mode!=mode)){
                st[x][y+3].mode=mode;
                st[x][y+3].dist=dist+1;
                visited[x][y+3]++;
                qpush_back(st[x][y+3]);
            }
            if(x-3>=0 && city[x-1][y]!=0 && city[x-2][y]!=0 && city[x-3][y]!=0 && visited[x-3][y]<=1 && (visited[x-3][y]!=1 || st[x-3][y].mode!=mode)){
                st[x-3][y].mode=mode;
                st[x-3][y].dist=dist+1;
                visited[x-3][y]++;
                qpush_back(st[x-3][y]);
            }
            if(y-3>=0 && city[x][y-1]!=0 && city[x][y-2]!=0 && city[x][y-3]!=0 && visited[x][y-3]<=1 && (visited[x][y-3]!=1 || st[x][y-3].mode!=mode)){
                    st[x][y-3].mode=mode;
                    st[x][y-3].dist=dist+1;
                    visited[x][y-3]++;
                    qpush_back(st[x][y-3]);
            }
               
            }
            else{
               
                if(x+2<n && city[x+1][y]!=0 && city[x+2][y]!=0 &&visited[x+2][y]<=1 && (visited[x+2][y]!=1 || st[x+2][y].mode!=mode ))                    
                {st[x+2][y].mode=mode;
                 st[x+2][y].dist=dist+1;
                 visited[x+2][y]++;
                qpush_back(st[x+2][y]);
                }
                
                if(y+2<m && city[x][y+1]!=0 && city[x][y+2]!=0 &&visited[x][y+2]<=1 && (visited[x][y+2]!=1 || st[x][y+2].mode!=mode ))                       
                {st[x][y+2].mode=mode;
                 st[x][y+2].dist=dist+1;
                 visited[x][y+2]++;
                 qpush_back(st[x][y+2]);
                 
                }
                if(x-2>=0 && city[x-1][y]!=0 && city[x-2][y]!=0&&visited[x-2][y]<=1 && (visited[x-2][y]!=1 || st[x-2][y].mode!=mode ))                       
                {st[x-2][y].mode=mode;
                 st[x-2][y].dist=dist+1;
                 visited[x-2][y]++;
                qpush_back(st[x-2][y]);
                }
                 
                if(y-2>=0 &&city[x][y-1]!=0 && city[x][y-2]!=0 &&visited[x][y-2]<=1 && (visited[x][y-2]!=1 || st[x][y-2].mode!=mode ))                       
                { 
                    st[x][y-2].mode=mode;
                    st[x][y-2].dist=dist+1;
                    visited[x][y-2]++;
                    qpush_back(st[x][y-2]);
                }

            }
        }
    }
    return -1;
}

int main() {
    cin>>t;
    while(t--){
        cin>>n>>m;
        rear=0,front=0;
        q=new node[2000000];//creates new queue for ever iteration
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>city[i][j];
                st[i][j].x=i;
                st[i][j].y=j;
                st[i][j].mode=0;
                st[i][j].dist=0;
                visited[i][j]=0;
            }   
        }
        cin>>dx>>dy;
        cout<<solve()<<"\n";
        delete q;
    }
    return 0;
}
