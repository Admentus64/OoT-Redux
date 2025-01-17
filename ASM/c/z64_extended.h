#ifndef Z64_EXTENDED_H
#define Z64_EXTENDED_H

#include "z64.h"

typedef void(*playsfx_t)(uint16_t sfx, z64_xyzf_t *unk_00_, int8_t unk_01_ , float *unk_02_, float *unk_03_, float *unk_04_);
typedef void(*usebutton_t)(z64_game_t *game, z64_link_t *link, uint8_t item, uint8_t button);

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

typedef enum {
    DPAD_NULL = 0x0,
    DPAD_SWORD,
    DPAD_SHIELD,
    DPAD_TUNIC,
    DPAD_BOOTS,
    DPAD_IRON_BOOTS,
    DPAD_HOVER_BOOTS,
    DPAD_ARROWS,
    DPAD_NUT,
    DPAD_LENS,
    DPAD_OCARINA,
    DPAD_CHILD_TRADE,
    DPAD_ADULT_TRADE,
    DPAD_DINS_FIRE,
    DPAD_FARORES_WIND,
    DPAD_NAYRUS_LOVE,
} dpad_action_t;

typedef enum {
    LIMIT_STICK = 0x0,
    LIMIT_NUT,
    LIMIT_BOMB,
    LIMIT_BOW,
    LIMIT_FIRE_ARROW,
    LIMIT_DINS_FIRE,
    LIMIT_SLINGSHOT,
    LIMIT_OCARINA,
    LIMIT_BOMBCHU,
    LIMIT_HOOKSHOT,
    LIMIT_ICE_ARROW,
    LIMIT_FARORES_WIND,
    LIMIT_BOOMERANG,
    LIMIT_LENS,
    LIMIT_BEANS,
    LIMIT_HAMMER,
    LIMIT_LIGHT_ARROW,
    LIMIT_NAYRUS_LOVE,
    LIMIT_BOTTLE_1,
    LIMIT_BOTTLE_2,
    LIMIT_BOTTLE_3,
    LIMIT_BOTTLE_4,
    LIMIT_ADULT_TRADE,
    LIMIT_CHILD_TRADE,
    LIMIT_QUIVER,
    LIMIT_KOKIRI_SWORD,
    LIMIT_MASTER_SWORD,
    LIMIT_GIANTS_KNIFE,
    LIMIT_BOMB_BAG,
    LIMIT_DEKU_SHIELD,
    LIMIT_HYLIAN_SHIELD,
    LIMIT_MIRROR_SHIELD,
    LIMIT_STRENGTH,
    LIMIT_KOKIRI_TUNIC,
    LIMIT_GORON_TUNIC,
    LIMIT_ZORA_TUNIC,
    LIMIT_SCALE,
    LIMIT_KOKIRI_BOOTS,
    LIMIT_IRON_BOOTS,
    LIMIT_HOVER_BOOTS,
} limit_item_t;

typedef enum {
    OPTIONS_SIZE_CORE  = 17,
    OPTIONS_SIZE_MAIN  = 27,
    OPTIONS_SIZE_ALL   = 34,
    
    OPTION_30_FPS = 0,
    OPTION_ARROW_TOGGLE,
    OPTION_DPAD,
    OPTION_SHOW_DPAD,
    OPTION_HIDE_HUD,
    OPTION_HUD_LAYOUT,
    OPTION_SHOW_HEALTH,
    OPTION_CHEST_CONTENTS,
    OPTION_A_BUTTON_SCALE,
    OPTION_B_BUTTON_SCALE,
    OPTION_C_LEFT_BUTTON_SCALE,
    OPTION_C_DOWN_BUTTON_SCALE,
    OPTION_C_RIGHT_BUTTON_SCALE,
    OPTION_INVERSE_AIM,
    OPTION_NO_IDLE_CAMERA,
    OPTION_KEEP_MASK,
    OPTION_TRISWIPE,
    
    OPTION_DAMAGE_TAKEN,
    OPTION_RANDOM_ENEMIES,
    OPTION_UNEQUIP_ITEM,
    OPTION_UNEQUIP_GEAR,
    OPTION_ITEM_ON_B,
    OPTION_DOWNGRADE_ITEM,
    OPTION_CROUCH_STAB_FIX,
    OPTION_WEAKER_SWORDS,
    OPTION_EXTRA_ABILITIES,
    OPTION_RUPEE_DRAIN,
    
    OPTION_FOG,
    OPTION_INVENTORY_EDITOR,
    OPTION_LEVITATION,
    OPTION_INFINITE_HP,
    OPTION_INFINITE_MP,
    OPTION_INFINITE_RUPEES,
    OPTION_INFINITE_AMMO,
} option;

