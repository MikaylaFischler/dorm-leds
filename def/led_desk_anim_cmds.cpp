/*
  Dorm LED Project: led_desk_anim_cmds.cpp
  This file contains the desk LED animation commands.

  These are meant to be executed using the multithreaded system.
  Note: First element in the var stack is to store number of complete executions (resetable).

  Created by: Michael Fischler
  10/22/2016 @ WPI
*/

#include <Adafruit_NeoPixel.h>

/*
  Template for a Command
  LocakStack* cmd(LocalStack* var_stack)

  LocakStack* cmd(LocalStack* var_stack){
    // set variables
    int i = var_stack->getInt(0);
    char t = var_stack->getChar(1);

    // run command code
    ...

    // update variables
    var_stack->update(0, &i);
    var_stack->update(1, &t);

    return var_stack;
  }
*/

/* ~~~~~~ Off Commands ~~~~~~ */

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

// &&& Command Ready Functions for Off Commands &&&

// Every LED for Desk 1 set to {0,0,0}
// Initial input var_stack : LocalStack* stack [empty]
LocalStack* desk1_off(LocalStack* var_stack){
  // set variables
  int fec = var_stack->getInt(0);

  // run command code
  _desk1_off();

  // update variables
  fec++;
  var_stack->update(0, &fec);

  return var_stack;
}

// Every LED for Desk 2 set to {0,0,0}
// Initial input var_stack : LocalStack* stack [empty]
LocalStack* desk2_off(LocalStack* var_stack){
  // set variables
  int fec = var_stack->getInt(0);

  // run command code
  _desk2_off();

  // update variables
  fec++;
  var_stack->update(0, &fec);

  return var_stack;
}

// Every LED set to {0,0,0}
// Initial input var_stack : LocalStack* stack [empty]
LocalStack* desks_off(LocalStack* var_stack){
  // set variables
  int fec = var_stack->getInt(0);

  // run command code
  _desk1_off();
  _desk2_off();

  // update variables
  fec++;
  var_stack->update(0, &fec);

  return var_stack;
}

/* ~~~~~~ Static Commands ~~~~~~ */

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

// &&& Command Ready Functions for Static Commands &&&

// Every third LED gets a red tinted white
// Initial input var_stack : LocalStack* stack [empty]
LocalStack* desk_both_dim_ambient(LocalStack* var_stack){
  // set variables
  int fec = var_stack->getInt(0);

  // run command code
  _desk_both_dim_ambient();

  // update variables
  fec++;
  var_stack->update(0, &fec);

  return var_stack;
}

/* ~~~~~~ Animated Commands ~~~~~~ */

// &&& Functions for Animated Commands &&&

void _desk_both_wpp_fade(int i){
  for(int y = 0; y < DESK1_LENGTH; y++){
    if(y%3 != 0){
      desk1.setPixelColor(y, desk1.Color((int)(((float)i / 150.0) * 100), 0, i));
    }else{
      desk1.setPixelColor(y, desk1.Color(75,45,25));
    }
  }

  for(int z = 0; z < DESK2_LENGTH; z++){
    if(z%3 != 0){
      desk2.setPixelColor(z, desk2.Color((int)(((float)i / 150.0) * 100), 0, i));
    }else{
      desk2.setPixelColor(z, desk2.Color(75,45,25));
    }
  }

  desk1.show();
  desk2.show();
}

// &&& Command Ready Functions for Animated Commands &&&

// Every third LED stays nice reddish white while the others fade in and out a calm purple
// Initial input var_stack : LocalStack* stack {0,0,true}
LocalStack* desk_both_wpp_fade(LocalStack* var_stack){
  // set variables
  int fec = var_stack->getInt(0);
  unsigned int i = var_stack->getUnsignInt(1);
  bool increasing = var_stack->getBool(2);

  // run command code
  _desk_both_wpp_fade(i);

  if(increasing){
    if(i == 150){
      i--;
      increasing = false;
    }else{
      i++;
    }
  }else{
    if(i == 0){
      i++;
      increasing = true;
      fec++;
    }else{
      i--;
    }
  }

  // update variables
  var_stack->update(0, &fec);
  var_stack->update(1, &i);
  var_stack->update(2, &increasing);

  return var_stack;
}
