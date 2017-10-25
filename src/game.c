#include <SDL.h>
#include "gf2d_graphics.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"
#include "g_entity.h"


int main(int argc, char * argv[])
{
	/*variable declarations*/
	int pause = 0;
	int test = 0;
	int done = 0;
	const Uint8 * keys;
	Sprite *sprite;
	Sprite *enemy;
	Entity *enter, *checker;
	SDL_Event event;
	int mx, my, counter;
	float mf = 0;
	int px = 0;
	int py = 0;
	Sprite *mouse;
	Sprite *bullet, *paus;
	Vector4D mouseColor = { 255,100,255,200 };
	Vector2D bgscale = { 4, 4 };
	int movement = 0;
	gf2d_entity_init(100);
	counter = 0;

	/*program initializtion*/
	init_logger("gf2d.log");
	slog("---==== BEGIN ====---");
	gf2d_graphics_initialize(
		"gf2d",
		1200,
		720,
		1200,
		720,
		vector4d(0, 0, 0, 255),
		0);
	gf2d_graphics_set_frame_delay(16);
	gf2d_sprite_init(1024);
	SDL_ShowCursor(SDL_DISABLE);

	/*demo setup*/
	sprite = gf2d_sprite_load_image("images/backgrounds/testbg.png");
	mouse = gf2d_sprite_load_all("images/pointer.png", 32, 32, 16);
	paus = gf2d_sprite_load_image("images/backgrounds/pause.png");
	/*main game loop*/

	//setup test entity 
	//update entity

	gf2d_entity_spawn(0);
	gf2d_entity_spawn(2);
	gf2d_entity_spawn(3);
	while (!done)
	{
		SDL_PumpEvents();   // update SDL's internal event structures
		
		keys = SDL_GetKeyboardState(NULL); // get the keyboard state for this frame
										   /*update things here*/
		SDL_GetMouseState(&mx, &my);
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_a:  px=-400; break;
			case SDLK_d: px=400; break;
			case SDLK_w:   py=-400; break;
			case SDLK_s:  py=400; break;
			case SDLK_q: if (pause = 0) { pause = 1; } if (pause = 1) {
				pause = 0;
			} break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_a:  px = 0; break;
			case SDLK_d: px = 0; break;
			case SDLK_w:   py = 0; break;
			case SDLK_s:  py = 0; break;
			
			}
			break;
		}
		
		mf += 0.1;
		if (mf >= 16.0)
		{
			mf = 0;
			//gf2d_entity_free();
		}


		gf2d_graphics_clear_screen();// clears drawing buffers
									 // all drawing should happen betweem clear_screen and next_frame
									 //backgrounds drawn first


		while(pause == 1)
		{
			gf2d_sprite_draw(
				paus,
				vector2d(0, 0),
				NULL,
				NULL,
				NULL,
				NULL,
				NULL,
				0);
		}



		gf2d_sprite_draw(
			sprite,
			vector2d(0, 0),
			&bgscale,
			NULL,
			NULL,
			NULL,
			NULL,
			0);

			updateEnt();
			drawEntity(px, py);
			
	
			doCollisions();
		
		//UI elements last
		gf2d_sprite_draw(
			mouse,
			vector2d(mx, my),
			NULL,
			NULL,
			NULL,
			NULL,
			&mouseColor,
			(int)mf);


		
		

		gf2d_grahics_next_frame();// render current draw frame and skip to the next frame

		if (keys[SDL_SCANCODE_ESCAPE])done = 1; // exit condition
		slog("Rendering at %f FPS", gf2d_graphics_get_frames_per_second());


	}
	slog("---==== END ====---");
	return 0;


}
/*eol@eof*/