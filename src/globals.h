#ifndef GLOBALS_H
#define GLOBALS_H

#include <inttypes.h> 	/* Yucky */

// Not the ideal position
typedef union Position {
	uint8_t pos[2];
	struct {
		uint8_t x;
		uint8_t y;
	};
} position_t;

typedef struct Globals {
	uint8_t tile_side;	// Tiles in pixels
	position_t map_section;	// Section of the map the player is on
} globals_t;

#endif // GLOBALS_H
