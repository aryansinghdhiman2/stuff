#ifndef MOVIES_H
#define MOVIES_H
#include <vector>
#include "movie.h"

class movies
{
    private:
        std::vector<movie> list;
    public:
        bool add_mov(std::string,rating,int);
        int inc_mov(std::string);
        void display_all();
};

#endif // MOVIES_H
