#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main()
{
    ll r, c, num, prev, i, j;
    while(cin >> r >> c)
    {prev=1;
    if(r==1 && c==1) cout << "0\n";
    else if (c>1)
    ffr(i,0,r)
    {

        num=2;
        ffr(j,0,c)
        {
            cout << num*prev << ' ';
            num++;
        }
        cout << '\n';
        prev=num+i;
    }
    else
    {
        ffr(i,0,r) cout << i+2 << '\n';
    }}

}
