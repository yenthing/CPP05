#include "Bureaucrat.hpp"

int main()
{
    std::cout << "---------------------------------------\n";
    std::cout << "Test 1 for incrementGrade\n";
    try
    {
        Bureaucrat b1("b1", 150);
        Bureaucrat b3(b1);
        Bureaucrat b4 = b1;
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << " after increment" << std::endl;
        std::cout << b3 << " after copy" << std::endl;
        std::cout << b4 << " after assign" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------------------------------\n";
    std::cout << "Test 2 for decrementGrade\n";
    try
    {
        Bureaucrat b2("b2", 1);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << " after decrement" <<  std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------------------------------\n";
    std::cout << "End Test, bye!\n";
    return 0;
}