typedef enum {
    /* 0x01 */ CHEST_BOMBS_5 = 1,
    /* 0x02 */ CHEST_DEKU_NUTS,
    /* 0x03 */ CHEST_BOMBCHU_10,
    /* 0x04 */ CHEST_FAIRY_BOW,
    /* 0x05 */ CHEST_FAIRY_SLINGSHOT,
    /* 0x06 */ CHEST_BOOMERANG,
    /* 0x07 */ CHEST_DEKU_STICK_1,
    /* 0x08 */ CHEST_HOOKSHOT,
    /* 0x09 */ CHEST_LONGSHOT,
    /* 0x0A */ CHEST_LENS_OF_TRUTH,
    /* 0x0B */ CHEST_ZELDAS_LETTER,
    /* 0x0C */ CHEST_OCARINA_OF_TIME,
    /* 0x0D */ CHEST_MEGATON_HAMMER,
    /* 0x0E */ CHEST_COJIRO,
    /* 0x0F */ CHEST_EMPTY_BOTTLE,
    /* 0x10 */ CHEST_RED_POTION,
    /* 0x11 */ CHEST_GREEN_POTION,
    /* 0x12 */ CHEST_BLUE_POTION,
    /* 0x13 */ CHEST_FAIRY,
    /* 0x14 */ CHEST_LON_LON_MILK_FULL,
    /* 0x15 */ CHEST_RUTOS_LETTER,
    /* 0x16 */ CHEST_MAGIC_BEAN,
    /* 0x17 */ CHEST_SKULL_MASK,
    /* 0x18 */ CHEST_SPOOKY_MASK,
    /* 0x19 */ CHEST_CUCCO,
    /* 0x1A */ CHEST_KEATON_MASK,
    /* 0x1B */ CHEST_BUNNY_HOOD,
    /* 0x1C */ CHEST_MASK_OF_TRUTH,
    /* 0x1D */ CHEST_POCKET_EGG,
    /* 0x1E */ CHEST_POCKET_CUCCO,
    /* 0x1F */ CHEST_ODD_MUSHROOM,
    /* 0x20 */ CHEST_ODD_POTION,
    /* 0x21 */ CHEST_POACHERS_SAW,
    /* 0x22 */ CHEST_BROKEN_GORONS_SWORD,
    /* 0x23 */ CHEST_PRESCRIPTION,
    /* 0x24 */ CHEST_EYEBALL_FROG,
    /* 0x25 */ CHEST_EYE_DROPS,
    /* 0x26 */ CHEST_CLAIM_CHECK,
    /* 0x27 */ CHEST_KOKIRI_SWORD,
    /* 0x28 */ CHEST_GIANTS_KNIFE,
    /* 0x29 */ CHEST_DEKU_SHIELD,
    /* 0x2A */ CHEST_HYLIAN_SHIELD,
    /* 0x2B */ CHEST_MIRROR_SHIELD,
    /* 0x2C */ CHEST_GORON_TUNIC,
    /* 0x2D */ CHEST_ZORA_TUNIC,
    /* 0x2E */ CHEST_IRON_BOOTS,
    /* 0x2F */ CHEST_HOVER_BOOTS,
    /* 0x30 */ CHEST_QUIVER_40,
    /* 0x31 */ CHEST_QUIVER_50,
    /* 0x32 */ CHEST_BOMB_BAG_20,
    /* 0x33 */ CHEST_BOMB_BAG_30,
    /* 0x34 */ CHEST_BOMB_BAG_40,
    /* 0x35 */ CHEST_SILVER_GAUNTLETS,
    /* 0x36 */ CHEST_GOLDEN_GAUNTLETS,
    /* 0x37 */ CHEST_SILVER_SCALE,
    /* 0x38 */ CHEST_GOLDEN_SCALE,
    /* 0x39 */ CHEST_STONE_OF_AGONY,
    /* 0x3A */ CHEST_GERUDO_MEMBERSHIP_CARD,
    /* 0x3B */ CHEST_FAIRY_OCARINA,
    /* 0x3C */ CHEST_DEKU_SEEDS_5,
    /* 0x3D */ CHEST_HEART_CONTAINER,
    /* 0x3E */ CHEST_PIECE_OF_HEART,
    /* 0x3F */ CHEST_BOSS_KEY,
    /* 0x40 */ CHEST_COMPASS,
    /* 0x41 */ CHEST_DUNGEON_MAP,
    /* 0x42 */ CHEST_SMALL_KEY,
    /* 0x43 */ CHEST_SMALL_MAGIC_JAR,
    /* 0x44 */ CHEST_LARGE_MAGIC_JAR,
    /* 0x45 */ CHEST_ADULT_WALLET,
    /* 0x46 */ CHEST_GIANT_WALLET,
    /* 0x47 */ CHEST_WEIRD_EGG,
    /* 0x48 */ CHEST_RECOVERY_HEART,
    /* 0x49 */ CHEST_ARROWS_5,
    /* 0x4A */ CHEST_ARROWS_10,
    /* 0x4B */ CHEST_ARROWS_30,
    /* 0x4C */ CHEST_GREEN_RUPEE,
    /* 0x4D */ CHEST_BLUE_RUPEE,
    /* 0x4E */ CHEST_RED_RUPEE,
    /* 0x4F */ CHEST_HEART_CONTAINER_2,
    /* 0x50 */ CHEST_LON_LON_MILK,
    /* 0x51 */ CHEST_GORON_MASK,
    /* 0x52 */ CHEST_ZORA_MASK,
    /* 0x53 */ CHEST_GERUDO_MASK,
    /* 0x54 */ CHEST_GORONS_BRACELET,
    /* 0x55 */ CHEST_PURPLE_RUPEE,
    /* 0x56 */ CHEST_GOLD_RUPEE,
    /* 0x57 */ CHEST_BIGGORON_SWORD,
    /* 0x58 */ CHEST_FIRE_ARROW,
    /* 0x59 */ CHEST_ICE_ARROW,
    /* 0x5A */ CHEST_LIGHT_ARROW,
    /* 0x5B */ CHEST_GOLD_SKULLTULA_TOKEN,
    /* 0x5C */ CHEST_DINS_FIRE,
    /* 0x5D */ CHEST_FARORES_WIND,
    /* 0x5E */ CHEST_NAYRUS_LOVE,
    /* 0x5F */ CHEST_BULLET_BAG_30,
    /* 0x60 */ CHEST_BULLET_BAG_40,
    /* 0x61 */ CHEST_DEKU_STICKS_5,
    /* 0x62 */ CHEST_DEKU_STICK_10,
    /* 0x63 */ CHEST_DEKU_NUTS_5,
    /* 0x64 */ CHEST_DEKU_NUTS_10,
    /* 0x65 */ CHEST_BOMB,
    /* 0x66 */ CHEST_BOMBS_10,
    /* 0x67 */ CHEST_BOMBS_20,
    /* 0x68 */ CHEST_BOMBS_30,
    /* 0x69 */ CHEST_DEKU_SEEDS_30,
    /* 0x6A */ CHEST_BOMBCHU_5,
    /* 0x6B */ CHEST_BOMBCHU_20,
    /* 0x6C */ CHEST_FISH,
    /* 0x6D */ CHEST_BUG,
    /* 0x6E */ CHEST_BLUE_FIRE,
    /* 0x6F */ CHEST_POE,
    /* 0x70 */ CHEST_BIG_POE,
    /* 0x71 */ CHEST_DOOR_KEY,
    /* 0x72 */ CHEST_LOSER_GREEN_RUPEE,
    /* 0x73 */ CHEST_LOSER_BLUE_RUPEE,
    /* 0x74 */ CHEST_LOSER_RED_RUPEE,
    /* 0x75 */ CHEST_WINNER_PURPLE_RUPEE,
    /* 0x76 */ CHEST_WINNER_PIECE_OF_HEART,
    /* 0x77 */ CHEST_DEKU_STICK_UPGRADE_20,
    /* 0x78 */ CHEST_DEKU_STICK_UPGRADE_30,
    /* 0x79 */ CHEST_DEKU_NUT_UPGRADE_30,
    /* 0x7A */ CHEST_DEKU_NUT_UPGRADE_40,
    /* 0x7B */ CHEST_BULLET_BAG_50,
    /* 0x7C */ CHEST_ICE_TRAP,
} ChestItemID;

