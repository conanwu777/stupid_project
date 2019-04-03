#include "Exceptions.hpp"

const char* lexicalSyntacticException::what() const throw() {
		return ("Lexical/syntactic error");}

const char* unknownInstructionException::what() const throw() {
		return ("Unknown instruction");}

const char* overflowException::what() const throw() {
		return ("Overflow/underflow on a value");}

const char* popEmptyException::what() const throw() {
		return ("Pop on an empty stack");}

const char* divisionModZeroException::what() const throw() {
		return ("Division/modulo by 0");}

const char* noExitException::what() const throw() {
		return ("The program doesn’t have an exit instruction");}

const char* assertNotTrueException::what() const throw() {
		return ("Assert not true");}

const char* notEnoughElementsException::what() const throw() {
		return ("Stack has strictly less than two values");}

const char* wrongTypePrintException::what() const throw() {
		return ("Value to Print is not of type Int8");}

const char* wrongTypeModException::what() const throw() {
		return ("Modulo by a value of non-integer type");}

const char* printEmptyException::what() const throw() {
		return ("Instruction print on an empty stack");}
