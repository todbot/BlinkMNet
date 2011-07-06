//
// BlinkMNet command script for ASTERISK
//
// There are 8 panels, arranged as four Arduinos with 2 BlinkM MaxMs each.
// Each MaxM is driving white panels only, to full brightness, on all channels.
//
//
// The 8 panels spell out the word "ASTERISK". one letter per panel.
// The timing is like below.  There are 27 frames, each "frame" taking 500 msec.
//  frame          11111111112222222
//       012345678901234567890123456
//  Adr  ---------------------------
//  11   AAAAAAAA                   
//  12   SSSSSSS                    
//  13   TTTTTT      T              
//  14   EEEEE   E                   
//  15   RRRR      R        R R  R  
//  16   III           I I IIII II  
//  17   SS         S       S S  S  
//  18   K        K         K K  K  
//       ----------------------------
//       0123456789012345678901234562
//                 111111111122222222
//

// an unused idea to make script definitions easier
#define LED_A  11
#define LED_S  12
#define LED_T  13
#define led_on(x,y)  {{ x, y, 'c', 0xff,0xff,0xff}}
#define led_off(x,y) {{ x, y, 'c', 0x00,0x00,0x00}}
// it would then be used like:
//  { led_on(500, LED_A) },
//  { led_of(0,   LED_S) },

const PROGMEM char cmdline_id[] = "ASTERISK for Hammer";
const cmdline cmdlines[] PROGMEM = { 
// dur, addr,cmd,  args 
  {  10,  0, 'o',  0x00,0x00,0x00, "stof" },
  {  10,  0, 'f',  100, 0x00,0x00, "fads" }, // set fadespeed
  { 500, 11, 'c',  0xff,0xff,0xff, "f00a" }, // frame 0: all on
  {   0, 12, 'c',  0xff,0xff,0xff, "f00b" }, // all at the same time, so 0 time
  {   0, 13, 'c',  0xff,0xff,0xff, "f00c" },
  {   0, 14, 'c',  0xff,0xff,0xff, "f00d" },
  {   0, 15, 'c',  0xff,0xff,0xff, "f00e" },
  {   0, 16, 'c',  0xff,0xff,0xff, "f00f" },
  {   0, 17, 'c',  0xff,0xff,0xff, "f00g" },
  {   0, 18, 'c',  0xff,0xff,0xff, "f00h" },
  { 500, 18, 'c',  0x00,0x00,0x00, "f01 " }, // frame  1: turn off K
  { 500, 17, 'c',  0x00,0x00,0x00, "f02 " }, // frame  2: turn off S
  { 500, 16, 'c',  0x00,0x00,0x00, "f03 " }, // frame  3: turn off I
  { 500, 15, 'c',  0x00,0x00,0x00, "f04 " }, // frame  4: turn off R
  { 500, 14, 'c',  0x00,0x00,0x00, "f05 " }, // frame  5: turn off E
  { 500, 13, 'c',  0x00,0x00,0x00, "f06 " }, // frame  6: turn off T
  { 500, 12, 'c',  0x00,0x00,0x00, "f07 " }, // frame  7: turn off S
  { 500, 11, 'c',  0x00,0x00,0x00, "f08a" }, // frame  8: turn off A, turn on E
  {   0, 14, 'c',  0xff,0xff,0xff, "f08b" },
  { 500, 14, 'c',  0x00,0x00,0x00, "f09a" }, // frame  9: turn off E, turn on K
  {   0, 18, 'c',  0xff,0xff,0xff, "f09b" },
  { 500, 18, 'c',  0x00,0x00,0x00, "f10a" }, // frame 10: turn off K, turn on R
  {   0, 15, 'c',  0xff,0xff,0xff, "f10b" },
  { 500, 18, 'c',  0x00,0x00,0x00, "f11a" }, // frame 11: turn off R, turn on S
  {   0, 15, 'c',  0xff,0xff,0xff, "f11b" },
  { 500, 18, 'c',  0x00,0x00,0x00, "f12a" }, // frame 12: turn off S, turn on T
  {   0, 15, 'c',  0xff,0xff,0xff, "f12b" },
  { 500,  0, 'c',  0x00,0x00,0x00, "f13 " }, // frame 13 turn off T (all
  { 500, 16, 'c',  0xff,0xff,0xff, "f14 " }, // frame 14: turn on I
  { 500, 16, 'c',  0x00,0x00,0x00, "f15 " }, // frame 15: turn off I
  { 500, 16, 'c',  0xff,0xff,0xff, "f16 " }, // frame 16: turn on I
  { 500, 16, 'c',  0x00,0x00,0x00, "f17 " }, // frame 17: turn off I
  { 500, 16, 'c',  0xff,0xff,0xff, "f18 " }, // frame 18: turn on I
  { 500, 15, 'c',  0xff,0xff,0xff, "f19a" }, // frame 19: turn on R,S,K
  {   0, 17, 'c',  0xff,0xff,0xff, "f19b" }, // 
  {   0, 18, 'c',  0xff,0xff,0xff, "f19c" }, // 
  { 500, 15, 'c',  0x00,0x00,0x00, "f20a" }, // frame 20: turn off R,S,K
  {   0, 17, 'c',  0x00,0x00,0x00, "f20b" }, // 
  {   0, 18, 'c',  0x00,0x00,0x00, "f20c" }, // 
  { 500, 15, 'c',  0xff,0xff,0xff, "f21a" }, // frame 21: turn on R,S,K
  {   0, 17, 'c',  0xff,0xff,0xff, "f21b" }, // 
  {   0, 18, 'c',  0xff,0xff,0xff, "f21c" }, // 
  { 500, 15, 'c',  0x00,0x00,0x00, "f22a" }, // frame 22: turn off R,I,S,K
  {   0, 16, 'c',  0x00,0x00,0x00, "f22b" }, // 
  {   0, 17, 'c',  0x00,0x00,0x00, "f22c" }, // 
  {   0, 18, 'c',  0x00,0x00,0x00, "f22d" }, // 
  { 500, 16, 'c',  0xff,0xff,0xff, "f23 " }, // frame 23: turn on I
  { 500, 15, 'c',  0xff,0xff,0xff, "f24a" }, // frame 24: turn on R,S,K
  {   0, 17, 'c',  0xff,0xff,0xff, "f24b" }, // 
  {   0, 18, 'c',  0xff,0xff,0xff, "f24c" }, // 
  { 500,  0, 'c',  0x00,0x00,0x00, "f25 " }, // frame 25: turn off all
  { 500,  0, 'c',  0x00,0x00,0x00, "f26 " }, // frame 26: turn off all
};  
const int cmdlines_len = sizeof(cmdlines)/sizeof(cmdline);

/*
const int cmdline_len = 11;
const cmdline cmdlines[] PROGMEM = { 
  {  10, 0, 'n',  0xff,0xff,0xff},
  {  10, 0, 'n',  0x00,0x00,0x00},
  {  10, 0, 'n',  0xff,0xff,0xff},
  {  10, 0, 'n',  0x00,0x00,0x00},
  {  10, 0, 'n',  0xff,0xff,0xff},
  { 100, 0, 'n',  0x00,0x00,0x00},
  { 100, 0, 'n',  0xff,0xff,0xff},
  { 100, 0, 'n',  0x00,0x00,0x00},
  { 100, 0, 'n',  0xff,0xff,0xff},
  { 100, 0, 'n',  0x00,0x00,0x00},
  { 100, 0, 'n',  0xff,0xff,0xff},
};
*/
