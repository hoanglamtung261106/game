#include "graphics.h"

Graphics graphics;
Sprite bird, bird2;
SDL_Rect pause_button[3];
bool menu = false, pause = false, play = true;

void initialize() {
    graphics.init();

    SDL_Texture* birdTexture = graphics.loadTexture(BIRD_SPRITE_FILE);
    bird.init(birdTexture, BIRD_FRAMES, BIRD_CLIPS);

    SDL_Texture* bird2Texture = graphics.loadTexture(BIRD2_SPRITE_FILE);
    bird2.init(bird2Texture, BIRD2_FRAMES, BIRD2_CLIPS);

    pause_button[0].x = SCREEN_WIDTH - 30;
    pause_button[0].y = 0;
    pause_button[0].w = 30;
    pause_button[0].h = 30;

    pause_button[1].x = SCREEN_WIDTH - 24;
    pause_button[1].y = 6;
    pause_button[1].w = 6;
    pause_button[1].h = 18;

    pause_button[2].x = SCREEN_WIDTH - 12;
    pause_button[2].y = 6;
    pause_button[2].w = 6;
    pause_button[2].h = 18;
}
