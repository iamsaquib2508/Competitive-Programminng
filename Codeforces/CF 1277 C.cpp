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

set<int> v;
int prev;


void f(string t, int pos)
{
    int sz=s.size(), tz=t.size();
    int found=-1, i, j;
    while(1)
    {
        found=s.find(t,found+1);
        if(found!=string::npos)
            {v.insert(found+pos); s[found+pos]='?'; }
        else break;
    }


}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        v.clear();


        cin >> s;
        f("twone", 2);
        f("one", 1);
        f("two", 1);
        int sz=v.size();
        cout << sz << endl;
        for(int a: v)
        {
            cout << a+1 << " ";
        }
        cout << endl;
    }
}
