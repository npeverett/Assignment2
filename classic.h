#pragma once
#include <iostream>
#include <fstream>
#include "buildMap.h"

using namespace std;

class Classic : public BuildMap{
public:
  Classic();
  ~Classic();
  string hasNeighbor(const int nextR, const int nextC, char** currentMap);
  char** getNextMap();

private:
  int countLive;
  string generationCycle;
  char** nextMap;
};
