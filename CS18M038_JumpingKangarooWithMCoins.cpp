/**********************************************************************
Filename: CS18M038_JumpingKangarooWithMCoins.CPP
Assignment:Jumping Kangaroo with M Coins
Author: Ojas Mehta (CS18M038)
Date: 05/08/2018
Description: iterative program to calculate number of ways in which monkey can reach to the top using exactly M coins
************************************************************************/
#include <iostream>
using namespace std;
int main() {
    int test,n,m;
    cin>>test;              //test variable used for number of test cases
    while(test--){          //decrement test everytime and terminates when test==0
        cin>>n>>m;
        if(n==m){
            cout<<1<<'\n';
            continue;
        }
        else if(n<m){
            cout<<0<<'\n';
            continue;
        }
        long long arr[n+1]={0,1,1,1},temp1=1,temp2=1,temp3=1,temp;  // initializes arr with values {0,1,1,1,0,.....}
        for(int j=2;j<=m;j++){                                      //j implies number of coins used hence goes till 'm'
            if(j==3){
               temp1=0;
               temp2=1;
               temp3=2;
            }
            else if(j==4){
               temp1=0;
               temp2=0;
               temp3=1;
            }
            else if(j>4){
               temp1=(temp2=(temp3=0));
            }
            arr[1]=temp1;
            arr[2]=temp2;
            arr[3]=temp3;
            for(int k=4; k<=n; k++){
                temp=arr[k];
                arr[k]=temp1+temp2+temp3;     //logic: number of combinations at n,m is 
                temp1=temp2;                  //   sum of no. of combinations at(n-1,m-1), (n-2,m-1), (n-3,m-1)
                temp2=temp3;                  // where n is total number of stairs while m is number of coins.
                temp3=temp;
            }
        }
        cout<<arr[n]<<'\n';      //prints for n which it gets after spending exactly m coins(implied by m iterations)
    }
    
    return 0;
}
