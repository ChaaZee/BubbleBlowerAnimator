/**
 * @file Bubble.cpp
 * @author Chaz Eden
 */

#include "pch.h"
#include "Bubble.h"
#include "BubbleBlower.h"

/// Gravity in pixels per second per second
const float Gravity = 2;

/// Radius of the Bubble
const double BubbleRadius = 50;

/**
 * Bubble constructor, set default radius to 2
 */
Bubble::Bubble(wxString imgDir) : mP(0,0), mV(0,0)
{
    mPolygon.Circle(BubbleRadius);
}

/**
 * Draw Bubble on the screen
 * @param graphics The Graphics object we are drawing on
 * @param x x-coordinate
 * @param y y-coordinate
 */
void Bubble::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) {
    mPolygon.DrawPolygon(graphics, x + mP.m_x, y + mP.m_y);
}

/**
 * Advance function for the Bubble, allowing Bubble to progress forward
 * @param delta time difference
 */
void Bubble::Update(double delta) {
    // Gravity affects the y-component of velocity
    mV = wxPoint2DDouble(mV.m_x, mV.m_y + Gravity * delta);
    mP = wxPoint2DDouble(mP.m_x + mV.m_x * delta, mP.m_y + mV.m_y * delta);
}

void Bubble::SetImage(wxString imgDir)
{
    mPolygon.SetImage(imgDir + L"/bubble.png");
}

/**
 * Set position for the Bubble particles
 * @param MP position
 */
void Bubble::setMp(const wxPoint2DDouble &MP)
{
    mP = MP;
}

/**
 * Set velocity for the Bubble particles
 * @param MV velocity
 */
void Bubble::setMv(const wxPoint2DDouble &MV)
{
    mV = MV;
}

/**
 * Get position for the Bubble particles
 * @return position
 */
const wxPoint2DDouble &Bubble::getMp() const
{
    return mP;
}

/**
 * Set velocity for the Bubble particles
 * @return velocity
 */
const wxPoint2DDouble &Bubble::getMv() const
{
    return mV;
}
