#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        int sz=s.size();
        vector<int> v;
        v.clear();
        int i, j;
        ffr(i,1,sz)
        {
            if(sz%i==0) v.push_back(i);
        }
        v.push_back(sz);
        int arrr[26];
        mm(arrr,0);
        ffr(i,0,sz)
        {
            char cur=s[i];
            arrr[cur-'A']++;
        }

        int vsz=v.size();
        //ffr(i,0,vsz) cout << arrr[i] << ' ';
        //cout << endl;
        int mn=10000000, k;
        ffr(k,0,vsz)
        {
            int arr[26];
            ffr(i,0,26) arr[i]=arrr[i];
            int ans=0;
            int cur=v[k];
            ffr(i,0,26)
            {
                if(arr[i]==0) continue;
                if(arr[i]==cur) continue;
                if(arr[i]<cur)
                {
                    ffr(j,0,26)
                    {
                        if(i==j) continue;
                        if(arr[j]==0) continue;
                        if(arr[j]!=cur)
                        {
                            arr[i]++;
                            arr[j]--;
                            ans++;

                            break;
                        }
                    }
                    if(j==26)
                    {
                        //boro painai
                        ans=10000000;
                        break;
                    }
                    else
                    {
                        i--;
                    }
                }

                //ffr(j,0,26) cout << arr[j] << ' ';
                //cout << endl;
            }
            ffr(i,0,26)
            {
                //cout << arr[i] << " ";
                if(arr[i]>0 && arr[i]!=cur)
                {
                    ans=10000000; //break;
                }
            }
            //cout << cur << " curwas\n";
            mn=min(ans,mn);
        }
        //cout << "Final: ";
        cout << mn << endl;
    }
}
