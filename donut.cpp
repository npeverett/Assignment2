#include <iostream>
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
  totalAlive = 0;
  isStable = true;
  nextMap = new char*[nextR];
  for (int i=0; i < nextR; ++i)
  {
    nextMap[i] = new char[nextC];
  }

  for (int i=0; i < nextR; ++i){
    for (int j=0; j < nextC; ++j){
      countLive = 0;

      //New Checking Methods For Donut (Some Still The Same Checks As Classic)
      if (i == 0 && j == 0){          //top left corner
        if (currentMap[i][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[nextR-1][j] == 'X'){
          countLive++;
        }
        if (currentMap[nextR-1][j+1]){
          countLive++;
        }
        if (currentMap[nextR-1][nextC-1]){
          countLive++;
        }
        if (currentMap[i][nextC-1]){
          countLive++;
        }
        if (currentMap[i+1][j]){
          countLive++;
        }
      }
      else if (i == nextR-1 && j == 0){ //bottom left corner
        if (currentMap[i][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][j] == 'X'){
          countLive++;
        }
        if (currentMap[0][j] == 'X'){
          countLive++;
        }
        if (currentMap[0][j+1]){
          countLive++;
        }
        if (currentMap[0][nextC-1]){
          countLive++;
        }
        if (currentMap[i][nextC-1]){
          countLive++;
        }
        if (currentMap[i-1][nextC-1]){
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
        if (currentMap[nextR-1][j] == 'X'){
          countLive++;
        }
        if (currentMap[nextR-1][j-1]){
          countLive++;
        }
        if (currentMap[nextR-1][0]){
          countLive++;
        }
        if (currentMap[i][0]){
          countLive++;
        }
        if (currentMap[i+1][0]){
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
        if (currentMap[0][j] == 'X'){
          countLive++;
        }
        if (currentMap[0][j-1]){
          countLive++;
        }
        if (currentMap[0][0]){
          countLive++;
        }
        if (currentMap[i][0]){
          countLive++;
        }
        if (currentMap[i-1][0]){
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
        if (currentMap[0][j] == 'X'){
          countLive++;
        }
        if (currentMap[0][j-1] == 'X'){
          countLive++;
        }
        if (currentMap[0][j+1] == 'X'){
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
        if (currentMap[i][nextC-1] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][nextC-1] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][nextC-1] == 'X'){
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
        if (currentMap[nextR-1][j] == 'X'){
          countLive++;
        }
        if (currentMap[nextR-1][j+1] == 'X'){
          countLive++;
        }
        if (currentMap[nextR-1][j-1] == 'X'){
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
        if (currentMap[i][0] == 'X'){
          countLive++;
        }
        if (currentMap[i-1][0] == 'X'){
          countLive++;
        }
        if (currentMap[i+1][0] == 'X'){
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

char** Donut::getNextMap()
{
  return nextMap;
}

//Method to Check If All Cells Have Died
void Donut::deadEnvironment()
{
  if (totalAlive == 0){
    cout << "Looks like your cells have all died out. System exiting..." << endl;
    exit(0);
  }
}

//Method to Print If Generations Have Stabilized
void Donut::Stabilized()
{
  if (isStable){
    cout << "Looks like your cells have stabilized. System exiting..." << endl;
    exit(0);
  }
}

//Method To Print Generations To Output File
void Donut::outputMap(bool output, string filename, const int nextR, const int nextC)
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
