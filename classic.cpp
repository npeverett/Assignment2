#include <iostream>
#include <sstream>
#include <fstream>
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

void Classic::hasNeighbor()
{
  char nextMap[R][C];
  gameMapRef = &gameMap;
  for (int i=0; i < R; ++i){
    for (int j=0; j < C; ++j){
      countLive = 0;
      if (gameMapRef[i-1][j-1] == "X"){
        countLive++;
      }
      if (gameMapRef[i][j-1] == "X"){
        countLive++;
      }
      if (gameMapRef[i-1][j] == "X"){
        countLive++;
      }
      if (gameMapRef[i-1][j+1] == "X"){
        countLive++;
      }
      if (gameMapRef[i+1][j-1] == "X"){
        countLive++;
      }
      if (gameMapRef[i+1][j+1] == "X"){
        countLive++;
      }
      if (gameMapRef[i][j+1] == "X"){
        countLive++;
      }
      if (gameMapRef[i+1][j] == "X"){
        countLive++;
      }

      nextMap[i][j] = '-';

      if (gameMap[i][j] == 'X' && countLive < 2)
      {
        nextMap[i][j] = '-';
      }
      else if (gameMap[i][j] == 'X' && countLive == 2)
      {
        nextMap[i][j] = 'X';
      }
      else if (gameMap[i][j] == 'X' && countLive == 3)
      {
        nextMap[i][j] = 'X';
      }
      else{
        nextMap[i][j] = '-';
      }
    }
  }
  delete[] nextMap;
}
