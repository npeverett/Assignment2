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
}

int Classic::hasNeighbor()
{
  gameMapRef = &gameMap;
  countLive = 0;
  for (int i=0; i < R; ++i){
    for (int j=0; j < C; ++j){
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
    }
  }
  return countLive;
}
