#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    Bureaucrat bureaucrat("bureaucrat", 1);
    AForm *form;

    form = intern.makeForm("ShrubberyCreationForm", "target");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;

    form = intern.makeForm("RobotomyRequestForm", "target");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;

    form = intern.makeForm("PresidentialPardonForm", "target");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;

    form = intern.makeForm("InvalidForm", "target");
    delete form;

    return 0;
}
