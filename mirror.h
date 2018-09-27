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
private:
  int totalAlive;
  int countLive;
  char** nextMap;

};
