#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

bool zero(string s)
{
    int i=0, sz=s.size();
    ffr(i,0,sz) if(s[i]!='0') return 0;
    return 1;
}

string string_string_add(string XX, string YY)
{
    if(zero(XX)) return YY;
    if(zero(YY)) return XX;

    int x=XX.size(), y=YY.size();
    if(x>y){string t=XX; XX=YY; YY=t; int tt=x; x=y; y=tt;}
    x--; y--;
    int car=0, cur;
    string ans="";
    for(;x>=0; x--, y--)
    {
        cur=XX[x]-'0'+YY[y]-'0'+car;
        if(cur>9)
        {
            ans+=(cur-10+'0');
            car=1;
        }
        else
        {
            ans+=(cur+'0');
            car=0;
        }
    }
    while(y>=0)
    {
        cur=YY[y]-'0'+car;
        if(cur>9)
        {
            ans+=(cur-10+'0');
            car=1;
        }
        else
        {
            ans+=(cur+'0');
            car=0;
        }

        y--;
    }
    if(car) ans+='1';
    reverse(ans.begin(), ans.end());

    return ans;
}

string string_num_multiply(string s, int x)
{
    string ans="";
    int i, sz=s.size(), cur, car=0;
    for(i=sz-1;i>=0;i--)
    {
        cur=(s[i]-'0')*x+car;
        car=cur/10;
        cur%=10;
        ans+=(cur+'0');
    }
    if(car>0) ans+=(car+'0');
    reverse(ans.begin(), ans.end());
    return ans;
}

string string_string_multiply(string XX, string YY)
{
    if(zero(XX) || zero(YY))
    {
        return "0";
    }
    string base=XX, ans="0";
    int i, sz=YY.size();
    for(i=sz-1;i>=0;i--)
    {
        string ret=string_num_multiply(base,YY[i]-'0');
        //cout << ret << endl;
        ans=string_string_add(ans,ret);
        base+='0';
    }
    //cout << endl;
    return ans;
}

string trim(string XX)
{
    int i=0, sz=XX.size();
    while(i<sz)
    {
        if(XX[i]>'0') break;
        i++;
    }
    string temp="";
    if(i==sz) temp="0";
    else
    {
        while(i<sz) temp+=XX[i++];
    }
    return temp;
}

int main()
{
    string XX, YY;
    while(cin >> XX >> YY)
    {
        XX=trim(XX); YY=trim(YY);
        cout << string_string_multiply(XX,YY) << endl;
        int k;
        //cin >> k;
        //cout << string_num_multiply(XX,k) << endl;
    }
}
