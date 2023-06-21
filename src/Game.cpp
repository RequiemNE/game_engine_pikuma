#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>

Game::Game()
{
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
    SDL_Window *window = SDL_CreateWindow(
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
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        std::cerr << "Error creating renderer." << std::endl;
        return;
    }
}

void Game::ProcessInput()
{
}

void Game::Destroy()
{
}

void Game::Render()
{
}

void Game::Run()
{
}

void Game::Update()
{
}