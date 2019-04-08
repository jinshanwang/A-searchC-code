#include "node.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;


node::node(){
  isExplored=false;
  isOccupied=true;
  cost=0;
}
void node::setX(int x)           //set the  x_axis
{
  x_axis=x;
}
void node::setY(int y)           //set the y_axis
{
  y_axis=y;
}
int node::getX()                 //return the x_axis
{
  return x_axis;
}
int node::getY()                 //return the y_axis
{
  return y_axis;
}
void node::setExplored(bool e)   //modify the value of isExplored;
{
  isExplored=e;
}
void node::setOccupied(bool o)   //modify the value of isOccupied;
{
  isOccupied=o;
}
bool node::getExplored()         //get the boolean value of the visited state
{
  return isExplored;
}
bool node::getOccupied()        //get the boolean value of the occupied state
{
  return isOccupied;
}
void node::setCost(int startX,int startY,int endX,int endY) {
  int G_cost=getGcost();
  int H_cost=abs(endX-x_axis)+abs(endY-y_axis);
  cost = G_cost+H_cost;
}
int node::getCost()              //get the f(n) ---the cost
{
  return cost;
}

void node::setPath(string action){
  path.append(action);
}
std::string node::getPath(){
  return path;
}
void node::setGCost(int c){
  gcost=c;
}
int node::getGcost(){
  return gcost;
}
void node::setParent(int x,int y){
  parentX=x;
  parentY=y;
}
int node::getParentX(){
  return parentX;
}
int node::getParentY(){
  return parentY;
}


void node::nodeModification(int parent_x,int parent_y,int Cost,int step_cost){
  parentX=parent_x;
  parentY=parent_y;
  cost = Cost;
  gcost= step_cost;
}
void node::pathModification(string l) {
  path=l;
}
