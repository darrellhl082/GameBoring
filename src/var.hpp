#include <iostream>
#include <string>
#include <vector>
#include "lib.hpp"
using namespace std;

// Variable Declaration
bool enemy_check;
bool check_continue;
vector<string>nameList ={"Jisoo", "Ning Ning", "Wendy", "Yujin", "Gaeul", "Rei", "Karina", 
"Winter", "Giselle", "Seulgi", "Irene","Liz", "Leeso","Wonyoung","Darrell"};
Weapon *palu= new Weapon("Palu",10,0.25);
Weapon *arit = new Weapon("Arit",50,0.1);
Weapon *rasengan = new Weapon("Rasengan",20,0.3);
Weapon *ak47 = new Weapon("Ak-47",30,0.2);
Weapon *gilette = new Weapon("Gilette",40,0.05);