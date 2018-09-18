#include <fstream>
#include <stdio.h>
#include "board.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "valkyrie.h"
#include "assassin.h"
#include "berserker.h"
#include "god.h"
#include "rat.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "ba.h"
#include "bd.h"
#include "rh.h"
#include "ph.h"
#include "wa.h"
#include "wd.h"
#include "potion.h"
#include "gold.h"
#include "dragonhoard.h"
#include "normalgold.h"
#include <cstdlib>
#include <ctime>
//#include ".h"


using namespace std;

const int Board::NUMENEMIES = 20;
const int Board::NUMGOLD = 10;
const int Board::NUMPOTIONS = 10;


const char Board::MOVE = 'm';
const char Board::ATK = 'a';
const char Board::USE = 'u';
const char Board::SKILL1 = 's';
const char Board::SKILL2 = 't';

const int Board::ENEMYDIST[ENEMYDENOM] = {HUMAN, HUMAN, HUMAN, HUMAN, DWARF, DWARF, DWARF, HALF, HALF, HALF, HALF, HALF, ELF, ELF, ORC, ORC, MERCH, MERCH};
const int Board::POTIONDIST[POTIONDENOM] = {RHID, BAID, BDID, PHID, WAID, WDID};
const int Board::GOLDDIST[GOLDDENOM] = {NORM, NORM, NORM, NORM, NORM, DHOARD, SMALL, SMALL};

string Board::floorData[NUMFLOORS] = {"", "" ,"" , "", ""};
const int Board::DEFAULTRACE = SHADE;

const string Board::FLOORPATH = "floor.txt";
	
//Default ctor uses DEFAULTRACE constant for race
Board::Board(string name){
	isFirst = true;
	int race = DEFAULTRACE;
	if(race == SHADE){
		p = new Shade();
	}else if(race == DROW){
		p = new Drow();
	}else if(race == VAMP){
		p = new Vampire();
	}else if(race == TROLL){
		p = new Troll();
	}else if(race == GOB){
		p = new Goblin();
	}else if(race == VALK){
		p = new Valkyrie();
	}else if(race == ASSN){
		p = new Assassin();
	}else if(race == BERS){
		p = new Berserker();
	}else if(race == GOD){
		p = new God();
	}
	pRace = race;
	s = new Cell('\\');

	floor = 0;
	setPlayerName(name);
	generate();
	cout <<"Player character has spawned." << endl;
}

Board::Board(int race, string name){
	isFirst = true;
	if(race == SHADE){
		p = new Shade();
	}else if(race == DROW){
		p = new Drow();
	}else if(race == VAMP){
		p = new Vampire();
	}else if(race == TROLL){
		p = new Troll();
	}else if(race == GOB){
		p = new Goblin();
	}else if(race == VALK){
		p = new Valkyrie();
	}else if(race == ASSN){
		p = new Assassin();
	}else if(race == BERS){
		p = new Berserker();
	}else if(race == GOD){
		p = new God();
	}
	pRace = race;
	s = new Cell('\\');

	floor = 0;

	setPlayerName(name);
	generate();
	cout <<"    Player character has spawned." << endl;
}


Cell * Board::getCell(int row, int col){
	if(items == NULL){
		return NULL;
	}
	return cells[row * cols + col];
}

void Board::setCell(int row, int col, Cell *c){
	cells[row * cols + col] = c;
}

Item * Board::getItem(int row, int col){
	if(items == NULL){
		return NULL;
	}
	return items[row * cols + col];
}

void Board::setItem(int row, int col, Item *i){
	items[row * cols + col] = i;
}

Enemy * Board::getEnemy(int row, int col){
	if(items == NULL){
		return NULL;
	}
	return enemies[row * cols + col];
}

void Board::setEnemy(int row, int col, Enemy *e){
	enemies[row * cols + col] = e;
}

Skill * Board::getPlayerSkill(int n){
	if(n == 1){return p->s1;}
	if(n == 2){return p->s2;}
	return NULL;
}

//deletes each enemy, item, and cell
//deletes the player and the stair
Board::~Board(){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			delete getEnemy(i, j);
			delete getItem(i, j);
			delete getCell(i, j);
		}
	}	
	delete s;
	delete p;
}


