#ifndef _ELLIPSE_HELPER_

#define _ELLIPSE_HELPER_

#include "../csvHandler.hpp"
#include <vector>
#include <string>

struct pointPair {
    double x;
    double y;
    pointPair(double a,double b): x(a),y(b) {}
    pointPair(): x(0),y(0) {}

};

struct ellipseData
{
    pointPair center;
    double radius_x;
    double radius_y;
    std::string pattern;
    int red;
    int blue;
    int green;
    ellipseData(pointPair center,
                double r_x,
                double r_y,
                std::string pattern,
                int red,
                int blue,
                int green)
                :
                center(center),
                radius_x(r_x),
                radius_y(r_y),
                pattern(pattern),
                red(red),
                green(green),
                blue(blue)
    {

    }
    ellipseData(double center_x,
                double center_y,
                double r_x,
                double r_y,
                std::string pattern,
                int red,
                int blue,
                int green)
                :
                center(center_x,center_y),
                radius_x(r_x),
                radius_y(r_y),
                pattern(pattern),
                red(red),
                green(green),
                blue(blue)
    {
        
    }
};  

ellipseData readRow(CSVHandler& handler);
std::vector<ellipseData> readFile(CSVHandler& handle,const int& number_of_lines_to_ignore);
#endif