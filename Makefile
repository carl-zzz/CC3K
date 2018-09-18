#!/bin/bash

COMPILER = g++
OPTION = -Wall -g -MMD -lX11
PROBLEM = cc3k
OBJECTS = main.o ba.o bd.o board.o cell.o character.o dragon.o dragonhoard.o goblin.o dwarf.o elf.o enemy.o drow.o gold.o halfling.o human.o item.o merchant.o normalgold.o object.o orc.o ph.o player.o potion.o rat.o rh.o shade.o troll.o vampire.o wa.o wd.o skill.o valkyrie.o assassin.o berserker.o god.o
DEPENDS = ${OBJECTS:.o=d}

${PROBLEM}: ${OBJECTS}
	${COMPILER}  ${OPTION} ${OBJECTS} -o ${PROBLEM}
-include ${DEPENDS}
.PHONY: clean
clean:
	rm ${OBJECTS} ${PROBLEM} ${DEPENDS}
