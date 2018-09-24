#include <iostream>
#include <sstream>
#include <fstream>
#include "buildMap.h"

using namespace std;

//Constructor
BuildMap::BuildMap()
{
}

//Destructor
BuildMap::~BuildMap()
{
  cout << "Map destroyed" << endl;
  delete[] gameMap;
}

//Method to create base-line blank map
void BuildMap::createNewMap(const int rows, const int columns)
{
  R = rows;               //set to access rows and columns in fillMap method
  C = columns;
  mapSize = rows * columns;

  gameMap = new char*[rows];
  for (int i=0; i < rows; ++i)
  {
    gameMap[i] = new char[columns];
  }

  for (int i=0; i < rows; ++i){         //map default spaces are -
    for (int j=0; j < columns; ++j){
      gameMap[i][j] = '-';
    }
  }
}

//Method to fill map with X based on user input of density
string BuildMap::fillMap(float populationDensity)
{
  stringstream strStream;
  int gen = 0;
  int numCells = mapSize * populationDensity;   //set to int because can't have fractional number of cells
  int open = 0;

  while (open < numCells){
    int randIndex1 = rand() % C;
    int randIndex2 = rand() % R;
    if (gameMap[randIndex1][randIndex2] == '-'){
      gameMap[randIndex1][randIndex2] = 'X';
      open++;
    }
  }

  for (int i=0; i < R; ++i){
    for (int j=0; j < C; ++j){
      cout << gameMap[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  strStream << "Current Generation: " << gen;
  generationCycle = strStream.str();
  gen++;
  return generationCycle;
}

void BuildMap::readMap(string filename)
{
  stringstream strStream;
  string line = "";
  int count = 0;

  fin.open(filename);
  if (fin.good()){
    strStream << fin.rdbuf();
    userMap = strStream.str();
  }

  else{
    cout << "Could not open file" << endl;
  }
  fin.close();
  fin.clear();
  fin.seekg(0, fin.beg);

  fin.open(filename);
  while (getline(fin,line)){
    ++count;
    if (count == 1){
      userRows = line;
    }
    if (count == 2){
      userColumns = line;
    }
  }
  fin.close();
  fin.clear();
  fin.seekg(0, fin.beg);
}

string BuildMap::createUserMap(string filename)
{
  stringstream strStream;
  fin.open(filename);
  string line;
  int gen = 0;
  int count = 0;
  R = stoi(userRows);
  C = stoi(userColumns);

  gameMap = new char*[R];
  for (int i=0; i < R; ++i)
  {
    gameMap[i] = new char[C];
  }

  while (count < 3){
    getline(fin, line);
    ++count;
  }

  for (int i=0; i < R; ++i){
    for (int j=0; j < C; ++j){
      fin >> gameMap[i][j];
      cout << gameMap[i][j];
    }
    cout << endl;
  }
  cout << endl;
  strStream << "Generation: " << gen;
  generationCycle = strStream.str();
  gen++;
  return generationCycle;
}

int BuildMap::getCurrentMapR()
{
  return R;
}

int BuildMap::getCurrentMapC()
{
  return C;
}

char** BuildMap::getMap()
{
  return gameMap;
}
