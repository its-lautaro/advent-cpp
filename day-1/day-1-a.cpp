#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const* argv[]) {
    int elf_id = 0;
    int calories = 0;

    int max_elf_id = 0;
    int max_calories = -1;

    ifstream in("calories.txt");
    if (!in) {
        std::cerr << "error while opening the file" << std::endl;
    }

    string line;
    while (getline(in, line)) {
        if (line.empty()) { //elf separator
            if (calories > max_calories) {
                max_calories = calories;
                max_elf_id = elf_id;
            }
            elf_id++;
            calories = 0;
        }
        else {
            calories += stoi(line);
        }
    }

    cout << "Elf with most calories: " << max_elf_id << endl;
    cout << "Calories: " << max_calories << endl;

    in.close();

    return 0;
}