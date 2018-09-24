#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class BuildMap
{
public:
  BuildMap();
  ~BuildMap();
  void createNewMap(const int rows, const int columns);
  string fillMap(float populationDensity);
  void readMap(string filename);
  string createUserMap(string filename);
  int getCurrentMapC();
  int getCurrentMapR();
  char** getMap();

  ifstream fin;
  ofstream fout;


private:
  int mapSize;
  char** gameMap;
  int R;
  int C;
  string generationCycle;
  string userRows;
  string userColumns;
  string userMap;

};
