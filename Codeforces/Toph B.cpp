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
    int T;
    while(cin >> T)
    {
        int cc=1, n, p,  i, x;
        set<int> arr[1003];
        while(T--)
        {
            cin >> n >> p;
            ffrr(i,1,p) arr[i].clear();
            ffr(i,0,n)
            {
                cin >> x;
                arr[x].insert(i);
            }
            pf("Test Case: %d\n", cc);
            cc++;

            std::vector<double> v;
            v.clear();
            ffrr(i,1,p)
            {
                if(arr[i].size()==1) break;
                else if(arr[i].size()==0) continue;
                else
                {
                    set<int>::iterator it=arr[i].begin();
                    int prev=(*it), cur;
                    int ans=0, cnt=0, temp;
                    for(it++;it!=arr[i].end();it++)
                    {
                        cur=(*it);
                        temp=cur-prev;
                        if(temp>1)
                        {ans+=temp-1;
                        cnt++;}
                        prev=cur;
                    }
                    if(cnt>0) {v.pb(ans*1.0/cnt); v.pb(i);}
                    else break;
                }
            }
            if(i<=p) {cout << "No Pattern\n";continue;}
            int sz=v.size();
            ffr(i,0,sz)
            {
                pf("%d %.2lf\n", ((int)v[i+1]), v[i]); i++;
            }
        }
    }
    return 0;
}
