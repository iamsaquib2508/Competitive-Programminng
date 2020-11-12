#include <bits/stdc++.h>
#define ull uint64_t
#define uint uint32_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair

using namespace std;

int main(){
    int tt=1;
    cin >> tt;
    while (tt--) {
        int r, g, b, w, cnt=0, cnt0=0;
        cin >> r >> g >> b >> w;
        string ans, yes="Yes\n", no="No\n";
        if(r%2==1) cnt++;
        if(g%2==1) cnt++;
        if(b%2==1) cnt++;
        if(r==0) cnt0++;
        if(g==0) cnt0++;
        if(b==0) cnt0++;
        if(w%2==0)
        {
            if(cnt==3) ans=yes;
            else if(cnt==2) {
                ans=no;
            }
            else if(cnt==1) ans=yes;
            else if(cnt==0) ans=yes;
        }
        else{
            if(cnt==3) ans=yes;
            else if(cnt==2) {
                if(cnt0==0) ans=yes;
                else ans=no;
            }
            else if(cnt==1) ans=no;
            else ans=yes;
        }
        cout << ans;

    }
    cin >> tt;
}
