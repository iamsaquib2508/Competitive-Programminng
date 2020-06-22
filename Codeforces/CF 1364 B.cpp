#include <bits/stdc++.h>
#define ll int64_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int maxx(int a, int b){
    if(a>b) return a; return b;
}

int minn(int a, int b){
    if(a<b) return a; return b;
}

int main()
{
    int tt; cin >> tt;
    while(tt--){
        int n, i, a[100005];
        bool inc;
        vector<int> ans; ans.clear();
        cin >> n;
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        ans.pb(a[0]);
        inc=0;
        if(a[1]>a[0]) inc=1;

        ffr(i,1,n){
            if(inc){
                if(a[i]>a[i-1]){
                    //agao
                }
                else{
                    ans.pb(a[i-1]);
                    inc=0;
                }
            }
            else{
                if(a[i]<a[i-1]){
                    //agao
                }
                else{
                    ans.pb(a[i-1]);
                    inc=1;
                }
            }
        }
        ans.pb(a[n-1]);
        cout << ans.size() << endl;
        for(int aa:ans) cout << aa << ' '; cout << endl;
    }
}
