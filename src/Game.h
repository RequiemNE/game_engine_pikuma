#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>

const int FPS = 60;
const int MILISECS_PER_FRAME = 1000 / FPS;

class Game
{
private:
    // Private member variables = all public class variables (below) will have
    // access to these.
    bool isRunning;
    int millisecsPreviousFrame = 0;
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    Game();
    ~Game();
    void Initialize();
    void Run();
    void Setup();
    void Destroy();
    void ProcessInput();
    void Update();
    void Render();

    int windowWidth;
    int windowHeight;
};

#endif