#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) 
{
    std::cout << "Assignation operator called to target: " << this->getTarget() << std::endl;
    if (this == &copy)
        return *this;
    _target = copy.getTarget();
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    if (!getSigned())
        throw AForm::GradeTooLowException(); // Assuming you need to check if the form is signed
    std::ofstream file(this->getTarget().append("_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file");

    file << "      _-_\n"
         << "   /~~   ~~\\\n"
         << " /~~         ~~\\\n"
         << "{               }\n"
         << " \\  _-     -_  /\n"
         << "   ~- _- -_ -~\n"
         << "     ~- _ -~\n"
         << "       ~~~\n";

    file.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
    out << "ShrubberyCreationForm " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
    return out;
}
