
#ifndef ENEMY_H
# define ENEMY_H

#include <string>

class Enemy
{
	private:
		std::string _Type;
		int _HP;
		Enemy();
	public:
		Enemy(int hp, std::string const & type);
		virtual ~Enemy();
		Enemy(const Enemy &copy);
		void 		operator = (const Enemy &s );
		std::string virtual getType() const;
		void virtual setType(std::string type);
		int getHP() const;
		void setHP(int hp);
		virtual void takeDamage(int damage);

};

#endif
