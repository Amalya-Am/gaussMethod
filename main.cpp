#include <iostream>
#include "matrix.hpp"
#include <unistd.h>

int
main()
{
	int n;
	if(::isatty(STDIN_FILENO)){}
    std::cin >> n;
	
    int m;
	if(::isatty(STDIN_FILENO)){}
    std::cin >> m;
	
    matrix a(n, m);
    a.triangular_form();
    gauss_method_solution(a);

}

