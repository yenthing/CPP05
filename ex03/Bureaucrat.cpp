#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high, max grade is 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low, min grade is 150";
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this == &copy)
        return *this;
    _grade = copy._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::signForm(AForm &form)
{
    if (_grade > form.getGradeToSign())
    {
        std::cout << _name << " cannot sign " << form.getName() << " because bureaucrat grade is too low" << std::endl;
        return;
    }
    form.beSigned(*this);
    std::cout << _name << " signs " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm &form)
{
    if (!form.getSigned())
    {
        std::cout << _name << " cannot execute " << form.getName() << " because it is not signed" << std::endl;
        return;
    }
    if (_grade > form.getGradeToExecute())
    {
        std::cout << _name << " cannot execute " << form.getName() << " because bureaucrat grade is too low" << std::endl;
        return;
    }
    form.execute(*this);
    std::cout << _name << " executes " << form.getName() << std::endl;
}
