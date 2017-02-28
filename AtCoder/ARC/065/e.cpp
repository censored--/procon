#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PI;
const ll mod = 1e9 + 7;

ll d(ll x_i, ll y_i, ll x_j, ll y_j)
{
  return abs(x_i-x_j)+abs(y_i-y_j);
}


int main(void){
  ll N, a, b;
  cin >> N >> a >> b;
  VI cord(N+1, VI(N+1, 0));
  VI x(N+1,0), y(N+1,0);
  REP(i,1,N+1)
    cin >> x[i] >> y[i];
  
}
