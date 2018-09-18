#ifndef BOARD_H 
#define BOARD_H 
 
#include "cell.h"
#include "item.h"
#include "enemy.h"
#include "player.h"
#include "skill.h"
#include <iostream>
#include <vector>
#include "dragonhoard.h"
#include "potion.h"
#include "gold.h"
#include <stdlib.h>
 
  class Board { 

	bool isFirst;
	//Game constants
	int rows;
	int cols;
	int numRooms;
	static const int NUMFLOORS = 5;
	//# of tiles in largest room
	static const int NUMENEMIES;
	static const int NUMGOLD;
	static const int NUMPOTIONS;

	//generation of objects
	// ie (human, 2/18) (Dwarf, 3/18)
  //denom here would be 18
	static const int ENEMYDENOM = 18;
	static const int POTIONDENOM  = 6;
	static const int GOLDDENOM = 8;
	//distribution (human, 2/18) then human will appear twice
	static const int ENEMYDIST[ENEMYDENOM];
	static const int POTIONDIST[POTIONDENOM];
	static const int GOLDDIST[GOLDDENOM];
	

	//Player Data
	Player *p;
	int pRace;
	int pRow, pCol;
	static const int DEFAULTRACE;

	//Stair Location
	Cell *s;
	int sRow, sCol;

	//First Floor == 1
	int floor;
	//NULL if default layout (floor.txt) or a filepath
	static const std::string FLOORPATH;

	//Walls, tiles, doors, passageways
	Cell **cells;

	//stores loc. of tiles that are valid for spawning
	//rmMax stores rm size, essentially row length in irregular 2d array
	std::vector<int> rmMax;
	std::vector<int> rmRow;
  std::vector<int> rmCol;
	
	//Renders on top of cells
	Item **items;

	//Renders on top of everything
	Enemy **enemies;
	static const bool HARDPATHING;

	Cell *getCell(int row, int col);

	void setCell(int row, int col, Cell *c);

	Item *getItem(int row, int col);

	void setItem(int row, int col, Item *i);

	Enemy *getEnemy(int row, int col);

	void setEnemy(int row, int col, Enemy *e);

	int getTileRow(int rm, int tile);

	int getTileCol(int rm, int tile);

	void addTile(int rm, int row, int col);

	//returns if valid location for player movement
	bool isValid(int row, int col);

	bool isValidEnemyMove(int row, int col);

	bool isValidSpawn(int row, int col);

	//note: will infinite loop if room chosen if completely filled
	void place(Enemy *e);

	void place(Item *i);

	void place(DragonHoard *g);
	
	void removeEnemy(int row, int col);

	void removeItem(int row, int col);

	void recFloor(bool *floor, int row, int col);
	
	Enemy *generateEnemy();

	Potion *generatePotion();


	//DEFINE GOLD CLASS CONSTANTS
	Gold *generateGold();

	bool inSameRoom(int row1, int col1, int row2, int col2);
	//current row col
	void moveEnemy(Enemy *e, int row, int col);

	void moveNextFloor();

	//player move
	bool move(int nRow, int nCol);

	void onDeath(Enemy *e, int row, int col);

	//player attack
	bool attack(int nRow, int nCol);

	//player use (for now only potions)
	bool use(int nRow, int nCol);

	bool hasEmptyNeighbor(int row, int col);

	bool useSkill(char command, int row, int col);
	bool useSkill(char command);


	public:
	static std::string floorData[NUMFLOORS];
	//input constants
	static const char MOVE;
	static const char ATK;
	static const char USE;
	static const char SKILL1;
	static const char SKILL2;

	// Player Race ids
	static const int SHADE = 0;
	static const int DROW = 1;
	static const int VAMP = 2;
	static const int TROLL = 3;
	static const int GOB = 4;
	static const int VALK = 5;
	static const int ASSN = 6;
	static const int BERS = 7;
	static const int GOD = 8;

	// Enemy ids
	static const int HUMAN = 0;
	static const int DWARF = 1;
	static const int HALF =  2;
	static const int ELF = 3;
	static const int ORC = 4;
	static const int MERCH = 5;
	static const int DRAG = 6;
	static const int RAT = 7;

	//Potion ids
	static const int RHID = 0;
	static const int BAID = 1;
	static const int BDID = 2;
	static const int PHID = 3;
	static const int WAID = 4;
	static const int WDID = 5;

	//Gold ids
	static const int SMALL = 6;
	static const int NORM = 7;
	static const int DHOARD = 8;
	static const int MHOARD = 9;

	//race - constant int referring to race
	Board(std::string name);
	Board(int race, std::string name);
	~Board();

	//initializes level, advances levels
	void generate();

	//returns true player died
	bool isGameOver();

	bool isWin();


	//print 
	void gameOver();
	void win();

	//move player in dir
	bool move(std::string dir);

	//use item in dir
	bool use(std::string dir);
	
	Skill *getPlayerSkill(int n);

	//have all enemies execute their turn
	void enemyTurn();

	//have player execute the specified move using input constants
	bool playerTurn(char command, std::string dir);

	void setPlayerName(std::string name);

	//displays the board using cout
	void print();

  }; 

#endif
