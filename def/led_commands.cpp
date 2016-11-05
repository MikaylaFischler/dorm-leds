/*
  Dorm LED Project: led_commands.cpp
  This file contains the Command definitions for all command functions.

  These are *ready* to be queued up and executed using the multithreaded handler.

  Created by: Michael Fischler
  10/23/2016 @ WPI
*/

LocalStack* basic = new LocalStack(0);

const int bottomdesk[1] = {DESK1};
const int topdesk[1]    = {DESK2};
const int alldesk[2]    = {DESK1, DESK2};

const int win1[1]   = {WINDOW1};
const int win2[1]   = {WINDOW2};
const int win3[1]   = {WINDOW3};
const int win12[2]  = {WINDOW1, WINDOW2};
const int win13[2]  = {WINDOW1, WINDOW3};
const int win23[2]  = {WINDOW2, WINDOW3};
const int allwin[3] = {WINDOW1, WINDOW2, WINDOW3};


/* ~~~~~~ Desk Commands ~~~~~~ */

// Every LED for Desk 1 set to {0,0,0}
Command desk1Off = Command("Desk[1]: Off",
                            bottomdesk,
                            1,
                            desk1_off,
                            basic);

// Every LED for Desk 2 set to {0,0,0}
Command desk2Off = Command("Desk[2]: Off",
                            topdesk,
                            1,
                            desk2_off,
                            basic);

// Every LED set to {0,0,0}
Command deskBothOff = Command("Desk[all]: Off",
                                alldesk,
                                2,
                                desks_off,
                                basic);

// Every third LED gets a red tinted white
Command deskBothDimAmbient = Command("Desk[all]: Dim Ambient",
                                      alldesk,
                                      2,
                                      desk_both_dim_ambient,
                                      basic);

// Every third LED stays nice reddish white while the others fade in and out a calm purple
int _d_wppf[] = {0,0,1};
LocalStack* d_wppf = new LocalStack(&_d_wppf);
Command deskBothWhitePurplePurpleFade = Command("Desk[all]: White with Purple Fade",
                                                alldesk,
                                                2,
                                                desk_both_wpp_fade,
                                                d_wppf);

/* ~~~~~~ Window Commands ~~~~~~ */

/* Animations */

// Every LED fades in and out a with calm purple
int _w_pf[] = {0,0,1};
LocalStack* w_pf = new LocalStack(&_w_pf);
Command winAllPurpleFade = Command("Window[all]: Purple Fade",
                                    allwin,
                                    3,
                                    win_all_purple_fade,
                                    w_pf);

// Every LED fades in and out a with calm purple
int _w_wpi[] = {0,0,0};
LocalStack* w_wpi = new LocalStack(&_w_wpi);
Command winAllWPISpirit = Command("Window[all]: WPI Spirit",
                                    allwin,
                                    3,
                                    win_all_WPI_spirit,
                                    w_wpi);

// Rainbow Color Wipe for first window
int _w1_rw[] = {0,0,0};
LocalStack* w1_rw = new LocalStack(&_w1_rw);
Command win1RainbowWipe = Command("Window[1]: Rainbow Color Wipe",
                                    win1,
                                    1,
                                    win_1_rainbow_wipe,
                                    w1_rw);

// Rainbow Color Wipe for second window
int _w2_rw[] = {0,0,0};
LocalStack* w2_rw = new LocalStack(&_w2_rw);
Command win2RainbowWipe = Command("Window[2]: Rainbow Color Wipe",
                                    win2,
                                    1,
                                    win_2_rainbow_wipe,
                                    w2_rw);

// Rainbow Color Wipe for third window
int _w3_rw[] = {0,0,0};
LocalStack* w3_rw = new LocalStack(&_w3_rw);
Command win3RainbowWipe = Command("Window[3]: Rainbow Color Wipe",
                                    win3,
                                    1,
                                    win_3_rainbow_wipe,
                                    w3_rw);

/* Seasonal Animations */

// Halloween

// Basic Orange/Purple Fade
int _w_hallo_f[] = {0,0,1};
LocalStack* w_hallo_f = new LocalStack(&_w_hallo_f);
Command winAllHalloweenFade = Command("Window[all]: Halloween Fade",
                                        allwin,
                                        3,
                                        win_all_halloween_fade,
                                        w_hallo_f);

// Sparkling Randomized Fade
int _w_hallo_srf[] = {0,0,0};
LocalStack* w_hallo_srf = new LocalStack(&_w_hallo_srf);
Command winAllHalloweenSparkle = Command("Window[all]: Halloween Sparkle Fade",
                                          allwin,
                                          3,
                                          win_all_halloween_sparkle,
                                          w_hallo_srf);
