#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}


int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

ll sil(double a)
{
    ll temp=(int)(a);
    if( temp < a ) temp++;
    return temp;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        double h, c, t, avg, ans, t1, t2;
        int ans1, ans2;
        cin >> h >> c >> t;
        avg=(h+c)/2;
        if(t<=avg) ans1=2;
        else
        {
            ans=(h-t)/(t-avg);

            //cout << ans;
            ans2=sil(ans);
            ans1=(int)ans;
            if(ans2==ans1)
            {
                //integer
                if(ans1&1)
                    {ans1--; ans2++;}

            }
            else
            {

                if(ans2 & 1)
                    ans2++;
                else ans1--;
            }
                //cout << ans1 << ' ' << ans2 << endl;
                t1=(avg*ans2+h)/(ans2+1);
                t2=(avg*ans1+h)/(ans1+1);
                //cout << t1 << ' ' << t2 << endl;
                if(t2-t>t-t1)
                    ans1=ans2;


            ans1++;
        }
        cout << (int)(ans1) << endl;
    }
}