int Board::getTileRow(int rm, int tile){
	int n = 0;	
	for(int i = 0; i < rm; i++){
		n += rmMax[i];
	}
	n += tile;
	return rmRow[n];
}

int Board::getTileCol(int rm, int tile){
	int n = 0;
	for(int i = 0; i < rm; i++){
		n += rmMax[i];
	}
	n += tile;
	return rmCol[n];
}

void Board::addTile(int rm, int row, int col){
	int n;
	rmMax[rm]++;
	for(int i = 0; i < rm; i++){
		n += rmMax[i];
	}
	rmRow.insert(rmRow.begin() + n, row);
	rmCol.insert(rmRow.begin() + n, col);
}

//returns if valid location for player movement
bool Board::isValid(int row, int col){
	bool valid = (row >= 0 && row < rows && col >= 0 && col < cols);
	//use this format valid = valid && (condition);
	if(getCell(row, col) == NULL){return false;}
	valid = valid && (getCell(row, col)->isTile());
	valid = valid && (getEnemy(row, col) == NULL);
	if(getItem(row, col) != NULL){
		valid = valid && !(dynamic_cast<Potion *>(getItem(row, col)));
	}
	valid = valid || getCell(row, col)->isPassage() || getCell(row, col)->isDoor();
	return valid;
}

bool Board::isValidEnemyMove(int row, int col){
	bool valid = (row >= 0 && row < rows && col >= 0 && col < cols);
	valid = valid && !(row == pRow && col == pCol);
	valid = valid && !(row == sRow && col == sCol);
	//use this format valid = valid && (condition);
	if(getCell(row, col) == NULL){return false;}
	valid = valid && (getCell(row, col)->isTile());
	valid = valid && (getEnemy(row, col) == NULL && getItem(row, col) == NULL);
	//cout << "isValidEnemyMove executed successfully" << endl;
	return valid;
}

bool Board::isValidSpawn(int row, int col){
	bool valid = row >= 0 && row < rows && col >= 0 && col < cols;
	//use this format valid = valid && (condition);
	if(getCell(row, col) == NULL){return false;}
	valid = valid && (getCell(row, col)->isTile());
	valid = valid && (getEnemy(row, col) == NULL && getItem(row, col) == NULL);
	valid = valid && (row != pRow && col != pCol);
	valid = valid && (row != sRow && col != sRow);
	return valid;
}



//note: will infinite loop if room chosen if completely filled
void Board::place(Enemy *e){
	if(e == NULL){return;}
	int rm  = rand() % numRooms;
	
	while(true){
	int tile = rand() % rmMax[rm];
	int row = getTileRow(rm, tile);
	int col = getTileCol(rm, tile);
		if(isValidSpawn(row, col)){
			setEnemy(row, col, e);
			return;
		}
	}
}

void Board::place(Item *i){
	if(i == NULL){return;}
	int rm  = rand() % numRooms;
	
	while(true){
	int tile = rand() % rmMax[rm];
	int row = getTileRow(rm, tile);
	int col = getTileCol(rm, tile);
		if(isValidSpawn(row, col)){
			setItem(row, col, i);
			return;
		}
	}
}

void Board::place(DragonHoard *g){
	if(g == NULL){return;}
	int rm  = rand() % numRooms;
	int dRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dCol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	
	while(true){
	int tile = rand() % rmMax[rm];
	int row = getTileRow(rm, tile);
	int col = getTileCol(rm, tile);
		if(isValidSpawn(row, col)){
			//spawn dragon and gold
			if(hasEmptyNeighbor(row, col)){ 
				int loc;	
				while(true){	
					loc = rand() % 8;
					if(isValidSpawn(row + dRow[loc], col + dCol[loc])){
						setItem(row, col, g);
						setEnemy(row + dRow[loc], col + dCol[loc], g->dragon);
						return;		
					}
				}
			}
		}
	}
}

	
	
