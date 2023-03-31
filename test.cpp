#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include "matrix.hpp"
#include <vector>

bool 
check_double(std::string l)
{
    bool answer;
    for (int i = 0; i < l.length(); ++i) {
        if (isdigit(l[i]) == true) {
            answer = true;
        } else
            answer = false;
    } 
    return answer;
}

void 
gauss_method_execution()
{
    int row_;
    if (::isatty(STDIN_FILENO)){}
    std::cin >> row_;
    int col_;
    if (::isatty(STDIN_FILENO)){}
    std::cin >> col_;
    matrix example(row_, col_);
    example.triangular_form();
    gauss_method_solution(example);
}



bool check_count(std::ifstream& file)
{
    double readNumbers;
    int number_of_doubles = 0;
    std::vector<double> numberVector;

    while (file >> readNumbers) {
        numberVector.push_back(readNumbers);
    }
    bool answer;
    if ((numberVector[0] != 0) && (numberVector[1] == (numberVector[0] + 1))) {
        if (numberVector.size() == (numberVector[0] * numberVector[1] + 2)) {
            answer = true;
	}else
            answer = false;
    }
    return answer;
}


void compare_files()
{
    std::fstream output;
    std::fstream golden;
    std::fstream result;
    bool answer;
    output.open("test_output.txt");

    golden.open("golden.txt");
    std::string line1;
    std::getline(output, line1);
    std::string line2;
    std::getline(golden, line2);
    for (int i = 0; i < line1.size(); ++i) {
	if (line1[i] != line2[i]) {
		answer = false;
	} 
	answer = true;
    }  
    result.open("result.txt");
    if (answer) {
        result << "Pass. ";
    }else{
        result << "Fail. ";
    }
}

int
main()
{
    bool result;
    std::ifstream inputFile;
    std::string line;
    inputFile.open("test_input.txt");
        while (std::getline(inputFile, line)) {
            if (check_double(line)) {
		if(check_count(inputFile)) {
                    result = true; 
		    break;
                }else{
                    result = false;
		    break;
                }
	    }
        }
        gauss_method_execution();
        if (result) {
            compare_files();
	    
        }else{
            std::cout << "Invalid input. ";
        }
    return 0;
}

