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
  char** gameMapRef;
  char** nextMap;
private:
  int countLive;
};
