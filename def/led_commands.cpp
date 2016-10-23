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

// Every third LED fades in and out purple
int tpf[] = {0,1};
std::vector<int> thirdpurplefade (tpf, tpf + sizeof(tpf) / sizeof(int));
Command deskBothThirdPurpleFade = Command("Desk[all]: Third Purple Fade",
                                      alldesk,
                                      desk_both_third_purple_fade,
                                      thirdpurplefade);

/* ~~~~~~ Window Commands ~~~~~~ */
