//////////////////////////////////////////////////
//
//      1. Console app gets the spiral size.
//      2. Sets values in the spiral.
//      3. Prints the final spiral.
// 
//      note:
//          The algorithm can only generate spirals of odd size.
//          In other case:
//              - The spiral size is set to an odd number for simpler code.
//              - In final spiral prints values within the range of the original spiral
//
//////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::string spaces(int amount)
{
    /* Return spaces (as many as in param) */
    std::string result = "";

    for (size_t i = 0; i < amount; i++)
        result += " ";

    return result;
}

int main()
{
    //Variables
    unsigned visible_spiral_size = 0;
    unsigned spiral_size = 0;
    std::vector<std::vector<std::string>> spiral;
    unsigned visible_max_value = 0;
    unsigned max_value = 0;
    unsigned center = 0;
    int offset_x = 0;
    int offset_y = 0;
    unsigned current_value = 0;

    //Get data from user
    std::cout << "Enter spiral size: ";
    std::cin >> visible_spiral_size;
    std::cout << std::endl;

    //Prepare variables
    spiral_size = visible_spiral_size - (visible_spiral_size % 2) + 1; //Sets the spiral size to an odd number to easier code
    max_value = spiral_size * spiral_size;
    visible_max_value = visible_spiral_size * visible_spiral_size;

    //Initialize 2D vector (spiral)
    spiral.resize(spiral_size, std::vector<std::string>());
    for (size_t x = 0; x < spiral_size; x++)
    {
        spiral[x].resize(spiral_size, std::string());
    }

    //Calculate the center of the spiral
    center = std::round((spiral_size / 2));

    //Set values in vector
    for (size_t i = 0; i < spiral_size; i++)
    {
        /* Hard to read but it does the same as my pattern at the end of file */
        /* Sets values in a spiral pattern starting from the center */
        if (i % 2 == 0)
        {
            for (int x = i - 1; x > -1; x--)
            {
                spiral[center + x - (std::round((i - 1) / 2) + (spiral_size % 2) - 1)][center - offset_y] = std::to_string(++current_value);
            }
            for (size_t y = 0; y < i + 1; y++)
            {
                spiral[center - offset_x][center + y - (std::round(i / 2) + (spiral_size % 2) - 1)] = std::to_string(++current_value);
            }
        }
        else
        {
            offset_x++;
            offset_y++;

            for (size_t x = 0; x < i; x++)
            {
                spiral[center + x - (std::round((i - 1) / 2) + (spiral_size % 2) - 1)][center + offset_y] = std::to_string(++current_value);
            }
            for (int y = i; y > -1; y--)
            {
                spiral[center + offset_x][center + y - (std::round(i / 2) + (spiral_size % 2) - 1)] = std::to_string(++current_value);
            }
        }
    }

    /* Print results */

    std::cout << "Your spiral: " << std::endl;

    //Print spiral
    for (size_t x = 0; x < spiral_size; x++)
    {
        bool new_line = false;
        for (size_t y = 0; y < spiral_size; y++)
        {
            /* Print values within the range of the spiral */
            std::string cur_elem = spiral[x][y];
            if (std::stoi(cur_elem) <= visible_max_value)
            {
                std::cout << spaces(size(std::to_string(max_value)) - size(cur_elem)) << cur_elem << " ";
                new_line = true;
            }
        }

        if  (new_line)
            std::cout << std::endl;
    }
}

//////////////////////////////////////////////////
//              Pattern:
//
//       spiral[x][y] = value;
// 
//   spiral[center + 0][center + 0 - 0] = "1";
//
//   spiral[center + 0 + 0][center + 1] = "2";
//
//   spiral[center + 1][center + 1 - 0] = "3";
//   spiral[center + 1][center + 0 - 0] = "4";
//
//   spiral[center + 1 + 0][center - 1] = "5";
//   spiral[center + 0 + 0][center - 1] = "6";
//
//   spiral[center - 1][center + 0 - 1] = "7";
//   spiral[center - 1][center + 1 - 1] = "8";
//   spiral[center - 1][center + 2 - 1] = "9";
//
//   spiral[center + 0 - 1][center + 2] = "10";
//   spiral[center + 1 - 1][center + 2] = "11";
//   spiral[center + 2 - 1][center + 2] = "12";
//
//   spiral[center + 2][center + 3 - 1] = "13";
//   spiral[center + 2][center + 2 - 1] = "14";
//   spiral[center + 2][center + 1 - 1] = "15";
//   spiral[center + 2][center + 0 - 1] = "16";
//
//   spiral[center + 3 - 1][center - 2] = "17";
//   spiral[center + 2 - 1][center - 2] = "18";
//   spiral[center + 1 - 1][center - 2] = "19";
//   spiral[center + 0 - 1][center - 2] = "20";
//
//   spiral[center - 2][center + 0 - 2] = "21";
//   spiral[center - 2][center + 1 - 2] = "22";
//   spiral[center - 2][center + 2 - 2] = "23";
//   spiral[center - 2][center + 3 - 2] = "24";
//   spiral[center - 2][center + 4 - 2] = "25";
// 
//////////////////////////////////////////////////
