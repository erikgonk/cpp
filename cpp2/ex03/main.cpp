/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:43:35 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/10/18 19:34:05 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    // Example usage and testing
    Point a(1.0f, 1.0f);
    Point b(4.0f, 1.0f);
    Point c(2.0f, 5.0f);

    Point insidePoint(2.0f, 3.0f);
    Point outsidePoint(0.0f, 0.0f);

    std::cout << "Is insidePoint inside the triangle? " << std::boolalpha << bsp(a, b, c, insidePoint) << std::endl;
    std::cout << "Is outsidePoint inside the triangle? " << std::boolalpha << bsp(a, b, c, outsidePoint) << std::endl;

    return 0;
}
