/**
 * @file BubbleBlower.h
 * @author Chaz Eden
 *
 *
 */
 
#ifndef BUBBLEBLOWER_H
#define BUBBLEBLOWER_H

#include "Component.h"
#include "IMotionSink.h"
#include <random>

class Bubble;

/**
 * BubbleBlowerBody class for the machine, derived from both Component and IMotionSink.
 */
class BubbleBlower : public Component, public IMotionSink
{
private:

    /// image directory
    wxString mImgDir;

    /// Bubbleblower for the machine
    std::vector<std::shared_ptr<Bubble>> mBubble;

    /// random variable used to generate random numbers
    std::mt19937 mRandom;

    /// Rotation for bubble blower
    double mRotation = 0.0;

    bool mBlowLeft = false;

public:
    BubbleBlower(wxString imageDir, bool blowLeft);

    /// Copy constructor (disabled)
    BubbleBlower(const BubbleBlower &) = delete;
    /// Assignment operator (disabled)
    void operator=(const BubbleBlower &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics,int x, int y) override;
    void Rotate(double rotation) override;
    void Update(double delta) override;

    void CalcRotate(double rotation);

    double Random(double fmValue, double toValue);

    /**
     * Get sink of the Bubble blower body
     * @return this
     */
    IMotionSink* GetSink() { return this; }
};

#endif //BUBBLEBLOWER_H