typedef enum {
    A_BUTTON = -1,
    B_BUTTON,
    C_LEFT_BUTTON,
    C_DOWN_BUTTON,
    C_RIGHT_BUTTON,
} button;

typedef struct {
    char item[0x002C];
} z64_usability_t;

typedef struct {
    uint16_t quiver[4];        // 0,  30,  40,  50
    uint16_t bomb_bag[4];      // 0,  20,  30,  40
    uint16_t u1[8];            // Unused
    uint16_t wallet[4];        // 99, 200, 500, 500
    uint16_t bullet_bag[4];    // 0,  30,  40,  50
    uint16_t stick_upgrade[4]; // 0,  20,  30,  40
    uint16_t nut_upgrade[4];   // 0,  10,  20,  30
} z64_capacity_t;

typedef enum {
    HUD_VISIBILITY_NO_CHANGE       = 0,
    HUD_VISIBILITY_NOTHING,
    HUD_VISIBILITY_NOTHING_ALT,
    HUD_VISIBILITY_HEARTS_FORCE,
    HUD_VISIBILITY_A,
    HUD_VISIBILITY_A_HEARTS_MAGIC_FORCE,
    HUD_VISIBILITY_A_HEARTS_MAGIC_MINIMAP_FORCE,
    HUD_VISIBILITY_ALL_NO_MINIMAP_BY_BTN_STATUS,
    HUD_VISIBILITY_B,
    HUD_VISIBILITY_HEARTS_MAGIC,
    HUD_VISIBILITY_B_ALT,
    HUD_VISIBILITY_HEARTS,
    HUD_VISIBILITY_A_B_MINIMAP,
    HUD_VISIBILITY_HEARTS_MAGIC_FORCE,
    HUD_VISIBILITY_ALL             = 50,
    HUD_VISIBILITY_NOTHING_INSTANT = 52
} z64_hud_visibility_mode_t;



