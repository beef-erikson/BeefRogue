//
// Created by Beef Erikson Studios on 10/14/2019.
//

#include <SDL.h>
#include <cstdio>
#include "Character.h"
#include "InputHandler.h"
#include "Game.h"

// TODO Input handler
//InputHandler input;

// Game handler
Game game;

int main(int argc, char *args[]) {
    // Start up SDL and create window
    if (!game.init()) {
        printf("Failed to initialize!");
    }
    else {
        // Load media
        if (!game.loadMedia()) {
            printf("Failed to load media!");
        }
        else {
            // Main loop flag
            bool quit = false;

            // Event handler
            SDL_Event event;

            // Create Player
            Character player("Beef",
                          "../sprites/player/playerUp.png",
                          "../sprites/player/playerDown.png",
                          "../sprites/player/playerLeft.png",
                          "../sprites/player/playerRight.png",
                          game.screen_width / 2 - 23,               // half of sprite width subtracted
                          game.screen_height / 2 - 32,              // half of sprite *height subtracted
                          64,
                          46,
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
                while (SDL_PollEvent(&event) != 0) {
                    // Quits game if X is clicked
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }

                    if (event.type == SDL_KEYDOWN) {
                        // Keyboard input detected
                        game.input_update(event, player, &playerRect);
                    }
                }
                game.render_update(playerRect);
            }
            ///
            /// End Main Game Loop
            ///
        }
    }

    game.close();
    return 0;
}