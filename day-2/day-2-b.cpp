#include <iostream>
#include <fstream>

int main() {
    std::ifstream strategy("strategy.txt");

    if (!strategy) {
        std::cerr << "error while opening the file" << std::endl;
        return -1;
    }

    int score = 0;
    char opp_choice, my_choice, game_output;

    while (strategy >> opp_choice >> std::ws >> game_output) {
        switch (game_output) {
        case 'X': //i lose
            //calculate my choice to lose based on opp choice
            switch (opp_choice){
                case 'A'://opp chooses rock
                //i choose scissors
                score+=3;
                break;
                case 'B': //opp chooses paper
                //i choose rock
                score+=1;
                break;
                case 'C': //opp chooses scissors
                //i choose paper
                score+=2;
                break;
            }
            break;
        case 'Y': //draw
            score += 3;
            //calculate my choice to draw based on opp choice
            switch (opp_choice){
                case 'A': //opp chooses rock
                //i choose rock
                score+=1;
                break;
                case 'B': //opp chooses paper
                //i choose paper
                score+=2;
                break;
                case 'C': //opp chooses scissors
                //i choose scissors
                score+=3;
                break;
            }
            break;
        case 'Z': //i win
            score += 6;
            //calculate my choice to win based on opp choice
            switch (opp_choice){
                case 'A': //opp chooses rock
                //i choose paper
                score+=2;
                break;
                case 'B': //opp chooses paper
                //i choose scissors
                score+=3;
                break;
                case 'C': //opp chooses scissors
                //i choose rock
                score+=1;
                break;
            }
            break;
        }
    }
    strategy.close();
    std::cout << "Total score: " << score << std::endl;
    return 0;
}