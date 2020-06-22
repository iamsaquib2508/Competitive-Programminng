#include <bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair

using namespace std;

double power(double x, int n)
{
    double res=1.0;
    while ( n )
    {
        if ( n & 1 )
        {
            res *= x;
        }
        x *= x ;
        n >>= 1;
    }
    return res;
}

/*

n[k1] = 0
n[k1-1] = 1+ (1-p) . n[k1] + p . t[1]
n[k1-2] = 1+ (1-p) . n[k1-1] + p . t[1]
        = 1+ (1-p) . ( 1+ (1-p) . n[k1] + p . t[1]) ) + p. t[1]
        = (1+ p . t[1]) ( 1 + (1-p) ) + (1-p)^2 . n[k1]
n[k1-j] = (1+ p . t[1]) ( 1 + (1-p) + ... + (1-p)^(j-1) ) + (1-p)^j . n[k1]
        = (1+ p . t[1]) . (1-(1-p)^j) / p ...(1)

so...
n[0] = n[k1-k1] = (1+ p . t[1]) . (1-(1-p)^k1) / p   and
t[0] = n[k2-k2] = (1+ (1-p) . n[1]) . (1-(p)^k1) / (1-p) ...(2)
so...
(1+ (1-p) . n[1]) . (1-(p)^k1) / (1-p) = (1+ p . t[1]) . (1-(1-p)^k1) / p ...(3)
this is one relation between n[1] and t[1]

also from (1)
n[1] = (1+ p . t[1]) . (1-(1-p)^(k1-1)) / p ...(4)
substitute n[1] in (3) with value from (4)
this gives t[1]. put it in (2)
*/

int main()
{
    int tt, cc=1; cin >> tt;
    while(tt--)
    {
        double p, lh, rh, one_pk2, one_p_k1, n0;
        int k1, k2;

        cin >> p >> k1 >> k2;
        if(p==0)
            n0=k1;
        else if(p==1)
            n0=k2;
        else
        {
            one_pk2 = 1 - power(p,k2);
            lh = 1.0/(1-p)*one_pk2;
            one_p_k1 = power((1-p),k1);
            rh = 1 - one_p_k1 - one_pk2 * (1 - one_p_k1 / (1-p));
            n0 = lh/rh*(1 - one_p_k1);
        }
        printf("Case %d: %.8lf\n", cc++, n0);
    }
}
