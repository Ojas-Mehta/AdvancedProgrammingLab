/******************************************************************
Author:    Ojas Mehta (CS18M038)
Assignment: APL-Inlab4
Date: 22/08/18
*******************************************************************/
#include <iostream>
using namespace std;
int count_node=0;//node maintains the count of node in tree
const int size=100000;
int bin_tree[size]={},count_dig;
string bin_num;
void toBinary(int n){
    //converts decimal number to binary string
bin_num="";
    count_dig=0;
    while(n){
          bin_num[count_dig]=(n%2?'1':'0');
          count_dig++;
        n>>=1;
    }
    for(int i=0; i<count_dig/2;i++){
        char temp=bin_num[i];
        bin_num[i]=bin_num[count_dig-i-1];
        bin_num[count_dig-i-1]=temp;
        
    }
}
void insert_node(int n){
    //inserts node in the tree
    //node=1 means node is black colored, node=2 means it is white colored, node=0 means not in the tree at all
    toBinary(n);
    int current_node=0,left,right;
    if(bin_tree[current_node]!=1){
            bin_tree[current_node]=2;
        }
    for(int i=1; i<count_dig; i++){
        left=2*current_node+1;
        right=2*current_node+2;
            if(bin_num[i]=='0'){
                current_node=left;
            }
            else{
                current_node=right;
            }
        if(bin_tree[current_node]!=1){
            bin_tree[current_node]=2;
        }
    }
    if(bin_tree[current_node]!=1)
     count_node++;
    bin_tree[current_node]=1;
}
void delete_node(int n){
    if(count_node<=0){
       cout<<"String is not present\n";
    }
    else{
        toBinary(n);
        int current_node=0,left,right,parent_node;
        for(int i=1; i<count_dig; i++){
            left=2*current_node+1;
            right=2*current_node+2;
                if(bin_num[i]=='0'){
                    current_node=left;
                }
                else{
                    current_node=right;
                }
        }   
        if(bin_tree[current_node]==2){
                cout<<"Node is white\n";        
        }
        else if(bin_tree[current_node]==0){
                cout<<"String is not present\n";

        }
        else{   
            left=2*current_node+1;//represents left child of current node
            right=2*current_node+2;//represents right child of current node
            count_node--;
            if(bin_tree[left] ==1 || bin_tree[right]==1){
                //if node has some left or right child with black node, doesn't delete it
                bin_tree[current_node]=2;
            }
            else{
                //else delete the node and delete all its parents with white color.
                bin_tree[current_node]=0;
                parent_node=(current_node-1)/2;
                left=2*parent_node+1;
                right=2*parent_node+2;
                while(parent_node>=0 && bin_tree[left]==0 && bin_tree[right]==0 && bin_tree[parent_node]!=0){
                    bin_tree[parent_node]=0;
                    parent_node=(current_node-1)/2;
                    left=2*parent_node+1;
                    right=2*parent_node+2;
                }
            }

        }
    }
}
void print(int n){
    if(count_node<=0){
        cout<<"Empty Tree\n";
    }
    else{
        for(int i=0; i<n; i++){
            if(bin_tree[i]==1)cout<<i+1<<" ";
        }
         cout<<'\n';
    }       
}
int main() {
    int cond, temp;
    while(1){
        cin>>cond;       
        switch(cond){
            case 1:{
                cin>>temp;
                insert_node(temp);
                break;
            }
            case 2:{
                cin>>temp;
                delete_node(temp);
                break;
            }
            case 3:{
                print(size);
                break;
            }
            case 4:{ //returns from main function, when 4 is entered.
                return 0;
            }
        }
    }    
    return 0;
}

