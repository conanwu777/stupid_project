#ifndef OPERAND_HPP
# define OPERAND_HPP
# include <iostream>
# include <map>

enum eOperandType {Non, Int8, Int16, Int32, Float, Double};

class IOperand {
	public:
		virtual int getPrecision( void ) const = 0;
		virtual eOperandType getType( void ) const = 0;
		virtual IOperand const * operator+( IOperand const & rhs ) const = 0;
		virtual IOperand const * operator-( IOperand const & rhs ) const = 0;
		virtual IOperand const * operator*( IOperand const & rhs ) const = 0;
		virtual IOperand const * operator/( IOperand const & rhs ) const = 0;
		virtual IOperand const * operator%( IOperand const & rhs ) const = 0;
		virtual std::string const & toString( void ) const = 0;
		virtual ~IOperand(void) {}
};

class operandFactory {
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
		operandFactory(operandFactory const & src);
		operandFactory & operator=(operandFactory const & src);
	public:
		operandFactory(void);
		~operandFactory(void);
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
};

class AOperand : public IOperand {
		AOperand(AOperand const & src);
		AOperand & operator=(AOperand const & src);
	protected:
		std::string str;
	public:
		static operandFactory factory;
		AOperand(void);
		virtual IOperand const * operator+( IOperand const & rhs ) const;
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const;
		virtual IOperand const * operator/( IOperand const & rhs ) const;
		virtual IOperand const * operator%( IOperand const & rhs ) const;
		virtual std::string const & toString( void ) const = 0;
		virtual ~AOperand(void);
};

class Int8 : public AOperand {
		char	value;
		Int8(void);
		Int8(Int8 const & src);
		Int8 & operator=(Int8 const & src);
	public:
		Int8(char v);
		~Int8(void);
		virtual int getPrecision( void ) const;
		virtual eOperandType getType( void ) const;
		virtual std::string const & toString( void ) const;
};

class Int16 : public AOperand {
		short	value;
		Int16(void);
		Int16(Int16 const & src);
		Int16 & operator=(Int16 const & src);
	public:
		Int16(short v);
		~Int16(void);
		virtual int getPrecision( void ) const;
		virtual eOperandType getType( void ) const;
		virtual std::string const & toString( void ) const;
};

class Int32 : public AOperand {
		int	value;
		Int32(void);
		Int32(Int32 const & src);
		Int32 & operator=(Int32 const & src);
	public:
		Int32(int v);
		~Int32(void);
		virtual int getPrecision( void ) const;
		virtual eOperandType getType( void ) const;
		virtual std::string const & toString( void ) const;
};

class Float : public AOperand {
		float	value;
		Float(void);
		Float(Float const & src);
		Float & operator=(Float const & src);
	public:
		Float(float v);
		~Float(void);
		virtual int getPrecision( void ) const;
		virtual eOperandType getType( void ) const;
		virtual std::string const & toString( void ) const;
};

class Double : public AOperand {
		double	value;
		Double(void);
		Double(Double const & src);
		Double & operator=(Double const & src);
	public:
		Double(double v);
		~Double(void);
		virtual int getPrecision( void ) const;
		virtual eOperandType getType( void ) const;
		virtual std::string const & toString( void ) const;
};

#endif
