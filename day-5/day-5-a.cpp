#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

int main(int argc, char const* argv[]) {
    std::ifstream crates("crates.txt");
    std::string line;

    if (!crates) return -1;

    //calculate how many stacks are there in total
    std::getline(crates, line);
    int total_stacks = (line.size() + 1) / 4;
    std::vector<char> stacks[total_stacks];

    //constructs each stack until reaching end
    while (line[1] != '1') {
        for (int i = 0; i < total_stacks; i++) {
            char c = line[1 + (i * 4)]; //gets char from ith stack
            if (c != ' ') {
                stacks[i].emplace(stacks[i].begin(), c);
            }
        }

        std::getline(crates, line);
    }
    std::getline(crates, line); //reads through empty line

    //process instructions using regex to extract relevant information
    const std::regex pattern(R"(move ([0-9]+) from ([0-9]+) to ([0-9]+))");
    while (std::getline(crates, line)) {
        std::smatch match; //holds the result of the matching operation
        std::regex_match(line, match, pattern);
        const int moves = std::stoi(match[1]);
        const int from = std::stoi(match[2]) - 1;
        const int to = std::stoi(match[3]) - 1;
        //execute instruction
        for (int i = 0; i < moves; i++) {
            const char c = stacks[from].back();
            stacks[to].emplace(stacks[to].end(), c);
            stacks[from].pop_back();
        }
    }

    //gather message
    char message[total_stacks + 1];
    message[total_stacks] = '\0';
    for (int i = 0; i < total_stacks; i++) {
        message[i] = stacks[i].back();
    }

    std::cout << "Message: " << message << std::endl;

    return 0;
}