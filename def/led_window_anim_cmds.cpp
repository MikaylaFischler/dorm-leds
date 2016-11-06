/*
  Dorm LED Project: led_window_anim_cmds.cpp
  This file contains the window LED animation commands.

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

// &&& Command Ready Functions for Off Commands &&&

/* ~~~~~~ Static Commands ~~~~~~ */

// &&& Functions for Static Commands &&&

// &&& Command Ready Functions for Animated Commands &&&

/* ~~~~~~ Animated Commands ~~~~~~ */

// &&& Functions for Animated Commands &&&

void _win_all_purple_fade(int i){
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

void _win_all_halloween_fade(int i){
    for(int x = 0; x < WINDOW_LENGTH; x++){
        window1.setPixelColor(x, window_generic.Color(i, (int)(((float)i / 255.0) * 50), 0));
        window2.setPixelColor(x, window_generic.Color((int)(((float)i / 255.0) * 150), 0, i));
        window3.setPixelColor(x, window_generic.Color(i, (int)(((float)i / 255.0) * 50), 0));
    }

    showAllWindowStrips();
}

unsigned long int _rand_halloween_color(){
  unsigned long int bright_orange = window_generic.Color(255, 50, 0);
  unsigned long int medium_orange = window_generic.Color(190, 37, 0);
  unsigned long int dim_orange = window_generic.Color(100, 20, 0);

  unsigned long int bright_purple = window_generic.Color(150, 0, 255);
  unsigned long int medium_purple = window_generic.Color(112, 0, 190);
  unsigned long int dim_purple = window_generic.Color(59, 0, 100);

  unsigned long int off = window_generic.Color(0,0,0);

  long int r = random(0,7);

  switch(r){
    case 0:
      return off;
    case 1:
      return bright_orange;
    case 2:
      return medium_orange;
    case 3:
      return dim_orange;
    case 4:
      return bright_purple;
    case 5:
      return medium_purple;
    case 6:
      return dim_purple;
  }
}

void _win_all_halloween_sparkle_randomize(){
  // randomly assign each pixel :D
  for(int x = 0; x < WINDOW_LENGTH; x++){
    window1.setPixelColor(x, _rand_halloween_color());
    window2.setPixelColor(x, _rand_halloween_color());
    window3.setPixelColor(x, _rand_halloween_color());
  }

  showAllWindowStrips();
}

// configuration for _win_all_halloween_sparkle_fade
const float ORANGE_R_SLOPE = 1.0;
const float ORANGE_G_SLOPE = 0.196078;
const float PURPLE_R_SLOPE = 0.588235;
const float PURPLE_B_SLOPE = 1.0;

bool* _win_all_halloween_sparkle_fade(float i, bool inc[]){
  // fade with absolute value since so many different values
  for(int x = 0; x < WINDOW_LENGTH * 3; x++){
    Adafruit_NeoPixel win;
    int pixel = 0;

    if(x < WINDOW_LENGTH){
      win = window1;
      pixel = x;
    }else if(x < WINDOW_LENGTH * 2){
      win = window2;
      pixel = x - WINDOW_LENGTH;
    }else{
      win = window3;
      pixel = x - WINDOW_LENGTH * 2;
    }

    unsigned long int color = win.getPixelColor(pixel);

    unsigned int red = redFromColor(color);
    unsigned int green = greenFromColor(color);
    unsigned int blue = blueFromColor(color);

    bool increasing = inc[x];

    if(red <= 0){
      // is off, randomly pick a color
      int r = random(0,2);

      if(increasing){
        increasing = false;
      }else{
        increasing = true;
      }

      if(r == 0){
        // purple
        win.setPixelColor(pixel, window_generic.Color(1,0,2));
      }else{
        // orange
        win.setPixelColor(pixel, window_generic.Color(5,1,0));
      }
    }else if(green == 0){
      // was purple
      if(increasing){
        win.setPixelColor(pixel, window_generic.Color((unsigned int)((float)red + PURPLE_R_SLOPE), 0, (unsigned int)((float)blue + PURPLE_B_SLOPE)));
      }else{
        win.setPixelColor(pixel, window_generic.Color((unsigned int)((float)red - PURPLE_R_SLOPE), 0, (unsigned int)((float)blue - PURPLE_B_SLOPE)));
      }
    }else if(blue == 0){
      // was orange
      if(increasing){
        win.setPixelColor(pixel, window_generic.Color((unsigned int)((float)red + ORANGE_R_SLOPE), (unsigned int)((float)green + ORANGE_G_SLOPE), 0));
      }else{
        win.setPixelColor(pixel, window_generic.Color((unsigned int)((float)red - ORANGE_R_SLOPE), (unsigned int)((float)green - ORANGE_G_SLOPE), 0));
      }
    }

    inc[x] = increasing;
  }

  showAllWindowStrips();

  return inc;
}

// &&& Command Ready Functions for Animated Commands &&&

// Every LED fades in and out a with calm purple
// Initial input var_stack : LocalStack* stack{0,0,true}
LocalStack* win_all_purple_fade(LocalStack* var_stack){
  // set variables
  int fec = var_stack->getInt(0);
  unsigned int i = var_stack->getUnsignInt(1);
  bool increasing = var_stack->getBool(2);

  // run command code
  _win_all_purple_fade(i);

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

// A spirited display for my college, WPI
// Initial input var_stack : LocalStack* stack{0,0,false}
LocalStack* win_all_WPI_spirit(LocalStack* var_stack){
  // set variables
  int fec = var_stack->getInt(0);
  unsigned int i = var_stack->getUnsignInt(1);
  bool mode = var_stack->getBool(2);

  // run command code
  _win_all_WPI_spirit(i, mode);

  if(mode){
    if(i + 1 == WINDOW_LENGTH){
      i = 0;
      mode = false;
      window2.show();
      fec++;
    }else{
      i++;
    }
  }else{
    if(i + 1 == WINDOW_LENGTH){
      i = 0;
      mode = true;
      window2.show();
    }else{
      i++;
    }
  }

  // update variables
  var_stack->update(0, &fec);
  var_stack->update(1, &i);
  var_stack->update(2, &mode);

  return var_stack;
}

// Rainbow Color Wipe for first window
// Initial input var_stack : LocalStack* stack {0,0,0}
LocalStack* win_1_rainbow_wipe(LocalStack* var_stack){
  // set variables
  int fec = var_stack->getInt(0);
  unsigned int i = var_stack->getUnsignInt(1);
  int color_mode = var_stack->getInt(2);

  // run command code
  if(color_mode % 2 != 0){
    window1.setPixelColor(i, window_generic.Color(0, 0, 0)); // Off
  }else if(color_mode == 0){
    window1.setPixelColor(i, window_generic.Color(255, 0, 0)); // Red
  }else if(color_mode == 2){
    window1.setPixelColor(i, window_generic.Color(255, 50, 0)); // Orange
  }else if(color_mode == 4){
    window1.setPixelColor(i, window_generic.Color(255, 150, 0)); // Yellow
  }else if(color_mode == 6){
    window1.setPixelColor(i, window_generic.Color(0, 255, 0)); // Green
  }else if(color_mode == 8){
    window1.setPixelColor(i, window_generic.Color(0, 255, 200)); // Sea Green
  }else if(color_mode == 10){
    window1.setPixelColor(i, window_generic.Color(0, 0, 255)); // Blue
  }else if(color_mode == 12){
    window1.setPixelColor(i, window_generic.Color(100, 0, 255)); // Indigo
  }else if(color_mode == 14){
    window1.setPixelColor(i, window_generic.Color(255, 0, 255)); // Violet
  }

  window1.show();

  i++;

  if(i == WINDOW_LENGTH){
    color_mode++;
    i = 0;

    if(color_mode == 16){
      color_mode = 0;
      fec++;
    }
  }

  // update variables
  var_stack->update(0, &fec);
  var_stack->update(1, &i);
  var_stack->update(2, &color_mode);

  return var_stack;
}

// Rainbow Color Wipe for second window
// Initial input var_stack : LocalStack* stack {0,0,0}
LocalStack* win_2_rainbow_wipe(LocalStack* var_stack){
  // set variables
  int fec = var_stack->getInt(0);
  unsigned int i = var_stack->getUnsignInt(1);
  int color_mode = var_stack->getInt(2);

  // run command code
  if(color_mode % 2 != 0){
    window2.setPixelColor(i, window_generic.Color(0, 0, 0)); // Off
  }else if(color_mode == 0){
    window2.setPixelColor(i, window_generic.Color(255, 0, 0)); // Red
  }else if(color_mode == 2){
    window2.setPixelColor(i, window_generic.Color(255, 50, 0)); // Orange
  }else if(color_mode == 4){
    window2.setPixelColor(i, window_generic.Color(255, 150, 0)); // Yellow
  }else if(color_mode == 6){
    window2.setPixelColor(i, window_generic.Color(0, 255, 0)); // Green
  }else if(color_mode == 8){
    window2.setPixelColor(i, window_generic.Color(0, 255, 200)); // Sea Green
  }else if(color_mode == 10){
    window2.setPixelColor(i, window_generic.Color(0, 0, 255)); // Blue
  }else if(color_mode == 12){
    window2.setPixelColor(i, window_generic.Color(100, 0, 255)); // Indigo
  }else if(color_mode == 14){
    window2.setPixelColor(i, window_generic.Color(255, 0, 255)); // Violet
  }

  window2.show();

  i++;

  if(i == WINDOW_LENGTH){
    color_mode++;
    i = 0;

    if(color_mode == 16){
      color_mode = 0;
      fec++;
    }
  }

  // update variables
  var_stack->update(0, &fec);
  var_stack->update(1, &i);
  var_stack->update(2, &color_mode);

  return var_stack;
}

// Rainbow Color Wipe for third window
// Initial input var_stack : LocalStack* stack {0,0,0}
LocalStack* win_3_rainbow_wipe(LocalStack* var_stack){
  // set variables
  int fec = var_stack->getInt(0);
  unsigned int i = var_stack->getUnsignInt(1);
  int color_mode = var_stack->getInt(2);

  // run command code
  if(color_mode % 2 != 0){
    window3.setPixelColor(i, window_generic.Color(0, 0, 0)); // Off
  }else if(color_mode == 0){
    window3.setPixelColor(i, window_generic.Color(255, 0, 0)); // Red
  }else if(color_mode == 2){
    window3.setPixelColor(i, window_generic.Color(255, 50, 0)); // Orange
  }else if(color_mode == 4){
    window3.setPixelColor(i, window_generic.Color(255, 150, 0)); // Yellow
  }else if(color_mode == 6){
    window3.setPixelColor(i, window_generic.Color(0, 255, 0)); // Green
  }else if(color_mode == 8){
    window3.setPixelColor(i, window_generic.Color(0, 255, 200)); // Sea Green
  }else if(color_mode == 10){
    window3.setPixelColor(i, window_generic.Color(0, 0, 255)); // Blue
  }else if(color_mode == 12){
    window3.setPixelColor(i, window_generic.Color(100, 0, 255)); // Indigo
  }else if(color_mode == 14){
    window3.setPixelColor(i, window_generic.Color(255, 0, 255)); // Violet
  }

  window3.show();

  i++;

  if(i == WINDOW_LENGTH){
    color_mode++;
    i = 0;

    if(color_mode == 16){
      color_mode = 0;
      fec++;
    }
  }

  // update variables
  var_stack->update(0, &fec);
  var_stack->update(1, &i);
  var_stack->update(2, &color_mode);

  return var_stack;
}

// Have a fade in and out of orange on window 1, purple on window 2, and orange on window 3
// Initial input var_stack : LocalStack* stack {0,0,true}
LocalStack* win_all_halloween_fade(LocalStack* var_stack){
    // set variables
    int fec = var_stack->getInt(0);
    unsigned int i = var_stack->getUnsignInt(1);
    bool increasing = var_stack->getBool(2);

    // run command code
    _win_all_halloween_fade(i);

    if(increasing){
        if(i == 255){
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

// Have a randomized sparkle effect of halloween colors on all windows.
// Initial input var_stack : LocalStack* stack {0,0,0,{false,false...xWINDOW_LENGTH*3}}
LocalStack* win_all_halloween_sparkle(LocalStack* var_stack){
  // set variables
  int fec = var_stack->getInt(0);
  unsigned int i = var_stack->getUnsignInt(1);
  short int mode = var_stack->getShortInt(2);
  bool* inc = var_stack->getBoolArray(3);

  // run command code
  if(mode == 0){
    // randomize
    _win_all_halloween_sparkle_randomize();
    mode = 1;
  }else if(mode == 1){
    // fade for a bit
    inc = _win_all_halloween_sparkle_fade((float) i, inc);

    i++;

    if(i == 256){
      i = 0;
      mode = 0;
      fec++;
    }
  }

  // update variables
  var_stack->update(0, &fec);
  var_stack->update(1, &i);
  var_stack->update(2, &mode);
  var_stack->update(3, &inc);

  return var_stack;
}
