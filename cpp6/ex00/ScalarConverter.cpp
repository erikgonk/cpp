/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:46:16 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/19 15:12:56 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
	std::string char_str("impossible");
	std::string int_str("impossible");
	std::string float_str("impossible");
	std::string double_str("impossible");
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
	{
		float_str = literal;
		double_str = literal.substr(0, literal.length() - 1);
	}
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
	{
		float_str = literal + "f";
		double_str = literal;
	}
	else
	{
		char *end(0);
		double value(std::strtod(literal.c_str(), &end));
		// strtod converts to str to double
		// c_str takes a std::string and converts it into a char * (needed for strtod to work)
		// end gets the char after the numbers
		if (*end == 'f' && *(end + 1) == '\0') // 12f
			value = static_cast<float>(value);
		else if (*end != '\0')
		{
			if (literal.length() == 1 && std::isprint(literal[0])) // 12abc
				value = static_cast<double>(literal[0]);
			else // abc
				value = std::numeric_limits<double>::quiet_NaN();
		}
		if (std::isnan(value) == 0)
		{
			convertToChar(value, char_str);
			convertToInt(value, int_str);
			convertToFloat(value, float_str);
			convertToDouble(value, double_str);
		}
	}
	std::cout << "char: " << char_str << "\n";
	std::cout << "int: " << int_str << "\n";
	std::cout << "float: " << float_str << "\n";
	std::cout << "double: " << double_str << "\n";
}

void ScalarConverter::convertToChar(double value, std::string &str)
{
	if (value >= std::numeric_limits<unsigned char>::min()
		&& value <= std::numeric_limits<unsigned char>::max())
	{
		char c(static_cast<char>(value));
		str = (std::isprint(c)) ? (std::string("'") + c + "'") : "Non displayable";
	}
}

void ScalarConverter::convertToInt(double value, std::string &str)
{
	if (value >= std::numeric_limits<int>::min()
		&& value <= std::numeric_limits<int>::max())
		str = static_cast<std::ostringstream &>((std::ostringstream() << static_cast<int>(value))).str();
}

void ScalarConverter::convertToFloat(double value, std::string &str)
{
	str = static_cast<std::ostringstream &>((std::ostringstream() << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f")).str();
}

void ScalarConverter::convertToDouble(double value, std::string &str)
{
	str = static_cast<std::ostringstream &>((std::ostringstream() << std::fixed << std::setprecision(1) << static_cast<double>(value))).str();
}
