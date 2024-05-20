#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "----Test 1----\n" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        Form f("Form", 1, 1);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n----Test 2----\n" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 150);
        Form f("AForm", 1, 1);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
