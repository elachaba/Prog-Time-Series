#pragma once 
#ifndef _CAR_H_
#define _CAR_H_

#include "cAbstCondMean.h"
#include "cRegArchValue.h"
#include "cRegArchGradient.h"

/*!
	\file cAr.h
	\brief header for class cAr.

	\author Jean-Baptiste DURAND, Ollivier TARAMASCO
	\date dec-18-2006 - Last change feb-18-2011
*/
/*
	mm(t, Teta) = F(Teta, ui, hj) = somme(i=1 � p, AR(i) Y(t-i))
	gradtetaF = (Y(t-1), ..., Y(t-i))
	hesstetaF = 0 (pxp)
*/
namespace RegArchLib {
	/*! 
	 * \class cAr
	 * \brief  Class to implement an AR model
	 */
	class cAr: public cAbstCondMean
	{
	private :
		cDVector mvAr ; ///< Vector of AR coefficients.
	public :
		cAr(const uint theNAr = 0) ; ///< A simple constructor
		cAr(const cDVector& theAr) ; ///< Another constructor
		cAr(const cAr& theAr) ; /// Recopy constructor
		virtual ~cAr() ;  ///< aA simple destructor
	//	cAbstCondMean* PtrCopy(void) ; /// < Return a copy of *this
		void Delete(void) ; ///< Delete mvAr
	#ifndef _RDLL_
		void Print(ostream& theOut = cout) const; ///< print the parameters
	#else
		void Print(void);
	#endif //_RDLL_

		void Set(const double theValue, const uint theIndex = 0, const uint theNumParam = 0); ///< Set model parameters.
		void Set(const cDVector& theVectParam, const uint theNumParam=0) ; ///< Set model parameters.
		double Get(const uint theIndex, const uint theNumParam) ;
		cDVector& Get(const uint theNumParam);
		void ReAlloc(const uint theSize, const uint theNumParam=0) ; ///< Allocation of the model parameters
		void ReAlloc(const cDVector& theVectParam, const uint theNumParam=0) ; ///< Allocation of the model parameters
		cAr& operator=(const cAr& theSrc) ; ///< Standard affectation
		void ReAllocProxyMeanParameters(uint theOldNParam = 0) {};
		double ComputeMean(uint theDate, const cRegArchValue& theData) const; ///< Compute the conditional mean value
		uint GetNParam(void) const;
		uint GetNLags(void) const ;
		void RegArchParamToVector(cDVector& theDestVect, uint theIndex);
		void VectorToRegArchParam(const cDVector& theSrcVect, uint theIndex = 0);
		void ComputeGrad(uint theDate, const cRegArchValue& theData, cRegArchGradient& theGradData, uint theBegIndex);
	};
}
#endif // _CAR_H_
