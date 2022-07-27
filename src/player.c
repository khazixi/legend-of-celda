/* libc */
#include <stdbool.h>

/* raylib */
#include <raylib.h>

/* header file */
#include "player.h"
#include "globals.h"

typedef enum direction {
	NORTH,
	EAST,
	WEST,
	SOUTH,
} direction_t;

typedef struct Player {
	position_t area_pos;
	struct Image model;
	// Inventory
	// A weapon
	// B weapon
} player_t;

typedef struct Tile {
	uint8_t hex;		// Image should be deduced based on hex
	bool passable;		// Determines if the space is passable
	bool rendered;		// Determines if the space is to be rendered by raylib
	struct Image img;	// Image to be drawn by raylib
} tile_t;

typedef struct Area {
	uint8_t length;			// length = 11
	uint8_t width;			// width = 16
	tile_t tiles[11][16];
} area_t;

typedef struct Map {
	area_t board[8][16];
} map_t;

void move_player(player_t * player, direction_t direction, globals_t global) {
	switch (direction) {
		case NORTH:
			player->area_pos.y += global.tile_side;
			break;
		case EAST:
			player->area_pos.x += global.tile_side;
			break;
		case WEST:
			player->area_pos.x -= global.tile_side;
			break;
		case SOUTH:
			player->area_pos.y -= global.tile_side;
			break;
	}
}

// Impliment Event Tiles for changing position
void change_map_section(player_t * player, direction_t direction, globals_t global) {
	switch (direction) {
		case NORTH:
			global.map_section.y += 1;
			player->area_pos.y = 0;
			break;
		case EAST:
			global.map_section.x += 1;
			player->area_pos.x += 0;
			break;
		case WEST:
			global.map_section.x -= 1;
			player->area_pos.x = 15;
			break;
		case SOUTH:
			global.map_section.y -= 1;
			player->area_pos.y = 10;
			break;
	}
}
