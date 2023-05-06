#ifndef BOSS_RUSH_H
#define BOSS_RUSH_H

#include "z64.h"
#include "z64_extended.h"

#include <string.h>
#include <stdio.h>

#define z64_playsfx						((playsfx_t)			0x800C806C)

void run_boss_rush();
void heal_player();
void reset_progress();
void set_progress();

/* Warp SRAM locations */
//#define LINKS_HOUSE						(*(uint32_t*)			0x80382EC0)

/*
#define LINKS_HOUSE_1					(*(uint32_t*)			0x800FA4D4)
#define LINKS_HOUSE_2					(*(uint32_t*)			0x800FA4D8)
#define LINKS_HOUSE_3					(*(uint32_t*)			0x800FA4DC)
#define LINKS_HOUSE_4					(*(uint32_t*)			0x800FA4E0)

#define GOHMA							(*(uint32_t*)			0x800FACCC)
#define GOHMA_1							(*(uint32_t*)			0x800FADEC)
#define GOHMA_2							(*(uint32_t*)			0x800FADF0)
#define GOHMA_3							(*(uint32_t*)			0x800FADF4)
#define GOHMA_4							(*(uint32_t*)			0x800FADF8)

#define KING_DODONGO					(*(uint32_t*)			0x800FACBC)
#define KING_DODONGO_1					(*(uint32_t*)			0x800FAE78)
#define KING_DODONGO_2					(*(uint32_t*)			0x800FAE7C)
#define KING_DODONGO_3					(*(uint32_t*)			0x800FAE80)
#define KING_DODONGO_4					(*(uint32_t*)			0x800FAE84)

#define BARINADE						(*(uint32_t*)			0x800FA894)
#define BARINADE_1						(*(uint32_t*)			0x800FA0C8)
#define BARINADE_2						(*(uint32_t*)			0x800FA0CC)
#define BARINADE_3						(*(uint32_t*)			0x800FA0D0)
#define BARINADE_4						(*(uint32_t*)			0x800FA0D4)

#define PHANTOM_GANON					(*(uint32_t*)			0x800F9CC0)
#define PHANTOM_GANON_1					(*(uint32_t*)			0x800FB430)
#define PHANTOM_GANON_2					(*(uint32_t*)			0x800FB434)
#define PHANTOM_GANON_3					(*(uint32_t*)			0x800FB438)
#define PHANTOM_GANON_4					(*(uint32_t*)			0x800FB43C)

#define VOLVAGIA						(*(uint32_t*)			0x800FA8A4)
#define VOLVAGIA_1						(*(uint32_t*)			0x800FB220)
#define VOLVAGIA_2						(*(uint32_t*)			0x800FB224)
#define VOLVAGIA_3						(*(uint32_t*)			0x800FB228)
#define VOLVAGIA_4						(*(uint32_t*)			0x800FB22C)

#define MORPHA							(*(uint32_t*)			0x800FACEC)

#define TEMPLE_OF_TIME					(*(uint32_t*)			0x800F9DDC)
#define TEMPLE_OF_TIME_CHILD_1			(*(uint32_t*)			0x800FA254)
#define TEMPLE_OF_TIME_CHILD_2			(*(uint32_t*)			0x800FA258)
#define TEMPLE_OF_TIME_ADULT_1			(*(uint32_t*)			0x800FAE60)
#define TEMPLE_OF_TIME_ADULT_2			(*(uint32_t*)			0x800FAE64)
*/

#endif
