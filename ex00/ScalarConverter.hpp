/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:25:18 by adeestev          #+#    #+#             */
/*   Updated: 2026/10/03 17:53:44 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& src);
		~ScalarConverter();

	public:
		static void convert(const std::string& input);
};

#endif
