#include <QtCore/QTime>
#include <QtCore/QtGlobal>

#include "math.h"
#include "time.h"

#include "gaussNoise.h"

using namespace mathUtils;

GaussNoise::GaussNoise()
	: mApproximationLevel(defaultApproximationLevel)
	, mDispersion(defaultDispersion)
{
	qsrand(time(0));
}

GaussNoise::GaussNoise(unsigned int const approximationLevel, qreal const variance)
{
	qsrand(time(0));
	mApproximationLevel = approximationLevel;
	mDispersion = variance;
}

GaussNoise::~GaussNoise()
{
}

void GaussNoise::setApproximationLevel(unsigned int const approximationLevel)
{
	mApproximationLevel = approximationLevel;
}

void GaussNoise::setDispersion(qreal const variance)
{
	mDispersion = variance;
}

qreal GaussNoise::genBody(unsigned int const approximationLevel, qreal const variance)
{
	qreal x = 0.0;

	for (unsigned int i = 0; i < approximationLevel; ++i) {
		x += static_cast<qreal>(qrand()) / (RAND_MAX + 1);
	}

	x -= approximationLevel * mu;
	x *= sqrt(variance / approximationLevel * var);

	return x;
}

qreal GaussNoise::generate()
{
	return genBody(mApproximationLevel, mDispersion);
}

qreal GaussNoise::generate(unsigned int const approximationLevel, qreal const variance)
{
	return genBody(approximationLevel, variance);
}

GaussNoise GaussNoise::operator >> (qreal &left)
{
	left = this->generate();
	return *this;
}
