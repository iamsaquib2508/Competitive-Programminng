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

using namespace std;

int main()
{
    int n, i, ans;
    while(cin >> n)
    {
        ans=10000000;
        string s;
        cin >> s;

        ffr(i,3,n)
        {
            int temp=0;
            temp+=min((s[i-3]-'A'+26)%26,(-s[i-3]+'A'+26)%26);
            temp+=min((s[i-2]-'C'+26)%26,(-s[i-2]+'C'+26)%26);
            temp+=min((s[i-1]-'T'+26)%26,(-s[i-1]+'T'+26)%26);
            temp+=min((s[i]-'G'+26)%26,(-s[i]+'G'+26)%26);
            ans=min(ans,temp);
        }
        cout << ans << endl;
    }
}
