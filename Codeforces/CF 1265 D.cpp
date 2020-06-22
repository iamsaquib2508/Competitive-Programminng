#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define pf printf
#define ll long long int
#define ff first
#define ss second
#define sf(a) scanf("%d", &a)
#define CMAX 30002

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
    int a, b, c, d, i;
    while(cin >> a >> b >> c >> d)
    {
        if(a>=b+2 || d>=c+2) cout << "NO\n";
        else if(a==b+1 && c+d==0)
        {
            cout << "YES\n0"; ffr(i,0,b) cout << " 1 0"; cout << endl;
        }
        else if(d==c+1 && a+b==0)
        {
            cout << "YES\n3"; ffr(i,0,c) cout << " 2 3"; cout << endl;
        }
        else
        {
            b-=a; c-=d; //010101   232323

            if(b>=0 && c>=0 && abs(b-c)<2)
            {
                if(b>c)
                {
                    cout << "YES\n1"; ffr(i,0,a) cout << " 0 1"; ffr(i,0,c) cout << " 2 1"; ffr(i,0,d) cout << " 2 3"; cout << endl;
                }
                else
                {
                    cout << "YES\n";
                    ffr(i,0,a) cout << "0 1 "; ffr(i,0,b) cout << "2 1 "; ffr(i,0,d) cout << "2 3 ";
                    if(b<c) cout << "2\n";
                    else cout << endl;
                }
            }
            else cout << "NO\n";
        }

    }
}
