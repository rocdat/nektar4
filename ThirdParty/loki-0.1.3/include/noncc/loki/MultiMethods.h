////////////////////////////////////
// Generated header: MultiMethods.h
// Forwards to the appropriate code
// that works on the detected compiler
// Generated on Mon Sep 30 23:14:48 2002
////////////////////////////////////

#ifdef LOKI_USE_REFERENCE
#	include "../../loki/MultiMethods.h"
#else
#	if (__INTEL_COMPILER)
#		include "../../loki/MultiMethods.h"
#	elif (__MWERKS__)
#		include "../../loki/MultiMethods.h"
#	elif (__BORLANDC__ >= 0x560)
#		include "../Borland/MultiMethods.h"
#	elif (_MSC_VER >= 1301)
#		include "../../loki/MultiMethods.h"
#	elif (_MSC_VER >= 1300)
#		include "../MSVC/1300/MultiMethods.h"
#	elif (_MSC_VER >= 1200)
#		include "../MSVC/1200/MultiMethods.h"
#	else
#		include "../../loki/MultiMethods.h"
#	endif
#endif
