#include "ellipse_helper.hpp"

ellipseData readRow(CSVHandler &handler)
{
    auto result = handler.readRowAndSplit();
    
    if(result.size()!=8) throw int(-1);

    double c_x = std::stod(result.at(0));
    double c_y = std::stod(result.at(1));
    double r_x = std::stod(result.at(2));
    double r_y = std::stod(result.at(3));
    std::string pat = result.at(4);
    int red = std::stoi(result.at(5));
    int blue = std::stoi(result.at(6));
    int green = std::stoi(result.at(7));

    return ellipseData(c_x,c_y,r_x,r_y,pat,red,blue,green);
}

std::vector<ellipseData> readFile(CSVHandler& handle,const int& number_of_lines_to_ignore)
{
    auto data = handle.readFile();
    std::vector<ellipseData> ellipses;
    ellipses.reserve(data.size());

    for(int i = 0;i<int(data.size())-number_of_lines_to_ignore;i++)
    {
        double c_x = std::stod(data.at(i).at(0));
        double c_y = std::stod(data.at(i).at(1));
        double r_x = std::stod(data.at(i).at(2));
        double r_y = std::stod(data.at(i).at(3));
        std::string pat = data.at(i).at(4);
        int red = std::stoi(data.at(i).at(5));
        int blue = std::stoi(data.at(i).at(6));
        int green = std::stoi(data.at(i).at(7));

        ellipses.emplace_back(c_x,c_y,r_x,r_y,pat,red,blue,green);
    }

    return ellipses;
}