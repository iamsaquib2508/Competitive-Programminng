#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n, i, cnt=0;
        cin >> n;
        string s, ans=""; cin >> s;
        ffr(i,0,n){
            if(s[i]=='1') break;
            ans+='0';
            cnt++;
        }
        ans+='0';
        for(i=s.size()-1;i>=0;i--){
            if(s[i]=='0') break;
            ans+='1';
            cnt++;
        }
        if(cnt==n) i=1;
        else i=0;
        ffr(i,i,ans.size()){
            cout << ans[i] ;
        }
        cout << endl;
    }
}
