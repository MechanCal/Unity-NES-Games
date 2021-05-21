
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>

// include NESLIB header
#include "neslib.h"

// include CC65 NES Header (PPU)
#include <nes.h>

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// BCD arithmetic support
#include "bcd.h"
//#link "bcd.c"

// VRAM update buffer
#include "vrambuf.h"
//#link "vrambuf.c"

/*{pal:"nes",layout:"nes"}*/
const char PALETTE[32] = { 
  0x02,			// screen color

  0x05,0x30,0x27,0x0,	// background palette 0
  0x1c,0x20,0x2c,0x0,	// background palette 1
  0x00,0x10,0x20,0x0,	// background palette 2
  0x06,0x16,0x26,0x0,   // background palette 3

  0x16,0x35,0x24,0x0,	// sprite palette 0
  0x00,0x37,0x25,0x0,	// sprite palette 1
  0x0d,0x2d,0x3a,0x0,	// sprite palette 2
  0x0d,0x27,0x2a	// sprite palette 3
};

  int count; //Timer for wait function
  //bool paper; // Inventory item


//oam_clear();
//oam_clear();
//vrambuf_clear();
//vrambuf_flush();
//vram_adr(NAMETABLE_A);




// setup PPU and tables
void setup_graphics() {
  // clear sprites
  oam_clear();
  // set palette colors
  pal_all(PALETTE);
}



void WAIT(){
  
  for(count=0; count<5; count++)
  {
     ppu_wait_frame();
     //ppu_wait_nmi();
  }
  
}




void clrscr(){
  vrambuf_clear();
  ppu_off();
  vram_adr(NAMETABLE_A);
  vram_fill(000000, 32*28);
  vram_adr(0x0);
  ppu_on_all();
}




void BAD_END(){
  clrscr();
  ppu_off();
  
  vram_adr(NTADR_A(1,2));
  vram_write("Exit?", 5);
  
  vram_adr(NTADR_A(1,7));
  vram_write("Oh no, you took the wrong path", 30);
  
  vram_adr(NTADR_A(1,9));
  vram_write("The evil", 8);
  
  vram_adr(NTADR_A(10,9));
  vram_write("genius Dr. Wylie has", 20);

  vram_adr(NTADR_A(1,11));
  vram_write("captured you forever, trapped", 29);
  
  vram_adr(NTADR_A(1,13));
  vram_write("in a loop of endless homework", 29);
  
  vram_adr(NTADR_A(1,15));
  vram_write("assignments.", 12);

  
   
  
  vram_adr(NTADR_A(1,20));
  vram_write("PRESS A", 7);
  

  ppu_on_all();

  
  while(1) {
    if(pad_trigger(0)&PAD_START || pad_trigger(0)&PAD_A) {
	ppu_off(); 
      	clrscr();
      	break;	
  }
  }
  
  ppu_off(); 

  
  vram_adr(NTADR_A(2,7));
  vram_write("I hope you're ready to fail", 28);
  
  vram_adr(NTADR_A(2,9));
  vram_write("for the rest of your life!!", 27);
  
  vram_adr(NTADR_A(16,11));
  vram_write("said Dr.Wylie. ", 14);


  vram_adr(NTADR_A(1,20));
  vram_write("PRESS A", 7);
  

  ppu_on_all();

  
  while(1) {
    if(pad_trigger(0)&PAD_START || pad_trigger(0)&PAD_A) {
        clrscr();
	ppu_off(); 
      	break;	
  }
  }
  
  
  vram_adr(NTADR_A(1,7));
  vram_write("Maybe if you return my lecture", 30);
  
  
  vram_adr(NTADR_A(1,9));
  vram_write("notes I could consider letting", 30);
  
  
  vram_adr(NTADR_A(1,11));
  vram_write("you go but alas you couldn't", 28);
  
  vram_adr(NTADR_A(1,13));
  vram_write("possibly know where they are.", 29);
  
  vram_adr(NTADR_A(1,15));
  vram_write("they are. Now get to working.", 29);
  
  vram_adr(NTADR_A(1,20));
  vram_write("PRESS A", 7);
  
 ppu_on_all();

  
  while(1) {
    if(pad_trigger(0)&PAD_START || pad_trigger(0)&PAD_A) {
        clrscr();
	ppu_off(); 
      	break;	
    }
  }
  
  vram_adr(NTADR_A(2,7));
  vram_write("Faced with the hard reality", 28);
  
  vram_adr(NTADR_A(2,9));
  vram_write("before you, you pass out...", 28);
  
  ppu_on_all();
  
  

  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  clrscr();
  vram_adr(NTADR_A(10,11));
  vram_write("Game Over!!", 11);
  
  ppu_on_all();
  
  while(1);
}



