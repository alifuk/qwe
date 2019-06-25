#include "krokosled.h"
#include <vector>
#include <krok.h>


Krokosled::Krokosled()
{
}


int Krokosled::rowCount(const QModelIndex & parent) const
{
	return 0;
}

QVariant Krokosled::data(const QModelIndex & index, int role) const
{
	return QVariant();
}

Krokosled::~Krokosled()
{
}
