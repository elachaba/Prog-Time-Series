// stdafx.h�: fichier Include pour les fichiers Include syst�me standard,
// ou les fichiers Include sp�cifiques aux projets qui sont utilis�s fr�quemment,
// et sont rarement modifi�s
//

#pragma once

#ifdef _MSC_VER // Compilateur MS VS
	#include "TargetVerRegArchLib.h"
#endif // _MSC_VER

#include <cmath>
#ifndef _RDLL_
	#include <iostream>
#endif //_RDLL_

#include "StdAfxError.h"
#include "StdAfxVectorAndMatrix.h"

#include "RegArchDef.h"
#include "cAbstCondMean.h"
#include "cAbstCondVar.h"
#include "cAbstResiduals.h"

#include "cConst.h"
#include "cAr.h"
#include "cMa.h"

#include "cConstCondVar.h"
#include "cArch.h"
#include "cGarch.h"

#include "cNormResiduals.h"
#include "cStudentResiduals.h"

#include "cCondMean.h"
#include "cRegArchModel.h"
#include "cRegArchValue.h"

#include "RegArchCompute.h"


#define WIN32_LEAN_AND_MEAN             // Exclure les en-t�tes Windows rarement utilis�s

