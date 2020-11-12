#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mkm make_pair
#define MMAX 200005
#define bug() cout << "hello\n"

using namespace std;

ff(int id, int val){
    ret = 0;
    if(v.find(id)!=v.end()){
        //found //endpart
        ret -= a[id];
        if(val>a[id+1]) ret += val;
        else if(a[id-1]<val) ret += a[id+1];
    }
}

int main(){
    int tt=1;
    cin >> tt;
    while(tt--){
        int n, i, q;
        ll x, ans, prev;
        int a[300005];
        
        cin >> n >> q;
        a[0]=0;
        ffr(i,1,n){
            cin >> a[i];
        }
        cin >> a[n];
        
        ans=0;
        set<int> v;
        //v.pb(0);
        ffrr(i,1,n){
            if(a[i]>a[i-1]){
                //cout << ans << endl;
                ans-=a[i-1];
                ans+=a[i];
                
            }
            if(a[i]<a[i-1]){
                v.insert(i-1);
            }
        }
        if(v.empty()) v.insert(n);
        while(q--){
            cin >> l >> r;

        }
        
        for(int aa:v) cout << aa << ' '; cout << endl;
        cout << ans << endl;
    }
}
