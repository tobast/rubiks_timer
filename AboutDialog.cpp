
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

#include "AboutDialog.h"

AboutDialog::AboutDialog() 
{
	buildWidget();
}

void AboutDialog::buildWidget()
{
	l_main = new QVBoxLayout;

	l_head = new QHBoxLayout;
	l_head->addLabel(QPixmap(":/icons/softIcon"));

	QVBoxLayout l_headtext* = new QVBoxLayout;
	l_headtext->addWidget(new QLabel(QString("<font size=\"10\"><b>")+QString(APPNAME)+"</b></font>"));
	l_headtext->addWidget(new QLabel(QString("<span align=\"right\">")+QString(VERSION)+"</span>"));
	l_head->addLayout(l_headtext);
	l_main->addLayout(l_head);

	returnButton = new QPushButton("Ok");
	connect(returnButton, SIGNAL(clicked()), this, SLOT(close()));
	l_main->addWidget(returnButton);

	setLayout(l_main);
}

