#include <iostream>
#include <SDL.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
#include "Screen.h"

using namespace std;

int main(int argc, char *argv[]){

	//Initialising
	Screen screen(800, 600);
	if(screen.init() == false){
		cout << "Couldn't Initialise SDL "<<endl;
		return -1;
	}

	//Creating Random Particles
	srand(time(NULL));
	Swarm swarm;

	//Game_Loop--------------------------------------
	while(true){

		//Changing Colour
		int elapsed = SDL_GetTicks();
		int green = ((1+sin(elapsed*0.0001)) * 128);
		int red = ((1+sin(elapsed * 0.0002)) * 128);
		int blue = ((1+sin(elapsed * 0.0003)) * 128);

		//Displaying Random Particles
		swarm.update();
		Particle* pParticles = swarm.getParticles();
		for(int i=0; i<swarm.NPARTICLES; i++){
			Particle points = pParticles[i];
			int x = (points.m_x+1) * (screen.SCREEN_WIDTH/2);
			int y = (points.m_y) * (screen.SCREEN_WIDTH/2) + screen.SCREEN_HEIGHT/2;

			screen.setPixel(x,y,red,green,blue);
		}

		screen.boxBlur();

		//Draw On Screen
		screen.update();

		//Checking for Messages and Events
		if(screen.processEvents() == false)
			break;
	}

	//Closing
	screen.close();

	return 0;
}
