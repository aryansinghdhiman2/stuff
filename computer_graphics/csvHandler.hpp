#ifndef _CSV_HANDLER_

#define _CSV_HANDLER_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class CSVHandler
{
    private:
        std::string fileName;
        std::fstream csvFile;
        std::vector<std::string> outputVector;
        std::string outputStr;
    public:
        CSVHandler(std::string fileName):fileName(fileName)
        {
            this->csvFile.open(this->fileName,std::ios::in | std::ios::out | std::ios::trunc);
        }
        ~CSVHandler()
        {
            this->csvFile.close();
        }
        const std::vector<std::string> readRowAndSplit();
        const std::vector<std::vector<std::string>> readFile();
		template <typename T>
		void writeToCSV(T t)
		{
			this->csvFile<<t<<std::endl;
            this->csvFile.flush();
		}

		template<typename T, typename ...Args>
		void writeToCSV(T t, Args... args)
		{
			this->csvFile<<t<<',';
			writeToCSV(args...);
		}

        void clearFile()
        {
            this->csvFile.close();
            this->csvFile.open(this->fileName,std::ios::in | std::ios::out | std::ios::trunc);
        }

        const int getNumberOfLines()
        {
            int num_of_lines = 0;
            std::string temp_str;
            this->csvFile.seekg(csvFile.beg);
            while(std::getline(this->csvFile,temp_str))
            {
                ++num_of_lines;
            }
            return num_of_lines;
        }

};

#endif
