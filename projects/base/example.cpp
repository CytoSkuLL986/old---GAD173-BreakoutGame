#include "example.h"

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	cat = kage::TextureManager::getTexture("data/cat.png");

	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	
	//The below commented-out code is the first trial of sf::RectangleShape.
	//line = sf::RectangleShape(sf::Vector2f(150.0f, 50.0f));
	//line.setFillColor(sf::Color::Magenta);
	//line.setPosition(sf::Vector2f(800.f,400.f));

	/*
	Below, you see the creation of the grid (more specifically, the grid lines); The first for loop is for the creation
	of the Vertical grid lines and the second is for the horizontal grid lines.
	The head of the for loop defines that we want the loop to continue for the pre-defined amount of cells we want on
	the X and Y axis respectively. (Definitions have been created under example.h)
	For the 3 lines of code inside the for loop:
	The first line draws the actual 'line' shape (Rectangle primitive) using SFML's capabilities, we defined the length
	and width of this line using the Vector2f function.
	The second line allows us to set the color of the line.
	The third line sets the position of the line shape, considering its starting point. Use of i * CELL_WIDTH/HEIGHT
	allows us to use the incrementaion in the for loop to establish multiple positions (evenly spaced) to be drawn.
	*/

	for (size_t i = 0; i < TOTAL_CELLS_X; i++)
	{
		vLine[i] = sf::RectangleShape(sf::Vector2f(LINE_THICKNESS, CELL_HEIGHT * TOTAL_CELLS_Y));
		vLine[i].setFillColor(sf::Color::Yellow);
		vLine[i].setPosition(sf::Vector2f(GRID_OFFSET_X + CELL_WIDTH * i, GRID_OFFSET_Y));
	}

	for (size_t i = 0; i < TOTAL_CELLS_Y; i++)
	{
		hLine[i] = sf::RectangleShape(sf::Vector2f(CELL_WIDTH * TOTAL_CELLS_X, LINE_THICKNESS));
		hLine[i].setFillColor(sf::Color::Cyan);
		hLine[i].setPosition(sf::Vector2f(GRID_OFFSET_X, GRID_OFFSET_Y + CELL_HEIGHT * i));
	}


	return true;
}

void Example::update(float deltaT)
{
	sf::Vector2i mouseposition = sf::Mouse::getPosition(m_window);

	//std::cout << mouseposition.x << " " << mouseposition.y << std::endl;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		int x = mouseposition.x / CELL_WIDTH;
		int y = mouseposition.y / CELL_HEIGHT;

		if (x >= 4 && y >= 1 &&
			x < (TOTAL_CELLS_X - 1) && y < (TOTAL_CELLS_Y - 1))
		{
			int i = x + y * (TOTAL_CELLS_X - 1);

				// Mustafa deleted this 1:20:24 std::cout << x << "  " << y << std::endl;

				sf::Sprite catSprite;
				catSprite.setTexture(*cat);
				catSprite.setPosition(sf::Vector2f(x * CELL_WIDTH, y * CELL_HEIGHT));

				tiles[i] = catSprite;
		
		} 
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	//m_window.draw(line);

	/*
	Below are for loops created to draw/render the gridlines on the actual game window, one for the vertical, and the
	other for horizontal lines.
	Also loop for creating array of sprites for spawning tiles on.
	Use of for loops allows us to easily say that we want this line drawn 'x' amount of times without being redundant.
	*/

	for (size_t i = 0; i < TOTAL_CELLS_X; i++)
	{
		m_window.draw(vLine[i]);
	}

	for (size_t i = 0; i < TOTAL_CELLS_Y; i++)
	{
		m_window.draw(hLine[i]);
	}

	for (size_t i = 0; i < TILES_ARRAY_SIZE; i++)
	{
		m_window.draw(tiles[i]);
	}
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

