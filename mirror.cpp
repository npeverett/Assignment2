#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include "buildMap.h"
#include "mirror.h"

using namespace std;

Mirror::Mirror()
{
}

Mirror::~Mirror()
{
  for (int i=0; i < BuildMap::getCurrentMapR(); ++i){
    delete[] nextMap[i];
  }
  delete[] nextMap;
  cout << "Mirror Destroyed" << endl;
}

void Mirror::mirrorNeighbors(const int nextR, const int nextC, char** currentMap)
{
  totalAlive = 0;
  nextMap = new char*[nextR];
  for (int i=0; i < nextR; ++i)
  {
    nextMap[i] = new char[nextC];
  }

  for (int i=0; i < nextR; ++i){
    for (int j=0; j < nextC; ++j){
      countLive = 0;

      //Same Checking as Classic Mode
      if (i-1 >= 0 && j-1 >= 0){
        if (currentMap[i-1][j-1]){
          countLive++;
        }
      }
      if (i-1 >= 0){
        if (currentMap[i-1][j] == 'X'){
          countLive++;
        }
      }
      if (i-1 >= 0 && j+1 < nextC){
        if (currentMap[i-1][j+1] == 'X'){
          countLive++;
        }
      }
      if (j-1 >= 0){
        if (currentMap[i][j-1] == 'X'){
          countLive++;
        }
      }
      if (j+1 < nextC){
        if (currentMap[i][j+1] == 'X'){
          countLive++;
        }
      }
      if (i+1 < nextR && j-1 >= 0){
        if (currentMap[i+1][j-1] == 'X'){
          countLive++;
        }
      }
      if (i+1 < nextR){
        if (currentMap[i+1][j] == 'X'){
          countLive++;
        }
      }
      if (i+1 < nextR && j+1 < nextC){
        if (currentMap[i+1][j+1] == 'X'){
          countLive++;
        }
      }

      //Same Check As Donut, but evaluates bool for Mirror mode
      if (i-1 < 0 && j-1 < 0){
        if (currentMap[nextR-1][nextC-1] == 'X'){
          countLive++;
        }
      }
      if (i-1 < 0){
        if (currentMap[nextR-1][j] == 'X'){
          countLive++;
        }
      }
      if (j-1 < 0){
        if (currentMap[i][nextC-1] == 'X'){
          countLive++;
        }
      }
      if (j+1 == nextC){
        if (currentMap[i][0] == 'X'){
          countLive++;
        }
      }
      if (i+1 == nextR){
        if (currentMap[0][j] == 'X'){
          countLive++;
        }
      }
      if (i-1 < 0 && j+1 == nextC){
        if (currentMap[nextR-1][0] == 'X'){
          countLive++;
        }
      }
      if (i+1 == nextR && j-1 < 0){
        if (currentMap[0][nextC-1] == 'X'){
          countLive++;
        }
      }
      if (i+1 == nextR && j+1 == nextC){
        if (currentMap[0][0] == 'X'){
          countLive++;
        }
      }

      nextMap[i][j] = '-';      //initialize spot to -
      //cout << i << "," << j << " " << countLive << endl;
      //Dead or Alive?
      if (currentMap[i][j] == 'X' && countLive < 2) // < 2, die
      {
        nextMap[i][j] = '-';
      }
      else if (currentMap[i][j] == 'X' && countLive == 2) // == 2, live
      {
        nextMap[i][j] = 'X';
        totalAlive++;
      }
      else if (countLive == 3) // ==3, live
      {
        nextMap[i][j] = 'X';
        totalAlive++;
      }
      else{                                             // > 3, die
        nextMap[i][j] = '-';
      }
      cout << nextMap[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

char** Mirror::getNextMap()
{
  return nextMap;
}

void Mirror::deadEnvironment()
{
  if (totalAlive == 0){
    cout << "Looks like your cells have all died out. System exiting..." << endl;
    exit(0);
  }
}
