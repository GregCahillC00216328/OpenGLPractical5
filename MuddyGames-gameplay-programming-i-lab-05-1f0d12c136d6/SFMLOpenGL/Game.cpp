#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
	
}

Game::~Game() {}

void Game::run()
{
	
	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			if (event.type == Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
				{
					m_currentState = states::Lines;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					m_currentState = states::PinkFloyd;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					m_currentState = states::Line_Strip;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && sf::Keyboard::isKeyPressed(sf::Keyboard::E))
				{
					m_currentState = states::Line_Loop;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
				{
					m_currentState = states::Triangles;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && sf::Keyboard::isKeyPressed(sf::Keyboard::O))
				{
					m_currentState = states::Triangle_Strip;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				{
					m_currentState = states::Triangle_Fan;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				{
					m_currentState = states::Quads;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					m_currentState = states::Quad_Strip;
				}
				
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	m_currentState = states::PinkFloyd;
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0); 
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	 cout << "Draw up" << endl; 
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	 switch (m_currentState)
	 {
	 case states::PinkFloyd:
		 glBegin(GL_LINES);
		 {
			 glColor3f(255, 255, 255);
			 glVertex3f(0.0, 2.0, -10.0);
			 glColor3f(255, 255, 255);
			 glVertex3f(-2.0, -2.0, -10.0);
		 }
		 glEnd();
		 glBegin(GL_LINES);
		 {
			 glColor3f(255, 255, 255);
			 glVertex3f(-2.0, -2.0, -10.0);
			 glColor3f(255, 255, 255);
			 glVertex3f(2.0, -2.0, -10.0); }
		 glEnd();
		 glBegin(GL_LINES);
		 {
			 glColor3f(255, 255, 255);
			 glVertex3f(0.0, 2.0, -10.0);
			 glColor3f(255, 255, 255);
			 glVertex3f(2.0, -2.0, -10.0); }
		 glEnd();
		 glBegin(GL_LINES);
		 {
			 glColor3f(255, 255, 255);
			 glVertex3f(-.5, .0, -5.0);
			 glColor3f(255, 255, 255);
			 glVertex3f(-2.2, -.7, -5.0); }
		 glEnd();
		 glBegin(GL_TRIANGLES);
		 {
			 glColor3f(255, 255, 255);
			 glVertex3f(-.5, .0, -5);
			 glColor3f(0, 0, 0);
			 glVertex3f(.5, .0, -5);
			 glColor3f(5, 5, 5);
			 glVertex3f(.3, .4, -5);
		 }

		 glEnd();
		 glBegin(GL_QUADS);
		 {
			 glColor3f(0, 0, 255);
			 glVertex3f(3, -1., -5);
			 glColor3f(0, 255, 0);
			 glVertex3f(.5, .0, -5);
			 glColor3f(255, 0, 0);
			 glVertex3f(.3, .4, -5);
			 glColor3f(255, 0, 255);
			 glVertex3f(3, -.1, -5); }
		 glEnd();
		 break;
	 case states::Lines:
		 glBegin(GL_LINES);
		 {
			 glColor3f(255, 255, 255);
			 glVertex3f(0.0, 2.0, -10.0);
			 glColor3f(255, 255, 255);
			 glVertex3f(-2.0, -2.0, -10.0);
		 }
		 glEnd();
		 break;
	 case states::Line_Strip:
		 glBegin(GL_LINE_STRIP);
		 {
			 glColor3f(50, 0, 100);
			 glVertex3f(-2.0, 0.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(-1.5, 2.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(-1.0, 0.0, -5.0);
			 glColor3f(50,0, 100);
			 glVertex3f(-0.5, 2.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(0.0, 0.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(0.5, 2.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(1.0, 0.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(1.5, 2.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(2.0, 0.0,-5.0);
		 }
		 glEnd();
		 break;
	 case states::Line_Loop:
		 glBegin(GL_LINE_LOOP);
		 {
			 glColor3f(50, 0, 100);
			 glVertex3f(-2.0, -2.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(-1.5, 0.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(-1.0, -2.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(-0.5, 0.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(0.0, -2.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(0.5, 0.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(1.0, -2.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(1.5, 0.0, -5.0);
			 glColor3f(50, 0, 100);
			 glVertex3f(2.0, -2.0, -5.0);
		 }
		 glEnd();
		 break;
	 case states::Triangles:
		 glBegin(GL_TRIANGLES);
		 {
			 glColor3f(255, 255, 255);
			 glVertex3f(-.5, .0, -5);
			 glColor3f(0, 0, 0);
			 glVertex3f(.5, .0, -5);
			 glColor3f(5, 5, 5);
			 glVertex3f(.3, .4, -5);
		 }

		 glEnd();
		 break;
	 case states::Triangle_Fan:
		 glBegin(GL_TRIANGLE_FAN);
		 {
			 glColor3f(255, 255, 255);
			 glVertex3f(0, 0, -5);
			 glColor3f(255, 255, 255);
			 glVertex3f(1, 0, -5);
			 glColor3f(255, 255, 255);
			 glVertex3f(0, 1, -5);
			 glColor3f(255, 255, 255);
			 glVertex3f(-1, 0, -5);
			 glColor3f(255, 255, 255);
			 glVertex3f(-1, -1, -5);
		 }
		 break;
	 case states::Triangle_Strip:
		 glBegin(GL_TRIANGLE_STRIP);
		 {
			 glColor3f(255, 255, 255);
			 glVertex3f(0.0, 0.0, -5);
			 glColor3f(255, 255, 255);
			 glVertex3f(1, 0.0, -5);
			 glColor3f(0, 255, 255);
			 glVertex3f(0.0, 1.0, -5);
			 glColor3f(255, 255, 0);
			 glVertex3f(0.9, 0.9, -5);
			 glColor3f(255, 0, 255);
			 glVertex3f(1.0, -1.0, -5);
			 glEnd();
		 }
		 break;
	 case states::Quads:
		 glBegin(GL_QUADS);
		 { glColor3f(255, 255, 255);
			 glVertex3f(0.0, 0.0, -5);
			 glColor3f(255, 255, 255);
		 glVertex3f(1.0, 0.0, -5);
		 glColor3f(255, 255, 255);
		 glVertex3f(1.0, 1.0, -5);
		 glColor3f(255, 255, 255);
		 glVertex3f(0.0, 1.0, -5); }
		 glEnd();
		 break;
	 case states::Quad_Strip:
		 glBegin(GL_QUAD_STRIP);
		 { glColor3f(255, 255, 255);
		 glVertex3f(-2.0, -0.0, -5);
		 glColor3f(255, 255, 255);
		 glVertex3f(-2.0, 0.0, -5);
		 glColor3f(255, 255, 255);
		 glVertex3f(-0.0, -0.0, -5);
		 glColor3f(255, 255, 255);
		 glVertex3f(-0.0, -3.0, -5);
		 glColor3f(255, 255, 255);
		 glVertex3f(2.0, -2.0, -5);
		 glColor3f(255, 255, 255);
		 glVertex3f(2.0, 2.0, -5); }
		 
		
		 glEnd();
		 break;
	 default:
		 break;
	 }
	
	 window.display(); 
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

