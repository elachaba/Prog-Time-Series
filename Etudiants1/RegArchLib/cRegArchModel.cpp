#include "StdAfxRegArchLib.h"

namespace RegArchLib {

	/*!
	 * \fn cRegArchModel::cRegArchModel()
	 * \param None
	 * \details A simple constructor
	 */
	cRegArchModel::cRegArchModel()
	{
        mMean = NULL;
        mVar = NULL;
        mResids = NULL;
	}

	/*!
	 * \fn cRegArchModel::cRegArchModel(cCondMean* theMean, cAbstCondVar* theVar, cAbstResiduals* theResiduals)
	 * \param cCondMean* theMean: pointer to conditional mean model
	 * \param cAbstCondVar* theVar: pointer to conditional variance model
	 * \param cAbstResiduals* theResiduals: pointer to conditional residuals distribution model
	 * \details A simple constructor
	 */
	cRegArchModel::cRegArchModel(cCondMean& theMean, cAbstCondVar& theVar, cAbstResiduals& theResiduals)
	{
        if (mMean != NULL)
            delete mMean;
        mMean = new cCondMean(theMean);
        if (mVar != NULL)
            delete mVar;
        mVar = CreateOneRealCondVar(theVar);
        if (mResids != NULL)
            delete mResids;
        mResids = CreateRealCondResiduals(theResiduals);
	}

	/*!
	 * \fn cRegArchModel::cRegArchModel(cRegArchModel& theModel)
	 * \param cRegArchModel& theModel: the source
	 * \details recopy constructor
	 */
	cRegArchModel::cRegArchModel(const cRegArchModel& theModel)
	{
        if (mMean != NULL)
            delete mMean;
        mMean = new cCondMean(*(theModel.mMean));
        if (mVar != NULL)
            delete mVar;
        mVar = CreateOneRealCondVar(*(theModel.mVar));
        if (mResids != NULL)
            delete mResids;
        mResids = CreateRealCondResiduals(*(theModel.mResids));
	}

	/*!
	 * \fn cRegArchModel::~cRegArchModel()
	 */
	cRegArchModel::~cRegArchModel()
	{
        if (mMean != NULL) {
            delete mMean;
            mMean = NULL;
        }
        if (mVar != NULL) {
            delete mVar;
            mVar = NULL;
        }
        if (mResids != NULL) {
            delete mResids;
            mResids = NULL;
        }

	}

	/*!
	 * \fn cRegArchModel& cRegArchModel::operator=(cRegArchModel& theRegArchModel)
	 * \param cRegArchModel& theRegArchModel: the source
	 * \details = operator for cRegArchModel
	 */
	cRegArchModel& cRegArchModel::operator=(cRegArchModel& theRegArchModel)
	{
        if (mMean != NULL) {
            mMean->Delete();
            mMean = NULL;
        }
        if (theRegArchModel.mMean != NULL)
            mMean = new cCondMean(*(theRegArchModel.mMean));

        if (mVar != NULL) {
            mVar->Delete();
            mVar = NULL;
        }
        if (theRegArchModel.mVar != NULL)
            mVar = CreateOneRealCondVar(*(theRegArchModel.mVar));

        if (mResids != NULL) {
            mResids->Delete();
            mResids = NULL;
        }
        if (theRegArchModel.mResids != NULL)
            mResids = CreateRealCondResiduals(*(theRegArchModel.mResids));
	}

	void cRegArchModel::Delete(void)
	{
        if (mMean != NULL) {
            mMean->Delete();
            mMean = NULL;
        }

        if (mVar != NULL) {
            mVar->Delete();
            mVar = NULL;
        }

        if (mResids != NULL) {
            mResids->Delete();
            mResids = NULL;
        }
	}

	/*!
	 * \fn void cRegArchModel::SetMean(cCondMean& theCondMean)
	 * \param cCondMean& theCondMean: the conditional mean model
	 */
	void cRegArchModel::SetMean(cCondMean& theCondMean)
	{
        if (mMean != NULL)
            mMean->Delete();
        mMean = new cCondMean(theCondMean);
	}

