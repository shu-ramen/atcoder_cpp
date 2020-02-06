//=template===================================================================//
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
typedef struct {
  LL cost;
  bool done;
} node_t;

// conversion
inline int
toInt(string s)
{
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline int countChar(string s, char c) {int cnt,i; cnt=0; REP (i,s.size()) {if (s[i]==c) cnt++;} return cnt;}
template<class T> inline string toString(T x) {ostringstream sout; sout<<x; return sout.str();}
//============================================================================//

//=function prototype=========================================================//
void dijkstra(vector<node_t>& nodes, const VVL map, const int start_idx, bool reverse);
//============================================================================//

//=variables==================================================================//

//============================================================================//
int main(void)
{
  // Scan begin.
  
  // Scan done.

  // Code begin.

  // Code done.

  return 0;
}

//=functions==================================================================//

//============================================================================//

//=Useful Function============================================================//
void dijkstra(vector<node_t>& nodes, const VVL map, const int start_idx, bool reverse) {
  nodes[start_idx].cost = 0;
  while (true)
  {
    int node_idx = -1;
    REP(i, nodes.size()) {
      // If the i_th node is already loaded or not yet loaded
      if (nodes[i].done || nodes[i].cost < 0) {
        continue;
      }
      // If no nodes selected
      if (node_idx == -1) {
        node_idx = i;
        continue;
      }
      // If i_th node is nearer than selected node
      if (nodes[i].cost < nodes[node_idx].cost) {
        node_idx = i;
      }
    }
    // If all paths done, then break
    if (node_idx == -1) {
      break;
    }
    // Set selected node as already loaded
    nodes[node_idx].done = true;
    // Path to all nodes
    REP(i, nodes.size()) {
      if (!reverse) {
        // Normal
        // If exists route.
        if (map[node_idx][i] >= 0) {
          // If this route is not yet opened
          if (nodes[i].cost < 0) {
            // Set cost
            nodes[i].cost = nodes[node_idx].cost + map[node_idx][i];
          }
          else {
            // If this route is nearer than now, update cost
            if (nodes[i].cost > (nodes[node_idx].cost + map[node_idx][i])) {
              nodes[i].cost = nodes[node_idx].cost + map[node_idx][i];
            }
          }
        }
      }
      else {
        // Reverse
        // If exists route.
        if (map[i][node_idx] >= 0) {
          // If this route is not yet opened
          if (nodes[i].cost < 0) {
            // Set cost
            nodes[i].cost = nodes[node_idx].cost + map[i][node_idx];
          }
          else {
            // If this route is nearer than now, update cost
            if (nodes[i].cost > (nodes[node_idx].cost + map[i][node_idx])) {
              nodes[i].cost = nodes[node_idx].cost + map[i][node_idx];
            }
          }
        }
      }
    }
  }
}
//============================================================================//