/*#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include "buildMap.h"
#include "donut.h"

using namespace std;

Donut::Donut()
{
}

Donut::~Donut()
{
  for (int i=0; i < BuildMap::getCurrentMapR(); ++i){
    delete[] nextMap[i];
  }
  delete[] nextMap;
  cout << "Donut Destroyed" << endl;
}

void Donut::donutNeighbors(const int nextR, const int nextC, char** currentMap)
{
  nextMap = new char*[nextR];
  for (int i=0; i < nextR; ++i)
  {
    nextMap[i] = new char[nextC];
  }

  for (int i=0; i < nextR; ++i){
    for (int j=0; j < nextC; ++j){
      countLive = 0;
      if (i == 0 && j == 0){             //top left corner  can't evaluate any i-1 or j-1
        if (currentMap[i][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j] == 'X'){
          countLive++;
        }
        if (currentMap[i+(nextR-1)][j] == 'X'){
          countLive++;
        }
        if (currentMap[i+(nextR-1)][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i][j+(nextC-1)] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j+(nextC-1)] == 'X'){
          countLive++;
        }
        if (currentMap[i+(nextR-1)][j+(nextC-1)] == 'X'){
          countLive++;
        }

      else if (i == nextR-1 && j == 0){  //bottom left corner  can't evaluate any i+1
      {
        if (currentMap[i-1][j] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i-(nextR-1)][j] == 'X'){
          countLive++;
        }
        if (currentMap[i-(nextR-1)][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i-(nextR-1)][j+(nextC-1)] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j+(nextC-1)] == 'X'){
          countLive++;
        }

      }
      else if (j == nextC-1 && i == 0){}  //top right corner
      else if (i == nextR-1 && j == nextC-1){}  //bottom right corner
      else if (i == nextR-1){}          //bottom row
      else if (j == 0){}                 //left column
      else if (i == 0){}                 //top row
      else if (j == nextC-1){}           //right column
      else{}                            //all spaces inbetween
}
*/
