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
  string S;
  cin >> S;
  while (true)
    {
      int len = S.size();
      if (len == 0)
	break;
      //cout << S << endl;
      if (len >= 5 && (S.substr(len-5) == "dream"||S.substr(len-5) == "erase"))
	S = S.substr(0,len-5);
      else if (len >=6 &&S.substr(len-6)=="eraser")
	S = S.substr(0,len-6);
      else if (len>=7 &&S.substr(len-7)=="dreamer")
	S = S.substr(0,len-7);
      else 
	{
	  cout << "NO" << endl;
	  return 0;
	}
      //cout << S << endl;
    }
  cout << "YES" << endl;
  return 0;
}
