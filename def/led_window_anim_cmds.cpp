/*
  Dorm LED Project: led_window_anim_cmds.cpp
  This file contains the window LED animation commands.

  These are meant to be executed using the multithreaded system.

  Created by: Michael Fischler
  10/22/2016 @ WPI
*/

/*
  Template for a Command
  std::vector<int> (*cmd)(std::vector<int>)

  std::vector<int> cmd(std::vector<int> var_stack){
    // set variables
    int i = var_stack.at(0);
    int t = var_stack.at(1);

    // run command code
    ...

    // update variables
    var_stack.at(0) = i;
    var_stack.at(1) = t;

    return var_stack;
  }
*/

/* ~~~~~~ Off Commands ~~~~~~ */

// &&& Functions for Off Commands &&&

// &&& Command Ready Functions for Off Commands &&&

/* ~~~~~~ Static Commands ~~~~~~ */

// &&& Functions for Static Commands &&&

// &&& Command Ready Functions for Animated Commands &&&

/* ~~~~~~ Animated Commands ~~~~~~ */

// &&& Functions for Animated Commands &&&

void _win_all_wpp_fade(int i){
  for(int x = 0; x < WINDOW_LENGTH; x++){
    setAllWindowPixelColor(x, window_generic.Color((int)(((float)i / 150.0) * 100), 0, i));
  }

  showAllWindowStrips();
}

void _win_all_WPI_spirit(int i, short int mode){
  //uint8_t red = window_generic.Color(172, 43, 55);
  //uint8_t white = window_generic.Color(169, 176, 183);

  if(mode == 0){
    window1.setPixelColor(i, window_generic.Color(255, 21, 27));

    if(i%2 == 0){
      window2.setPixelColor(i, window_generic.Color(169, 176, 183));
    }else{
      window2.setPixelColor(i, window_generic.Color(255, 21, 27));
    }

    int modified = WINDOW_LENGTH + 9 - 1 - i;

    if(modified >= WINDOW_LENGTH){
      modified -= WINDOW_LENGTH;
    }

    window3.setPixelColor(modified, window_generic.Color(255, 21, 27));
  }else if(mode == 1){
    window1.setPixelColor(i, window_generic.Color(169, 176, 183));

    for(int j = 0; j < WINDOW_LENGTH; j++){
      if(i%2 != 0){
        window2.setPixelColor(i, window_generic.Color(169, 176, 183));
      }else{
        window2.setPixelColor(i, window_generic.Color(255, 21, 27));
      }
    }

    int modified = WINDOW_LENGTH + 9 - 1 - i;

    if(modified >= WINDOW_LENGTH){
      modified -= WINDOW_LENGTH;
    }

    window3.setPixelColor(modified, window_generic.Color(169, 176, 183));
  }

  window1.show();
  window3.show();
}

// &&& Command Ready Functions for Animated Commands &&&

// Every LED fades in and out a with calm purple
// Initial input var_stack : std::vector<int> stack{0,1}
std::vector<int> win_all_wpp_fade(std::vector<int> var_stack){
  // set variables
  int i = var_stack.at(0);
  short int increasing = var_stack.at(1);

  // run command code
  _win_all_wpp_fade(i);

  if(increasing == 1){
    if(i == 150){
      i--;
      increasing = 0;
    }else{
      i++;
    }
  }else{
    if(i == 0){
      i++;
      increasing = 1;
    }else{
      i--;
    }
  }

  // update variables
  var_stack.at(0) = i;
  var_stack.at(1) = increasing;

  return var_stack;
}

// A spirited display for my college, WPI
// Initial input var_stack : std::vector<int> stack{0,0}
std::vector<int> win_all_WPI_spirit(std::vector<int> var_stack){
  // set variables
  int i = var_stack.at(0);
  short int mode = var_stack.at(1);

  // run command code
  _win_all_WPI_spirit(i, mode);

  if(mode == 0){
    if(i + 1 == WINDOW_LENGTH){
      i = 0;
      mode = 1;
      window2.show();
    }else{
      i++;
    }
  }else if(mode == 1){
    if(i + 1 == WINDOW_LENGTH){
      i = 0;
      mode = 0;
      window2.show();
    }else{
      i++;
    }
  }

  // update variables
  var_stack.at(0) = i;
  var_stack.at(1) = mode;

  return var_stack;
}
