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
	myConst.Print();

	//	cAr	myAr(2);
	cAr	myAr(2);
		myAr.Set(.8, 0);
		myAr.Set(-.2, 1);
		myAr.Print();

	cMa myMa(2);
	//	cMa myMa(1);
	myMa.Set(0.4, 0);
	myMa.Set(0.6, 1);
	myMa.Print();

	cConstCondVar myConstVar(1.0);
	myConstVar.Print();

	cArch myArch(1);
	myArch.Set(0.4, 0, 0);
	myArch.Set(0.6, 0, 1);
	myArch.Print();

	cGarch myGarch(1, 1);
	myGarch.Set(0.1, 0, 0);
	myGarch.Set(0.1, 0, 1);
	myGarch.Set(0.8, 0, 2);

	cNormResiduals myNormResid;
	//cDVector myResid ;
	//	myNormResid.Generate(10, myResid);
	//cout << myResid << endl;

	cStudentResiduals myStudent(5, true);
//	cDVector myResidSt ;
//		myStudent.Generate(10, myResidSt);
//		cout << myResidSt << endl;

	cCondMean myCondMean;

	myCondMean.AddOneMean(myConst);
		    myCondMean.AddOneMean(myAr);
			myCondMean.AddOneMean(myMa);
	//cout << "CondMean" << endl;
	//myCondMean.Print();

	cRegArchModel myModel;

	myModel.SetMean(myCondMean);

	//myModel.SetVar(myConstVar);
	myModel.SetVar(myGarch);
	//	myModel.SetVar(myGarch);

	myModel.SetResid(myNormResid);
	//		myModel.SetResid(myStudent) ;

	cout << "Modele : " << endl;

    cDVector myParam;
    myModel.RegArchParamToVector(myParam);
    cout << "Vecteur des paramètres" << endl << myParam << endl;

    myModel.Print();

	uint myNSimul = 10;

	cRegArchValue myValue(myNSimul);

	RegArchSimul(myNSimul, myModel, myValue);

//cout << myValue << endl;
     cout << "LLH : " << RegArchLLH(myModel, myValue) << endl;

       cRegArchGradient myGradient = cRegArchGradient(&myModel);
       uint myNParam = myModel.GetNParam();
       uint myNDistrParam = myModel.mResids->GetNParam();
       uint myNMeanVarParam = myNParam - myNDistrParam;
       cDVector myGradlt(myNParam);
       uint myDate = 7;
       cRegArchValue myAuxValue(myValue);

       for (uint t = 0; t < myNSimul; t++)
       {
           myModel.ComputeGrad(t, myValue, myGradient);
           if (t >= myNSimul - 10) //  (t <= 10)
           {
               cout << "t = " << t << endl;
               cout << "------" << endl;
               cout << "Grad Mu" << endl;
               cout << myGradient.mCurrentGradMu << endl;
               cout << "Grad Var" << endl;
               cout << myGradient.mCurrentGradVar << endl;
               cout << "Grad Sigma" << endl;
               cout << myGradient.mCurrentGradSigma << endl;
               cout << "Grad Eps" << endl;
               cout << myGradient.mCurrentGradEps << endl;
               cout << "Grad Dens" << endl;
               cout << myGradient.mCurrentGradLogDens << endl;
               cout << "Diff LogDens" << endl;
               cout << myGradient.mCurrentDiffLogDensity << endl;
               cout << "Grad diff LogDens Numerique" << endl;
           }
           myGradient.Update();
        }
    return 0;
}
