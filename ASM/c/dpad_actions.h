#ifndef DPAD_ACTIONS_H
#define DPAD_ACTIONS_H

#include "z64.h"

typedef void(*use_item_t)                   (z64_game_t* game, z64_link_t* link, u8  item);
typedef void(*update_bottle_item_t)         (z64_game_t* game, u8          item, u8  button);
typedef void(*update_bottle_held_t)         (z64_game_t* game, z64_link_t* link, s32 item, s32 item_action);

void change_sword(    z64_game_t* game, z64_link_t* link, u8 sword);
void change_shield(   z64_game_t* game, z64_link_t* link, u8 shield);
void change_tunic(    z64_game_t* game, z64_link_t* link, u8 tunic);
void change_boots(    z64_game_t* game, z64_link_t* link, u8 boots);
void change_equipment(z64_game_t* game, z64_link_t* link);

bool can_use_ocarina();
bool can_use_child_trade();
bool can_use_adult_trade();
bool can_use_items();
bool can_use_lens();
bool can_use_farores_wind();
bool is_semi_alpha(u8 alpha);

void  draw_dpad_actions(   z64_disp_buf_t* db,   u8          alpha);
void  run_equipment_action(z64_game_t*     game, z64_link_t* link,   u8  action);
void  draw_action(         z64_disp_buf_t* db,   z64_slot_t  action, s8  icon_x, s8  icon_y, s8 icon_big_x, s8 icon_big_y, u8 alpha);
void  draw_ammo(           z64_disp_buf_t* db,   u8          item,   u16 x,      u16 y,      u8 size,       s8 spacing,    u8 alpha);

void toggle_sword(    z64_game_t* game, z64_link_t* link);
void toggle_shield(   z64_game_t* game, z64_link_t* link);
void toggle_tunic(    z64_game_t* game, z64_link_t* link);
void toggle_boots(    z64_game_t* game, z64_link_t* link);
void swap_goron_tunic(z64_game_t* game, z64_link_t* link);
void swap_zora_tunic( z64_game_t* game, z64_link_t* link);
void swap_iron_boots( z64_game_t* game, z64_link_t* link);
void swap_hover_boots(z64_game_t* game, z64_link_t* link);
void use_item(        z64_slot_t slot,  u8 usability);

void draw_sword_icon(      z64_disp_buf_t* db,                                     s8 icon_x, s8 icon_y,                                 u8 alpha);
void draw_shield_icon(     z64_disp_buf_t* db,                                     s8 icon_x, s8 icon_y,                                 u8 alpha);
void draw_tunic_icon(      z64_disp_buf_t* db,                                     s8 icon_x, s8 icon_y,                                 u8 alpha);
void draw_boots_icon(      z64_disp_buf_t* db,                                     s8 icon_x, s8 icon_y,                                 u8 alpha);
void draw_equipment_icon(  z64_disp_buf_t* db,                                     s8 icon_x, s8 icon_y, s8   icon_big_x, s8 icon_big_y, u8 alpha, u8 icon, bool has_item, bool is_equipped);
void draw_child_trade_icon(z64_disp_buf_t* db, z64_item_t item,                    s8 icon_x, s8 icon_y, s8   icon_big_x, s8 icon_big_y, u8 alpha);
void draw_adult_trade_icon(z64_disp_buf_t* db, z64_item_t item,                    s8 icon_x, s8 icon_y,                                 u8 alpha);
void draw_ocarina_icon(    z64_disp_buf_t* db, z64_item_t item,                    s8 icon_x, s8 icon_y,                                 u8 alpha);
void draw_arrow_icon(      z64_disp_buf_t* db, z64_item_t item,   z64_slot_t slot, s8 icon_x, s8 icon_y, bool usability,                 u8 alpha);
void draw_item_icon(       z64_disp_buf_t* db, z64_item_t item,   z64_slot_t slot, s8 icon_x, s8 icon_y, bool usability,                 u8 alpha);
void draw_dpad_icon(       z64_disp_buf_t* db, sprite_t*  sprite, u8         icon, s8 x,      s8 y,      u8   size);

void                   player_update_bottle_item(  z64_game_t* game, z64_item_t              item, u8                button);
void                   update_c_button_bottle_item(z64_game_t* game, z64_item_t              item, z64_item_button_t button);
void                   player_process_item_buttons(z64_link_t* link, z64_game_t*             game);
bool                   player_item_is_in_use(      z64_link_t* link, z64_item_t              item);
z64_action_parameter_t player_item_to_item_action( z64_item_t  item);
bool                   player_item_is_item_action( z64_item_t  item,  z64_action_parameter_t item_action);
z64_item_t             player_get_item_on_button(  z64_game_t* game,  u8                     index);
z64_item_t             get_dpad_btn_item(          u8          button);
bool                   has_lens_on_dpad_button();

