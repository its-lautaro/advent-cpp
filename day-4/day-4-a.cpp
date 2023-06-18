#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char const* argv[]) {
    std::ifstream file("pairs.txt");
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return -1;
    }

    int min, max, dmin, dmax, delimiter_pos;
    std::string line, range1, range2;
    int duplicate_ranges = 0;
    //reads ranges
    while (std::getline(file, line)) {
        delimiter_pos = line.find(',');
        range1 = line.substr(0, delimiter_pos);
        range2 = line.substr(delimiter_pos + 1);

        delimiter_pos = range1.find('-');
        min = std::stoi(range1.substr(0, delimiter_pos));
        max = std::stoi(range1.substr(delimiter_pos + 1));

        delimiter_pos = range2.find('-');
        dmin = std::stoi(range2.substr(0, delimiter_pos));
        dmax = std::stoi(range2.substr(delimiter_pos + 1));
        //checks if range2 is contained in range1 or viceversa
        if ((min <= dmin && max >= dmax) || (min >= dmin && max <= dmax)) {
            duplicate_ranges++;
        }
    }

    std::cout << "There are " << duplicate_ranges << " pairs which contain the other" << std::endl;
    return 0;
}
