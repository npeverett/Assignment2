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
  cout << "Classic Destructor Invoked" << endl;
  delete[] gameMapRef;
  delete[] nextMap;
}

void Classic::hasNeighbor(const int nextR, const int nextC, char** currentMap)
{
  nextMap = new char*[nextR];
  for (int i=0; i < nextR; ++i)
  {
    nextMap[i] = new char[nextC];
  }

  gameMapRef = new char*[nextR];
  for (int i=0; i < nextR; ++i){
    gameMapRef[i] = new char[nextC];
  }

  memcpy(gameMapRef, currentMap, (sizeof(char *) * nextR * nextC));

  for (int i=0; i < nextR; ++i){
    for (int j=0; j < nextC; ++j){
      countLive = 0;

      if ((i-1 < 0) || (j-1 < 0)){
        continue;
      }
      if ((i+1 > nextR || j+1 > nextC)){
        continue;
      }

      if (gameMapRef[i-1][j-1] == 'X'){
        countLive++;
      }
      if (gameMapRef[i][j-1] == 'X'){
        countLive++;
      }
      if (gameMapRef[i-1][j] == 'X'){
        countLive++;
      }
      if (gameMapRef[i-1][j+1] == 'X'){
        countLive++;
      }
      if (gameMapRef[i+1][j-1] == 'X'){
        countLive++;
      }
      if (gameMapRef[i+1][j+1] == 'X'){
        countLive++;
      }
      if (gameMapRef[i][j+1] == 'X'){
        countLive++;
      }
      if (gameMapRef[i+1][j] == 'X'){
        countLive++;
      }

      nextMap[i][j] = '-';

      if (gameMapRef[i][j] == 'X' && countLive < 2)
      {
        nextMap[i][j] = '-';
      }
      else if (gameMapRef[i][j] == 'X' && countLive == 2)
      {
        nextMap[i][j] = 'X';
      }
      else if (gameMapRef[i][j] == 'X' && countLive == 3)
      {
        nextMap[i][j] = 'X';
      }
      else{
        nextMap[i][j] = '-';
      }
    }
  }
}
