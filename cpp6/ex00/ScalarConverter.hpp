/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:46:24 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/22 10:11:57 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>

class ScalarConverter
{
  public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();
    static void convert(const std::string &literal);

  private:
    static void convertToChar(double value, std::string &str);
    static void convertToInt(double value, std::string &str);
    static void convertToFloat(double value, std::string &str);
    static void convertToDouble(double value, std::string &str);
};

#endif

