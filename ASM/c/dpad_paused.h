#ifndef DPAD_PAUSED_H
#define DPAD_PAUSED_H

#include "z64.h"

void handle_dpad_paused();
void handle_dpad_slots(  pad_t      pad_pressed);
void set_dpad_action(    pad_t      pad_pressed, z64_slot_t slot);
u8   run_set_dpad_action(z64_slot_t slot,        u8         button);
void handle_unequipping( pad_t      pad_pressed);
void handle_switch_mask( pad_t      pad_pressed);
u8   get_next_mask();
void update_trade_equips(u8         item,        u8         slot);
void handle_downgrading( pad_t      pad_pressed);
void swap_item(          z64_slot_t slot,        z64_item_t original, z64_item_t swap);
void unequip_gear(       u8         play);
void unequip_sword(      u8         play);
void unequip_shield();
void unequip_tunic();

#endif
