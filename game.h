#ifndef GAME_H
#define GAME_H

#define INITIAL_SPEED 3

#include "definition.h"
#include "graphics.h"

struct Mouse {
    int x, y;
    int dx = 0, dy = 0;
    int speed = INITIAL_SPEED;
    void move() {
        x += dx;
        y += dy;
    }
    void turnNorth() {
        dy = -speed;
        dx = 0;
    }
    void turnSouth() {
        dy = speed;
        dx = 0;
    }
    void turnWest() {
        dy = 0;
        dx = -speed;
    }
    void turnEast() {
        dy = 0;
        dx = speed;
    }
};

void render(const Mouse& mouse, const Graphics& graphics) {
    SDL_Rect filled_rect;
    filled_rect.x = mouse.x;
    filled_rect.y = mouse.y;
    filled_rect.w = 10;
    filled_rect.h = 10;
    SDL_SetRenderDrawColor(graphics.renderer, 0, 255, 0, 255); // green
    SDL_RenderFillRect(graphics.renderer, &filled_rect);
}

bool gameOver(const Mouse& mouse) {
    return mouse.x < 0 || mouse.x >= SCREEN_WIDTH ||
           mouse.y < 0 || mouse.y >= SCREEN_HEIGHT;
}

void update(Graphics& graphics, Sprite& bird, Sprite& bird2, bool& upside_down, int& x, int& y) {
    /* upside_down là true nếu ngược
    x là tọa độ x, y là tọa đô y */


    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_SPACE]) upside_down ^= 1; //Nếu ấn dấu cách thì đảo xuôi thành ngược và ngược lại

    if (!upside_down) /*Xuôi*/ {
        if (currentKeyStates[SDL_SCANCODE_UP] && y >= 10) y -= 10;
        else if (currentKeyStates[SDL_SCANCODE_UP]); //TH này chỉ ra y == 10, và chim ko bay lên nữa kể cả ấn phím lên
        else if (y <= 390) y += 10;
        graphics.prepareScene();
        graphics.render(x, y, bird);
    }
    else /*Ngược*/ {
        if (currentKeyStates[SDL_SCANCODE_UP] && y <= 390) y += 10;
        else if (currentKeyStates[SDL_SCANCODE_UP]); //TH này chỉ ra y == 390, và chim ko bay xuống nữa kể cả ấn phím lên
        else if (y >= 10) y -= 10;
        graphics.prepareScene();
        graphics.render(x, y, bird2);
    }


    SDL_SetRenderDrawColor(graphics.renderer, 0, 255, 0, 255); // green
    SDL_RenderFillRect(graphics.renderer, &pause_button[0]);

    SDL_SetRenderDrawColor(graphics.renderer, 0, 0, 0, 255); // black
    for (int i = 1; i <= 2; i++) SDL_RenderFillRect(graphics.renderer, &pause_button[i]);

    bird.tick(); bird2.tick(); //Update 1 đoạn mới cho 2 loại chim (14 đoạn tất cả)
}
#endif // GAME_H
