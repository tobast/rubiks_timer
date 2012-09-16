
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

#include "scrambleGen.h"

const QString randomScramble()
{
	std::string scramble = "";

	int prevMvType = MOVEMENTS_TYPE_NB; // <=> +oo
	for(int mvId = 0; mvId < SCRAMBLE_NB_MV; ++mvId)
	{
		int mvType = 0;
		do {
			mvType = rand() % MOVEMENTS_TYPE_NB;
		} while(mvType == prevMvType);

		scramble += MOVEMENTS[mvType][rand()%MOVEMENTS_PER_TYPE];
		scramble += " ";

		prevMvType = mvType;
	}

	return QString(scramble.c_str());
}

const QString maxLengthVoidScramble()
{
	std::string scramble = "";
	for(int mvId = 0; mvId < SCRAMBLE_NB_MV; ++mvId)
	{
		scramble += MOVEMENTS[0][2];
		scramble += ' ';
	}
	return QString(scramble.c_str());
}

