




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

using namespace std;


/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

ll dp[502][502];
ll bigsum, summ[502];
vector<int> num[502];
ll n, m, k;

ll call(int pos, int kk)
{
    if(kk==0) return 0;
    if(pos==n) return 0;
    
    if(dp[pos][kk]!=-1) return dp[pos][kk];
    int sz=num[pos].size(), i;
    ll tans, ans;
    int sp=0, ep=sz-1;

    ll cnt=0;
    ans=call(pos+1,kk)+summ[pos];
    ffr(i,0,sz)
    {
        if(kk-i<1) break;
        if(num[pos][sp]>num[pos][ep])
        {
            cnt+=num[pos][sp];
            tans=call(pos+1, kk-i-1)+(summ[pos]-cnt);
            //if(tans)
            ans=min(ans,tans);
            sp++;
        }
        else
        {
            cnt+=num[pos][ep];
            tans=call(pos+1, kk-i-1)+(summ[pos]-cnt);
            //if(tans)
            ans=min(ans,tans);
            ep--;
        }
    }
    pf("pos %d kk %d ans %d\n", pos, kk, ans);
    return dp[pos][kk]=ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    int i, j, sum, cn;
    bigsum=0;
    mm(summ,0);
    mm(dp,-1);
    string s;
    ffr(i,0,n)
    {
        cin >> s;
        
        j=0;
        while(s[j]=='0') j++;
        sum=1;
        while(j<m)
        {
            j++; cn=1;
            
            while(1)
            {
                if(j==m) goto ddd;
                if(s[j]!='0') break;
                j++; cn++;
            }
            //cout << cn << ' ';
            num[i].pb(cn);
            sum+=cn;
        }
        ddd:
        summ[i]=sum;
        bigsum+=sum;

        cout << sum << endl;
    }
    cout << call(0, k) << endl;
	return 0;

}
