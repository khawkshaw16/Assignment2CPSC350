#include <iostream>

using namespace std;

class gameUserInput {
  //get user input for grid either take in a txt or set up a random grid
  public:
    gameUserInput();

  private:

    int row;
    int column;
    double density; //ask user for density of grid for random grid setup
    string grid; //maybe set up as array and learn to pass it through to driver
    char mode; //type of mode classic, donut or mirror
    bool fileOrRand; //bool for asking if they want to upload text file or rand grid setup



}
