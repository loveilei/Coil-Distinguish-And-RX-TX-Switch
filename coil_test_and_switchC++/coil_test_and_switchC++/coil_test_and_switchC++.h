
// coil_test_and_switchC++.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Ccoil_test_and_switchCApp:
// See coil_test_and_switchC++.cpp for the implementation of this class
//

class Ccoil_test_and_switchCApp : public CWinApp
{
public:
	Ccoil_test_and_switchCApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Ccoil_test_and_switchCApp theApp;