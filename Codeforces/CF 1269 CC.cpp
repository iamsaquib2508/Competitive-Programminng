#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 100003
#define pil pair<int,ll>
#define mp make_pair

using namespace std;

char maxx(char a, char b)
{
    if(a>b) return a; return b;
}

int n, k;

string print(string t)
{
    ll lim=n/k, cur=0, i;
    string ret="";
    //cout << cur << endl;
    ffr(i,0,lim) {ret+=t;}
    //cout << cur << endl;
    i=0;
    ffr(cur,t.size()*lim,n) {ret+=t[i]; i++;}
    return ret;//cout << endl;
}

int main()
{

    while(cin >> n >> k)
    {
        string s;
        cin >> s;
        cout << n << endl;
        int i, sz, j;
        string t="";
        ffr(i,0,k) t+=s[i];

        string sol=print(t);
        //cout << sol << " sol\n";
        if(sol<s)
        {
            for(i=k-1;i>=0;i--)
            {
                if(t[i]<'9') {t[i]++; ffr(j,i+1,k) t[j]='0'; break;}
            }
            sol=print(t);
        }
        cout << sol << endl;

    }
}
