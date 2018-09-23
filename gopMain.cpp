#include <iostream>
#include "buildMap.h"
#include "classic.h"
using namespace std;

int main()
{
  BuildMap bm;
  Classic c;
  int row;
  int column;
  string filename;
  float popDensity;
  char answer;

  cout << "Game of Life" << endl;
  cout << "Would you like to provide a map file? Y/N" << endl;
  cin >> answer;


  if (toupper(answer) == 'Y'){
    cout << "Enter the file name: ";
    cin >> filename;
    bm.readMap(filename);
    cout << bm.createUserMap(filename) << endl;
  }

  else if (toupper(answer) == 'N'){
    cout << "Enter number of rows: " << endl;
    cin >> row;
    cout << "Enter number of columns: " << endl;
    cin >> column;
    cout << " " << endl;
    cout << "Enter the initial population density between 0 and 1" << endl;
    cin >> popDensity;

    if (cin.fail()){
      cout << "Please enter a float between 0 and 1" << endl;
      exit(0);
    }

    if (0 > popDensity || popDensity > 1){
      cout << "Please only enter a value between 0 and 1" << endl;
      exit(0);
    }

    bm.createNewMap(row, column);
    cout << bm.fillMap(popDensity) << endl;
    cout << c.hasNeighbor() << endl;
  }
  else{
    cout << "Please only enter Y or N respectively" << endl;
    return 0;
  }

  return 0;
}
