#ifndef INHERITANCE_H
#define INHERITANCE_H
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Player{
    protected:
        string player_name;
        string character_name;
        string class_type;
        double health;
        double mana;
        int level;
        string skill;
    private:
        static int total_player;

    public:
        Player(
            string player_name = "Unknown",
            string character_name = "Unknown",
            string class_type = "Unknown",
            double health = 0,
            double mana = 0,
            int level = 1,
            string skill = "Not learn yet"
        );
        void display_info() const;
        void increase_total_player();
        static void display_total_player(); 
};

class Human: public Player{
    private:
        int intelligent;
    public:
        Human(
            string player_name,
            string character_name,
            string class_type,
            double health,
            double mana,
            int level,
            string skill
        );
        void display_info() const;
};

class Monster: public Player{
    private:
        int strength;
    public:
        Monster(
            string player_name,
            string character_name,
            string class_type,
            double health,
            double mana,
            int level,
            string skill
        );
        void display_info() const;
};

class Angel: public Player{
    private:
        int blessing;
    public:
        Angel(
            string player_name,
            string character_name,
            string class_type,
            double health,
            double mana,
            int level,
            string skill
        );
        void display_info() const;
};

#endif 
