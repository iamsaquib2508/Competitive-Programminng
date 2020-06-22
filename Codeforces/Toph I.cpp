#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mx 100005

using namespace std;
int x, y;
ll dp[1001][1001];
ll MOD=1000000007;

bool val(int xx, int yy)
{
    if(xx<0 || xx>x || yy<0 || yy>y) return 0;
    return 1;
}

int main()
{
    int i, j;
    while(scanf("%d %d", &x, &y)==2)
    {
        mm(dp,-1);
        dp[0][0]=1;
        //cout << call(x,y) << endl;
        ffrr(i,1,x) dp[i][0]=1;
        ffrr(i,1,y) {dp[0][i]=0; i++; if(i>y) break; dp[0][i]=1;}

        ffrr(i,1,x)
        {
            ffrr(j,1,y)
            {
                ll cur=0;
                if(val(i,j-2)) {cur+=dp[i][j-2]; if(cur>=MOD) cur-=MOD;}
                if(val(i-1,j-1)) {cur+=dp[i-1][j-1]; if(cur>=MOD) cur-=MOD;}
                if(val(i-1,j)) {cur+=dp[i-1][j]; if(cur>=MOD) cur-=MOD;}
                if(val(i-2,j-2)) {cur+=dp[i-2][j-2]; if(cur>=MOD) cur-=MOD;}
                dp[i][j]=cur;
            }
        }
        pf("%lld\n", dp[x][y]);
    }
}
