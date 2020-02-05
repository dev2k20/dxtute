#pragma once

#include <Windows.h>
#include <d2d1.h>

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Init(HWND hWindow);

	void BeginDraw() { m_renderTarget->BeginDraw(); }
	void EndDraw()   { m_renderTarget->EndDraw(); }

	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);

private:
	ID2D1Factory*				m_factory;
	ID2D1HwndRenderTarget*		m_renderTarget;
	ID2D1SolidColorBrush*		m_brush;

};
