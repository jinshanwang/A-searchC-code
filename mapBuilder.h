#ifndef MAPBUILDER_H
#define MAPBUILDER_H
#include "node.h"
#include <vector>
class mapBuilder {
private:

  int HEIGHT;
  int WIDTH;
  std::vector<std::vector<node> > v;

public:
  mapBuilder (int height, int width, int** mapArray);
  std::vector<std::vector<node> > getMapVector();
  void displayMap();
};


#endif
