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
  void Stabilized();
  void outputMap(bool output, string filename, const int nextR, const int nextC);

private:
  bool isStable;
  int totalAlive;
  int countLive;
  char** nextMap;
};
