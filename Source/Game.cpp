#include "Game.h"
#include "Timer.h"
#include "Constants.h"

namespace GameDev2D
{
	Game::Game() 
		
	{
		m_Timer.SetDuration(DURATION);
		m_Timer.SetDoesLoop(true);
		m_Timer.Start();


		m_Platform1 = new Polygon();
		m_Platform1->MakeRectangle(150, 20, true);
		m_Platform1->SetColor(Color::BlueColor());
		m_Platform1->SetPosition(550, Y_AXIS);

		m_Platform2 = new Polygon();
		m_Platform2->MakeRectangle(150, 20, true);
		m_Platform2->SetColor(Color::OrangeColor());
		m_Platform2->SetPosition(50, 350);

		m_Platform3 = new Polygon();
		m_Platform3->MakeRectangle(150, 20, true);
		m_Platform3->SetColor(Color::ForestGreenColor());
		m_Platform3->SetPosition(550, 600);
	}

	Game::~Game()
	{
		SafeDelete(m_Platform1);
		SafeDelete(m_Platform2);
		SafeDelete(m_Platform3);
	}

	void Game::Update(double aDelta)
	{
		m_Timer.Update(aDelta);

		Rotation rotation = Rotation::Radians((2.0f * M_PI) * m_Timer.GetPercentage());
		float radians = rotation.GetRadians();
		float x = radians * 140;
		float y = Math::CalculateSine(x, TRAVEL_DISTANCE, AMPLITUDE);

		m_Platform1->SetPosition(Vector2(500 + y, Y_AXIS));
		float radians2 = rotation.GetRadians();
		float x2 = radians * 140;
		float y2 = Math::CalculateSine(x2, TRAVEL_DISTANCE, AMPLITUDE);
		m_Platform2->SetPosition(Vector2(50, 350 + y2));

		
		float x3 = radians * 140;
		float y3 = Math::CalculateSine(x, TRAVEL_DISTANCE, AMPLITUDE);
		m_Platform3->SetPosition(Vector2(500 - y3, 650));
	}

	void Game::Draw()
	{
		m_Platform1->Draw();
		m_Platform2->Draw();
		m_Platform3->Draw();
	}

	void Game::HandleLeftMouseClick(float aMouseX, float aMouseY)
	{

	}

	void Game::HandleRightMouseClick(float aMouseX, float aMouseY)
	{

	}

	void Game::HandleMouseMove(float aMouseX, float aMouseY, float aPreviousX, float aPreviousY)
	{
		
	}

	void Game::HandleKeyPress(Keyboard::Key aKey)
	{

	}

	void Game::HandleKeyReleased(Keyboard::Key key)
	{

	}
}