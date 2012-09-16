
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

void AboutDialog::create()
{
	AboutDialog dial;
	dial.exec();
}

void AboutDialog::buildWidget()
{
	l_main = new QVBoxLayout;

	l_head = new QHBoxLayout;
	QLabel* iconLabel = new QLabel;
	iconLabel->setPixmap(QPixmap(":/icons/softIcon"));
	l_head->addWidget(iconLabel);

	QVBoxLayout* l_headtext = new QVBoxLayout;
	l_headtext->addWidget(new QLabel(QString("<font size=\"10\"><b>")+QString(APPNAME)+"</b></font>"));
	QLabel* versionLabel = new QLabel(QString("<i>")+QString(VERSION)+"</i>");
	versionLabel->setAlignment(Qt::AlignRight);
	l_headtext->addWidget(versionLabel);
	l_head->addLayout(l_headtext);
	l_main->addLayout(l_head);

	l_main->addWidget(new QLabel(QString("Software by ")+QString(AUTHOR)+QString(" <")+QString(CONTACT)+">."));
	l_main->addWidget(new QLabel(QString("Please report bugs, ideas and stuff to <")+QString(BUGREP)+">."));
	l_main->addWidget(new QLabel(QString("This software is distributed under the terms of the ")+QString(LICENCE)+QString(" licence \n<")+QString(LICENCE_URL)+">."));
	l_main->addWidget(new QLabel(QString("<br/><br/>Licence:<br/><br/>")+LICENCE_SHORT_TEXT));

	returnButton = new QPushButton("Ok");
	connect(returnButton, SIGNAL(clicked()), this, SLOT(close()));
	l_main->addWidget(returnButton);

	setLayout(l_main);
}