	/*!
	 * \fn void cRegArchModel::GetNMean(void)
	 * \param void
	 * \details return the number of mean components
	 */
	int cRegArchModel::GetNMean(void)
	{
        return (mMean != NULL) ? mMean->GetNMean() : 0;

	}

	/*!
	 * \fn void cRegArchModel::AddOneMean(cAbstCondMean& theOneMean)
	 * \param cAbstCondMean& theOneMean: the conditional mean component model
	 * \details Add a new mean component
	 */
	void cRegArchModel::AddOneMean(cAbstCondMean& theOneMean)
	{
        if (mMean != NULL)
            mMean->AddOneMean(theOneMean);
        else
            cError("cRegArchModel::AddOneMean : mMean is NULL");
	}

	/*!
	 * \fn void cRegArchModel::GetOneMean(int theNumMean)
	 * \param int theNumMean: the index of the mean component
	 * \details Return theNumMean th mean component
	 */
	cAbstCondMean* cRegArchModel::GetOneMean(int theNumMean)
	{
        if (mMean != NULL) {
            if (theNumMean < MAX_COND_MEAN)
                return mMean->GetOneMean(theNumMean);
            else
                cError("cRegArchModel::GetOneMean : Index out of range");
        }

	}

	bool cRegArchModel::IsGoodMeanType(eCondMeanEnum theMeanEnum, int theIndex)
	{
	}

#ifndef _RDLL_
	
	/*!
	* \fn void cRegArchModel::PrintMean(ostream& theOut) const
	* \param ostream& theOut: output stream (screen or file). Default: cout
	*/
	void cRegArchModel::PrintMean(ostream& theOut) const
    {
        if (mMean != NULL)
            mMean->Print(theOut);
	}

	/*!
	* \fn void cRegArchModel::PrintVar(ostream& theOut) const
	* \param ostream& theOut: output stream (screen or file). Default: cout
	*/
	void cRegArchModel::PrintVar(ostream& theOut) const
	{
        if (mVar != NULL)
            mVar->Print(theOut);
	}
	/*!
	* \fn void cRegArchModel::PrintResiduals(ostream& theOut) const
	* \param ostream& theOut: output stream (screen or file). Default: cout
	*/
	void cRegArchModel::PrintResiduals(ostream& theOut) const
	{
        if (mResids != NULL)
            mResids->Print(theOut);
	}

	/*!
	* \fn void cRegArchModel::Print(ostream& theOut) const
	* \param ostream& theOut: output stream (screen or file). Default: cout
	*/
	void cRegArchModel::Print(ostream& theOut) const
	{
        theOut << "Regression with ARCH type residuals" << endl;
        theOut << "-----------------------------------" << endl;
        PrintMean(theOut);
        PrintVar(theOut);
        PrintResiduals(theOut);
	}
#endif //_RDLL_
	/*!
	 * \fn void cRegArchModel::SetVar(cAbstCondVar& theCondVar)
	 * \param cCondVar& theCondVar: the conditional variance model
	 */
	void cRegArchModel::SetVar(cAbstCondVar& theCondVar)
	{
        if (mVar != NULL)
        {
            mVar->Delete();
            mVar = NULL;
        }
        mVar = CreateOneRealCondVar(theCondVar);
	}

	cAbstCondVar* cRegArchModel::GetVar(void)
	{
	}

	/*!
	 * \fn void cRegArchModel::SetResid(cAbstResiduals& theCondResiduals)
	 * \param cAbstResiduals& theCondResiduals: the conditional residuals model
	 */
	void cRegArchModel::SetResid(cAbstResiduals& theCondResiduals)
	{
	}

	cAbstResiduals*  cRegArchModel::GetResid(void)
	{
	}

	uint cRegArchModel::GetNParam(void) const
    {
    }

	uint cRegArchModel::GetNLags(void) const
    {
    }
	
}//namespace

