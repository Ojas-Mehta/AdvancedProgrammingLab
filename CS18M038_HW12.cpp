
#include <iostream>
using namespace std;
int count = 0;
int countsteps(int n){
	// it will return the lowest cost in which neighbourhood can be visited.
    if(n==1){
        count+=2;
        return 0;
    }
    if(n<=0){
        return 0;
    }
    if(n%2==0 && (n-n/2)>=2){
		count+=4; //increase cost by 4 when n is multiple of 2
		countsteps(n/2);//half the number of neighbourhood.
	}
    else {
		count+=2;
		countsteps(n-1);//decrease the neighbourhood by 1 otherwise
	}
    return 0;
}
int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        count=0;
        countsteps(n);
        cout<<count<<endl;
    }
    return 0;
}
