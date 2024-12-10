#include "StdAfxRegArchLib.h"
//#include <gsl/gsl_cdf.h>
/*!
	\file RegArchCompute.cpp
	\brief implementation of the Simulation / Estimation procedures for general RegArchModel
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - last change feb-18-2011
*/


namespace RegArchLib {
	using namespace VectorAndMatrixNameSpace;


	/*!
	 * \fn void RegArchSimul(const uint theNSample, const cRegArchModel& theModel, cRegArchValue& theData)
	 * \param const uint theNSample: size of the sample
	 * \param const cRegArchModel& theModel: the RegArch model
	 * \param cRegArchValue& theData: output parameter. The Y(t) values are stored in theData.mYt
	 */
	void RegArchSimul(const uint theNSample, const cRegArchModel& theModel, cRegArchValue& theData)
	{
	}

   /*!
	 * \fn void RegArchSimul(const uint theNSample, const cRegArchModel& theModel, cDVector& theYt)
	 * \param const uint theNSample: size of the sample
	 * \param const cRegArchModel& theModel: the RegArch model
	 * \param cDVector& theYt: output parameter. 
	 */
	void RegArchSimul(const uint theNSample, const cRegArchModel& theModel, cDVector& theYt, cDMatrix* theXt, cDMatrix* theXvt)
	{
	}

	void FillValue(uint theDate, const cRegArchModel& theModel, cRegArchValue& theValue)
	{
	}

  	/*!
	 * \fn double RegArchLLH(const cRegArchModel& theModel, cDVector* theYt, cDMatrix* theXt)
	 * \param const cRegArchModel& theModel: the model
	 * \param cDVector* theYt: the observations
	 * \param cDMatrix* theXt: the regressors matrix. Default NULL
	 * \brief return the log-likelihood value
	 */
	double RegArchLLH(const cRegArchModel& theModel, cDVector* theYt, cDMatrix* theXt)
	{
	}

	/*!
	 * \fn double RegArchLLH(const cRegArchModel& theModel,cRegArchValue& theData)
	 * \param const cRegArchModel& theModel: the model
	 * \param cRegArchValue& theData: theData.mYt contains the observations.
	 * \brief return the log-likelihood value
	 */
	double RegArchLLH(const cRegArchModel& theModel, cRegArchValue& theData)
	{
	}

}
