#ifndef FILEREADER_H
#define FILEREADER_H
#include "node.h"


class fileReader {
private:
  int width;				/*the width of the map*/
  int height;				/*the height of the map*/
  int **mapArray;			/*store the map info into the double pointer array*/
public:
  fileReader (char const * source);			/*read the file and process the stream*/
  int getWidth();							/*return the width */
  int getHeight();							/*return the length*/
  int** getMapArray();						/*return the mapArray*/
};
#endif
