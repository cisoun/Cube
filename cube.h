#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

/**
 * Colors 
 * NOTE: taken from https://flatuicolors.com/palette/de
 */
static GLubyte black[] = { 0, 0, 0 };
static GLubyte white[] = { 255, 255, 255 };
static GLubyte gray_darkest[] = { 75, 101, 132 };
static GLubyte gray_dark[] = { 119, 140, 163 };
static GLubyte gray_light[] = { 165, 177, 194 };
static GLubyte gray_lightest[] = { 209, 216, 224 };
static GLubyte blue[] = { 69, 170, 242 };
static GLubyte blue_dark[] = { 45, 152, 218 };
static GLubyte green[] = { 38, 222, 129 };
static GLubyte green_dark[] = { 32, 191, 107 };
static GLubyte indigo[] = { 75, 123, 236 };
static GLubyte indigo_dark[] = { 56, 103, 214 };
static GLubyte orange[] = { 253, 150, 68 };
static GLubyte orange_dark[] = { 250, 130, 49 }; 
static GLubyte red[] = { 252, 92, 101 };
static GLubyte red_dark[] = { 235, 59, 90 };
static GLubyte turquoise[] = { 43, 203, 186 };
static GLubyte turquoise_dark[] = { 15, 185, 177 };
static GLubyte yellow[] = { 254, 211, 48 };
static GLubyte yellow_dark[] = { 247, 183, 49 };

typedef struct vec3 vec3;
struct vec3
{
    float x;
    float y;
    float z;
};

typedef struct Cube Cube;
struct Cube
{
    vec3 position;
};
