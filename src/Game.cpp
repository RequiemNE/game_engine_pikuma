#include "Game.h"
#include <iostream>

Game::Game()
{
    isRunning = false;
    std::cout << "constructor called" << std::endl;
}

Game::~Game()
{
    std::cout << "destructor called" << std::endl;
}

void Game::Initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_BORDERLESS);

    if (!window)
    {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }

    // createRended -1 means get the default render driver. 0 means no SDL flags.
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        std::cerr << "Error creating renderer." << std::endl;
        return;
    }

    // If everything is running/rendering, THEN isRunning = true;
    isRunning = true;
}

void Game::ProcessInput()
{
    SDL_Event sdlEvent;
    // While there are events (there will be), poll for events.
    while (SDL_PollEvent(&sdlEvent))
    {
        switch (sdlEvent.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
            break;
        }
    }
}

void Game::Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::Render()
{
}

void Game::Run()
{
    while (isRunning)
    {
        ProcessInput();
        Update();
        Render();
    }
}

void Game::Update()
{
}