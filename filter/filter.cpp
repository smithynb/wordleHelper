#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream inputFile("words.txt");
    std::ofstream outputFile("filtered_words.txt");
    std::string word;
    if(inputFile.is_open() && outputFile.is_open()){
        while(std::getline(inputFile, word)){
            if(word.length() == 5){
                outputFile << word << std::endl;
            }
        }
        inputFile.close();
        outputFile.close();
        std::cout << "Successfully written 5 letter words to filtered_words.txt" << std::endl;
    } else{
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    return 0;

}