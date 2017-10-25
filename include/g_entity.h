#include "gf2d_sprite.h"
#include "gf2d_vector.h"


typedef struct Entity_S
{
	Sprite *obj;
	int health;
	int speed;
	int aceleration;
	int scale;
	Vector2D location;
	int velocity;
	double time;
	int inuse;
	int width;
	int height;
	int type;

}Entity;


void gf2d_entity_free();

void gf2d_entity_spawn();

Entity *gf2d_new();
