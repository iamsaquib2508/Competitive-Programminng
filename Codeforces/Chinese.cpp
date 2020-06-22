#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mp(a,b) make_pair(a,b)
#define mmxx 1000000

using namespace std;

void ex_euclid(ll m, ll n, ll* a, ll* b)
{
    //assuming m>n
    //am+bn= gcd(m,n), fill a,b
    if(n==0)
    {
        a[0]=1; b[0]=0;
        return;
    }
    ex_euclid(n,m%n,a,b);
    ll aa=b[0];
    ll bb=a[0]-m/n*b[0];
    a[0]=aa;
    b[0]=bb;
    //cout << bb[0] << " * a + m * " << aa[0] << endl;
    //pf("am + bn -> %lld * %lld + %lld * %lld\n", aa, m, bb, n);
    return;
}

ll mod_inverse(ll a, ll m)
{
    //assuming gcd(a,m)=1, a<m
    ll *aa, *bb;
    aa=new ll[1], bb=new ll[1];
    ex_euclid(m,a,aa,bb);
    //cout << bb[0] << " * a + m * " << aa[0] << endl;
    return (bb[0]+m*(bb[0]<0));
}

ll gcd(ll a, ll b)
{
    return (b)?gcd(b,a%b):a;
}

ll bbb[10], mmm[10];
ll mymod(ll sec, ll m)
{
    if(sec<0)
    {sec=sec+(-sec)/m*m; if(sec<0) sec+=m;}
    else sec=sec-sec/m*m;
    return sec;
}

plolo call(int pos, ll l, ll r)
{
    if(pos<0) return mp(l,r);
    ll b=bbb[pos], m=mmm[pos];

    ll sec=(b-r)*mod_inverse(l,m);
    sec=mymod(sec,m);

    plolo p= call(pos-1,m,sec);

    m=l*p.first;
    return mp(m,mymod((l*p.second+r),m));
}

int main()
{
    //cout << mod_inverse(4,7);

    ll n, i, a, b, m, g, temp;
    //while(cin >> a >> m) cout << mod_inverse(a,m) << endl;
    while(cin >> n)
    {
        ffr(i,0,n)
        {
            cin >> a >> b >> m;
            g=gcd(a,m);
            a/=g; b/=g; m/=g; //if not, this is inconsistent

            if(a>1)
            {
                temp=mod_inverse(a,m);
                b*=temp; b%=m;
            }
            bbb[i]=b;
            mmm[i]=m;
        }
        plolo p=call(n-1,1,0);
        pf("%lld*k+%lld\n",p.first,p.second);
    }
}
