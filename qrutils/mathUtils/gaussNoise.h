#pragma once

#include <QtCore/QtGlobal>

namespace mathUtils
{

qreal const mu = 0.5;
qreal const var = 0.083; // 1/12

class GaussNoise
{
public:
    GaussNoise();
    GaussNoise(unsigned int const approximationLevel, qreal const variance);
    ~GaussNoise();

    // Gauss noise generator. Uses Central Limit Thorem Method
    qreal generate(unsigned int const approximationLevel, qreal const variance);
    qreal generate();

    // Functions for working with properties
    void setApproximationLevel(unsigned int const approximationLevel);
    void setDispersion(qreal const variance);

    GaussNoise operator >> (qreal &left);

private:
    // Body of function 'generate'. Uses for various realizations of 'generate'
    qreal genBody(unsigned int const approximationLevel, qreal const variance);

    unsigned int mApproximationLevel;
    qreal mDispersion;
};

}
