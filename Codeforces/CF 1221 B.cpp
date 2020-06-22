#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    int n, i, j;
    while(cin >> n)
    {
        bool ok=1;
        ffr(i,0,n)
        {
            ffr(j,0,n)
            {
                if(ok) cout << 'B';
                else cout << 'W';
                ok=!ok;
            }
            cout << endl;
            if(!(n&1)) ok=!ok;
        }
    }
}
