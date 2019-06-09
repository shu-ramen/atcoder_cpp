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
  int n;
  cin >> n;
  VI w(n);
  REP(i,n) {
    cin >> w[i];
  }
  // Scan done.

  // Code begin.
  int ans = 99999;
  REP(i, n) {
    int sum1 = 0;
    int sum2 = 0;
    FOR(j,0,i) {
      sum1 += w[j];
    }
    FOR(j,i,n) {
      sum2 += w[j];
    }
    if (abs(sum2 - sum1) < ans) {
      ans = abs(sum2 - sum1);
    }
  }
  cout << ans << endl;
  // Code done.

  return 0;
}

//=functions=================================================================//

//===========================================================================//