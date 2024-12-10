#include "StdAfxRegArchLib.h"
/*!
 \file cMa.cpp
 \brief sources for class cMa methods.

 \author Jean-Baptiste Durand, Ollivier TMAAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*!
	 * \fn cMa::cMa(uint theNMa):cAbstCondMean(eMa)
	 * \param int theNMa: number of lags.
	 */

	cMa::cMa(uint theNMa):cAbstCondMean(eMa)
	{
        mvMa.ReAlloc(theNMa);
	}

	/*!
	 * \fn cMa::cMa(const cDVector& theMa):cAbstCondMean(eMa)
	 * \param const cDVector& theMa: vector of MA coefficients.
	 */
	cMa::cMa(const cDVector& theMa):cAbstCondMean(eMa)
	{
        mvMa = theMa;
	}

	/*!
	 * \fn cMa::cMa(cAbstCondMean& theAbstCondMean)
	 * \param const cAbstCondMean& theAbstCondMean: the cMa source.
	 */
	cMa::cMa(const cMa& theMa):cAbstCondMean(eMa)
	{
        mvMa = theMa.mvMa;
	}

	/*!
	 * \fn cMa::~cMa()


	 */
	cMa::~cMa()
	{
        mvMa.Delete();
	}

	/*!
	 * \fn void cMa::Delete(void)
	 * \param void
	 */
	void cMa::Delete(void)
	{
        mvMa.Delete();
	}

	/*!
	 * \fn void cMa::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
#ifndef _RDLL_
	void cMa::Print(ostream& theOut) const
	{
        theOut << "MA(" << mvMa.GetSize() << ") model with:" << endl;
        for (uint i = 0; i < mvMa.GetSize(); i++)
            theOut << "MA(" << i+1 << ") " << mvMa[i] << endl;
        theOut << endl;
	}
#endif //_RDLL_

	/*!
	 * \fn void cMa::Set(const double theValue, const uint theIndex=0, const uint theNumParam)
	 * \param const double theValue: the theIndex th value
	 * \param const uint theIndex: the index
	 * \param const uint theNumParam: not used here
	 * \details mvMa[theIndex] = theValue
	 */
	void cMa::Set(const double theValue, const uint theIndex, const uint theNumParam)
	{
        if (theIndex < mvMa.GetSize())
            mvMa[theIndex] = theValue;
        else
            cError("theIndex must be < Ma size.");
	}

	/*!
	 * \fn void cMa::Set(const cDVector& theVectParam, const uint theNumParam)
	 * \param const cDVector& theVectParam: the vector of MA coefficients
	 * \param const uint theNumParam: not used here
	 * \details mvMa = theVectParam
	 */
	void cMa::Set(const cDVector& theVectParam, const uint theNumParam)
	{
        mvMa = theVectParam;
	}

	double cMa::Get(const uint theIndex, const uint theNumParam)
	{
        if (theIndex < mvMa.GetSize())
            return mvMa[theIndex];
        else
            cError("theIndex must be < Ma size.");
	}

	cDVector& cMa::Get(const uint theNumParam)
	{
        return mvMa;
	}

	/*!
	 * \fn void cMa::ReAlloc(const uint theSize, const uint theNumParam)
	 * \param const uint theSize: new size of mvMA
	 * \param const uint theNumParam; not used here.
	 * \details new allocation of mvMa 
	 */
	void cMa::ReAlloc(const uint theSize, const uint theNumParam)
	{
		mvMa.ReAlloc(theSize) ;
	}

	/*!
	 * \fn void cAr::ReAlloc(const cDVector& theVectParam, const uint theNumParam)
	 * \param const cDVector& theVectParam: the vector of MA coefficients
	 * \param const uint theNumParam: not used here.
	 * \details new allocation of mvMa
	 */
	void cMa::ReAlloc(const cDVector& theVectParam, const uint theNumParam)
	{
        mvMa = theVectParam;
	}

	/*!
	 * \fn cAbstCondMean& cMa::operator =(cAbstCondMean& theSrc)
	 * \param cAbstCondMean& theSrc: source to be recopied
	 * \details An error occurs if theSrc is not an cMa class parameter
	 */
	cMa& cMa::operator =(const cMa& theSrc)
	{
        mvMa = theSrc.mvMa;
        return *this ;
	}

	/*!
	 * \fn cMa::ComputeMean(uint theDate, const cRegArchValue& theData) const
	 * \param int theDate: date of the computation
	 * \param cRegArchValue& theData: past datas.
	 * \details theData is not updated here.
	 */
	double cMa::ComputeMean(uint theDate, const cRegArchValue& theData) const
	{
        double myResult = 0;
        for (uint j = 0; j < MIN(mvMa.GetSize(), theDate); j++)
            myResult += mvMa[j] * theData.mUt[theDate - (j + 1)];

        return myResult;
	}

	uint cMa::GetNParam(void) const
	{
        return mvMa.GetSize();
	}
	
	uint cMa::GetNLags(void) const
	{
        return mvMa.GetSize();
	}

}//namespace
