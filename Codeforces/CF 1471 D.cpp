#include <bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair
#define ll long long int
#define pb push_back
using namespace std;
    
vector<int> pm;
    
void go(){
    int num, div;
    pm.pb(2);
    for(num=3; num<999; num+=2){
        for(div=3; div<num; div+=2){
            if(num%div==0) break;
        }
        if(div==num) pm.pb(num);
    }
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int cc=1, tt;
    cin >> tt;
    go();
    while(tt--){
        int n, m, i, mx=0, x, q, ke, val, ans0, ans1, cur, j;
        ll qq;
        vector<ll> a;
        a.clear();
        cin >> n;
        ffr(i,0,n){
            cin >> x;
            a.pb(x);
        }
        sort(a.begin(),a.end());
        map<ll,ll> cnt;
        cnt.clear();
        ffr(i,0,n){
            for(int j: pm){
                cur = j*j;
                if (cur > a[i]){
                    break;
                }
                while (a[i]%cur == 0){
                    a[i]/=cur;
                }
                j++;
            }
            cnt[a[i]]++;
        }
        int even=0, odd=0, one=0;
        for(auto elem: cnt){
            ke = elem.first;
            val = elem.second;
            // cout << ke << ' ' << val << endl;
            if(ke==1){
                one=val;
            }
            else if(val%2==0){
                even+=val;
            }
            else{
                odd++;
            }
            if(val > mx){
                mx = val;
            }
        }
        // cout << one << ' ' << even << ' ' << odd << endl;
        if (one > mx) mx = one;
        ans0 = mx;
        ans1 = even+one;
        if (mx > ans1) ans1 = mx;
        cin >> q;
        ffrr(i,1,q){
            cin >> qq;
            if (qq==0) cout << ans0 << endl;
            else cout << ans1 << endl;
        }
    }
}