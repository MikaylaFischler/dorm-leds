/* Initialization Code for the Dorm LED System */

void set_pin_modes() {
 //set pin modes here
}

void init_strips() {
  // Window Strips
  window1.begin();
  window1.show();
  
  window2.begin();
  window2.show();
  
  window3.begin();
  window3.show();

  // Desk Strips
  desk1.begin();
  desk1.show();
  
  desk2.begin();
  desk2.show();
}

