#include "gfx.h"

#include "util.h"
#include "z64.h"

extern uint8_t FONT_TEXTURE[];
extern uint8_t DPAD_TEXTURE[];
extern uint8_t TRIFORCE_ICON_TEXTURE[];
extern uint8_t L_BUTTON_PAUSE_SCREEN_TEXTURE[];
extern uint8_t CFG_WS;

z64_disp_buf_t redux_overlay_db __attribute__ ((aligned (16)));

typedef struct {
    Gfx redux_overlay[0xF00];
} ReduxGFXPool;

ReduxGFXPool reduxGfxPools[2];
uint8_t reduxGfxPoolIndex;

Gfx setup_db[] = {
    gsDPPipeSync(),
    gsSPLoadGeometryMode(0),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, Z64_SCREEN_WIDTH, Z64_SCREEN_HEIGHT),
    gsDPSetOtherMode(G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TD_CLAMP | G_TP_NONE | G_TL_TILE | G_TT_NONE | G_PM_NPRIMITIVE | G_CYC_1CYCLE | G_TF_BILERP, G_AC_NONE | G_ZS_PRIM | G_RM_XLU_SURF | G_RM_XLU_SURF2),
    gsSPEndDisplayList()
};

Gfx empty_dlist[] = { gsSPEndDisplayList() };

sprite_t stones_sprite = {
    NULL, 16, 16, 3,
    G_IM_FMT_RGBA, G_IM_SIZ_32b, 4
};

