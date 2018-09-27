#include <iostream>
#include "buildMap.h"
#include "classic.h"
#include "donut.h"
using namespace std;

int main()
{
  //Global Variables
  BuildMap bm;
  Classic c;
  Donut d;
  int row;
  int column;
  string filename;
  char gameMode;
  float popDensity;
  char answer;
  char again;
  int gen = 0;

  //Introduction to Game
  cout << " " << endl;
  cout << "Game of Life" << endl;
  cout << "Would you like to provide a map file? Y/N" << endl;
  cin >> answer;
  answer = toupper(answer);
  //If User Inputs Char Other Than Y or N
  if (answer != 'Y' && answer != 'N'){
    cout << "Please only enter Y or N respectively" << endl;
    exit(0);
  }

  //Which Game Mode?
  cout << " " << endl;
  cout << "Which gamemode would you like to play? (C,D,M)" << endl;
  cout << " " << endl;
  cout << "Classic: All locations off grid are considered empty." << endl;
  cout << "Donut:   Grid is wrapped horizontally and vertically." << endl;
  cout << "Mirror:  References off the grid are bounced back as if wall is mirror." << endl;
  cin >> gameMode;
  gameMode = toupper(gameMode);
  cout << " " << endl;
  //If User Inputs Char Other Than Game Mode Type
  if (gameMode != 'C' && gameMode != 'D' && gameMode != 'M' ){
    cout << "Please enter a character respective to your game mode choice." << endl;
    exit(0);
  }


  //Asking for File Name
  if (answer == 'Y'){
    cout << "Enter the file name: ";
    cin >> filename;
    bm.readMap(filename);
    bm.createUserMap(filename);
  }

  //User Decides to Create Own Map
  else if (answer == 'N'){
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> column;
    cout << " " << endl;
    cout << "Enter the initial population density between 0 and 1" << endl;
    cin >> popDensity;
    cout << " " << endl;

    //Checks to Make Sure Input is a float AND within 0-1 range
    if (cin.fail()){
      cout << "Please enter a float between 0 and 1" << endl;
      exit(0);
    }

    if (0 > popDensity || popDensity > 1){
      cout << "Please only enter a value between 0 and 1" << endl;
      exit(0);
    }

    //Instantiate Initial Map
    bm.createNewMap(row, column);
    bm.fillMap(popDensity);
    cout << "Current Generation: " << 0 << endl;
    cout << "Press X to stop program" << endl;
    cout << " " << endl;

    //If User Chooses Classic Mode
    if (gameMode == 'C')
    {
      int row2 = bm.getCurrentMapR();
      int column2 = bm.getCurrentMapC();
      char** mapRef = bm.getMap();
      c.hasNeighbor(row2, column2, mapRef);
      gen++;
      cout << "Current Generation: " << gen << endl;
      cout << "Press Enter to see next generation" << endl;
      again = cin.get();
      while(again == ('\n')){
        char** temp = c.getNextMap();
        c.hasNeighbor(row2, column2, temp);
        gen++;
        cout << "Current Generation: " << gen << endl;
        c.deadEnvironment();
        cout << "Press Enter to see next generation" << endl;
        again = cin.get();
        if (again == 'x'){
          return 0;
        }
        else if (again != '\n'){
          cout << "Press Enter to Continue, or 'X' to exit" << endl;
          again = cin.get();
        }
      }
    }

    //If User Chooses Donut Mode
    else if (gameMode == 'D')
    {
      int row2 = bm.getCurrentMapR();
      int column2 = bm.getCurrentMapC();
      char** mapRef = bm.getMap();
      d.donutNeighbors(row2, column2, mapRef);
      gen++;
      cout << "Current Generation: " << gen << endl;
      cout << "Press Enter to see next generation" << endl;
      again = cin.get();
      while(again == ('\n')){
        char** temp = d.getNextMap();
        d.donutNeighbors(row2, column2, temp);
        gen++;
        cout << "Current Generation: " << gen << endl;
        d.deadEnvironment();
        cout << "Press Enter to see next generation" << endl;
        again = cin.get();
        if (again == 'x'){
          return 0;
        }
        else if (again != '\n'){
          cout << "Press Enter to Continue, or 'X' to exit" << endl;
          again = cin.get();
        }
      }
    }
    else if (gameMode == 'M')
    {
      cout << "This game mode has not been developed yet." << endl;
    }
  }

  return 0;
}
