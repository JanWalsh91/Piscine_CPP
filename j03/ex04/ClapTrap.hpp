#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>

class ClapTrap {

	private:
		static void	_initRand( void );
		static int	_randInit;

	protected:
		std::string _name;
		int _maxHitPoints;
		int _maxEnergyPoints;
		int _hitPoints;
		int _energyPoints;
		int _level;
		int _meleeDmg;
		int _rangedDmg;
		int _armor;
		ClapTrap( void );

	public:
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & ClapTrap );
		virtual ~ClapTrap( void );
		
		std::string getName( void );
		virtual void rangedAttack( std::string & target );
		virtual void meleeAttack( std::string & target );
		void takeDamage( unsigned int dmg );
		void beRepaired( unsigned int hitPoints );

		ClapTrap &    operator=( ClapTrap const & rhs );
};

#endif