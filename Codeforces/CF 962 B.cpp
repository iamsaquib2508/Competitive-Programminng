




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
ll ans, boro, soto;

void call(ll len)
{
    if(len==0) return;
    ll alen, blen;
    alen=len/2.0;
    blen=alen;
    if(len&1)
    {
        blen++;
    }
    //cout << len << " " << boro << " " << soto << endl;
    ans+=min(alen,soto);
    soto-=alen; if(soto<0) soto=0;
    
    ans+=min(blen,boro);
    boro-=blen; if(boro<0) boro=0;
    
    ll b=boro;
    boro=max(boro,soto);
    soto=min(b,soto);
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //while(1)
    {

    ll a, b, n, i, sl=0;
    string ss;
    cin >> n >> a >> b;
    boro=max(a,b); soto=min(a,b);
    cin >> ss;
    ans=0;
    ffr(i,0,n)
    {
        if(ss[i]=='*')
        {
            call(sl);
            sl=0;
        }
        else
        {
            sl++;
        }
    }
    call(sl);
    
    cout << setprecision(15) << ans << endl;
    
}

    return 0;
}
