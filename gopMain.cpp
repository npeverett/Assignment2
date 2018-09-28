#include <iostream>
#include "buildMap.h"
#include "classic.h"
#include "donut.h"
#include "mirror.h"
using namespace std;

int main()
{
  //Global Variables
  BuildMap bm;
  Classic c;
  Donut d;
  Mirror m;
  string filenameINPUT;
  string filenameOUTPUT;
  char answerINPUT;
  char answerOUTPUT;
  bool outputToFile = false;
  ofstream fout;
  int row;
  int column;
  char gameMode;
  float popDensity;
  char again;
  int gen = 0;

  //Introduction to Game
  cout << " " << endl;
  cout << "Game of Life" << endl;
  cout << "Would you like to provide a map file? Y/N" << endl;
  cin >> answerINPUT;
  answerINPUT = toupper(answerINPUT);

  //If User Inputs Char Other Than Y or N
  if (answerINPUT != 'Y' && answerINPUT != 'N'){
    cout << "Please only enter Y or N respectively" << endl;
    exit(0);
  }

  //If User Would Like Output Into A File
  cout << " " << endl;
  cout << "Would you like the generation maps to be outputted to a file? Y/N" << endl;
  cin >> answerOUTPUT;
  answerOUTPUT = toupper(answerOUTPUT);
  if (answerOUTPUT != 'Y' && answerOUTPUT != 'N'){
    cout << "Please only enter Y or N respectively" << endl;
    exit(0);
  }
  if (answerOUTPUT == 'Y'){
    outputToFile = true;
    cout << "Enter the output file name: ";
    cin >> filenameOUTPUT;
    fout.open(filenameOUTPUT);
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
  if (answerINPUT == 'Y'){
    cout << "Enter the file name: ";
    cin >> filenameINPUT;
    bm.readMap(filenameINPUT);
    bm.createUserMap(filenameINPUT);
  }

  //User Decides to Create Own Map
  else if (answerINPUT == 'N'){
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
  }
    //If User Chooses Classic Mode
    if (gameMode == 'C')
    {
      int row2 = bm.getCurrentMapR();
      int column2 = bm.getCurrentMapC();
      char** mapRef = bm.getMap();
      c.hasNeighbor(row2, column2, mapRef);
      c.outputMap(outputToFile, filenameOUTPUT, row2, column2);
      gen++;
      cout << "Current Generation: " << gen << endl;
      cout << "Press Enter to see next generation, or X to exit" << endl;
      again = cin.get();
      while(again == ('\n')){
        char** temp = c.getNextMap();
        c.hasNeighbor(row2, column2, temp);
        c.outputMap(outputToFile, filenameOUTPUT, row2, column2);
        gen++;
        cout << "Current Generation: " << gen << endl;
        c.deadEnvironment();
        c.Stabilized();
        cout << "Press Enter to see next generation, or X to exit" << endl;
        again = cin.get();
        if (again == 'x'){
          cout << "Exiting..." << endl;
          exit(0);
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
      d.outputMap(outputToFile, filenameOUTPUT, row2, column2);
      gen++;
      cout << "Current Generation: " << gen << endl;
      cout << "Press Enter to see next generation, or X to exit" << endl;
      again = cin.get();
      while(again == ('\n')){
        char** temp = d.getNextMap();
        d.donutNeighbors(row2, column2, temp);
        d.outputMap(outputToFile, filenameOUTPUT, row2, column2);
        gen++;
        cout << "Current Generation: " << gen << endl;
        d.deadEnvironment();
        d.Stabilized();
        cout << "Press Enter to see next generation, or X to exit" << endl;
        again = cin.get();
        if (again == 'x'){
          cout << "Exiting..." << endl;
          return 0;
        }
        else if (again != '\n'){
          cout << "Press Enter to Continue, or 'X' to exit" << endl;
          cin >> again;
        }
      }
    }
    else if (gameMode == 'M')
    {
      int row2 = bm.getCurrentMapR();
      int column2 = bm.getCurrentMapC();
      char** mapRef = bm.getMap();
      m.mirrorNeighbors(row2, column2, mapRef);
      m.outputMap(outputToFile, filenameOUTPUT, row2, column2);
      gen++;
      cout << "Current Generation: " << gen << endl;
      cout << "Press Enter to see next generation, or X to exit" << endl;
      again = cin.get();
      while(again == ('\n')){
        char** temp = m.getNextMap();
        m.mirrorNeighbors(row2, column2, temp);
        m.outputMap(outputToFile, filenameOUTPUT, row2, column2);
        gen++;
        cout << "Current Generation: " << gen << endl;
        m.deadEnvironment();
        cout << "Press Enter to see next generation, or X to exit" << endl;
        again = cin.get();
        if (again == 'x'){
          cout << "Exiting..." << endl;
          exit(0);
        }
        else if (again != '\n'){
          cout << "Press Enter to Continue, or 'X' to exit" << endl;
          cin >> again;
        }
      }
    }
  return 0;
}
