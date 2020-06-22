#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int a[3000];

bool ggo(int num, int need)
{
    if(num==0) return false;
    if(a[num]>=need) return true;
    else return ggo(num/2,(need-a[num])*2);
}

int main()
{
    int q, n, i, x;
    while(cin >> q)
    {
        while(q--)
        {
            mm(a,0);
            cin >> n;
            ffr(i,0,n)
            {
                cin >> x;
                if(x>2048) continue;
                a[x]++;
            }
            if(ggo(2048,1)) cout << "YES\n";
            else cout << "NO\n";

        }

    }
}
