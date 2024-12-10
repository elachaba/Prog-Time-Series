#include "StdAfxRegArchLib.h"
/*!
	\file cAr.cpp
	\brief sources for class cAr methods.

	\author Jean-Baptiste Durand, Ollivier TARAMASCO
	\date dec-18-2006 - Last change feb-18-2011
*/

namespace RegArchLib {
	/*!
	 * \fn cAr::cAr(const uint theNAr):cAbstCondMean(eAr)
	 * \param const uint theNAr: number of AR lags.
	 */
	cAr::cAr(const uint theNAr):cAbstCondMean(eAr)
	{
        mvAr.ReAlloc(theNAr);
	}

	/*!
	 * \fn cAr::cAr(const cDVector& theAr):cAbstCondMean(eAr)
	 * \param const cDVector& theAr: vector of AR coefficients.
	 */
	cAr::cAr(const cDVector& theAr):cAbstCondMean(eAr)
	{
        mvAr = theAr;
	}

	/*!
	 * \fn cAr::cAr(cAbstCondMean& theAbstCondMean)
	 * \param const ccAbstCondMean& theAbstCondMean: the cAr source.
	 */
	cAr::cAr(const cAr& theAr):cAbstCondMean(eAr)
	{
        mvAr = theAr.mvAr;
	}

	/*!
	 * \fn cAr::~cAr()
	 */
	cAr::~cAr()
	{
        mvAr.Delete();
	}

	/*!
	 * \fn void cAr::Delete(void)
	 * \param void
	 */
	void cAr::Delete(void)
	{
        mvAr.Delete();
	}

	/*!
	 * \fn void cAr::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
#ifndef _RDLL_
	void cAr::Print(ostream& theOut) const
	{
        theOut << "AR(" << mvAr.GetSize() << ") model with:" << endl;
        for (uint i = 0; i < mvAr.GetSize(); i++)
            cout << "AR(" << i+1 << ") " << mvAr[i] << endl;
        theOut << endl;
	}
#endif // _RDLL_

	/*!
	 * \fn void cAr::Set(const double theValue, const uint theIndex, const uint theNumParam)
	 * \brief fill the parameters vector
	 * \param const double theValue: the value of the "theIndex" th lag. Default 0.
	 * \param const uint theIndex: the index.
	 * \param const uint theNumParam: not used for AR model. Default 0.
	 * \details mvAr[theIndex] = theValue
	 */
	void cAr::Set(const double theValue, const uint theIndex, const uint theNumParam)
	{
        if (theIndex < mvAr.GetSize())
            mvAr[theIndex] = theValue;
        else
            cError("cAR: theIndex must be < Ar size.");
    }

	/*!
	 * \fn void cAr::Set(const cDVector& theVectParam, const uint theNumParam)
	 * \brief fill the parameters vector
	 * \param const cDVector& theVectParam: the vector of AR param
	 * \param const uint theNumParam: not used for AR model. Default 0.
	 * \details mvAr = theVectParam
	 */
	void cAr::Set(const cDVector& theVectParam, const uint theNumParam)
	{
        mvAr = theVectParam;
	}

	/*!
	 * \fn void cAr::ReAlloc(const uint theSize, const uint theNumParam)
	 * \param const uint theSize: new size of mvAr
	 * \param const uint theNumParam; not used here.
	 * \details new allocation of mvAr
	 */

	double  cAr::Get(const uint theIndex, const uint theNumParam)
	{
		if (theIndex < mvAr.GetSize())
            return mvAr[theIndex];
        else
            cError("cAR: theIndex must be < Ar size.");
	}

	cDVector&  cAr::Get(const uint theNumParam)
	{
		return mvAr;
	}

	void cAr::ReAlloc(const uint theSize, const uint theNumParam)
	{
		mvAr.ReAlloc(theSize) ;
	}

	/*!
	 * \fn void cAr::ReAlloc(const cDVector& theVectParam, const uint theNumParam)
	 * \param const cDVector& theVectParam: the vector of AR coefficients
	 * \param const uint theNumParam: not used here.
	 * \details new allocation of mvAr
	 */
	void cAr::ReAlloc(const cDVector& theVectParam, const uint theNumParam)
	{
		mvAr = theVectParam ;
	}

	/*!
	 * \fn cAbstCondMean& cAr::operator =(cAbstCondMean& theSrc)
	 * \param cAbstCondMean& theSrc: source to be recopied
	 * \details An error occurs if theSrc is not an cAr class parameter 
	 */
	cAr& cAr::operator =(const cAr& theSrc)
	{
		mvAr = theSrc.mvAr ;
		return *this ;
	}


	/*!
	 * \fn double cAr::ComputeMean(uint theDate, const cRegArchValue& theData) const
	 * \brief Compute conditional mean component for an AR model
	 * \param int theDate: date of the computation
	 * \param const cRegArchValue& theData: past datas.
	 * \details theData is not updated here.
	 */
	double cAr::ComputeMean(uint theDate, const cRegArchValue& theData) const
	{
        double myResult = 0;
        for (uint i = 0; i < MIN(mvAr.GetSize(), theDate); i++)
            myResult += mvAr[i] * theData.mYt[theDate - (i + 1)];

        return myResult;
	}

	uint cAr::GetNParam(void) const
	{
        return mvAr.GetSize();
	}

	uint cAr::GetNLags(void) const
	{
        return mvAr.GetSize();
	}

}//namespace
