#include <stdio.h>
//#include <SFML/Window/Keyboard.h>             
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
//#include <SFML/Graphics/RenderWindow.h>
//#include <SFML/Graphics/Texture.h>        
//#include <SFML/Graphics/Sprite.h>
//#include <SFML/System.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#ifndef STRUCT_H_
#define STRUCT_H_

struct s_allin
{
	sfRenderWindow *window;
	sfVideoMode video_mode;
	sfFont *font;
        sfText *text;
	sfEvent event;
	sfTexture *textbird;
	sfTexture *textback;
	sfTexture *textscore;
	sfTexture *textsonic;
	sfTexture *texteggman;
	sfTexture *textring;
	sfTexture *textheart;
	sfTexture *textcursor;
	sfSprite *bird;
	sfSprite *sonic;
	sfSprite *background;
	sfSprite *score;
	sfSprite *eggman;
	sfSprite *ring;
	sfSprite *heart;
	sfSprite *cursor;
	sfVector2f vector;
	sfVector2f vector2;
	sfVector2f vector3;
	sfVector2f vectorofbird;
	sfVector2f vectorofscore;
	sfVector2f vectorofsonic;
	sfVector2f vectorofring;
	sfVector2f vectorofheart;
	sfVector2f vectorofcursor;
	sfVector2i vectormouse;
	sfVector2f vectorsizeofsonic; 
	sfVector2f vectorsizeheart;
	sfIntRect rect;
	sfIntRect rect2;
	sfIntRect rect3;
	sfIntRect rectring;
	sfIntRect rectheart;
	int y;
	int z;
	int b;
	sfSoundBuffer *buffer;
	sfSound *sound;
	sfTime temps;
	float seconds;
	float seconds2;
       	sfClock *clock;
	sfKeyEvent key;
};
	
#endif /* STRUCT_H_ */
