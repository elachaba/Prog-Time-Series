// Test.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "StdAfxTestCPlusPlus.h"

using namespace std;
using namespace ErrorNameSpace;
using namespace VectorAndMatrixNameSpace;
using namespace RegArchLib;

int main(int argc, char* argv[])
{

 	cout.precision(4);
	fixed;


	cConst myConst(10);

	//	cAr	myAr(2);
	cAr	myAr(1);
	myAr.Set(.8, 0);
	//	myAr.Set(-.2, 1);

	cMa myMa(2);
	//	cMa myMa(1);
	myMa.Set(0.4, 0);
	myMa.Set(0.6, 1);

	cConstCondVar myConstVar(1.0);

	cArch myArch(1);
	myArch.Set(0.4, 0, 0);
	myArch.Set(0.6, 0, 1);

	cGarch myGarch(1, 1);
	myGarch.Set(0.1, 0, 0);
	myGarch.Set(0.1, 0, 1);
	myGarch.Set(0.8, 0, 2);

	cNormResiduals myNormResid;
	cStudentResiduals myStudent(5, true);

	cCondMean myCondMean;

	myCondMean.AddOneMean(myConst);
	//	    myCondMean.AddOneMean(myAr);
	//		myCondMean.AddOneMean(myMa);

	cRegArchModel myModel;

	myModel.SetMean(myCondMean);

	myModel.SetVar(myConstVar);
	//	myModel.SetVar(myArch);
	//	myModel.SetVar(myGarch);

	myModel.SetResid(myNormResid);
	//		myModel.SetResid(myStudent) ;

	cout << "Modele : " << endl;
    cout << endl;
	myModel.Print();

    myMa.Print();
    myAr.Print();

	uint myNSimul = 100;

	cRegArchValue myValue(myNSimul);


	RegArchSimul(myNSimul, myModel, myValue);

	cout << myValue << endl;


	return 0;
}
