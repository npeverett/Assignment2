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
  for (int i=0; i < R; ++i)
  {
    delete[] gameMap[i];
  }
  delete[] gameMap;
  cout << "Map destroyed" << endl;
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
  for (int i=0; i < rows; i++){         //map default spaces are -
    for (int j=0; j < columns; j++){
      gameMap[i][j] = '-';
    }
  }
}

//Method to fill map with X based on user input of density
void BuildMap::fillMap(float populationDensity)
{
  stringstream strStream;
  int numCells = mapSize * populationDensity;   //set to int because can't have fractional number of cells
  int open = 0;
  while (open < numCells){
    int randIndex1 = rand() % (R - 1);          //getting random indexs to place the 'X' char
    int randIndex2 = rand() % (C - 1);
    if (gameMap[randIndex1][randIndex2] == '-'){
      gameMap[randIndex1][randIndex2] = 'X';

      open++;
    }
  }
  for (int i=0; i < R; ++i){          //printing map to console
    for (int j=0; j < C; ++j){
      cout << gameMap[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void BuildMap::readMap(string filename)
{
  string line = "";
  int count = 0;

  //Checking If File Is Good
  fin.open(filename);
  if (fin.good() == false){
    cout << "Could not open file" << endl;
    exit(0);
  }

  fin.close();
  fin.clear();
  fin.seekg(0, fin.beg);

  //Get Line and Column Count
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

  //Properly Close File
  fin.close();
  fin.clear();
  fin.seekg(0, fin.beg);
}

//Method To Create Map If User Has Given A File
void BuildMap::createUserMap(string filename)
{
  fin.open(filename);
  string line;
  int gen = 0;
  int count = 0;
  R = stoi(userRows);
  C = stoi(userColumns);

  //Insantiate New Empty Array
  gameMap = new char*[R];
  for (int i=0; i < R; ++i)
  {
    gameMap[i] = new char[C];
  }

  //Getting Actual Map Content, not Rows/Columns starting on 3rd line
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
}

//Getter for Rows
int BuildMap::getCurrentMapR()
{
  return R;
}

//Getter for Columns
int BuildMap::getCurrentMapC()
{
  return C;
}

//Getter for Game Map
char** BuildMap::getMap()
{
  return gameMap;
}
