/*
  Dorm LED Project: led_desk_anim_cmds.cpp
  This file contains the desk LED animation commands.

  These are meant to be executed using the multithreaded system.

  Created by: Michael Fischler
  10/22/2016 @ WPI
*/

/*
  Template for a Command
  std::vector<var> (*cmd)(std::vector<var>)

  std::vector<var> cmd(std::vector<var> var_stack){
    // set variables
    int i = var_stack.at(0).value;
    int t = var_stack.at(1).value;

    // run command code
    ...

    // update variables
    var_stack.at(0).value = i;
    var_stack.at(1).value = t;

    return var_stack;
  }
*/

/* ~~~~~~ Off Commands ~~~~~~ */

// Every LED for Desk 1 set to {0,0,0}
// Initial input var_stack : std::vector<var> stack [empty]
std::vector<var> desk1_off(std::vector<var> var_stack){
  // set variables
  // n/a

  // run command code
  _desk1_off();

  // update variables
  // n/a

  return var_stack;
}

// Every LED for Desk 2 set to {0,0,0}
// Initial input var_stack : std::vector<var> stack [empty]
std::vector<var> desk2_off(std::vector<var> var_stack){
  // set variables
  // n/a

  // run command code
  _desk2_off();

  // update variables
  // n/a

  return var_stack;
}

// Every LED set to {0,0,0}
// Initial input var_stack : std::vector<var> stack [empty]
std::vector<var> desks_off(std::vector<var> var_stack){
  // set variables
  // n/a

  // run command code
  _desk1_off();
  _desk2_off();

  // update variables
  // n/a

  return var_stack;
}

// &&& Functions for Off Commands &&&

void _desk1_off(){
  for(int i = 0; i < DESK1_LENGTH; i++){
    desk1.setPixelColor(i, desk1.Color(0,0,0));
  }

  desk1.show();
}

void _desk2_off(){
  for(int i = 0; i < DESK2_LENGTH; i++){
    desk2.setPixelColor(i, desk2.Color(0,0,0));
  }

  desk2.show();
}

/* ~~~~~~ Static Commands ~~~~~~ */

// Every third LED gets a red tinted white
// Initial input var_stack : std::vector<var> stack [empty]
std::vector<var> desk_both_dim_ambient(std::vector<var> var_stack){
  // set variables
  // n/a

  // run command code
  _desk_both_dim_ambient();

  // update variables
  // n/a

  return var_stack;
}

// &&& Functions for Static Commands &&&

void _desk_both_dim_ambient(){
  for(int i = 0; i < DESK1_LENGTH; i++){
    if(i%3 == 0){
      desk1.setPixelColor(i, desk1.Color(75,45,25));
    }else{
      desk1.setPixelColor(i, desk1.Color(0,0,0));
    }
  }

  for(int i = 0; i < DESK2_LENGTH; i++){
    if(i%3 == 0){
      desk2.setPixelColor(i, desk2.Color(75,45,25));
    }else{
      desk2.setPixelColor(i, desk2.Color(0,0,0));
    }
  }

  desk1.show();
  desk2.show();
}

/* Animated Commands */
