/**
 * @file BubbleBlower.cpp
 * @author Chaz Eden
 */

#include "pch.h"
#include "BubbleBlower.h"
#include "Bubble.h"

/// Average amount of bubble created per rotation
const double BubblePerRotation = 10;

/// Variance in how much Bubble is created
const double BubbleVariancePerSecond = 100;

/// Angle range for the end of the Bubble machine in radians.
const double BubbleMachineAngleRange = 0.25;

/// Offset to end of Bubble blower from middle in pixels
const double BubbleBlowerOffset = 100;

/// Random variance in the Bubbleblower offset
const double BubbleBlowerOffsetVariance = 5;

/// Minimum Bubble particle velocity
const double BubbleMinimumXVelocity = 70;

/// Maximum Bubble particle velocity
const double BubbleMaximumXVelocity = 90;

/// Minimum Bubble particle velocity
const double BubbleMinimumYVelocity = -50;

/// Maximum Bubble particle velocity
const double BubbleMaximumYVelocity = 50;

///////////////////////////////////////

/// Constant epsilon
const double epsilon = 0.0001;

/// Radius of the Bubble
const double Radius = 50;

/**
 * Constructor for Bubble blower body
 * @param imageDir image directory used to story all the files
 */
BubbleBlower::BubbleBlower(wxString imageDir, bool blowLeft) : mImgDir(imageDir), mBlowLeft(blowLeft)
{
    std::random_device rd;	// Generates a random seed
    mRandom.seed(rd());		// Seed the random number generator
}

/**
 * Function that draw Bubble blower body on the screen
 * @param graphics The Graphics object we are drawing on
 * @param x x-coordinate
 * @param y y-coordinate
 */
void BubbleBlower::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{

//    graphics->PushState();

    for (auto bubble : mBubble)
    {
        bubble->Draw(graphics, x, y);
    }

//    graphics->PopState();

    Component::Draw(graphics, x, y);
}

/**
 * Rotate the Bubble blower body to a certain angle, and use the value of rotation
 * to determine amount of Bubble that should be generated.
 * @param rotation rotation value of the Bubble blower body
 */
void BubbleBlower::Rotate(double rotation)
{
    double diff = rotation - mRotation;
    mRotation = rotation;
    CalcRotate(diff);
}

/**
 * Calculate the amount of Bubble generated per second.
 * @param rotation rotation difference of the previous function
 */
void BubbleBlower::CalcRotate(double rotation)
{
    // Compute how much Bubble to generate for this amount of rotation.
    auto num = (int)(rotation * (BubblePerRotation + Random(-BubbleVariancePerSecond, BubbleVariancePerSecond)));

    // Reduce the amount of Bubble
    num /= 3;

    for (int i = 0; i < num; i++)
    {
        // This code computes a vector to the emitting end of the
        // Bubble machine. The random value means that position is over
        // the entire end of the machine, not just a single point.

        auto angle = GetRotation() * 2 * M_PI + Random(-BubbleMachineAngleRange, BubbleMachineAngleRange);
        auto dx = sin(angle);
        auto dy = -cos(angle);

        double offset = BubbleBlowerOffset + Random(-BubbleBlowerOffsetVariance, BubbleBlowerOffsetVariance);
        double velocityX = Random(BubbleMinimumXVelocity, BubbleMaximumXVelocity);
        double velocityY = Random(BubbleMinimumYVelocity, BubbleMaximumYVelocity);

        if (mBlowLeft){
            velocityX *= -1;
        }

        wxPoint2DDouble BubblePosition((float)(GetX()+dx * offset), (float)(GetY()+dy * offset));
        wxPoint2DDouble BubbleVelocity((float)(velocityX), (float)(velocityY));

        auto bubble = std::make_shared<Bubble>(mImgDir);
        bubble->SetImage(mImgDir);
        bubble->setMp(BubblePosition);
        bubble->setMv(BubbleVelocity);

        mBubble.push_back(bubble);
    }
}

/**
 * Update function to drive the Bubble moving forward
 * @param delta time difference
 */
void BubbleBlower::Update(double delta)
{
    for (auto bubble : mBubble)
    {
        if (bubble->getMp().m_y > 600)
        {

        }
        bubble->Update(delta);
    }
}

/**
 * Generate a uniform distribution random number from fmValue to toValue
 * \param fmValue Minimum value to generate
 * \param toValue Maximum value to generate
 * \return Random number
 */
double BubbleBlower::Random(double fmValue, double toValue)
{
    std::uniform_real_distribution<> distribution(fmValue, toValue);
    return distribution(mRandom);
}