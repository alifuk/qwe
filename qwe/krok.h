#pragma once
#include "string"
#include "qwidget.h"
#include "krokosled.h"

using namespace std;

class krok : QWidget
{
public:
	krok();
	~krok();

	string name;


protected:
	void execute(Krokosled* _krokosled);

		
	
};

