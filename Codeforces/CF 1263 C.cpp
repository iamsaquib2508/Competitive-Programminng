#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf
#define PI acos(-1.0)

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

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n==1)
        {
            cout << "2\n0 1\n";
        }
        else if(n==2)
        {
            cout << "3\n0 1 2\n";
        }
        else if(n==3)
        {
            cout << "3\n0 1 3\n";
        }
        else
        {
            set<int> s;
            s.clear();

            s.insert(0);
            s.insert(1);
            int div=2, cur;

            cur=n/div;
            while(cur>1)
            {
                div=n/cur;
                s.insert(div);
                div++;
                cur=n/div;
            }
            s.insert(n);
            //set<int>::iterator it=st.begin();
            cout << s.size() << endl;
            for (auto a: s)
            {
                cout << a << " ";
            }
            cout << endl;
        }

    }
}
