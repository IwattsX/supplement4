#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "csv_file_utils.h"

/**
 * @brief Gets the next 10 numbers of a number as a comma delimited string
 * 
 * @param num starting point
 * @return std::string a comma delimited string of the next 10 numbers
 */
std::string next_ten_nums(const int num){
    std::string res = "";

    for(int i = 1; i <= 10; i++){
        int tmp = num + i;
        res += std::to_string(tmp);
        if(i < 10){
            res.push_back(',');
        }
    }
    return res;
}

/**
 * @brief Converts a vector of strings to a comma delimited string
 * 
 * @param vec input vector to be converted
 * @return std::string a comma delimited string containing all the strings in vec
 */
std::string list_of_strings(const std::vector<std::string> vec){
    std::string res = "";
    int n = vec.size();

    for(int i = 0; i < n; i++){
        res += vec[i];
        if(i < n - 1){
            res.push_back(',');
        } 
    }
    return res;
}

/**
 * @brief Writes to a csv file with headers and data
 * 
 * @param headers goes to the top of the csv file
 * @param data the data that after the headers (normally going 1 to 1 with each other)
 * @param filename the file that it will write to
 * 
 * @throw std::runtime_error if the file can't be written to (ex: no file write permissions)
 */
void write_to_csv(const std::string headers, const std::string data, const std::string filename){
    try{
        std::ofstream csv_file(filename);
        if(!csv_file.is_open()){
            throw std::runtime_error("File not found: " + filename);
        }
        csv_file << headers << "\n";
        csv_file << data << "\n";
        csv_file.close();
    }
    catch(const std::runtime_error& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
