#include <raylib.h>
#include "linear.hpp"

int main()
{
	int constexpr screen_width{ 800 };
	int constexpr screen_height{ 600 };
	char const * const window_title = "Hello, World!";

	InitWindow(screen_width, screen_height, window_title);

	while (!WindowShouldClose()) {
		
		BeginDrawing();
		{
			ClearBackground(BLACK);
		}
		EndDrawing();
	}
}
