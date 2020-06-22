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

int main()
{
    int tt; cin >> tt;
    while(tt--){
        int n, i, x, k1=0, k2=0, ans;
        cin >> n;
        ffr(i,0,n){
            cin >> x;
            if(x&1){
                if(i&1) continue;
                else k1++;
            }
            else{
                if(i&1) k2++;

            }
        }
        if(k1==k2) ans=k1;
        else ans=-1;
        cout << ans << endl;
    }
}
