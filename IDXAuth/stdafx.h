// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0500		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0500	// Change this to the appropriate value to target other versions of Windows.
#endif						

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

#define SECURITY_WIN32
#define WIN32_LEAN_AND_MEAN
// Windows Header Files:
#include <windows.h>
#include <sspi.h>
//#include <ntstatus.h>
#include <ntsecapi.h>
#include <Ntsecpkg.h>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


// TODO: reference additional headers your program requires here
