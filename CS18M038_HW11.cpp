/**********************************
Author: Ojas Mehta (CS18M038)
**************************************/
#include <iostream> 
using namespace std;

int start = -1;
string txt;//stores s
int init, n, m;


inline int strmatch(string pat) { 
    int i = init, j = 0, index_txt = -1, 
    index_pat = -1; 
    int ans = -1;
   
    while (i<n && j<m) { 
    
        if (txt[i] == pat[j]) { //if character are matched
            if(j==0)start = i;
            ans = i;
            i++; 
            j++; 
            
        } 
  
        else if (j < m && pat[j] == '?') { //for wildcard char ? because it can be matched to any length of substring
            if(i==init)ans = i;
            index_txt = i; 
            index_pat = j; 
            j++;
           
        } 
        
        else if (index_pat != -1) { //when ? is replaced by a substring move forward
            j = index_pat + 1; 
            i = index_txt + 1; 
            index_txt++; 
            
        } 
        
        else { 
            if(j==0){
               i++; 
            }
            else
            return -1; //when strings dont match
        } 
    } 
  
    
    if (j < m && pat[j] == '?') { 
        j++; //increment j till end of pattern
    } 
  
    
    if (j == m) { 
        return ans+1; //if patter is matched return the desired index
    } 
  
    return -1; 
} 
  

int main() 
{ 
   
   int pl,sl,t;
   cin>>t;
   ios_base::sync_with_stdio(false); /*to disable the synchronization between c and c++ output streams which is useless                                        in this case*/
    
    while(t--){//runs for each test case
        string patt;//stores s1
        cin>>patt>>txt;

        n = txt.length();
        int tlength = patt.length();
        m=0;
        char cr[tlength] = {};
        for(int z=0;  z<tlength;){
            
            if(patt[z]=='?'){
                while(patt[z]=='?')z++;
                cr[m++]='?';
            }
            else{
                cr[m++]=patt[z++];
            }
        }
      string pat(cr);
        for(int i=0;i<n; i++){
            init = i;
            int ch = strmatch(pat);//calls the function to match the strings
            cout<<ch<<" ";
            if(ch==-1){
                i++;
                while(i<n){
                    cout<<-1<<" "; //prints -1 after first string is not matched because subsequent too wont match.
                    i++;
                }
                
            }
            if(start!=-1){//if first letter of s and s1 dont  match
                for(;i<start; i++){
                    cout<<ch<<" ";
                }
                start  = -1;
            }
            
        }
        cout<<'\n';
    } 
    return 0; 
} 