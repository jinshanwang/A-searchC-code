#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "Pathfinder.h"
#include "node.h"
#include "mapBuilder.h"
using namespace std;





pathFinder::pathFinder (vector<vector<node> > originalMap){
  map=originalMap;
  ExploredCounter=0;
}
void pathFinder::setStartX(int x){
  startX=x+1;
}
void pathFinder::setStartY(int y){
  startY=y+1;
}
void pathFinder::setEndX(int x){
  endX=x+1;
}
void pathFinder::setEndY(int y){
  endY=y+1;
}
void pathFinder::pathSearching(){
    // validate whether the start point and end point is occupied or not
    // if the start point or the end point is occupied we do not need to find the path
    if (map[startX][startY].getOccupied()==false && map[endX][endY].getOccupied()==false)
    {
    /*step 1: start from the start node, set the cost of the node is 0
                and then push the startpoint into the frontier queue*/
    node startPoint = map[startX][startY];
    startPoint.setGCost(0);
    frontier.push(startPoint);

    /*Step 2: 
      1.check that if the frontier is empty or not if it is and then we can stop search */
    while (frontier.empty()==false) {

      node currentNode = frontier.top();
      /*2.if the current node is the goal then assign the node to the target and break.*/
      if (currentNode.getX()==endX && currentNode.getY()==endY) {
          target=currentNode;
          break;
      }
      /*3.if it is node the target then we set the node to be explored and increase the 
          the ExploredCounter by 1.*/
        map[currentNode.getX()][currentNode.getY()].setExplored(true);
        ExploredCounter+=1;
      /*4.pop out the top node of the frontier*/
      frontier.pop();
      /*5.looking for the neighborhood on the left*/
      node neighbor_L=LeftOperation(currentNode);
      /*check whether it is occupied or not*/
      if (neighbor_L.getOccupied()==false) {
          if (map[neighbor_L.getX()][neighbor_L.getY()].getExplored()==false) {
            neighbor_L.setParent(currentNode.getX(),currentNode.getY());
            neighbor_L.setGCost(currentNode.getGcost()+1);
            neighbor_L.setCost(startX,startY,endX,endY);
            neighbor_L.setPath(currentNode.getPath()+"L ");
             /*check whether it can be found on the frontier or not
                we can push the node into the frontier there is no 
                this node before*/
            if (findNode(neighbor_L)==false) {
                frontier.push(neighbor_L);
            }
            /*if we can find the node we need to make some comparison 
              and inprovement to refresh the path*/
            else if (findNode(neighbor_L)==true ) {
                Pathimprovement(neighbor_L);
            }
          }


      }
      /*6.looking for the neighborhood on the right*/
      node neighbor_R=RightOperation(currentNode);
      /*check whether it is occupied or not*/
      if (neighbor_R.getOccupied()==false) {
        if (map[neighbor_R.getX()][neighbor_R.getY()].getExplored()==false) {

          neighbor_R.setParent(currentNode.getX(),currentNode.getY());
          neighbor_R.setGCost(currentNode.getGcost()+1);
          neighbor_R.setCost(startX,startY,endX,endY);
          neighbor_R.setPath(currentNode.getPath()+"R ");
          /*check whether it can be found on the frontier or not
                we can push the node into the frontier there is no 
                this node before*/
          if (findNode(neighbor_R)==false) {

            frontier.push(neighbor_R);
          }
          /*if we can find the node we need to make some comparison 
              and inprovement to refresh the path*/
          else if (findNode(neighbor_R)==true ) {

              Pathimprovement(neighbor_R);
            }
        }

      }
      /*7.looking for the neighborhood on the top*/
      node neighbor_UP=UpOperation(currentNode);
      /*check whether it is occupied or not*/
      if (neighbor_UP.getOccupied()==false) {
        if (map[neighbor_UP.getX()][neighbor_UP.getY()].getExplored()==false) {

          neighbor_UP.setParent(currentNode.getX(),currentNode.getY());
          neighbor_UP.setGCost(currentNode.getGcost()+1);
          neighbor_UP.setCost(startX,startY,endX,endY);
          neighbor_UP.setPath(currentNode.getPath()+"U ");
          /*check whether it can be found on the frontier or not
                we can push the node into the frontier there is no 
                this node before*/
          if (findNode(neighbor_UP)==false ) {

            frontier.push(neighbor_UP);
          }
          /*if we can find the node we need to make some comparison 
              and inprovement to refresh the path*/
          else if (findNode(neighbor_UP)==true ) {
          Pathimprovement(neighbor_UP);
          }
        }

      }
      /*8.looking for the neighborhood under the floor*/      
      node neighbor_D=DownOperation(currentNode);
      /*check whether it is occupied or not*/
      if (neighbor_D.getOccupied()==false) {
      if (map[neighbor_D.getX()][neighbor_D.getY()].getExplored()==false) {
        neighbor_D.setParent(currentNode.getX(),currentNode.getY());
        neighbor_D.setGCost(currentNode.getGcost()+1);
        neighbor_D.setCost(startX,startY,endX,endY);
        neighbor_D.setPath(currentNode.getPath()+"D ");
        /*check whether it can be found on the frontier or not
                we can push the node into the frontier there is no 
                this node before*/
        if (findNode(neighbor_D)==false) {

          frontier.push(neighbor_D);
        }
        /*if we can find the node we need to make some comparison 
              and inprovement to refresh the path*/
        else if (findNode(neighbor_D)==true ) {
          Pathimprovement(neighbor_D);
        }
      }

    }
  }
    }

}
node pathFinder::LeftOperation(node n){
      return map[n.getX()][n.getY()-1];
}
node pathFinder::RightOperation(node n){
      return map[n.getX()][n.getY()+1];
}
node pathFinder::UpOperation(node n){
      return map[n.getX()-1][n.getY()];
}
node pathFinder::DownOperation(node n){
      return map[n.getX()+1][n.getY()];
}

bool pathFinder::findNode(node n){
      std::priority_queue<node, std::vector<node>, node_cmp> frontierCopy = frontier;
      while(!frontierCopy.empty()){
        node current= frontierCopy.top();
        if (current.getX()==n.getX() && current.getY()==n.getY()) {
            return true;
        }
        frontierCopy.pop();
        }
        return false;
}
/*if there is duplicate node, we need to do some improvement
    according to the total cost*/
void pathFinder::Pathimprovement(node n){
    std::priority_queue<node, std::vector<node>, node_cmp> v;
    while (!frontier.empty()) {
      node current = frontier.top();
      if (current.getX()==n.getX() && current.getY()==n.getY()) {
        if (current.getCost()>n.getCost()) {
            current.nodeModification(n.getParentX(),n.getParentY(),n.getCost(),n.getGcost());
            current.pathModification(n.getPath());
        }
      }
      v.push(current);
      frontier.pop();
    }
    frontier=v;
  }



node pathFinder::getTarget(){
  return target;
}

int pathFinder::getExploredCounter(){
  return ExploredCounter;
}
