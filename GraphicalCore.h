
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
#include <QTimer>
#include <QLabel>
#include <QKeyEvent>
#include <QString>

class GraphicalCore : public QWidget
{
	Q_OBJECT
	public:
		GraphicalCore();

	private slots:
		void time10ms();

	private://meth
		QString numberWithDigits(int num, int nbDigits);
		void buildWidget();
		void updateDisplay();

		void keyPressEvent(QKeyEvent* e);
		void keyReleaseEvent(QKeyEvent* e);
		void onKeyEvent();

	private:
		QVBoxLayout* l_main;
		QLabel* timerDisplay;
		QLabel* instructions;

		QTimer timer;

		long csecEllapsed; // csed = sec/100

		bool k1pressed;
		bool k2pressed;
		bool statePressed;

		bool noLaunch;
};

#endif//DEF_GRAPHICALCORE

