#include <iostream>
#include "Span.hpp"

int main( void )
{
    std::cout << "TEST 1" << std::endl;
    std::cout << "Longest: 14 (between 3 and 17). Shortest: 2 (between 9 and 11)" << std::endl;
    try
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "The shortest distance is: " << sp.shortestSpan() << std::endl;
        std::cout << "The longest distance is: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "TEST 2: FAIL" << std::endl;
    try
    {
        Span sp = Span(5);

        sp.addNumber(1);
        sp.addNumber(4);
        sp.addNumber(6);
        sp.addNumber(8);
        sp.addNumber(6);
        sp.addNumber(6);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "TEST 3: FAIL" << std::endl;
    try
    {
        Span sp = Span(5);

        sp.addNumber(1);
        std::cout << "If I try to find the shortest distance... " << std::endl;
        std::cout << sp.shortestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
/*    std::cout << std::endl << "TEST 4: minimum of 10 000 numbers" << std::endl;
    std::cout << "Max: 10000, Min: 2" << std::endl;
    try
    {
        Span sp = Span(10001);

        for (int i = 0; i < 10001; i = i + 2)
        {
            sp.addNumber(i + 2);
        }
        std::cout << "The shortest distance is: " << sp.shortestSpan() << std::endl;
        std::cout << "The longest distance is: " << sp.longestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }*/
    std::cout << std::endl <<  "TEST 5: Let's go with negative numbers" << std::endl;
    std::cout << "Longest: 20 (between -3 and 17). Shortest: 2 (between 9 and 11)" << std::endl;
    try
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(-3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "The shortest distance is: " << sp.shortestSpan() << std::endl;
        std::cout << "The longest distance is: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl <<  "TEST 6: Let's go with negative numbers" << std::endl;
    std::cout << "Longest: 10 (between -1 and -11). Shortest: 2 (between -1 and -3)" << std::endl;
    try
    {
        Span sp = Span(5);

        sp.addNumber(-1);
        sp.addNumber(-3);
        sp.addNumber(-5);
        sp.addNumber(-11);
        sp.addNumber(-8);
        std::cout << "The shortest distance is: " << sp.shortestSpan() << std::endl;
        std::cout << "The longest distance is: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl <<  "TEST 7: Let's go with extremal numbers" << std::endl;
    std::cout << "Longest and shorter: 4294967295 (between -2147483648 and 2147483647)" << std::endl;
    try
    {
        Span sp = Span(2);

        sp.addNumber(2147483647);
        sp.addNumber(-2147483648);
        std::cout << "The shortest distance is: " << sp.shortestSpan() << std::endl;
        std::cout << "The longest distance is: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl <<  "TEST 8: Let's go with only 2 numbers" << std::endl;
    std::cout << "Longest and shorter: 6 (between -3 and 3)" << std::endl;
    try
    {
        Span sp = Span(2);

        sp.addNumber(-3);
        sp.addNumber(3);
        std::cout << "The shortest distance is: " << sp.shortestSpan() << std::endl;
        std::cout << "The longest distance is: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << std::endl <<  "TEST 9: 2 numbers, the both with the same value" << std::endl;
	try {
		Span sp = Span(2);

		sp.addNumber(5);
		sp.addNumber(5);
		std::cout << "The shortest distance is: " << sp.shortestSpan() << std::endl;
		std::cout << "The longest distance is: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
    return (0);
}
