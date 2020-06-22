




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




int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    ll n, m, i, j, k, ans, mx=0, l, ii, jj;
    char a[102][102];
    cin >> n >> m;
    ffr(i,0,n)
    {
        ffr(j,0,n) cin >> a[i][j];
    }
    
    ffr(i,0,n)
    {
        ffr(j,0,n)
        {
            if(a[i][j]=='#') continue;
            ans=0;
            for(k=j; k<n && (k-j+1<=m) ;k++)
            {
                if(a[i][k]=='#') break;
            }
            l=(k-j);
            for(k=j;k>=0 && (j-k+1<=m);k--)
            {
                if(a[i][k]=='#') break;
            }
            l+=(j-k);
            
            l--;
            if(l>=m)
            ans+=(l-m+1);
            
            //cout << ans << endl;
            
            for(k=i; k<n && (k-i+1<=m) ;k++)
            {
                if(a[k][j]=='#') break;
            }
            l=(k-i);
            for(k=i;k>=0 && (i-k+1<=m);k--)
            {
                if(a[k][j]=='#') break;
            }
            l+=(i-k);
            l--;
            if(l>=m)
            ans+=(l-m+1);
            ans--;
            if(mx<ans)
            {
                ii=i, jj=j; mx=ans;
                //cout << ii << " " << jj << " " << mx << endl;
            }
        }
    }
    cout << ii+1 << " " << jj+1 << endl;
    return 0;
}