void EXIT(){
  pal_col(0, 0x0f);
  ppu_off();
 
  vram_adr(NTADR_A(2,2));
  vram_write("Hallway", 7);
  
  vram_adr(NTADR_A(3,5));
  vram_write("The flashlight turned off!", 26);
  
  vram_adr(NTADR_A(3,7));
  vram_write("You hear something coming", 25);
  
  
  
  vram_adr(NTADR_A(3,15));
  vram_write("Hide in a nearby room", 21);
  
  vram_adr(NTADR_A(3,17));
  vram_write("PRESS A", 7); 
  
  
  vram_adr(NTADR_A(3,20));
  vram_write("Run away", 8);
  
  vram_adr(NTADR_A(3,22));
  vram_write("PRESS B", 7);

  ppu_on_all();

  
  while(1) {
    if(pad_trigger(0)&PAD_A) {
	ppu_off(); 
      	clrscr();
        BAD_END();
      	
    }	
    else if(pad_trigger(0)&PAD_B){
      	ppu_off(); 
      	clrscr();
        break;
      
    }   
    
  }
  ppu_off();
  
  vram_adr(NTADR_A(2,2));
  vram_write("Exit Door", 9);
  
  vram_adr(NTADR_A(3,5));
  vram_write("You found the exit!", 19);
 
  vram_adr(NTADR_A(3,17));
  vram_write("PRESS A", 7); 
  
  
  ppu_on_all();

  while(1) {
    if(pad_trigger(0)&PAD_A) {
	ppu_off(); 
      	clrscr();
        break;
      	
    }	
  }
  
  
  ppu_off();
  clrscr();
  
  vram_adr(NTADR_A(10,11));
  vram_write("You escaped!!", 13);
  
  ppu_on_all();
  
 while(1){}
}





void OFFICE_ROOM(){
  ppu_off();
  //clrscr();
  vram_adr(NTADR_A(2,2));
  vram_write("Office", 6);
  
  vram_adr(NTADR_A(3,5));
  vram_write("You search and find some", 24);
  
  vram_adr(NTADR_A(3,7));
  vram_write("important looking documents", 27);
  
  ppu_on_all();
  //ppu_off();
  
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  
  
  vram_adr(NTADR_A(3,9));
  vram_write("T", 1);
  WAIT();
  
  vram_adr(NTADR_A(4,9));
  vram_write("H", 1);
  WAIT();
 
  vram_adr(NTADR_A(5,9));
  vram_write("E", 1);
  WAIT();
  
  vram_adr(NTADR_A(7,9));
  vram_write("D", 1);
  WAIT();
  
  vram_adr(NTADR_A(8,9));
  vram_write("O", 1);
  WAIT();
  
  vram_adr(NTADR_A(9,9));
  vram_write("O", 1);
  WAIT();
  
  vram_adr(NTADR_A(10,9));
  vram_write("R", 1);
  WAIT();
  
  
  vram_adr(NTADR_A(12,9));
  vram_write("O", 1);
  WAIT();
  
  vram_adr(NTADR_A(13,9));
  vram_write("P", 1);
  WAIT();
  
  vram_adr(NTADR_A(14,9));
  vram_write("E", 1);
  WAIT();
  
  vram_adr(NTADR_A(15,9));
  vram_write("N", 1);
  WAIT();
  
  vram_adr(NTADR_A(16,9));
  vram_write("S", 1);
  WAIT();
  
  vram_adr(NTADR_A(18,9));
  vram_write("B", 1);
  WAIT();
  
  vram_adr(NTADR_A(19,9));
  vram_write("E", 1);
  WAIT();
  
  vram_adr(NTADR_A(20,9));
  vram_write("H", 1);
  WAIT();
  
  vram_adr(NTADR_A(21,9));
  vram_write("I", 1);
  WAIT();
  
  vram_adr(NTADR_A(22,9));
  vram_write("N", 1);
  WAIT();
  
  vram_adr(NTADR_A(23,9));
  vram_write("D", 1);
  WAIT();
  
  vram_adr(NTADR_A(25,9));
  vram_write("Y", 1);
  WAIT();
  
  vram_adr(NTADR_A(26,9));
  vram_write("O", 1);
  WAIT();
  
  vram_adr(NTADR_A(27,9));
  vram_write("U", 1);
  WAIT(); 
  
  
  
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();
  WAIT();


  
  
  clrscr();
  ppu_off();
  
  vram_adr(NTADR_A(2,2));
  vram_write("Office", 6);
  
  vram_adr(NTADR_A(3,5));
  vram_write("So this is where I left the", 27);
  
  vram_adr(NTADR_A(3,7));
  vram_write("notes. said Dr. Wylie.", 22);
  
  vram_adr(NTADR_A(3,9));
  vram_write("Why are you here so late?", 25);
  
  vram_adr(NTADR_A(3,11));
  vram_write("Don't tell me you believe", 25);
  
  vram_adr(NTADR_A(3,13));
  vram_write("the ghost rumors.", 17);
  
  vram_adr(NTADR_A(3,15));
  vram_write("You should go before the", 24);
  
  vram_adr(NTADR_A(3,17));
  vram_write("doors get locked", 17);
  
  
  vram_adr(NTADR_A(3,20));
  vram_write("Press A", 7);
  
  ppu_on_all();
  
  while(1) {
    if(pad_trigger(0)&PAD_A) {
	ppu_off(); 
      	clrscr();
      	break;
    }	
  }
  
  vram_adr(NTADR_A(10,11));
  vram_write("You escaped!!", 13);
  
  ppu_on_all();
  
  while(1){}
  
  
}



