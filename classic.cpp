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
      if (i == 0 && j == 0){
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
      else if (i == nextR-1 && j == 0){
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
      //cout << i << "," << j << " " << countLive << endl;
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
