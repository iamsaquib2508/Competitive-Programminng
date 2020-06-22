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
        int n, x, i, a[100005], sum=0, ans;
        cin >> n >> x;
        ffr(i,0,n)
        {
            cin >> a[i];
            sum+=a[i];
        }
        if(sum%x==0){
            int k1=1, k2=1;
            ffr(i,0,n){
                if(a[i]%x==0) k1++;
                else break;
            }
            ffr(i,0,n){
                if(a[n-1-i]%x==0) k2++;
                else break;
            }
            ans=n-(minn(k1,k2));
        }
        else ans=n;
        cout << ans << endl;
    }
}