void choice_A()
{
  pal_col(0, 0x0f);
  ppu_off();
  
  vram_adr(NTADR_A(2,2));
  vram_write("Hallway", 7);
  
  vram_adr(NTADR_A(3,5));
  vram_write("You managed to find an exit.", 28);
  
  vram_adr(NTADR_A(3,7));
  vram_write("You see a flashlight on the", 27);
  
  vram_adr(NTADR_A(3,9));
  vram_write("ground.", 7);
  
  
  vram_adr(NTADR_A(3,15));
  vram_write("Take it", 7);
  
  vram_adr(NTADR_A(3,17));
  vram_write("PRESS A", 7); 
  
  ppu_on_all();
  
  while(1){
    if(pad_trigger(0)&PAD_A)
      break;
  }
  

  
  
  clrscr();
  ppu_off();
  
  pal_col(0,0x08);
  
  vram_adr(NTADR_A(2,2));
  vram_write("Hallway", 7);
  
  vram_adr(NTADR_A(3,5));
  vram_write("The light reveals you to be", 27);
  
  vram_adr(NTADR_A(3,7));
  vram_write("in a school. You look around", 28);
 
  
  vram_adr(NTADR_A(3,9));
  vram_write("and see an office and an", 24);
  
  vram_adr(NTADR_A(3,11));
  vram_write("exit door", 9);
  
  
  
  
  vram_adr(NTADR_A(3,15));
  vram_write("Go into the office", 18);
  
  vram_adr(NTADR_A(3,17));
  vram_write("PRESS A", 7); 
  
  
  vram_adr(NTADR_A(3,20));
  vram_write("Go towards the exit", 19);
  
  vram_adr(NTADR_A(3,22));
  vram_write("PRESS B", 7);

  ppu_on_all();

  
  while(1) {
    if(pad_trigger(0)&PAD_A) {
	ppu_off(); 
      	clrscr();
      	OFFICE_ROOM();
      	
    }	
    else if(pad_trigger(0)&PAD_B){
      	ppu_off(); 
      	clrscr();
        EXIT();
      
    }   
    
  }

  
  
  
  
 
  
  
  
  
  
  while(1){}
}











