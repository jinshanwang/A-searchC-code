#ifndef NODE_H
#define NODE_H
#include <iostream>


class node {
  private:

    int   x_axis;                       //horizontal location
    int   y_axis;                       //vertical location
    bool  isExplored;                   //whether it is explored or not;
    bool  isOccupied;                   //whether it is occupied or not;
    int   gcost;                        //this is the step cost
    int   cost;                         //refer to f(n) = g(n) + h(n)
    std::string path;                   //record the shortest path from the start to the current node
    int parentX;
    int parentY;

  public:
    node();
    void setX(int x);                                                       /*set the  x_axis*/
    void setY(int y);                                                       /*set the y_axis*/
    int getX();                                                             /*return the x_axis*/
    int getY();                                                             /*return the y_axis*/
    void setExplored(bool e);                                               /*modify the value of isExplored;*/
    void setOccupied(bool o);                                               /*modify the value of isOccupied;*/
    bool getExplored();                                                     /*get the boolean value of the visited state*/
    bool getOccupied();                                                     /*get the boolean value of the occupied state*/
    void setCost(int startX,int startY,int endX,int endY);
    int getCost();                                                          /*get the f(n) ---the cost*/
    void setParent(int x,int y);                                            /*store the location of the parent of its node*/
    int getParentX();                                                       /*retrieve the parent's node(Xpos)*/
    int getParentY();                                                       /* the parent's node(Ypos)*/
    void setGCost(int c);                                                   /*set the g(x) ---->which is the cumulative step cost*/
    int getGcost();                                                         /*return the g(x)*/
   void setPath(std::string action);                                        /*append the previous path to the current path*/
    std::string getPath();                                                  /*return the path */
    void nodeModification(int parent_x,int parent_y,int Cost,int step_cost);/*this is an improvement of the node*/
    void pathModification(std::string l);                                   /*this is the improvement of the path */

};
#endif
