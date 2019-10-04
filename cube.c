/* cube.c
 *
 * Copyright 2018 Cyriaque Skrapits
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "cube.h"

void draw_background()
{
    glBegin(GL_POLYGON);
    
    glColor3ubv(gray_darkest);
    glVertex3d(-1, 1, 1);
    glVertex3d(1, 1, 1);
    
    glColor3ubv(turquoise);
    glVertex3d(1, -1, 1);    
    glVertex3d(-1, -1, 1);
 
    glEnd();
}

void draw_cube(const Cube cube)
{ 
    const vec3 position = cube.position;

    //glScalef(0.2f, 0.2f, 0.2f);
    glTranslatef(position.x, position.y, position.z);
    
    //glRotatef(-25, 1, 0, 0);
    //glRotatef(-45, 0, 1, 0);
    
    glBegin(GL_POLYGON);                // Begin drawing the color cube with 6 quads
                                      // 
      // Top face(y = 1.0f)
      // Define vertices in counter-clockwise(CCW) order with normal pointing out
      glColor3ubv(yellow);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
    glEnd();
    
    /*glBegin(GL_POLYGON); 
      // Bottom face(y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();*/
    
    /*glBegin(GL_POLYGON); 
      // Front face (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
     glEnd();*/
    
    glBegin(GL_POLYGON); 
      // Back face(z = -1.0f)
      glColor3ubv(yellow_dark);    // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
     glEnd();
    
    glBegin(GL_POLYGON); 
      // Left face(x = -1.0f)
      glColor3ubv(orange);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
     glEnd();
    
    /*glBegin(GL_POLYGON); 
      // Right face(x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();*/
    
    //glRotatef(45, 0, 1, 0);
    //glRotatef(25, 1, 0, 0);
    
    glTranslatef(-position.x, -position.y, -position.z);
    
    //glScalef(5.f, 5.f, 5.f);
}

int main(int argc, char *argv[])
{
    int width = 640;
    int height = 640;
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }
    
    SDL_WM_SetCaption("Cube", NULL);
    SDL_SetVideoMode(width, height, 32, SDL_OPENGL);
    
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    
    int loop = 1;
    SDL_Event event;
    
    
    vec3 position = { 0.0, 0.0, 0.0 };
    Cube cube;
    cube.position = position;
    
    Cube cube2;
    vec3 position2 = { 0.0, 3.0, 0.0 };
    cube2.position = position2;
    
    Cube cube3;
    vec3 position3 = { 0.0, -3.0, 0.0 };
    cube3.position = position3;

    unsigned int lastTime = 0, currentTime;
    unsigned int delta = 1000 / 60; // 1000 / fps
    
    while(loop)
    {
        // Force to desired frames per second.
        currentTime = SDL_GetTicks();
        if(currentTime < lastTime + delta) continue;
        lastTime = currentTime;
        
        
        //SDL_WaitEvent(&event);
        if(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        /*case SDLK_DOWN: cube.x -= 10; break;
                        case SDLK_LEFT: cube.x -= 10; break;
                        case SDLK_RIGHT: cube.x += 10; break;
                        case SDLK_UP: cube.y += 10; break;*/
                    }
                    break;
                
                case SDL_KEYUP:
                break;
                
                        
                case SDL_QUIT:
                    loop = 0;
            }
        }
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        
        draw_background();
        
        glScalef(0.2f, 0.2f, 0.2f);
        glRotatef(-25, 1, 0, 0);
        glRotatef(-45, 0, 1, 0);
    
        draw_cube(cube3);
        draw_cube(cube);
        draw_cube(cube2);
        
        
        glFlush();
        SDL_GL_SwapBuffers();
        
        cube.position.y = sin(SDL_GetTicks() * 0.002);
    }

    SDL_Quit();

    return 0;
}
