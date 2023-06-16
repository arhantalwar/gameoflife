#include "raylib.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX_BLOX 50

float rand_text() {
    return ((float) rand() / (float) RAND_MAX) * 16.f;
}

typedef struct {
    int x;
    int y;
    int num;
} blox;

typedef struct {
    int rows;
    int cols;
    blox *data;
} Mat;

int main() {

    srand(time(0));

    int width = 0;
    int height = 0;

    InitWindow(width, height, "GAME");
    SetTargetFPS(10);

    Image block0 = LoadImage("./train_data/0000.png");
    Image block1 = LoadImage("./train_data/0001.png");
    Image block2 = LoadImage("./train_data/0010.png");
    Image block3 = LoadImage("./train_data/0011.png");
    Image block4 = LoadImage("./train_data/0100.png");
    Image block5 = LoadImage("./train_data/0101.png");
    Image block6 = LoadImage("./train_data/0110.png");
    Image block7 = LoadImage("./train_data/0111.png");
    Image block8 = LoadImage("./train_data/1000.png");
    Image block9 = LoadImage("./train_data/1001.png");
    Image block10 = LoadImage("./train_data/1010.png");
    Image block11 = LoadImage("./train_data/1011.png");
    Image block12 = LoadImage("./train_data/1100.png");
    Image block13 = LoadImage("./train_data/1101.png");
    Image block14 = LoadImage("./train_data/1110.png");
    Image block15 = LoadImage("./train_data/1111.png");

    Texture2D texture[16] = { 0 };

    texture[0] = LoadTextureFromImage(block0);
    texture[1] = LoadTextureFromImage(block1);
    texture[2] = LoadTextureFromImage(block2);
    texture[3] = LoadTextureFromImage(block3);
    texture[4] = LoadTextureFromImage(block4);
    texture[5] = LoadTextureFromImage(block5);
    texture[6] = LoadTextureFromImage(block6);
    texture[7] = LoadTextureFromImage(block7);
    texture[8] = LoadTextureFromImage(block8);
    texture[9] = LoadTextureFromImage(block9);
    texture[10] = LoadTextureFromImage(block10);
    texture[11] = LoadTextureFromImage(block11);
    texture[12] = LoadTextureFromImage(block12);
    texture[13] = LoadTextureFromImage(block13);
    texture[14] = LoadTextureFromImage(block14);
    texture[15] = LoadTextureFromImage(block15);

    blox blox_array[MAX_BLOX] = { 0 };
    size_t count = 0;
    int blox_width = 28;

    for(size_t i = 0; i < MAX_BLOX; ++i) {
        blox_array[i].x = 100 + blox_width;
        blox_array[i].y = 300 + 0*28;
        blox_array[i].num = rand_text();
        blox_width += 28;
        //printf("blox%zu x: %d, y %d, num: %d\n", i, blox_array[i].x, blox_array[i].y, blox_array[i].num);
    }

    //DrawTexture(texture[random_texture], x, y, WHITE);

    while(!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for(size_t i = 0; i < MAX_BLOX; ++i) {
            if (i < 25) {
                DrawTexture(texture[blox_array[i].num], blox_array[i].x, blox_array[i].y, RAYWHITE);
            } else if (i > 24) {
                DrawTexture(texture[blox_array[i].num], blox_array[i].x - 28 * 25, blox_array[i].y + 28, RAYWHITE);
            }
            blox_array[i].num = (blox_array[i].num) ^ blox_array[i+1].num;
            blox_array[i].num = (blox_array[i].num) & blox_array[i+1].num;
        }

        EndDrawing();

    }

    for (int i = 0; i < 16; i++) UnloadTexture(texture[i]);

    CloseWindow();

    return 0;

}






//blox_array[i].num = blox_array[i].num ^ blox_array[i+1].num; // BLANK LINE ACROSS
//blox_array[i].num = blox_array[i].num & blox_array[i+1].num;
