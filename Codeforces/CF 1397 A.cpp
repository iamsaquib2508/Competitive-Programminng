#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define sf scanf
    
using namespace std;
    
int minn(int a, int b){
    if(a<b) return a; return b;
}
    
int main(){
    int tt=1; 
    cin >> tt;
    while(tt--){
        int n, i, cnt[26]={};
        string s;
        cin >> n;
        ffr(i,0,n){
            cin >> s;
            for(char aa:s){
                cnt[aa-'a']++;
            }
        }
        ffr(i,0,26){
            if((cnt[i]%n)>0) break;
        }
        if(i==26) cout << "YES\n";
        else cout << "NO\n";
    }
}