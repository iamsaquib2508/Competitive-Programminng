#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

string s, s1, s2;

void print()
{
    int i=0, j=0;
    while(i<s1.size() && j<s2.size())
    {
        if(s1[i]<s2[j]) {cout << s1[i]; i++;}
        else {cout << s2[j]; j++;}
    }
    while(i<s1.size()) {cout << s1[i]; i++;}
    while(j<s2.size()) {cout << s2[j]; j++;}
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> s;
        s1=""; s2="";
        int start=(s[0]&1);
        int cur=0, n=s.size();
        while(cur<n)
        {
            while(cur<n && (s[cur]&1)==start){ s1+=s[cur]; cur++;}

            while(cur<n && (s[cur]&1)!=start){ s2+=s[cur]; cur++;}

        }
        //cout << s1 << " " << s2 << endl;
        print(); cout << endl;
    }
}
