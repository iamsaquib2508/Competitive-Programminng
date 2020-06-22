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
    int n; cin >> n;
    while(n--)
    {
        string s;
        cin >> s;

        int i, sz=s.size(), sum=0;
        bool z=0, ev=0;

        ffr(i,0,sz)
        {
            if(s[i]=='0' && !z) {z=1; continue;}
            else if( ( (s[i]-'0')&1)==0 && 1 )
            {
                ev=1; sum+=(s[i]-'0');
            }
            else sum+=(s[i]-'0');

        }
        if((s=="0") || (z && ev && (sum%3)==0 )) cout << "red\n";
        else cout << "cyan\n";
    }
}
