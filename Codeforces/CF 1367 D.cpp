#include <bits/stdc++.h>
#define ull uint64_t
#define uint uint32_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair

using namespace std;

int main()
{
    int tt; cin >> tt;
    while(tt--){
        int i, j, sum, cntz, curchar, count[26]={}, n, left, right, diff, id, k;
        string s;
        cin >> s;
        //sort(t.begin(),t.end());
        int a[60]={}, ans[60]={};
        for(char aa:s){
            count[aa-'a']++;
        }
        sum=0;
        cntz=0;
        cin >> n;
        ffr(i,0,n){
            cin >> a[i];
            if(a[i]==0){
                sum+=i;
                cntz++;
            }
        }
        curchar=25;
        //ffr(k,0,n) cout << a[k] << ' '; cout << endl;

        while(curchar>=0){
            while(count[curchar]<cntz) curchar--;
            left=0;
            right=cntz;
            diff=sum;
            id=0; cntz=0; sum=0;

            while(id<n){
                if(a[id]==-1) {id++; diff += (left-right); continue;}
                if(a[id]==0){
                    //diff += (left-right);
                    left++; right--;
                    diff += (left-right);
                    ans[id]='a'+curchar;
                    a[id]=-1;

                }
                else{
                    a[id] -= diff;
                    if(a[id]==0) {cntz++;
                    sum += id;}

                    diff += (left-right);
                }
                id++;
                //cout << diff << endl;

            }
            //ffr(k,0,n) cout << a[k] << ' '; cout << endl;
            curchar--;

        }
        ffr(i,0,n){
            cout << (char)ans[i];
        }
        cout << endl;
    }
}
