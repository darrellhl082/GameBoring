#include <iostream>
#include "var.hpp"
#include "lib.hpp"

using namespace std;

int main(int argc, char const *argv[])
{   
    label_start:
    system("cls");
    string name;
    int choose;
    check_continue = true;
    // Greeting
    cout << "=============================" << endl;
    cout << "     Welcome to The Game" << endl;
    cout << "=============================" << endl;
    cout << "Input name: ";
    cin >> name;
    cout << "Entering The Battlefield" << endl;
    Sleep(SLEEP);
    cout << "In" << endl;
    Sleep(SLEEP);
    cout << "3" << endl;
    Sleep(SLEEP);
    cout << "2" << endl;
    Sleep(SLEEP);
    cout << "1" << endl;
    Sleep(SLEEP);
    system("cls");
    Player* player = new Player(name,'P');
    Sleep(SLEEP);
    Player* computer= new Player(nameList[randRange(1,10)],'C');
    Sleep(SLEEP);
    choose = chooseWeapon();
    Sleep(SLEEP);
    cout<< "Battle start in" << endl;
    for(int i = 5; i>0;i--){
        cout << i << endl;
        Sleep(SLEEP);
    }
    system("cls");
    setWeapon(player, choose);
    Sleep(SLEEP);
    setWeapon(computer, randRange(1,5));
    Sleep(SLEEP);

    // Main Loop
    while(check_continue){
        check_continue = true;
        enemy_check = true;
        player->attack(computer);
        if(!check_continue){
            break;
        }
        if(!enemy_check){
            cout << endl;
            Player* computer= new Player(nameList[randRange(1,10)],'C');
            setWeapon(computer, randRange(1,5));
        }
        computer->attack(player);
    }
    // end
    Sleep(SLEEP);
    cout << "Game Over" << endl;
    Sleep(SLEEP);
    system("cls");
    cout << "===========================" << endl;
    cout << "        Thank you" << endl;
    cout << "===========================" << endl;
    cin.get();
    return 0;
}


