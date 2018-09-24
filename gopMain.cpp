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
  string gameMode;
  float popDensity;
  char answer;

  cout << "Game of Life" << endl;
  cout << "Would you like to provide a map file? Y/N" << endl;
  cin >> answer;

  cout << " " << endl;
  cout << "Which gamemode would you like to play?" << endl;
  cout << "Classic: All locations off grid are considered empty." << endl;
  cout << "Donut:   Grid is wrapped horizontally and vertically." << endl;
  cout << "Mirror:  References off the grid are bounced back as if wall is mirror." << endl;
  cin >> gameMode;
  cout << " " << endl;

  if (toupper(answer) == 'Y'){
    cout << "Enter the file name: ";
    cin >> filename;
    bm.readMap(filename);
    cout << bm.createUserMap(filename) << endl;
  }

  else if (toupper(answer) == 'N'){
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> column;
    cout << " " << endl;
    cout << "Enter the initial population density between 0 and 1" << endl;
    cin >> popDensity;
    cout << " " << endl;

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
    int row2 = bm.getCurrentMapC();
    int column2 = bm.getCurrentMapR();
    char** mapRef = bm.getMap();
    c.hasNeighbor(row2, column2, mapRef);
  }
  else{
    cout << "Please only enter Y or N respectively" << endl;
    return 0;
  }

  return 0;
}
