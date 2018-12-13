/***************************
Author: Ojas Mehta (CS18M038)
*****************************/
#include <iostream>
using namespace std;

int main() {
    string s,t;
    cin>>s>>t;
    //kprev will represent imax
    //left and right represents limits to do binary search for "imax" i.e. kprev(here)
    //in worst case it will run till log(100) = 7 times.
    int n, m, k = 0, left = 1, right = 100, count=0, kprev = 0;
    n = s.length();
    m = t.length();
    while(left<=right){ /*BINARY SEARCH "imax" till left limit is less than right limit*/
        int i,j;
        count = 0; //will keep count of character matched between both the strings
        k = (left+right)/2;
        for(i=0, j=0; i<n; i++){
            if(s[i]==t[j]){
                count++;
            }
            if(count==k){
                count=0;//reset when k occurances of earlier character were found
                j++;//increase the pointer of string t to match the next character
            }
            if(j==m)break;//break when whole string "t" is matched.
         }    
         i<n? kprev = k,left = k+1:right = k-1;//check for higher value of k if current satisfy but keep its record in                                                  //kprev. 
    }
    cout<<kprev;//print the output
    return 0;
}
