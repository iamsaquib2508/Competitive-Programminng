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
        ll n, k, z, sum=0;
        ll a[100005], solo, vmax=0, vid;
        vector<ll> v; v.clear();
        ll i, temp;
        cin >> n >> k >> z;
        cin >> a[0];
        sum=a[0];
        ffr(i,1,n){
            cin >> a[i];
        }
        ffrr(zz,0,z){

        }
        cout << sum << endl;

    }
    cin >> tt;
}
