#ifndef PARTICLE_H_
#define PARTICLE_H_

struct Particle {

	double m_x;
	double m_y;

	double speed;
    double direction;

public:
	Particle();
	virtual ~Particle();
	void update();
};

#endif /* PARTICLE_H_ */
