#ifndef HEADER_SignalsPanel
#define HEADER_SignalsPanel
/*
htop - SignalsPanel.h
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPLv2+, see the COPYING file
in the source distribution for its full text.
*/

#include "Panel.h"
#include <signal.h>


typedef struct SignalItem_ {
   const char* name;
   int number;
} SignalItem;

#define SIGNALSPANEL_INITSELECTEDSIGNAL SIGTERM

Panel* SignalsPanel_new(int preSelectedSignal);

#endif
