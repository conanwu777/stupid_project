#include "Operand.hpp"
#include "Exceptions.hpp"
#include <sstream>
#include <limits>

operandFactory AOperand::factory;

AOperand::AOperand(void) {};
IOperand const * AOperand::operator+(IOperand const & rhs) const {
	eOperandType t = std::max(this->getType(), rhs.getType());
	std::ostringstream s;
	s << (stod(this->toString()) + stod(rhs.toString()));
	return (AOperand::factory.createOperand(t, s.str()));}
IOperand const * AOperand::operator-(IOperand const & rhs) const {
	eOperandType t = std::max(this->getType(), rhs.getType());
	std::ostringstream s;
	s << (stod(this->toString()) - stod(rhs.toString()));
	return (AOperand::factory.createOperand(t, s.str()));}
IOperand const * AOperand::operator*(IOperand const & rhs) const {
	eOperandType t = std::max(this->getType(), rhs.getType());
	std::ostringstream s;
	s << (stod(this->toString()) * stod(rhs.toString()));
	return (AOperand::factory.createOperand(t, s.str()));}
IOperand const * AOperand::operator/(IOperand const & rhs) const {
	eOperandType t = std::max(this->getType(), rhs.getType());
	std::ostringstream s;
	if (stod(rhs.toString()) == 0)
		throw (divisionModZeroException());
	s << (stod(this->toString()) / stod(rhs.toString()));
	return (AOperand::factory.createOperand(t, s.str()));}
IOperand const * AOperand::operator%(IOperand const & rhs) const {
	eOperandType t = std::max(this->getType(), rhs.getType());
	if (t > Int32)
		throw (wrongTypeModException());
	if (stoi(rhs.toString()) == 0)
		throw (divisionModZeroException());
	std::ostringstream s;
	s << (stoi(this->toString()) % stoi(rhs.toString()));
	return (AOperand::factory.createOperand(t, s.str()));}
AOperand::~AOperand(void) {};


static void check_float_format(std::string str)
{
	int i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && str[i] != '.'){
		if (str[i] < '0' || str[i] > '9')
			throw (lexicalSyntacticException());
		i++;}
	if (str[i] == '.')
		i++;
	while (str[i]){
		if (str[i] < '0' || str[i] > '9')
			throw (lexicalSyntacticException());
		i++;}
}


operandFactory::operandFactory(void) {}
operandFactory::~operandFactory(void) {}
IOperand const * operandFactory::createInt8
(std::string const & value) const {
	try {stoi(value);}
	catch (std::exception &){
		throw (overflowException());}
	if (value.compare(std::to_string(stoi(value))))
		throw (lexicalSyntacticException());
	if (stod(value) > std::numeric_limits<char>::max()
	|| stod(value) < std::numeric_limits<char>::min())
		throw (overflowException());
	unsigned char v = stoi(value);
	return (new class Int8(v));}
IOperand const * operandFactory::createInt16
(std::string const & value) const {
	try {stoi(value);}
	catch (std::exception &){
		throw (overflowException());}
	if (value.compare(std::to_string(stoi(value))))
		throw (lexicalSyntacticException());
	if (stod(value) > std::numeric_limits<short>::max()
	|| stod(value) < std::numeric_limits<short>::min())
		throw (overflowException());
	unsigned short v = stoi(value);
	return (new class Int16(v));}
IOperand const * operandFactory::createInt32
(std::string const & value) const {
	try {stoi(value);}
	catch (std::exception &){
		throw (overflowException());}
	if (value.compare(std::to_string(stoi(value))))
		throw (lexicalSyntacticException());
	if (stod(value) > std::numeric_limits<int>::max()
	|| stod(value) < std::numeric_limits<int>::min())
		throw (overflowException());
	unsigned int v = stoi(value);
	return (new class Int32(v));}
IOperand const * operandFactory::createFloat
(std::string const & value) const {
	check_float_format(value);
	try {stof(value);}
	catch (std::exception &){
		throw (overflowException());}
	float v = stof(value);
	return (new class Float(v));}
IOperand const * operandFactory::createDouble
(std::string const & value) const {
	check_float_format(value);
	try {stod(value);}
	catch (std::exception &){
		throw (overflowException());}
	double v = stod(value);
	return (new class Double(v));}
IOperand const * operandFactory::createOperand
(eOperandType type, std::string const & value) const {
	switch (type) {
		case Int8 : return (operandFactory::createInt8(value));
		case Int16 : return (operandFactory::createInt16(value));
		case Int32 : return (operandFactory::createInt32(value));
		case Float : return (operandFactory::createFloat(value));
		case Double : return (operandFactory::createDouble(value));
		default : throw(lexicalSyntacticException());}}


Int8::Int8(void) : value(0) {
	this->str = "";}
Int8::Int8(char v) : value(v) {
	std::ostringstream is;
	is << static_cast<int>(v);
	this->str = is.str();}
Int8::~Int8(void) {}
int Int8::getPrecision( void ) const {return 0;}
eOperandType Int8::getType( void ) const {
	return eOperandType::Int8; }
std::string const & Int8::toString( void ) const {
	return (this->str);}


Int16::Int16(void) : value(0) {
	this->str = "";}
Int16::Int16(short v) : value(v) {
	std::ostringstream is;
	is << v;
	this->str = is.str();}
Int16::~Int16(void) {}
int Int16::getPrecision( void ) const {return 0;}
eOperandType Int16::getType( void ) const {
	return eOperandType::Int16; }
std::string const & Int16::toString( void ) const {
	return (this->str);}


Int32::Int32(void) : value(0) {
	this->str = "";}
Int32::Int32(int v) : value(v) {
	std::ostringstream is;
	is << v;
	this->str = is.str();}
Int32::~Int32(void) {}
int Int32::getPrecision( void ) const {return 0;}
eOperandType Int32::getType( void ) const {
	return eOperandType::Int32; }
std::string const & Int32::toString( void ) const {
	return (this->str);}


Float::Float(void) : value(0) {
	this->str = "";}
Float::Float(float v) : value(v) {
	std::ostringstream is;
	is << v;
	this->str = is.str();}
Float::~Float(void) {}
int Float::getPrecision( void ) const {
	return 7;}
eOperandType Float::getType( void ) const {
	return eOperandType::Float; }
std::string const & Float::toString( void ) const {
	return (this->str);}


Double::Double(void) : value(0) {
	this->str = "";}
Double::Double(double v) : value(v) {
	std::ostringstream is;
	is << v;
	this->str = is.str();}
Double::~Double(void) {}
int Double::getPrecision( void ) const {
	return 15;}
eOperandType Double::getType( void ) const {
	return eOperandType::Double; }
std::string const & Double::toString( void ) const {
	return (this->str);}
