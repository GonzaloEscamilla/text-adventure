#ifndef _TSV_PARSER_
#define _TSV_PARSER_

#include <iostream>
#include <fstream>
#include<string>
#include<vector>

namespace serialization_tools
{
    std::vector<std::string> get_file_elements(std::string file_name, int file_columns_amount); 
}


#endif