#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define eps 1e-8
using namespace std;
long double kvsum=0, v2sum=0, k2sum=0, d;
long double r1, r2, x;
bool ok(long double mid)
{
    long double d = k2sum + kvsum*mid*2 + v2sum*mid*mid;
    if(d<=r1*r1+r2*r2-2.0*r1*r2) return true;
    return false;
}
int main()
{
    int T, n, i;
    long double k[12], v[12];
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(cin >> T)
    {
        while(T--)
        {
            cin >> n >> r1 >> r2;
            kvsum=0, v2sum=0, k2sum=0;

            ffr(i,0,n) {cin >> x; k[i]=x;}
            ffr(i,0,n) {cin >> x; k[i]-=x; k2sum+=(k[i]*k[i]);}

            ffr(i,0,n) {cin >> x; v[i]=x;}
            ffr(i,0,n) {cin >> x; v[i]-=x; kvsum+=(k[i]*v[i]); v2sum+=(v[i]*v[i]);}
            if(r2==r1) {cout << "-1\n"; continue;}
            if(r2>r1) {long double tm=r1; r1=r2; r2=tm;}
            if(kvsum*v2sum>=0)
            {
                //no relative movement // or best at initial
                if(!ok(0)) {cout << "-1\n"; continue;}
                else cout << "0\n";
            }
            else
            {
                long double hi, lo, mid;
                hi=(-kvsum)/v2sum; lo=0;
                if(!ok(hi)) {cout << "-1\n"; continue;}
                mid=(hi+lo)/2;
                while(hi-lo>eps)
                {
                    mid=(hi+lo)/2;
                    if(ok(mid)) hi=mid;
                    else lo=mid;
                    if(lo>100000) break;
                }
                long double ans;
                if(ok(lo)) ans=lo;
                else ans=hi;
                if(ans>100000) {cout << "-1\n"; continue;}
                cout << setprecision(12) << ans << endl;
            }
        }
    }
}
