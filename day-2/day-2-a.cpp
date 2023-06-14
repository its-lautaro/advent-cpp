#include <iostream>
#include <fstream>

int main() {
    std::ifstream strategy("strategy.txt");

    if (!strategy) {
        std::cerr << "error while opening the file" << std::endl;
        return -1;
    }

    int score = 0;
    char opp_choice,my_choice;

    while (strategy>>opp_choice>>std::ws>>my_choice) {
        //first calculate score by choice
        switch (my_choice) {
        case 'X': //rock
            score += 1;
            //calculate score by match output (draw/win)
            if (opp_choice != 'B') {
                (opp_choice == 'A') ? score += 3 : score += 6;
            }
            break;
        case 'Y': //paper
            score += 2;
            //calculate score by match output (draw/win)
            if (opp_choice != 'C') {
                (opp_choice == 'B') ? score += 3 : score += 6;
            }
            break;
        case 'Z': //scissors
            score += 3;
            //calculate score by match output (draw/win)
            if (opp_choice != 'A') {
                (opp_choice == 'C') ? score += 3 : score += 6;
            }
            break;
        }
    }
    strategy.close();
    std::cout << "Total score: " << score << std::endl;
    return 0;
}