void Board::removeEnemy(int row, int col){
	if(getEnemy(row, col) != NULL && dynamic_cast<Dragon *>(getEnemy(row, col))){
		if(dynamic_cast<Dragon *>(getEnemy(row, col))->dh != NULL){		
			dynamic_cast<Dragon *>(getEnemy(row, col))->dh->dragon = NULL;
		}
	}
	delete getEnemy(row, col);	
	setEnemy(row, col, NULL);
}

void Board::removeItem(int row, int col){
	delete getItem(row, col);
	setItem(row, col, NULL);
}


Enemy * Board::generateEnemy(){
	int race = rand() % ENEMYDENOM;
	Enemy *e;
	race = ENEMYDIST[race];
	if(race == HUMAN){
		e = new Human();
	}else if(race == DWARF){
		e = new Dwarf();
	}else if(race == HALF){
		e = new Halfling();
	}else if(race == ELF){
		e = new Elf();
	}else if(race == ORC){
		e = new Orc();
	}else if(race == MERCH){
		e = new Merchant();
	}
	return e;
}

Potion * Board::generatePotion(){
	int type = rand() % POTIONDENOM;
	Potion *p;
	type = POTIONDIST[type];
	if(type == RHID){
		p = new RH();
	}else if(type == BAID){
		p = new BA();
	}else if(type == BDID){
		p = new BD();
	}else if(type == PHID){
		p = new PH();
	}else if(type == WAID){
		p = new WA();
	}else if(type == WDID){
		p = new WD();
	}
	return p;
}

Gold * Board::generateGold(){
	int type = rand() % GOLDDENOM;
	type = GOLDDIST[type];
	Gold *g;
	if(type == SMALL){
		g = new NormalGold(Gold::SMALL);
	}else if(type == NORM){
		g = new NormalGold(Gold::NORM);
	}else if(type == DHOARD){
		Dragon *d = new Dragon();
		DragonHoard *dh = new DragonHoard(d);
		d->dh = dh;
		place(dh);
		return NULL;
	}
	return g;
}

void Board::recFloor(bool *floor, int row, int col){
	floor[row * cols + col] = false;
	rmRow.push_back(row);		
	rmCol.push_back(col);	
	rmMax.at(numRooms)++;
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			if((row + i >= 0) && (row + i < rows) && (col + i >= 0) && (col + i < cols) && floor[(row + i) * cols + (col + j)] && (i != 0 || j != 0)){
				recFloor(floor, row + i, col + j);
			}
		}
	}
}
			 

