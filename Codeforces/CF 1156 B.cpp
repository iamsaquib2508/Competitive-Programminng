#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mp(a,b) make_pair(a,b)
#define mmxx 1000000

using namespace std;

int cnt[26], arr[26];

int aaa(int cur)
{
    int i;
    ffr(i,0,26)
    {
        if(arr[i]==0) continue;
        if(abs(i-cur)!=1)
        {
            if(cnt[i]>0)
            {
                cnt[i]--;
                arr[i]--;
                return i;
            }
        }
    }
    return -1;
}


int main()
{
    int T, i, n ;
    cin >> T;
    while(T--)
    {
        mm(arr,0); mm(cnt,0);
        bool fail=0;
        string s;

        cin >> s;
        n=s.size();
        ffr(i,0,n)
        {
            arr[s[i]-'a']++;
        }
        cnt[0]=(n-1-cnt[1]);
        cnt[25]=(n-1-cnt[24]);
        ffr(i,1,25)
        {
            cnt[i]=(n-1-arr[i-1]-arr[i+1]);
        }
        int w=0;
        std::vector<int> ww, alll;
        ww.clear(); alll.clear();
        ffr(i,0,26)
        {
            if(arr[i]==0) continue;
            alll.pb(i);
            if(cnt[i]==0) fail=1;
            if(cnt[i]==1) {w++; ww.pb(i); cnt[i]=0;}
        }
        if(fail || (!fail && w>2))
        {
            cout << "No answer\n";
        }
        else
        {
            s="";
            int cur=-1, allind;
            if(w==0)
            {
                cur=alll[0];
                cnt[cur]--;
                arr[cur]--;
            }
            else
            {
                cur=ww[0];
            }
            while(cur!=-1)
            {
                s+=((char)('a'+cur));
                cur=aaa(cur);
            }
            if(w==2)
            {
                s+=((char)('a'+ww[1]));
            }
            cout << s << endl;
        }
    }
}
