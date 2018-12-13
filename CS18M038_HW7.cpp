/****************************************************
Author: Ojas Mehta
Date: 15/09/18
Assignment: APL-7
*********************************************/
#include <iostream>
using namespace std;

int n,m,v1,v2,*visited, travcountt=0,*ans,anscnt=0, *dist,maximumDistance=-1;
struct node{
    int v;
    node* next;
}*head,*newnode,*traverse;

struct pairr{
    int cnt,vertex;
}*countt;

struct que{
  node tempnode;
    que* next;
}*front=NULL, *rear=NULL;

void addNode(int v1, int v2){
    //checking self loop
    if(v1==v2)return;
    
    newnode = new node;
    newnode->v = v2;
    newnode->next = NULL;
    
    traverse = head[v1].next;
    if(traverse == NULL){
        head[v1].next = newnode;
    }
    else{
        while(traverse->next!=NULL)traverse = traverse->next;
        traverse->next = newnode;
    }
    
    
}

void printgraph(){
    //to print the graph
    for(int i=0; i<n; i++){       
        if(head[i].next != NULL){
            cout<<"countt "<<head[i].v<<'\n';
            traverse = head[i].next;
            while(traverse!=NULL){
                cout<<traverse->v<<" ";
                traverse=traverse->next;
            }
            cout<<'\n';
        }
    }
}
void initGraph(){
    //initializes graph
    for(int i=0; i<n; i++){
        head[i].v = i;
        head[i].next = NULL;
        
    }
    for(int i=0; i<n; i++){
        countt[i].vertex = i;
        countt[i].cnt = 0;
    }
}
void sortcountt(){
    
    pairr temp;
    //sorting the vertex in decreasing order of number of vertices to which each can communicate
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if((countt[j].cnt<countt[j+1].cnt)){
                temp=countt[j+1];
                countt[j+1] = countt[j];
                countt[j] = temp;
            }
        }
    }
   
}
void depthFirstSearch(node* traverse){
    
    visited[traverse->v] = 1;
    if(traverse->next==NULL){
        return;
    }
    else{
        while(traverse!=NULL){
            
            traverse=traverse->next;
            
            if(traverse!=NULL && visited[traverse->v]==0){
                travcountt++;
                depthFirstSearch(&head[traverse->v]);    
            }
        }
    }
}
void resetvisit(){
    //clears visited array
    for(int i=0; i<n; i++)visited[i]=0;
}

void getcountt(){
    for(int i=0; i<n; i++){
        travcountt=0;
        resetvisit();
        if(head[i].next!=NULL)
            depthFirstSearch(&head[i]);
        countt[i].cnt = travcountt;
    }
}
void qpush_back(node tempnode){
    que* point = (que*)malloc(sizeof(que));
    point->tempnode = tempnode;
    point->next=NULL;
    if(rear==NULL){
        rear = point;
        front = rear;
    }
    else{
        rear->next = point;
        rear=point;
    }
}
node qpop_front(){
    node tempp;
    if(front!=NULL)
    tempp =  front->tempnode; 
    front = front->next;
    return tempp;
}
int qempty(){
    if(front==NULL)return 1;
    else return 0;
}
void findMinSet(){
    int currentVertex;
    
    for(int i=0; i<n; i++){
       
        currentVertex = countt[i].vertex;
        if(visited[currentVertex] == 0){
            ans[anscnt++]=currentVertex;
            visited[currentVertex] = 1;
            depthFirstSearch(&head[currentVertex]);
        }
    }
    int swaptemp;
    for(int i=0; i<anscnt-1; i++){
        for(int j=0; j<anscnt-1-i; j++){
            if(ans[j]>ans[j+1]){
                swaptemp = ans[j+1];
                ans[j+1] = ans[j];
                ans[j] = swaptemp;
                
            }
        }    
    }
    for(int i=0; i<anscnt; i++){
        cout<<ans[i]<<" ";
        
    }
    cout<<'\n';
}

void minhop(){
    node temp;
    
    resetvisit();
    int predecessor=0;
    for(int i=0; i<anscnt; i++){
        qpush_back(head[ans[i]]);
        dist[head[ans[i]].v]=predecessor+1;
    }
   
    while(!qempty()){
        temp = head[qpop_front().v];
       
        visited[temp.v]=1;
        
        
        if(temp.v<n)
        predecessor = dist[temp.v];
        while(temp.next!=NULL){
            if(visited[(temp.next)->v]==0){
              
                if(temp.v<n)
                dist[(temp.next)->v] = predecessor+1;
                qpush_back(*(temp.next));
            }
            temp = *(temp.next);
        }
    
    }
    for(int i=0; i<n; i++){
        if(maximumDistance<dist[i])maximumDistance = dist[i];
    }
    cout<<maximumDistance; //prints minimum number of hops
    
}

int main() {
    cin>>n>>m;
    head = new node[n];
    countt = new pairr[n];
    visited = new int[n]();
    ans = new int[n];
    dist = new int[n];
    for(int i=0; i<n;i++)dist[i]=-1;
    initGraph();
    for(int i=0; i<m; i++){
        cin>>v1>>v2;
        addNode(v1,v2);
    }
    
    getcountt();    //get number of nodes reachable from each node
    resetvisit();
    sortcountt();   //Sorts countt array in decreasing order
    resetvisit();
    findMinSet();   //find set with minimum nodes
    resetvisit();
    minhop();       //finds minimum hops for the set
    return 0;
}
