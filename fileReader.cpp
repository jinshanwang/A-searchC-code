#include <iostream>
#include <fstream>
#include "node.h"
#include "fileReader.h"
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;
fileReader::fileReader(char const* source){
  string line;
  vector<std::string> v;
  ifstream txt_file(source);

  if (txt_file.is_open()) {
   /*step 1: get the size of the map*/
    getline(txt_file,line);
  std::stringstream aa(line);
  std::string token;
  int int_s;
  int i=0;
  while (getline(aa, token, ' ')) {

        int_s = stoi(token);
        if (i==0)
        {
          width=int_s;

        }
        else{
          height=int_s;
        }
        i++;
     }
   /*step 2: initialize the mapArray space to store the value in the file
              and then assign the value from the file to the mapArray*/
    mapArray=new int*[height];
    for (int i = 0; i < height; i++) {
      mapArray[i]=new int[width];
    }

    int count = 0;
    while (getline(txt_file,line)) {

     int icounter=0;
     std::stringstream ss(line);
     std::string token;
     int int_s;
     while (getline(ss, token, ' ')) {

        int_s = stoi(token);
        mapArray[count][icounter]=int_s;
        icounter++;
     }
           count++;
    }

  }

}
int fileReader::getWidth(){
    return width;
}
int fileReader::getHeight(){
    return height;
}
int** fileReader::getMapArray(){
    return mapArray;
}
