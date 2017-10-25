










#include "g_entity.h"
#include <math.h>
#include "gf2d_types.h"

#define entitySize 1024
#define player 0
#define tree 2
#define spider 3
#define bullet 1
#define sword 4
#define rebullet 5
int currentSize = 0;

typedef struct
{
	Entity *EntityList[entitySize];
}EntityManager;

EntityManager entity_manager;


gf2d_entity_init()
{
	int counter = 0;
	for (counter = 0; counter < entitySize; counter++)
	{
		entity_manager.EntityList[counter] = (Entity *)malloc(sizeof(Entity));
		memset(entity_manager.EntityList[counter], 0, sizeof(Entity));
	}

}

int test = 0;


drawEntity(int mx, int my)
{
	int x = 900;
	int y = 450;
	static int r = 0;
		r = rand() % 1200;
	static int q;
	q=rand() % 720;
	Vector4D playercolor = { 73, 223, 168, 200 };
	Vector2D loc = { r, q };
	Vector2D loc2 = { x, y};
	Vector2D loc3 = { 700, 600 };
	Vector2D loc4 = { 900, 150 };
	


	for (int counter = 0; counter < entitySize; counter++)
	{


		if (entity_manager.EntityList[counter]->inuse == 1)
		{

			
			if (entity_manager.EntityList[counter]->type == player) {
				gf2d_sprite_draw(
					entity_manager.EntityList[counter]->obj,
					entity_manager.EntityList[counter]->location,
					NULL,
					NULL,
					NULL,
					NULL,
					&playercolor,
					2);
				entity_manager.EntityList[player]->location.y += my*gf2d_delta() / 1000.0f;
				entity_manager.EntityList[player]->location.x += mx*gf2d_delta() / 1000.0f;
				if (entity_manager.EntityList[player]->location.y > 700)
				{
					entity_manager.EntityList[player]->location.y = 700;
				}
				if (entity_manager.EntityList[player]->location.y < 0)
				{
					entity_manager.EntityList[player]->location.y = 0;
				}
				if (entity_manager.EntityList[player]->location.x > 1180)
				{
					entity_manager.EntityList[player]->location.x = 1180;
				}
				if (entity_manager.EntityList[player]->location.x < 0)
				{
					entity_manager.EntityList[player]->location.x = 0;
				}
			}
			if (entity_manager.EntityList[counter]->type == bullet)
			{
				gf2d_sprite_draw(
					entity_manager.EntityList[counter]->obj,
					loc,
					NULL,
					NULL,
					NULL,
					NULL,
					&playercolor,
					2);
			}
			if (entity_manager.EntityList[counter]->type == spider)
			{
				gf2d_sprite_draw(
					entity_manager.EntityList[counter]->obj,
					loc,
					NULL,
					NULL,
					NULL,
					NULL,
					&playercolor,
					2);
				
			}
			if (entity_manager.EntityList[counter]->type == tree)
			{
				gf2d_sprite_draw(
					entity_manager.EntityList[counter]->obj,
					loc2,
					NULL,
					NULL,
					NULL,
					NULL,
					&playercolor,
					2);
				loc2.x -= 200 ;
			}
		}
	}
}
updateEnt()
{
	
	int counter = 0;
	for (counter = 0; counter < entitySize; counter++)
	{

		//gf2d_sprite_draw_image(entity_manager.EntityList[counter]->obj, vector2d(200, 300));
	}
}


void gf2d_entity_free()
{
	int counter = 0;
	for (counter; counter < entitySize; counter++)
	{
		entity_manager.EntityList[counter]->inuse = 0;
	}
}




void gf2d_entity_spawn(int type)
{

	

	if (type == player) {
		entity_manager.EntityList[currentSize]->obj = gf2d_sprite_load_all("images/player.png", 25, 29, 5);
		entity_manager.EntityList[currentSize]->location.x = 200;
		entity_manager.EntityList[currentSize]->location.y = 200;
		entity_manager.EntityList[currentSize]->inuse = 1;
		entity_manager.EntityList[currentSize]->health = 4;
		entity_manager.EntityList[currentSize]->scale = 20;
		entity_manager.EntityList[currentSize]->width = 25;
		entity_manager.EntityList[currentSize]->height = 29;
		entity_manager.EntityList[currentSize]->type = player;
		currentSize++;
	}if (type == bullet) {
		entity_manager.EntityList[currentSize]->obj = gf2d_sprite_load_all("images/player.png", 10, 10, 4);
		entity_manager.EntityList[currentSize]->inuse = 1;
		entity_manager.EntityList[currentSize]->health = 1;
		entity_manager.EntityList[currentSize]->scale = 20;
		entity_manager.EntityList[currentSize]->width = 10;
		entity_manager.EntityList[currentSize]->height = 10;
		entity_manager.EntityList[currentSize]->type = bullet;
		currentSize++;
	}
	if (type == tree) {
		entity_manager.EntityList[currentSize]->obj = gf2d_sprite_load_all("images/player.png", 25, 29, 5);
		entity_manager.EntityList[currentSize]->inuse = 1;
		entity_manager.EntityList[currentSize]->health = 3;
		entity_manager.EntityList[currentSize]->scale = 20;
		entity_manager.EntityList[currentSize]->width = 27;
		entity_manager.EntityList[currentSize]->height = 32;
		entity_manager.EntityList[currentSize]->type = tree;
		currentSize++;
	}
	if (type == spider) {
		entity_manager.EntityList[currentSize]->obj = gf2d_sprite_load_all("images/player.png", 25, 29, 5);
		entity_manager.EntityList[currentSize]->inuse = 1;
		entity_manager.EntityList[currentSize]->health = 1;
		entity_manager.EntityList[currentSize]->scale = 20;
		entity_manager.EntityList[currentSize]->width = 25;
		entity_manager.EntityList[currentSize]->height = 29;
		entity_manager.EntityList[currentSize]->type = spider;
		currentSize++;
	}
	if (type == spider) {
		entity_manager.EntityList[currentSize]->obj = gf2d_("images/spider.png", 43, 16, 1);
		entity_manager.EntityList[currentSize]->inuse = 1;
		entity_manager.EntityList[currentSize]->health = 1;
		entity_manager.EntityList[currentSize]->scale = 20;
		entity_manager.EntityList[currentSize]->width = 25;
		entity_manager.EntityList[currentSize]->height = 29;
		entity_manager.EntityList[currentSize]->type = spider;
		currentSize++;
	}
			

			
		
}



void doCollisions()
{
	int i, j;


	for (i = 0; i < currentSize; i++)
	{
		if (entity_manager.EntityList[i]->inuse == 0)
		{



			for (j = 0; j < currentSize; j++)
			{

				if (i == j || entity_manager.EntityList[j]->inuse == 0)
				{
					continue;
				}


				if (collision(entity_manager.EntityList[i]->location.x, entity_manager.EntityList[i]->location.y, entity_manager.EntityList[i]->width, entity_manager.EntityList[i]->height,
					entity_manager.EntityList[j]->location.x, entity_manager.EntityList[j]->location.y, entity_manager.EntityList[j]->width, entity_manager.EntityList[j]->height) == 1)
				{
					entity_manager.EntityList[i]->inuse = 0;
					entity_manager.EntityList[j]->inuse = 0;

				}
			}
		}

	}
}

int collision(int x0, int y0, int w0, int h0, int x2, int y2, int w1, int h1)
{
	int x1 = x0 + w0;
	int y1 = y0 + h0;

	int x3 = x2 + w1;
	int y3 = y2 + h1;

	return !(x1<x2 || x3<x0 || y1<y2 || y3<y0);
}
