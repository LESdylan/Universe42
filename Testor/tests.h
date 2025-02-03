/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:10:51 by dlesieur          #+#    #+#             */
/*   Updated: 2025/01/15 10:09:34 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
#define TESTS_H
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h> // pour usleep
#include "helpers.h"
//#include "macros.h"

/* Memory function prototypes */
int     test_ft_memcpy_random(const char *input);

/* CType functions prototypes */
int     test_ft_isprint(const char *input);
int     test_ft_isalpha(const char *input);
int     test_ft_isascii(const char *input);
int     test_ft_isdigit(const char *input);
int     test_ft_isalnum_random(const char *input);

/* change input */
int     test_ft_tolower(const char *input);
int     test_ft_toupper(const char *input);

/* string functionn prototype*/
int     test_ft_strlen_random(const char *input);

#endif
