#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005
#define so(x) cerr << #x << " = " << x << endl

using namespace std;

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll n, x, i, sum=0, xorr=0, j, k;

        cin >> n;
        ffr(i,0,n)
        {
            cin >> x; sum+=x;
            xorr^=x;
        }
        if(sum==xorr) cout << "2\n" << sum << ' ' << sum+sum << endl;
        else
        {
            //cout << "parina\n";
            int boss=900;
            ffr(i,0,boss)
            {
                ffr(j,0,boss)
                {
                    ffr(k,0,boss)
                    {
                        if(sum+i+j+k==2*(xorr^i^j^k))
                        {
                            cout << i << ' ' << j << ' ' << k << endl;
                            break;
                        }
                    }
                    if(k<boss) break;
                }
                if(j<boss) break;
            }
            // bool more=0;
            // ll rem;
            // if(sum&1)
            // {
            //     sum++; xorr^=1; more=1;
            // }
            // rem=xorr+xorr-sum;
            // if(more) cout << "3\n1 "; else cout << "2\n";
            // cout << rem/2 << ' ' << rem/2 << endl;
        }
    }
}
