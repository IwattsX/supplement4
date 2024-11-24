#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "csv_file_utils.h"

TEST(test_csv_file, BasicAssertion){
    
    std::vector<std::string> header_vec;
    
    for(int i = 1; i <= 10; i++){
        header_vec.push_back("num" + std::to_string(i));
    }
    
    std::string headers = list_of_strings(header_vec);
    ASSERT_EQ(headers, "num1,num2,num3,num4,num5,num6,num7,num8,num9,num10");

    int test_num = 12;
    std::string data = next_ten_nums(test_num);
    ASSERT_EQ(data, "13,14,15,16,17,18,19,20,21,22");


    write_to_csv(headers, data, "test1.csv");

    // read file and test if it is accurate
    std::ifstream csv_file("test1.csv");
    std::string tmp_read;
    std::string read_text;

    if(!csv_file.is_open()){ // should be unreachable code
        throw std::runtime_error("File not found while reading test1.csv");
    }

    while( getline(csv_file, tmp_read) ){
        // getline goes all the way until either a \0,(end of file), or \n
        read_text += tmp_read + '\n';
    }

    ASSERT_EQ(read_text, headers + "\n" + data + "\n");
    csv_file.close();

}