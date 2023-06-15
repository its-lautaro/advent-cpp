#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

//Ignores characters if they are not letters
int compute_priority(char c){
    //lowercase
    if(c>=97 && c<=122){
        return (c-96);
    }//uppercase
    else if (c>=65 && c<=90){
        return (c-38);
    }else{
        return 0;
    }
}

// Returns a null character if there is no repeating item
char find_duplicate(const std::string& line) {
    std::unordered_set<char> items;

    std::string compartment_a = line.substr(0, line.size() / 2);
    std::string compartment_b = line.substr(line.size() / 2);

    for (char i : compartment_a) {
        items.emplace(i);
    }

    for (char i : compartment_b) {
        if (items.count(i)) {
            return i;
        }
    }

    return '\0';
}

int main(int argc, char const* argv[]) {
    std::ifstream rucksacks("rucksacks.txt");
    
    std::string line;
    char duplicate;
    int sum = 0;
    while (std::getline(rucksacks, line)) {
        duplicate = find_duplicate(line);
        if (duplicate == '\0') return -1; //assuming there's always a repeating element, no repeating means bad file input

        sum += compute_priority(duplicate);
    }
    std::cout << "Sum of repeating items priority: " << sum << std::endl;
    return 0;
}
