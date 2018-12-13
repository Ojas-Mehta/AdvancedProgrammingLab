/**********************************************************************
Filename: CS18M038_l3.cpp
Assignment: Karatsuba Polynomial Multiplication
Author: Ojas Mehta (CS18M038)
Date: 18/08/2018
************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;
void k_suba(int a[],int b[], int ans[],int l, int r){
    int deg=r-l,times=(deg)/2,sumsize=2*ceil((deg+1)*1.0/2)-1, mid=(l+r)/2,ad0[sumsize]={},ad1[sumsize]={},ad01[sumsize]={};
    if(deg<=0){//when degree becomes zero, then simply multiply the coefficients of the polynomial
        ans[0]=a[l]*b[r];
        return;
    }
    k_suba(a, b,ad0, l, mid);
    k_suba(a, b, ad1,  mid+1, r);
    int change=((deg+1)/2);
    int asum_arr[change]={}, bsum_arr[change]={};
    for(int i=0; i<change; i++){
        asum_arr[i]=a[i+l]+a[i+mid+1];
        bsum_arr[i]=b[i+l]+b[i+mid+1];
    }
    if(deg%2==0){//if degree of the polynomial is even
        asum_arr[change]=a[l+change];
        bsum_arr[change]=b[l+change];
        k_suba(asum_arr, bsum_arr, ad01, 0, change);
    }
    else{//if degree of the polynomial is odd
        k_suba(asum_arr, bsum_arr, ad01, 0, change-1);
    } 
    for(int i=0; i<sumsize; i++){
        ad01[i]=ad01[i]-ad1[i]-ad0[i];
    }
    //finally combining ad0, ad01 and ad1 to get final expression for the polynomial passed as arg in that fn call
    for(int i=0; i<sumsize; i++){
        ans[i]=ad0[i];
    }    
    for(int i=0; i<sumsize; i++){      
        ans[i+sumsize-times]+=ad01[i];       
    }
    for(int i=0; i<sumsize; i++){
        ans[i+2*(sumsize-times)]+=ad1[i];
    }
}
int main() {
    int m,n,mxd;
    cin>>m>>n;
    mxd=max(m,n);
    int a[mxd]={},b[mxd]={}, ans[m+n]={};
    for(int i=0; i<m; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    //first call to k_suba function with coeffiecient of polynomials in array a and b whose addresses are passed.
    k_suba(a,b,ans, 0, mxd-1);
    //array ans contains the resultant coefficients of polynomial multiplications
    for(int i=0; i<m+n-1; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
