#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) 
{
    if (this == &copy)
        return *this;
    this->_target = copy._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << "*drilling noises*\n";
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully\n";
    else
        std::cout << _target << " robotomization has failed\n";
}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
    out << "RobotomyRequestForm " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
    return out;
}