void Board::generate(){
	//erase previous locations
	p->reset();
	if(!isFirst){
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				removeItem(i, j);
				removeEnemy(i, j);
			}
		}
		if(items != NULL){
			delete []items;
		}

		if(enemies != NULL){
			delete []enemies;
		}

		rmMax.clear();
		rmRow.clear();
		rmCol.clear();
		isFirst = false;
	}
	numRooms = 0;

	srand(time(NULL));
	//read in cells
	string path;
	if(floorData[floor] == ""){
		path = FLOORPATH;
	}else{
		path = floorData[floor];
	}

	ifstream dim(path.c_str(), ifstream::in);
	char c = dim.get();
	int numRows = 0;
	int numCols = 0;
	while(dim.good() && c != '\n'){
		numCols++;
		c = dim.get();
	}

	while(dim.good()){
		if(c == '\n'){
			numRows++;
		}
		c = dim.get();
	}

	//dim.close();
	rows = numRows;
	cols = numCols;	

	cells = new Cell *[rows * cols + 1];
	enemies = new Enemy *[rows * cols + 1];
	items = new Item *[rows * cols + 1];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cells[i * cols + j] = NULL;
		}
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			enemies[i * cols + j] = NULL;
		}
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			items[i * cols + j] = NULL;
		}
	}

	
	//Read in room data
	int row = 0;
	int col = 0;
	ifstream is(path.c_str(), ifstream::in);
	c = is.get();

	while(is.good()){
		if(c == '|' || c == '-' || c == '+' || c == '#'){
			Cell *ce = new Cell(c);
			setCell(row, col, ce);
		}else if(c == '\\'){
			sRow = row;
			sCol = col;
		}else if (c != ' '){
			Cell *ce = new Cell('.');
			setCell(row, col, ce);		
		}

		Item *i = NULL;
		if(c == '0'){
			i = new RH();
		}else if(c == '1'){
			i = new BA();
		}else if(c == '2'){
			i = new BD();
		}else if(c == '3'){
			i = new PH();
		}else if(c == '4'){
			i = new WA();
		}else if(c == '5'){
			i = new WD();
		}else if(c == '6'){
			i = new NormalGold(Gold::NORM);
		}else if(c == '7'){
			i = new NormalGold(Gold::SMALL);
		}else if(c == '8'){
			i = new NormalGold(Gold::MHOARD);
		}else if(c == '9'){
			//detect which dragon is the dragonhoards
			i = new DragonHoard(NULL);
		}
		setItem(row, col, i);
		Enemy *e = NULL;
		if(c == '@'){
			pRow = row;
			pCol = col;
		}else if(c == 'H'){
			e = new Human();
		}else if(c == 'W'){
			e = new Dwarf();
		}else if(c == 'E'){
			e = new Elf();
		}else if(c == 'O'){
			e = new Orc();
		}else if(c == 'M'){
			e = new Merchant();
		}else if(c == 'D'){
			e = new Dragon();
		}else if(c == 'L'){
			e = new Halfling();
		}/*else if(c == 'R'){	*/
		setEnemy(row, col, e);

		col++;
		if(c == '\n'){
			col = 0;
			row++;
		}
	
		c = is.get();
	}

	bool temp[rows * cols];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(cells[i * cols + j] == NULL){
				temp[i * cols + j] = false;
			}else{
				temp[i * cols + j] = (cells[i * cols + j]->getChar() == '.');
			}	
		}
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(temp[i * cols + j]){
				//helper recursion
				rmMax.push_back(0);
				recFloor(temp, i, j);
				numRooms++;
			}
		}
	}	

	//is.close();
	if(floorData[floor] == ""){
		//random generate player location
		int rm  = rand() % numRooms;
		int tile = rand() % rmMax[rm];
		pRow = getTileRow(rm, tile);
		pCol = getTileCol(rm, tile);
	
		//random generate stair location
		int stairRm = rand() % numRooms;
		while(rm == stairRm){stairRm = rand() % numRooms;}
		tile = rand() % rmMax[stairRm];
		sRow = getTileRow(stairRm, tile);
		sCol = getTileCol(stairRm, tile);

		//generate enemies
		for(int i = 0; i < NUMENEMIES; i++){
			place(generateEnemy());
		}

		//generate gold, spawn dragons
		for(int i = 0; i < NUMGOLD; i++){
			place(generateGold());
		}

		//generate potions
		for(int i = 0; i < NUMPOTIONS; i++){
			place(generatePotion());
		}
	}
	floor++;
	print();
}	

void Board::enemyTurn(){
	Enemy **enemyTemp = new Enemy *[rows * cols + 1];
	for(int i = 0; i < rows * cols + 1; i++){
		enemyTemp[i] = enemies[i];
	}
	Enemy *e;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			e = enemyTemp[i * cols + j];
			if(e != NULL){
				e->preTurn();
				int rowDiff = pRow - i;
				int colDiff = pCol - j;
				if(abs(rowDiff) <= 1 && abs(colDiff) <= 1){
					if(dynamic_cast<Dragon *>(e)){
						e->setHostile(true);
					}
					if(e->isHostile()){
						p->attackedBy(e);
						if(dynamic_cast<Elf *>(e)){
							p->attackedBy(e);
						}
					}
				}else{
					moveEnemy(e, i, j);
				}
				//getEnemy(i, j)->postTurn();
			}
		}
	}
	delete []enemyTemp;
}

bool Board::inSameRoom(int row1, int col1, int row2, int col2){
	int rm1;
	int rm2;
	bool found1 = false;
	bool found2 = false;
	for(int i = 0; i < numRooms; i++){
		for(int j = 0; j < rmMax.at(i); j++){
			if(!found1 && getTileRow(i, j) == row1 && getTileCol(i, j) == col1){
				rm1 = i;
				found1 = true;
			}
			if(!found2 && getTileRow(i, j) == row2 && getTileCol(i, j) == col2){
				rm2 = i;
				found2 = true;
			}
			if(found1 && found2){return rm1 == rm2;}
		}
	}
	return rm1 == rm2;
}

