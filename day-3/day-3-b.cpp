#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

//Ignores characters if they are not letters
int compute_priority(char c) {
    //lowercase
    if (c >= 97 && c <= 122) {
        return (c - 96);
    }//uppercase
    else if (c >= 65 && c <= 90) {
        return (c - 38);
    }
    else {
        return 0;
    }
}

// Returns a null character if there is no repeating item
char find_duplicate(const std::string& line1, const std::string& line2, const std::string& line3) {
    std::unordered_set<char> items;
    std::unordered_set<char> repeated;

    for (char i : line1) {
        items.emplace(i);
    }

    for (char i : line2) {
        if (items.count(i)) {
            repeated.emplace(i);
        }
    }

    for (char i : line3) {
        if (repeated.count(i)) {
            return i;
        }
    }

    return '\0';
}

int main(int argc, char const* argv[]) {
    std::ifstream rucksacks("rucksacks.txt");

    std::string line1, line2, line3;
    char duplicate;
    int sum = 0;
    while (std::getline(rucksacks, line1)) {
        std::getline(rucksacks, line2);
        std::getline(rucksacks, line3);

        duplicate = find_duplicate(line1, line2, line3);

        if (duplicate == '\0') return -1; //assuming there's always a repeating element, no repeating means bad file input

        sum += compute_priority(duplicate);
    }
    std::cout << "Sum of repeating items priority: " << sum << std::endl;
    return 0;
}
