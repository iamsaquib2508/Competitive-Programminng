#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n, p, rem, i=0;
        cin >> n;
        p=n/4;
        rem=n%4;
        string ans;
        if(rem==0){
            ans="";
            ffr(i,0,p){
                ans+='8';
            }
            ffr(i,i,n){
                ans+='9';
            }
        }
        else{
            ans="8";
            ffr(i,0,p){
                ans+='8';
            }
            ffr(i,i+1,n){
                ans+='9';
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
    }
    cin >> tt;
}