/* Functions */
#define z64_usebutton                   ((usebutton_t)          0x8038C9A0)

/* DRAM addresses & data */
#define z64_usability                   (*(z64_usability_t*)    0x8039F114)
#define z64_capacity                    (*(z64_capacity_t*)     0x800F8CCC)
#define z64_change_scene                (*(uint32_t*)           0x801DB09C)
#define z64_has_minimap                 (*(uint16_t*)           0x8018884C) // 0x8011B9B3, 8017643C, 8018884C
#define z64_dungeon_scene               (*(uint16_t*)           0x801D8BEA)
#define z64_scene                       (*(uint16_t*)           0x801C8544)
#define z64_camera_view                 (*(uint8_t*)            0x801DB0CD)
#define z64_mask_equipped               (*(uint8_t*)            0x801DAB7F)
#define z64_throwing_nut                (*(uint8_t*)            0x80124696)
#define z64_triswipe                    (*(uint8_t*)            0x8011B9ED)
#define z64_x_axis_input                (*(int8_t*)             0x801C84C8)
#define z64_y_axis_input                (*(int8_t*)             0x801C84C9)
#define z64_button_input                (*(int16_t*)            0x801C84C0) // 801C84B4, 801C84BA, 801C84C6
#define z64_link_animation_parameter    (*(uint16_t*)           0x801DABF0)
#define z64_link_a_action               (*(uint16_t*)           0x801DAA90)
#define z64_idle_camera_counter         (*(uint8_t*)            0x801C86CF)
#define z64_inventory_editor_index      (*(uint8_t*)            0x8039EA59)
#define z64_damage_taken_modifier_1     (*(uint32_t*)           0x8038E5D0)
#define z64_damage_taken_modifier_2     (*(uint32_t*)           0x8038E5D8)
#define z64_damage_taken_modifier_3     (*(uint16_t*)           0x8038E5EA)
#define z64_textbox                     (*(uint16_t*)           0x801D8870)

