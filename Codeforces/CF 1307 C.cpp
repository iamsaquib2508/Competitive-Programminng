#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18
#define bug(x) ;//cerr << #x << " = " << x << endl

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

int main()
{
    string s;
    while(cin >> s)
    {
        int num, i, j;
        ll cnt[26]={}, ans2[27*27]={}, mx;
        for(char a: s)
        {
            num=a-'a';

            ffr(i,0,26)
            {
                //c='a'+i;
                //if(i!=num)
                {
                    ans2[i*26+num]+=cnt[i];
                }
            }
            cnt[num]++;
        }
        mx=0;
        ffr(i,0,26)
        {
            ffr(j,0,26)
            {
                //if(i!=j)
                mx=maxx(mx,ans2[i*26+j]);
            }
            mx=maxx(mx,cnt[i]);
        }
        cout << mx << endl;
    }
}