//current row col
void Board::moveEnemy(Enemy *e, int row, int col){
	if(((rand() % 10 > 5 - floor) || (dynamic_cast<Dragon *>(e))) && inSameRoom(pRow, pCol, row, col)){
		int rowDiff = pRow - row;
		int colDiff = pCol - col;
		if(rowDiff != 0){rowDiff /= abs(rowDiff);}
		if(colDiff != 0){colDiff /= abs(colDiff);}
		if(isValidEnemyMove(row + rowDiff, col + colDiff)){
			setEnemy(row + rowDiff, col + colDiff, e);
			setEnemy(row, col, NULL);
			return;
		}else{
			int rnd = rand() % 2;
			if(rnd == 0){
				if(isValidEnemyMove(row + rowDiff, col)){
					setEnemy(row + rowDiff, col, e);
					setEnemy(row, col, NULL);
					return;
				}else if(isValidEnemyMove(row, col + colDiff)){
					setEnemy(row, col + colDiff, e);
					setEnemy(row, col, NULL);
					return;
				}
			}else{
 				if(isValidEnemyMove(row, col + colDiff)){
					setEnemy(row, col + colDiff, e);
					setEnemy(row, col, NULL);
					return;
				}else if(isValidEnemyMove(row + rowDiff, col)){
					setEnemy(row + rowDiff, col, e);
					setEnemy(row, col, NULL);
					return;
				}
			}
		}
	}else{
		//non dragon pathing (Random)
		int rnd;
		int dRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
		int dCol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
		if(hasEmptyNeighbor(row, col)){
			while(true){
				rnd = rand() % 8;
				if(isValidEnemyMove(row + dRow[rnd], col + dCol[rnd])){
					setEnemy(row + dRow[rnd], col + dCol[rnd], e);
					setEnemy(row, col, NULL);
					return;
				}
			}
		}
	}
}


void Board::moveNextFloor(){
	generate();
	//add custom messages
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    " << p->getName() << " has made it to Floor " << floor << ". " << endl;
	out.close();
}

//player move
bool Board::move(int nRow, int nCol){
	if(attack(nRow, nCol)){return true;}
	if(isValid(nRow, nCol)){
		pRow = nRow;
		pCol = nCol;
		if(pRow == sRow && pCol == sCol){
			moveNextFloor();
		}else{
			ofstream out;
			out.open("action.txt", ios::app);
			out <<"    " << p->getName()  << " moved to location (" << nRow << ", " << nCol << "). " << endl;
			out.close();
		}
		//since isValid checks if potion
		//can assume if item is non-Null must be gold
		if(getItem(nRow, nCol) != NULL && (!dynamic_cast<DragonHoard *>(getItem(nRow, nCol)) || dynamic_cast<DragonHoard *>(getItem(nRow, nCol))->dragon == NULL)){
			getItem(nRow, nCol)->useOn(p);
			removeItem(nRow,nCol);
		}
		return true;
	}
	return false;
}


void Board::onDeath(Enemy *e, int row, int col){
	//fine to override right now since guaranteed enemy cant walk on potions and gold
	if(dynamic_cast<Human *>(e)){
		Item *i = new NormalGold(2 * Gold::NORM);
	  setItem(row, col, i);
	}else if(dynamic_cast<Merchant *>(e)){
		Item *i = new NormalGold(Gold::MHOARD);
	  setItem(row, col, i);
	}
	removeEnemy(row, col);
}
//player attack
bool Board::attack(int nRow, int nCol){
	if(getEnemy(nRow, nCol) != NULL){
		getEnemy(nRow, nCol)->attackedBy(p);
		if(getEnemy(nRow, nCol)->isDead()){
			onDeath(getEnemy(nRow, nCol), nRow, nCol);
		}
		return true;
	}
	return false;
}

