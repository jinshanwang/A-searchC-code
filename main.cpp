#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include "node.h"
#include "fileReader.h"
#include "mapBuilder.h"
#include "Pathfinder.h"
#include <vector>

using namespace std;
int main(int argc, char const *argv[]) {

/*  Step 1:  read and parse the txt file
             in this step, we are supposed to
             get the size of the map and the
             detail of each one of the grid*/
  fileReader FR(argv[1]);
  int ** Map= FR.getMapArray();
  int height=FR.getHeight();
  int width= FR.getWidth();
  /*Step 2:  build the map using the Map array above*/
  mapBuilder MB(height,width,Map);
  std::vector<std::vector<node> > v= MB.getMapVector();
  /*Step 3:  find the optimal path in the grid map above
             firstly, we need to initialize the pathfinder 
             by creating an object of pathFinder class. 
             and then we need to set a start point and 
             the goal point. finally we starting searching 
             using the A* search algorithm and store the 
             path in a goal node(which means that the path
             is stored in the node.path)*/
  pathFinder PF(v);
  /*set the Xpos of the start point*/
  string startYpos= argv[2];
  PF.setStartY(stoi(startYpos));
  /*set he Ypos of the start point*/
  string startXpos= argv[3];
  PF.setStartX(stoi(startXpos));
  /*set the Xpos of the end point*/
  string endYpos= argv[4];
  PF.setEndY(stoi(endYpos));
  /*set the Xpos of the end point*/
  string endXpos= argv[5];
  PF.setEndX(stoi(endXpos));
  /*START SEARCHING HERE*/
  PF.pathSearching();
  /*GET THE PATH HERE*/
  node result = PF.getTarget();
  string path = result.getPath();
  /*Step 4:   output the result including the number of node that has been 
              explored and the length of path as well as the path which 
              is represented by sequence of the actions we need to get to the goal */
  std::cout << PF.getExploredCounter()<<" "<<path.length()/2<< '\n';
  if (path.length()==0)
  {
      cout<<"X"<<'\n';
  }
  else
  {
      std::cout << path << '\n';
  }

  return 0;
}
