
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

class DigitalNumber : public QGraphicsItemGroup
{
	public:
		DigitalNumber(int initNum = 0);
		void setDigit(int digit);
	
	private: //meth
		void buildWidget();
		void setSegments(bool* matrix);

	private:
		static const bool DIGITAL_PATTERNS[10][7];
		QPen segOffPen, segOnPen;

		std::vector<QGraphicsLineItem*> segments;
		const int SEG_HEIGHT=50, SEG_WIDTH=10;
}

#endif//DEF_DIGITALNUMBER