/* DRAM addresses & data for HUD */
#define z64_b_button_label_x            (*(uint16_t*)           0x801C7C3A)
#define z64_b_button_label_y            (*(uint16_t*)           0x801C7C3E)
#define z64_c_left_x_set_item           (*(uint16_t*)           0x8039EAF8)
#define z64_c_left_y_set_item           (*(uint16_t*)           0x8039EB00)
#define z64_c_down_x_set_item           (*(uint16_t*)           0x8039EAFA)
#define z64_c_down_y_set_item           (*(uint16_t*)           0x8039EB02)
#define z64_c_right_x_set_item          (*(uint16_t*)           0x8039EAFC)
#define z64_c_right_y_set_item          (*(uint16_t*)           0x8039EB04)

/* DRAM addresses & data for Lens of Truth on D-Pad */
#define z64_dpad_lens_1                 (*(uint16_t*)           0x80072D40)
#define z64_dpad_lens_2                 (*(uint16_t*)           0x80072D4C)
#define z64_dpad_lens_3                 (*(uint16_t*)           0x80072D58)

/* DRAM addresses & data for FPS */
#define fps_limit                       (*(uint8_t*)            0x801C6FA1)
#define control_link                    (*(uint16_t*)           0x801DAADE)

/* DRAM addresses & data for Medallion Abilities */
#define z64_tunic_color                 (*(uint8_t*)            0x801DAB6C)
#define z64_move_speed                  (*(uint16_t*)           0x801DB258)
#define z64_max_move_speed              (*(uint16_t*)           0x801DB2A0)
#define z64_damage_frames               (*(uint8_t*)            0x801DB498)
#define z64_sword_damage_1              (*(uint8_t*)            0x801DAF1E)
#define z64_sword_damage_2              (*(uint8_t*)            0x801DAF9E)
#define z64_inner_red_trail_r           (*(uint8_t*)            0x80273794)
#define z64_inner_red_trail_g           (*(uint8_t*)            0x80273795)
#define z64_inner_red_trail_b           (*(uint8_t*)            0x80273796)
#define z64_outer_red_trail_r           (*(uint8_t*)            0x802738B4)
#define z64_outer_red_trail_g           (*(uint8_t*)            0x802738B5)
#define z64_outer_red_trail_b           (*(uint8_t*)            0x802738B6)

/* Availability */
#define HAS_MAGIC                       (z64_file.magic_acquired && z64_file.magic_capacity_set)
#define CAN_CONTROL_LINK                (z64_game.pause_ctxt.state == 0 && (uint32_t)z64_ctxt.state_dtor == z64_state_ovl_tab[3].vram_dtor && z64_file.game_mode == 0 && (z64_event_state_1 & 0x20) == 0)
#define IS_PAUSE_SCREEN_CURSOR          (z64_game.pause_ctxt.state == 6 && z64_game.pause_ctxt.unk_02_[1] == 0 && z64_game.pause_ctxt.cursor_pos != 0xA && z64_game.pause_ctxt.cursor_pos != 0xB)
#define TYCOON_WALLET                   (z64_file.event_chk_inf[13] & (1 << 13) )

