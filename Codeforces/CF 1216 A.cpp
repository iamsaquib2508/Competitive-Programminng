#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int mn(int a, int b)
{
    if(a<b) return a;
    return b;
}


int main()
{
    int n, i, ans;
    string s;
    while(cin >> n >> s)
    {
        ans=0;
        ffr(i,0,n)
        {
            if(s[i]=='b' && s[i+1]=='b') {ans++; s[i+1]='a';}
            else if(s[i]=='a' && s[i+1]=='a') {ans++; s[i+1]='b';}
            i++;
        }
        cout << ans << endl << s << endl;
    }
}
