/**********************************************************************
Filename: CS18M038_JumpingKangaroo1.CPP
Assignment:jumping-kangaroo
Author: Ojas Mehta (CS18M038)
Date: 05/08/2018
Description: Recursive program to calculate number of ways in which monkey can reach to the top
************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
long long jump(int n){
    //this function returns the total possible combinations of jumps monkey can make
    if(n<0)return 0;  //zero because monkey makes higher jump resulting in lowervalue
    if(n==0)return 1; //when monkey exactly reaches the top, returns 1 because its correct jump
    return jump(n-1)+jump(n-2)+jump(n-3);//three calls because monkey can jump only in 3 ways
}

int main(){
    int n;
    cin>>n;
     cout<<jump(n);//call with n steps that monkey has to climb as parameter
    return 0;
}
