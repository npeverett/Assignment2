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
  char again;

  cout << "Game of Life" << endl;
  cout << "Would you like to provide a map file? Y/N" << endl;
  cin >> answer;

  cout << " " << endl;
  cout << "Which gamemode would you like to play?" << endl;
  cout << " " << endl;
  cout << "Classic: All locations off grid are considered empty." << endl;
  cout << "Donut:   Grid is wrapped horizontally and vertically." << endl;
  cout << "Mirror:  References off the grid are bounced back as if wall is mirror." << endl;
  cin >> gameMode;
  cout << " " << endl;

  if (toupper(answer) == 'Y'){
    cout << "Enter the file name: ";
    cin >> filename;
    bm.readMap(filename);
    bm.createUserMap(filename);
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
    bm.fillMap(popDensity);
    int row2 = bm.getCurrentMapR();
    int column2 = bm.getCurrentMapC();
    char** mapRef = bm.getMap();
    cout << c.hasNeighbor(row2, column2, mapRef) << endl;
    cout << "Press Enter to see next generation" << endl;
    cin.get();
    while(cin.get() == '\n'){
      char** temp = c.getNextMap();
      cout << c.hasNeighbor(row2, column2, temp) << endl;
      cout << "Press Enter to see next generation" << endl;
      cin.get();
    }
  }
  else{
    cout << "Please only enter Y or N respectively" << endl;
    return 0;
  }
  return 0;
}
