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

class node
{
public:
    int index;
    int rel;
    node(){}
    node(int id, int rell)
    {
        index=id; rel=rell;
    }
};

class node2
{
public:
    int index;
    int carr;
    node2(){}
    node2(int id, int c)
    {
        index=id; carr=c;
    }
};

stack<node> car[26];
int neg[26], neg2[26];
vector<node2> rels[3];

int main()
{
    int n, q, i, x;
    string s;
    while(cin >> n >> q)
    {
        ffr(i,0,26)
        {
            while(!car[i].empty()) car[i].pop();

            neg[i]=0;
            neg2[i]=0;
        }
        ffr(i,0,3) rels[i].clear();
        cin >> s;
        int c;
        ffr(i,0,n)
        {
            c=s[i]-'a';
            car[c].push(node(i,-1));
        }

        queue<node> temp;
        ffr(i,0,26)
        {
            while(!car[i].empty()) {
                temp.push(car[i].top());
                car[i].pop();
            }
            while(!temp.empty()) {
                car[i].push(temp.front());
                temp.pop();
            }
        }
        char cur; int rel, id;
        while(q--)
        {
            cin >> cur;
            if(cur=='+')
            {
                cin >> rel >> cur;
                rel--;
                c=cur-'a';
                if(car[c].empty())
                {
                    cout << "NO\n";
                    neg[c]++;
                    rels[rel].pb(node2(-1,c));
                }
                else
                {
                    int xxx=car[c].top().index;
                    if( rels[rel].size()==0 || xxx>rels[rel][rels[rel].size()-1].index)
                    {
                        cout << "YES\n";
                    }
                    else
                    {
                        cout << "NO\n";
                        neg2[rel]++;
                    }
                    rels[rel].pb(node2(xxx,c));
                    car[c].pop();
                    //cout << "YES\n";
                }
            }
            else
            {
                cin >> rel;
                rel--;
                node2 now=rels[rel][rels[rel].size()-1];
                rels[rel].pop_back();
                if(neg2[rel]>0) neg2[rel]--;
                i=now.carr;
                id=now.index;

                if(neg[i]>0)
                {
                    neg[i]--;
                    if(neg[i]>0) cout << "NO\n";
                    else
                    {
                        int j;
                        ffr(j,0,3) if(neg2[j]>0) break;
                        if(j==3) cout << "YES\n";
                        else cout << "NO\n";
                    }
                }
                else{

                    stack<node> temp;
                    while(!car[i].empty() && car[i].top().index<id) {
                        temp.push(car[i].top());
                        car[i].pop();
                    }
                    car[i].push(node(id,rel));
                    while(!temp.empty()) {
                        car[i].push(temp.top());
                        temp.pop();
                    }
                    int j;
                    ffr(j,0,3) if(neg2[j]>0) break;
                    if(j==3) cout << "YES\n";
                    else cout << "NO\n";
                }
            }
        }
    }
}
