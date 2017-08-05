#ifndef STRIP_OWNERSHIP_H_
#define STRIP_OWNERSHIP_H_

// command strip ownership
#include "strip_id.h"

short DESK_BOTTOM[1] = { DESK1 };
short DESK_TOP[1]    = { DESK2 };
short DESK_ALL[2]    = { DESK1, DESK2 };

short WINDOW_1[1]    = { WINDOW1 };
short WINDOW_2[1]    = { WINDOW2 };
short WINDOW_3[1]    = { WINDOW3 };
short WINDOW_1_3[2]  = { WINDOW1, WINDOW3 };
short WINDOW_1_2[2]  = { WINDOW1, WINDOW2 };
short WINDOW_2_3[2]  = { WINDOW2, WINDOW3 };
short WINDOW_ALL[3]  = { WINDOW1, WINDOW2, WINDOW3 };

#endif