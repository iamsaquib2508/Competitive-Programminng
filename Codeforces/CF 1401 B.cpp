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

    while(tt--){
        ll a0, a1, a2, b0, b1, b2, ans;
        cin >> a0 >> a1 >> a2;
        cin >> b0 >> b1 >> b2;
        ans = minn(a2,b1);
        a2-=ans; b1-=ans;
        ans+=ans;

        b2-=(a2+a0);
        if(b2>0)ans-=(2*(b2));
        cout << ans << endl;
    }
    cin >> tt;
}
