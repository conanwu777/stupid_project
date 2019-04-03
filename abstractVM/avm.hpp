#ifndef AVM_HPP
# define AVM_HPP

#include "Operand.hpp"
#include "mutantstack.hpp"
#include "Exceptions.hpp"
#include <fstream>
#include <map>

void vm_push(IOperand* op);
void vm_pop(IOperand*);
void vm_dump(IOperand*);
void vm_assert(IOperand* op);
void vm_add(IOperand*);
void vm_sub(IOperand*);
void vm_mul(IOperand*);
void vm_div(IOperand*);
void vm_mod(IOperand*);
void vm_print(IOperand*);
void vm_exit(IOperand*);

static MutantStack<IOperand*> stack;
static bool vm_stdin = 0;

static std::map<std::string, void (*)(IOperand*)> hash =
{
	{"filler",	NULL},
	{"push",	&vm_push},
	{"pop",		&vm_pop},
	{"dump",	&vm_dump},
	{"assert",	&vm_assert},
	{"add",		&vm_add},
	{"sub",		&vm_sub},
	{"mul",		&vm_mul},
	{"div",		&vm_div},
	{"mod",		&vm_mod},
	{"print",	&vm_print},
	{"exit",	&vm_exit}
};

static std::map<std::string, eOperandType> types =
{
	{"filler",	Non},
	{"int8",	Int8},
	{"int16",	Int16},
	{"int32",	Int32},
	{"float",	Float},
	{"double",	Double}
};

#endif
