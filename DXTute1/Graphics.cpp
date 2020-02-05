#include "Graphics.h"

Graphics::Graphics() : m_factory(NULL), m_renderTarget(NULL), m_brush(NULL)
{
	
}

Graphics::~Graphics()
{
	if (m_factory) m_factory->Release();
	if (m_renderTarget) m_renderTarget->Release();
	if (m_brush) m_brush->Release();
}

bool Graphics::Init(HWND hWindow)
{
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_factory);
	if (res != S_OK) return(false);

	RECT rect;
	GetClientRect(hWindow, &rect);
	res = m_factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWindow, D2D1::SizeU(rect.right, rect.bottom)),
		&m_renderTarget);
	if (res != S_OK) return(false);

	res = m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 0), &m_brush);
	if (res != S_OK) return(false);

	return(true);
}

void Graphics::ClearScreen(float r, float g, float b)
{
	m_renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a)
{
	m_brush->SetColor(D2D1::ColorF(r, g, b, a));

	m_renderTarget->DrawEllipse(
		D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius),
		m_brush, 3.0f
	);
}
