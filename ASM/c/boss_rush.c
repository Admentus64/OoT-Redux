#include "boss_rush.h"

extern uint8_t CFG_BOSS_RUSH;

uint8_t  started_rush = 0;

void heal_player() {
	z64_file.energy = z64_file.energy_capacity;
	z64_file.magic  = 0x30;
}

void reset_progress() {
	// SRAM
	/*for (uint8_t i=0; i<24; i++)
		z64_file.items[i] = 0xFF;
	for (uint8_t i=0; i<14; i++)
		z64_file.event_chk_inf[i] = 0;
	
	// Buttons
	for (uint8_t i=0; i<3; i++)
		z64_file.button_items[i+1] = z64_file.c_button_slots[i]      = z64_file.adult_button_items[i+1] = z64_file.adult_c_button_slots[i] = z64_file.child_button_items[i+1] = z64_file.child_c_button_slots[i] = 0xFF;
	z64_file.button_items[0]       =  z64_file.adult_button_items[0] = z64_file.child_button_items[0]   = 0xFF;*/
	
	// Clear SRAM events
	z64_file.event_chk_inf[4]  |= 1 << 11; // Door of Time
	z64_file.event_chk_inf[4]  |= 1 << 15; // Navi shows Master Sword
	z64_file.event_chk_inf[4]  |= 1 << 5;  // First time Master Sword
	z64_file.event_chk_inf[10] |= 1 << 7;  // Temple of Time intro
	z64_file.event_chk_inf[12] |= 1 << 5;  // Sheik introduction
	
	// Health and magic
	z64_file.energy             = z64_file.energy_capacity    = 0xA0;
	/*z64_file.double_defense     = 0;
	z64_file.magic_acquired     = z64_file.magic_capacity_set = 0;
	z64_file.magic              = 0;*/
	
	// Unequip
	/*z64_file.equip_sword   = z64_file.child_equip_sword  = z64_file.adult_equip_sword  = 0;
	z64_file.equip_shield  = z64_file.child_equip_shield = z64_file.adult_equip_shield = 0;
	z64_file.equip_tunic   = z64_file.child_equip_tunic  = z64_file.adult_equip_tunic  = 1;
	z64_file.equip_boots   = z64_file.child_equip_boots  = z64_file.adult_equip_boots  = 1;
	z64_file.inf_table[29] = 1;
	
	// Equipment
	z64_file.kokiri_boots       = z64_file.kokiri_tunic       = 1;
	z64_file.iron_boots         = z64_file.hover_boots        = 0;
	z64_file.goron_tunic        = z64_file.zora_tunic         = 0;
	z64_file.kokiri_sword       = z64_file.master_sword       = z64_file.giants_knife  = z64_file.broken_giants_knife = 0;
	z64_file.deku_shield        = z64_file.hylian_shield      = z64_file.mirror_shield = 0;
	
	// Progress
	z64_file.rupees           = 0;
	z64_file.light_medallion  = z64_file.forest_medallion = z64_file.fire_medallion = z64_file.water_medallion   = z64_file.shadow_medallion   = z64_file.spirit_medallion  = 0;
	z64_file.kokiris_emerald  = z64_file.gorons_ruby      = z64_file.zoras_sapphire = 0;
	z64_file.stone_of_agony   = z64_file.gerudos_card     = 0;
	z64_file.zeldas_lullaby   = z64_file.eponas_song      = z64_file.suns_song      = z64_file.sarias_song       = z64_file.song_of_time       = z64_file.song_of_storms    = 0;
	z64_file.prelude_of_light = z64_file.minuet_of_forest = z64_file.bolero_of_fire = z64_file.serenade_of_water = z64_file.nocturne_of_shadow = z64_file.requiem_of_spirit = 0;
	z64_file.bullet_bag       = z64_file.nut_upgrade      = z64_file.stick_upgrade  = z64_file.bomb_bag          = z64_file.quiver             = z64_file.strength_upgrade  = z64_file.diving_upgrade = 0;
	z64_file.ammo[0]          = z64_file.ammo[1]          = z64_file.ammo[2]        = z64_file.ammo[3]           = z64_file.ammo[6]            = z64_file.ammo[8]           = z64_file.ammo[14]       = 0;*/
}

