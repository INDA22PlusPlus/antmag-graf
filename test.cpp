
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long, long> pll;
typedef pair<string, string> pss;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<long> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

template<typename T>
void print_vec(vector<T>& A){
    for(T& a : A){
        cout << a << " ";
    }
    cout << "\n";
}

void test_case(){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({1,2});
    pq.push({1,3});
    pq.push({4,2});

    for(int i = 0; i < 3; i++){
        pll t = pq.top(); pq.pop();
        cout << t.first << endl;
    }

}

int main(){
    cin.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int t = 1;
    while(t--){
        test_case();
    }
}

