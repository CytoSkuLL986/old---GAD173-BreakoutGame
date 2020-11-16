#pragma once

#include "app.h"

//Definitions for some grid parameters. Utilizing definitions this way allows us to easily modify the the dimensions
//of the grid if needed.
#define LINE_THICKNESS 3

#define GRID_OFFSET_X 300
#define GRID_OFFSET_Y 50

#define CELL_WIDTH 80
#define CELL_HEIGHT 35

#define TOTAL_CELLS_X 15 + 1
#define	TOTAL_CELLS_Y 25 + 1

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	sf::Sprite *m_backgroundSprite;
	//sf::RectangleShape line;

	//Below arrays were created for the horizontal and vertical grid lines respectively. The definitions mentioned
	//at the top of this script were used to set the array sizes.
	sf::RectangleShape vLine[TOTAL_CELLS_X];
	sf::RectangleShape hLine[TOTAL_CELLS_Y];
};
