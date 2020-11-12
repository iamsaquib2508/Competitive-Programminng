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

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main(){
    int tt=1;
    cin >> tt;
    ll n, k;
    while(cin >> n >> k){
        ll a[200005], i, mx=-1000000009, mx2;

        ffr(i,0,n){
            cin >> a[i];
            mx=maxx(mx,a[i]);
        }
        int times=0;
        while(times<k){
            if(times>4 && ((times&1) == (k&1))) break;
            mx2=-1000000009;
            ffr(i,0,n){
                a[i] = mx-a[i];
                mx2=maxx(mx2,a[i]);
            }
            mx=mx2;
            times++;
        }
        ffr(i,0,n){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}
