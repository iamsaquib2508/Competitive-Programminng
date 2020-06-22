#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf

using namespace std;


ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}


int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, prev, temp, cur, arr[100005], i;
        bool taken[100005];

        cin >> n;
        mm(taken,0);
        cin >> prev;

        cur=1;
        taken[prev]=true;

        bool ok=true;
        arr[0]=prev;

        ffr(i,1,n)
        {
            cin >> temp;
            if(temp==prev)
            {
                while(cur<prev && taken[cur]==true)
                {
                    cur++;
                }
                if(cur<prev && taken[cur]==false)
                {
                    arr[i]=cur;
                    taken[cur]=true;
                    while(taken[cur]==true)cur++;
                }
                else
                {
                    ok=false;
                }
            }
            else
            {
                arr[i]=temp;
                taken[temp]=true;
                prev=temp;
            }
        }
        if(ok==false)
        {
            cout << "-1\n";
        }
        else
        {
            ffr(i,0,n) cout << arr[i] << " "; cout << endl;
        }

    }
    return 0;
}
