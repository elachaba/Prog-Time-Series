#include "StdAfxRegArchLib.h"
/*!
 \file cStudentResiduals.cpp
 \brief implementation of the class for Student conditional distribution.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO
 \date dec-18-2006 - Last change apr-7-2019
*/
namespace RegArchLib {
	/*!
	 * \fn cStudentResiduals::cStudentResiduals(double theDof, bool theSimulFlag)
	 * \param double theDof: number of degrees of freedom 
	 * \param bool theSimulFlag: true if created for simulation
	 * \details: mvBool is initialised by ce cAbstResiduals constructor
	 */
	cStudentResiduals::cStudentResiduals(double theDof, bool theSimulFlag): cAbstResiduals(eStudent, NULL, theSimulFlag)
	{
	}

	/*!
	 * \fn cStudentResiduals::cStudentResiduals(const cDVector* theDistrParameter, bool theSimulFlag): cAbstResiduals(eStudent, theDistrParameter, theSimulFlag)
	 * \param const cDVector* theDistrParameter: theDistrParameter[0] = d.o.f.
	 * \param bool theSimulFlag: true if created for simulation
	 * \details: mvBool is initialised by ce cAbstResiduals constructor
	 */
	cStudentResiduals::cStudentResiduals(cDVector* theDistrParameter, bool theSimulFlag): cAbstResiduals(eStudent, theDistrParameter, theSimulFlag)
	{
	}

	cStudentResiduals::cStudentResiduals(const cStudentResiduals& theSrc) : cAbstResiduals(eStudent, theSrc.mDistrParameter, (theSrc.mtR != NULL))
	{
	}

	/*!
	 * \fn cStudentResiduals::~cStudentResiduals()
	 */
	cStudentResiduals::~cStudentResiduals()
	{
	}

	/*!
	 * \fn void cStudentResiduals::Generate(const uint theNSample, cDVector& theYt) const
	 * \param const uint theNSample: the sample size
	 * \param cDVector& theYt: the output vector
	 */
	void cStudentResiduals::Generate(const uint theNSample, cDVector& theYt) const
	{
        double myDof = (*mDistrParameter)[0];
        if (myDof <= 2)
            cError("cStudent : d.o.f must be >2 \n");
        double myStd = sqrt(myDof/(myDof-2));
        theYt.ReAlloc(theNSample);
        for(uint t = 0; t<theNSample; t++) {
            theYt[t] = gsl_ran_tdist(mtR, myDof) / myStd;
        }
	}

	/*!
	 * \fn void cStudentResiduals::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
#ifndef _RDLL_
	void cStudentResiduals::Print(ostream& theOut) const
	{
		theOut << "Conditional Student Distribution with " << (*mDistrParameter)[0] << " d. o. f." << endl ;
	}
#endif // _RDLL_

	double cStudentResiduals::LogDensity(double theX) const
	{
	}

	/*!
	 * \fn double cStudentResiduals::GetNParam(void) const
	 * \param void.
	 * \brief return 1: One parameter for St(n) residuals.
	 */
	uint cStudentResiduals::GetNParam(void) const
	{
	}


}//namespace
