/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <stdio.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "struct.h"

int my_putstr(char *str);

void move_rect(sfIntRect *rect, int offset, int max_value)
{
	rect -> left = rect -> left + offset;
	if (rect -> left == max_value)
		rect -> left = rect -> left - max_value;
}
		 
void analyse_events(sfEvent event)
{	
	sfMouseButtonEvent  mouse;

        if (event.type == sfEvtMouseButtonPressed) {
		mouse = event.mouseButton;
		printf("\n");
		printf("--------\n");
		printf("x = %d\ny = %d\n", mouse.x, mouse.y);
		printf("--------\n");
		printf("\n");
	}
}

struct s_allin proportions(struct s_allin allin)
{
	allin.clock = sfClock_create();
	srand(time(NULL));
	
	allin.video_mode.width  = 1600;
	allin.video_mode.height = 679;
	allin.video_mode.bitsPerPixel = 32;

	return(allin);
}
struct s_allin create_of_textsprite(struct s_allin allin)
{
	allin.window = sfRenderWindow_create(allin.video_mode,
					     "Fenetre",
					     sfDefaultStyle,
					     NULL);

	allin.textbird = sfTexture_createFromFile("Sprite/tails.png",
						  NULL);
	allin.bird = sfSprite_create();

	allin.textback = sfTexture_createFromFile("Sprite/sonic2.png",
						  NULL);
	allin.background = sfSprite_create();

	allin.buffer = sfSoundBuffer_createFromFile("Sound/music2.ogg");

	allin.textscore = sfTexture_createFromFile("Sprite/score.png",
						   NULL);
	allin.score = sfSprite_create();

	//tallin.exteggman = sfTexture_createFromFile("Sprite/eggman.png",                           // NULL);                                                                                                                                                                       
	//allin.eggman = sfSprite_create();                                                                                                                                               
	allin.textsonic = sfTexture_createFromFile("Sprite/sonic.png",
						   NULL);
	allin.sonic = sfSprite_create();
	
	allin.textring = sfTexture_createFromFile("Sprite/ring.png",
						  NULL);
	allin.ring = sfSprite_create();

	allin.textheart = sfTexture_createFromFile("Sprite/heart.png",
						   NULL);
	allin.heart = sfSprite_create();

	allin.textcursor = sfTexture_createFromFile("Sprite/cursor.png",
						    NULL);
	allin.cursor = sfSprite_create();
	
	allin.sound = sfSound_create();
	sfSound_setBuffer(allin.sound , allin.buffer);

	/*allin.font = sfFont_createFromFile("NiseSegaSonic.TTF");
	  allin.text = sfText_create();
	  sfText_setString(allin.text, "LoL");                                         
	  sfText_setFont(allin.text, allin.font);                                              
	  sfText_setCharacterSize(allin.text, 50);*/
	
		
	sfSound_play(allin.sound);

	return(allin);
}

struct s_allin functionvector(struct s_allin allin)
{
	//allin.vectoreggman.x = 1;                                                           
	//allin.vectoreggman.y = 0;                                                           

	allin.vectorofsonic.x = 745;
	allin.vectorofsonic.y = 432;

	allin.vector.x = 0.4;
	allin.vector.y = 0;

	allin.vector2.x = 0;
	allin.vector2.y = 0;

	//allin.vector3.x = 0;                                                                
	//allin.vector3.y = 0;                                                                

	//allin.vector4.x = 0;                                                                
	//allin.vector4.y = 0;                                                                

	allin.vectorofring.x = 490;
	allin.vectorofring.y = 500;

	allin.vectorofscore.x = 65;
	allin.vectorofscore.y = 590;

	allin.vectorofheart.x = 1225;
	allin.vectorofheart.y = 560;

	allin.rect.top = 0;
	allin.rect.left = 0;
	allin.rect.width = 110;
	allin.rect.height = 110;

	//allin.rect2.top = 0;                                                                
	//allin.rect2.left = 0;                                                               
	//allin.rect2.width = 64;                                                             
	//allin.rect2.height = 64;

	allin.rect3.top = 0;
	allin.rect3.left = 0;
	allin.rect3.width = 30;
	allin.rect3.height = 56;

	allin.rectring.top = 0;
	allin.rectring.left = 0;
	allin.rectring.width = 64;
	allin.rectring.height = 640;

	allin.rectheart.top = 0;
	allin.rectheart.left = 0;
	allin.rectheart.width = 150;
	allin.rectheart.height = 451;

	return(allin);
}

struct s_allin clock_part(struct s_allin allin)
{
	allin.temps = sfClock_getElapsedTime(allin.clock);
	allin.seconds = allin.temps.microseconds / 190000;
	allin.seconds2 = allin.temps.microseconds / 1299990;

	if (allin.seconds > 1.00) {
			
		move_rect(&allin.rect, 110, 330);
		//move_rect(&allin.rect2, 64, 128);
		move_rect(&allin.rect, 110, 330);
		move_rect(&allin.rect3,75,150);
		allin.y++;
		sfClock_restart(allin.clock);

	}
	if (allin.seconds2 > 1.00)
		move_rect(&allin.rectring, 64,640);
		
	allin.vectorofbird = sfSprite_getPosition(allin.bird);
		
	if (allin.vectorofbird.x >= 1600) {  
		sfSprite_setPosition(allin.bird, allin.vector2);
		//sfSprite_setPosition(allin.eggman, allin.vector3);
		//sfSprite_setPosition(allin.sonic, allin.vector4);
		allin.rectheart.left = allin.rectheart.left + 146;
		allin.y = 0;
		allin.b++;
		allin.z++;
	}

	return(allin);
}

struct s_allin  draw_and_setposition_part(struct s_allin allin)
{
	//sfRenderWindow_drawSprite(window, eggman, NULL);

