#include "tsv_parser.h"

namespace serialization_tools
{
    std::vector<std::string> get_file_elements(std::string file_name, int file_columns_amount)
    {
        std::ifstream my_file;
        std::vector<std::string> file_elements;

        my_file.open(file_name);

        while (my_file.good())
        {
            std::string line;

            for (int i = 0; i < file_columns_amount - 1; i++)
            {
                getline(my_file, line, '\t');
                file_elements.push_back(line);
            }
            
            getline(my_file, line, '\n');
            file_elements.push_back(line);
        }

        return file_elements;
    }
}
