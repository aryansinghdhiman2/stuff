#include "./CSVHandler.hpp"

const std::vector<std::string> CSVHandler::readRowAndSplit()
{
    this->outputVector.clear();
    
    if(this->csvFile.peek()==EOF) 
        return outputVector;
    
    std::getline(this->csvFile,this->outputStr);
    std::string::size_type beginPos = 0;
    std::string::size_type endPos = 0;
    while((endPos=this->outputStr.find(',',endPos))!=std::string::npos)
    {
        this->outputVector.push_back(this->outputStr.substr(beginPos,endPos-beginPos));
        beginPos = endPos = endPos + 1;
    }
    this->outputVector.push_back(this->outputStr.substr(beginPos,this->outputStr.length()-beginPos));
    return outputVector;
    
}

const std::vector<std::vector<std::string>> CSVHandler::readFile()
{
    this->csvFile.clear();
    this->csvFile.seekg(csvFile.beg);

    std::vector<std::vector<std::string>> data;

    while(true)
    {
        auto row = this->readRowAndSplit();
        if(row.empty()) break;

        data.push_back(row);
    }
    this->csvFile.clear();
    return data;
}