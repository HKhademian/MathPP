#include <iostream>
#include <vector>
#include <stddef.h>
#include "Raylib.h"

using namespace std;
using namespace Raylib;
#define SIZE 100

class Game
{
    const size_t screenWidth, screenHeight;

public:
    int map[SIZE][SIZE];

    Game(size_t screenWidth, size_t screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight)
    {
    }

    void Init()
    {
        InitWindow(screenWidth, screenHeight, "My Game");
        SetTargetFPS(60);
    }

    void Run()
    {
        while (!WindowShouldClose())
        {
            Update();
            Draw();
        }

        CloseWindow();
    }

    void Update()
    {
        // Update game logic here
    }

    void Draw()
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawFPS(2 * Vector2{11, 11} + Vector2{11, 11} / 5);
        DrawText("Congrats! You created your first window!", {190, 200}, 20, LIGHTGRAY);

        // Draw the map
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
            }
        }

        EndDrawing();
    }
};

int main()
{
    Game game(800, 600);
    game.Init();
    game.Run();

    return 0;
}