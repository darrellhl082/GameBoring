// Directive
#ifndef __LIB
#define __LIB
#define SLEEP 1000

// Include Library
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

// Namespace
using namespace std;
// Variable Declaration
extern bool enemy_check;
extern bool check_continue;
extern vector<string>nameList;
// Class Initialization / Prototype
class Weapon{
    private:
        string name;
        double power;
        double chance;
    public:
        Weapon(string, double, double);
        void display();
        // Getter
        string getName();
        double getPower();
        double getChance();
};

class Player{
    private:
        string name;
        char role;
        double health;
        Weapon* weapon;
        int kill = 0;
        int attPosition;
    public:
        Player(string, char);
        ~Player();
        void attack(Player* enemy);
        void damaged(Player* enemy, int position);
        bool avoid(Weapon *weapon, int position, string name);
        bool defence(Weapon *weapon, string name, int position);
        // getter
        string getName();
        double getHealth();
        string getWeapon();
        char getRole();
        // setter
        void equiptWeapon(Weapon *weapon);
};

// Function Initialization / Prototype
int randRange (int, int);
int chooseWeapon();
bool enemy_status();
bool is_continue();
void setWeapon(Player *player, int choose);

// Create Weapon

extern Weapon *palu;
extern Weapon *arit; 
extern Weapon *rasengan;
extern Weapon *ak47;
extern Weapon *gilette;

#endif