/* D-Pad & Controls Availability */
#define BLOCK_DPAD                      (0x00000001 | 0x00000002 | 0x00000080 | 0x00000400 | 0x10000000 | 0x20000000)
#define CAN_USE_DPAD                    ( (z64_link.state_flags_1 & BLOCK_DPAD) == 0 && (uint32_t)z64_ctxt.state_dtor == z64_state_ovl_tab[3].vram_dtor && z64_file.game_mode == 0 && (z64_event_state_1 & 0x20) == 0)
#define CAN_DRAW_HUD                    ( ( (uint32_t)z64_ctxt.state_dtor==z64_state_ovl_tab[3].vram_dtor) && (z64_file.game_mode == 0) && ( (z64_event_state_1 & 0x20) == 0) )
#define IS_SEMI_ALPHA                   (z64_game.pause_ctxt.state == 0 && alpha >= 0x46)

/* D-Pad Usability for Items */
#define BLOCK_ITEMS                     (0x00800000 | 0x00000800 | 0x00200000 | 0x08000000)
#define CAN_USE_OCARINA                 (z64_game.pause_ctxt.state == 0 && (z64_file.items[Z64_SLOT_OCARINA]     == Z64_ITEM_FAIRY_OCARINA || z64_file.items[Z64_SLOT_OCARINA]     == Z64_ITEM_OCARINA_OF_TIME) && !z64_game.restriction_flags.ocarina     && ((z64_link.state_flags_1 & BLOCK_ITEMS) == 0))
#define CAN_USE_CHILD_TRADE             (z64_game.pause_ctxt.state == 0 && (z64_file.items[Z64_SLOT_CHILD_TRADE] >= Z64_ITEM_WEIRD_EGG     && z64_file.items[Z64_SLOT_CHILD_TRADE] <= Z64_ITEM_MASK_OF_TRUTH)   && !z64_game.restriction_flags.trade_items && ((z64_link.state_flags_1 & BLOCK_ITEMS) == 0))
#define CAN_USE_ADULT_TRADE             (z64_game.pause_ctxt.state == 0 && (z64_file.items[Z64_SLOT_ADULT_TRADE] >= Z64_ITEM_POCKET_EGG    && z64_file.items[Z64_SLOT_ADULT_TRADE] <= Z64_ITEM_CLAIM_CHECK)     && !z64_game.restriction_flags.trade_items && ((z64_link.state_flags_1 & BLOCK_ITEMS) == 0))
#define CAN_USE_ITEMS                   (z64_game.pause_ctxt.state == 0 && !z64_game.restriction_flags.all && ( (z64_link.state_flags_1 & BLOCK_ITEMS) == 0) )
#define CAN_USE_LENS                    (z64_game.pause_ctxt.state == 0 && (!z64_game.restriction_flags.all || z64_game.scene_index == 0x0010) && ( (z64_link.state_flags_1 & BLOCK_ITEMS) == 0) )
#define CAN_USE_FARORES_WIND            (z64_game.pause_ctxt.state == 0 && !z64_game.restriction_flags.farores_wind && ( (z64_link.state_flags_1 & BLOCK_ITEMS) == 0) )

/* D-Pad SRAM locations */
#define DPAD_ADULT_UP                   (z64_file.ammo[0x04])
#define DPAD_CHILD_UP                   (z64_file.ammo[0x05])
#define DPAD_ADULT_RIGHT                (z64_file.ammo[0x07])
#define DPAD_CHILD_RIGHT                (z64_file.ammo[0x09])
#define DPAD_ADULT_DOWN                 (z64_file.ammo[0x0A])
#define DPAD_CHILD_DOWN                 (z64_file.ammo[0x0B])
#define DPAD_ADULT_LEFT                 (z64_file.ammo[0x0C])
#define DPAD_CHILD_LEFT                 (z64_file.ammo[0x0D])

