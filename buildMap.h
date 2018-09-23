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
  int readMap(string filename);
  int createUserMap();

  ifstream fin;
  ofstream fout;


private:
  char** gameMap;
  int mapSize;
  int R;
  int C;
  string userRows;
  string userColumns;
  string userMap;

};
