



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

int kx, ky;
int n, m;

ll solve(int row, int col)
{
    ll ans=0;
    int rd, cd;
    bool paisi=0;
    ans+=(n-1)+(m-1);
    ans+=(min(row,col)+min(n-1-row,col)+min(row,m-1-col)+min(n-1-row,m-1-col));
    //cout << ans << " ans1\n";
    if(row==kx)
    {
        paisi=1;
        if(col<ky)
        {
            ans-=(m-1-ky);
        }
        else ans-=(ky);
        //cout << ans << " ans21\n";
    }
    if(col==ky)
    {
        paisi=1;
        if(row<kx) ans-=(n-1-kx);
        else ans-=(kx);
        //cout << ans << " ans22\n";
    }
    rd=abs(row-kx);
    cd=abs(col-ky);
    if(rd==cd)
    {
        paisi=1;
        if(kx<row && ky<col)
        {
            ans-=(min(kx,ky));
        }
        else if(kx>row && col<ky)
        {
            ans-=(min(n-1-kx,ky));
        }
        else if(row<kx && col<ky)
        {
            ans-=(min(n-1-kx,m-1-ky));
        }
        else
        {
            ans-=(min(kx,m-1-ky));
        }
        //cout << ans << " ans23\n";
    }
    if(!paisi) ans++;
    //cout << "ans " << ans << endl;
    return ans;
}

int main()
{

    int T, i, j, row, col;
    ll ans;
    cin >> T;
    while(T--)
    {

        cin >> n >> m >> kx >> ky;
        kx--; ky--;
        ans=0;
        ffr(i,0,n)
        {
            ffr(j,0,m)
            {
                if(i==kx && j==ky) continue;
                ans+=(m*n-solve(i,j)-1);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
