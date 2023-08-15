#include <iostream>
#include <string>
#include <vector>
#include<windows.h>
#include "lib.hpp"

using namespace std;

int randRange (int low, int high)
{
    return (rand() % high) +low;
}
int chooseWeapon(){
    int choose;
    cout << "Choosing Weapon" << endl;
    Sleep(SLEEP);
    cout << "===========================" << endl;
    cout << "Weapons List: " << endl;
    cout << "-Number 1" << endl;
    palu->display();
    cout << endl;
    cout << "-Number 2" << endl;
    arit->display();
    cout << endl;
    cout << "-Number 3" << endl;
    rasengan->display();
    cout << endl;
    cout << "-Number 4" << endl;
    ak47->display();
    cout << endl;
    cout << "-Number 5" << endl;
    gilette->display();
    cout << endl;
    cout << "Choose your weapon (1-5): ";
    cin >> choose;
    return choose;
}
bool enemy_status(){
    bool check = enemy_check;
    return check;
};
bool is_continue(){
    char check;
    label_continue:
    cout << "Play Again? (y/n): ";
    cin >> check;
    if(check == 'y' || check == 'Y'){
        check = true;
    } else if(check == 'N' || check == 'n'){
        check = false;
    } else {
        cout << "WTF, STUPID" << endl;
        goto label_continue;
    }
    return check;
}

void setWeapon(Player *player, int choose){
    enum option{PALU = 1, ARIT, RASENGAN, AK47, GILETTE};
    switch (choose)
    {
    case PALU:
        player->equiptWeapon(palu);
        break;
    case ARIT:
        player->equiptWeapon(arit);
        break;
    case RASENGAN:
        player->equiptWeapon(rasengan);
        break;
    case AK47:
        player->equiptWeapon(ak47);
        break;
    case GILETTE:
        player->equiptWeapon(gilette);
        break;
    
    default:
        cout << "STUPID" << endl;
        break;
    }
 
}

Weapon::Weapon(string name, double power, double chance){
    this->name = name;
    this->power = power;
    this->chance = chance;
}
void Weapon::display(){
    cout << "====Weapon specification====" << endl;
    cout << "Name      : " << this->name << endl;
    cout << "Power     : " << this->power << " per damage" << endl;
    cout << "Hit Chance: " << this->chance *100 << "%" << endl;
}
       
string Weapon::getName(){
    return this->name;
}
double Weapon::getPower(){
    return this->power;
}
double Weapon::getChance(){
    return this->chance;
}

Player::Player(string  name, char role){
    this->name = name;
    this->role = role;
    this->health = 100;
    cout << this->name << " In the arena" << endl;
}
Player::~Player(){
    cout << this->name << " died" << endl;
}
void Player::attack(Player* enemy){
    int choose;
    int range = (1 / this->weapon->getChance() );
    if(this->role == 'C'){
        choose = randRange(1,range);
    } else {
        cout << endl;
        cout << "It's your turn now!, Fire!Fire!Fire!" << endl;
        Label_Choose:
        cout << "Available targets in the range 1-" << range << "\nChoose target: ";
        cin >> choose; 
        if(choose > range){
            goto Label_Choose;
        }
    }
    Sleep(500);
    damaged(enemy, choose);
}
void Player::damaged(Player* enemy, int position){
    if(this->health <= 0){
        cout << this->name << " Has died" << endl;
    } else {
        if(enemy->defence(this->weapon, this->name, position) == false){
            if(enemy->getHealth() <= 0){
                cout << enemy->getName() << " health is 0" << endl; 
            } else {
                cout << enemy->getName() << " health is " << enemy->getHealth() << endl; 
            }
    };
    Sleep(500);
        if(enemy->getHealth() <= 0){
            if(enemy->getRole() == 'C'){
                this->kill++;
                delete enemy;
                cout << "You Win!!" << endl;
                cout << this->name << " has killed " << this->kill << " enemies" << endl << endl;
                check_continue = is_continue();  
                enemy_check = false;
            } else {
                cout << "You die, you lose" << endl;
                delete this;
                check_continue = false;
            }
        }
    }
}
bool Player::avoid(Weapon *weapon, int position, string name){
    int range = 1 / weapon->getChance();
    int choose;
    bool status = false;
    if(this->role == 'C'){
        choose = randRange(1,range);
        cout << this->name << " goes to " << choose << endl;
    } else {
        cout << endl;
        cout << name << " is attacking, RUN!!RUN!" << endl;
        Label_Choose:
        cout << "Available positions in the range 1-" << range << " Go to: ";
        cin >> choose; 
        if(choose > range){
            cout << "Out of range!!!" << endl;
            goto Label_Choose;
        }
        cout << "Enemy strikes " << position << endl;
    }
    Sleep(500);
    if(position == choose){
        status = false;
    } else {
         status = true;
    }
    return status;
}
bool Player::defence(Weapon *weapon, string name, int position){
    bool status = false;
    if(this->avoid(weapon, position, name) == false){
        this->health-=weapon->getPower();
        cout << this->name << " damaged " << weapon->getPower() << " by " << name << " using " << weapon->getName() << endl;
        if(this->health <=0){
            cout << this->name << " died" << endl;
        } 
    } else {
        cout << this->name << " safe" << endl;
        status = true;
    }
        return status;
}
// getter
string Player::getName(){
    return this->name;
}
double Player::getHealth(){
    return this->health;
}
string Player::getWeapon(){
    return this->weapon->getName();
}
char Player::getRole(){
    return this->role;
}
// setter
void Player::equiptWeapon(Weapon *weapon){
    this->weapon = weapon;
    cout << this->name << " equipped " << weapon->getName() << endl;
}