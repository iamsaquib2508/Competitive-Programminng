




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

string s;
ll bk[100005], dk[100005], z;


void ff()
{
    stack<int> st;
    ll sz=s.size(), i, dan, bam;
    while(!st.empty()) st.pop();
    ffr(i,0,sz)
    {
        if(s[i]==')')
        {

            if(st.empty() || st.top()==')')
            {
                st.push(')');
            }
            else
            {
                st.pop();
            }
        }
        else if(s[i]=='(')
        {

            //if(st.empty() || st.top()=='(')
            {
                st.push('(');
            }
            //else
            {
                //st.pop();
            }
        }
    }
    dan=0;
    while(!st.empty())
    {
        if(st.top()==')') break;
        dan++;
        st.pop();
    }
    bam=0;
    while(!st.empty())
    {
        //if(st.top()==')') break;
        bam++;
        st.pop();
    }
    if(dan==0 && bam==0)
    {
        z++;
    }
    else if(dan>0 && bam>0) return;
    else if(dan==0) bk[bam]++;
    else dk[dan]++;

    return;
}


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    ll ans, n, i;
    mm(dk,0); mm(bk,0); z=0;

    cin >> n;
    ffr(i,0,n)
    {
        cin >> s;
        ff();
    }
    ans=z*z;
    ffr(i,1,100005)
    {
        ans+=(dk[i]*bk[i]);
    }
    cout << ans << endl;




    return 0;
}
