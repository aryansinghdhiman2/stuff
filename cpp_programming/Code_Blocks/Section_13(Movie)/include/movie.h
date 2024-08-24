#ifndef MOVIE_H
#define MOVIE_H
#include <string>

enum rating {G=0,PG=1,PG_13=2,R=3};
class movie
{
    private:
        std::string name;
        enum rating movie_rating;
        int num_watch;

    public:
        movie(std::string str,enum rating rat,int num);
        std::string get_name() const;
        enum rating get_rating() const;
        int get_num_watch() const;
        std::string set_name(const std::string str);
        enum rating set_rating(const enum rating source);
        int inc_num_watch();
        movie(const movie &src);
        void display();
};

#endif // MOVIE_H
