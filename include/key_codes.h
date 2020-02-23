/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_codes.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:45:34 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/21 11:45:34 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CODES_H
# define KEY_CODES_H

# ifdef LINUXs
#  define KEY_SPACE 32
#  define KEY_A (int)'a'
#  define KEY_D (int)'d'
#  define KEY_H (int)'h'
#  define KEY_J (int)'j'
#  define KEY_K (int)'k'
#  define KEY_L (int)'l'
#  define KEY_Q (int)'q'
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# else
#  define KEY_CMD 259
#  define KEY_ESC 53
#  define KEY_SPACE 49
#  define KEY_LSHIFT 257
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_H 4
#  define KEY_J 38
#  define KEY_K 40
#  define KEY_L 37
#  define KEY_Q 12
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# endif

#endif