/* D-Pad Button Mappings */
#define DPAD_ADULT_SET1_UP              ( (DPAD_ADULT_UP    >> 4) & 0xF)
#define DPAD_ADULT_SET2_UP              (DPAD_ADULT_UP    & 0xF)
#define DPAD_CHILD_SET1_UP              ( (DPAD_CHILD_UP    >> 4) & 0xF)
#define DPAD_CHILD_SET2_UP              (DPAD_CHILD_UP    & 0xF)
#define DPAD_ADULT_SET1_RIGHT           ( (DPAD_ADULT_RIGHT >> 4) & 0xF)
#define DPAD_ADULT_SET2_RIGHT           (DPAD_ADULT_RIGHT & 0xF)
#define DPAD_CHILD_SET1_RIGHT           ( (DPAD_CHILD_RIGHT >> 4) & 0xF)
#define DPAD_CHILD_SET2_RIGHT           (DPAD_CHILD_RIGHT & 0xF)
#define DPAD_ADULT_SET1_DOWN            ( (DPAD_ADULT_DOWN  >> 4) & 0xF)
#define DPAD_ADULT_SET2_DOWN            (DPAD_ADULT_DOWN  & 0xF)
#define DPAD_CHILD_SET1_DOWN            ( (DPAD_CHILD_DOWN  >> 4) & 0xF)
#define DPAD_CHILD_SET2_DOWN            (DPAD_CHILD_DOWN  & 0xF)
#define DPAD_ADULT_SET1_LEFT            ( (DPAD_ADULT_LEFT  >> 4) & 0xF)
#define DPAD_ADULT_SET2_LEFT            (DPAD_ADULT_LEFT  & 0xF)
#define DPAD_CHILD_SET1_LEFT            ( (DPAD_CHILD_LEFT  >> 4) & 0xF)
#define DPAD_CHILD_SET2_LEFT            (DPAD_CHILD_LEFT  & 0xF)

/* Extra saving for Redux (8011B4C8) */

#define DPAD_INIT_SETUP                 ( (z64_file.inf_table[0x15] & 0x0001) >> 0)
#define DOWNGRADE_GIANTS_KNIFE          ( (z64_file.inf_table[0x15] & 0x0002) >> 1)
#define DOWNGRADE_OCARINA               ( (z64_file.inf_table[0x15] & 0x0004) >> 2)
#define DOWNGRADE_HOOKSHOT              ( (z64_file.inf_table[0x15] & 0x0008) >> 3)

#define SAVE_30_FPS                     ( (z64_file.inf_table[0x15] & 0x0010) >> 4)
#define SAVE_ARROW_TOGGLE               ( (z64_file.inf_table[0x15] & 0x0020) >> 5)
#define SAVE_SHOW_HEALTH                ( (z64_file.inf_table[0x15] & 0x0040) >> 6)
#define SAVE_CHEST_CONTENTS             ( (z64_file.inf_table[0x15] & 0x0080) >> 7)
#define SAVE_INVERSE_AIM                ( (z64_file.inf_table[0x15] & 0x0100) >> 8)
#define SAVE_NO_IDLE_CAMERA             ( (z64_file.inf_table[0x15] & 0x0200) >> 9)
#define SAVE_KEEP_MASK                  ( (z64_file.inf_table[0x15] & 0x0400) >> 10)
#define SAVE_TRISWIPE                   ( (z64_file.inf_table[0x15] & 0x0800) >> 11)
#define SAVE_UNEQUIP_ITEM               ( (z64_file.inf_table[0x15] & 0x1000) >> 12)
#define SAVE_UNEQUIP_GEAR               ( (z64_file.inf_table[0x15] & 0x2000) >> 13)
#define SAVE_ITEM_ON_B                  ( (z64_file.inf_table[0x15] & 0x4000) >> 14)
#define SAVE_DOWNGRADE_ITEM             ( (z64_file.inf_table[0x15] & 0x8000) >> 15)
#define SAVE_CROUCH_STAB_FIX            ( (z64_file.inf_table[0x14] & 0x0100) >> 8)
#define SAVE_WEAKER_SWORDS              ( (z64_file.inf_table[0x14] & 0x0200) >> 9)
#define SAVE_EXTRA_ABILITIES            ( (z64_file.inf_table[0x14] & 0x0400) >> 10)
#define SAVE_LEVITATION                 ( (z64_file.inf_table[0x14] & 0x0800) >> 11)
#define SAVE_INFINITE_HP                ( (z64_file.inf_table[0x14] & 0x1000) >> 12)
#define SAVE_INFINITE_MP                ( (z64_file.inf_table[0x14] & 0x2000) >> 13)
#define SAVE_INFINITE_RUPEES            ( (z64_file.inf_table[0x14] & 0x4000) >> 14)
#define SAVE_INFINITE_AMMO              ( (z64_file.inf_table[0x14] & 0x8000) >> 15)

