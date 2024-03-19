#include <string>
#include <fstream>
#include <iostream>

using std::string;

void countAndWriteDigitsPerLine(string filename, string outputFilename)
{
    std::ifstream InputFile(filename);
    std::ofstream OutputFile(outputFilename);
    int count = 0;
    string line;
    char c;

    while (getline(InputFile, line)) {
        for (int i = 0; i < line.size(); i++) { 
            c = line[i];
            if (isdigit(c)) {
                count++;
            }
        } 
    }

    OutputFile << count;
    InputFile.close();
    OutputFile.close();
}

unsigned int countMaxDigits(string filename)
{
    std::ifstream InputFile(filename);
    int count = 0;
    int max = 0;
    string line;
    char c;

    while (getline(InputFile, line)) {
        count = 0;
        for (int i = 0; i < line.size(); i++) { 
            c = line[i];
            if (isdigit(c)) {
                count++;
            }
        }
        if (count > max) {
            max = count;
        }
    }

    InputFile.close();
    return max;
}

int main() { //for testing
    countAndWriteDigitsPerLine("inputfile.txt", "outputfile.txt");
    std::cout << countMaxDigits("inputfile.txt");
    return 0;
}