#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include "buildMap.h"

using namespace std;

class Donut : public BuildMap
{
public:
  Donut();
  ~Donut();
  void donutNeighbors(const int nextR, const int nextC, char** currentMap);
  char** getNextMap();
  void deadEnvironment();
private:
  int totalAlive;
  int countLive;
  char** nextMap;
};
