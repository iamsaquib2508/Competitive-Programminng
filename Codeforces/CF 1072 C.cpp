



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


ll solver(ll a)
{
    if(a==0) return 0;
    ll hi, lo, mid, nnplus1;
    lo=0; hi=1000000;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        nnplus1=mid*mid+mid;
        if(nnplus1==a)
        return mid;
        else if(nnplus1<a) lo=mid;
        else hi=mid;
    }
    if(hi*hi+hi<=a) return hi;
    else return lo;
}

vector<ll> v1, v2;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);

    ll a, b, total, cur, i, j, sz, fake=-1;

    v1.clear(); v2.clear();
    cin >> a >> b;
    total=solver(a+b+a+b);
    //if(a==0 && b==0) {cout << "0\n\n0\n\n"; return 0;}
    //cout << total << " total\n";
    cur=total;
    while(cur>0 && a>=cur)
    {
        v1.pb(cur); a-=cur; cur--;
    }
    //cout << a << " a cur " << cur << endl;
    if(a>0)
    {
        v1.pb(a); fake=a;
    }
    while(cur>0)
    {
        if(cur!=fake)
        v2.pb(cur); cur--;
    }
    sz=v1.size();
    cout << sz << endl;
    ffr(i,0,sz)
    {
        cout << v1[i] << ' ';
    }
    sz=v2.size();
    cout << endl << sz << endl;
    ffr(i,0,sz)
    {
        cout << v2[i] << ' ';
    }
    cout << endl;



    return 0;
}
