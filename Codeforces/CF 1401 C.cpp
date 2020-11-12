#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mkm make_pair
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main(){
    int tt;
    cin >> tt;
    int n;
    while(cin >> n){
        int i, a[100005], mn=1000000009, id;
        vector<int> v; v.clear();
        ffr(i,0,n){
            cin >> a[i];
            mn=minn(mn,a[i]);
        }
        ffr(i,0,n){
            if(a[i]%mn==0){
                v.pb(a[i]);
            }
        }
        sort(v.begin(),v.end());
        id=0;
        ffr(i,0,n){
            if(a[i]%mn==0){
                a[i]=v[id++];
            }
        }
        ffr(i,1,n){
            if(a[i]<a[i-1]) break;
        }
        if(i==n) cout << "YES\n";
        else cout << "NO\n";
    }
}
