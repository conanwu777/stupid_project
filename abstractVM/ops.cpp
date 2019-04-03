#include "avm.hpp"

void vm_push(IOperand* op){
	stack.push(op);}

void vm_pop(IOperand*){
	IOperand* t;
	if (stack.empty())
		throw (popEmptyException());
	t = stack.top();
	delete t;
	stack.pop();}

void vm_dump(IOperand*){
	MutantStack<IOperand*>::iterator it = stack.end();
	while (--it >= stack.begin())
		std::cout << (*it)->toString() << std::endl;}

void vm_assert(IOperand* op){
	if (op->getType() != stack.top()->getType()
		|| op->toString().compare(stack.top()->toString()))
		throw (assertNotTrueException());}

void vm_add(IOperand*){
	IOperand* a;
	IOperand* b;
	IOperand* r;

	if (stack.size() < 2)
		throw (notEnoughElementsException());
	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();
	r = const_cast<IOperand*>(*b + *a);
	vm_push(r);
	delete a;
	delete b;}

void vm_sub(IOperand*){
	IOperand* a;
	IOperand* b;
	IOperand* r;

	if (stack.size() < 2)
		throw (notEnoughElementsException());
	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();
	r = const_cast<IOperand*>(*b - *a);
	vm_push(r);
	delete a;
	delete b;}

void vm_mul(IOperand*){
	IOperand* a;
	IOperand* b;
	IOperand* r;

	if (stack.size() < 2)
		throw (notEnoughElementsException());
	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();
	r = const_cast<IOperand*>(*b * *a);
	vm_push(r);
	delete a;
	delete b;}

void vm_div(IOperand*){
	IOperand* a;
	IOperand* b;
	IOperand* r;

	if (stack.size() < 2)
		throw (notEnoughElementsException());
	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();
	r = const_cast<IOperand*>(*b / *a);
	vm_push(r);
	delete a;
	delete b;}

void vm_mod(IOperand*){
	IOperand* a;
	IOperand* b;
	IOperand* r;

	if (stack.size() < 2)
		throw (notEnoughElementsException());
	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();
	r = const_cast<IOperand*>(*b % *a);
	vm_push(r);
	delete a;
	delete b;}

void vm_print(IOperand*){
	IOperand* t;
	char c;

	if (stack.empty())
		throw (printEmptyException());
	t = stack.top();
	if (t->getType() != Int8)
		throw (wrongTypePrintException());
	c = stoi(t->toString());
	std::cout << c;}

void vm_exit(IOperand*){
	exit(1);}
