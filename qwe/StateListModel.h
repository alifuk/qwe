#pragma once

#include <QAbstractListModel>
#include "krokosled.h"

using namespace std;

class StateListModel : public QAbstractListModel {
		Q_OBJECT

public:
	StateListModel();
	~StateListModel();

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;

	void addState();
	void removeCurrentState();

private:
	vector<Krokosled>* states;
	int number_of_states;


};

