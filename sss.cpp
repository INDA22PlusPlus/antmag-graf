#include<bits/stdc++.h>
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;

typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pll> vii;
typedef vector<long> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
ll dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
ll diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

template<typename T>
void print_vec(vector<T>& A){
    for(T& a : A){
        cout << a << " ";
    }
    cout << "\n";
}

/*
6 8 3 0
0 2 3
0 4 2
0 5 100
1 4 1
1 5 5
2 3 10
2 4 1
4 5 3
3
1
5
0 0 0 0

*/

void test_case(){
    ll n, m, q, s; cin >> n >> m >> q >> s;
    vector<vector<ll>> R;

    while(!(n == 0 && m == 0 && q == 0 && s == 0)){
        vector<vector<pll>> adj_list(n, vector<pll>());
        for(ll i = 0; i < m; i++){
            ll x,y,w; cin >> x >> y >> w;
            adj_list[x].push_back({y,w});
        }
        
        vector<ll> queries(q);
        for(ll i = 0; i < q; i++){
            cin >> queries[i];
        }

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        vector<ll> dist(n, INFF);
        
        pq.push({0, s});
        dist[s] = 0;

        while(pq.size() > 0){
            pll t = pq.top(); pq.pop();
            //cout << "Considering dist: " << t.first << endl;

            for(ll i = 0; i < adj_list[t.second].size(); i++){
                ll new_dist = t.first + adj_list[t.second][i].second;
                ll node = adj_list[t.second][i].first;

                if(new_dist < dist[node]){
                    pq.push({new_dist, node});
                    dist[node] = new_dist;
                }
            }
        }
        R.push_back(vector<ll>(q));
        for(ll i = 0; i < q; i++){
            R[R.size()-1][i] = dist[queries[i]];
        }
        cin >> n >> m >> q >> s;
    }


    for(ll i = 0; i < R.size(); i++){
        for(ll j = 0; j < R[i].size(); j++){
            if(R[i][j] == INFF){
                cout << "Impossible" << "\n";
            }else{
                cout << R[i][j] << "\n";
            }
        }
        if(i != R.size() - 1) cout << "\n";
    }

}

int main(){
    cin.tie(nullptr); std::ios_base::sync_with_stdio(false);
    ll t = 1;
    while(t--){
        test_case();
    }
    return 0;
}
