/*
	Actionaz
	Copyright (C) 2008-2010 Jonathan Mercier-Ganady

	Actionaz is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Actionaz is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.

	Contact : jmgr@jmgr.info
*/

#ifndef ACTIONPAUSEDEFINITION_H
#define ACTIONPAUSEDEFINITION_H

#include "actiondefinition.h"
#include "numberparameterdefinition.h"
#include "actionpauseinstance.h"

#include <limits.h>

namespace ActionTools
{
	class ActionPack;
	class ActionInstance;
}

class ActionPauseDefinition : public QObject, public ActionTools::ActionDefinition
{
   Q_OBJECT

public:
	explicit ActionPauseDefinition(ActionTools::ActionPack *pack)
	: ActionDefinition(pack)
	{
		ActionTools::NumberParameterDefinition *duration = new ActionTools::NumberParameterDefinition(ActionTools::ElementDefinition::INPUT,
																								"duration",
																								tr("Duration"),
																								this);

		duration->setTooltip(tr("The duration of the pause"));
		duration->setSuffix(tr(" ms", "milliseconds"));
		duration->setMinimum(0);
		duration->setMaximum(INT_MAX);
		duration->setDefaultValue(1000);
		addElement(duration);
	}

	QString name() const													{ return QObject::tr("Pause"); }
	QString id() const														{ return "ActionPause"; }
	Flag flags() const														{ return ActionDefinition::flags() | Official; }
	QString description() const												{ return QObject::tr("Pauses the script execution"); }
	ActionTools::ActionInstance *newActionInstance() const					{ return new ActionPauseInstance(this); }
	Category category() const												{ return Internal; }
	QPixmap icon() const													{ return QPixmap(":/actions/icons/pause.png"); }

private:
	Q_DISABLE_COPY(ActionPauseDefinition)
};

#endif // ACTIONPAUSEDEFINITION_H