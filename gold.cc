#include "gold.h"
using namespace std;


void Gold::setAmt(const int a)
{
	amt = a;
	setChar('G');
	if (a == 1) setDesc("Small");
	else if (a == 2) setDesc("Normal");
	else if (a == 4) setDesc("MerchantHoard");
}


int Gold::getAmt()
{
	return amt;
}
