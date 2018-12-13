#include <iostream>
using namespace std;
typedef struct{
    //stores the indexes of both min heap
  int x,y;  
}pairr;
pairr *printt;
int printtcnt=0,m,n;

int check(int a,int b, int A[], int B[]){
    for(int i=0; i<printtcnt; i++){
        if(printt[i].x==a && printt[i].y==b)return 1;
    }
   return 0;
}
void heapify(int pq[], int ind, int sz){
    //heapify the array
    int left=2*ind+1, right=2*ind+2;
    int min=ind;
    if(left<sz && pq[left]<pq[min]){
        min=left;
    }
    if(left<sz && pq[right]<pq[min]){
        min=right;
    }
    if(min<sz && min!=ind){
        int temp=pq[min];
        pq[min]=pq[ind];
        pq[ind]=temp;
        heapify(pq, min, sz);
    }
}

void create(int pq[], int sz){
    for(int i=sz/2-1; i>=0; i--)
        heapify(pq, i, sz);
}

int remove(int pq[], int last){
    //last is size and not index
   int temp=pq[0];
    pq[0]=pq[last-1];
    heapify(pq, 0, last);
    return temp;
}



void pairheapify(pairr pq[], int sz, int ind, int A[], int B[]){
    //heapify priority queue with pair
    int left=2*ind+1, right=2*ind+2;
    int min=ind;
    if(left< sz && (A[pq[left].x]+B[pq[left].y])<(A[pq[min].x]+B[pq[min].y])){
        min=left;
    }
    if(right< sz && (A[pq[right].x]+B[pq[right].y])<(A[pq[min].x]+B[pq[min].y])){
        min=right;
    }
    if(min<sz && min!=ind){
        pairr temp=pq[min];
        pq[min]=pq[ind];
        pq[ind]=temp;
        pairheapify(pq, sz, min, A, B);
    }
}

int pairinsert(pairr pq[], int sz, int Aind, int Bind, int A[], int B[]){
    //insert pair
    pairr cur;
    cur.x=Aind;
    cur.y=Bind;
    int ind=sz;
    if(Aind>=m || Bind>=n) return 0;
    if(check((Aind-1)/2, Bind, A, B) || check(Aind, (Bind-1)/2, A, B)){
       // dbg2(Aind, Bind);
        return 0;
    }
    
    pq[ind]=cur;
    int par=(ind-1)/2;
    while(par>=0){
      
        if((A[pq[par].x]+B[pq[par].y])<=(A[pq[ind].x]+B[pq[ind].y])){
          
            break;
        }
        else{
            pairr temp=pq[ind];
            pq[ind]=pq[par];
            pq[par]=temp;
            ind=par;
            par=(ind-1)/2;
        }
    }
    return 1;
}


pairr pairremove(pairr pq[], int last, int A[], int B[]){
    //delete pair
    pairr temp=pq[0];
    pq[0]=pq[last-1];
    pairheapify(pq, last-1, 0, A, B);
    return temp;
}


int main() {
    int k;
    cin>>m>>n>>k;
    int A[m], B[n];
    //int pq[sz];
    for(int i=0;i<m; i++){
        cin>>A[i];
    }
    for(int i=0;i<n; i++){
        cin>>B[i];
    }
    create(A,m);
    create(B,n);
    printt= new pairr[k];
    int fsz=8*k, fcnt=0;
    //fin is the final heap that stores the K minimum sum and has O(k) space complexity
    pairr fin[fsz], pass;
    pairinsert(fin,  fcnt, 0, 0,A, B);
    fcnt++;
    for(int i=0; i<k; i++){
        pass=fin[0];
    // checks for four combinations and insert each into min heap fin
        int Acur=pass.x, Bcur=pass.y, Aleft=2*pass.x+1, Bleft=2*pass.y+1, Aright=2*pass.x+2, Bright=2*pass.y+2;
       
        if(Acur<m && Bleft<n){
        if(pairinsert(fin,  fcnt, Acur,Bleft, A, B))fcnt++;
           
        }
        if(Acur<m && Bright<n){
        if(pairinsert(fin,  fcnt, Acur, Bright, A, B))
        fcnt++;
        }
        if(Aleft<m && Bcur<n){
        if(pairinsert(fin,  fcnt, Aleft, Bcur, A, B))
           
        fcnt++;
        }
        if(Aright<m && Bcur<n){
        if(pairinsert(fin,  fcnt, Aright, Bcur, A, B))
         fcnt++;
        }        
        printt[printtcnt++]=pairremove(fin, fcnt--, A, B);
        
        cout<<A[pass.x]+B[pass.y]<<" ";
    }
    
    return 0;
}
