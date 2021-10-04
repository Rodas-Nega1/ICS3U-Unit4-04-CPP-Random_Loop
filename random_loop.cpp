// Copyright (c) 2021 Rodas Nega All rights reserved
//
// Created by: Rodas Nega
// Created on: Oct 2021
// This program asks the user to pick a number between 0-9 and guess correctly

#include <iostream>
#include <random>


int main() {
    // this function loops until it exits out of a break if
    // the user guesses correctly, otherwise it loops back for the user to
    // restart guessing

    int dice;
    std::string userNumber;
    int userNumberInt;

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);
    // [0, 9]
    dice = idist(rgen);

    // input
    std::cout << "Enter in a positive integer: ";
    std::cin >> userNumber;
    std::cout << std::endl;

    // process & output
    try {
        userNumberInt = std::stoi(userNumber);
        while (true) {
        if (userNumberInt < 0) {
            std::cout << "That is an invalid answer" << std::endl;
        } else {
            if (userNumberInt == dice) {
                std::cout << "You guessed right!";
                break;
            }
            if (userNumberInt < dice) {
                std::cout << "You guessed too low.";
            }
            if (userNumberInt > dice) {
                std::cout << "You guessed too high.";
            }
        }
        std::cout << "" << std::endl;
        std::cout << "Try again: ";
        std::cin >> userNumber;

        userNumberInt = std::stoi(userNumber);
        }
    } catch (std::invalid_argument) {
        std::cout << "That is an invalid answer.";
    }
    std::cout << "" << std::endl;
    std::cout << "\nDone." << std::endl;
}
