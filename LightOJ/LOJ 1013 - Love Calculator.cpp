#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define sf scanf

using namespace std;
string f, s;
ll fs, ss;

class node
{
    public:

    ll ways, len;
    bool operator !=(node b)
    {
        return ( ways!=b.ways || len!=b.len ) ;
    }
};

node dp[35][35];
node bingu;

/* ******************* Donate Blood, Save Life *********************** */

node call(ll i, ll j)
{
    if(i>=fs || j>=ss)
    {
        node ans;
        if(i>=fs)
        {
            ans.len=ss-j;
            ans.ways=1;
        }
        else
        {
            ans.len=fs-i;
            ans.ways=1;
        }
        return ans;
    }
    if(dp[i][j]!=bingu) return dp[i][j];

    node ans;
    if(f[i]==s[j])
    {
        ans=call(i+1,j+1);

        ans.len++;
    }
    else
    {
        node temp=call(i,j+1);
        node temp2=call(i+1,j);

        // ans.len=1+min(temp.len,temp2.len);
        if(temp.len==temp2.len)
        {
            ans.len=1+temp.len;
            ans.ways=temp.ways+temp2.ways;
        }
        else if(temp.len<temp2.len)
        {
            ans.len=1+temp.len;
            ans.ways=temp.ways;
        }
        else
        {
            ans.len=1+temp2.len;
            ans.ways=temp2.ways;
        }
    }
    return dp[i][j]=ans;
}

int main()
{
    int cc=1, t;
    sf("%d", &t);
    int i, j;
    bingu.ways=bingu.len=-1;
    while(t--)
    {
        cin >> f;
        cin >> s;

        fs=f.size();
        ss=s.size();

        ffr(i,0,35)
        {
            ffr(j,0,35) dp[i][j]=bingu;
        }

        node ans=call(0,0);
        pf("Case %d: %lld %lld\n", cc++, ans.len, ans.ways);
    }
    return 0;
}

/*

3
USA
USSR
LAILI
MAJNU
SHAHJAHAN
MOMTAJ

Case 1: 5 3
Case 2: 9 40
Case 3: 13 15

*/