void choice_B(void)
{
  pal_col(0,0x16);
  clrscr();
  ppu_off();
  vram_adr(NTADR_A(2,8));
  vram_write("You decide to follow the", 24); 
  
  vram_adr(NTADR_A(2,11));
  vram_write("voice and find out what's", 25);
  
  vram_adr(NTADR_A(2,14));
  vram_write("happening...", 12);
  
  vram_adr(NTADR_A(2,22));
  vram_write("Press A to continue...", 22);
  
  ppu_on_all();
  
  
  while(1){
    if(pad_trigger(0)&PAD_A)
      break;
    //choice_C();
  }
  
  
  clrscr();
  ppu_off();
  
  vram_adr(NTADR_A(2,8));
  vram_write("You wander into an abandoned", 28); 
  
  vram_adr(NTADR_A(2,11));
  vram_write("building and find a little", 26);
  
  vram_adr(NTADR_A(2,14));
  vram_write("girl kneeling in the corner...", 30);
  
  vram_adr(NTADR_A(2,22));
  vram_write("Press A to continue...", 22);
  
  ppu_on_all();
  
  
  while(1){
    if(pad_trigger(0)&PAD_A)
      break;
    //choice_C();
  }
  
  
  clrscr();
  ppu_off();
  
  vram_adr(NTADR_A(2,8));
  vram_write("You decide to approach the", 26); 
  
  vram_adr(NTADR_A(2,11));
  vram_write("girl but you hear something", 27);
  
  vram_adr(NTADR_A(2,14));
  vram_write("scraping the floor behind", 25);
  
  vram_adr(NTADR_A(2,17));
  vram_write("you...", 6);
   
  vram_adr(NTADR_A(2,22));
  vram_write("Press A to continue...", 22);
  
  ppu_on_all();
  
  
  while(1){
    if(pad_trigger(0)&PAD_A)
      break;
    //choice_C();
  }
  
  
  clrscr();
  ppu_off();
  
  vram_adr(NTADR_A(2,8));
  vram_write("You are greeted with a", 22); 
  
  vram_adr(NTADR_A(2,11));
  vram_write("sinister smile and the", 22);
  
  vram_adr(NTADR_A(2,14));
  vram_write("overwhelming smell of blood", 27);
  
  vram_adr(NTADR_A(2,17));
  vram_write("and rust...", 11);
  
  vram_adr(NTADR_A(2,22));
  vram_write("Press A to continue...", 22);
  
  ppu_on_all();
  
  
  while(1){
    if(pad_trigger(0)&PAD_A)
      break;
    //choice_C();
  }
  
  
  clrscr();
  ppu_off();
  
  vram_adr(NTADR_A(2,8));
  vram_write("You run away as fast as you", 27); 
  
  vram_adr(NTADR_A(2,11));
  vram_write("can but as you exit the", 23);
  
  vram_adr(NTADR_A(2,14));
  vram_write("building the little girl and", 28);
  
  vram_adr(NTADR_A(2,17));
  vram_write("another figure standing next", 28);
  
  vram_adr(NTADR_A(2,20));
  vram_write("to her walk towards you with", 28);
  
  vram_adr(NTADR_A(2,23));
  vram_write("a knife in their hands...", 25);
  
  vram_adr(NTADR_A(2,28));
  vram_write("To be continued...", 18);
  
  ppu_on_all();
  
  
  while(1){
    if(pad_trigger(0)&PAD_A)
      break;
    //choice_C();
  }
  
  clrscr();
  ppu_off();
  
  vram_adr(NTADR_A(7,14));
  vram_write("To be continued...", 18);
  
  ppu_on_all();
  
   while(1){
   //if(pad_trigger(0)&PAD_A)
   //break;
   }
} 




void title_screen(void){
  
  
  while(1)
  {

    if(pad_trigger(0)&PAD_START || pad_trigger(0)&PAD_A) {
	ppu_off(); 
      	clrscr();
      	break;
    }
  }
}

