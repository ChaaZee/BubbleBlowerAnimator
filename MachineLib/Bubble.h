/**
 * @file Bubble.h
 * @author Chaz Eden
 *
 *
 */
 
#ifndef BUBBLE_H
#define BUBBLE_H

#include <random>

#include "Polygon.h"

class BubbleBlower;

/**
 * Bubble class for the machine.
 */
class Bubble
{
private:
    /// Position of the Bubble
    wxPoint2DDouble mP;

    /// Velocity of the Bubble
    wxPoint2DDouble mV;

    /// The machine contain all the components
    BubbleBlower* mBubbleBlower = nullptr;

    /// Polygon that contains the shape and image for the bubble
    cse335::Polygon mPolygon;

public:
    Bubble(wxString imgDir);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);
    void Update(double delta);
    void SetImage(wxString imgDir);

    void setMp(const wxPoint2DDouble &MP);
    void setMv(const wxPoint2DDouble &MV);

    const wxPoint2DDouble &getMp() const;
    const wxPoint2DDouble &getMv() const;
};

#endif //BUBBLE_H
