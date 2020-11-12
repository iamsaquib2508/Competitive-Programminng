#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

string s, stemp;

int ff(){
    int ti=0, ret=0;
    for(char c:s){
        if(c==stemp[ti]){
            ti ^= 1;
            ret++;
        }
    }
    return ret/2*2;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        cin >> s;
        int cnt[10]={0,0,0,0,0,0,0,0,0,0}, i, j, temp, ans;

        for(char c:s){
            cnt[c-'0']++;
        }
        ans=0;
        ffr(i,0,10){
            if(cnt[i]>ans) ans=cnt[i];
        }

        ffr(i,0,10){
            ffr(j,0,10)
            {
                if(i!=j)
                {
                    stemp=('0'+i);
                    stemp += ('0'+j);
                    //cout << stemp << endl;
                    temp = ff();
                    if(temp > ans){
                        ans=temp;
                    }
                }
            }
        }
        cout << s.size()-ans << endl;
    }
    cin >> tt;
}
