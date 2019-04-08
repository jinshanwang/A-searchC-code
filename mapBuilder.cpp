#include "mapBuilder.h"
#include "node.h"
#include <iostream>
#include <queue>
using namespace std;



mapBuilder::mapBuilder(int height, int width, int** mapArray){
  //initialize the map size
  /*assuming there is a virtual bound around the map,
    so I would like to expand the wodth by two */
  HEIGHT=height+2;
  WIDTH=width+2;
  v.resize(HEIGHT);
  for (size_t i = 0; i < HEIGHT; i++) {
    v[i].resize(WIDTH);
  }
  for (size_t i = 0; i < HEIGHT; i++) {
    for (size_t j = 0; j < WIDTH; j++) {
      v[i][j].setX(i);
      v[i][j].setY(j);
    }
  }
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      if (mapArray[i][j]==0) {
        v[i+1][j+1].setOccupied(false);
      }
    }
  }
}
/*return the map as a vector*/
vector<vector<node> > mapBuilder::getMapVector(){
  return v;
}
/*this function is the simulation to check whether the mapBiulder works or not */
void mapBuilder::displayMap() {
    for (size_t i = 0; i < HEIGHT; i++) {
      for (size_t j = 0; j < WIDTH; j++) {
        if (v[i][j].getOccupied()==true) {
          std::cout << "[#] ";
        }else{
          std::cout << "[ ] ";
        }
      }
      std::cout << '\n';
    }
}
