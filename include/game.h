#pragma once
#include <string>
#include "plant.h"

// Game lifecycle
std::string getusername();
void menu(int& money, int (&storage)[6], plant* (&plants)[4][4]);
void help();

// Economy
bool poor(int& money, int price);
void sell(int& money, int (&storage)[6]);
void Fsell(int& price, int& money, int& type, int (&storage)[6], int& quantity);

// Plants / grid
void buy(int& money, plant* (&plants)[4][4]);
void Fbuy(char type, plant* (&plants)[4][4]);
bool anyempty(plant* (&plants)[4][4]);
void showplants(plant* (&plants)[4][4]);
void store(char type, int (&storage)[6]);
void GoEat(int& money, plant* (&plants)[4][4]);
