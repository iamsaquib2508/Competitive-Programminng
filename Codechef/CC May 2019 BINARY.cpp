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

int main()
{
    while(cin >> T)
    {
        while(T--)
        {
            cin >> n >> z;
            ffr(i,0,n)
            {
                cin >> x;
                a[i]=x;
                if(x) vy1++;
                else vy1=0;
            }
            prevwt=0;

            cur1=0;
            for(i=n-1;i>=0;i--)
            {
                if(a[i])
                {
                    cur1++;
                }
                else
                {
                    if(z<=cur1)
                    {
                        cout << cur1-z+vy1 << endl;
                    }
                    else
                    {
                        
                    }
                }
            }
        }
    }
}
