#include <iostream>
#include <vector>
#include <random>
#include "Dice.h"

std::default_random_engine randGenerator;

int dice(std::vector<Dice> dices) {
    int result = 0;

    for (Dice dice : dices) {
        std::uniform_int_distribution<int> face(1, dice.getFaceAmount());

        for (int i = 0; i < dice.getDiceAmount(); i++) {
            int randomNumber = face(randGenerator);
            //std::cout << randomNumber << ' ';

            result += randomNumber;
        }
        //std::cout << std::endl;

        if (dice.getModifierNumber() > 0)
            result += dice.getModifierNumber();
    }

    return result;
}

int main() {
    randGenerator.seed(time(NULL));
    int diceNumber = 3;
    int facesNumber = 10;
    int result = 0;
    std::vector<Dice> dices;
    std::vector<int> resultNumbers;

    dices.push_back(Dice(diceNumber, facesNumber));

    for (int i = 0; i < facesNumber * diceNumber; i++)
        resultNumbers.push_back(0);

    /*dices.push_back(Dice(2, 6));
    dices.push_back(Dice(3, 6));
    dices.push_back(Dice(1, 10));
    dices.push_back(Dice(2, 10));
    dices.push_back(Dice(3, 10));*/

    for (int i = 0; i < 10000; i++) {
        result = dice(dices);
        resultNumbers[result - 1] += 1;
    }

    for (auto i : resultNumbers)
        std::cout << i << std::endl;
}