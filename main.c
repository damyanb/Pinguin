#include <gb/gb.h>
#include "p3.c"
#include "p1.c"
#include "fondo.c"

void init();
void checkInput();
void updateSwitches();
UINT8 player[2];
UINT8 a;
UINT8 b;
UINT8 bola1[2];
UINT8 bola2[2];
UINT8 bola3[2];
UINT8 bola4[2];
UINT8 bola5[2];
UINT8 bola6[2];
UINT8 bola7[2];
UINT8 bola8[2];
UINT8 bola9[2];
unsigned char noWalk[2];
void main() {
	init();
	while(1) {
		checkInput();				// Check for user input (and act on it)
		updateSwitches();			// Make sure the SHOW_SPRITES and SHOW_BKG switches are on each loop
		wait_vbl_done();			// Wait until VBLANK to avoid corrupting memory
	}	
}
void init() {
	DISPLAY_ON;		// Turn on the display
	NR52_REG = 0x8F;	// Turn on the sound
	NR51_REG = 0x11;	// Enable the sound channels
	NR50_REG = 0x77;	// Increase the volume to its max
    set_bkg_data(0, 3, p3);		// Load 23 tiles into background memory
    set_bkg_tiles(6,5,9,8,fondo); 
    set_sprite_data(0, 6, p1);
    set_sprite_tile(0,0);
    set_sprite_tile(1,4);
    set_sprite_tile(2,4);
    set_sprite_tile(3,4);
    set_sprite_tile(4,4);
    set_sprite_tile(5,4);
    set_sprite_tile(6,4);
    set_sprite_tile(7,4);
    set_sprite_tile(8,4);
    set_sprite_tile(9,4);
    player[0] = 72;
    player[1] = 64;
    a = 0;
    b = 0;
    bola1[0] = 72;
    bola1[1] = 80;
    bola2[0] = 80;
    bola2[1] = 80;
    bola3[0] = 96;
    bola3[1] = 80;
    bola4[0] = 104;
    bola4[1] = 80;
    bola5[0] = 72;
    bola5[1] = 96;
    bola6[0] = 80;
    bola6[1] = 96;
    bola7[0] = 96;
    bola7[1] = 96;
    bola8[0] = 104;
    bola8[1] = 96;
    bola9[0] = 88;
    bola9[1] = 88;
}
void updateSwitches() {
	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
}
void checkInput() {
    b=0;
	if (joypad() & J_UP && ((player[1]>=65 && player[0]>65 && player[0]<103 ) || (player[1]>=73 && (player[0]<73 || player[0]>103 ) ))) {// UP		
		player[1]=player[1]-1;
	}
	if (joypad() & J_DOWN && player[1]<=103) {// DOWN		
		player[1]++;
	}
	if ((joypad() & J_LEFT) && ((player[0]>=73 && player[1]<=72) || (player[0]>=65 && player[1]>=72))) {// LEFT	
		player[0]=player[0]-1;
	}	
	if (joypad() & J_RIGHT &&((player[0]<=103 && player[1]<=72) || (player[0]<=111 && player[1]>=72))) {// RIGHT
		player[0]++;
	}
    if (!(joypad() & J_RIGHT) && !(joypad() & J_LEFT) && !(joypad() & J_DOWN) && !(joypad() & J_UP)&& !(joypad() & J_B)) {
        a=0;
        set_sprite_tile(0,a);
	}else{
		if ((a==0 || a==3) && b==0){
NR10_REG = 0x15;
NR11_REG = 0x96;
NR12_REG = 0x73;
NR13_REG = 0xBB;
NR14_REG = 0x85;
            a=1;
            b=1;
        }if ((a==1 || a ==2) && b==0){
            a=0;
            b=1;
        }
        set_sprite_tile(0,a);
    }
    if (joypad() & J_B) {
        NR10_REG = 0x4F;  
NR11_REG = 0x27;  
NR12_REG = 0xB7;  
NR13_REG = 0xBB;  
NR14_REG = 0x85;
        set_sprite_tile(0,2);
        delay(200);
        set_sprite_tile(0,3);
        delay(200);
    }
    if ((player[1]==bola1[1]-7) && (player[0]>bola1[0]-6) && (player[0]<bola1[0]+6)){
        bola1[1]=bola1[1]+1;
    }
    if ((player[0]==bola1[0]-7) && (player[1]>bola1[1]-6) && (player[1]<bola1[1]+6)){
        bola1[0]=bola1[0]+1;
    }
    if ((player[1]==bola1[1]+7) && (player[0]>bola1[0]-6) && (player[0]<bola1[0]+6)){
        bola1[1]=bola1[1]-1;
    }
    if ((player[0]==bola1[0]+7) && (player[1]>bola1[1]-6) && (player[1]<bola1[1]+6)){
        bola1[0]=bola1[0]-1;
    }
    if ((player[1]==bola2[1]-7) && (player[0]>bola2[0]-6) && (player[0]<bola2[0]+6)){
        bola2[1]=bola2[1]+1;
    }
    if ((player[0]==bola2[0]-7) && (player[1]>bola2[1]-6) && (player[1]<bola2[1]+6)){
        bola2[0]=bola2[0]+1;
    }
    if ((player[1]==bola2[1]+7) && (player[0]>bola2[0]-6) && (player[0]<bola2[0]+6)){
        bola2[1]=bola2[1]-1;
    }
    if ((player[0]==bola2[0]+7) && (player[1]>bola2[1]-6) && (player[1]<bola2[1]+6)){
        bola2[0]=bola2[0]-1;
    }
    if ((player[1]==bola3[1]-7) && (player[0]>bola3[0]-6) && (player[0]<bola3[0]+6)){
        bola3[1]=bola3[1]+1;
    }
    if ((player[0]==bola3[0]-7) && (player[1]>bola3[1]-6) && (player[1]<bola3[1]+6)){
        bola3[0]=bola3[0]+1;
    }
    if ((player[1]==bola3[1]+7) && (player[0]>bola3[0]-6) && (player[0]<bola3[0]+6)){
        bola3[1]=bola3[1]-1;
    }
    if ((player[0]==bola3[0]+7) && (player[1]>bola3[1]-6) && (player[1]<bola3[1]+6)){
        bola3[0]=bola3[0]-1;
    }
    if ((player[1]==bola4[1]-7) && (player[0]>bola4[0]-6) && (player[0]<bola4[0]+6)){
        bola4[1]=bola4[1]+1;
    }
    if ((player[0]==bola4[0]-7) && (player[1]>bola4[1]-6) && (player[1]<bola4[1]+6)){
        bola4[0]=bola4[0]+1;
    }
    if ((player[1]==bola4[1]+7) && (player[0]>bola4[0]-6) && (player[0]<bola4[0]+6)){
        bola4[1]=bola4[1]-1;
    }
    if ((player[0]==bola4[0]+7) && (player[1]>bola4[1]-6) && (player[1]<bola4[1]+6)){
        bola4[0]=bola4[0]-1;
    }
    if ((player[1]==bola5[1]-7) && (player[0]>bola5[0]-6) && (player[0]<bola5[0]+6)){
        bola5[1]=bola5[1]+1;
    }
    if ((player[0]==bola5[0]-7) && (player[1]>bola5[1]-6) && (player[1]<bola5[1]+6)){
        bola5[0]=bola5[0]+1;
    }
    if ((player[1]==bola5[1]+7) && (player[0]>bola5[0]-6) && (player[0]<bola5[0]+6)){
        bola5[1]=bola5[1]-1;
    }
    if ((player[0]==bola5[0]+7) && (player[1]>bola5[1]-6) && (player[1]<bola5[1]+6)){
        bola5[0]=bola5[0]-1;
    }
    if ((player[1]==bola6[1]-7) && (player[0]>bola6[0]-6) && (player[0]<bola6[0]+6)){
        bola6[1]=bola6[1]+1;
    }
    if ((player[0]==bola6[0]-7) && (player[1]>bola6[1]-6) && (player[1]<bola6[1]+6)){
        bola6[0]=bola6[0]+1;
    }
    if ((player[1]==bola6[1]+7) && (player[0]>bola6[0]-6) && (player[0]<bola6[0]+6)){
        bola6[1]=bola6[1]-1;
    }
    if ((player[0]==bola6[0]+7) && (player[1]>bola6[1]-6) && (player[1]<bola6[1]+6)){
        bola6[0]=bola6[0]-1;
    }
    
        if ((player[1]==bola7[1]-7) && (player[0]>bola7[0]-6) && (player[0]<bola7[0]+6)){
        bola7[1]=bola7[1]+1;
    }
    if ((player[0]==bola7[0]-7) && (player[1]>bola7[1]-6) && (player[1]<bola7[1]+6)){
        bola7[0]=bola7[0]+1;
    }
    if ((player[1]==bola7[1]+7) && (player[0]>bola7[0]-6) && (player[0]<bola7[0]+6)){
        bola7[1]=bola7[1]-1;
    }
    if ((player[0]==bola7[0]+7) && (player[1]>bola7[1]-6) && (player[1]<bola7[1]+6)){
        bola7[0]=bola7[0]-1;
    }
    if ((player[1]==bola8[1]-7) && (player[0]>bola8[0]-6) && (player[0]<bola8[0]+6)){
        bola8[1]=bola8[1]+1;
    }
    if ((player[0]==bola8[0]-7) && (player[1]>bola8[1]-6) && (player[1]<bola8[1]+6)){
        bola8[0]=bola8[0]+1;
    }
    if ((player[1]==bola8[1]+7) && (player[0]>bola8[0]-6) && (player[0]<bola8[0]+6)){
        bola8[1]=bola8[1]-1;
    }
    if ((player[0]==bola8[0]+7) && (player[1]>bola8[1]-6) && (player[1]<bola8[1]+6)){
        bola8[0]=bola8[0]-1;
    }
    if ((player[1]==bola9[1]-7) && (player[0]>bola9[0]-6) && (player[0]<bola9[0]+6)){
        bola9[1]=bola9[1]+1;
    }
    if ((player[0]==bola9[0]-7) && (player[1]>bola9[1]-6) && (player[1]<bola9[1]+6)){
        bola9[0]=bola9[0]+1;
    }
    if ((player[1]==bola9[1]+7) && (player[0]>bola9[0]-6) && (player[0]<bola9[0]+6)){
        bola9[1]=bola9[1]-1;
    }
    if ((player[0]==bola9[0]+7) && (player[1]>bola9[1]-6) && (player[1]<bola9[1]+6)){
        bola9[0]=bola9[0]-1;
    }
    if (joypad() & J_A) {
        NR10_REG = 0x15;
NR11_REG = 0x8D;
NR12_REG = 0x63;
NR13_REG = 0xC8;
NR14_REG = 0x80;
        player[0] = 72;
        player[1] = 64;
        a = 0;
        b = 0;
        bola1[0] = 72;
        bola1[1] = 80;
        bola2[0] = 80;
        bola2[1] = 80;
        bola3[0] = 96;
        bola3[1] = 80;
        bola4[0] = 104;
        bola4[1] = 80;
        bola5[0] = 72;
        bola5[1] = 96;
        bola6[0] = 80;
        bola6[1] = 96;
        bola7[0] = 96;
        bola7[1] = 96;
        bola8[0] = 104;
        bola8[1] = 96;
        bola9[0] = 88;
        bola9[1] = 88;
    }
    move_sprite(1, bola1[0], bola1[1]);
    move_sprite(2, bola2[0], bola2[1]);
    move_sprite(3, bola3[0], bola3[1]);
    move_sprite(4, bola4[0], bola4[1]);
    move_sprite(5, bola5[0], bola5[1]);
    move_sprite(6, bola6[0], bola6[1]);
    move_sprite(7, bola7[0], bola7[1]);
    move_sprite(8, bola8[0], bola8[1]);
    move_sprite(9, bola9[0], bola9[1]);
    move_sprite(0, player[0], player[1]);
    delay(50);
}