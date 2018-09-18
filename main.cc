#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "board.h"
#include <fstream>
using namespace std;

bool isDirectional(string s){
	return((s == "no") || (s == "so") || (s == "ea") || (s == "we") || (s == "ne") ||(s == "nw") || (s == "se") || (s == "sw"));
}

int main (int argc, char* argv[]) {
	ifstream in("dinosaur.txt");
	for (string str; getline(in,str);)
		cout << str << endl;
	
	cout << "Press Enter To Continue: " << endl;
	string s;
	getline(cin,s);

	srand(rand() % 10000);
	bool first = true;
	bool qMove = true;
	string temp;
	Board *board;
	if(argc == 2){
		for(int i = 0; i < 5; i++){
			board->floorData[i] = argv[1];
		}
	}
	fstream f("action.txt",ios::out);
	f.close();
	do {
		if (first) {

			cout << "WELCOME TO CHAMBERCRAWLER3000!" << endl;
			cout << "RACES: " << endl;
			cout << "                HP  ATK  DEF  MP     Description" << endl;
			cout << "s  Shade     ( 125,  25,  25, 20)  - The industry standard. Gets 1.5 the score." << endl << endl;
			cout << "d  Drow      ( 150,  25,  15, 20)  - Meds + Alcohol: 50% amplified potion effects." << endl;
			cout << "                                    EV = 1.5 * (10hp-10hp + 5atk-5atk + 5def-5def) = 1.5 (0hp + 0atk + 0def)" << endl;
			cout << "                                    Higher variance: If you're feeling lucky, go for it." << endl << endl;
			cout << "v  Vampire   (  50,  25,  25, 25)  - Blood is a valuable resource. Good thing you can acquire more: +5hp on successful attack." << endl << endl;
			cout << "t  Troll     ( 120,  25,  15, 10)  - Kill enemies. Run circles. Win game. Simple as that. +5hp per turn." << endl << endl;
			cout << "g  Goblin    ( 110,  15,  20, 15)  - Kill the weak, run from the strong. Selling dead corpses since 1980. +5 gold from kills" << endl;
			cout << "                                    \"But I only had 2 gold...\" ~Dwarf's last words~" << endl << endl;
			cout << "k  Valkyrie  (  50,   5, 200, 50)  - Wow this armor is heavy: -20% dodge change. My attack sucks, I need more MP: +3MP on basic attack. +1MP upon being hit." << endl;
			cout << "                                    I'm a Valkyrie after all: Starts out with Divine Strike and Heal. " << endl << endl;
			cout << "a  Assassin  (  20,  20,  10, 20)  - Tankiness is relative: Dodge Change 90%. Assassins are Skilled: Attacks twice. " << endl;
			cout << "                                    We live on the edge: Lethal attacks when above 1 hp leave you at 1 hp."  << endl;
			cout << "                                    \"I keep getting 3 shot...\"" << endl << endl;
			cout << "b  Berserker (  80,  30,  15, 10)  - Losing blood makes you see red. Duh: +1Atk per hp lost " << endl;
			cout << "                                    Slaying enemies pleases you: +5hp on kill." << endl << endl;
			cout << "x  God       (  1 ,  0 ,-101,  0)  - My name is Nomair Naeem: My power is limitless." << endl ;
			cout << "                                    Customized skills and death messages." << endl << endl;
			cout << "r  Random Race" << endl << endl;
			string race;
			int raceNum = 0;
			cout << "Please choose your race: " << endl;

			getline(cin,race);
			if (race == "s") cout << "SHADE was chosen. " << endl;
			else if (race == "d") {cout << "DROW was chosen. " << endl; raceNum = 1;}
			else if (race == "v") {cout << "VAMPIRE was chosen. " << endl; raceNum = 2;}
			else if (race == "t") {cout << "TROLL was chosen. " << endl; raceNum = 3;}
			else if (race == "g") {cout << "GOBLIN was chosen. " << endl; raceNum = 4;}
			else if (race == "q") {cout << "GAME OVER! Devs: 1 You: 0" << endl; return 0;}
			else if (race == "k") {cout << "VALKYRIE was chosen. " << endl; raceNum = 5;}
			else if (race == "a") {cout << "ASSASSIN was chosen. " << endl; raceNum = 6;}
			else if (race == "b") {cout << "BERSERKER was chosen. " << endl; raceNum = 7;}
			else if (race == "x") {cout << "Welcome Nomair. " << endl; raceNum = 8;}
			else if (race == "r") {cout << "Random race was chosen for you" << endl; raceNum = rand() % 9;}
			else cout << "Race not found! The default race SHADE is chosen. " << endl;
		
			// NAME INPUT
			string name;
			if(raceNum != 8){
				cout << "Please enter your name: ";			
				getline(cin,name);
			}else{
				name = "Nomair";
			}
		
			board = new Board(raceNum, name);
			//board->setPlayerName(name);

			first = false;
		}

		string buffer;
		char cmd;
		string dir;
		char c;
		bool validMove = false;
		bool waiting = false;
		bool skillwaiting = false;
		while(true){
			ofstream f;
			f.open("action.txt", std::ofstream::out | std::ofstream::trunc);
			f.close();
			cout << endl << "Please enter command(s). Does not have to be space separated: ";
			getline(cin, buffer);
			cmd = 'X';
			waiting = false;
			skillwaiting = false;
			while(buffer.length() >= 1){
				validMove = false;
				//if still waiting for a directional dont reset command
				if(!waiting && !skillwaiting){				
					cmd = 'X';
				}
				dir = "";
				//ignore whitespace
				while(buffer.at(0) == ' '){
					buffer.erase(0, 1);
				}
		
				//cardinal direction movement
				if(buffer.length() >= 4 && buffer.substr(0, 4) == "quit"){
					board->gameOver();
					delete board;
					return 0;
				}else if(buffer.length() >= 2 && isDirectional(buffer.substr(0, 2))){
					if(!waiting && !skillwaiting){					
						cmd = Board::MOVE;
					}else{
						waiting = false;
						skillwaiting = false;
					}
					dir = buffer.substr(0, 2);
					buffer.erase(0, 2);
				}else{
					if(!waiting){
						c = buffer.at(0);
						buffer.erase(0, 1);
					}
					//  qwe
					//  a d  
					//  zsc <= 'x' can also be used as downward movement
					if(c == 'a'){
						if(skillwaiting){
							dir = "we";
							skillwaiting = false;
						}else if((cmd == Board::ATK && dir == "" ) || buffer.length() == 0){
							cmd = Board::MOVE;
							dir = "we";
							waiting = false;
						}else{
							cmd = Board::ATK;
							waiting = true;
						}
					}else if(c == 'q'){
						if(!qMove){
							board->gameOver();
							delete board;
							return 0;
						}
						if(!skillwaiting){
							cmd = Board::MOVE;
						}else{
							skillwaiting = false;
						}
						dir = "nw";
					}else if(c == 'w'){
						if(!skillwaiting){
							cmd = Board::MOVE;
						}else{
							skillwaiting = false;
						}
						dir = "no";
					}else if(c == 'e'){
						if(!skillwaiting){
							cmd = Board::MOVE;
						}else{
							skillwaiting = false;
						}
						dir = "ne";
					}else if(c == 'd'){
						if(!skillwaiting){
							cmd = Board::MOVE;
						}else{
							skillwaiting = false;
						}
						dir = "ea";
					}else if(c == 'c'){
						if(!skillwaiting){
							cmd = Board::MOVE;
						}else{
							skillwaiting = false;
						}
						dir = "se";
					}else if(c == 's' || c == 'x'){
						if(!skillwaiting){
							cmd = Board::MOVE;
						}else{
							skillwaiting = false;
						}
						dir = "so";
					}else if(c == 'z'){
						if(!skillwaiting){
							cmd = Board::MOVE;
						}else{
							skillwaiting = false;
						}
						dir = "sw";
					}else if(c == 'u'){
						if(cmd == Board::USE && dir == "" || buffer.length() == 0){
							cmd = 'X';
							cout << "Direction for use \"" << buffer.substr(0, 2) << " \"is invalid. \"" << buffer.substr(0,2) << "\" will continue to be used in the input buffer." << endl;
							skillwaiting = false;
						}else{
							cmd = Board::USE;
							skillwaiting = true;
						}
					}else if(c == 'i'){
						//inventory					
					}else if(c == 'h'){
						cout << "Welcome to CC3K! Here's a quick rundown." << endl;
						cout << "**********************************************************" << endl;
						cout << "* Controls *" << endl;
						cout << "************" << endl;
						cout << "   no, ne, etc.. -Cardinal directional movement" << endl << endl;

						cout << "   q  w  e " << endl;
						cout << "   a     d       - Additional movement keys. Moving onto an enemy will now also attack them." << endl;
						cout << "   z s/x c          Can be combined with use(u) and skill(1,2) command." << endl << endl;

						cout << "   u + [dir.]    - Attempt to use the item in the direction specified." << endl;
						cout << "   1 / 2         - Use skill 1 / 2. If the skill is targetted, specify a direction." << endl << endl;
						cout << "   Note: -Invalid moves and input will be ignored." << endl;
						cout << "         -Multiple commands can be entered. They do not have to be space separated." << endl;
						cout << endl;
						cout << "**********************************************************" << endl;
						cout << "* Skills *" << endl;
						cout << "**********" << endl;
						cout << "   Heal          - Self-Explanatory." << endl;
						cout << "   Divine Strike - Deal Damage and Heal for Half." << endl;
						cout << endl;
						cout << "**********************************************************" << endl;
						cout << "* Mechanics *" << endl; 
						cout << "*************" << endl;
						cout << "   Dodging       - Chance to not take damage when attacked. Most players dodge 50% of the time" << endl;
						cout << "   Damage        - Damage(Defender) = ceiling((100 / (100 + Def(Defender))) * Atk(Attacker))" << endl;
						cout << "   Winning       - Make it to the stair on floor 5. Alive." << endl;
						cout << endl;
						cout << "**********************************************************" << endl;
						cout << "* Classes *" << endl;
						cout << "**********" << endl;
						cout << "                HP  ATK  DEF  MP     Description" << endl;
						cout << "s  Shade     ( 125,  25,  25, 20)  - The industry standard. Gets 1.5 the score." << endl << endl;
						cout << "d  Drow      ( 150,  25,  15, 20)  - Meds + Alcohol: 50% amplified potion effects." << endl;
						cout << "                                    EV = 1.5 * (10hp-10hp + 5atk-5atk + 5def-5def) = 1.5 (0hp + 0atk + 0def)" << endl;
						cout << "                                    Higher variance: If you're feeling lucky, go for it." << endl << endl;
						cout << "v  Vampire   (  50,  25,  25, 25)  - Blood is a valuable resource. Good thing you can acquire more: +5hp on successful attack." << endl << endl;
						cout << "t  Troll     ( 120,  25,  15, 10)  - Kill enemies. Run circles. Win game. Simple as that. +5hp per turn." << endl << endl;
						cout << "g  Goblin    ( 110,  15,  20, 15)  - Kill the weak, run from the strong. Selling dead corpses since 1980. +5 gold from kills" << endl;
						cout << "                                    \"But I only had 2 gold...\" ~Dwarf's last words~" << endl << endl;
						cout << "k  Valkyrie  (  50,   5, 200, 50)  - Wow this armor is heavy: -20% dodge change. My attack sucks, I need more MP: +3MP on basic attack. +1MP upon being hit." << endl;
						cout << "                                    I'm a Valkyrie after all: Starts out with Divine Strike and Heal. " << endl << endl;
						cout << "a  Assassin  (  20,  20,  10, 20)  - Tankiness is relative: Dodge Change 90%. Assassins are Skilled: Attacks twice. " << endl;
						cout << "                                    We live on the edge: Lethal attacks when above 1 hp leave you at 1 hp."  << endl;
						cout << "                                    \"I keep getting 3 shot...\"" << endl << endl;
						cout << "b  Berserker (  80,  30,  15, 10)  - Losing blood makes you see red. Duh: +1Atk per hp lost " << endl;
						cout << "                                    Slaying enemies pleases you: +5hp on kill." << endl << endl;
						cout << "x  God       (  1 ,  0 ,-101,  0)  - My name is Nomair Naeem: My power is limitless." << endl ;
						cout << "                                    Customized skills and death messages." << endl << endl;
					}else if(c == '1'){
						if(board->getPlayerSkill(1) == NULL){
							cout << "You have no skill in this slot." << endl;
						}else{
							//non directional skills
							if(cmd == Board::SKILL1 && board->getPlayerSkill(1)->isTargetted()){
								if(dir == "" || buffer.length() == 0){
									cmd = 'X';
									cout << "Need a direction for this skill, try again." << endl;
									skillwaiting = false;
								}
							}else{
								cmd = Board::SKILL1;
								if(board->getPlayerSkill(1)->isTargetted()){
									skillwaiting = true;
								}
							}
						}
					}else if(c == '2'){
						if(board->getPlayerSkill(2) == NULL){
							cout << "You have no skill in this slot." << endl;
						}else{
							//non directional skills
							if(cmd == Board::SKILL2 && board->getPlayerSkill(2)->isTargetted()){
								if(dir == "" || buffer.length() == 0){
									cmd = 'X';
									cout << "Need a direction for this skill, try again." << endl;
									skillwaiting = false;
								}
							}else{
								cmd = Board::SKILL2;
								if(board->getPlayerSkill(2)->isTargetted()){
									skillwaiting = true;
								}
							}
						}
					}else if(c == 'r'){
						first = true;
						break;
					}
				}
				if(first){
					break;
				}
				if(board->isWin()){
                                                        board->win();
                                                        while(1) {
                                                                cout << endl << "Would you like to play again? (Y or N)" << endl;
                                                                string cont;
                                                                getline(cin, cont);
                                                                if(cont == "Y"){
                                                                        first = true;
                                                                        break;
                                                                }else if(cont == "N"){
									delete board;
                                                                        return 0;
                                                                }else continue;
                                                        }
                                }

				//if valid command and command valid/executed, then enemy turn and print
				if(cmd != 'X' && !waiting && !skillwaiting){
					if(board->playerTurn(cmd, dir) || validMove){
						board->enemyTurn();
						board->print();
						if(board->isGameOver()){
							board->gameOver();
							while(1) {
								cout << endl << "Would you like to play again? (Y or N)" << endl;
								string cont;
								getline(cin, cont);
								if(cont == "Y"){
									first = true;
									break;
								}else if(cont == "N"){
									delete board;
									return 0;
								}else continue;
							}
						}else if(board->isWin()){
							board->win();
							while(1) {
								cout << endl << "Would you like to play again? (Y or N)" << endl;
								string cont;
								getline(cin, cont);
								if(cont == "Y"){
									first = true;
									break;
								}else if(cont == "N"){
									delete board;
									return 0;
								}else continue;
							}
						}
					}

				}	
			if(first){
				break;
			}
		}
			if(first){
				break;
			}
		}

			/*
			if ((temp == "no") || (temp == "so") || (temp == "ea") || (temp == "we") || (temp == "ne") ||
			    (temp == "nw") || (temp == "se") || (temp == "sw")) {
				if(cmd == 'X'){
					cmd = Board::MOVE;
				}
			}else if (temp == "a") {
				cmd = Board::ATK;
				cin >> temp;
			}else if (temp == "u") {
				cmd = Board::USE;
				cin >> temp;
			}else if (temp == "r") {
				first = true;
				break;
			}else if (temp == "q") {
				board->gameOver();
				break;
			}else {
				cmd = 'X';
				temp = "invalid";
			}

		}while(!board->playerTurn(cmd, temp));*/
		//cout <<"enemy turn stuff" << endl;
		//board->enemyTurn();
		//board->print();
		//cout << "error in enemy turn" << endl;


	}while (true);
}
