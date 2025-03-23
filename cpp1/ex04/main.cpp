/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:12:31 by erigonza          #+#    #+#             */
/*   Updated: 2025/03/06 18:24:47 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <limits.h>

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED_BACKGROUND "\033[41m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

bool    openFile( std::fstream &file, std::string filename, std::ios::openmode mode );
std::string findAndReplace( std::string line, std::string oldWord, std::string newWord );

int	main(int ac, char *av[]) {
	std::cout << "\033[2J\033[H" << std::endl;
	if (ac != 4) {
		std::cout << RED_BACKGROUND << "error: wrong num of args" << std::endl
			<< "Please enter: ./sedIsForLoosers,  <filename>, <search> & <replace>" <<
			RESET << std::endl << std::endl;
		return 0;
	}
    std::fstream    infile;
    std::fstream    outfile;
    std::string     nameOutfile;
    std::string     line;
    if (!openFile(infile, av[1], std::ios::in))
        return (1);
    nameOutfile = std::string(av[1]).append(".replace");
    if (!openFile(outfile, nameOutfile, std::ios::out)) {
        infile.close();
        return (1);
    }
    while (std::getline(infile, line)) {
		outfile << findAndReplace(line, av[2], av[3]) << std::endl;
    }
    return 0;
}

bool    openFile( std::fstream &file, std::string filename, std::ios::openmode mode )
{
    file.open(filename.c_str(), mode);

    if (file.fail()) {
        std::cout << RED_BACKGROUND << "error: opening file: " << filename << RESET << std::endl;
        return (false);
    }
    return (true);
}

std::string findAndReplace( std::string line, std::string oldWord, std::string newWord )
{
    std::string res;  // String to store the final result after replacements
    size_t pos = 0;      // Variable to store the current position of 'oldWord' in 'line'
    size_t oldWordLength = oldWord.length();  // Length of 'oldWord', to help with removal

    // Loop to find and replace every occurrence of 'oldWord' in 'line'
    while ((pos = line.find(oldWord, pos)) != std::string::npos) {
        // Append the part of 'line' before 'oldWord' and replace 'oldWord' with 'newWord'
        res += line.substr(0, pos) + newWord;

        // Remove the processed part of 'line' including the 'oldWord' we just replaced
        line.erase(0, pos + oldWordLength);

        // Reset 'pos' to 0 to start searching from the beginning of the modified 'line'
        pos = 0;
    }

    // Append any remaining part of 'line' after the last occurrence of 'oldWord'
    res += line;

    // Return the final string with all replacements
    return res;
}
