#pragma once
#include <iostream>
#include <fstream>
#include "buildMap.h"

using namespace std;

class Classic : public BuildMap{
public:
  Classic();
  ~Classic();
  void hasNeighbor(const int nextR, const int nextC, char** currentMap);
  char** getNextMap();
  void deadEnvironment();

private:
  int totalAlive;
  int countLive;
  char** nextMap;
};
