/*****************************
Author: Ojas Mehta (CS18M038)
Date: 01/09/2018
Assignment: Connecting the Points
********************************/
#include <iostream>
using namespace std;
int total=0;//it stores the final cost
typedef struct{
    //stores the left, right end points of the rope and its cost
  int l, r, c;  
}point;
point *st;
int sz,k,n, *link, *cost;
//sz=size of heap;
void pairheapify(int ind){
    //heapify min with pair and
    int left=2*ind+1, right=2*ind+2;
    int min=ind;
    if(left< sz && st[left].c<st[ind].c){
        min=left;
    }
    if(right< sz && st[min].c>st[right].c){
        min=right;
    }
    if(min<sz && min!=ind){
        point temp=st[min];
        st[min]=st[ind];
        st[ind]=temp;
        pairheapify(min);
    }
}
void paircreate(){
    //creates the min heap ordered according to the value of cost
    for(int i=sz/2-1; i>=0; i--)
        pairheapify(i);
}

int pairinsert(point ins){
    //insert pair into the heap
    sz++;
    int ind = sz-1;
    st[ind]=ins;
    int par=(ind-1)/2;
    while(par>=0){
        
        if(st[par].c<=st[ind].c){
          
            break;
        }
        else{
            point temp=st[ind];
            st[ind]=st[par];
            st[par]=temp;
            ind=par;
            par=(ind-1)/2;
        }
    }
    return 1;
}


point pairremove(){
    //deletes the rope from the min-heap
    point temp=st[0];
    st[0]=st[sz-1];
    sz--;
    pairheapify(0);
    return temp;
}

int optgreedy(){
    //This function performs the logic of the code using optimized greedy
    point cur;
    for(int i=0; i<k; ){
        cur=pairremove();

       if(cur.l>=0 && cur.r<n && link[cur.l]==0 && link[cur.r]==0){
                i++;
              total+=cur.c;
            link[cur.l]=(link[cur.r]=1);
          if(cur.l-1>=0 && cur.r+1<n ){
              //checks the l-1th and r+1th nodes whether that leads to optimal result
                    point ins;
                    ins.l=cur.l-1;
                    ins.r=cur.r+1;
                    ins.c=cost[cur.l-1]+cost[cur.r]-cur.c;
                    //inserts the newly created node into the heap
                    pairinsert(ins);
               
                }
            }        
         
    }
    return total;
}


int main() {
    
    cin>>n>>k;
    sz=n-1;
    st=new point[sz];
    link=new int[sz];
    cost=new int[sz];
    int l,r,c;
    for(int i=0; i<sz; i++){
       cin>>l>>r>>c;
        l--;r--;
       st[i].l=l;
       st[i].r=r;
       st[i].c=c;
       cost[i]=c;
    }
    //create the heap
    paircreate();
    //calls optgreedy method for finding optimal K ropes
    cout<<optgreedy();
    return 0;
}