/* D-Pad */
#define CHECK_BTN_ALL(state, combo)         (((state) & (combo)) == (combo))
#define BTN_B                               0x4000
#define BTN_CLEFT                           0x0002
#define BTN_CDOWN                           0x0004
#define BTN_CRIGHT                          0x0001
#define BTN_DUP                             0x0800
#define BTN_DDOWN                           0x0400
#define BTN_DLEFT                           0x0200
#define BTN_DRIGHT                          0x0100
#define BLOCK_ITEMS                         (PLAYER_STATE1_RIDING | PLAYER_STATE1_CLIMBING | PLAYER_STATE1_SWIMMING /*| PLAYER_STATE1_HOLDING_ABOVE_HEAD*/)
#define B_BTN_ITEM                          ((z64_file.button_status[0] == Z64_ITEM_NONE) ? Z64_ITEM_NONE : (z64_file.button_items[0] == Z64_ITEM_GIANTS_KNIFE) ? Z64_ITEM_BIGGORON_SWORD : z64_file.button_items[0])
#define C_BTN_ITEM(button)                  ((z64_file.button_status[(button) + 1] != BTN_DISABLED) ? z64_file.button_items[(button) + 1] : Z64_ITEM_NONE)
#define BLOCK_HOOKSHOT                      (((z64_link.state_flags_3 & (1 << 7))) && z64_game.bombchuBowlingStatus == 0 && z64_game.shootingGalleryStatus == 0)

/* D-Pad variables and checks */
#define z64_use_held_item                   (*(s32*)           0x803A9E74)
#define z64_held_item_button_is_held_down   (*(s32*)           0x803A9E78)
#define z64_dpad_lens_1                     (*(u16*)           0x80072D40)
#define z64_dpad_lens_2                     (*(u16*)           0x80072D4C)
#define z64_dpad_lens_3                     (*(u16*)           0x80072D58)
#define z64_throw_check_1                   (*(u8*)            0x8038B8B6)
#define z64_throw_check_2                   (*(u8*)            0x803955A2)
#define z64_throw_check_3                   (*(u8*)            0x8039AC2E)
#define z64_throw_check_4                   (*(u8*)            0x8039CDAE)

/* Functions */
#define Player_UseItem                      ((use_item_t)               0x8038C9A0) // ROM: 0xBD19B0
#define Inventory_UpdateBottleItem          ((update_bottle_item_t)     0x80071B7C) // ROM: 0xAE7ADC
#define Player_UpdateBottleHeld             ((update_bottle_held_t)     0x80079848) // ROM: 0xAEF7A8



/* Backup */
//#define Player_IsHoldingHookshot          ((is_holding_hookshot_t)    0x80079854) // ROM: 0xAEF7B4
//#define Player_ItemToItemAction           ((item_to_item_action_t)    0x8038A0EC) // ROM: 0xBCF0FC
//#define Player_ItemIsInUse                ((item_is_in_use_t)         0x8038A654) // ROM: 0xBCF664
//#define Player_ItemIsItemAction           ((item_is_item_action_t)    0x8038A6A0) // ROM: 0xBCF6B0
//#define Player_GetItemOnButton            ((get_item_on_button_t)     0x8038A6DC) // ROM: 0xBCF6EC
//#define z64_dpad_item_in_use              (*(u16*)                    0x8038A9D4)
//#define z64_dpad_b_button_prompt          (*(u16*)                    0x803AABE8)
//#define z64_dpad_b_button_item_check      (*(u16*)                    0x8038A73C)
//#define z64_dpad_b_button_item            (*(u8*)                     0x8038A74B)
//#define z64_dpad_item_b                   (*(u16*)                    0x8038A948)
//#define z64_dpad_item_1                   (*(u16*)                    0x8038A978)
//#define z64_dpad_item_2                   (*(u16*)                    0x8038A9A8)
//#define z64_dpad_item_3                   (*(u16*)                    0x8038A9D4)
//#define z64_dpad_index_b_check            (*(u16*)                    0x8038A724)
//#define z64_dpad_index_cl_check           (*(u16*)                    0x8038A770)
//#define z64_dpad_check_all_buttons_1      (*(u16*)                    0x8038AA10)
//#define z64_dpad_check_all_buttons_2      (*(u16*)                    0x8038AA6C)
//#define z64_dpad_held_button_1            (*(u16*)                    0x8038B6A8) // ROM: 0xBD06B8
//#define z64_dpad_held_button_2            (*(u16*)                    0x8038BD1C) // ROM: 0xBD0D2C
//#define z64_dpad_held_button_3            (*(u16*)                    0x8038BE70) // ROM: 0xBD0E80
//#define z64_dpad_held_button_4            (*(u16*)                    0x8038C3D0) // ROM: 0xBD13E0
//#define z64_held_item_check               (*(u16*)                    0x8038CDF4)
//#define z64_dpad_get_index_none           (*(s8*)                     0x8038A6FB)
//#define z64_dpad_buttons_prompt_1         (*(u32*)                    0x803AABE8)
//#define z64_dpad_buttons_prompt_2         (*(u32*)                    0x803AABEC)
//#define z64_dpad_get_index_cl_1           (*(u8*)                     0x8038A77F)
//#define z64_dpad_get_index_cl_2           (*(u8*)                     0x8038A793)

#endif