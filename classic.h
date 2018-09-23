#pragma once
#include <iostream>
#include <fstream>
#include "buildMap.h"

using namespace std;

class Classic : public BuildMap{
public:
  Classic();
  ~Classic();
  int hasNeighbor();
  char*** gameMapRef;
private:
  int countLive;
};
