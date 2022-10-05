#include "buttons.h"

extern uint8_t CFG_HUD_LAYOUT;
extern uint8_t CFG_HIDE_HUD_ENABLED;
extern uint8_t CFG_B_BUTTON_ITEM_ENABLED;
extern uint8_t CFG_INVENTORY_EDITOR_ENABLED;
extern uint8_t CFG_INFINITE_HEALTH;
extern uint8_t CFG_INFINITE_MAGIC;
extern uint8_t CFG_INFINITE_AMMO;
extern uint8_t CFG_INFINITE_RUPEES;

uint8_t hud_hide		= 0;
uint8_t hud_hearts_hide	= 1;
uint8_t hud_counter		= 0;
uint8_t block			= 0;
uint8_t pressed_r		= 0;
uint8_t pressed_z		= 0;

void handle_buttons() {
	pad_t pad_pressed = z64_game.common.input[0].pad_pressed;
	
	handle_layout();
	handle_hud();
	set_b_button(pad_pressed);
	
	if (z64_game.pause_ctxt.state == 6 && pad_pressed.s && z64_game.pause_ctxt.unk_02_[1])
		z64_game.pause_ctxt.unk_02_[1] = 0;
}


void handle_l_button() {
	if (z64_game.pause_ctxt.state != 0 && z64_game.pause_ctxt.state != 6)
		return;
	
	pad_t pad_released = z64_game.common.input[0].pad_released;
	
	if (z64_game.common.input[0].raw.pad.r)
		pressed_r = 1;
	if (z64_game.common.input[0].raw.pad.z)
		pressed_z = 1;
	if (pad_released.l && !pressed_r && !pressed_z) {
		toggle_minimap();
		hide_hud();
		inventory_editor();
		handle_downgrading();
	}
	if (!z64_game.common.input[0].raw.pad.l)
		pressed_r = pressed_z = 0;
	
	if (z64_game.common.input[0].pad_pressed.l && !z64_game.common.input[0].raw.pad.r)
		block = 1;
	else if (z64_game.common.input[0].pad_pressed.l && !z64_game.common.input[0].raw.pad.z)
		block = 1;
	if (!z64_game.common.input[0].raw.pad.l)
		block = 0;
	
	if (block) {
		z64_game.common.input[0].raw.pad.r = z64_game.common.input[0].pad_pressed.r = 0;
		z64_game.common.input[0].raw.pad.z = z64_game.common.input[0].pad_pressed.z = 0;
	}
	
	z64_game.common.input[0].pad_pressed.l = 0;	
}

