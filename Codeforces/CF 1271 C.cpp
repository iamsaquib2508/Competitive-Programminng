#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int main()
{
    int n, x, y, sx, sy, mx, down, up, i, right, left;
    while(cin >> n >> sx >> sy)
    {
        left=0, right=0, up=0, down=0;
        ffr(i,0,n)
        {
            cin >> x >> y;
            if(x<sx) left++;
            if(sx<x) right++;
            if(y<sy) down++;
            if(sy<y) up++;
        }
        mx=maxx(maxx(left,right),maxx(up,down));
        cout << mx << endl;
        if(mx==0)
        {
            if(sy==0) cout << sx << " 1\n";
            else cout << sx << " 0\n";
        }
        else if(mx==left) cout << sx-1 << " " << sy << endl;
        else if(mx==right) cout << sx+1 << " " << sy << endl;
        else if(mx==up) cout << sx << " " << sy+1 << endl;
        else cout << sx << " " << sy-1 << endl;
    }
}
