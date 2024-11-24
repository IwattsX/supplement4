// csv_file_utils.h
#include <string>
#include <vector>
#ifndef CSV_FILE_UTILS
#define CSV_FILE_UTILS

std::string next_ten_nums(const int num);

std::string list_of_strings(const std::vector<std::string> vec);

void write_to_csv(const std::string headers, const std::string data, const std::string filename);

#endif // csv_file_utils.h