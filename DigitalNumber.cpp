
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

#include "DigitalNumber.h"


DigitalNumber::DigitalNumber(int initNum)
{
	segOffPen = QPen(QColor(0x36,0,0));
	segOffPen.setWidth(SEG_WIDTH/2);
	segOffPen.setCapStyle(Qt::RoundCap);
	segOnPen = QPen(segOffPen);
	segOnPen.setColor(QColor(0xff,0,0));

	buildWidget();
	setDigit(initNum);
}

void DigitalNumber::setDigit(int digit)
{
	if(digit<0 || digit>9)
		return;
	setSegments(DIGIT_PATTERNS[digit]);
}

void DigitalNumber::buildWidget()
{
	segments.push_back(new QGraphicsLineItem(SEG_WIDTH*1.5f, SEG_WIDTH*0.5f, SEG_WIDTH*1.5+SEG_HEIGHT, SEG_WIDTH*0.5f));
	segments.push_back(new QGraphicsLineItem(SEG_WIDTH*2.5f+SEG_HEIGHT, SEG_WIDTH*1.5f, SEG_WIDTH*2.5+SEG_HEIGHT, SEG_WIDTH*1.5f+SEG_HEIGHT));
	segments.push_back(new QGraphicsLineItem(SEG_WIDTH*2.5f+SEG_HEIGHT, SEG_WIDTH*3.5f+SEG_HEIGHT, SEG_WIDTH*2.5+SEG_HEIGHT, SEG_WIDTH*3.5f+2*SEG_HEIGHT));
	segments.push_back(new QGraphicsLineItem(SEG_WIDTH*1.5f, SEG_WIDTH*4.5f+2*SEG_HEIGHT, SEG_WIDTH*1.5+SEG_HEIGHT, SEG_WIDTH*4.5f+2*SEG_HEIGHT));
	segments.push_back(new QGraphicsLineItem(SEG_WIDTH*0.5f, SEG_WIDTH*3.5f+SEG_HEIGHT, SEG_WIDTH*0.5, SEG_WIDTH*3.5f+2*SEG_HEIGHT));
	segments.push_back(new QGraphicsLineItem(SEG_WIDTH*0.5f, SEG_WIDTH*1.5f, SEG_WIDTH*0.5, SEG_WIDTH*1.5f+SEG_HEIGHT));
	segments.push_back(new QGraphicsLineItem(SEG_WIDTH*1.5f, SEG_WIDTH*2.5f+SEG_HEIGHT, SEG_WIDTH*1.5+SEG_HEIGHT, SEG_WIDTH*2.5f+SEG_HEIGHT));
	for(size_t seg=0; seg<segments.size(); ++seg)
	{
		segments[seg]->setPen(segOffPen);
		addToGroup(segments[seg]);
	}
}

void DigitalNumber::setSegments(const bool* matrix)
{
	for(size_t seg=0; seg<segments.size(); ++seg)
		segments[seg]->setPen((matrix[seg]) ? segOnPen : segOffPen);
}

