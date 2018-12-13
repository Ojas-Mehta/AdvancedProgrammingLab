//author:CS18M038
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define mx 100000
int test=0,oldtest1=0,oldtest2=0;
void sort_print(string arr[], int n, int size)
{   //This function sort the array of strings to arrange them lexicographic order
    sort (arr, arr + n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}
int partone(string arr[],int r, int b,int index){
    // r=number of red balls
    // b=number of blue balls
    static int i=0;  //static variable which maintains the represent the rows in array of strings. Indexes strings into the array.
    if(test!=oldtest1){ // reset the value of static variable for each testcase
        oldtest1=test;
        i=0;
    }
    if(r<=0 && b<=0){
       return i;//returns when both red balls and blue balls are exhausted.
    }
    else if(r>0 && b>0)
    {
         arr[i][index]='R';
         arr[i][index+1]='B';
         partone(arr,r-1, b-1,index+2);
            if(r<=b){
                
                 i++;
                 for(int ii=0; i>0 && ii<index;ii++){
                     arr[i][ii]=arr[i-1][ii];
                 }
                 arr[i][index]='B';
                    partone(arr,r, b-1,index+1);
                    
            }
            else{
                 for(int ii=0; i>0 && ii<index;ii++){
                 }
                 arr[i][index]='R';
                 arr[i][index+1]='B';
                partone(arr,r-1, b-1,index+2);
            }
    }
    else if(r>0){ //if only red balls are remaining
     
     arr[i][index]='R';
        partone(arr,r-1, b,index+1);
    }
    else{ //if only blue balls are remaining
     
     arr[i][index]='B';
        partone(arr,r, b-1,index+1);
    }
    return i;
}

int parttwo(string arr[],int r, int b,int index,int cnt){
    // r=number of red balls
    // b=number of blue balls
    static int i=0;  //static variable which maintains the represent the rows in array of strings. Indexes strings into the array.
    if(test!=oldtest2){
        oldtest2=test; // reset the value of static variable for each testcase
        i=0;
    }
    if(r<=0 && b<=0){
        return i;     //returns when both red balls and blue balls are exhausted.
    }
    else if(r>0 && b>0)
    {
        if(cnt>=2){
            arr[i][index]='B';
             parttwo(arr,r, b-1,index+1,0);    
        }
        else{
            int flag=-1;
            if(r<=2*(b)){
                 flag=0;
                 arr[i][index]='B';
                 parttwo(arr,r, b-1,index+1,0);
            }
            else{
                 flag=1;
                 arr[i][index]='R';
                 parttwo(arr,r-1, b,index+1,cnt+1);
            }
            if(flag==0){
                 i++;
                 for(int ii=0; i>0 && ii<index;ii++){
                        arr[i][ii]=arr[i-1][ii];
                 }
                 arr[i][index]='R';
                 parttwo(arr,r-1, b,index+1,cnt+1);  
                }
        }
        
    }
    else if(r>0){
        //if only red balls are remaining
        arr[i][index]='R';
        parttwo(arr,r-1, b,index+1,cnt+1);
    }
    else{
        //if only blue balls are remaining
        arr[i][index]='B'; 
        parttwo(arr,r, b-1,index+1,0);
    }
    return i;
}

int main() {
    int n,r,b;
    cin>>n;
    
    for(int i=0; i<n; i++){
        test=i+1;
        cin>>r>>b;
        int num_arrange=0;
        string arr[mx];
        for(int i=0; i<mx; i++){
            arr[i].resize(r+b);
        }
        if(r>b+1){  //if no arrangement is possible which follows the problem statement
            cout<<0<<'\n';
        }
        else{
            num_arrange=partone(arr,r,b,0)+1; //calls function partone for first part of the problem
            sort_print(arr,num_arrange,r+b);
            cout<<num_arrange<<'\n';
        }

        if(r>2*(b+1)){  //if no arrangement is possible which follows the problem statement
            cout<<0<<'\n';
        }
        else{
             num_arrange=parttwo(arr,r,b,0,0)+1; //calls function parttwo for second part of the problem
             sort_print(arr,num_arrange,r+b);
             cout<<num_arrange<<'\n';
        }
      
    }
    
    return 0;
}