#define SAVE_DPAD                       ( (z64_file.inf_table[0x1B] & 0x0003) >> 0)  // Options: 2
#define SAVE_SHOW_DPAD                  ( (z64_file.inf_table[0x1B] & 0x000C) >> 2)  // Options: 3
#define SAVE_HIDE_HUD                   ( (z64_file.inf_table[0x1B] & 0x0070) >> 4)  // Options: 4
#define SAVE_HUD_LAYOUT                 ( (z64_file.inf_table[0x1B] & 0x0380) >> 7)  // Options: 6
#define SAVE_A_BUTTON_SCALE             ( (z64_file.inf_table[0x1B] & 0x0C00) >> 10) // Options: 2
#define SAVE_B_BUTTON_SCALE             ( (z64_file.inf_table[0x1B] & 0x7000) >> 12) // Options: 7
#define SAVE_RANDOM_ENEMIES             ( (z64_file.inf_table[0x1B] & 0x8000) >> 15) // Options: 1
#define SAVE_C_LEFT_BUTTON_SCALE        ( (z64_file.inf_table[0x1C] & 0x0007) >> 0)  // Options: 7
#define SAVE_C_DOWN_BUTTON_SCALE        ( (z64_file.inf_table[0x1C] & 0x0070) >> 4)  // Options: 7
#define SAVE_C_RIGHT_BUTTON_SCALE       ( (z64_file.inf_table[0x1C] & 0x0700) >> 8)  // Options: 7
#define SAVE_DAMAGE_TAKEN               ( (z64_file.inf_table[0x1C] & 0x7000) >> 12) // Options: 7
#define SAVE_RUPEE_DRAIN                ( (z64_file.inf_table[0x18] & 0x000F) >> 0)  // Options: 15
#define SAVE_FOG                        ( (z64_file.inf_table[0x18] & 0x00F0) >> 4)  // Options: 15

/* Keeping track of values */
#define A_BUTTON_SCALE                  (*(uint16_t*)           0x80074F76)
#define A_BUTTON_TEXT_SCALE             (*(uint16_t*)           0x8007650E)
#define MAX_SWORD_HEALTH                (*(uint8_t*)            0x8038E1A3)
#define SWORD_HEALTH                    (*(uint8_t*)            0x8011B4F8) // 0x30

/* Extra Ability Tunic Colors */
#define TUNIC_KOKIRI_R                  (*(uint8_t*)            0x800F7AD8)
#define TUNIC_KOKIRI_G                  (*(uint8_t*)            0x800F7AD9)
#define TUNIC_KOKIRI_B                  (*(uint8_t*)            0x800F7ADA)
#define TUNIC_GORON_R                   (*(uint8_t*)            0x800F7ADB)
#define TUNIC_GORON_G                   (*(uint8_t*)            0x800F7ADC)
#define TUNIC_GORON_B                   (*(uint8_t*)            0x800F7ADD)
#define TUNIC_ZORA_R                    (*(uint8_t*)            0x800F7ADE)
#define TUNIC_ZORA_G                    (*(uint8_t*)            0x800F7ADF)
#define TUNIC_ZORA_B                    (*(uint8_t*)            0x800F7AE0)
#define TUNIC_UNUSED_R                  (*(uint8_t*)            0x800F7AE1)
#define TUNIC_UNUSED_G                  (*(uint8_t*)            0x800F7AE2)
#define TUNIC_UNUSED_B                  (*(uint8_t*)            0x800F7AE3)

#define MP_FIRE_ARROW                   (*(uint8_t*)            0x803AAC00)
#define MP_ICE_ARROW                    (*(uint8_t*)            0x803AAC01)
#define MP_LIGHT_ARROW                  (*(uint8_t*)            0x803AAC02)

#endif