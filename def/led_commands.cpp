/*
  Dorm LED Project: led_commands.cpp
  This file contains the Command definitions for all command functions.

  These are *ready* to be queued up and executed using the multithreaded handler.

  Created by: Michael Fischler
  10/23/2016 @ WPI
*/

std::vector<int> empty;

const Strip bottomdesk[1] = {DESK1};
const Strip topdesk[1]    = {DESK2};
const Strip alldesk[2]    = {DESK1, DESK2};

const Strip win1[1]   = {WINDOW1};
const Strip win2[1]   = {WINDOW2};
const Strip win3[1]   = {WINDOW3};
const Strip win12[2]  = {WINDOW1, WINDOW2};
const Strip win13[2]  = {WINDOW1, WINDOW3};
const Strip win23[2]  = {WINDOW2, WINDOW3};
const Strip allwin[3] = {WINDOW1, WINDOW2, WINDOW3};


/* ~~~~~~ Desk Commands ~~~~~~ */

// Every LED for Desk 1 set to {0,0,0}
Command desk1Off = Command("Desk[1]: Off",
                            bottomdesk,
                            desk1_off,
                            empty);

// Every LED for Desk 2 set to {0,0,0}
Command desk2Off = Command("Desk[2]: Off",
                            topdesk,
                            desk2_off,
                            empty);

// Every LED set to {0,0,0}
Command deskBothOff = Command("Desk[all]: Off",
                                alldesk,
                                desks_off,
                                empty);

// Every third LED gets a red tinted white
Command deskBothDimAmbient = Command("Desk[all]: Dim Ambient",
                                      alldesk,
                                      desk_both_dim_ambient,
                                      empty);

// Every third LED stays nice reddish white while the others fade in and out a calm purple
int _d_wppf[] = {0,1};
std::vector<int> d_wppf (_d_wppf, _d_wppf + sizeof(_d_wppf) / sizeof(int));
Command deskBothWhitePurplePurpleFade = Command("Desk[all]: White with Purple Fade",
                                                alldesk,
                                                desk_both_wpp_fade,
                                                d_wppf);

/* ~~~~~~ Window Commands ~~~~~~ */

// Every LED fades in and out a with calm purple
int _w_pf[] = {0,1};
std::vector<int> w_pf (_w_pf, _w_pf + sizeof(_w_pf) / sizeof(int));
Command winAllPurpleFade = Command("Window[all]: Purple Fade",
                                    allwin,
                                    win_all_wpp_fade,
                                    w_pf);
