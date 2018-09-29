#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include "buildMap.h"
#include "mirror.h"

using namespace std;

//Empty Constructor
Mirror::Mirror()
{
}

//Destructor
Mirror::~Mirror()
{
  for (int i=0; i < BuildMap::getCurrentMapR(); ++i){
    delete[] nextMap[i];
  }
  delete[] nextMap;
  cout << "Mirror Destroyed" << endl;
}

//Method for Neighbor Checking in Mirror Mode
void Mirror::mirrorNeighbors(const int nextR, const int nextC, char** currentMap)
{
  //Local Variables
  totalAlive = 0;
  isStable = true;
  bool isAlive = false;    //keeps track of whether to check reflected spot or not

  //Insantiate New Array
  nextMap = new char*[nextR];
  for (int i=0; i < nextR; ++i)
  {
    nextMap[i] = new char[nextC];
  }

  for (int i=0; i < nextR; ++i){
    for (int j=0; j < nextC; ++j){
      countLive = 0;

      //New Checking For Mirror Mode (Some Still Same Checks As Classic)
      if (i == 0 && j == 0){      //top left corner
        if (currentMap[i][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 3;
        }
        if (currentMap[i][j+1] == 'X' && isAlive == false){
          countLive++;
        }
        if (currentMap[i+1][j] == 'X' && isAlive == false){
          countLive++;
        }
        if (currentMap[i+1][j+1] == 'X' && isAlive == false){
          countLive++;
        }
      }
      else if (i == nextR-1 && j == 0){ //bottom left corner
        isAlive = false;
        if (currentMap[i][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 3;
        }
        if (currentMap[i][j+1] == 'X' && isAlive == false){
          countLive++;
        }
        if (currentMap[i-1][j] == 'X' && isAlive == false){
          countLive++;
        }
        if (currentMap[i-1][j+1] == 'X' && isAlive == false){
          countLive++;
        }
      }
      else if (i == 0 && j == nextC-1){  //top right corner
        isAlive = false;
        if (currentMap[i][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 3;
        }
        if (currentMap[i][j-1] == 'X' && isAlive == false){
          countLive++;
        }
        if (currentMap[i+1][j] == 'X' && isAlive == false){
          countLive++;
        }
        if (currentMap[i+1][j-1] == 'X' && isAlive == false){
          countLive++;
        }
      }
      else if (i == nextR-1 && j == nextC-1){  //bottom right corner
        isAlive = false;
        if (currentMap[i][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 3;
        }
        if (currentMap[i][j-1] == 'X' && isAlive == false){
          countLive++;
        }
        if (currentMap[i-1][j] == 'X' && isAlive == false){
          countLive++;
        }
        if (currentMap[i-1][j-1] == 'X' && isAlive == false){
          countLive++;
        }
      }
      else if (i == nextR-1){          //bottom row
        isAlive = false;
        if (currentMap[i][j-1] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 2;
        }
        if (currentMap[i-1][j-1] == 'X' && isAlive == false){
          countLive++;
        }
        isAlive = false;
        if (currentMap[i][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive++;
        }
        if (currentMap[i-1][j] == 'X' && isAlive == false){
          countLive++;
        }
        isAlive = false;
        if (currentMap[i][j+1] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 2;
        }
        if (currentMap[i-1][j+1] == 'X' && isAlive == false){
          countLive++;
        }
      }
      else if (j == 0){                 //left column
        isAlive = false;
        if (currentMap[i-1][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 2;
        }
        if (currentMap[i-1][j+1] == 'X' && isAlive == false){
          countLive++;
        }
        isAlive = false;
        if (currentMap[i][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive++;
        }
        if (currentMap[i][j+1] == 'X' && isAlive == false){
          countLive++;
        }
        isAlive = false;
        if (currentMap[i+1][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 2;
        }
        if (currentMap[i+1][j+1] == 'X' && isAlive == false){
          countLive++;
        }
      }
      else if (i == 0){                 //top row
        isAlive = false;
        if (currentMap[i][j-1] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 2;
        }
        if (currentMap[i+1][j-1] == 'X' && isAlive == false){
          countLive++;
        }
        isAlive = false;
        if (currentMap[i][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive++;
        }
        if (currentMap[i+1][j] == 'X' && isAlive == false){
          countLive++;
        }
        isAlive = false;
        if (currentMap[i][j+1] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 2;
        }
        if (currentMap[i+1][j+1] == 'X' && isAlive == false){
          countLive++;
        }
      }
      else if (j == nextC-1){           //right column
        isAlive = false;
        if (currentMap[i-1][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 2;
        }
        if (currentMap[i-1][j-1] == 'X' && isAlive == false){
          countLive++;
        }
        isAlive = false;
        if (currentMap[i][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive++;
        }
        if (currentMap[i][j-1] == 'X' && isAlive == false){
          countLive++;
        }
        isAlive = false;
        if (currentMap[i+1][j] == 'X'){
          isAlive = true;
        }
        if (isAlive){
          countLive = countLive + 2;
        }
        if (currentMap[i+1][j-1] == 'X' && isAlive == false){
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

//Getter For Next Map
char** Mirror::getNextMap()
{
  return nextMap;
}

//Method To Check If Map Cells Have Died Out
void Mirror::deadEnvironment()
{
  if (totalAlive < 2){
    cout << "Looks like your cells have all died out. System exiting..." << endl;
    exit(0);
  }
}

//Method To Check If Generation Has Stabilized
void Mirror::Stabilized()
{
  if (isStable){
    cout << "Looks like your cells have stabilized. System exiting..." << endl;
    exit(0);
  }
}

//Method To Output Generation To File, Upon User Request
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
