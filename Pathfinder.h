#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include "node.h"
#include "mapBuilder.h"


struct node_cmp {
  bool operator()(  node a, node b)
  {
    return a.getCost() > b.getCost();

  }
};
class pathFinder {
private:
  std::vector<std::vector<node> > map;                            //the map
  int startX;                                                     //the Xpos of goal
  int startY;                                                     //the Ypos of goal
  int endX;                                                       //the Xpos of goal
  int endY;                                                       //the Ypos of goal
  node target;                                                    //the target node to store the path
  std::string Path;                                               //declare a path variable to store the action
  int ExploredCounter;                                            //explored counter
  std::priority_queue<node, std::vector<node>, node_cmp> frontier;//fringe
// these are prvate functions 
  node LeftOperation(node n);                                     //looking for the left neighborhood   
  node RightOperation(node n);                                    //looking for the right neighborhood
  node UpOperation(node n);                                       //looking for the  neighborhood on the top
  node DownOperation(node n);                                     //looking for the  neighborhood nuder the current node
  void Pathimprovement(node n);                                   //when there is another path which has the lower cost, we need to improve the path
  bool findNode(node n);                                          //find the node to see whether the node is in the frontier(fringe)
public:
  pathFinder (std::vector<std::vector<node> > originalMap);       //get the map from the mapBuilder 
  void setStartX(int x);                                          //get access the start point(X location)
  void setStartY(int y);                                          //get access the start point(Y location)
  void setEndX(int x);                                            //get access the end point(X location)
  void setEndY(int y);                                            //get access the end point(Y location)
  void pathSearching();                                           //search the node and assign the node to the target variable
  node getTarget();                                               //return the target node which store the optimal path 
  int getExploredCounter();                                       //return the number of node that has been explored
};


#endif