void TEXT(){
 pal_col(0, 0x0f);
  
 vram_adr(NTADR_A(2,2));
 vram_write("Start", 5);

 WAIT();
 vram_adr(NTADR_A(3,5));
 vram_write("Y", 1);
 WAIT();
 vram_adr(NTADR_A(4,5));
 vram_write("O", 1);
 WAIT();
 vram_adr(NTADR_A(5,5));
 vram_write("U", 1);
 WAIT();
  
 vram_adr(NTADR_A(7,5));
 vram_write("A", 1);
 WAIT(); 
 vram_adr(NTADR_A(8,5));
 vram_write("W", 1);
 WAIT();
 vram_adr(NTADR_A(9,5));
 vram_write("A", 1);
 WAIT(); 
 vram_adr(NTADR_A(10,5));
 vram_write("K", 1);
 WAIT();
 vram_adr(NTADR_A(11,5));
 vram_write("E", 1);
 WAIT(); 
 
 vram_adr(NTADR_A(13,5));
 vram_write("I", 1);
 WAIT();
 vram_adr(NTADR_A(14,5));
 vram_write("N", 1);
 WAIT(); 
  
 vram_adr(NTADR_A(16,5));
 vram_write("A", 1);
 WAIT();
  
 vram_adr(NTADR_A(18,5));
 vram_write("D", 1);
 WAIT(); 
 vram_adr(NTADR_A(19,5));
 vram_write("A", 1);
 WAIT();
 vram_adr(NTADR_A(20,5));
 vram_write("R", 1);
 WAIT(); 
 vram_adr(NTADR_A(21,5));
 vram_write("K", 1);
 WAIT();
  
 vram_adr(NTADR_A(23,5));
 vram_write("R", 1);
 WAIT(); 
 vram_adr(NTADR_A(24,5));
 vram_write("O", 1);
 WAIT();  
 vram_adr(NTADR_A(25,5));
 vram_write("O", 1);
 WAIT(); 
 vram_adr(NTADR_A(26,5));
 vram_write("M", 1);
 WAIT(); 
 vram_adr(NTADR_A(27,5));
 vram_write(".", 1);
 WAIT();  
  
 vram_adr(NTADR_A(3,7));
 vram_write("I", 1);
 WAIT(); 
 vram_adr(NTADR_A(4,7));
 vram_write("N", 1);
 WAIT(); 
  
 vram_adr(NTADR_A(6,7));
 vram_write("T", 1);
 WAIT(); 
 vram_adr(NTADR_A(7,7));
 vram_write("H", 1);
 WAIT(); 
 vram_adr(NTADR_A(8,7));
 vram_write("E", 1);
 WAIT();  
  
 vram_adr(NTADR_A(10,7));
 vram_write("D", 1);
 WAIT();  
 vram_adr(NTADR_A(11,7));
 vram_write("I", 1);
 WAIT();  
 vram_adr(NTADR_A(12,7));
 vram_write("S", 1);
 WAIT();  
 vram_adr(NTADR_A(13,7));
 vram_write("T", 1);
 WAIT();  
 vram_adr(NTADR_A(14,7));
 vram_write("A", 1);
 WAIT();  
 vram_adr(NTADR_A(15,7));
 vram_write("N", 1);
 WAIT();  
 vram_adr(NTADR_A(16,7));
 vram_write("C", 1);
 WAIT();  
 vram_adr(NTADR_A(17,7));
 vram_write("E", 1);
 WAIT();  
  
 vram_adr(NTADR_A(19,7));
 vram_write("Y", 1);
 WAIT();  
 vram_adr(NTADR_A(20,7));
 vram_write("O", 1);
 WAIT();  
 vram_adr(NTADR_A(21,7));
 vram_write("U", 1);
 WAIT();  
  
 vram_adr(NTADR_A(23,7));
 vram_write("H", 1);
 WAIT();  
 vram_adr(NTADR_A(24,7));
 vram_write("E", 1);
 WAIT();  
 vram_adr(NTADR_A(25,7));
 vram_write("A", 1);
 WAIT();  
 vram_adr(NTADR_A(26,7));
 vram_write("R", 1);
 WAIT();  
  
 vram_adr(NTADR_A(3,9));
 vram_write("A", 1);
 WAIT(); 	  
  
 vram_adr(NTADR_A(5,9));
 vram_write("V", 1);
 WAIT();   
 vram_adr(NTADR_A(6,9));
 vram_write("O", 1);
 WAIT(); 
 vram_adr(NTADR_A(7,9));
 vram_write("I", 1);
 WAIT(); 
 vram_adr(NTADR_A(8,9));
 vram_write("C", 1);
 WAIT(); 
 vram_adr(NTADR_A(9,9));
 vram_write("E", 1);
 WAIT(); 
  
 vram_adr(NTADR_A(10,9));
 vram_write(".", 1);
 WAIT(); 
 vram_adr(NTADR_A(11,9));
 vram_write(".", 1);
 WAIT(); 
   
  
ppu_off();
vram_adr(NTADR_A(3,15));
vram_write("Look for a way out", 18);
  
vram_adr(NTADR_A(3,17));
vram_write("PRESS A", 7); 
  
vram_adr(NTADR_A(3,20));
vram_write("Follow the voice", 16);
  
vram_adr(NTADR_A(3,22));
vram_write("PRESS B", 7);

ppu_on_all();

  
  while(1) {
    if(pad_trigger(0)&PAD_B) {
	ppu_off(); 
      	clrscr();
      	choice_B();
    }	
    else if(pad_trigger(0)&PAD_A){
      	ppu_off(); 
      	clrscr();
        choice_A();
      
    }   
    
  }

  
  
  
  

  
}



/*else if(pad_trigger(0)&PAD_B || pad_trigger(0)&PAD_START)
    {
      ppu_off(); 
      clrscr();
      vram_adr(NTADR_A(10,18));
      vram_write("Game Over", 9);
    }
*/







void main(void)
{
  setup_graphics();
  vram_adr(NTADR_A(10,18));
  vram_write("PRESS START!", 12);
  
  vram_adr(NTADR_A(11,10));
  vram_write("The Game!", 9);
  

  
  // enable rendering
  ppu_on_all();
  
  title_screen();
  
  //choice_A();
  //  BAD_END();

  TEXT();
  
  
  
  

  
  
  
  
  // infinite loop
  while(1) {

  }
}
