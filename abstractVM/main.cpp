#include "avm.hpp"

void act(std::string str)
{
	std::string cmd;
	std::string tp;
	std::string nbr;
	IOperand* op;

	if (str == "" || str[0] == ';')
		return ;
	int i = 0;
	while (str[i] && str[i] != ' '){
		cmd += str[i++];}
	if (!hash[cmd])
		throw(unknownInstructionException());
	if (!cmd.compare("push") || !cmd.compare("assert"))
	{
		if (!str[i++])
			throw(lexicalSyntacticException());
		while (str[i] && str[i] != '('){
			tp += str[i++];}
		if (!types[tp] || str[i] == '\0')
			throw(lexicalSyntacticException());
		i++;
		while (str[i] && str[i] != ')'){
			nbr += str[i++];}
		if (str[i] == '\0' ||
			(str[i + 1] != '\0' && !(str[i + 1] == ' ' && str[i + 2] && str[i + 2] == ';')))
			throw(lexicalSyntacticException());
		op = const_cast<IOperand*>(AOperand::factory.createOperand(types[tp], nbr));
		hash[cmd](op);
	}
	else
	{
		if (str[i] && !(str[i] == ' ' && str[i + 1] && str[i + 1] == ';'))
			throw(lexicalSyntacticException());
		hash[cmd](NULL);
	}
}

int main (int ac, char** av)
{
	std::string line;
	int count = 0;
	if (ac > 2)
	{
		std::cout << "usage: avm [input_file]\n";
		return -1;
	}
	if (ac == 1)
	{
		vm_stdin = 1;
		std::ofstream file("tmp");
		while (std::cin.good())
		{
			std::getline(std::cin, line);
			if (!line.compare(";;"))
				break ;
			file << line << std::endl;
		}
		file.close();
	}
	std::fstream fin;
	fin.open(vm_stdin ? "tmp" : av[1]);
	if (fin.fail())
	{
		std::cout << "avm: "<< av[1] << ": No such file or directory\n";
		return -1;
	}
	while (fin.good())
	{
		std::getline(fin, line);
		count++;
		try {act(line);}
		catch (IavmExceptions & e) {
			std::cout << e.what() << " : line " << count << " : " << line << std::endl;}
	}
	try {throw (noExitException());}
	catch (IavmExceptions & e){
		std::cout << e.what() << std::endl;}
	fin.close();
	remove("tmp");
	return 0;
}
