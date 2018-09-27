#pragma once
#include <iostream>
#include <fstream>
#include "buildMap.h"

class Mirror : public BuildMap
{
public:
  Mirror();
  ~Mirror();
  void mirrorNeighbors(const int nextR, const int nextC, char** currentMap);
  char** getNextMap();
  void deadEnvironment();
  void Stabilized();
  void outputMap(bool output, string filename, const int nextR, const int nextC);
private:
  int totalAlive;
  int countLive;
  bool isStable;
  char** nextMap;

};
