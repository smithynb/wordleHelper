#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>

std::vector<std::string> importWords(){
    std::vector<std::string> words;
    std::ifstream file("./filter/filtered_words.txt");
    std::string word;
    if(file.is_open()){
        while (file >> word) {
            words.push_back(word);
        }
    } else{
        std::cerr << "Error opening file." << std::endl;
        return words;
    }
    return words;
}

/*
void parseInput(const std::string& input, std::array<char, 5>& knownChars, std::vector<int>& unknownIndexes) {
    knownChars.fill('_');

    for (int i = 0; i < input.length() && i < 5; i++) {
        if (input[i] == '_') {
            unknownIndexes.push_back(i); //store the index of the unknown character
        } else {
            knownChars[i] = input[i]; //store the known character at its respective index
        }
    }
}
*/

std::vector<std::string> filterWords(const std::vector<std::string>& words, const std::string& input, const std::string& excludedChars) {
    std::vector<std::string> filteredWords;

    for (const auto& word : words) {
        bool matches = true;
        for (int i = 0; i < 5; i++) {
            if (input[i] != '_' && word[i] != input[i]) { //if current character of current word is not blank, and does not match the input character, then it is not a match
                matches = false;
                break;
            }
        }
        for (char c : excludedChars) {
            if (word.find(c) != std::string::npos) { //if the current word contains any of the excluded characters, then it is not a match
                matches = false;
                break;
            }
        }
        if (matches) {
            filteredWords.push_back(word);
        }
    }
    return filteredWords;
}

int main(){
    std::vector<std::string> words = importWords();
    if (words.empty()) {
        std::cerr << "No words found in the file." << std::endl;
        return 1;
    }

    std::string wordInput;
    std::cout << "Wordle Helper" << std::endl;
    std::cout << "Enter known characters with unknown marked as '_' (e.g. app_e): ";
    std::cin >> wordInput; //now we have the word input from the user

    std::cout << "Enter excluded characters (e.g. abc): ";
    std::string excludedChars;
    std::cin >> excludedChars; //now we have the excluded characters from the user"

    //parse the input string to get the known and unknown characters, and positions of unknown characters
    /*
    std::vector<char> knownChars;
    std::vector<int> unknownIndexes;
    parseInput(wordInput, knownChars, unknownIndexes); //parse the input string to get the known and unknown characters
    */

    //search for words that match the known characters and do not contain the unknown characters
    std::vector<std::string> filteredWords = filterWords(words, wordInput, excludedChars); //filter the words based on the known and unknown characters

    //print the filtered words
    std::cout << "Filtered words:" << std::endl;
    for (const auto& word : filteredWords) {
        std::cout << word << std::endl; //print the filtered words
    }
    return 0;
}