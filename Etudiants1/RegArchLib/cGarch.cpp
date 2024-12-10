#include "StdAfxRegArchLib.h"
/*!
	\file cGarch.cpp
	\brief sources for class cGarch methods.

	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*!
	 * \fn cGarch::cGarch(uint theNArch, uint theNGarch):cAbstCondVar(eGarch)
	 * \param uint theNArch: number of ARCH lags
	 * \param uint theNGarch: number of GARCH lags
	*/
	cGarch::cGarch(uint theNArch, uint theNGarch)
		:cAbstCondVar(eGarch)  // call constructor of cAbstCondVar with type eGarch
	{
        mvArch.ReAlloc(theNArch);
        mvGarch.ReAlloc(theNGarch);
	}

	/*!
	 * \fn cGarch::cGarch(double theConst, cDVector& theArch, cDVector& theGarch):cAbstCondVar(eGarch)
	 * \param double theConst: constant part of the GARCH(p, q) model
	 * \param cDVector& theGarch theArch: ARCH parameters
	 * \param cDVector& theGarch theGarch: GARCH parameters
	*/
	cGarch::cGarch(double theConst, cDVector& theArch, cDVector& theGarch)
		:cAbstCondVar(eGarch)
	{
        mvConst = theConst;
        mvArch = theArch;
        mvGarch = theGarch;
	}

	/*!
	* \fn cGarch::cGarch(const cAbsCondVar& theGarch):cAbstCondVar(eGarch)
	* \param cAbsCondVar& theEgarch: theGarch class
	*/
	cGarch::cGarch(const cGarch& theGarch)
		:cAbstCondVar(eGarch)
	{
        mvConst = theGarch.mvConst;
        mvArch = theGarch.mvArch;
        mvGarch = theGarch.mvGarch;
	}

	/*!
	 * \fn cGarch::~cGarch()
	*/
	cGarch::~cGarch()
	{
        mvArch.Delete();
        mvGarch.Delete();
	}

	/*!
	 * \fn void cGarch::Delete(void)
	 * \param void
	 * \details Free memory
	 */
	void cGarch::Delete(void)
	{
        mvArch.Delete();
        mvGarch.Delete();
	}

	/*!
	 * \fn void cGarch::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
#ifndef _RDLL_
	void cGarch::Print(ostream& theOut) const
	{
        theOut << "ARCH(" << mvArch.GetSize() << ") model with:" << endl;
        theOut << "Const= " << this->mvConst << endl;
        for (uint i = 0; i < mvArch.GetSize(); i++)
            theOut << "ARCH(" << i+1 << ") " << mvArch[i] << endl;
        for (uint j = 0; j < mvGarch.GetSize(); j++)
            theOut << "GARCH(" << j+1 << ") " << mvGarch[j] << endl;
        theOut << endl;

    }
#endif //_RDLL_

	/*!
	 * \fn void cGarch::ReAlloc(const uint theSize, const uint theNumParam)
	 * \param const uint theSize: new size of mvArch or mvGarch
	 * \param const uint theNumParam: 0 for mvArch, 1 for mvGarch.
	 * \details new allocation of mvArch or mvGarch
	 */
	void cGarch::ReAlloc(const uint theSize, const uint theNumParam)
	{
        if (theNumParam == 0)
            mvArch.ReAlloc(theSize);
        else if(theNumParam == 1)
            mvGarch.ReAlloc(theSize);
	}

	/*!
	 * \fn void cGarch::ReAlloc(const cDVector& theVectParam, const uint theNumParam)
	 * \param const cDVector& theVectParam: the vector of Const, ARCH or GARCH coefficients
	 * \param const uint theNumParam: =0, the constant part; =1 the ARCH coefficients; =2 theGARCH Coefficients
	 * \details new allocation of mvArch or mvConst
	 */
	void cGarch::ReAlloc(const cDVector& theVectParam, const uint theNumParam)
	{
        if (theNumParam == 0) {
            if (theVectParam.GetSize() > 0)
                mvConst = theVectParam[0];
            else
                cError("theVectParam size must be > 0");
        }
        else if (theNumParam == 1)
            mvArch = theVectParam;
        else if (theNumParam == 2)
            mvGarch = theVectParam;
	}

	/*!
	 * \fn void cGarch::Set(const double theValue, const uint theIndex, const uint theNumParam)
	 * \brief fill the parameters vector
	 * \param const double theValue: the value of the "theIndex" th lag. Default 0.
	 * \param const uint theIndex: the index.
	 * \param const uint theNumParam: =0, mvConst, =1, ARCH parameters; =2, GARCH parameters
	 * \details mvArch[theIndex] = theValue or mvGarch[theIndex]= theValue or mvConst = theValue
	 */
	void cGarch::Set(const double theValue, const uint theIndex, const uint theNumParam)
	{
        if (theNumParam == 0) {
            mvConst = theValue;
        }
        else if (theNumParam == 1) {
            if (theIndex < mvArch.GetSize())
                mvArch[theIndex] = theValue;
            else
                cError("theIndex must be < ARCH size");
        }
        else if (theNumParam == 2) {
            if (theIndex < mvGarch.GetSize())
                mvGarch[theIndex] = theValue;
            else
                cError("theIndew must be < GARCH size");
        }
	}

	/*!
	 * \fn void cGarch::Set(const cDVector& theVectParam, const uint theNumParam)
	 * \brief fill the parameters vector
	 * \param const cDVector& theVectParam: the vector of values
	 * \param const uint theNumParam: =0, mvConst, =1, ARCH parameters; =2, GARCH parameters
	 * \details mvAr = theValue
	 */
	void cGarch::Set(const cDVector& theVectParam, const uint theNumParam)
	{
        if (theNumParam == 0) {
            if (theVectParam.GetSize() > 0)
                mvConst = theVectParam[0];
            else
                cError("theVectParam size must be > 0");
        }
        else if (theNumParam == 1)
            mvArch = theVectParam;
        else if (theNumParam == 2)
            mvGarch = theVectParam;
	}

	double  cGarch::Get(const uint theIndex, const uint theNumParam)
	{
        if (theNumParam == 0)
            return mvConst;
        if (theNumParam == 1) {
            if (theIndex < mvArch.GetSize())
                return mvArch[theIndex];
            else
                cError("theIndex must be < ARCH size");
        }
        if (theNumParam == 2) {
            if (theIndex < mvGarch.GetSize())
                return mvGarch[theIndex];
            else
                cError("theIndex must be < GARCH size");
        }
	}

	cDVector& cGarch::Get(const uint theNumParam)
	{
        if (theNumParam == 0)
            return *new cDVector(1, mvConst);
        if (theNumParam == 1)
            return mvArch;
        if (theNumParam == 2)
            return mvGarch;
	}

	cGarch& cGarch::operator =(const cGarch& theSrc)
	{
        mvConst = theSrc.mvConst;
        mvArch = theSrc.mvArch;
        mvGarch = theSrc.mvGarch;

        return *this;
	}

	/*!
	 * \fn double cGarch::ComputeVar(uint theDate, const cRegArchValue& theData) const
	 * \param int theDate: date of computation
	 * \param const cRegArchValue& theData: past datas
	 * \details theData is not updated here.
	*/
	double cGarch::ComputeVar(uint theDate, const cRegArchValue& theData) const 
	{
        double myResult = mvConst;
        for (uint i = 0; i < MIN(mvArch.GetSize(), theDate); i++)
            myResult += mvArch[i] * theData.mUt[theDate - (i + 1)];

        for (uint j = 0; j < MIN(mvGarch.GetSize(), theDate); j++)
            myResult += mvGarch[j] * theData.mHt[theDate - (j + 1)];

        return myResult;
	}

	uint cGarch::GetNParam(void) const
	{
        return 1 + mvArch.GetSize() + mvGarch.GetSize();
	}

	uint cGarch::GetNLags(void) const
	{
        return MAX(mvArch.GetSize(), mvGarch.GetSize());
	}

}//namespace
