#include <iostream>

using namespace std;

class gameOfLife{
  public:
    gameOfLife(int rows,int columns,double density,string grid,char mode,bool fileOrRand);


  private:
    int row;
    int column;
    double density; //ask user for density of grid for random grid setup
    string grid; //maybe set up as array and learn to pass it through to driver
    char mode; //type of mode classic, donut or mirror
    string output;

    void runGame; //run the actual game
    void array2D; //current generation of the 2d array
    void runSimulation; //runs the simulation 
    void printFile; //print to a file

    char **currGrid; //current generation
    char **tempGrid; //next generation
    bool isDead;
    bool isStable; //if the generations are stable
    bool outputFile; //foroutputting the file


}
