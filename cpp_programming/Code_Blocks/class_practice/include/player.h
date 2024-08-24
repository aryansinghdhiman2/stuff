#ifndef PLAYER_H
#define PLAYER_H
#include <string>
class player
{
    private:
        //attributes
        std::string* name;
        int health;
    public:
        //methods
        std::string get_name();
        int get_health();
        void set_name(std::string g);
        void set_health(int a);
        //constructor and destructor
        player();
        player(std::string,int);
        player(const player &source);
        ~player();
};

#endif // PLAYER_H
