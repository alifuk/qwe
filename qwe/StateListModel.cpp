#include "StateListModel.h"
#include <string> 
#include <qmessagebox.h>

using namespace std;

StateListModel::StateListModel()
{
	states = new vector<Krokosled*>();
	number_of_states = 1;
	addState();
}


StateListModel::~StateListModel()
{
}

int StateListModel::rowCount(const QModelIndex & parent) const
{
	return states->size();
}

QVariant StateListModel::data(const QModelIndex & index, int role) const
{
	if (role == Qt::DisplayRole) {
		Krokosled* k = states->at(index.row());
		QVariant* v = new QVariant(QString::fromStdString(k->name));
		return *v;
	}

	return QVariant();
}

void StateListModel::addState()
{ 
	Krokosled* krokosled = new Krokosled();
	krokosled->name = to_string(number_of_states) ;
	states->push_back(krokosled);
	number_of_states++;
	dataChanged(QModelIndex(), QModelIndex());
}

void StateListModel::removeCurrentState()
{
}
