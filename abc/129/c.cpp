//=template==================================================================//
// include
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

// namespace
using namespace std;

// define
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(i,n) FOR(i,0,n)
#define MIN_V(v) *min_element(v.begin(), v.end())
#define MAX_V(v) *max_element(v.begin(), v.end())

// typedef
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef long long LL;
typedef unsigned long long ULL;

// conversion
inline int toInt(string s) {int v; istringstream sin(s); sin>>v; return v;}
inline int countChar(string s, char c) {int cnt,i; cnt=0; REP (i,s.size()) {if (s[i]==c) cnt++;} return cnt;}
template<class T> inline string toString(T x) {ostringstream sout; sout<<x; return sout.str();}
//===========================================================================//

//=function prototype========================================================//

//===========================================================================//

//=variables=================================================================//

//===========================================================================//
int main(void)
{
  // Scan begin.
  int n, m;
  cin >> n >> m;
  VI broken(n+1);
  REP(i,m) {
    int idx;
    cin >> idx;
    broken[idx] = 1;
  }
  // Scan done.

  // Code begin.
  const LL mod = 1000000007;
  vector<LL> dp(n + 2);
  dp[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (broken[i]) {
      dp[i] = 0;
      continue;
    }
    dp[i] = (dp[i + 1] + dp[i + 2]) % mod;
  }
  cout << dp[0] << endl;
  // Code done.

  return 0;
}

//=functions=================================================================//

//===========================================================================//