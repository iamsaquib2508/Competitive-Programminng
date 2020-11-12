#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mkm make_pair
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

class node{
public:
    int scnt, dcnt;
    ll sum;
    node(int sc, int dc, ll s){
        scnt=sc; dcnt=dc; sum=s;
    }
    node(){scnt=0; dcnt=0; sum=0;}
    void print(){
        printf("scnt %d dcnt %d sum %lld\n", scnt, dcnt, sum);
    }
};

node* tree;

void update(int pos, int lo, int hi, int cnt, int idx, int val, bool dtype){
    if(idx<lo || hi<idx) return;
    if(lo==hi){
        if(dtype)
            tree[pos].dcnt += cnt;
        else
            tree[pos].scnt += cnt;
        tree[pos].sum += cnt*val;
        return;
    }
    int mid = (lo+hi)/2;
    int pos2=pos<<1;
    update(pos2, lo,mid, cnt,idx,val,dtype);
    update(pos2+1, mid+1,hi, cnt,idx,val,dtype);
    tree[pos].scnt=tree[pos2].scnt+tree[pos2+1].scnt;
    tree[pos].dcnt=tree[pos2].dcnt+tree[pos2+1].dcnt;
    tree[pos].sum=tree[pos2].sum+tree[pos2+1].sum;
    return;
}

//return sum ans cound of lightning
pair<ll,int> query(int pos, int lo, int hi, int lastcnt){
    if(lo==hi){
        if(lastcnt==1) {
            return make_pair(tree[pos].sum,(tree[pos].dcnt==1));
        }
        else return make_pair(0,0);
    }
    int mid = (lo+hi)/2;
    int pos2=pos<<1;
    if(tree[pos2+1].scnt+tree[pos2+1].dcnt>lastcnt) return query(pos2+1, mid+1,hi, lastcnt);

    pair<ll,int> p = query(pos2, lo,mid, lastcnt-(tree[pos2+1].scnt+tree[pos2+1].dcnt));
    return make_pair(p.first+tree[pos2+1].sum, p.second+tree[pos2+1].dcnt);
}


int main(){
    int tt=1;
    //cin >> tt;
    int n;
    while(cin >> n){

        int i, idx=0, cursize=0;
        bool tp[200005]; int d[200005];
        map<int, int> mp;
        ffr(i,0,n){
            cin >> tp[i] >> d[i];
            mp[abs(d[i])]=1;
        }
        idx=0;
        for(auto aa: mp){
            mp[aa.first]=(++idx);
        }
        tree = new node[4*idx];
        ffr(i,0,n){
            if(d[i]>0){
                update(1, 1, idx, +1, mp[d[i]], d[i], tp[i]);
                cursize++;
            }
            else{
                update(1, 1, idx, -1, mp[-d[i]], -d[i], tp[i]);
                cursize--;
            }

            pair<ll,int>  allsum = query(1, 1, idx, cursize);
            //cout << ans << endl;
            int dcur = allsum.second;
            ll ans = allsum.first;
            if(dcur>0){
                pair<ll,int> temp = query(1, 1, idx, dcur);
                if(dcur==temp.second){
                    if(dcur==cursize){
                        //all d.
                        //d ddddddddddd
                        //case 2
                        ans += query(1, 1, idx, dcur-1).first;
                    }
                    else{
                        //s d ddddddddddd
                        //case 3
                        ans += (query(1, 1, idx, dcur+1).first - temp.first + query(1, 1, idx, dcur-1).first);
                    }
                }
                else ans += temp.first; //case 1
            }
            cout << ans << endl;
        }
    }
}

/*
ok. cosider a simple case. say fire spells are called s type and lightning spells are called d type (quality of making the next
spell single and double)
for any instance, you can double atmost (num of d) numbers UNLESS all of the spells are of d type
because clearly, you cannot double the first one.
Let, d_cnt =(# of d type in an instance).
Also, you wanna double the largest ones, whether they are of d type or not.
That is always possible actually, iff atleast 1 of the d type is not in the largest d_cnt numbers.
Consider sssdsddddd (sorted). Cast them as sssdddddds. Actually, whichever d type is not in the largest d_cnt can contribute to
double the s type that replaced it (save 1 for doubling the first d that IS in the largest d_cnt).

So, 3 cases.
ssds...dddd = can double the d_cnt of the largests.
ddddddd = can't double the 1st d i.e. can double the d_cnt-1 of the largest.
sssssddddd = can't double the 1st d BUT can double the last s, unlike the last case where we have no s to double.

So, let's provide unique (sorted) id to the numbers (co-ordinate compression) using a map.
Now, keep a segment tree for continuous answer. query is formatted for the sum of "last x terms" style.
so that we can call it on
1) currentarraysize, for sum of the entire array. and,
2) d_cnt or d_cnt-1 or d_cnt+1 (for the numbers that can be doubled).
let's also format the query to also provide the number of d it faced to find the sum in the range asked.
it will help to determine which case we are actually in, to allow us to call the second query appropriately.

Nodes will have scnt (# of s type), dcnt(# of d type) and sum of the numbers in that range that it's supposed to represent.
updates and queries are pretty obvious if someone is familiar with segment tree.
*/