void handle_layout() {
	if (CFG_HUD_LAYOUT == 0 || !CAN_DRAW_HUD || z64_gameinfo.a_button_y == 9)
		return;
	
	uint16_t a_x = 0, a_y = 0, b_x = 0, b_y = 0, c_left_x = 0, c_left_y = 0, c_down_x = 0, c_down_y = 0, c_right_x = 0, c_right_y = 0, c_up_x = 0, c_up_y = 0;
	
	if (CFG_HUD_LAYOUT == 1) { // Majora's Mask
		a_x			= 4;	// 186	->	190
		a_y			= 14;	// 9	->	23
		b_x			= 7;	// 160	->	167
	}
	else if (CFG_HUD_LAYOUT == 2) { // Nintendo
		a_x			= 70;	// 186	->	256
		a_y			= 23;	// 9	->	32
		b_x			= 80;	// 160	->	240
		b_y			= 45;	// 11	->	56
		c_left_x	= 14;	// 227	->	241
		c_left_y	= 0;	// 18	->	18
		c_down_x	= 30;	// 249	->	279
		c_down_y	= -20;	// 34	->	14
		c_right_x	= -54;	// 271	->	217
		c_right_y	= 20;	// 18	->	38
		c_up_x		= 10;	// 254	->	264
		c_up_y		= -10;	// 16	->	6
	}
	else if (CFG_HUD_LAYOUT == 3) { // Modern
		a_x			= 46;	// 186	->	234
		a_y			= 45;	// 9	->	54
		b_x			= 104;	// 160	->	264
		b_y			= 23;	// 11	->	33
		c_left_x	= -10;	// 227	->	217
		c_left_y	= 20;	// 18	->	38
		c_down_x	= 30;	// 249	->	279		
		c_down_y	= -20;	// 34	->	14		
		c_right_x	= -30;	// 271	->	241
		c_right_y	= 0;	// 18	->	18
		c_up_x		= 10;	// 254	->	264		
		c_up_y		= -10;	// 16	->	6		
	}
	else if (CFG_HUD_LAYOUT == 4) { // GameCube (Original)
		a_x			= 55;	// 186	->	241
		a_y			= 20;	// 9	->	29
		b_x			= 65;	// 160	->	225
		b_y			= 40;	// 11	->	51
		c_left_x	= 24;	// 227	->	251
		c_left_y	= -10;	// 18	->	8
		c_down_x	= 30;	// 249	->	279
		c_down_y	= -20;	// 34	->	14
		c_right_x	= 11;	// 271	->	282
		c_right_y	= 25;	// 18	->	43
		c_up_x		= -20;	// 254	->	234
	}
	else if (CFG_HUD_LAYOUT == 5) { // GameCube (Modern)
		a_x			= 55;	// 186	->	241
		a_y			= 20;	// 9	->	29
		b_x			= 65;	// 160	->	225
		b_y			= 40;	// 11	->	51
		c_left_x	= 55;	// 227	->	282
		c_left_y	= 25;	// 18	->	43
		c_down_x	= 30;	// 249	->	279
		c_down_y	= -20;	// 34	->	14
		c_right_x	= -20;	// 271	->	251
		c_right_y	= -10;	// 18	->	8
		c_up_x		= -20;	// 254	->	234
	}
	
	z64_gameinfo.a_button_x			+= a_x;
	z64_gameinfo.a_button_y			+= a_y;
	z64_gameinfo.a_button_icon_x	+= a_x;
	z64_gameinfo.a_button_icon_y	+= a_y;
	z64_gameinfo.item_button_x[0]	+= b_x;
	z64_gameinfo.item_button_y[0]	+= b_y;
	z64_gameinfo.item_icon_x[0]		+= b_x;
	z64_gameinfo.item_icon_y[0]		+= b_y;
	z64_gameinfo.item_ammo_x[0]		+= b_x;
	z64_gameinfo.item_ammo_y[0]		+= b_y;
	z64_b_button_label_x			+= b_x;
	z64_b_button_label_y			+= b_y;
	z64_gameinfo.item_button_x[1]	+= c_left_x;
	z64_gameinfo.item_button_y[1]	+= c_left_y;
	z64_gameinfo.item_icon_x[1]		+= c_left_x;
	z64_gameinfo.item_icon_y[1]		+= c_left_y;
	z64_gameinfo.item_ammo_x[1]		+= c_left_x;
	z64_gameinfo.item_ammo_y[1]		+= c_left_y;
	z64_gameinfo.item_button_x[2]	+= c_down_x;
	z64_gameinfo.item_button_y[2]	+= c_down_y;
	z64_gameinfo.item_icon_x[2]		+= c_down_x;
	z64_gameinfo.item_icon_y[2]		+= c_down_y;
	z64_gameinfo.item_ammo_x[2]		+= c_down_x;
	z64_gameinfo.item_ammo_y[2]		+= c_down_y;
	z64_gameinfo.item_button_x[3]	+= c_right_x;
	z64_gameinfo.item_button_y[3]	+= c_right_y;
	z64_gameinfo.item_icon_x[3]		+= c_right_x;
	z64_gameinfo.item_icon_y[3]		+= c_right_y;
	z64_gameinfo.item_ammo_x[3]		+= c_right_x;
	z64_gameinfo.item_ammo_y[3]		+= c_right_y;
	z64_gameinfo.c_up_button_x		+= c_up_x;
	z64_gameinfo.c_up_button_y		+= c_up_y;
	z64_gameinfo.c_up_icon_x		+= c_up_x;
	z64_gameinfo.c_up_icon_y		+= c_up_y;
}

void toggle_minimap() {
	if (z64_game.pause_ctxt.state != 0 || hud_hide)
		return;
	
	if ( (z64_game.scene_index >= 0x00 && z64_game.scene_index <= 0x09 ) || (z64_game.scene_index >= 0x51 && z64_game.scene_index <= 0x64) ) {
		z64_gameinfo.minimap_disabled ^= 1;
		if (z64_gameinfo.minimap_disabled)
			z64_playsfx(0x4813, (z64_xyzf_t*)0x80104394, 0x04, (float*)0x801043A0, (float*)0x801043A0, (float*)0x801043A8);
		else z64_playsfx(0x4814, (z64_xyzf_t*)0x80104394, 0x04, (float*)0x801043A0, (float*)0x801043A0, (float*)0x801043A8);
	}
}

