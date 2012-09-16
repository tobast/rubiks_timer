
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

#ifndef DEF_GRAPHICALCORE
#define DEF_GRAPHICALCORE

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QLabel>
#include <QKeyEvent>
#include <QString>
#include <QIcon>
#include <QPushButton>

#include "DigitalTimerDisplay.h"
#include "AboutDialog.h"
#include "scrambleGen.h"

class GraphicalCore : public QWidget
{
	Q_OBJECT
	public:
		GraphicalCore();

	private slots:
		void time10ms();
		void showAboutDial();
		void rollScramble();

	private://meth
		QString numberWithDigits(int num, int nbDigits);
		void buildWidget();
		void updateDisplay();

		void keyPressEvent(QKeyEvent* e);
		void keyReleaseEvent(QKeyEvent* e);
		void onKeyEvent();

	private:
		QVBoxLayout* l_main;
		QHBoxLayout* l_scramble;
		QLabel* scramble;
		QPushButton* b_rollScramble;
		DigitalTimerDisplay* digitalTimerDisplay;
		QHBoxLayout* l_bottom;
		QLabel* instructions;
		QPushButton* b_showAbout;

		QTimer timer;

		long csecEllapsed; // csed = sec/100

		bool k1pressed;
		bool k2pressed;
		bool statePressed;

		bool noLaunch;
};

#endif//DEF_GRAPHICALCORE

