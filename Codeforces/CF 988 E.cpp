



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
#define inf 1000000

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */
string s, ss;
int sz;

int for75()
{
    ss=s;
    int cnt=0, i, j;
    for(i=sz-1;i>0;i--)
    {
        if(ss[i]=='5')
        {

            ffr(j,i+1,sz)
            {
                ss[j-1]=ss[j];
                cnt++;
            }
            ss[j-1]='5';
            break;
        }
    }
    if(i==0) return inf;
    for(i=sz-2;i>=0;i--)
    {
        if(ss[i]=='7')
        {
            if(i>0)
            {
                cnt+=(sz-2-i);
                return cnt;
            }
            if(i==0)
            {
                ffr(j,i+1,sz-1)
                {
                    if(ss[j]>'0')
                    {
                        cnt+=(j-i-1);
                        cnt+=(sz-2-i);
                        return cnt;
                    }
                }
                if(j==sz-1) return inf;
            }
        }
    }
    return inf;
}

int for25()
{
    int i, j, cnt=0;
    ss=s;
    for(i=sz-1;i>0;i--)
    {
        if(ss[i]=='5')
        {

            ffr(j,i+1,sz)
            {
                ss[j-1]=ss[j];
                cnt++;
            }
            ss[j-1]='5';
            break;
        }
    }
    if(i==0) return inf;
    for(i=sz-2;i>=0;i--)
    {
        if(ss[i]=='2')
        {
            if(i>0)

            {
                cnt+=(sz-2-i);
                return cnt;
            }
            if(i==0)
            {
                ffr(j,i+1,sz-1)
                {
                    if(ss[j]>'0')
                    {
                        cnt+=(j-i-1);
                        cnt+=(sz-2-i);
                        return cnt;
                    }
                }
                if(j==sz-1) return inf;
            }
        }
    }
    return inf;
}

int for00()
{
    int i, j, cnt=0;
    ss=s;
    for(i=sz-1;i>0;i--)
    {
        if(ss[i]=='0')
        {
            cnt+=(sz-1-i);
            break;
        }
    }
    if(i==0) return inf;
    for(i=i-1;i>0;i--)
    {
        if(ss[i]=='0')
        {
            cnt+=(sz-2-i);
            return cnt;
            break;
        }
    }
    return inf;
}

int for50()
{
    int i, j, cnt=0;
    ss=s;
    for(i=sz-1;i>0;i--)
    {
        if(ss[i]=='0')
        {

            ffr(j,i+1,sz)
            {
                ss[j-1]=ss[j];
            }
            ss[j-1]='0';
            cnt+=(sz-1-i);
            break;
        }
    }
    if(i==0) return inf;
    for(i=sz-2;i>=0;i--)
    {
        if(ss[i]=='5')
        {
            if(i>0)

            {
                cnt+=(sz-2-i);
                return cnt;
            }
            if(i==0)
            {
                ffr(j,i+1,sz-1)
                {
                    if(ss[j]>'0')
                    {
                        cnt+=(j-i-1);
                        cnt+=(sz-2-i);
                        return cnt;
                    }
                }
                if(j==sz-1) return inf;
            }
        }
    }
    return inf;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    cin >> s;
    sz=s.size();
    int ans;
    if(sz<3)
    {
        if(s=="25" || s=="50" || s=="75" || s=="0")
        {
            cout << "0\n";
        }
        else if(s=="52" || s=="57")
        {
            cout << "1\n";
        }
        else cout << "-1\n";
    }
    else
    {
        ans=min(for75(),for25());
        ans=min(ans,for00());
        ans=min(ans,for50());
        if(ans<inf)
        cout << ans << endl;
        else cout << "-1\n";
    }




    return main();
}
