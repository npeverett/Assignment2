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
  for (int i=0; i < BuildMap::getCurrentMapR(); ++i){
    delete[] nextMap[i];
  }
  delete[] nextMap;
  cout << "Classic Destroyed" << endl;
}

void Classic::hasNeighbor(const int nextR, const int nextC, char** currentMap)
{
  isStable = true;
  totalAlive = 0;
  stringstream strStream;
  nextMap = new char*[nextR];
  for (int i=0; i < nextR; ++i)
  {
    nextMap[i] = new char[nextC];
  }

  for (int i=0; i < nextR; ++i){
    for (int j=0; j < nextC; ++j){
      countLive = 0;
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

      nextMap[i][j] = '-';      //initialize spot to -

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

      //Checking if Map Stabilizes
      if (currentMap[i][j] != nextMap[i][j]){
        isStable = false;
      }

      //Printing New Generation
      cout << nextMap[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

char** Classic::getNextMap()
{
  return nextMap;
}

void Classic::deadEnvironment()
{
  if (totalAlive == 0){
    cout << "Looks like your cells have all died out. System exiting..." << endl;
    exit(0);
  }
}

void Classic::Stabilized()
{
  if (isStable){
    cout << "Looks like your cells have stabilized. System exiting..." << endl;
    exit(0);
  }
}

void Classic::outputMap(bool output, string filename, const int nextR, const int nextC)
{
  ofstream fout;
  fout.open(filename, ios_base::app);
  if (output){
    for (int i=0; i < nextR; ++i){
      for (int j=0; j < nextC; ++j){
        fout << nextMap[i][j] << " ";
      }
      fout << endl;
    }
    fout << endl;
  }
}
