#pragma once

// Si vous incluez SDKDDKVer.h, cela d�finit la derni�re plateforme Windows disponible.

// Si vous souhaitez g�n�rer votre application pour une plateforme Windows pr�c�dente, incluez WinSDKVer.h et
// d�finissez la macro _WIN32_WINNT � la plateforme que vous souhaitez prendre en charge avant d'inclure SDKDDKVer.h.

#ifdef _MSC_VER // Compilateur MS Visual Studio
	#include <SDKDDKVer.h>
#endif // _MSC_VER
