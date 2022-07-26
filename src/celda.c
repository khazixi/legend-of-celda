/* libc */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* raylib */
#include <raylib.h>

void _(){}
int main(void){
	SetTraceLogCallback(_);			// do not log!
	InitWindow(800, 600, "Legend of Celda");

	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(WHITE);
		EndDrawing();
	}
	CloseWindow();
}