void handle_hud() {
	if (hud_hide && (z64_game.pause_ctxt.state == 0 || z64_game.pause_ctxt.state == 0x1A || z64_game.pause_ctxt.state == 0x1B) ) {
		if (z64_game.hud_alpha_channels.minimap != 0) {
			if (hud_counter < 8) {
				hud_counter++;
				return;
			}
		}
		else hud_counter = 0;
		
		if (z64_game.hud_alpha_channels.b_button              > 40)		z64_game.hud_alpha_channels.b_button          -= 40; else z64_game.hud_alpha_channels.b_button          = 0;
		if (z64_game.hud_alpha_channels.cl_button             > 40)		z64_game.hud_alpha_channels.cl_button         -= 40; else z64_game.hud_alpha_channels.cl_button         = 0;
		if (z64_game.hud_alpha_channels.cd_button             > 40)		z64_game.hud_alpha_channels.cd_button         -= 40; else z64_game.hud_alpha_channels.cd_button         = 0;
		if (z64_game.hud_alpha_channels.cr_button             > 40)		z64_game.hud_alpha_channels.cr_button         -= 40; else z64_game.hud_alpha_channels.cr_button         = 0;
		if (z64_game.hud_alpha_channels.a_button_carots       > 40)		z64_game.hud_alpha_channels.a_button_carots   -= 40; else z64_game.hud_alpha_channels.a_button_carots   = 0;
		if (z64_game.hud_alpha_channels.minimap               > 40)		z64_game.hud_alpha_channels.minimap           -= 40; else z64_game.hud_alpha_channels.minimap           = 0;
		
		if (hud_hearts_hide) {
			if (z64_game.hud_alpha_channels.hearts_navi       > 40)		z64_game.hud_alpha_channels.hearts_navi       -= 40; else z64_game.hud_alpha_channels.hearts_navi       = 0;
			if (z64_game.hud_alpha_channels.rupees_keys_magic > 40)		z64_game.hud_alpha_channels.rupees_keys_magic -= 40; else z64_game.hud_alpha_channels.rupees_keys_magic = 0;
		}
		else {
			if (z64_game.hud_alpha_channels.hearts_navi       < 215)	z64_game.hud_alpha_channels.hearts_navi       += 40; else z64_game.hud_alpha_channels.hearts_navi       = 255;
			if (z64_game.hud_alpha_channels.rupees_keys_magic < 215)	z64_game.hud_alpha_channels.rupees_keys_magic += 40; else z64_game.hud_alpha_channels.rupees_keys_magic = 255;
		}
	}
}

void hide_hud() {
	if (!CFG_HIDE_HUD_ENABLED || z64_game.pause_ctxt.unk_02_[1] != 0)
		return;
	
	if (z64_game.pause_ctxt.state == 6 && z64_game.pause_ctxt.screen_idx == 1) {
		hud_hide ^= 1;
		if (hud_hide)
			z64_playsfx(0x4813, (z64_xyzf_t*)0x80104394, 0x04, (float*)0x801043A0, (float*)0x801043A0, (float*)0x801043A8);
		else z64_playsfx(0x4814, (z64_xyzf_t*)0x80104394, 0x04, (float*)0x801043A0, (float*)0x801043A0, (float*)0x801043A8);
	}
	else if (z64_game.pause_ctxt.state == 0 && hud_hide)
		hud_hearts_hide ^= 1;
}

void set_b_button(pad_t pad_pressed) {
	if (!CFG_B_BUTTON_ITEM_ENABLED || !pad_pressed.a || z64_game.pause_ctxt.screen_idx != 0 || z64_game.pause_ctxt.unk_02_[1] != 0 || z64_game.pause_ctxt.cursor_pos == 0x0A || z64_game.pause_ctxt.cursor_pos == 0x0B || z64_game.pause_ctxt.item_cursor <= Z64_SLOT_STICK || z64_game.pause_ctxt.item_cursor >= Z64_SLOT_CHILD_TRADE)
		return;
	
	z64_item_t item = 0xFF;
	for (uint8_t i=0; i<18; i++)
		if (z64_game.pause_ctxt.item_cursor == i) {
			if ( (!z64_file.link_age && z64_usability.item[i] == 1) || (z64_file.link_age && z64_usability.item[i] == 0) )
				item = 0xFF;
			else item = z64_file.items[i];
		}
	
	if (item != Z64_ITEM_SLINGSHOT && item != Z64_ITEM_BOW && item != Z64_ITEM_BOMBCHU && item != Z64_ITEM_LENS && item <= Z64_ITEM_NAYRUS_LOVE) {
		z64_file.button_items[0] = item;
		if (!z64_file.link_age)
			z64_file.adult_button_items[0] = item;
		else if	(z64_file.link_age)
			z64_file.child_button_items[0] = item;
		z64_UpdateItemButton(&z64_game, 0);
		z64_playsfx(0x4808, (z64_xyzf_t*)0x80104394, 0x04, (float*)0x801043A0, (float*)0x801043A0, (float*)0x801043A8);
	}
}

