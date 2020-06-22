#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int

using namespace std;
int n;
ll a[100005];

int f(ll x, ll b)
{
    int i, sz=n;
    ll cur, dif=b-x;
    int cnt=0;
    ffr(i,2,sz)
    {
        cur=a[i];
        if(cur-b+1==dif)
        {
            cnt++; b=cur+1;
        }
        else if(cur-1-b==dif)
        {
            cnt++; b=cur-1;
        }
        else if(cur-b==dif) b=cur;
        else return 1e9;
    }
    return cnt;
}

int main()
{
    int ans, i; ll x, y;
    cin >> n;
    ffr(i,0,n)
    {
        cin >> x; a[i]=x;
    }
    if(n<3) {cout << "0\n"; return 0;}
    x=a[0]; y=a[1];
    ans=1e9;
    ans=min(ans,f(x,y));
    //cout << ans << endl;
    ans=min(ans,1+f(x,y+1));
    //cout << ans << endl;
    ans=min(ans,1+f(x,y-1));
    //cout << ans << endl;
    ans=min(ans,1+f(x+1,y));
    //cout << ans << endl;
    ans=min(ans,2+f(x+1,y+1));
    //cout << ans << endl;
    ans=min(ans,2+f(x+1,y-1));
    //cout << ans << endl;
    ans=min(ans,1+f(x-1,y));
    //cout << ans << endl;
    ans=min(ans,2+f(x-1,y+1));
    //cout << ans << endl;
    ans=min(ans,2+f(x-1,y-1));
    //cout << ans << endl;

    //cout << "ans org ";
    if(ans<1e9)
    cout << ans << endl;
    else cout << "-1\n";
    return 0;
}
