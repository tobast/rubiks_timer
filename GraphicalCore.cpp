
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

#include "GraphicalCore.h"

GraphicalCore::GraphicalCore() : csecEllapsed(0), k1pressed(false), k2pressed(false), statePressed(false), noLaunch(false)
{
	buildWidget();
	setFocusPolicy(Qt::StrongFocus);

	timer.setInterval(10);
	connect(&timer, SIGNAL(timeout()), this, SLOT(time10ms()));
	setFocus();
}

void GraphicalCore::time10ms()
{
	csecEllapsed++;
	updateDisplay();
}

void GraphicalCore::showAboutDial()
{
	AboutDialog::create();
}

void GraphicalCore::rollScramble(bool maxLength)
{
	scramble->setText(QString("<font size=\"4\">") + QString((maxLength) ? maxLengthVoidScramble() : randomScramble()) + "</font>");
}

void GraphicalCore::refocus()
{
	setFocus();
}

QString GraphicalCore::numberWithDigits(int num, int nbDigits)
{
	QString out = QString::number(num);
	while(out.size()<nbDigits)
		out.insert(0,'0');
	return out;
}

void GraphicalCore::buildWidget()
{
	setWindowTitle("RubiksTimer");
	setWindowIcon(QIcon(":/icons/softIcon"));

	l_main=new QVBoxLayout;

	l_scramble = new QHBoxLayout;
	scramble = new QLabel();
	scramble->setAlignment(Qt::AlignCenter);
	l_scramble->addWidget(scramble);
	rollScramble(true);
	scramble->setMinimumWidth(scramble->width());
	rollScramble();
	b_rollScramble = new QPushButton("Roll");
	connect(b_rollScramble, SIGNAL(clicked()), this, SLOT(rollScramble()));
	l_scramble->addWidget(b_rollScramble);
	l_main->addLayout(l_scramble);

	digitalTimerDisplay = new DigitalTimerDisplay();
	l_main->addWidget(digitalTimerDisplay);

	l_bottom = new QHBoxLayout;
	instructions = new QLabel("Hold down Space and Enter keys, then let them go when you're ready!\nHold them back to end the timer. Good luck!");
	instructions->setAlignment(Qt::AlignCenter);
	l_bottom->addWidget(instructions);
	b_showAbout = new QPushButton("About...");
	connect(b_showAbout, SIGNAL(clicked()), this, SLOT(showAboutDial()));
	l_bottom->addWidget(b_showAbout);
	l_main->addLayout(l_bottom);

	setLayout(l_main);
	updateDisplay();

}

void GraphicalCore::updateDisplay()
{
	int csec = csecEllapsed%100;
	int sec = csecEllapsed/100;
	int min = sec/60;
	sec -= min*60;

	digitalTimerDisplay->setTime(min, sec, csec);
}

void GraphicalCore::keyPressEvent(QKeyEvent* e)
{
	if(e->isAutoRepeat())
		return;
	
	if(e->key() == Qt::Key_Space)
		k1pressed=true;
	else if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return)
		k2pressed=true;
	else
		return;
	
	onKeyEvent();
}

void GraphicalCore::keyReleaseEvent(QKeyEvent* e)
{
	if(e->isAutoRepeat())
		return;
	
	if(e->key() == Qt::Key_Space)
		k1pressed=false;
	else if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return)
		k2pressed=false;
	else
		return;
	
	onKeyEvent();
	QWidget::keyReleaseEvent(e);
}

void GraphicalCore::onKeyEvent()
{
	if(timer.isActive())
	{
		if(k1pressed && k2pressed)
		{
			timer.stop();
			noLaunch=true;
			rollScramble();
		}
	}
	else
	{
		if(statePressed && !k1pressed && !k2pressed)
		{
			if(noLaunch)
				noLaunch=false;
			else
			{
				csecEllapsed=0;
				timer.start();
			}
		}
	}

	if(k1pressed && k2pressed)
		statePressed=true;
	else if(!k1pressed && !k2pressed)
		statePressed=false;
}

void GraphicalCore::focusOutEvent(QFocusEvent* e)
{
	setFocus();
	e->accept();
}

