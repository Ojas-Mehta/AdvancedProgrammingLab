/**********************************
Author: Ojas Mehta(CS18M038)
***************************************/
#include <iostream>
using namespace std;

int **dp, *wealth, wsum = 0, fper, n;
void printdpp(){/*prints the sequence in descending order*/
    int i=n-1, j=fper-1;
    for(; i>=1 && j>0; i--){
      if(dp[i][j]!=dp[i-1][j]){
          cout<<i<<" ";
          j = j - wealth[i];
      }
    }
    cout<<0;
}
void fillTable(){/*fills the dp table*/
    for(int i=wealth[0]; i<fper; i++){
        dp[0][i] = wealth[0];
    }
    for(int i = 1; i<n; i++){
        for(int j=1; j<fper; j++){ 
            if(j<dp[i-1][j-wealth[i]]+wealth[i])
       /*if the value after adding exceeds the column wealth then just copy from top*/
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = (dp[i-1][j]>dp[i-1][j-wealth[i]]+wealth[i])?dp[i-1][j]:dp[i-1][j-wealth[i]]+wealth[i];
        }
    }
}

int main() {
    cin>>n;
    wealth = new int[n];
    for(int i=0; i<n; i++){
        cin>>wealth[i];  
        wsum+=wealth[i];  //calculates total wealth 
    }    
    fper = 2*wsum/5 + 1;
    dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[fper]();
    }
    fillTable();//calls function to fill dp table in bottom up manner
    printdpp();
    return 0;
}
