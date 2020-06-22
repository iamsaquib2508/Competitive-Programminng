#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int fixer(int i, int dod, int n)
{
    return (dod+i)%n;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, a[6]={0,0,0,0,0,0}, j;
        cin >> n;
        cin >> a[0] >> a[1] >> a[2]; //r p s
        string st;
        cin >> st;
        ffr(i,0,n)
        {
            if(st[i]=='R')
            {
                if(a[1]>0) {st[i]='P'; a[1]--;}
                else st[i]='.';
            }
            else if(st[i]=='P') { if(a[2]>0) {st[i]='S'; a[2]--;} else st[i]='.'; }
            else if(st[i]=='S') { if(a[0]>0) {st[i]='R'; a[0]--;} else st[i]='.'; }

        }
        int ans=0;

        ffr(i,0,n)
        {
            if(st[i]=='.')
            {
                if(a[0]>0) { st[i]='R'; a[0]--; }
                else if(a[1]>0) { st[i]='P'; a[1]--; }
                else if(a[2]>0) { st[i]='S'; a[2]--; }
            }
            else ans++;
        }
        //cout << ans;
        if(ans>(n-1)/2)
        {

            cout << "YES\n" << st << endl;
        }
        else cout << "NO\n";
    }
}
