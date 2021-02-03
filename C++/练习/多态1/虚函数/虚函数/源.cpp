#include"AAA.h"

void DeleteFish(Fish *PFish)
{
	delete PFish;
}
int main()
{
	Tuna *ptuna = new Tuna;
	DeleteFish(ptuna);
	Fish PFish;
	PFish.printf();
	cout << endl;
	Tuna mtuna;
	mtuna.printf();
	return 0;
}