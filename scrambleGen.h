
/*
 * SOFTWARE:
 *   RubkisTimer
 * 
 * AUTHOR:
 *   Theophile BASTIAN "Tobast" <contact@tobast.fr>
 *
 * WEBSITE:
 *   http://tobast.fr/
 *
 * LICENCE:
 *   GNU GPL v3
 *
 * DESCRIPTION:
 *   Small software designed to act as a Rubik's Cube competition timer.
 *
 * LICENCE HEADER:
 *   Copyright (C) 2012  BASTIAN Theophile
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/gpl.txt>.
 */

#ifndef DEF_SCRAMBLEGEN
#define DEF_SCRAMBLEGEN

#include <cstdlib>
#include <string>

static const int SCRAMBLE_NB_MV = 25, MOVEMENTS_TYPE_NB = 6, MOVEMENTS_PER_TYPE = 3;
static const char MOVEMENTS[MOVEMENTS_TYPE_NB][MOVEMENTS_PER_TYPE][] = {
	{ "U","U'","U2" },
	{ "D","D'","D2" },
	{ "R","R'","R2" },
	{ "L","L'","L2" },
	{ "F","F'","F2" },
	{ "B","B'","B2" }
};

char* randomScramble();

#endif//DEF_SCRAMBLEGEN

