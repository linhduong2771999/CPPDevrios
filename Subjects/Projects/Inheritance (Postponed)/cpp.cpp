#include "header.h"

int Player::total_player = 0;

void Player::increase_total_player(){
    total_player++;
}
 void Player::display_total_player(){
    cout << total_player << endl;
}

Player::Player(
    string player_name,
    string character_name,
    string class_type,
    double health,
    double mana,
    int level,
    string skill) : player_name{player_name},
                    character_name{character_name},
                    class_type{class_type},
                    health{health},
                    mana{mana},
                    level{level},
                    skill{skill}
{
    increase_total_player();
}

void Player::display_info() const {
    cout << "Your Player info: " << endl;
    cout << player_name << endl;
    cout << character_name << endl;
    cout << class_type << endl;
    cout << health << endl;
    cout << mana << endl;
    cout << level << endl;
    cout << skill << endl;
}   



Human::Human(
    string player_name,
    string character_name,
    string class_type,
    double health,
    double mana,
    int level,
    string skill
): Player {player_name,character_name, class_type, health, mana, level, skill} {
}

void Human::display_info() const {
    Player::display_info();
}

Monster::Monster(
    string player_name,
    string character_name,
    string class_type,
    double health,
    double mana,
    int level,
    string skill
): Player {player_name,character_name, class_type, health, mana, level, skill} {
}

void Monster::display_info() const {
    Player::display_info();
}

Angel::Angel(
    string player_name,
    string character_name,
    string class_type,
    double health,
    double mana,
    int level,
    string skill
): Player {player_name,character_name, class_type, health, mana, level, skill} {
}

void Angel::display_info() const {
    Player::display_info();
}


