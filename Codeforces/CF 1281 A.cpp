#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

string s;

bool f(string t)
{
    if(s[s.size()-1]==t[t.size()-1]) return true;
    return false;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> s;
        if(f("po"))
        {
            cout << "FILIPINO\n";
        }
        else if(f("desu"))
        {
            cout << "JAPANESE\n";
        }
        else if(f("masu"))
        {
            cout << "JAPANESE\n";
        }
        else
        {
            cout << "KOREAN\n";
        }
    }
}
