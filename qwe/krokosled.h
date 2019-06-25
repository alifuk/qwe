#pragma once

#include <vector>
#include <QAbstractListModel>
#include "krok.h"


class Krokosled : public QAbstractListModel {
	Q_OBJECT

public:
	Krokosled();

	std::string name;

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;

	~Krokosled();
};