sprite_t medals_sprite = {
    NULL, 16, 16, 6,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t items_sprite = {
    NULL, 32, 32, 90,
    G_IM_FMT_RGBA, G_IM_SIZ_32b, 4
};

sprite_t quest_items_sprite = {
    NULL, 24, 24, 20,
    G_IM_FMT_RGBA, G_IM_SIZ_32b, 4
};

sprite_t font_sprite = {
    NULL, 8, 14, 108,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t dpad_sprite = {
    NULL, 32, 32, 1,
    G_IM_FMT_RGBA, G_IM_SIZ_32b, 4
};  

sprite_t triforce_sprite = {
    NULL, 16, 16, 16,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t l_button_pause_screen_sprite = {
    NULL, 24, 32, 1,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t song_note_sprite = {
    NULL, 16, 24, 1,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t key_rupee_clock_sprite = {
    NULL, 16, 16, 3,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t item_digit_sprite = {
    NULL, 8, 8, 10,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t linkhead_skull_sprite = {
    NULL, 16, 16, 2,
    G_IM_FMT_RGBA, G_IM_SIZ_16b, 2
};

sprite_t heart_sprite = {
    NULL, 16, 16, 10,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t button_sprite = {
    NULL, 32, 32, 5,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t counter_digit_sprite = {
    NULL, 8, 16, 10,
    G_IM_FMT_I, G_IM_SIZ_8b, 1
};

sprite_t ammo_digit_sprite = {
    NULL, 8, 8, 10,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t subscreen_sprite = {
    NULL, 80, 32, 67,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t item_name_sprite = {
    NULL, 128, 16, 9,
    G_IM_FMT_IA, G_IM_SIZ_4b, 1
};

sprite_t title_sprite = {
    NULL, 128, 16, 10,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t title_text_sprite = {
    NULL, 128, 16, 9,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t name_panel_sprite = {
    NULL, 72, 24, 2,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t magic_meter_end = {
    NULL, 8, 16, 1,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t magic_meter_mid = {
    NULL, 24, 16, 1,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

sprite_t magic_meter_fill = {
    NULL, 8, 8, 1,
    G_IM_FMT_IA, G_IM_SIZ_8b, 1
};

int sprite_bytes_per_tile(sprite_t *sprite) {
    return sprite->tile_w * sprite->tile_h * sprite->bytes_per_texel;
}

int sprite_bytes(sprite_t *sprite) {
    return sprite->tile_count * sprite_bytes_per_tile(sprite);
}

void sprite_load(z64_disp_buf_t *db, sprite_t *sprite, int start_tile, int tile_count) {
    int width  = sprite->tile_w;
    int height = sprite->tile_h * tile_count;
    gDPLoadTextureTile(db->p++, sprite->buf + (start_tile * sprite_bytes_per_tile(sprite)), sprite->im_fmt, sprite->im_siz, width, height, 0, 0, width - 1, height - 1, 0, G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void sprite_draw(z64_disp_buf_t *db, sprite_t *sprite, int tile_index, int left, int top, int width, int height) {
    int width_factor  = (1<<10) * sprite->tile_w / width;
    int height_factor = (1<<10) * sprite->tile_h / height;
    gSPTextureRectangle(db->p++, left<<2, top<<2, (left + width)<<2, (top + height)<<2, 0, 0, (tile_index * sprite->tile_h)<<5, width_factor, height_factor);
}

void sprite_load_and_draw(z64_disp_buf_t *db, sprite_t *sprite, int index, int16_t x, int16_t y, uint8_t w, uint8_t h) {
    sprite_load(db, sprite, index, 1);
    sprite_draw(db, sprite, 0, x, y, w, h);
}

void sprite_texture(z64_disp_buf_t* db, sprite_t* sprite, int tile_index, int16_t left, int16_t top, int16_t width, int16_t height) {
    int width_factor  = (1<<10) * sprite->tile_w / width;
    int height_factor = (1<<10) * sprite->tile_h / height;
    gDPLoadTextureBlock(db->p++, ((uint8_t*)(sprite->buf)) + (tile_index * sprite_bytes_per_tile(sprite)), sprite->im_fmt, sprite->im_siz, sprite->tile_w, sprite->tile_h, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(db->p++, left * 4, top * 4, (left + width) * 4, (top + height) * 4, G_TX_RENDERTILE, 0,0,width_factor, height_factor);
}

void sprite_texture_4b(z64_disp_buf_t *db, sprite_t *sprite, int tile_index, int16_t left, int16_t top, int16_t width, int16_t height) {
    if (sprite->im_siz != G_IM_SIZ_4b)
        return;

    int width_factor  = (1<<10) * sprite->tile_w / width;
    int height_factor = (1<<10) * sprite->tile_h / height;

    gDPPipeSync(db->p++);
    gDPSetCombineLERP(db->p++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetEnvColor(db->p++, 0, 0, 0, 255);
    gDPLoadTextureBlock_4b(db->p++, ((uint8_t*)(sprite->buf)) + tile_index * sprite_bytes_per_tile(sprite), sprite->im_fmt, sprite->tile_w, sprite->tile_h, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(db->p++, left * 4, top * 4, (left + width) * 4, (top + height) * 4, G_TX_RENDERTILE, 0, 0, width_factor, height_factor);
}

void display_buffer_init() {
    reduxGfxPoolIndex = 0;
}

void display_buffer_reset() {
    ReduxGFXPool* pool = &reduxGfxPools[reduxGfxPoolIndex & 1];
    redux_overlay_db.size = sizeof(pool->redux_overlay);
    redux_overlay_db.buf = &pool->redux_overlay[0];
    redux_overlay_db.p = &redux_overlay_db.buf[0];
}

void close_display_buffer() {
    //char error_msg[256];

    OPEN_DISPS(z64_ctxt.gfx);

    /*if (((int) redux_overlay_db.p - (int) redux_overlay_db.buf) > redux_overlay_db.size) {
        sprintf(error_msg, "size = %x\nmax = %x\np = %p\nbuf = %p\nd = %p", ((int) redux_overlay_db.p - (int) redux_overlay_db.buf), redux_overlay_db.size, redux_overlay_db.p, redux_overlay_db.buf, redux_overlay_db.d);
        Fault_AddHungupAndCrashImpl("Display buffer exceeded!", error_msg);
    }*/

    gSPEndDisplayList(redux_overlay_db.p++);
    gSPDisplayList(OVERLAY_DISP++, redux_overlay_db.buf);

    CLOSE_DISPS();
    reduxGfxPoolIndex++;
}

void gfx_init() {
    display_buffer_init();
    
    if (CFG_WS)
        setup_db[2] = gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, Z64_SCREEN_WIDTH + 104, Z64_SCREEN_HEIGHT);
    
    file_t title_static = {
        NULL, z64_file_select_static_vaddr, z64_file_select_static_vsize
    };
    file_init(&title_static);

    file_t icon_item_24_static = {
        NULL, z64_icon_item_24_static_vaddr, z64_icon_item_24_static_vsize
    };
    file_init(&icon_item_24_static);

    file_t icon_item_static = {
        NULL, z64_icon_item_static_vaddr, z64_icon_item_static_vsize
    };
    file_init(&icon_item_static);
    
    file_t parameter_static = {
        NULL, z64_parameter_static_vaddr, z64_parameter_static_vsize
    };
    file_init(&parameter_static);

    file_t icon_item_dungeon_static = {
        NULL, z64_icon_item_dungeon_static_vaddr, z64_icon_item_dungeon_static_vsize
    };
    file_init(&icon_item_dungeon_static);
    
    file_t subscreen_static = {
        NULL, 0x008193C0, 0x29E00
    };
    file_init(&subscreen_static);
    
    file_t item_name_static = {
        NULL, 0x00880000, 0x03D800
    };
    file_init(&item_name_static);
    
    stones_sprite.buf                = title_static.buf             + 0x2A300;
    medals_sprite.buf                = title_static.buf             + 0x2980;
    items_sprite.buf                 = icon_item_static.buf;
    quest_items_sprite.buf           = icon_item_24_static.buf;
    dpad_sprite.buf                  = DPAD_TEXTURE;
    triforce_sprite.buf              = TRIFORCE_ICON_TEXTURE;
    l_button_pause_screen_sprite.buf = L_BUTTON_PAUSE_SCREEN_TEXTURE;
    song_note_sprite.buf             = icon_item_static.buf         + 0x88040;
    key_rupee_clock_sprite.buf       = parameter_static.buf         + 0x1E00;
    item_digit_sprite.buf            = parameter_static.buf         + 0x35C0;
    linkhead_skull_sprite.buf        = icon_item_dungeon_static.buf + 0x1980;
    heart_sprite.buf                 = parameter_static.buf;
    button_sprite.buf                = parameter_static.buf         + 0xA00;
    counter_digit_sprite.buf         = parameter_static.buf         + 0x3040;
    ammo_digit_sprite.buf            = parameter_static.buf         + 0x35C0;
    subscreen_sprite.buf             = subscreen_static.buf;
    item_name_sprite.buf             = item_name_static.buf         + 0x38400;
    title_sprite.buf                 = title_static.buf             + 0x2D700;
    title_text_sprite.buf            = title_static.buf             + 0x2DF00;
    name_panel_sprite.buf            = icon_item_static.buf         + 0x867C0;
    magic_meter_end.buf              = parameter_static.buf         + 0x38C0;
    magic_meter_mid.buf              = parameter_static.buf         + 0x3940;
    magic_meter_fill.buf             = parameter_static.buf         + 0x3AC0;
    
    int font_bytes = sprite_bytes(&font_sprite);
    font_sprite.buf = heap_alloc(font_bytes);
    for (int i = 0; i < font_bytes / 2; i++) {
        font_sprite.buf[2*i] = (FONT_TEXTURE[i] >> 4) | 0xF0;
        font_sprite.buf[2*i + 1] = FONT_TEXTURE[i] | 0xF0;
    }
    
}
