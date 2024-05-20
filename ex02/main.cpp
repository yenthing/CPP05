#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);
    ShrubberyCreationForm s1("s1");
    RobotomyRequestForm r1("r1");
    PresidentialPardonForm p1("p1");

    std::cout << "-----Before signing and executing forms-----" << std::endl;
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << s1 << std::endl;
    std::cout << r1 << std::endl;
    std::cout << p1 << std::endl;

    std::cout << "\n-----Signing forms-----" << std::endl;
    b1.signForm(s1);
    b1.signForm(r1);
    b1.signForm(p1);

    std::cout << "\n-----Executing forms-----" << std::endl;
    b1.executeForm(s1);
    b1.executeForm(r1);
    b1.executeForm(r1);
    b1.executeForm(p1);

    return 0;
}
