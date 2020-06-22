#include <bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int sp[10000002];
bool prime[10000002];
int d2[500002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int sq = (10000001);
    int p2;
    memset(prime, true, sizeof(prime));

    for (int p=3; p*p<=sq; p+=2)
    {
        if (prime[p] == true)
        {
            p2 = p+p;
            sp[p]=p;
            for (int i=p*p; i<=sq; i += p2){
                prime[i] = false;
                sp[i]=p;
            }
        }
    }
    int n;
    while(cin >> n)
    {
        int x, i, p, pp;
        ffr(i,0,n)
        {
            cin >> x;
            if(!(x&1))
            {
                x>>=1;
                p=2;
                while(!(x&1)){
                    x>>=1;
                    p+=p;
                }
            }
            else{
                //cout << sp[x] << endl;
                pp=sp[x];
                p=pp;
                x/=pp;
                while(x%pp==0){
                    x/=p;
                    p*=pp;
                }
            }
            if(x==1) x=-1, d2[i]=-1;
            else d2[i]=p;
            cout << x << ' ';// << d2[i] << endl;
        }
        //ffr(i,0,n)
        //    cout << d1[i] << ' ';
        cout << endl;
        ffr(i,0,n)
            cout << d2[i] << ' '; cout << endl;
    }
}
