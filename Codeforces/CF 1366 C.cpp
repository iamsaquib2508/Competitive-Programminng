#include <bits/stdc++.h>
#define ull uint64_t
#define uint uint32_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int n, m, i, j, x, total, d1, d2, ans=0, d[100][2]={}, z, on;
        cin >> n >> m;
        total=n+m-2;
        ffr(i,0,n)
        {
            ffr(j,0,m)
            {
                cin >> x;
                //a[i][j]=x;
                d1=(i+j);
                d2=(total-i-j);
                //cout << d1 << " d1 d2 " << d2 << endl;
                if(d1!=d2)
                {
                    d[minn(d1,d2)][x]++;
                }
            }
        }
        ffr(i,0,total)
        {
            z=d[i][0]; on=d[i][1];
            //cout << z << " z on " << on << endl;
            ans+=(minn(z,on));
        }
        cout << ans << endl;
    }
}