void set_progress() {
	if (!CFG_BOSS_RUSH)
		return;
	
	if (z64_file.link_age == 1 && z64_game.scene_index == 0x34) { // Link's House
		reset_progress();
		started_rush          = 1;
		z64_file.kokiri_sword = 1;
	}
	
	if (!started_rush)
		return;
	
	if (z64_game.scene_index == 0x11) { // Gohma
		z64_file.deku_shield               = z64_file.bullet_bag = z64_file.nut_upgrade = z64_file.stick_upgrade = 1;
		z64_file.items[Z64_SLOT_SLINGSHOT] = Z64_ITEM_SLINGSHOT;
		z64_file.items[Z64_SLOT_NUT]       = Z64_ITEM_NUT;
		z64_file.items[Z64_SLOT_STICK]     = Z64_ITEM_STICK;
		z64_file.ammo[0]                   = z64_capacity.stick_upgrade[z64_file.stick_upgrade];
		z64_file.ammo[1]                   = z64_capacity.nut_upgrade[z64_file.nut_upgrade];
		z64_file.ammo[6]                   = z64_capacity.bullet_bag[z64_file.bullet_bag];
	}
	
	if (z64_game.scene_index == 0x12) { // King Dodongo
		z64_file.kokiris_emerald             = z64_file.hylian_shield = z64_file.strength_upgrade = z64_file.zeldas_lullaby = z64_file.eponas_song = z64_file.suns_song = z64_file.sarias_song = z64_file.bomb_bag = 1;
		z64_file.items[Z64_SLOT_OCARINA]     = Z64_ITEM_FAIRY_OCARINA;
		z64_file.items[Z64_SLOT_BOTTLE_1]    = Z64_ITEM_FAIRY;
		z64_file.items[Z64_SLOT_CHILD_TRADE] = Z64_ITEM_ZELDAS_LETTER;
		z64_file.items[Z64_SLOT_BOMB]        = Z64_ITEM_BOMB;
		z64_file.ammo[2]                     = z64_capacity.bomb_bag[z64_file.bomb_bag];
	}
	
	if (z64_game.scene_index == 0x13) { // Barinade
		z64_file.gorons_ruby               = z64_file.magic_acquired = z64_file.magic_capacity_set = z64_file.diving_upgrade = 1;
		z64_file.magic                     = 0x30;
		z64_file.items[Z64_SLOT_BOOMERANG] = Z64_ITEM_BOOMERANG;
		z64_file.items[Z64_SLOT_BOTTLE_2]  = Z64_ITEM_FAIRY;
	}
	
	if (z64_game.scene_index == 0x43) { // Temple of Time
		heal_player();
		z64_file.zoras_sapphire = z64_file.song_of_time = 1;
		z64_file.ammo[2]        = z64_capacity.bomb_bag[z64_file.bomb_bag];
	}
	
	if (z64_game.scene_index == 0x14) { // Phantom Ganon
		z64_file.light_medallion             = z64_file.master_sword = z64_file.song_of_storms = z64_file.quiver = 1;
		z64_file.items[Z64_SLOT_HOOKSHOT]    = Z64_ITEM_HOOKSHOT;
		z64_file.items[Z64_SLOT_BOTTLE_3]    = Z64_ITEM_FAIRY;
		z64_file.items[Z64_SLOT_ADULT_TRADE] = Z64_ITEM_POCKET_EGG;
		z64_file.items[Z64_SLOT_BOW]         = Z64_ITEM_BOW;
		z64_file.ammo[3]                     = z64_capacity.quiver[z64_file.quiver];
	}
	
	if (z64_game.scene_index == 0x15) { // Volvagia
		z64_file.forest_medallion         = z64_file.goron_tunic = 1;
		z64_file.items[Z64_SLOT_HAMMER]   = Z64_ITEM_HAMMER;
		z64_file.items[Z64_SLOT_BOTTLE_4] = Z64_ITEM_FAIRY;
		z64_file.items[Z64_SLOT_BOMBCHU]  = Z64_ITEM_BOMBCHU;
		z64_file.ammo[8] = 20;
	}
	
	if (z64_game.scene_index == 0x16) { // Morpha
		z64_file.fire_medallion           = z64_file.zora_tunic = z64_file.iron_boots = 1;
		z64_file.items[Z64_SLOT_HOOKSHOT] = Z64_ITEM_LONGSHOT;
	}
	
	if (z64_game.scene_index == 0x18) { // Bongo Bongo
		z64_file.water_medallion            = z64_file.hover_boots = 1;
		z64_file.items[Z64_SLOT_FIRE_ARROW] = Z64_ITEM_FIRE_ARROW;
		z64_file.items[Z64_SLOT_ICE_ARROW]  = Z64_ITEM_ICE_ARROW;
		z64_file.items[Z64_SLOT_LENS]       = Z64_ITEM_LENS;
	}
	
	if (z64_game.scene_index == 0x17) { // Twinrova
		z64_file.shadow_medallion  = z64_file.mirror_shield = 1;
		z64_file.strength_upgrade  = 2;
	}
	
	if (z64_game.scene_index == 0x19) { // Ganondorf
		z64_file.spirit_medallion            = 1;
		z64_file.strength_upgrade            = 3;
		z64_file.items[Z64_SLOT_LIGHT_ARROW] = Z64_ITEM_LIGHT_ARROW;
	}
}