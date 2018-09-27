#pragma once
#include <iostream>
#include <fstream>
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
  void Stabilized();
  void outputMap(bool output, string filename, const int nextR, const int nextC);
private:
  int totalAlive;
  int countLive;
  bool isStable;
  char** nextMap;
};
