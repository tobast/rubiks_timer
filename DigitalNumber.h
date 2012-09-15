
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

#ifndef DEF_DIGITALNUMBER
#define DEF_DIGITALNUMBER

#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QBrush>
#include <QPen>
#include <vector>

/* Digits are represented by a boolean matrix describing the state of each segment as following :
 *   ___
 * 6| 1 | 2
 *  |___|
 * 5| 7 | 3
 *  |___|
 *    4 
 */
static const bool DIGIT_PATTERNS[10][7] =
{
	{true,true,true,true,true,true,false},		// 0
	{false,true,true,false,false,false,false},	// 1
	{true,true,false,true,true,false,true},		// 2
	{true,true,true,true,false,false,true},		// 3
	{false,true,true,false,false,true,true},	// 4
	{true,false,true,true,false,true,true},		// 5
	{true,false,true,true,true,true,true},		// 6
	{true,true,true,false,false,false,false},	// 7
	{true,true,true,true,true,true,true},		// 8
	{true,true,true,true,false,true,true}		// 9
};
static const int SEG_HEIGHT=50, SEG_WIDTH=10;
class DigitalNumber : public QGraphicsItemGroup
{
	public:
		DigitalNumber(int initNum = 0);
		void setDigit(int digit);
		static int digitWidth() { return 3*SEG_WIDTH+SEG_HEIGHT; }
		static int digitHeight() { return 5*SEG_WIDTH+2*SEG_HEIGHT; }

	private: //meth
		void buildWidget();
		void setSegments(const bool* matrix);

	private:
		QPen segOffPen, segOnPen;

		std::vector<QGraphicsLineItem*> segments;
};

#endif//DEF_DIGITALNUMBER