	sfRenderWindow_drawSprite(allin.window, allin.background, NULL);
		
	sfRenderWindow_drawSprite(allin.window, allin.score, NULL);
		
	sfRenderWindow_drawSprite(allin.window, allin.sonic, NULL);

	sfRenderWindow_drawSprite(allin.window, allin.ring, NULL);

	sfRenderWindow_drawSprite(allin.window, allin.heart, NULL);

	//sfRenderWindow_drawSprite(allin.window, allin.font, NULL);
		
	sfRenderWindow_drawSprite(allin.window, allin.bird, NULL);

	sfRenderWindow_drawSprite(allin.window, allin.cursor, NULL);
		                
	sfSprite_setPosition(allin.score, allin.vectorofscore);

	sfSprite_setPosition(allin.sonic, allin.vectorofsonic);

	sfSprite_setPosition(allin.ring, allin.vectorofring) ;

	sfSprite_setPosition(allin.heart, allin.vectorofheart);
					
	sfRenderWindow_display(allin.window);

	return(allin);
}

struct s_allin set_texture(struct s_allin allin)
{
	allin.vector2.y = rand() % 450;
	
       	//allin.vector3.y = rand() % 320;
						
	sfSprite_setTexture(allin.bird,allin.textbird, sfTrue);

	sfSprite_move(allin.bird, allin.vector);
		
	//sfSprite_setTexture(allin.eggman, allin.texteggman, sfTrue);

	//sfSprite_move(allin.eggman, allin.vectoreggman);

	 				
	sfSprite_setTexture(allin.background, allin.textback, sfTrue);

	sfSprite_setTexture(allin.score, allin.textscore, sfTrue);

	sfSprite_setTexture(allin.heart, allin.textheart, sfTrue);

	sfSprite_setTexture(allin.sonic, allin.textsonic, sfTrue);

	sfSprite_setTexture(allin.ring, allin.textring, sfTrue);
	  
	sfSprite_setTexture(allin.cursor, allin.textcursor, sfTrue);
		                
	sfSprite_setTextureRect(allin.bird, allin.rect);

	sfSprite_setTextureRect(allin.ring, allin.rectring);

	sfSprite_setTextureRect(allin.heart, allin.rectheart);

	//sfSprite_setTextureRect(allin.eggman, allin.rect2);

	sfSprite_setTextureRect(allin.sonic, allin.rect3);

	return (allin);
}

struct s_allin speed_at_25(struct s_allin allin)
{
	if (allin.b == 25)
		allin.vector.x = allin.vector.x + 4.5;
		
	printf("Hit");
	printf("\n");
	sfSprite_setPosition(allin.bird, allin.vector2);
	allin.vector.x = allin.vector.x + 0.12;
	return(allin);
}
 
struct s_allin mousecursor(struct s_allin allin)
{
	allin.vectormouse = sfMouse_getPositionRenderWindow(allin.window);
	allin.vectorofcursor.x = allin.vectormouse.x - 22;
	allin.vectorofcursor.y = allin.vectormouse.y - 13;
	sfSprite_setPosition(allin.cursor, allin.vectorofcursor);
	sfRenderWindow_setMouseCursorVisible(allin.window, 0);

	return (allin);
}

struct s_allin destroy(struct s_allin allin)
{
	sfSprite_destroy(allin.bird);
	sfSprite_destroy(allin.background);
	sfSprite_destroy(allin.sonic);
	sfSprite_destroy(allin.ring);
	//sfSprite_destroy(allin.eggman);
	sfSprite_destroy(allin.heart);
	sfSprite_destroy(allin.cursor);
	sfTexture_destroy(allin.textback);
	sfTexture_destroy(allin.textbird);
	sfTexture_destroy(allin.textsonic);
	sfTexture_destroy(allin.textring);
	sfTexture_destroy(allin.textcursor);
	//sfTexture_destroy(allin.texteggman);
	sfTexture_destroy(allin.textheart);
	sfSound_destroy(allin.sound);
	sfSoundBuffer_destroy(allin.buffer);
	sfRenderWindow_destroy(allin.window);
	return (allin);
}
int main ()
{
	struct s_allin allin;
	
	allin = proportions(allin);
	allin = functionvector(allin);
	allin = create_of_textsprite(allin);
		
	while (sfRenderWindow_isOpen(allin.window)) {

		allin = set_texture(allin);
		allin = clock_part(allin);
		sfSprite_setScale(allin.heart, allin.vectorsizeheart);
		sfSprite_setScale(allin.sonic, allin.vectorsizeofsonic);
		
		while (sfRenderWindow_pollEvent(allin.window, &allin.event)) {
			analyse_events(allin.event);
	
			
			if (allin.event.type == sfEvtMouseButtonPressed) {
				if (sfMouse_getPositionRenderWindow(allin.window).x >= sfSprite_getPosition(allin.bird).x &&
				    sfMouse_getPositionRenderWindow(allin.window).x <= sfSprite_getPosition(allin.bird).x + 110) {
					if(sfMouse_getPositionRenderWindow(allin.window).y >= sfSprite_getPosition(allin.bird).y &&
					   sfMouse_getPositionRenderWindow(allin.window).y <= sfSprite_getPosition(allin.bird).y + 110) {
					}
					sfSprite_setPosition(allin.bird, allin.vector2);
					allin = speed_at_25(allin);
				}
			}				
			if(allin.z >= 3)
				sfRenderWindow_close(allin.window);

			allin = mousecursor(allin);
			allin.key = allin.event.key;
			if(allin.key.code == 36)
				sfRenderWindow_close(allin.window);
		     
			if (allin.event.type == sfEvtClosed)
				sfRenderWindow_close(allin.window);
		}
	}
	allin = destroy(allin);
	
}
