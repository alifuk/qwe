#pragma once

#include "krok.h"

class KrokyGeneral
{
public:
	KrokyGeneral();
	~KrokyGeneral();
};

class Krok_rotate : Krok {
protected:
	void execute(Krokosled* _krokosled);

};