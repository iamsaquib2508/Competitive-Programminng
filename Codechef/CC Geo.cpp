



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

ll func(double cosx, ll a, ll b)
{
    double csquare=a*a+b*b-2*a*b*cosx;
    double c=sqrtl(csquare*1.0);
    ll ret=(floor(c));
    ll ans;
    if((ret-1)*(ret-1)>=csquare) ans=ret-1;
    else if((ret*ret)>=csquare) ans=ret;
    else if((ret+1)*(ret+1)>=csquare) ans=ret+1;

    return min(ans,a+b-1);
}

double cosss(ll a, ll b, ll c)
{
    double temp=a*a*1.0+b*1.0*b-c*1.0*c;
    temp/=(2.0*a*b);

    return temp;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int T, i;
    cin >> T;

    pair<ll,int> a[1003];
    while(T--)
    {
        int ansa, ansb, ansc, j;
        int n, p, q, temp;
        int aa, bb, cc;
        cin >> n >> p >> q;
        ffr(i,0,n)
        {
            cin >> temp;
            a[i]=mp(temp,i);
        }
        sort(a,a+n);
        double cosx=p*1.0/q;
        double ans=1.1, got;
        ffr(i,0,n)
        {
            ffr(j,i+1,n)
            {
                ll uplim=func(cosx,a[i].first,a[j].first), lo, hi, mid;
                lo=0; hi=n-1;
                while(hi-lo>1)
                {
                    mid=(lo+hi)/2;
                    if(a[mid].first>uplim)
                    {
                        hi=mid;
                    }
                    else
                    {
                        lo=mid;
                    }
                }
                if(uplim<a[lo].first)
                {
                    //imp
                }
                else if(uplim<a[hi].first)
                {
                    //lo
                    if(lo==j || lo==i)
                    {
                        lo--;
                        if(lo==i) lo--;
                        if(lo<0) continue;
                    }

                    aa=a[i].first;
                    bb=a[j].first;
                    cc=a[lo].first;
                    got=cosss(aa,bb,cc);
                    if(got<=ans)
                    {
                        ansa=a[i].second, ansb=a[j].second, ansc=a[lo].second;
                        ans=got;
                    }
                }
                else
                {
                    //hi
                    if(hi==j || hi==i)
                    {
                        hi--;
                        if(hi==i) hi--;
                        if(hi<0) continue;
                    }
                    aa=a[i].first;
                    bb=a[j].first;
                    cc=a[hi].first;
                    got=cosss(aa,bb,cc);
                    if(got<=ans)
                    {
                        ansa=a[i].second, ansb=a[j].second, ansc=a[hi].second;
                        ans=got;
                    }
                }
            }
        }
        //cout << "my: ";
        if(ans>=1)
        {
            cout << "-1\n";
        }
        else
        {
            cout << ansc+1 << " " << ansb+1 << " " << ansa+1 << endl;
        }


    }




    return 0;
}
