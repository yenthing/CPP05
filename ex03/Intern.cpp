#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return (*this);
}

Intern::~Intern(){}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm *ptr = NULL;
    const std::string form_names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (int i = 0; i < 3; i++)
    {
        if (formName == form_names[i])
        {
            switch (i)
            {
                case 0:
                    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
                    ptr = new ShrubberyCreationForm(target);
                    break;
                case 1:
                    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
                    ptr = new RobotomyRequestForm(target);
                    break;
                case 2:
                    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
                    ptr = new PresidentialPardonForm(target);
                    break;
            }
            return (ptr);
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    return (NULL);
}
