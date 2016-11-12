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

int main(void){
  int H,W;
  cin >> H >> W;
  int x = -1,y = 0;
  REP(i,0,H)
    {
      REP(j,0,W)
	{
	  char a;
	  cin >>a;
	  if (a == '#' && x == j-1 && y == i)
	    {
	      x++;
	    }
	  else if (a == '#' && y == i-1 && x == j)
	    {
	      y++;
	    }
	  else if (a == '.')
	    {
	      continue;
	    }
	  else 
	    {
	      cout << "Impossible"<<endl;
	      return 0;
	    }
	}
    }
  cout << "Possible" << endl;
}
