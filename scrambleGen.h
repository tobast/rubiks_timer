
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
#include <QString>

static const int SCRAMBLE_NB_MV = 20, MOVEMENTS_TYPE_NB = 6, MOVEMENTS_PER_TYPE = 3;
static const std::string MOVEMENTS[MOVEMENTS_TYPE_NB][MOVEMENTS_PER_TYPE] = {
	{ std::string("U"),std::string("U'"),std::string("U2") },
	{ std::string("D"),std::string("D'"),std::string("D2") },
	{ std::string("R"),std::string("R'"),std::string("R2") },
	{ std::string("L"),std::string("L'"),std::string("L2") },
	{ std::string("F"),std::string("F'"),std::string("F2") },
	{ std::string("B"),std::string("B'"),std::string("B2") }
};

const QString randomScramble();
const QString maxLengthVoidScramble();

#endif//DEF_SCRAMBLEGEN

