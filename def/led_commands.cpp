/*
  Dorm LED Project: led_commands.cpp
  This file contains the Command definitions for all command functions.

  These are *ready* to be queued up and executed using the multithreaded handler.

  Created by: Michael Fischler
  10/23/2016 @ WPI
*/

//LocalStack* basic = new LocalStack(0);

const bool true_ptr = true;
const bool false_ptr = false;

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
/*
// Every LED for Desk 1 set to {0,0,0}
Command* desk1Off = new Command("Desk[1]: Off",
                            bottomdesk,
                            1,
                            desk1_off,
                            basic);

// Every LED for Desk 2 set to {0,0,0}
Command* desk2Off = new Command("Desk[2]: Off",
                            topdesk,
                            1,
                            desk2_off,
                            basic);

// Every LED set to {0,0,0}
Command* deskBothOff = new Command("Desk[all]: Off",
                                alldesk,
                                2,
                                desks_off,
                                basic);

// Every third LED gets a red tinted white
Command* deskBothDimAmbient = new Command("Desk[all]: Dim Ambient",
                                      alldesk,
                                      2,
                                      desk_both_dim_ambient,
                                      basic);
*/
// Every third LED stays nice reddish white while the others fade in and out a calm purple
/*void* _d_wppf[] = {0, 0, &false_ptr};
LocalStack* d_wppf = new LocalStack(_d_wppf, 3);
Command* deskBothWhitePurplePurpleFade = new Command("Desk[all]: White with Purple Fade",
                                                alldesk,
                                                2,
                                                desk_both_wpp_fade,
                                                d_wppf);*/

int _d_wppf[] = {0,0,1};
std::vector<int> d_wppf (_d_wppf, _d_wppf + sizeof(_d_wppf) / sizeof(int));
Command deskBothWhitePurplePurpleFade = Command("Desk[all]: White with Purple Fade",
                                                alldesk,
                                                2,
                                                desk_both_wpp_fade,
                                                d_wppf);

/* ~~~~~~ Window Commands ~~~~~~ */

/* Animations */
/*
// Every LED fades in and out a with calm purple
void* _w_pf[] = {0, 0, &true_ptr};
LocalStack* w_pf = new LocalStack(_w_pf, 3);
Command* winAllPurpleFade = new Command("Window[all]: Purple Fade",
                                    allwin,
                                    3,
                                    win_all_purple_fade,
                                    w_pf);

// WPI spirit theme
void* _w_wpi[] = {0, 0, &false_ptr};
LocalStack* w_wpi = new LocalStack(_w_wpi, 3);
Command* winAllWPISpirit = new Command("Window[all]: WPI Spirit",
                                    allwin,
                                    3,
                                    win_all_WPI_spirit,
                                    w_wpi);

// Rainbow Color Wipe for first window
void* _w1_rw[] = {0,0,0};
LocalStack* w1_rw = new LocalStack(_w1_rw, 3);
Command* win1RainbowWipe = new Command("Window[1]: Rainbow Color Wipe",
                                    win1,
                                    1,
                                    win_1_rainbow_wipe,
                                    w1_rw);

// Rainbow Color Wipe for second window
void* _w2_rw[] = {0,0,0};
LocalStack* w2_rw = new LocalStack(_w2_rw, 3);
Command* win2RainbowWipe = new Command("Window[2]: Rainbow Color Wipe",
                                    win2,
                                    1,
                                    win_2_rainbow_wipe,
                                    w2_rw);

// Rainbow Color Wipe for third window
void* _w3_rw[] = {0,0,0};
LocalStack* w3_rw = new LocalStack(_w3_rw, 3);
Command* win3RainbowWipe = new Command("Window[3]: Rainbow Color Wipe",
                                    win3,
                                    1,
                                    win_3_rainbow_wipe,
                                    w3_rw);
/*
/* Seasonal Animations */

// Halloween
/*
// Basic Orange/Purple Fade
void* _w_hallo_f[] = {0,0,&true_ptr};
LocalStack* w_hallo_f = new LocalStack(_w_hallo_f, 3);
Command* winAllHalloweenFade = new Command("Window[all]: Halloween Fade",
                                        allwin,
                                        3,
                                        win_all_halloween_fade,
                                        w_hallo_f);

// Sparkling Randomized Fade
void* _w_hallo_srf[] = {0,0,0};
LocalStack* w_hallo_srf = new LocalStack(_w_hallo_srf, 3);
Command* winAllHalloweenSparkle = new Command("Window[all]: Halloween Sparkle Fade",
                                          allwin,
                                          3,
                                          win_all_halloween_sparkle,
                                          w_hallo_srf);

*/

// Snow
int _w_snow[] = {0,0,0,0,0,0,0,0,0,0};
std::vector<int> w_snow (_w_snow, _w_snow + sizeof(_w_snow) / sizeof(int));
Command win1Snow = Command("Window[1]: Snow",
                                          win1,
                                          1,
                                          win_snow,
                                          w_snow);
std::vector<int> w_snow2 (_w_snow, _w_snow + sizeof(_w_snow) / sizeof(int));
Command win2Snow = Command("Window[2]: Snow",
                                          win2,
                                          1,
                                          win_snow,
                                          w_snow2);
std::vector<int> w_snow3 (_w_snow, _w_snow + sizeof(_w_snow) / sizeof(int));
Command win3Snow = Command("Window[3]: Snow",
                                          win3,
                                          1,
                                          win_snow,
                                          w_snow3);
