//
// Created by Beef Erikson Studios on 10/14/2019.
//

#include "main.h"

int main(int argc, char *args[]) {
    // Start up SDL and create window
    if (!init.InitSDL()) {
        printf("Failed to initialize!");
    }
    else {
        // Load media
        if (!game.loadMedia()) {
            printf("Failed to load media!");
        }
        else {
            // Create Player
            Character player("Beef",
                             "../sprites/player/playerUp.png",
                             "../sprites/player/playerDown.png",
                             "../sprites/player/playerLeft.png",
                             "../sprites/player/playerRight.png",
                             SCREEN_WIDTH / 2 - 17,               // half of sprite width subtracted
                             SCREEN_HEIGHT / 2 - 24,              // half of sprite *height subtracted
                             34,
                             48,
                             false,
                             100);

            // Player rectangle size, placement at center of screen
            SDL_Rect playerRect{player.get_x_position(), player.get_y_position(),
                                player.get_spriteWidth(), player.get_spriteHeight()};

            ///
            /// MAIN GAME LOOP
            ///
            while (!quit) {
                // Handle events
                while (SDL_PollEvent(&app.inputEvent) != 0) {
                    // Quits game if X is clicked
                    if (app.inputEvent.type == SDL_QUIT) {
                        quit = true;
                    }
                    // Keyboard input detected
                    if (app.inputEvent.type == SDL_KEYDOWN) {
                        game.input_update(app.inputEvent, player, &playerRect);
                    }
                }
                game.render_update(playerRect);
            }
            ///
            /// END GAME LOOP
            ///
        }
    }

    game.close();
    return 0;
}