//player use (for now only potions)
bool Board::use(int nRow, int nCol){
	if(getItem(nRow, nCol) != NULL && dynamic_cast<Potion *>(getItem(nRow, nCol))){
		getItem(nRow, nCol)->useOn(p);
		removeItem(nRow, nCol);
		return true;
	}
	return false;
}

//Assumes one command per turn
bool Board::playerTurn(char command, string dir){
	p->preTurn();

	int nRow = pRow;
	int nCol = pCol;
	if(dir == "no"){
		nRow--;
	}else if(dir == "ne"){
		nRow--;
		nCol++;
	}else if(dir == "ea"){
		nCol++;
	}else if(dir == "se"){
		nRow++;
		nCol++;
	}else if(dir == "so"){
		nRow++;
	}else if(dir == "sw"){
		nRow++;
		nCol--;
	}else if(dir == "we"){
		nCol--;
	}else if(dir == "nw"){
		nRow--;
		nCol--;
	}
	
	bool commandExecuted = false;
	if(command == MOVE){
		commandExecuted = move(nRow, nCol);
	}else if(command == ATK){
		commandExecuted = attack(nRow, nCol);
	}else if(command == USE){
		commandExecuted = use(nRow, nCol);
	}else if(command == SKILL1){
		if(p->s1->isTargetted()){
			commandExecuted = useSkill(command, nRow, nCol);
		}else{
			commandExecuted = useSkill(command);
		}
	}else if(command == SKILL2){
		if(p->s2->isTargetted()){
						commandExecuted = useSkill(command, nRow, nCol);
		}else{
			commandExecuted = useSkill(command);
		}
	}

	if(commandExecuted){
		p->postTurn();
	}else{
		cout << "Invalid input. Don't worry, I'm sure you'll get it on your next try =/" << endl;
	}
	return commandExecuted;
}

bool Board::useSkill(char command, int row, int col){
	if(command == SKILL1){
		cout << "skill called" << endl;
		return p->s1->useOn(p, getEnemy(row, col));
	}else if(command == SKILL2){
		return p->s2->useOn(p, getEnemy(row, col));
	}
	return false;
}
bool Board::useSkill(char command){
	if(command == SKILL1){
		p->s1->useOn(p);
		return true;
	}else if(command == SKILL2){
		p->s1->useOn(p);
		return true;
	}
	return false;
}

bool Board::hasEmptyNeighbor(int row, int col){
	int dRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dCol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	bool valid = false;
	for(int i = 0; i < 8; i++){
		valid = valid || isValid(row + dRow[i], col + dCol[i]);
	}
	return valid;
}

bool Board::isWin(){
	return (floor == NUMFLOORS);// && (pRow == sRow) && (pCol == sCol);
}

void Board::win(){
	cout << "Player Score: " << p->getScore() << endl;
	remove("action.txt");
}

bool Board::isGameOver(){
	return p->isDead();
}

void Board::gameOver(){
/*                for(int i = 0; i < rows; i++){
                        for(int j = 0; j < cols; j++){
                                removeItem(i, j);
                                removeEnemy(i, j);
                        }
                }
                if(items != NULL){
                        delete []items;
                }

                if(enemies != NULL){
                        delete []enemies;
                }

                rmMax.clear();
                rmRow.clear();
                rmCol.clear();
*/
	remove("action.txt");
	cout << "Player Score: " << p->getScore() << endl;
}

void Board::setPlayerName(string name){
	p->setName(name);
}

void Board::print(){
	cout << endl;
	Object *out[rows * cols];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			out[i * cols + j] = getCell(i, j);

			if(getItem(i, j) != NULL){
				out[i * cols + j] = getItem(i, j);
			}

			if(getEnemy(i, j) != NULL){
				out[i * cols + j] = getEnemy(i, j);
			}
		}
	}
	out[pRow * cols + pCol] = p;
	out[sRow * cols + sCol] = s;	

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(out[i * cols + j] == NULL){
				cout << ' ';
			}else{
				cout << out[i * cols + j]->getChar();
			}
		}
		cout << endl;
	}

	cout << "Race: " << p->getDesc() << " Gold: " << p->getGold() << "                                                Floor " << floor << endl;
	p->print();
	
}


