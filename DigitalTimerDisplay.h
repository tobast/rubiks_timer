
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

#ifndef DEF_DIGITALTIMERDISPLAY
#define DEF_DIGITALTIMERDISPLAY

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <vector>

#include "DigitalNumber.h"

class DigitalTimerDisplay : public QGraphicsView
{
	public:
		DigitalTimerDisplay();
		void setTime(int min, int sec, int csec);
	
	private://meth
		void buildWidget();

	private:
		QGraphicsScene scene;
		
		DigitalNumber* minNum[2];
		DigitalNumber* secNum[2];
		DigitalNumber* csecNum[2];
};

#endif//DEF_DIGITALTIMERDISPLAY

