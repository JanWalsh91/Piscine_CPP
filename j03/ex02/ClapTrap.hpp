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
		ClapTrap( std::string name, int hitPoints, int energyPoints, int level, int meleeDmg, int rangedDmg, int armor );
		ClapTrap( ClapTrap const & ClapTrap );
		~ClapTrap( void );
		
		ClapTrap &    operator=( ClapTrap const & rhs );

		virtual void rangedAttack( std::string const & target ) const;
		virtual void meleeAttack( std::string const & target ) const;
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
};

#endif
