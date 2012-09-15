
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

#include "DigitalTimerDisplay.h"

DigitalTimerDisplay::DigitalTimerDisplay()
{
	scene.setBackgroundBrush(QBrush(QColor(0,0,0)));

	buildWidget();
	setScene(&scene);
}

void DigitalTimerDisplay::setTime(int min, int sec, int csec)
{
	int min1=min/10, min0=min-min1*10;
	min1 -= (min1/10)*10;
	int sec1=sec/10, sec0=sec-sec1*10;
	sec1 -= (sec1/10)*10;
	int csec1=csec/10, csec0=csec-csec1*10;
	csec1 -= (csec1/10)*10;

	minNum[0]->setDigit(min1);
	minNum[1]->setDigit(min0);
	secNum[0]->setDigit(sec1);
	secNum[1]->setDigit(sec0);
	csecNum[0]->setDigit(csec1);
	csecNum[1]->setDigit(csec0);
}

void DigitalTimerDisplay::buildWidget()
{
	int nbWidth = DigitalNumber::digitWidth();

	minNum[0] = new DigitalNumber;
	minNum[0]->setPos(10,10);
	scene.addItem(minNum[0]);
	minNum[1] = new DigitalNumber;
	minNum[1]->setPos(20+nbWidth,10);
	scene.addItem(minNum[1]);

	scene.addLine(2*nbWidth+30, 25, 2*nbWidth+35, 10, QPen(QBrush(QColor(0xff,0,0)), 5, Qt::SolidLine, Qt::RoundCap));

	secNum[0] = new DigitalNumber;
	secNum[0]->setPos(60+2*nbWidth,10);
	scene.addItem(secNum[0]);
	secNum[1] = new DigitalNumber;
	secNum[1]->setPos(70+3*nbWidth,10);
	scene.addItem(secNum[1]);

	scene.addLine(4*nbWidth+80, 25, 4*nbWidth+85, 10, QPen(QBrush(QColor(0xff,0,0)), 5, Qt::SolidLine, Qt::RoundCap));
	scene.addLine(4*nbWidth+90, 25, 4*nbWidth+95, 10, QPen(QBrush(QColor(0xff,0,0)), 5, Qt::SolidLine, Qt::RoundCap));

	csecNum[0] = new DigitalNumber;
	csecNum[0]->setPos(120+4*nbWidth,10);
	scene.addItem(csecNum[0]);
	csecNum[1] = new DigitalNumber;
	csecNum[1]->setPos(130+5*nbWidth,10);
	scene.addItem(csecNum[1]);
	
	scene.setSceneRect(-10,-10, 40*3 + (10+DigitalNumber::digitWidth())*6 - 10, 40+DigitalNumber::digitHeight());
}

