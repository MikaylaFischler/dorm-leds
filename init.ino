/* Initialization Code for the Dorm LED System */

void set_pin_modes() {
  pinMode(STRIP_PIN_W1, OUTPUT);
  pinMode(STRIP_PIN_W2, OUTPUT);
  pinMode(STRIP_PIN_W3, OUTPUT);
  pinMode(STRIP_PIN_D1, OUTPUT);
  pinMode(STRIP_PIN_D2, OUTPUT);
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

