#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if(m%n>0) {cout << "-1\n"; return 0;}
    int x=m/n, i=0;
    while(x%3==0)
    {
        x/=3; i++;
    }
    while(x%2==0) {x/=2; i++;}
    if(x==1) cout << i << endl;
    else cout << "-1\n";

    return 0;
}
