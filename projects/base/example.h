#pragma once

#include "app.h"
#include <vector>

//Definitions for some grid parameters. Utilizing definitions this way allows us to easily modify the the dimensions
//of the grid if needed.
#define LINE_THICKNESS 3

//As of now, Offsets are set 0, as they where creating unnecessary complications for during debugging.
//I have kept the defines for future testing.
#define GRID_OFFSET_X 0
#define GRID_OFFSET_Y 0

#define CELL_WIDTH 110
#define CELL_HEIGHT 50

#define TOTAL_CELLS_X 15 + 1
#define	TOTAL_CELLS_Y 15 + 1

#define TILES_ARRAY_SIZE (TOTAL_CELLS_X - 1) * (TOTAL_CELLS_Y - 1)

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

	int TileID = 0;

	//pointers for tile textures
	sf::Texture* sapphire = nullptr;
	sf::Texture* diamond = nullptr;
	sf::Texture* stone = nullptr;
	sf::Texture* questionMark = nullptr;

	//Below we have created the array of sprites (for grid-slots)
	sf::Sprite tiles[TILES_ARRAY_SIZE];

	sf::Sprite *m_backgroundSprite = nullptr;
	

	//Below arrays were created for the horizontal and vertical grid lines respectively. The definitions mentioned
	//at the top of this script were used to set the array sizes.
	sf::RectangleShape vLine[TOTAL_CELLS_X];
	sf::RectangleShape hLine[TOTAL_CELLS_Y];
};
