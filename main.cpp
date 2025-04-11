#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "definition.h"
#include "initialize.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[]) {
    initialize();

    bool quit = false;
    bool upside_down = false;
    SDL_Event e;
    int x = 150, y = 150;

    while (!quit) {
        /*while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) quit = true;
        }*/

        if (play) {
            update(graphics, bird, bird2, upside_down, x, y);
            int px, py;
            SDL_GetMouseState(&px, &py);
            SDL_PollEvent(&e);
            cerr << SDL_MOUSEBUTTONDOWN << " " << e.type << "\n";
            if (px >= SCREEN_WIDTH - 30 && px <= SCREEN_WIDTH && py >= 0 && py <= 30
                && e.type == SDL_MOUSEBUTTONDOWN) play = false, pause = true;
        }
        else if (pause);
        else if (menu);

        graphics.presentScene();
        SDL_Delay(15);

    }

	//SDL_DestroyTexture( manTexture ); manTexture = nullptr;
	//SDL_DestroyTexture( birdTexture ); birdTexture = nullptr;

    graphics.quit();
}
