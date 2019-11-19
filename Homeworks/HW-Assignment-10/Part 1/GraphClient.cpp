#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
  Graph joelTgraph;
  for (int i = 0; i < 5; i++) {
    joelTgraph.add_vertex();
  }
  joelTgraph.add_edge(0,4);
  joelTgraph.add_edge(0,2);
  joelTgraph.add_edge(4,2);
  joelTgraph.add_edge(4,1);
  joelTgraph.add_edge(2,3);

  cout << joelTgraph << endl;
}