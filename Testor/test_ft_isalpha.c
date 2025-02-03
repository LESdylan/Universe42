/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:29:28 by dlesieur          #+#    #+#             */
/*   Updated: 2025/01/14 13:42:06 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int test_ft_isalpha(const char *input)
{
    char generate_char = generate_random_char();
    int expected = isalpha(generate_char);
    int myfunction = ft_isalpha(generate_char);
    if(strcmp(input, "detailed") == 0)
    {
        printf("Generated character: '%c' (ASCII: %d)\n Expected (is alnum): %d\n", 
            generate_char, generate_char, isalpha((unsigned char)generate_char) != 0, ft_isalnum(generate_char));

    }
    elseif(strcmp(input, "short") == 0)
    {
        
    }
    else 
    {
        fprintf(stderr, "Error, the input has to be 'short'  or 'detailed");
        return 1;
    }
    
}
