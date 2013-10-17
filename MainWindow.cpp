
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

#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent)
{
	buildWidget();
}

void MainWindow::buildWidget()
{
	centralWidget = new GraphicalCore();
	setCentralWidget(centralWidget);

	m_view = menuBar()->addMenu(tr("&View"));
	a_dispScramble = m_view->addAction(tr("Display scramble"));
	a_dispScramble->setCheckable(true);

	m_timer = menuBar()->addMenu(tr("&Timer"));
	ag_timerStartSelect = new QActionGroup(m_timer);
	a_spaceEnter = m_timer->addAction(tr("Start with space and enter"));
	a_spaceEnter->setCheckable(true);
	a_spaceEnter->setActionGroup(ag_timerStartSelect);
	a_anykey = m_timer->addAction(tr("Start with any key"));
	a_anykey->setCheckable(true);
	a_anykey->setActionGroup(ag_timerStartSelect);
	ag_timerStartSelect->setExclusive(true);
}

