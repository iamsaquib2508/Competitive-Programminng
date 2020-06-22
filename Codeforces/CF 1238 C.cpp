#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

int main()
{
    int q; cin >> q;
    while(q--)
    {
        int h, n, i;
        int p[200005];
        cin >> h >> n;
        p[0]=0;
        ffr(i,0,n)
        {
            cin >> p[i+1];
        }
        sort(p,p+n+1);
        int ans=0, cur, next;
        cur=p[n]; next=n-1;
        while(next>1)
        {
            //cout << cur << " cur next " << p[next] << endl;
            if(cur-1==p[next])
            {
                if(p[next-1]==cur-2)
                {
                    cur-=2; next-=2;
                }
                else
                {
                    next--; ans++;
                }
            }
            else
            {
                cur=p[next]+1;
            }
        }
        if(cur>=p[next]+1 && p[next]>1) ans++;

        cout << ans << endl;
    }
}
