#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

int arr[200005];
int n, b, a, i, afix, bfix;

int main()
{
    while(cin >> n >> b >> a)
    {
        afix=a; bfix=b;
        ffr(i,0,n) cin >> arr[i];
        ffr(i,0,n)
        {
            if(arr[i]==0)
            {
                if(a>0) a--;
                else if(b>0) {b--;}
                else break;
            }
            else
            {
                if(a==afix) a--;
                else if(b>0) {b--; a++;}
                else if(a>0) a--;
                else break;
            }
        }
        //if(i<n)
        cout << i << endl;
    }
    return 0;
}
