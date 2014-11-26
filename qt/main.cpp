#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

using namespace std;

int main(int argc, char* argv[]) {
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO /*|SDL_INIT_AUDIO*/) == -1) {
		cerr << "Error initializing SDL" << endl;
		exit(1);
	}

	// create the window
	SDL_Window* window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	// make the scaled rendering look smoother
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	// render at a virtual resolution then stretch to actual resolution
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	// load ball
	SDL_Texture* blue{nullptr};
	int ballWidth{0};
	int ballHeight{0};
	{
		SDL_Surface* temp = IMG_Load("blue.png");

		blue = SDL_CreateTextureFromSurface(renderer, temp);
		ballWidth = temp->w;
		ballHeight = temp->h;

		SDL_FreeSurface(temp);
	}

	// set ball position
	SDL_Rect ballRect;
	ballRect.x = 10;
	ballRect.y = 10;
	ballRect.w = ballWidth;
	ballRect.h = ballHeight;
	int xSpeed{1000};
	int ySpeed{1000};

	const Uint32 targetFrameDelay = 10;
	Uint32 startTime = SDL_GetTicks();
	Uint32 lastFrameTime = startTime;

	// main loop
	bool running{true};
	while (running) {
		// calculate deltaTime to use for updates
		// done just before updates are done for maximum accuracy
		Uint32 frameDelay = SDL_GetTicks() - lastFrameTime;
		float deltaTime = frameDelay / 1000.0f;
		lastFrameTime += frameDelay;

		// handle events
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					running = false;
				}
				else if (event.key.keysym.sym == SDLK_x) {
					xSpeed = -xSpeed;
				}
				else if (event.key.keysym.sym == SDLK_y) {
					ySpeed = -ySpeed;
				}
			}
		}

		// update things, scaled by deltaTime
		ballRect.x += xSpeed*deltaTime;
		ballRect.y += ySpeed*deltaTime;

		if (ballRect.x + ballWidth > SCREEN_WIDTH || ballRect.x < 0) {
			xSpeed = -xSpeed;
		}
		if (ballRect.y + ballHeight > SCREEN_HEIGHT || ballRect.y < 0) {
			ySpeed = -ySpeed;
		}

		// clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// draw things
		SDL_RenderCopy(renderer, blue, nullptr, &ballRect);

		// show the newly drawn things
		SDL_RenderPresent(renderer);

		// wait before drawing the next frame
		frameDelay = SDL_GetTicks() - lastFrameTime;
		if (targetFrameDelay > frameDelay) {
			// only wait if it's actually needed
			Uint32 sleepTime = targetFrameDelay - frameDelay;
			SDL_Delay(sleepTime);
		}
	}

	// free memory
	SDL_DestroyTexture(blue);
	blue = nullptr;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}
