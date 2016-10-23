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

// &&& Command Ready Functions for Animated Commands &&&

// Every LED fades in and out a with calm purple
// Initial input var_stack : std::vector<int> stack{0,1}
std::vector<int> win_all_wpp_fade(std::vector<int> var_stack){
  // set variables
  int i = var_stack.at(0);
  int increasing = var_stack.at(1);

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
