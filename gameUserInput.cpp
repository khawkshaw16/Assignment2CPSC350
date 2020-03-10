#include "gameUser.h"
#include <cmath>
#include <ifstream>
#include <string>
#include <time.h>
#include <std.lib.h>

using namespace std;

gameUserInput::gameUserInput(){

  row = 0;
  column = 0;
  density = 0.0;
  grid = "";
  mode = '';
  fileOrRand = false;
}

void gameUserInput::userIn(){
  //get user input first to start gameUser
  cout << "Would you like to setup a random grid or input a txt file?" << endl;
  cout << "For a random grid input: 'r' " << endl;
  cout << "If inputing a file input: 'f' " << endl;
  cout << "If you would like to exit input: 'x' " << endl;
  char userInput;
  cin >> userInput;
  if(userInput == 'f'){
    //input of text file use ifstream
    //call the inputGrid method
    inputGrid();
    }
  }
  else if(userInput == 'r'){
    //set up the random grid
    //call the randGrid method
    randGrid();
  }
  else if(userInput == 'x'){
    //exit program
    exit(0);
  }
  else{
    //error from input restart program
    //call the gameUserInput method
    //gameUserInput();
    cout << "There was an error with your input try again please." << endl;
    gameUserInput();
  }
}

void gameUserInput::inputGrid(){
  string nameOfFile;
  cout << "Enter name of file you would like to use: " << endl;
  cin >> nameOfFile;
  ifstream inTextFile;
  inTextFile.open(nameOfFile);
  if(inTextFile.fail()){
    cout << "Text file opening error!!!" << endl;
    exit(1);
    gameUserInput();
}

void gameUserInput::randGrid(){
  //setting up 2d array with the dimensions from input
  cout << "How many rows do you want for your grid?" << endl;
  cin >> row;
  //make sure the user input works
  if(cin.fail() || row <=1){
    cin.clear();
    cin.ignore();
    cout << "There was a problem with your input please try again." << endl;
    randGrid();
    return;
  }
  cout << "How many columns do you want for your grid?" << endl;
  cin >> column;
  //make sure the user input works
  if(cin.fail() || column <=1){
    cin.clear();
    cin.ignore();
    cout << "There was a problem with your input please try again." << endl;
    randGrid();
    return;
  }
  cout << "What would you like the density to be for the grid?" << endl;
  cin >> density;
  //make sure the user input works
  if(cin.fail()){
    cin.clear();
    cin.ignore();
    cout << "There was a problem with your input please try again." << endl;
    randGrid();
    return;
  }

  grid = "";
  srand(time(0));

  int numAlive = round(density * (row*column));
  while(grid.length() < (row*column)){
    int nextCell = rand() % 2 + 1;
    if(nextCell == 1){
      if(numAlive > 0){
        grid += "x";
        --numAlive;
      }
      else{
        grid += "-";
      }
    }
    else if(nextCell == 2){
      if((row*column) - grid.length() = numAlive){
        grid += "x";
      }
      else{
        grid += "-";
      }

    }
  }
//calling next method to put it into an array using pointers

}
