#include "gameOfLife.h"
#include <cmath>
#include <ifstream>
#include <string>
#include <time.h>
#include <std.lib.h>

using namespace std;

gameOfLife::gameOfLife(int row,int column,double density,string grid,char mode,bool fileOrRand){

  char alive = 'x';
  char dead = '-';
  this.row = row;
  this.column = column;
  this.density = density;
  this.grid = grid;
  this.mode = mode;
  this.fileOrRand = fileOrRand;
  string pauseBetween; //pauses between generations
  string enterBetween; //enter to go to next generation
  char outputFile; //choose how they want file to be output
  currGrid = new char*[row];
  tempGrid = new char*[row];
  numRow = row;
  numCol = column;
  for(int i = 0; i < numRow; ++i){
    currGrid[i] = new char[numCol];
    tempGrid[i] = new char[numCol];
    for(int j = 0; j < numCol; ++j){
      currGrid[i][j] = '-';
      tempGrid[i][j] = '-';
    }
  }
  //adding grid string into the 2d array
  if(array2D(grid)){
    runSimulation(); //runs the simulation for the game
  }

}


void gameOfLife::array2D(){
  if(grid.length() = (numRow * numCol)){
    int gridIndex = 0;
    for(int i = 0; i < numRow; ++i){
      for(int j = 0; j < numCol; ++j){
        if(tolower(grid(gridIndex)) == 'x' || grid(gridIndex) == '-'){
          currGrid[i][j] = grid(gridIndex);
          ++gridIndex;
        }
      }
    }
  }

}


void gameOfLife::runSimulation(){

  int numAlive = 0;
  for(int i = 0; i < numRow; ++i){
    for(int j = 0; j < numCol; ++j){
      //first corner
      if(i == 0 && j == 0){
        if(grid[i][j+1] == alive){
          numAlive++;
        }
        if(grid[i+1][j+1] == alive){
          numAlive++;
        }
        if(grid[i+1][j] == alive){
          numAlive++;
        }
      }
      //second corner
      else if(i == 0 && j == numRow){
        if(grid[i][numRow - 1] == alive){
          numAlive++;
        }
        if(grid[numRow - 1][j+1] == alive){
          numAlive++;
        }
        if(grid[numRow][j+1] == alive){
          numAlive++;
        }
      }
      //third corner
      else if(i == numCol && j == 0){
        if(grid[numCol - 1][j] == alive){
          numAlive++;
        }
        if(grid[i+1][numCol - 1] == alive){
          numAlive++;
        }
        if(grid[i+1][numCol] == alive){
          numAlive++;
        }
      }
      //fourth corner
      else if(i == numCol && j == numRow){
        if(grid[numCol - 1][numRow] == alive){
          numAlive++;
        }
        if(grid[numCol - 1][numRow - 1] == alive){
          numAlive++;
        }
        if(grid[numCol][numRow - 1] == alive){
          numAlive++;
        }
      }

      //top border
      else if(j == 0){
        if(grid[i-1][j] == alive){
          numAlive++;
        }
        if(grid[i-1][j+1] == alive){
          numAlive++;
        }
        if(grid[i][j+1] == alive){
          numAlive++;
        }
        if(grid[i+1][j+1] == alive){
          numAlive++;
        }
        if(grid[i+1][j] == alive){
          numAlive++;
        }
      }
      //left side border
      else if(i == 0){
        if(grid[i][j-1] == alive){
          numAlive++;
        }
        if(grid[i+1][j-1] == alive){
          numAlive++;
        }
        if(grid[i+1][j] == alive){
          numAlive++;
        }
        if(grid[i+1][j+1] == alive){
          numAlive++;
        }
        if(grid[i][j+1] == alive){
          numAlive++;
        }
      }
      //right side border
      else if(j == numRow){
        if(grid[numRow][j-1] == alive){
          numAlive++;
        }
        if(grid[numRow - 1][j-1] == alive){
          numAlive++;
        }
        if(grid[numRow - 1][j] == alive){
          numAlive++;
        }
        if(grid[numRow - 1][j+1] == alive){
          numAlive++;
        }
        if(grid[numRow][j+1] == alive){
          numAlive++;
        }
      }
      else if(i == numCol){
        if(grid[i-1][numCol] == alive){
          numAlive++;
        }
        if(grid[i-1][numCol - 1] == alive){
          numAlive++;
        }
        if(grid[i][numCol - 1] == alive){
          numAlive++;
        }
        if(grid[i+1][numCol - 1] == alive){
          numAlive++;
        }
        if(grid[i+1][numCol] == alive){
          numAlive++;
        }
      }
      //middle piece
      else{
        if(grid[i-1][j-1] == alive){
          numAlive++;
        }
        if(grid[i][j-1] == alive){
          numAlive++;
        }
        if(grid[i+1][j-1] == alive){
          numAlive++;
        }
        if(grid[i+1][j] == alive){
          numAlive++;
        }
        if(grid[i+1][j+1] == alive){
          numAlive++;
        }
        if(grid[i][j+1] == alive){
          numAlive++;
        }
        if(grid[i-1][j+1] == alive){
          numAlive++;
        }
        if(grid[i-1][j] == alive){
          numAlive++;
        }
      }
      //one or less it will be empty
      if(numAlive <= 1){
        grid[i][j] = '-';
      }
      //if there was 2 remains stable if full stays full if empty stays empty
      else if(numAlive == 2){
        grid[i][j] = grid[i][j];
      }
      //if there is 3 it will have a cell if there wasn't one birth one
      else if(numAlive == 3){
        if(grid[i][j] == 'x'){
          grid[i][j] = 'x';
        }
        else if(grid[i][j] == '-'){
          grid[i][j] = 'x';
        }
      }
      //overcrowding so it will be empty
      else{
        grid[i][j] = '-';
      }

  }
}
void gameOfLife::runGame(){


}

void gameOfLife::printFile(){
  ofstream file;
  file.open(o, ofstream::out | ofstream::app);
  if(file.is_open()){
    file << numGens << endl;
    for(int i = 0; i < numRow; ++i){
      for(int j = 0; j < numCol; ++j){
        file << currGrid[i][j];
      }
      file << endl;
    }
    file.close();
  }
  else{
    cerr << "Error when opening file" << endl;
  }

}
