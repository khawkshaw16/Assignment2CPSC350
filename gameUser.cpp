#include "gameUser.h"
#include <cmath>
#include <ifstream>

using namespace std;

gameUserInput::gameUserInput(){

  row = 0;
  column = 0;
  density = 0.0;
  grid = "";
  mode = '';
  fileOrRand = false;
}

gameStart::gameStart(){
  //get user input first to start gameUser
  cout << "Would you like to setup a random grid or input a txt file?" << endl;
  cout << "For a random grid input: 'r' " << endl;
  cout << "If inputing a file input: 'f' " << endl;
  cout << "If you would like to exit input: 'x' " << endl;
  char userInput;
  cin >> userInput;


}
