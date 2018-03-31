#ifndef I_MINING_LASER_H
# define I_MINING_LASER_H

class IAsteroid;

class IMiningLaser {

	public:
		virtual ~IMiningLaser( void ) {};
		virtual void mine( IAsteroid* ) = 0;
};

#endif