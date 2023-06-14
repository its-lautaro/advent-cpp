#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct elf_calories {
    int elf_id;
    int calories;
};

void add_sorted(int calories, int elf_id, vector<elf_calories>& max_elf_calories) {
    //each time there's an insertion the array gets reordered
    int aux_c;
    int aux_id;
    for (int i = 0; i < 3; i++) {
        if (calories > max_elf_calories[i].calories) {
            //backup info to be replaced
            aux_id = max_elf_calories[i].elf_id;
            aux_c = max_elf_calories[i].calories;
            //replace
            max_elf_calories[i].calories = calories;
            max_elf_calories[i].elf_id = elf_id;
            //set up variables for reorder
            calories = aux_c;
            elf_id = aux_id;
        }
    }
}

int main(int argc, char const* argv[]) {
    int elf_id = 0;
    int calories = 0;

    vector<elf_calories> max_elf_calories(3, { -1,-1 }); //this array will be sorted in descending order of calories

    ifstream in("calories.txt");
    if (!in) {
        std::cerr << "error while opening the file" << std::endl;
        return -1;
    }

    string line;
    while (getline(in, line)) {
        if (line.empty()) { //elf separator
            if (calories > max_elf_calories[2].calories) add_sorted(calories, elf_id, max_elf_calories);
            elf_id++;
            calories = 0;
        }
        else {
            calories += stoi(line);
        }
    }

    int total_calories = 0;
    for (int i = 0; i < 3; i++) {
        total_calories += max_elf_calories[i].calories;
        cout << i << " elf with most calories: " << max_elf_calories[i].elf_id << endl;
        cout << "Calories: " << max_elf_calories[i].calories << endl;
    }

    cout << "Total calories: " << total_calories << endl;
    in.close();

    return 0;
}
