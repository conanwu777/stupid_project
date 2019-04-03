#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP
# include <iostream>
# include <stdexcept>

class IavmExceptions : public std::exception {
	public:
		virtual const char* what() const throw() = 0;};

class lexicalSyntacticException : public IavmExceptions {
	public:
		virtual const char* what() const throw();};
class unknownInstructionException : public IavmExceptions {
	public:
		virtual const char* what() const throw();};
class overflowException : public IavmExceptions {
	public:
		virtual const char* what() const throw();};
class popEmptyException : public IavmExceptions {
	public:
		virtual const char* what() const throw();};
class divisionModZeroException : public IavmExceptions {
	public:
		virtual const char* what() const throw();};
class noExitException : public IavmExceptions {
	public:
		virtual const char* what() const throw();};
class assertNotTrueException : public IavmExceptions {
	public:
		virtual const char* what() const throw();};
class notEnoughElementsException : public IavmExceptions {
	public:
		virtual const char* what() const throw();};
class wrongTypePrintException : public IavmExceptions {
	public:
		virtual const char* what() const throw();};
class wrongTypeModException : public IavmExceptions {
	public:
		virtual const char* what() const throw();};
class printEmptyException : public IavmExceptions {
	public:
		virtual const char* what() const throw();};

#endif
