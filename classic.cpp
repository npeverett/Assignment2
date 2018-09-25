#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include "classic.h"
#include "buildMap.h"

using namespace std;

Classic::Classic()
{
}

Classic::~Classic()
{
  for(int i=0; i < BuildMap::getCurrentMapR(); ++i)
  {
    delete[] nextMap[i];
  }
  delete[] nextMap;
  cout << "Classic Destructor Invoked" << endl;
}

string Classic::hasNeighbor(const int nextR, const int nextC, char** currentMap)
{
  int gen = 0;
  stringstream strStream;

  nextMap = new char*[nextR];
  for (int i=0; i < nextR; ++i)
  {
    nextMap[i] = new char[nextC];
  }

  for (int i=0; i < nextR; ++i){
    for (int j=0; j < nextC; ++j){
      countLive = 0;
      if (i == 0 && j == 0){             //top left corner
        if (currentMap[i][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j+1] == 'X'){
          countLive++;
        }
      }
      else if (i == nextR-1 && j == 0){  //bottom left corner
        if (currentMap[i][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j] == 'X'){
          countLive++;
        }
      }
      else if (j == nextC-1 && i == 0){  //top right corner
        if (currentMap[i][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j-1] == 'X'){
          countLive++;
        }
      }
      else if (i == nextR-1 && j == nextC-1){  //bottom right corner
        if (currentMap[i-1][j] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i][j-1] == 'X'){
          countLive++;
        }
      }
      else if (i == nextR-1){          //bottom row
        if (currentMap[i][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i][j+1] == 'X'){
          countLive++;
        }
      }
      else if (j == 0){                 //left column
        if (currentMap[i-1][j] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j] == 'X'){
          countLive++;
        }
      }
      else if (i == 0){                 //top row
        if (currentMap[i][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i][j+1] == 'X'){
          countLive++;
        }
      }
      else if (j == nextC-1){           //right column
        if (currentMap[i-1][j] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j] == 'X'){
          countLive++;
        }
      }
      else{                            //all spaces inbetween
        if (currentMap[i-1][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j+1] == 'X'){
        countLive++;
        }
        if (currentMap[i+1][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j] == 'X'){
          countLive++;
        }
      }

      nextMap[i][j] = '-';      //initialize spot to -

      //Dead or Alive?
      if (currentMap[i][j] == 'X' && countLive < 2) // < 2, die
      {
        nextMap[i][j] = '-';
      }
      else if (currentMap[i][j] == 'X' && countLive == 2) // == 2, live
      {
        nextMap[i][j] = 'X';
      }
      else if (currentMap[i][j] == 'X' && countLive == 3) // ==3, live
      {
        nextMap[i][j] = 'X';
      }
      else{                                             // > 3, die
        nextMap[i][j] = '-';
      }
      cout << nextMap[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  memcpy(currentMap, nextMap, (sizeof(char *) * nextR * nextC));
  strStream << "Current Generation: " << gen;
  generationCycle = strStream.str();
  gen++;
  return generationCycle;
}

char** Classic::getNextMap()
{
  return nextMap;
}