void inventory_editor() {
	if (!CFG_INVENTORY_EDITOR_ENABLED || z64_game.pause_ctxt.state != 6)
		return;
	
	if (z64_game.pause_ctxt.unk_02_[1] == 0 && z64_game.pause_ctxt.screen_idx == 2) {
		z64_game.pause_ctxt.unk_02_[1] = 2;
		z64_playsfx(0x4813, (z64_xyzf_t*)0x80104394, 0x04, (float*)0x801043A0, (float*)0x801043A0, (float*)0x801043A8);
	}
	else if (z64_game.pause_ctxt.unk_02_[1] == 2) {
		z64_game.pause_ctxt.unk_02_[1] = 0;
		z64_playsfx(0x4814, (z64_xyzf_t*)0x80104394, 0x04, (float*)0x801043A0, (float*)0x801043A0, (float*)0x801043A8);
	}
}

void handle_infinite() {
	if (CFG_INFINITE_HEALTH) {
		if (z64_file.energy < z64_file.energy_capacity)
			z64_file.energy = z64_file.energy_capacity;
	}
	
	if (CFG_INFINITE_MAGIC) {
		if (z64_file.magic_acquired && z64_file.magic_capacity_set) {
			if (z64_file.magic_capacity)
				z64_file.magic = 0x60;
			else z64_file.magic = 0x30;
		}
	}
	
	if (CFG_INFINITE_AMMO) {
		if (z64_file.nut_upgrade == 1)
			z64_file.ammo[0x01] = z64_capacity.nut_upgrade[1];
		else if (z64_file.nut_upgrade == 2)
			z64_file.ammo[0x01] = z64_capacity.nut_upgrade[2];
		else if (z64_file.nut_upgrade == 3)
			z64_file.ammo[0x01] = z64_capacity.nut_upgrade[3];
		
		if (z64_file.stick_upgrade == 1)
			z64_file.ammo[0x00] = z64_capacity.stick_upgrade[1];
		else if (z64_file.stick_upgrade == 2)
			z64_file.ammo[0x00] = z64_capacity.stick_upgrade[2];
		else if (z64_file.stick_upgrade == 3)
			z64_file.ammo[0x00] = z64_capacity.stick_upgrade[3];
		
		if (z64_file.bullet_bag == 1)
			z64_file.ammo[0x06] = z64_capacity.bullet_bag[1];
		else if (z64_file.bullet_bag == 2)
			z64_file.ammo[0x06] = z64_capacity.bullet_bag[1];
		else if (z64_file.bullet_bag == 3)
			z64_file.ammo[0x06] = z64_capacity.bullet_bag[1];
		
		if (z64_file.quiver == 1)
			z64_file.ammo[0x03] = z64_capacity.quiver[1];
		else if (z64_file.quiver == 2)
			z64_file.ammo[0x03] = z64_capacity.quiver[2];
		else if (z64_file.quiver == 3)
			z64_file.ammo[0x03] = z64_capacity.quiver[3];
		
		if (z64_file.bomb_bag == 1)
			z64_file.ammo[0x02] = z64_capacity.bomb_bag[1];
		else if (z64_file.bomb_bag == 2)
			z64_file.ammo[0x02] = z64_capacity.bomb_bag[2];
		else if (z64_file.bomb_bag == 3)
			z64_file.ammo[0x02] = z64_capacity.bomb_bag[3];
		
		if (z64_file.items[Z64_SLOT_BOMBCHU] == Z64_ITEM_BOMBCHU)
			z64_file.ammo[0x08] = 50;
	}
	
	if (CFG_INFINITE_RUPEES) {
		if (z64_file.wallet == 0)
			z64_file.rupees = z64_capacity.wallet[0];
		else if (z64_file.wallet == 1)
			z64_file.rupees = z64_capacity.wallet[1];
		else if (z64_file.wallet == 2)
			z64_file.rupees = z64_capacity.wallet[2];
		else if (z64_file.wallet == 3)
			z64_file.rupees = z64_capacity.wallet[3];
	}
}