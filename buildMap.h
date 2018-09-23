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

  ifstream fin;
  ofstream fout;
  char** gameMap;
  int R;
  int C;

private:
  int mapSize;
  string generationCycle;
  string userRows;
  string userColumns;
  string userMap;

};
