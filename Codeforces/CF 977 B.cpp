#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)

using namespace std;

int main()
{
    int n, i, j, k, mx=0, cnt;
    string s, ans;
    cin >> n >> s;
    ffr(i,0,26)
    {
        ffr(j,0,26)
        {
            //t=('a'+i)+('a'+j);
            cnt=0;
            ffr(k,1,n)
            {
                if((s[k-1]==('A'+i)) && (s[k]==('A'+j)))
                {
                    cnt++;
                }
            }
            if(cnt>mx)
            {
                mx=cnt;
                ans="";
                ans+=('A'+i);
                ans+=('A'+j);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
