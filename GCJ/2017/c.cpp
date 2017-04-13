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
typedef long long unsigned llu;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PI;
const ll mod = 1e9 + 7;

int main(void){
  unsigned T;
  cin >> T;
  REP(t, 1, T+1)
    {
      ll K, N;
      cin >> N >> K;
      priority_queue<pair<ll, ll> > n;
      n.push(pair<ll, ll>(N, 1));
      ll LS = -1, RS = -1;
      while (K > 0) 
	{
	  pair<ll, ll> pair_max_n = n.top();
	  n.pop();
	  ll max_n = pair_max_n.first;
	  ll num_max_n = pair_max_n.second;
	  K -= num_max_n;
	  if (max_n % 2 == 1)
	    {
	      LS = max_n / 2;
	      RS = max_n / 2;
	      n.push(pair<ll, ll>(LS, 2 * num_max_n));
	    }
	  else
	    {
	      LS = max_n / 2 - 1;
	      RS = max_n / 2;
	      n.push(pair<ll, ll>(LS, num_max_n));
	      n.push(pair<ll, ll>(RS, num_max_n));
	    }
	}
      cout << "Case #" << t << ": " << max(LS,RS) << " " << min(LS, RS) << endl;
    }
}
