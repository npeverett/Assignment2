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

      //Check for Mirror mode
      if (i-1 < 0 && j-1 < 0){
        if (currentMap[0][0] == 'X'){
          countLive = countLive + 3;
        }
      }
      if (i-1 < 0){
        if (j-1 != -1 && j+1 != nextC){
          if (currentMap[i][j] == 'X'){
            countLive++;
          }
        }
      }
      if (j-1 < 0){
        if (i-1 != -1 && i+1 != nextR){
          if (currentMap[i][j] == 'X'){
            countLive++;
          }
        }
      }
      if (j+1 == nextC){
        if (i-1 != -1 && i+1 != nextR){
          if (currentMap[i][j] == 'X'){
            countLive++;
          }
        }
      }
      if (i+1 == nextR){
        if (j-1 != -1 && j+1 != nextC){
          if (currentMap[i][j] == 'X'){
            countLive++;
          }
        }
      }
      if (i-1 < 0 && j+1 == nextC){
        if (currentMap[0][nextC-1] == 'X'){
          countLive = countLive + 3;
        }
      }
      if (i+1 == nextR && j-1 < 0){
        if (currentMap[nextR-1][0] == 'X'){
          countLive = countLive + 3;
        }
      }
      if (i+1 == nextR && j+1 == nextC){
        if (currentMap[nextR-1][nextC-1] == 'X'){
          countLive = countLive + 3;
        }
      }
      //cout << i << "," << j << " " << countLive << endl;
       //Initialize Spot To -
      nextMap[i][j] = '-';

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
      else{                   // > 3, die
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

//Getter For Map To Access For Next Generation
char** Mirror::getNextMap()
{
  return nextMap;
}

//Method To Check If Environment Has Died
void Mirror::deadEnvironment()
{
  if (totalAlive == 0){
    cout << "Looks like your cells have all died out. System exiting..." << endl;
    exit(0);
  }
}

//Method to Print If Generations Have Stabilized
void Mirror::Stabilized()
{
  if (isStable){
    cout << "Looks like your cells have stabilized. System exiting..." << endl;
    exit(0);
  }
}

//Method To Print Generations To Output File
void Mirror::outputMap(bool output, string filename, const int nextR, const int nextC)
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
