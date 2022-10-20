// Videogame project 3.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <random>
#include <iomanip>
#include <string>
#include <sstream>
#pragma comment(lib, "winmm.lib")

using namespace std;


class Party
{
private:
	int strenght = 500, defense = 15, speed = 7, magic = 400, resistance = 15, luck = 5, curhp = 0, maxhp = 1050, maxmp = 330, curmp = 0, pmem, menuChoice = 0, skillChoice = 0;
	int damage = 0, usedMp;
	string name;
	bool alive = true;
	bool defend = false;
	bool invincible = false;
	bool def_down = false;
	int def_downc = 0, def_downam = 0, res_downam = 0;
	bool str_down = false;
	int str_downc = 0, str_downam = 0, magic_downam = 0;
	bool spd_down = false;
	int spd_downc = 0, spd_downam = 0;
	bool spd_up=false;
	int spd_upc = 0, spd_upam = 0;
	bool str_up = false;
	int str_upc = 0, str_upam = 0, magic_upam = 0;
	bool def_up = false;
	int def_upc = 0, def_upam = 0, res_upam = 0;
	bool aggro = false;
	
public:

	Party()
	{

	}
	Party(int hp, int mp, int strenght, int defense, int speed, int magic, int resistance, int luck, int name)
	{
		maxhp += hp;
		curhp = maxhp;
		maxmp += mp;
		curmp = maxmp;
		this->strenght += strenght;
		this->defense += defense;
		this->speed += speed;
		this->magic += magic;
		this->resistance += resistance;
		this->luck += luck;
		pmem = name;
		alive = true;
		damage = 0;

		if (name == 1)
		{
			this->name = "Marianne";

		}

		else if (name == 2)
		{
			this->name = "Lysithea";
		}

		else if (name == 3)
		{
			this->name = "Leonie";
		}

		else if (name == 4)
		{
			this->name = "Claude";
		}


	}


	string returnName()
	{
		return name;
	}

	void DisplayDstats()
	{
		cout << "Name: " << name << endl;
		cout << "HP: " << maxhp << endl;
		cout << "MP: " << maxmp << endl; 
		cout << "Strenght: " << strenght << endl;
		cout << "Defense: " << defense << endl;
		cout << "Speed: " << speed << endl;
		cout << "Magic: " << magic << endl;
		cout << "Resistance: " << resistance << endl;
		cout << "Luck: " << luck << endl;
		cout << endl;
	}

	void DisplayCstat()
	{
		cout << left << setw(9) << name <<setw(6)<< "   HP: " <<setw(4)<< maxhp << "/" <<setw(4)<< curhp <<setw(6)<< "   MP: " <<setw(4)<< curmp << "/" <<setw(4)<< maxmp << " ";
	}

	void setSkillChoice(int sk)
	{
		skillChoice = sk;
	}

	void takeDamage(int d)
	{
		curhp -= d;

		if (curhp <= 0)
		{
			curhp = 0;

			alive = false;

			Sleep(1000);
			cout << name << " has fallen!" << endl;
			Sleep(1000);

			if (def_up == true)
			{
				def_up = false;
				defense -= def_upam;
				resistance -= res_upam;
			}

			if (str_up == true)
			{
				str_up = false;
				strenght -= str_upam;
				magic -= magic_upam;
			}

			if (spd_up == true)
			{
				spd_up = false;
				speed -= spd_upam;
			}

			if (def_down == true)
			{
				def_down = false;
				defense += def_downam;
				resistance += res_downam;
			}

			if (str_down == true)
			{
				str_down = false;
				strenght += str_downam;
				magic += magic_downam;
			}

			if (spd_down == true)
			{
				spd_down = false;
				speed += spd_downam;
			}
			
		}
	}

	void recoverMp(int rec)
	{
		curmp += rec;

		if (curmp > maxmp)
		{
			rec -= (curmp - maxmp);
			curmp = maxmp;
		}
	}

	void recoverHp(int rec)
	{
		curhp += rec;


		if (curhp > maxhp)
		{
			rec -= (curhp - maxhp);
			curhp = maxhp;
			
		}

		cout << name << " recovers " << rec << " points of Hp!" << endl;
		Sleep(1000);
	}

	void recoverStats()
	{
		if (def_down == true)
		{
			def_down = false;
			defense += def_downam;
			resistance += res_downam;
		}
		
		if (str_down == true)
		{
			str_down = false;
			strenght += str_downam;
			magic += magic_downam;
		}
		
		if (spd_down == true)
		{
			spd_down = false;
			speed += spd_downam;
		}

		cout << name << " has returned to normal!" << endl;
		Sleep(1000);
	}

	void resetBuffs()
	{
		if (def_up == true)
		{
			def_up = false;
			defense -= def_upam;
			resistance -= res_upam;
		}

		if (str_up == true)
		{
			str_up = false;
			strenght -= str_upam;
			magic -= magic_upam;
		}

		if (spd_up == true)
		{
			spd_up = false;
			speed -= spd_upam;
		}

		if ((str_up == true) or (spd_up == true) or (def_up == true))
		{
			cout << name << " has lost all bonuses!" << endl;
			Sleep(1000);
		}

	}

	void Revive(bool safe)
	{
		if (safe == true)
		{
			alive = true;
			cout << name << " has come back to life!" << endl;
			Sleep(1000);
		}
	}

	void setAggro()
	{
		aggro = true;

		cout << name << " is attracting the enemy's attention!" << endl;
		Sleep(1000);
	}

	void resetAggro()
	{
		aggro = false;

		cout << name << " is no longer distracting the enemy!" << endl;
		Sleep(1000);
	}

	bool returnAggro()
	{
		return aggro;
	}

	void setInv()
	{
		invincible = true;

		cout << name << " has become invulnerable to all forms of damage!" << endl;
		Sleep(1000);
	}

	void resetInv()
	{
		invincible = false;

		cout << name << " is no longer invulnerable!" << endl;
		Sleep(1000);
	}

	void InvPierce()
	{
		invincible = false;
		cout << "The attack pierces through"<<name<<"'s invulnerability!" << endl;
		Sleep(1000);
	}

	void InvUnPierce()
	{
		invincible = true;
	}

	bool returnInv()
	{
		return invincible;
	}

	void setDefend()
	{
		defend = true;

		cout << name << " is defending!" << endl;


		Sleep(1000);
	}

	void resetDefend()
	{
		defend = false;

		cout << name << " has stopped defending!" << endl;

		Sleep(1000);
	}

	bool returnDefend()
	{
		return defend;
	}

	void setDefDown()
	{
		if (def_up == true)
		{
			defense -= def_upam;
			resistance -= res_upam;
			def_up = false;
			def_upc = 0;

			cout << name << "'s defenses have returned to normal!" << endl;
			Sleep(1000);
		}

		else
		{
			def_down = true;
			def_downc = 3;
			def_downam = (defense / 2);
			res_downam = (resistance / 2);
			defense -= def_downam;
			resistance -= res_upam;

			cout << name << " feels fragile!" << endl;
			Sleep(1000);
			cout << name << "'s defense has been lowered by " << def_downam << " points!" << endl;
			Sleep(1000);
			cout << name << "'s resistance has been lowered by " << res_downam << " points!" << endl;
			Sleep(1000);
		}

	}

	void reduceDefDownCounter()
	{
		def_downc -= 1;

		if (def_downc < 0)
		{
			def_down = false;
			defense += def_downam;
			resistance += res_downam;

			cout << name << "'s defenses have returned to normal!" << endl;

			Sleep(1000);
		}
	}

	bool returnDefDown()
	{
		return def_down;
	}

	void setStrDown()
	{

		if (str_up == true)
		{
			strenght -= str_upam;
			magic -= magic_upam;
			str_upc = 0;
			str_up = false;

			cout << name << "'s offenses have returned to normal!" << endl;
			Sleep(1000);
		}

		else
		{
			str_down = true;
			str_downc = 3;
			str_downam = strenght / 2;
			magic_downam = magic / 2;
			strenght -= str_downam;
			magic -= magic_downam;

			cout << name << " feels weaker!" << endl;
			Sleep(1000);
			cout << name << "'s strenght has been lowered by " << str_downam << " points!" << endl;
			Sleep(1000);
			cout << name << "'s magic has been lowered by " << magic_downam << " points!" << endl;
			Sleep(1000);
		}
	}

	void reduceStrDownCounter()
	{
		str_downc -= 1;

		if (str_downc < 0)
		{
			str_down = false;
			strenght += str_downam;
			magic += magic_downam;

			cout << name << "'s offenses have returned to normal!" << endl;

			Sleep(1000);
		}
	}

	bool returnStrDown()
	{
		return str_down;
	}

	void setSpdDown()
	{

		if (spd_up == true)
		{
			speed -= spd_upam;
			spd_upc = 0;
			spd_up = false;

			cout << name << "'s speed has returned to normal!" << endl;
			Sleep(1000);
		}

		else
		{
			spd_down = true;
			spd_downc = 3;
			spd_downam = speed / 2;
			speed -= spd_downam;
			
			cout << name << " feels slower!" << endl;
			Sleep(1000);
			cout << name << "'s speed has been lowered by " << spd_downam << " points!" << endl;
			Sleep(1000);
		}
	}

	void reduceSpdDownCounter()
	{
		spd_downc -= 1;

		if (spd_downc < 0)
		{
			spd_down = false;
			speed += spd_downam;

			cout << name << "'s speed has returned to normal!" << endl;

			Sleep(1000);
		}
	}

	bool returnSpdDown()
	{
		return spd_down;
	}

	void setDefUp()
	{
		if (def_down == true)
		{
			defense += def_downam;
			resistance += res_downam;
			def_downc = 0;
			def_down = false;

			cout << name << "'s defenses have returned to normal!" << endl;

			Sleep(1000);
		}

		else
		{
			def_up = true;
			def_upc = 3;
			def_upam = defense / 2;
			res_upam = resistance / 2;
			defense += def_upam;
			resistance += res_upam;

			cout << name << " feels sturdier!" << endl;
			Sleep(1000);
			cout << name << "'s defense has increased by " << def_upam << " points!" << endl;
			Sleep(1000);
			cout << name << "'s resistance has increased by " << res_upam << " points!" << endl;
			Sleep(1000);

		}
	}

	void reduceDefUpCounter()
	{
		def_upc -= 1;

		if (def_upc < 0)
		{
			def_up = false;
			defense -= def_upam;
			resistance -= res_upam;

			cout << name << "'s defenses have returned to normal!" << endl;

			Sleep(1000);
		}
	}

	bool returnDefenseUp()
	{
		return def_up;
	}

	void setStrUp()
	{
		if (str_down == true)
		{
			strenght += str_downam;
			magic += magic_downam;
			str_downc = 0;
			str_down = false;

			cout << name << "'s offenses have returned to normal!" << endl;

			Sleep(1000);
		}

		else
		{
			str_up = true;
			str_upc = 3;
			str_upam = strenght / 2;
			magic_upam = magic / 2;
			strenght += str_upam;
			magic += magic_upam;

			cout << name << " feels stronger!" << endl;
			cout << name << "'s strenght has increased by " << str_upam << " points!" << endl;
			Sleep(1000);
			cout << name << "'s magic has increased by " << magic_upam << " points!" << endl;
			Sleep(1000);

		}
	}

	void reduceStrUpCounter()
	{
		str_upc -= 1;

		if (str_upc < 0)
		{
			str_up = false;
			strenght -= str_upam;
			magic -= magic_upam;

			cout << name << "'s offenses have returned to normal!" << endl;

			Sleep(1000);
		}
	}

	bool returnStrUp()
	{
		return str_up;
	}

	void setSpdUp()
	{
		if (spd_down == true)
		{
			speed += spd_downam;
			spd_downc = 0;
			spd_down = false;

			cout << name << "'s speed has returned to normal!" << endl;

			Sleep(1000);
		}

		else
		{
			spd_up = true;
			spd_upc = 3;
			spd_upam = speed / 2;
			speed += spd_upam;

			cout << name << " feels faster" << endl;
			Sleep(1000);
			cout << name << "'s spd has increased by " << spd_upam << " points!" << endl;

			Sleep(1000);

		}
	}

	void reduceSpdUpCounter()
	{
		spd_upc -= 1;

		if (spd_upc < 0)
		{
			spd_up = false;
			speed -= spd_upam;

			cout << name << "'s speed has returned to normal!" << endl;

			Sleep(1000);
		}
	}

	void setUsedMp(int skllmp)
	{
		usedMp = skllmp;
	}

	int returnUsedMp()
	{
		return usedMp;
	}

	bool returnSpdUp()
	{
		return spd_up;
	}

	int returnSpeed()
	{
		return speed;
	}

	int returnIndicator()
	{
		return pmem;
	}

	bool returnStatus()
	{
		return alive;
	}

	int returnMenu()
	{
		return menuChoice;
	}

	int returnSkill()
	{
		return skillChoice;
	}

	int returnCurHp()
	{
		return curhp;
	}

	int returnMaxHp()
	{
		return maxhp;
	}

	int returnCurMp()
	{
		return curmp;
	}

	int returnMaxMp()
	{
		return maxmp;
	}

	bool returnFullHp()
	{
		if (maxhp - curhp == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int returnStr()
	{
		return strenght;
	}

	int returnDefense()
	{
		return defense;
	}

	int returnMagic()
	{
		return magic;
	}

	int returnRes()
	{
		return resistance;
	}

	int returnLuck()
	{
		return luck;
	}

	friend class Boss;

	void PlayerMenu();

	void PlayerSkills();

	void DisplayPlayerBD();
};

class Boss
{
private:
	int strenght, defense, speed, magic, resistance, luck, curhp, maxhp, maxmp, curmp, ind = 0, sk = 0;
	int damage = 0;
	int rage = 0;
	string name;
	bool alive = true;
	bool defend = false;
	bool invincible = false;
	bool actAgain = false;
	bool def_down = false;
	int def_downc = 0, def_downam = 0, res_downam = 0;
	bool str_down = false;
	int str_downc = 0, str_downam = 0, magic_downam = 0;
	bool spd_down = false;
	int spd_downc = 0, spd_downam = 0;
	bool spd_up = false;
	int spd_upc = 0, spd_upam = 0;
	bool str_up = false;
	int str_upc = 0, str_upam = 0, magic_upam = 0;
	bool def_up = false;
	int def_upc = 0, def_upam = 0, res_upam = 0;
	bool regen = false;
	bool iron_will = false;
	bool awakened = false;
	bool power_charge = false;


public:
	Boss()
	{
		strenght = 200;
		defense = 300;
		speed = 65;
		magic = 70;
		resistance = 300;
		luck = 35;
		maxhp = 150000;
		curhp = maxhp;
		ind = 0;
		name = "???";
		alive = true;
	}

	void DisplayHp()
	{
		cout << curhp << " / " << maxhp << endl;
	}

	void takeDamage(int d)
	{
		curhp -= d;

		if (curhp <= 0)
		{
			curhp = 0;

			alive = false;

		}
	}

	void recoverMp(int rec)
	{
		curmp += rec;

		if (curmp > maxmp)
		{
			rec -= (curmp - maxmp);
			curmp = maxmp;
		}
	}

	void recoverHp(int rec)
	{
		curhp += rec;


		if (curhp > maxhp)
		{
			rec -= (curhp - maxhp);
			curhp = maxhp;

		}

		cout << name << " recovers " << rec << " points of Hp!" << endl;
		Sleep(1000);
	}

	void recoverStats()
	{
		if (def_down == true)
		{
			def_down = false;
			defense += def_downam;
			resistance += res_downam;
		}

		if (str_down == true)
		{
			str_down = false;
			strenght += str_downam;
			magic += magic_downam;
		}
		
		if (spd_down == true)
		{
			spd_down = false;
			speed += spd_downam;
		}

		if (str_down == true or spd_down == true or def_down == true)
		{
			cout << name << " has returned to normal!" << endl;
			Sleep(1000);
		}

	}

	void resetBuffs()
	{
		if (str_up == true or spd_up == true or def_up == true)
		{
			cout << name << " has lost all bonuses!" << endl;
			Sleep(1000);
		}

		if (def_up == true)
		{
			def_up = false;
			defense -= def_upam;
			resistance -= res_upam;
		}
		
		if (str_up == true)
		{
			str_up = false;
			strenght -= str_upam;
			magic -= magic_upam;
		}

		if (spd_up == true)
		{
			spd_up = false;
			speed -= spd_upam;
		}

	}

	void IncreaseRage(int r)
	{
		if (r < 1)
		{
			r = 1;
		}

		else if (r > 100)
		{
			rage = 100;
		}

		rage += r;
	}

	void DecreaseRage(int re)
	{
		rage -= re;

		if (rage < 0)
		{
			rage = 0;
		}
	}

	int ReturnRage()
	{
		return rage;
	}

	void SetSkill(int s)
	{
		sk = s;
	}

	int ReturnSkill()
	{
		return sk;
	}

	void setInv()
	{
		invincible = true;

		cout << name << " has become invulnerable to all forms of damage!" << endl;
		Sleep(1000);
	}

	void resetInv()
	{
		invincible = false;

		cout << name << " is no longer invulnerable!" << endl;
		Sleep(1000);
	}

	void InvPierce()
	{
		invincible = false;
		cout << "The attack pierces through the enemy's invulnerability!" << endl;
		Sleep(1000);
	}

	void InvUnPierce()
	{
		invincible = true;
	}

	bool returnInv()
	{
		return invincible;
	}

	void setAct(bool act)
	{
		actAgain = act;

		if (act == true)
		{
			cout << name << " can act again!" << endl;
			Sleep(1000);
		}
		
	}

	bool returnAct()
	{
		return actAgain;
	}

	bool SubdueCheck(int d)
	{
		if ((curhp - d) < 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void setDefend()
	{
		defend = true;

		cout << name << " is defending!" << endl;


		Sleep(1000);
	}

	void resetDefend()
	{
		defend = false;

		cout << name << " has stopped defending!" << endl;

		Sleep(1000);
	}

	bool returnDefend()
	{
		return defend;
	}

	void setDefDown()
	{
		if (def_up == true)
		{
			defense -= def_upam;
			resistance -= res_upam;
			def_up = false;
			def_upc = 0;

			cout << name << "'s defenses have returned to normal!" << endl;
			Sleep(1000);
		}

		else
		{
			def_down = true;
			def_downc = 3;
			def_downam = (defense / 2);
			res_downam = (resistance / 2);
			defense -= def_downam;
			resistance -= res_upam;

			cout << name << " feels fragile" << endl;
			Sleep(1000);
			cout << name << "'s defense has been lowered by " << def_downam << " points!" << endl;
			Sleep(1000);
			cout << name << "'s resistance has been lowered by " << res_downam << " points!" << endl;
			Sleep(1000);
		}

	}

	void reduceDefDownCounter()
	{
		def_downc -= 1;

		if (def_downc < 0)
		{
			def_down = false;
			defense += def_downam;
			resistance += res_downam;

			cout << name << "'s defenses have returned to normal!" << endl;

			Sleep(1000);
		}
	}

	bool returnDefDown()
	{
		return def_down;
	}

	void setStrDown()
	{

		if (str_up == true)
		{
			strenght -= str_upam;
			magic -= magic_upam;
			str_upc = 0;
			str_up = false;

			cout << name << "'s offenses have returned to normal!" << endl;
			Sleep(1000);
		}

		else
		{
			str_down = true;
			str_downc = 3;
			str_downam = strenght / 2;
			magic_downam = magic / 2;
			strenght -= str_downam;
			magic -= magic_downam;

			cout << name << " feels weaker!" << endl;
			Sleep(1000);
			cout << name << "'s strenght has been lowered by " << str_downam << " points!" << endl;
			Sleep(1000);
			cout << name << "'s magic has been lowered by " << magic_downam << " points!" << endl;
			Sleep(1000);
		}
	}

	void reduceStrDownCounter()
	{
		str_downc -= 1;

		if (str_downc < 0)
		{
			str_down = false;
			strenght += str_downam;
			magic += magic_downam;

			cout << name << "'s offenses have returned to normal!" << endl;

			Sleep(1000);
		}
	}

	bool returnStrDown()
	{
		return str_down;
	}

	void setSpdDown()
	{

		if (spd_up == true)
		{
			speed -= spd_upam;
			spd_upc = 0;
			spd_up = false;

			cout << name << "'s speed has returned to normal!" << endl;
			Sleep(1000);
		}

		else
		{
			spd_down = true;
			spd_downc = 3;
			spd_downam = speed / 2;
			speed -= spd_downam;

			cout << name << " feels slower!" << endl;
			Sleep(1000);
			cout << name << "'s speed has been lowered by " << spd_downam << " points!" << endl;
			Sleep(1000);
		}
	}

	void reduceSpdDownCounter()
	{
		spd_downc -= 1;

		if (spd_downc < 0)
		{
			spd_down = false;
			speed += spd_downam;

			cout << name << "'s speed has returned to normal!" << endl;

			Sleep(1000);
		}
	}

	bool returnSpdDown()
	{
		return spd_down;
	}

	void setDefUp()
	{
		if (def_down == true)
		{
			defense += def_downam;
			resistance += res_downam;
			def_downc = 0;
			def_down = false;

			cout << name << "'s defenses have returned to normal!" << endl;

			Sleep(1000);
		}

		else
		{
			def_up = true;
			def_upc = 3;
			def_upam = defense / 2;
			res_upam = resistance / 2;
			defense += def_upam;
			resistance += res_upam;

			cout << name << " feels sturdier!" << endl;
			Sleep(1000);
			cout << name << "'s defense has increased by " << def_upam << " points!" << endl;
			Sleep(1000);
			cout << name << "'s resistance has increased by " << res_upam << " points!" << endl;
			Sleep(1000);

		}
	}

	void reduceDefUpCounter()
	{
		def_upc -= 1;

		if (def_upc < 0)
		{
			def_up = false;
			defense -= def_upam;
			resistance -= res_upam;

			cout << name << "'s defenses have returned to normal!" << endl;

			Sleep(1000);
		}
	}

	bool returnDefenseUp()
	{
		return def_up;
	}

	void setStrUp()
	{
		if (str_down == true)
		{
			strenght += str_downam;
			magic += magic_downam;
			str_downc = 0;
			str_down = false;

			cout << name << "'s offenses have returned to normal!" << endl;

			Sleep(1000);
		}

		else
		{
			str_up = true;
			str_upc = 3;
			str_upam = strenght / 2;
			magic_upam = magic / 2;
			strenght += str_upam;
			magic += magic_upam;

			cout << name << " feels stronger!" << endl;
			Sleep(1000);
			cout << name << "'s strenght has increased by " << str_upam << " points!" << endl;
			Sleep(1000);
			cout << name << "'s magic has increased by " << magic_upam << " points!" << endl;
			Sleep(1000);

		}
	}

	void reduceStrUpCounter()
	{
		str_upc -= 1;

		if (str_upc < 0)
		{
			str_up = false;
			strenght -= str_upam;
			magic -= magic_upam;

			cout << name << "'s offenses have returned to normal!" << endl;

			Sleep(1000);
		}
	}

	bool returnStrUp()
	{
		return str_up;
	}

	void setSpdUp()
	{
		if (spd_down == true)
		{
			speed += spd_downam;
			spd_downc = 0;
			spd_down = false;

			cout << name << "'s speed has returned to normal!" << endl;

			Sleep(1000);
		}

		else
		{
			spd_up = true;
			spd_upc = 3;
			spd_upam = speed / 2;
			speed += spd_upam;

			cout << name << " feels faster!" << endl;
			Sleep(1000);
			cout << name << "'s spd has increased by " << spd_upam << " points!" << endl;

			Sleep(1000);

		}
	}

	void reduceSpdUpCounter()
	{
		spd_upc -= 1;

		if (spd_upc < 0)
		{
			spd_up = false;
			speed -= spd_upam;

			cout << name << "'s speed has returned to normal!" << endl;

			Sleep(1000);
		}
	}

	bool returnSpdUp()
	{
		return spd_up;
	}

	int returnSpeed()
	{
		return speed;
	}

	int returnIndicator()
	{
		return ind;
	}

	bool returnStatus()
	{
		return alive;
	}

	int returnSkill()
	{
		return sk;
	}

	string returnName()
	{
		return name;
	}

	int returnCurHp()
	{
		return curhp;
	}

	int returnMaxHp()
	{
		return maxhp;
	}

	int returnCurMp()
	{
		return curmp;
	}

	int returnMaxMp()
	{
		return maxmp;
	}

	int returnStr()
	{
		return strenght;
	}

	int returnDefense()
	{
		return defense;
	}

	int returnMagic()
	{
		return magic;
	}

	int returnRes()
	{
		return resistance;
	}

	int returnLuck()
	{
		return luck;
	}

	void setRegen()
	{
		regen = true;
		cout << name << " will now regenrate some hp every turn!" << endl;
		Sleep(1000);
	}

	bool returnRegen()
	{
		return regen;
	}

	void setIron_will()
	{
		iron_will = true;
		cout << name << " will now take reduced damage!!" << endl;
		Sleep(1000);
	}

	bool returnIronWill()
	{
		return iron_will;
	}

	void setAwakening()
	{
		awakened = true;
		cout << name << " has awakened to their full potential!!!" << endl;
		Sleep(1000);
		cout <<"They will now perform two actions per turn and their stats have increased!" << endl;
		Sleep(1000);
		strenght += 15;
		defense += 15;
		speed += 15;
		magic += 15;
		resistance += 15;
		luck += 15;
	}

	bool returnAwakened()
	{
		return awakened;
	}

	void setPower_charge()
	{
		power_charge = true;
		cout << name << " is focused!" << endl;
		Sleep(1000);
	}

	bool returnPower_charge()
	{
		return power_charge;
	}

	void resetPower_charge()
	{
		power_charge = false;
		cout << name << " is no longer focused!" << endl;
		Sleep(1000);
	}
	
	void DisplayBossBD();

};

class TurnOrder
{
private:
	int speed, tind;

public:
	TurnOrder()
	{
		speed = 0;
		tind = 0;
	}

	void setSpeed(int speed)
	{
		this->speed = speed;
	}

	void setTurnIndicator(int indicator)
	{
		tind = indicator;
	}

	int returnSpeed()
	{
		return speed;
	}

	int returnTurnIndicator()
	{
		return tind;
	}
};

void Display(Boss H, Party mem1, Party mem2, Party mem3, Party mem4);
void charSelection(int c, int& h, int& m, int& str, int& def, int& spd, int& mag, int& res, int& lu);
void setIndicator(Party mem1, Party mem2, Party mem3, Party mem4, Boss HQD, TurnOrder[]);
void setSpeed(Party mem1, Party mem2, Party mem3, Party mem4, Boss HQD, TurnOrder[]);
void sortTurn(TurnOrder[]);
void PlayerTurn(Boss& target, Party& attacker, Party& sup1, Party& sup2, Party& sup3);
void UseMarianneSkills(Boss& target, Party& attacker, Party& sup1, Party& sup2, Party& sup3);
void UseLysitheaSkills(Boss& target, Party& attacker, Party& sup1, Party& sup2, Party& sup3);
void UseLeonieSkills(Boss& target, Party& attacker, Party& sup1, Party& sup2, Party& sup3);
void UseClaudeSkills(Boss& target, Party& attacker, Party& sup1, Party& sup2, Party& sup3);
void AttackCheck(Boss& target, int dmg, int hit, int avoid, int crtc, int crta, int chara);
void BAttackCheck(Party* target, int dmg, int hit, int avoid, int crtc, int crta);
void AvoAndCritAvoSet(Party* target, int& critavo, int& avo, int skill);
void BossTurn(Boss& agresor, Party& receiver1, Party& receiver2, Party& receiver3, Party& receiver4);
void ReducePCounter(Party& target);
void ReduceBCounter(Boss& target);
int NumCheck();
bool PlayerUHCheck(Party& target, string search);
bool PlayerUHACheck(Party& target, string search);
bool PlayerHCheck(Party &target, Party &User, string search);
bool PlayerLCheck(Party* target, string search);
bool BossLCheck(Boss& target, string search);
bool BossHCheck(Boss& target, string search);
bool IsTargetAlive(Party receiver1, Party receiver2, Party receiver3, Party receiver4, int target);
bool IsTargetAggro(Party receiver1, Party receiver2, Party receiver3, Party receiver4, int& t);
Party* Ctarget(Party& receiver1, Party& receiver2, Party& receiver3, Party& receiver4);

void Boss::DisplayBossBD()
{

	if (str_up == true)
	{
		cout << "STR^";
		cout << " ";
	}

	else if (str_down == true)
	{
		cout << "STRv";
		cout << " ";
	}

	if (def_up == true)
	{
		cout << "DEF^";
		cout << " ";
	}

	else if (def_down == true)
	{
		cout << "DEFv";
		cout << " ";
	}

	if (spd_up == true)
	{
		cout << "SPD^";
		cout << " ";
	}

	else if (spd_down == true)
	{
		cout << "SPDv";
		cout << " ";
	}

	if (invincible == true)
	{
		cout << "INV";
	}

}

void Party::DisplayPlayerBD()
{
	if (alive == false)
	{
		return;
	}

	if (str_up == true)
	{
		cout << "STR^";
		cout << " ";
	}

	else if (str_down == true)
	{
		cout << "STRv";
		cout << " ";
	}

	if (def_up == true)
	{
		cout << "DEF^";
		cout << " ";
	}

	else if (def_down == true)
	{
		cout << "DEFv";
		cout << " ";
	}

	if (spd_up == true)
	{
		cout << "SPD^";
		cout << " ";
	}

	else if (spd_down == true)
	{
		cout << "SPDv";
		cout << " ";
	}

	if (invincible == true)
	{
		cout << "INV";
	}

}

void Party::PlayerMenu()
{
	skillChoice = 0;
	menuChoice = 0;
	bool choicepass = false;
	cout << name << " ";
	DisplayPlayerBD();
	cout << endl;
	cout << "1.Attack  2.Skills  3.Defend  4.Escape" << endl;

	while (choicepass == false)
	{
		try
		{
			
			menuChoice = NumCheck();

			if (menuChoice != 1 and menuChoice != 2 and menuChoice != 3 and menuChoice != 4)
			{
				throw 1;
			}
			else
			{
				choicepass = true;
			}
		}
		catch (int)
		{
			cout << "Invalid input" << endl;
		}

	}

}

void Party::PlayerSkills()
{
	bool choicepass = false;
	string skillChoicePass;

	if (pmem == 1)
	{
		cout << "1.Heal. A spell that moderately restore's an ally's Hp. 10 mp" << endl;
		cout << "2.Fimbulvetr. Advanced ice magic that deals heavy magical damage to an enemy and reduces their offense for 3 turns. 30 mp" << endl;
		cout << "3.Soulblade. Advanced sword technique that embodies the user's will unto a powerful slash that deals severe magical damage to an enemy and is capable of partially piercing enemy defenses. 40 mp" << endl;
		cout << "4.Restore. A spell that removes all status reductions to all allies. 10 mp" << endl;
		cout << "5.All-Mighty Blow. Unique brawling technique that delivers a devastating blow that deals devastating damage to an enemy, is uncappable of missing and ignores damage reduction. 35 mp" << endl;
		cout << "6.Beast Fang. Advanced sword technique unique to Blutang that utilizes the user's physical and magical might to perform a fierce 3-slash combo that deals extreme damage while ignoring the enemy's defenses and reduces all of their attributes for 3 turns. 100 mp" << endl;
		cout << "7.Back" << endl;
		
		while (choicepass == false)
		{
			try
			{
				skillChoice = NumCheck();

				if (skillChoice != 1 and skillChoice != 2 and skillChoice != 3 and skillChoice != 4 and skillChoice != 5 and skillChoice != 6 and skillChoice != 7)
				{
					throw 1;
				}
				else
				{
					choicepass = true;
				}
				
				
			}
			catch (int)
			{
				cout << "Invalid input" << endl;
			}
		}

		if (skillChoice == 1)
		{
			if (curmp >= 10)
			{
				curmp -= 10;

				usedMp = 10;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 2)
		{
			if (curmp >= 30)
			{
				curmp -= 30;

				usedMp = 30;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 3)
		{
			if (curmp >= 40)
			{
				curmp -= 40;

				usedMp = 40;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 4)
		{
			if (curmp >= 10)
			{
				curmp -= 10;

				usedMp = 10;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 5)
		{
			if (curmp >= 35)
			{
				curmp -= 35;

				usedMp = 35;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 6)
		{
			if (curmp >= 100)
			{
				curmp -= 100;

				usedMp = 100;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

	}

	if (pmem == 2)
	{
		cout << "1.Rally Offense. Increases an ally's magical and physical might for 3 turns. 10mp" << endl;
		cout << "2.Luna. Advanced dark magic that pierces the enemy's resistance and deals moderate damage. 25 mp" << endl;
		cout << "3.Fortify. Advanced light magic that moderately restores Hp to all allies. 35 mp" << endl;
		cout << "4.Resurrection. Forbidden light magic only usable by scions of the goddess capable of bringing an ally back from the dead. 70 mp" << endl;
		cout << "5.Hades ��. Ultimate dark magic that unleashes the darkness of the underworld to deal extreme damage to an enemy and removing any positive effects to stats. 50 mp" << endl;
		cout << "6.Banshee ��. Advanced dark magic that restrains the enemy's advance, dealing heavy damage and reducing their speed for 3 turns. 30 mp" << endl;
		cout << "7.Back" << endl;

		while (choicepass == false)
		{
			try
			{
				skillChoice = NumCheck();

				if (skillChoice != 1 and skillChoice != 2 and skillChoice != 3 and skillChoice != 4 and skillChoice != 5 and skillChoice != 6 and skillChoice != 7)
				{
					throw 1;
				}
				else
				{
					choicepass = true;
				}


			}
			catch (int)
			{
				cout << "Invalid input" << endl;
			}
		}

		if (skillChoice == 1)
		{
			if (curmp >= 10)
			{
				curmp -= 10;

				usedMp = 10;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 2)
		{
			if (curmp >= 25)
			{
				curmp -= 25;

				usedMp = 25;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 3)
		{
			if (curmp >= 35)
			{
				curmp -= 35;

				usedMp = 35;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 4)
		{
			if (curmp >= 70)
			{
				curmp -= 70;

				usedMp = 70;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 5)
		{
			if (curmp >= 50)
			{
				curmp -= 50;

				usedMp = 50;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 6)
		{
			if (curmp >= 30)
			{
				curmp -= 30;

				usedMp = 30;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

	}

	if (pmem == 3)
	{
		cout << "1.Rally Defense. Increases and ally's physical and magical defense for 3 turns. 10 mp" << endl;
		cout << "2.Shatter Slash. Advanced lance technique that unleashes a armor-crushing slash that deals heavy damage to an enemy and reduces their defenses for 3 turns. 30 mp"<< endl;
		cout << "3.Vengeance. Crafty lance technique that unleashes untold fury upon the enemy, dealing damage proportional to the Hp lost by the user. 25 mp" << endl;
		cout << "4.Heavy Draw. Advanced bow technique that unleashes a powerful but inaccuarate shot that deals extreme damage to the enemy it it lands. 35mp" << endl;
		cout << "5.Shield Bash. Leonie's signature technique that delivers a powerful shield strike dealing normal damage to an enemy and allowing the user to defend until their next turn and force them to target her for 1 turn, even if it misses. 20 mp" << endl;
		cout << "6.Arrow Rain. Bow technique unique to the Inexhaustible that unleashes a barrage against all enemies, dealing 4 shots of moderate damage and high critical chance. 80 mp" << endl;
		cout << "7.Back" << endl;

		while (choicepass == false)
		{
			try
			{
				skillChoice = NumCheck();

				if (skillChoice != 1 and skillChoice != 2 and skillChoice != 3 and skillChoice != 4 and skillChoice != 5 and skillChoice != 6 and skillChoice != 7)
				{
					throw 1;
				}
				else
				{
					choicepass = true;
				}


			}
			catch (int)
			{
				cout << "Invalid input" << endl;
			}
		}

		if (skillChoice == 1)
		{
			if (curmp >= 10)
			{
				curmp -= 10;

				usedMp = 10;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 2)
		{
			if (curmp >= 30)
			{
				curmp -= 30;

				usedMp = 30;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 3)
		{
			if (curmp >= 25)
			{
				curmp -= 25;

				usedMp = 25;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 4)
		{
			if (curmp >= 35)
			{
				curmp -= 35;

				usedMp = 35;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 5)
		{
			if (curmp >= 20)
			{
				curmp -= 20;

				usedMp = 20;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 6)
		{
			if (curmp >= 80)
			{
				curmp -= 80;

				usedMp = 80;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

	}

	if (pmem == 4)
	{
		cout << "1.Rally Speed. Boosts an ally's speed for 3 turns. 10 mp" << endl;
		cout << "2.Windsweep. Advanced sword technique that unleashes a lightning fast sweep that deals damage based on the user's speed and cannot miss. 30 mp" << endl;
		cout << "3.Subdue. Sword technique unique to highborn individuals that delivers a devastating downward slash, dealing damage proportional to the enemy's Hp. 45 mp" << endl;
		cout << "4.Deadeye. Advanced bow technique that delivers an incredibly accurate shot that cannot miss and deals moderate damage with a high chance of critical to an enemy. 50 mp" << endl;
		cout << "5.Wind God. Claude's signature technique that delivers a powerful curved shot straight to the enemy's vitals, dealing heavy damage that pierces defenses and has an increased critical chance based on the user's speed. 70 mp" << endl;
		cout << "6.Fallen Star. Bow techinque unique to Failnaught that unleashes a shot to the heavens that comes crashing down onto the enemy with the fury of the stars, dealing extreme damage, while increasing all of the user's attributes for 3 turns and negating damage until their next turn. 140 mp" << endl;
		cout << "7.Back" << endl;

		while (choicepass == false)
		{
			try
			{
				skillChoice = NumCheck();

				if (skillChoice != 1 and skillChoice != 2 and skillChoice != 3 and skillChoice != 4 and skillChoice != 5 and skillChoice != 6 and skillChoice != 7)
				{
					throw 1;
				}
				else
				{
					choicepass = true;
				}

			}
			catch (int)
			{
				cout << "Invalid input" << endl;
			}
		}

		if (skillChoice == 1)
		{
			if (curmp >= 10)
			{
				curmp -= 10;

				usedMp = 10;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 2)
		{
			if (curmp >= 30)
			{
				curmp -= 30;

				usedMp = 30;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 3)
		{
			if (curmp >= 45)
			{
				curmp -= 45;

				usedMp = 45;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 4)
		{
			if (curmp >= 50)
			{
				curmp -= 50;

				usedMp = 50;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 5)
		{
			if (curmp >= 70)
			{
				curmp -= 70;

				usedMp = 70;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

		else if (skillChoice == 6)
		{
			if (curmp >= 140)
			{
				curmp -= 140;

				usedMp = 140;
			}

			else
			{
				Sleep(1000);
				cout << "Not enough Mp!" << endl;
				Sleep(1000);
				skillChoice = 7;
			}
		}

	}
}

int main()
{
	int hp, mp, strenght, defense, speed, magic, resistance, luck;
	Boss Hilda;
	bool start = true;

	charSelection(1, hp, mp, strenght, defense, speed, magic, resistance, luck);

	Party Marianne(hp, mp, strenght, defense, speed, magic, resistance, luck, 1);

	charSelection(2, hp, mp, strenght, defense, speed, magic, resistance, luck);

	Party Lysithea(hp, mp, strenght, defense, speed, magic, resistance, luck, 2);

	charSelection(3, hp, mp, strenght, defense, speed, magic, resistance, luck);

	Party Leonie(hp, mp, strenght, defense, speed, magic, resistance, luck, 3);

	charSelection(4, hp, mp, strenght, defense, speed, magic, resistance, luck);

	Party Claude(hp, mp, strenght, defense, speed, magic, resistance, luck, 4);

	cout << "Party: " << endl;
	Sleep(1000);
	Marianne.DisplayDstats();
	Sleep(1000);
	Lysithea.DisplayDstats();
	Sleep(1000);
	Leonie.DisplayDstats();
	Sleep(1000);
	Claude.DisplayDstats();
	Sleep(1000);

	cout << "NOTE: Defending recovers 20 mp and Normal Attacks recover 10 mp" << endl;

	system("pause");

	TurnOrder battle[5];
	

	do
	{
		system("cls");

		if (start)
		{
			PlaySound(TEXT("battle.wav"), NULL, SND_LOOP | SND_ASYNC);
			start = false;
		}
		
		Display(Hilda, Marianne, Lysithea, Leonie, Claude);
		if (Hilda.returnCurHp() <= (int)(Hilda.returnMaxHp()*.75) and Hilda.returnRegen()==false)
		{
			cout << "'Ouch!" << endl;
			Sleep(2000);
			cout << "'I forgot who am I dealing with here'" << endl;
			Sleep(2000);
			cout << "'Guess I should even the odds a little bit'" << endl;
			Sleep(2000);
			Hilda.setRegen();
			system("cls");
			Display(Hilda, Marianne, Lysithea, Leonie, Claude);
		}

		setIndicator(Marianne, Lysithea, Leonie, Claude, Hilda, battle);
		setSpeed(Marianne, Lysithea, Leonie, Claude, Hilda, battle);
		sortTurn(battle);
		Sleep(1000);

		for (int count = 0; count <= 4; count++)
		{

			if (!Hilda.returnStatus())
			{
				break;
			}

			else if (battle[count].returnTurnIndicator() == Hilda.returnIndicator())
			{
				ReduceBCounter(Hilda);
				system("cls");
				do
				{
					Display(Hilda, Marianne, Lysithea, Leonie, Claude);
					BossTurn(Hilda, Marianne, Lysithea, Leonie, Claude);
					system("cls");

					if (Hilda.returnAct() == true)
					{
						Hilda.setAct(false);
						continue;
					}
					else if (Hilda.returnAct() == false)
					{
						break;
					}

				} while (true);
				Display(Hilda, Marianne, Lysithea, Leonie, Claude);
			}

			else if (battle[count].returnTurnIndicator() == Marianne.returnIndicator() and Marianne.returnStatus()==true)
			{
				ReducePCounter(Marianne);
				do
				{
					system("cls");
					Display(Hilda, Marianne, Lysithea, Leonie, Claude);
					Marianne.PlayerMenu();
					system("cls");
					Display(Hilda, Marianne, Lysithea, Leonie, Claude);

					if (Marianne.returnMenu() == 2)
					{
						Marianne.PlayerSkills();
					}

					Sleep(1000);

					PlayerTurn(Hilda, Marianne, Lysithea, Leonie, Claude);
					
				} while (Marianne.returnSkill() == 7);

				system("cls");
				Display(Hilda, Marianne, Lysithea, Leonie, Claude);

			}

			else if (battle[count].returnTurnIndicator() == Lysithea.returnIndicator() and Lysithea.returnStatus() == true)
			{
				ReducePCounter(Lysithea);
				do
				{
					system("cls");
					Display(Hilda, Marianne, Lysithea, Leonie, Claude);
					Lysithea.PlayerMenu();
					system("cls");
					Display(Hilda, Marianne, Lysithea, Leonie, Claude);

					if (Lysithea.returnMenu() == 2)
					{
						Lysithea.PlayerSkills();
					}

					Sleep(1000);

					PlayerTurn(Hilda, Lysithea, Marianne, Leonie, Claude);

				} while (Lysithea.returnSkill() == 7);

				
				system("cls");
				Display(Hilda, Marianne, Lysithea, Leonie, Claude);

			}

			else if (battle[count].returnTurnIndicator() == Leonie.returnIndicator() and Leonie.returnStatus() == true)
			{
				ReducePCounter(Leonie);
				do
				{
					system("cls");
					Display(Hilda, Marianne, Lysithea, Leonie, Claude);
					Leonie.PlayerMenu();
					system("cls");
					Display(Hilda, Marianne, Lysithea, Leonie, Claude);

					if (Leonie.returnMenu() == 2)
					{
						Leonie.PlayerSkills();
					}

					Sleep(1000);

					PlayerTurn(Hilda, Leonie, Marianne, Lysithea, Claude);

				} while (Leonie.returnSkill() == 7);

				
				system("cls");
				Display(Hilda, Marianne, Lysithea, Leonie, Claude);

			}

			else if (battle[count].returnTurnIndicator() == Claude.returnIndicator() and Claude.returnStatus() == true)
			{
				ReducePCounter(Claude);
				do
				{
					system("cls");
					Display(Hilda, Marianne, Lysithea, Leonie, Claude);
					Claude.PlayerMenu();
					system("cls");
					Display(Hilda, Marianne, Lysithea, Leonie, Claude);

					if (Claude.returnMenu() == 2)
					{
						Claude.PlayerSkills();
					}

					Sleep(1000);

					PlayerTurn(Hilda, Claude, Marianne, Lysithea, Leonie);

				} while (Claude.returnSkill() == 7);

				
				system("cls");
				Display(Hilda, Marianne, Lysithea, Leonie, Claude);

			}
		}

		if (!Hilda.returnStatus())
		{
			break;
		}
		
		cout << "This marks the end of a round" << endl;
		Sleep(1000);

	} while (Hilda.returnStatus() and (Marianne.returnStatus() or Lysithea.returnStatus() or Leonie.returnStatus() or Claude.returnStatus()));

	system("cls");
	Display(Hilda, Marianne, Lysithea, Leonie, Claude);

	PlaySound(NULL, NULL, SND_LOOP | SND_ASYNC);

	if (!Marianne.returnStatus() and !Lysithea.returnStatus() and !Leonie.returnStatus() and !Claude.returnStatus())
	{
		cout << "The party has been defeated!" << endl;
		Sleep(1000);
		system("cls");
		Display(Hilda, Marianne, Lysithea, Leonie, Claude);
		cout << "'I suppose this it'" << endl;
		Sleep(2000);
		cout << "'So long have you been a torn at my side'" << endl;
		Sleep(2000);
		cout << "'But that ends now!'" << endl;
		Sleep(2000);
		cout << "The misterious figure shouts angrily as it swings its axe to put you out of your misery" << endl;
		Sleep(2000);
		cout << "As the swing is about to connect you catch a glimpse of the assailants face, its hair a light pink you used to know so well" << endl;
		Sleep(2000);
		cout << "'Hi....l..da...'" << endl;
		Sleep(2000);
		cout << "Just as the words escape you, the blow connects and the world turns black" << endl;
		Sleep(2000);
		cout << "leaving you wondering where it all went wrong..." << endl;
		Sleep(2000);
		cout << "GAME OVER" << endl;
		system("pause");
	
	}
	else
	{
		cout << "The enemy has been defeated!" << endl;
		Sleep(1000);
		system("cls");
		Display(Hilda, Marianne, Lysithea, Leonie, Claude);
		cout << "As you deal the finishing blow, the assilant is finally knocked down" << endl;
		Sleep(2000);
		cout << "You and the others decide to get closer and confirm their victory. however as you approach the body you are startled by the lifeless face staring back at you" << endl;
		Sleep(2000);
		cout << "After all it is a face you very well" << endl;
		Sleep(2000);
		cout << "'Hilda.........why.......?'" << endl;
		Sleep(2000);
		cout << "As the realization finally hits you, you feel the tears rush out as you let out a bloodcurling scream full of despair" << endl;
		Sleep(2000);
		cout << "After what seems from an eternity you gaze at the horizon, your dead eyes scorning the result of this wretched fairy tail" << endl;
		Sleep(2000);
		cout << "Was there really no other way?" << endl;
		Sleep(2000);
		cout << "Victory....?" << endl;
		system("pause");
		
	}


	return 0;


}

int NumCheck()
{
	string numi;
	int numf;
	try
	{
		cout << "Your Choice: ";
		getline(cin, numi);

			for (int count = 0; count < numi.length(); count++)
			{
				if (numi[count] == '.')
				{
					for (int c = count + 1; c < numi.length(); c++)
					{
						if (numi[c] != '0')
						{
							throw 1;
						}
					}
				}

				else if (!isdigit(numi[count]))
				{
					throw 1;
				}
			}

			stringstream nums(numi);

			nums >> numf;

			return numf;
		
	}
	catch (int)
	{
		return -1;
	}
}

void charSelection(int c, int& h, int& m, int& str, int& def, int& spd, int& mag, int& res, int& lu)
{
	if (c == 1)
	{
		h = 300;
		m = 300;
		str = 70;
		def = 45;
		spd = 70;
		mag = 80;
		res = 55;
		lu = 35;
	}

	else if (c == 2)
	{
		h = 120;
		m = 450;
		str = 25;
		def = 25;
		spd = 45;
		mag = 150;
		res = 70;
		lu = 25;
	}

	else if (c == 3)
	{
		h = 300;
		m = 200;
		str = 65;
		def = 70;
		spd = 40;
		mag = 15;
		res = 25;
		lu = 25;
	}

	else if (c == 4)
	{
		h = 200;
		m = 300;
		str = 50;
		def = 55;
		spd = 85;
		mag = 25;
		res = 40;
		lu = 75;
	}
}

void setIndicator(Party mem1, Party mem2, Party mem3, Party mem4, Boss HQD, TurnOrder in[])
{
	in[0].setTurnIndicator(HQD.returnIndicator());
	in[1].setTurnIndicator(mem1.returnIndicator());
	in[2].setTurnIndicator(mem2.returnIndicator());
	in[3].setTurnIndicator(mem3.returnIndicator());
	in[4].setTurnIndicator(mem4.returnIndicator());
}

void setSpeed(Party mem1, Party mem2, Party mem3, Party mem4, Boss HQD, TurnOrder b[])
{

	b[0].setSpeed(HQD.returnSpeed());
	b[1].setSpeed(mem1.returnSpeed());
	b[2].setSpeed(mem2.returnSpeed());
	b[3].setSpeed(mem3.returnSpeed());
	b[4].setSpeed(mem4.returnSpeed());


}

void sortTurn(TurnOrder round[])
{
	int startScan, minIndex, size=5;

	TurnOrder minTurn;

	for(startScan=0; startScan<(size-1); startScan++)
	{
		minIndex = startScan;
		minTurn.setSpeed(round[startScan].returnSpeed());
		minTurn.setTurnIndicator(round[startScan].returnTurnIndicator());

		for (int index = startScan + 1; index < size; index++)
		{
			if(round[index].returnSpeed() > minTurn.returnSpeed())
			{
				minTurn.setSpeed(round[index].returnSpeed());
				minTurn.setTurnIndicator(round[index].returnTurnIndicator());
				minIndex = index;
			}
		}

		round[minIndex].setSpeed(round[startScan].returnSpeed());
		round[minIndex].setTurnIndicator(round[startScan].returnTurnIndicator());
		round[startScan].setSpeed(minTurn.returnSpeed());
		round[startScan].setTurnIndicator(minTurn.returnTurnIndicator());
	}
}

void ReducePCounter(Party& target)
{
	if (target.returnAggro()==true)
	{
		target.resetAggro();
	}

	if (target.returnInv() == true)
	{
		target.resetInv();
	}

	if (target.returnDefend() == true)
	{
		target.resetDefend();
	}

	if (target.returnDefDown() == true)
	{
		target.reduceDefDownCounter();
	}

	if (target.returnStrDown() == true)
	{
		target.reduceStrDownCounter();
	}

	if (target.returnSpdDown() == true)
	{
		target.reduceSpdDownCounter();
	}

	if (target.returnDefenseUp() == true)
	{
		target.reduceDefUpCounter();
	}

	if (target.returnStrUp() == true)
	{
		target.reduceStrUpCounter();
	}

	if (target.returnSpdUp() == true)
	{
		target.reduceSpdUpCounter();
	}
}

void ReduceBCounter(Boss& target)
{
	if (target.returnInv() == true)
	{
		target.resetInv();
	}

	if (target.returnDefend() == true)
	{
		target.resetDefend();
	}

	if (target.returnDefDown() == true)
	{
		target.reduceDefDownCounter();
	}

	if (target.returnStrDown() == true)
	{
		target.reduceStrDownCounter();
	}

	if (target.returnSpdDown() == true)
	{
		target.reduceSpdDownCounter();
	}

	if (target.returnDefenseUp() == true)
	{
		target.reduceDefUpCounter();
	}

	if (target.returnStrUp() == true)
	{
		target.reduceStrUpCounter();
	}

	if (target.returnSpdUp() == true)
	{
		target.reduceSpdUpCounter();
	}
}

void Display(Boss H, Party mem1, Party mem2, Party mem3, Party mem4)
{
	cout << " ________________________________________________________________________________________________________________________ " << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#/**%#*/*/(*,,,,(%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ *((/,.**/(#(/#*,,,,/,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/* *&&%*,,,,(/*%#(**,,,*/#((/*/*@@@@,/*#%&@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,&&/*/,,*,/,,,*(/#*#%((///////#@@@@@*,,*/@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.(/*#/*,,,,,,,,///(#/**//////#*,,,,**@%,,**@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/@@#,/**(.,..,,,,,,/***///(#(/,,,,,,,,//,.,,,,/*/, @@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(**#/////*/*/(/**&*,/#((%%(///*,,...,*//*,..,*/&@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//,@@@(*/(%*//#,,##(#//&,/(((/////*******(,****///.,&%@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@#(/*/,(#**(#%../*%@&/(@(///////***/#,///////*,,,,,*%@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(/,.........*(%@/(/#@%#(/////////%.////*//,,,,,,,,*&@@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(@@#. ......,@%%%%*....@&##%(/////#%,//////////////,,/@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/.*/&...#@%@%%&,..,**#@%%%%%%####%,//#((((((((((//*(@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&/,***//%@%&%%%&@&%%%@@@&%%%%%%%%%%%*//%((((((((((((/%@@@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*.*,*(#(/@//(%&#(*,/////&@@%%%%%%%%%%%/(&(((((((((((((/%/**@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#&&/.,*/#**(@/#@#%/(%&&,*%#*,,,/*/(/%@%%%%%%%%%#//%%%%(((((((((((//////#&#@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/*.,((@@@@@@@@@@,@#%%%&&@,/.(*#**,,,*%*#@#@%%%%%%%&//&##%%###((((((((((/////% #*/@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(//#&@@@@@@@@@@@%%@&@@&&/..*,.,,,,*,#/((&%&@%%%%%%&&######%###%(((((((((////(//(%#/#@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.///*@@@@@@@@@@%#/*#@%*.  ,*.,,,,,,*(,,*#&#(@@%%%%%%#############(((((((((//((((/&.@@*%|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,//@@@@@@@@@@*#//#/.#,,*,,,,,,,,*/,,,,*(%#(@%&%&%################%((((((((/((((((/&@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/#(@@@@@%*####@.../*(*( ,,,,/,/,,,,,&(%&(@#&#&&%%###############&(##((((((((((&/,@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&/(/////////@*,.,***(//(/((****,,*%(((%#&#&%%&@@################/##((((((((#&&#@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%&(((((##((#%&///%(&,/***/#////((///#(((((#(%%&&&%&&%#(########(###(%#@/(##((((((#%@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@*(@@@@@@@&*%%#(#//%@@@((#%/(/%#%((#%(((/((#%*&@@&#,*%*@#((###&&@&&##@#@@@@/&#((((((%@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@,///&&###&##(#&(#%(((#(##&&&@&*%&%%%%#,,,/%((%##&&@##@/@@@@@@%%(((((#%@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@@@##/*@@@@@@@@@@@%,@@*//&%######%#%(@%((#(#@&&%%%%%%%%%%&#///***,####&&&&.@@@@@@@@@,#(((((@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@&@*,/#@@@@@@@@&,..//%//%###%####((%#@#&@&&&###%%%%%%%%&%*,,,,,,,,*###&&&&.*@@@@@@@@#@%((/*@@@@@@@@@|" << endl;
	cout << "|@@@@@@@@@@@@@@@@@@@@@(#/%&@@@@@@@@**//@///(%#######(((&&%@&&&#####%&&&#////////*,,/##/*###%&@&@@&(@@@&##(##(/@@@@@@@@@@@|" << endl;
	cout << "|%@@@@@@.,&@@@@@@@@@@%&/,%.@@@@@@@@##(&//////(########@&&&&&&&&&&%&&#///***,,,,,,,,,,,,,,,*##%@&@#&%(@@@@@/#(/*@@@@@@@@@@|" << endl;
	cout << "|@@@@@%(,%@@@@@@@@./@**%(.,. .,(/((&/////////%####%@@&@%&&@&@%%%%&%%%*,,,,,,,,,,,,,,,,,,(####&&@@@@@@@@@#(@(/@@@@@@@@@@@@|" << endl;
	cout << "|@@@@%//**,@@@@@,//(*/((((((((&&%#////////#&%%#%&&%&%@&&&&&&&&&%%%%%%&&,,,,,,,,,,,,,,,,#%###&&%&%%@@@@@,(@/,@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@.(##&,(%#,,///#((((#&(//////%&@@&&#@&##%%&&%%&%@&@&&&%%&%%&%%%%%%%%@*,,,,,,,,,,(&%###%&&@#@@@@@@@@/(@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@&,%/*(((((/(/((((((/***(//*/%(((@%###%#%%&%%#@##((&&%%%%&%%%&%%%%%%%&%%,,,,,%&&&###&&&&&#@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|@@@@*,&////((((/#,(((((/*((/(/##((%(#@###%%%%(@%#%%(((/@&%%%%@%%%&%%%%##%%&##(&&&&&%&&&@%%#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|%@(*/((,/((////(,(((((*((/(/(#(((*%&&@#&%%%#&@@@#(@((,,,/%@%%%@&%%%&#%%%%&@%@%&@&&&&&@,(#%*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|,##///#,*/(((((//(/*(/(///#%(((/&&%%@@&%@&/@@@@@&%%(,,,,,,&%%%%&###%%&%%%&(,%/@*%/@@&*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|(//////*//(((#((,,///(/((%((%%#&#@@@@@@@@@@@@@@@@%(%,,,%%%%%&#&@&&&(***%&@*%@@@@@@//(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|#//*//(/*/((((//((((/#((%#/((#*#@@@@@@@@@@@@@@@@@@(#%&&&##%&&&@&#(&***,&,(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|#((/#*///(#(#/(((((///%((//,,(#@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&@&&*/%*...,@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|/#(#%(**#&%(((////(/(((/,(,(.@@@@@@@@@@@@@@@@@@@@@@%@&&&&@@(%****,@&@&/,/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|///%%((@#(//(#(%&((*/*,,&#,@@@@@@@@@@@@@@@@@@@@@@@@@&&@@&%&&**%%%%&%##/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|/(/(*@(##((#(#/#@#&#,,,&,@@@@@@@@@@@@@@@@@@@@@@@@@@@@&%##**/%%%%%%%&##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|(((#&*&####(//#&&#/,*%#,,,,,,.#@@@@@@@@@@@@@@@@@@@@@@@@@/((((((((((##(*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << endl;
	cout << "|________________________________________________________________________________________________________________________|" << endl;
	cout << "                                                              ???                                       " << endl;
	cout << "                                                        ";
	H.DisplayBossBD();
	cout << endl;
	cout << endl;
	mem1.DisplayCstat();
	cout << " ";
	mem1.DisplayPlayerBD();
	cout << endl;
	mem2.DisplayCstat();
	cout <<"";
	mem2.DisplayPlayerBD();
	cout << endl;
	mem3.DisplayCstat();
	cout << " ";
	mem3.DisplayPlayerBD();
	cout << endl;
	mem4.DisplayCstat();
	cout << " ";
	mem4.DisplayPlayerBD();
	cout << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
}

void BossTurn(Boss& agresor, Party& receiver1, Party& receiver2, Party& receiver3, Party& receiver4)
{
	int damage;
	bool Tinv= false;
	unsigned seed;
	seed = time(0);
	srand(seed);
	int critc, crita;
	int avoc, hit;
	critc = 5+(agresor.returnLuck() / 8);
	hit = 75 + (agresor.returnSpeed() / 5) + (rand() % 5 + 1);
	agresor.setAct(false);

	Party* target;
	
	if (agresor.ReturnRage() >= 50)
	{
		agresor.SetSkill(rand() % 13 + 1);
	}
	else if (agresor.ReturnRage() >= 30)
	{
		agresor.SetSkill(rand() % 10 + 1);
	}
	else if (agresor.ReturnRage() >= 10)
	{
		agresor.SetSkill(rand() % 4 + 1);
	}
	else
	{
		agresor.SetSkill(1);
	}

	if (agresor.returnSkill() == 1)
	{
		target = Ctarget(receiver1, receiver2, receiver3, receiver4);
			

		AvoAndCritAvoSet(target, crita, avoc, agresor.returnSkill());

		cout << agresor.returnName() << " attacks!" << endl;
		Sleep(1000);

		damage = ((agresor.returnStr()) - target->returnDefense()) + (rand() % 15 + 1);
		BAttackCheck(target, damage, hit, avoc, critc, crita);


		if (hit > avoc)
		{
			agresor.IncreaseRage(5);
		}
	}

	if (agresor.returnSkill() == 2 and agresor.ReturnRage() >= 10)
	{
	
		target = Ctarget(receiver1, receiver2, receiver3, receiver4);
		AvoAndCritAvoSet(target, crita, avoc, agresor.returnSkill());

		cout << agresor.returnName() << " performs a Waning Strike!" << endl;
		Sleep(1000);

		damage = ((agresor.returnStr() * 2.35) - target->returnDefense()) + (rand() % 15 + 1);
		BAttackCheck(target, damage, hit, avoc, critc, crita);

		if (target->returnInv() == true)
		{
			Tinv = true;
		}

		if (PlayerLCheck(target, "Str") != true and hit > avoc and target->returnStatus() == true and Tinv != true)
		{
			target->setStrDown();
		}


		if (BossHCheck(agresor, "Str") != true and hit > avoc and Tinv!=true)
		{
			agresor.setStrUp();
		}

		agresor.DecreaseRage(10);

		if (hit > avoc and Tinv != true)
		{
			agresor.IncreaseRage(5);
		}

	}

	if (agresor.returnSkill() == 3 and agresor.ReturnRage() >= 10)
	{
		target = Ctarget(receiver1, receiver2, receiver3, receiver4);
		AvoAndCritAvoSet(target, crita, avoc, agresor.returnSkill());

		cout << agresor.returnName() << " performs a Crushing Strike!" << endl;
		Sleep(1000);

		damage = ((agresor.returnStr() * 2.35) - target->returnDefense()) + (rand() % 15 + 1);
		BAttackCheck(target, damage, hit, avoc, critc, crita);

		if (target->returnInv() == true)
		{
			Tinv = true;
		}

		if (PlayerLCheck(target, "Def") != true and hit > avoc and target->returnStatus() == true and Tinv != true)
		{
			target->setDefDown();
		}

		if (BossHCheck(agresor, "Def") != true and hit > avoc and Tinv!=true)
		{
			agresor.setDefUp();
		}

		agresor.DecreaseRage(10);

		if (hit > avoc and Tinv != true)
		{
			agresor.IncreaseRage(5);
		}

	}

	if (agresor.returnSkill() == 4 and agresor.ReturnRage() >= 10)
	{
		target = Ctarget(receiver1, receiver2, receiver3, receiver4);
		AvoAndCritAvoSet(target, crita, avoc, agresor.returnSkill());

		cout << agresor.returnName() << " performs a Binding Strike!" << endl;
		Sleep(1000);

		damage = ((agresor.returnStr() * 2.35) - target->returnDefense()) + (rand() % 15 + 1);
		BAttackCheck(target, damage, hit, avoc, critc, crita);

		if (target->returnInv() == true)
		{
			Tinv = true;
		}

		if (PlayerLCheck(target, "Spd") != true and hit > avoc and target->returnStatus() == true and Tinv != true)
		{
			target->setSpdDown();
		}

		if (BossHCheck(agresor, "Spd") != true and hit > avoc and Tinv != true)
		{
			agresor.setSpdUp();
		}

		agresor.DecreaseRage(10);

		if (hit > avoc and Tinv != true)
		{
			agresor.IncreaseRage(5);
		}

	}

	if ((agresor.returnSkill() == 5 or agresor.returnSkill() == 6 or agresor.returnSkill() == 7) and agresor.ReturnRage() >= 30)
	{
		
		cout << agresor.returnName() << " swings wildly!" << endl;
		Sleep(1000);

		target = &receiver1;
		AvoAndCritAvoSet(target, crita, avoc, agresor.returnSkill());
		damage = ((agresor.returnStr() * 3.35) - receiver1.returnDefense()) + (rand() % 15 + 1);
		BAttackCheck(&receiver1, damage, hit, avoc, critc, crita);
		
		if (hit > avoc and receiver1.returnInv()!= true)
		{
			agresor.IncreaseRage(5);
		}

		target = &receiver2;
		AvoAndCritAvoSet(target, crita, avoc, agresor.returnSkill());
		damage = ((agresor.returnStr() * 3.35) - receiver2.returnDefense()) + (rand() % 15 + 1);
		BAttackCheck(&receiver2, damage, hit, avoc, critc, crita);

		if (hit > avoc and receiver2.returnInv() != true)
		{
			agresor.IncreaseRage(5);
		}

		target = &receiver3;
		AvoAndCritAvoSet(target, crita, avoc, agresor.returnSkill());
		damage = ((agresor.returnStr() * 3.35) - receiver3.returnDefense()) + (rand() % 15 + 1);
		BAttackCheck(&receiver3, damage, hit, avoc, critc, crita);

		if (hit > avoc and receiver3.returnInv() != true)
		{
			agresor.IncreaseRage(5);
		}

		target = &receiver4;
		AvoAndCritAvoSet(target, crita, avoc, agresor.returnSkill());
		damage = ((agresor.returnStr() * 3.35) - receiver4.returnDefense()) + (rand() % 15 + 1);
		BAttackCheck(&receiver4, damage, hit, avoc, critc, crita);

		if (hit > avoc and receiver4.returnInv() != true)
		{
			agresor.IncreaseRage(5);
		}
		
		agresor.DecreaseRage(30);
	}

	if ((agresor.returnSkill() == 8 or agresor.returnSkill() == 9 or agresor.returnSkill() == 10) and agresor.ReturnRage() >= 30)
	{
		target = Ctarget(receiver1, receiver2, receiver3, receiver4);
		AvoAndCritAvoSet(target, crita, avoc, agresor.returnSkill());
		hit = rand() % 100 + 1;

		cout << agresor.returnName() << " attempts to strike at " << target->returnName() << "'s vital points!" << endl; 
		Sleep(1000);

		damage = (target->returnCurHp()-1);
		BAttackCheck(target, damage, hit, avoc, critc, crita);

		if (target->returnInv() == true)
		{
			Tinv = true;
		}

		agresor.DecreaseRage(5);

		if (hit > avoc and Tinv != true)
		{
			agresor.IncreaseRage(10);
		}
	}

	if ((agresor.returnSkill() == 11 or agresor.returnSkill() == 12 or agresor.returnSkill() == 13) and agresor.ReturnRage() >= 50)
	{
		target = Ctarget(receiver1, receiver2, receiver3, receiver4);
		AvoAndCritAvoSet(target, crita, avoc, agresor.returnSkill());

		cout << agresor.returnName() << " unleashes a Raging Storm strike! " << endl;
		Sleep(1000);

		damage = ((agresor.returnStr() * 2.72) - target->returnDefense()) + (rand() % 15 + 1);
		BAttackCheck(target, damage, hit, avoc, critc, crita);

		if (target->returnInv() == true)
		{
			Tinv = true;
		}

		agresor.DecreaseRage(30);

		if (hit > avoc and Tinv != true)
		{
			agresor.IncreaseRage(10);
			agresor.setAct(true);
		}
	}

	if (agresor.returnRegen() == true)
	{
		agresor.recoverHp((int)agresor.returnMaxHp() * .01);
	}

}

void PlayerTurn(Boss& target, Party& attacker, Party& sup1, Party& sup2, Party& sup3)
{
	
	if (attacker.returnMenu() == 1)
	{
		int damage;
		unsigned seed;
		seed = time(0);
		srand(seed);
		int critc, crita;
		int avoc, hit;
		critc = 5 + (attacker.returnLuck() / 5);
		hit = 75+(attacker.returnSpeed() / 5) + (rand() % 5 + 1);

		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc =((target.returnSpeed() / 5) + (rand() % 90 + 1));
		cout << attacker.returnName() << " attacks!" << endl;
		Sleep(1000);
		damage = (attacker.returnStr() - target.returnDefense())+ (rand()%15+1);

		attacker.recoverMp(10);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

	}

	else if (attacker.returnMenu() == 2)
	{
		if (attacker.returnIndicator() == 1)
		{
			UseMarianneSkills(target, attacker, sup1, sup2, sup3);

		}

		else if (attacker.returnIndicator() == 2)
		{
			UseLysitheaSkills(target, attacker, sup1, sup2, sup3);
		}


		else if (attacker.returnIndicator() == 3)
		{
			UseLeonieSkills(target, attacker, sup1, sup2, sup3);
		}


		else if (attacker.returnIndicator() == 4)
		{
			UseClaudeSkills(target, attacker, sup1, sup2, sup3);
		}

	}

	else if (attacker.returnMenu() == 3)
	{
		attacker.setDefend();

		attacker.recoverMp(20);

	}

	else if (attacker.returnMenu() == 4)
	{
		if ((rand() % 1000 + 1) == 1)
		{
			cout << "You have managed to escape for now...." << endl;
			Sleep(1000);
			cout << "But know that your fate was sealed that day 5 years ago" << endl;
			Sleep(1000);
			cout << "In the end only one of you can prevail, as cruel as that may be....." << endl;
			Sleep(5000);
			exit(0);
		}

		else
		{
			cout << "Escaping from fate is useless..." << endl;
			Sleep(1000);
		}
	}
}

void UseMarianneSkills(Boss& target, Party& attacker, Party& sup1, Party& sup2, Party& sup3)
{
	int damage;
	unsigned seed;
	seed = time(0);
	srand(seed);
	int critc, crita;
	int avoc, hit;
	critc = 5 + (attacker.returnLuck() / 5);
	hit = 75 + ((attacker.returnSpeed() / 5) + (rand() % 10 + 1));

	if (attacker.returnSkill() == 1)
	{
		int c, heal;
		bool choicepass = false;


		system("cls");
		Display(target, attacker, sup1, sup2, sup3);

		cout << "Select a target:" << endl;
		cout << "1." << attacker.returnName() << endl;
		cout << "2." << sup1.returnName() << endl;
		cout << "3." << sup2.returnName() << endl;
		cout << "4." << sup3.returnName() << endl;
		cout << "5.Back" << endl;

		while (choicepass == false)
		{
			try
			{
				c = NumCheck();

				if (c != 1 and c != 2 and c != 3 and c != 4 and c != 5)
				{
					throw 1;
				}
				else
				{
					choicepass = true;
				}


			}
			catch (int)
			{
				cout << "Invalid input" << endl;

			}
		}

		if (c == 1)
		{
			if (PlayerUHCheck(attacker, "Hp") == true)
			{
				return;
			}

		}

		else if (c == 2)
		{
			if (PlayerHCheck(sup1, attacker, "Hp") == true)
			{
				return;
			}
		}

		else if (c == 3)
		{
			if (PlayerHCheck(sup2, attacker, "Hp") == true)
			{
				return;
			}
		}

		else if (c == 4)
		{
			if (PlayerHCheck(sup3, attacker, "Hp") == true)
			{
				return;
			}
		}

		else if (c == 5)
		{
			attacker.setSkillChoice(7);
			return;
		}

		Sleep(1000);

		system("cls");
		Display(target, attacker, sup1, sup2, sup3);

		cout << attacker.returnName() << " casts Heal!" << endl;
		Sleep(1000);

		heal = attacker.returnMagic();

		if (c == 1)
		{
			attacker.recoverHp(heal);
		}

		else if (c == 2)
		{
			sup1.recoverHp(heal);
		}

		else if (c == 3)
		{
			sup2.recoverHp(heal);
		}

		else if (c == 4)
		{
			sup3.recoverHp(heal);
		}

	}

	if (attacker.returnSkill() == 2)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 8) + (rand() % 95 + 1));

		damage = ((attacker.returnMagic() * 2.95) - target.returnRes() + rand()%15+1);

		system("cls");
		Display(target, attacker, sup1, sup2, sup3);

		cout << attacker.returnName() << " casts Fimbulvetr!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());


		if (BossLCheck(target, "Str") != true and hit>avoc and target.returnInv() == false)
		{
			target.setStrDown();
		}
		


	}

	if (attacker.returnSkill() == 3)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc =((target.returnSpeed() / 10) + (rand() % 90 + 1));

		damage = (attacker.returnMagic() * 3.55) - ((target.returnRes())/2) + (rand() % 15 + 1);

		system("cls");
		Display(target, attacker, sup1, sup2, sup3);

		cout << attacker.returnName() << " unleashes Soulblade!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());
	}

	if (attacker.returnSkill() == 4)
	{
		system("cls");
		Display(target, attacker, sup1, sup2, sup3);

		if (PlayerUHCheck(attacker, "downall") == true and PlayerUHCheck(sup1, "downall") == true and PlayerUHCheck(sup2, "downall") == true and PlayerUHCheck(sup3, "downall") == true)
		{
			cout <<"Everyone is already in perfect condition!" << endl;
			attacker.setSkillChoice(7);
			attacker.recoverMp(attacker.returnUsedMp());
			Sleep(1000);
			return;
		}
		else
		{
			cout << attacker.returnName() << " casts Restore!" << endl;
			Sleep(1000);

			if (PlayerUHCheck(attacker, "downall") != true)
			{
				attacker.recoverStats();
			}
			
			if (PlayerUHCheck(sup1, "downall") != true)
			{
				sup1.recoverStats();
			}

			if (PlayerUHCheck(sup2, "downall") != true)
			{
				sup2.recoverStats();
			}
			
			if (PlayerUHCheck(sup3, "downall") != true)
			{
				sup3.recoverStats();
			}

		}
	}

	if (attacker.returnSkill() == 5)
	{
		crita = (target.returnLuck() / 5) + (rand() % 10 + 1);
		avoc = 0;

		damage = ((attacker.returnStr() * 4.25) - target.returnDefense() + rand() % 15 + 1);

		if (target.returnDefend() == true)
		{
			damage *= 2;
		}

		system("cls");
		Display(target, attacker, sup1, sup2, sup3);

		cout << attacker.returnName() << " delivers an All-Mighty Blow!" << endl;
		Sleep(1000);

		if (target.returnInv() == true)
		{
			target.InvPierce();
		}

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

		if (target.returnInv() == true)
		{
			target.InvUnPierce();
		}
	}

	if (attacker.returnSkill() == 6)
	{
		crita = (target.returnLuck() / 5) + (rand() % 10 + 1);
		avoc = 0;

		damage = ((attacker.returnMagic() + attacker.returnStr())*3.5) + (rand() % 15 + 1);

		system("cls");
		Display(target, attacker, sup1, sup2, sup3);

		cout << attacker.returnName() << " gathers her strength and prepares to unleash the beast within!" << endl;
		Sleep(1000);
		cout << attacker.returnName() << " uses Blutang's ultimate combo technique: Beast Fang!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = 5 + ((target.returnSpeed() / 5) + (rand() % 25 + 1));
		damage = ((attacker.returnMagic() + attacker.returnStr()) * 4.5) + (rand() % 15 + 1);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = 5 + ((target.returnSpeed() / 5) + (rand() % 25 + 1));
		damage = ((attacker.returnMagic() + attacker.returnStr()) * 5.5) + (rand() % 15 + 1);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

		if (BossLCheck(target, "Str") != true and target.returnInv() == false)
		{
			target.setStrDown();
		}

		if (BossLCheck(target, "Spd") != true and target.returnInv() == false)
		{
			target.setSpdDown();
		}

		if (BossLCheck(target, "Def") != true and target.returnInv() == false)
		{
			target.setDefDown();
		}
	
	}
}

void UseLysitheaSkills(Boss& target, Party& attacker, Party& sup1, Party& sup2, Party& sup3)
{
	int damage, heal;
	unsigned seed;
	seed = time(0);
	srand(seed);
	int critc, crita;
	int avoc, hit;
	critc = 5 + (attacker.returnLuck() / 5);
	hit = 75 + ((attacker.returnSpeed() / 5) + (rand() % 10 + 1));

	if (attacker.returnSkill() == 1)
	{
		int c;
		bool choicepass = false;


		system("cls");
		Display(target, sup1, attacker, sup2, sup3);

		cout << "Select a target:" << endl;
		cout << "1." << attacker.returnName() << endl;
		cout << "2." << sup1.returnName() << endl;
		cout << "3." << sup2.returnName() << endl;
		cout << "4." << sup3.returnName() << endl;
		cout << "5.Back" << endl;

		while (choicepass == false)
		{
			try
			{
				c = NumCheck();

				if (c != 1 and c != 2 and c != 3 and c != 4 and c != 5)
				{
					throw 1;
				}
				else
				{
					choicepass = true;
				}


			}
			catch (int)
			{
				cout << "Invalid input" << endl;

			}
		}

		if (c == 1)
		{
			if (PlayerUHCheck(attacker, "Str") == true)
			{
				return;
			}

		}

		else if (c == 2)
		{
			if (PlayerHCheck(sup1, attacker, "Str") == true)
			{
				return;
			}
		}

		else if (c == 3)
		{
			if (PlayerHCheck(sup2, attacker, "Str") == true)
			{
				return;
			}
		}

		else if (c == 4)
		{
			if (PlayerHCheck(sup3, attacker, "Str") == true)
			{
				return;
			}
		}

		else if (c == 5)
		{
			attacker.setSkillChoice(7);
			return;
		}

		Sleep(1000);

		system("cls");
		Display(target, sup1, attacker, sup2, sup3);

		cout << attacker.returnName() << " uses Rally Offense!" << endl;
		Sleep(1000);

		if (c == 1)
		{
			attacker.setStrUp();
		}

		else if (c == 2)
		{
			sup1.setStrUp();
		}

		else if (c == 3)
		{
			sup2.setStrUp();
		}

		else if (c == 4)
		{
			sup3.setStrUp();
		}

	}

	if (attacker.returnSkill() == 2)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 8) + (rand() % 95 + 1));

		damage = ((attacker.returnMagic() * 2.35) + rand() % 15 + 1);

		system("cls");
		Display(target, sup1, attacker, sup2, sup3);

		cout << attacker.returnName() << " casts Luna!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());
	}

	if (attacker.returnSkill() == 3)
	{
		system("cls");
		Display(target, sup1, attacker, sup2, sup3);

		if (PlayerUHCheck(attacker, "Hpall") == true and PlayerUHCheck(sup1, "Hpall") == true and PlayerUHCheck(sup2, "Hpall") == true and PlayerUHCheck(sup3, "Hpall") == true)
		{
			cout << "Everyone is already at full health!" << endl;
			attacker.setSkillChoice(7);
			attacker.recoverMp(attacker.returnUsedMp());
			Sleep(1000);
			return;
		}
		else
		{
			cout << attacker.returnName() << " casts Fortify!" << endl;
			Sleep(1000);
			heal = attacker.returnMagic() * 1.5;

			if (PlayerUHCheck(sup1, "Hpall") != true and sup1.returnStatus()==true)
			{
				sup1.recoverHp(heal);
			}

			if (PlayerUHCheck(attacker, "Hpall") != true)
			{
				attacker.recoverHp(heal);
			}

			if (PlayerUHCheck(sup2, "Hpall") != true and sup2.returnStatus() == true)
			{
				sup2.recoverHp(heal);
			}

			if (PlayerUHCheck(sup3, "Hpall") != true and sup3.returnStatus() == true)
			{
				sup3.recoverHp(heal);
			}

		}
	}

	if (attacker.returnSkill() == 4)
	{
		int c;
		bool choicepass = false;


		system("cls");
		Display(target, sup1, attacker, sup2, sup3);

		cout << "Select a target:" << endl;
		cout << "1." << sup1.returnName() << endl;
		cout << "2." << sup2.returnName() << endl;
		cout << "3." << sup3.returnName() << endl;
		cout << "4.Back" << endl;

		while (choicepass == false)
		{
			try
			{
				c = NumCheck();

				if (c != 1 and c != 2 and c != 3 and c != 4)
				{
					throw 1;
				}
				else
				{
					choicepass = true;
				}


			}
			catch (int)
			{
				cout << "Invalid input" << endl;

			}
		}

		if (c == 1)
		{
			if (PlayerHCheck(sup1, attacker, "Alive") == true)
			{
				return;
			}
		}

		else if (c == 2)
		{
			if (PlayerHCheck(sup2, attacker, "Alive") == true)
			{
				return;
			}
		}

		else if (c == 3)
		{
			if (PlayerHCheck(sup3, attacker, "Alive") == true)
			{
				return;
			}
		}

		else if (c == 4)
		{
			attacker.setSkillChoice(7);
			return;
		}

		Sleep(1000);

		system("cls");
		Display(target, sup1, attacker, sup2, sup3);

		cout << attacker.returnName() << " casts Resurrection!" << endl;
		Sleep(1000);

		if (c == 1)
		{
			heal = attacker.returnMagic();
			sup1.Revive(true);
			sup1.recoverHp(heal);
		}

		else if (c == 2)
		{
			heal = attacker.returnMagic();
			sup2.Revive(true);
			sup2.recoverHp(heal);
		}

		else if (c == 3)
		{
			heal = attacker.returnMagic();
			sup3.Revive(true);
			sup3.recoverHp(heal);
		}
	}

	if (attacker.returnSkill() == 5)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 9) + (rand() % 85 + 1));

		damage = ((attacker.returnMagic() * 7.5) - target.returnRes() + rand() % 15 + 1);

		system("cls");
		Display(target, sup1, attacker, sup2, sup3);

		cout << attacker.returnName() << " prepares to unleash a most terryfyng spell upon the enemy!" << endl;
		Sleep(1000);
		cout << "Ultimate Dark Magic: Hades ��" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

		if (hit > avoc and target.returnInv()==false)
		{
			target.resetBuffs();
		}
	}

	if (attacker.returnSkill() == 6)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 8) + (rand() % 95 + 1));

		damage = ((attacker.returnMagic() * 3) - target.returnRes() + rand() % 15 + 1);

		system("cls");
		Display(target, sup1, attacker, sup2, sup3);

		cout << attacker.returnName() << " casts Banshee ��!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());


		if (BossLCheck(target, "Spd") != true and hit > avoc and target.returnInv() == false)
		{
			target.setSpdDown();
		}
	}
}

void UseLeonieSkills(Boss& target, Party& attacker, Party& sup1, Party& sup2, Party& sup3)
{
	int damage, heal;
	unsigned seed;
	seed = time(0);
	srand(seed);
	int critc, crita;
	int avoc, hit;
	critc = 5 + (attacker.returnLuck() / 5);
	hit = 75 + ((attacker.returnSpeed() / 5) + (rand() % 10 + 1));

	if (attacker.returnSkill() == 1)
	{
		int c;
		bool choicepass = false;


		system("cls");
		Display(target, sup1, sup2, attacker, sup3);

		cout << "Select a target:" << endl;
		cout << "1." << attacker.returnName() << endl;
		cout << "2." << sup1.returnName() << endl;
		cout << "3." << sup2.returnName() << endl;
		cout << "4." << sup3.returnName() << endl;
		cout << "5.Back" << endl;

		while (choicepass == false)
		{
			try
			{
				c = NumCheck();

				if (c != 1 and c != 2 and c != 3 and c != 4 and c != 5)
				{
					throw 1;
				}
				else
				{
					choicepass = true;
				}


			}
			catch (int)
			{
				cout << "Invalid input" << endl;

			}
		}

		if (c == 1)
		{
			if (PlayerUHCheck(attacker, "Def") == true)
			{
				return;
			}

		}

		else if (c == 2)
		{
			if (PlayerHCheck(sup1, attacker, "Def") == true)
			{
				return;
			}
		}

		else if (c == 3)
		{
			if (PlayerHCheck(sup2, attacker, "Def") == true)
			{
				return;
			}
		}

		else if (c == 4)
		{
			if (PlayerHCheck(sup3, attacker, "Def") == true)
			{
				return;
			}
		}

		else if (c == 5)
		{
			attacker.setSkillChoice(7);
			return;
		}

		Sleep(1000);

		system("cls");
		Display(target, sup1, sup2, attacker, sup3);

		cout << attacker.returnName() << " uses Rally Defense!" << endl;
		Sleep(1000);

		if (c == 1)
		{
			attacker.setDefUp();
		}

		else if (c == 2)
		{
			sup1.setDefUp();
		}

		else if (c == 3)
		{
			sup2.setDefUp();
		}

		else if (c == 4)
		{
			sup3.setDefUp();
		}

	}

	if (attacker.returnSkill() == 2)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 8) + (rand() % 95 + 1));

		damage = ((attacker.returnStr() * 3.15) - target.returnDefense() + rand() % 15 + 1);

		system("cls");
		Display(target, sup1, sup2, attacker, sup3);

		cout << attacker.returnName() << " uses Shatter Slash!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());


		if (BossLCheck(target, "Def") != true and hit > avoc and target.returnInv() == false)
		{
			target.setDefDown();
		}
	}

	if (attacker.returnSkill() == 3)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 8) + (rand() % 75 + 1));

		damage = ((attacker.returnStr() * 2.15) - target.returnDefense() + rand() % 15 + 1);

		if (attacker.returnCurHp() < attacker.returnMaxHp() * .75)
		{
			damage = ((attacker.returnStr() * 3.12) - target.returnDefense() + rand() % 15 + 1);
		}

		else if (attacker.returnCurHp() < attacker.returnMaxHp() * .50)
		{
			damage = ((attacker.returnStr() * 4.25) - target.returnDefense() + rand() % 15 + 1);
		}

		else if (attacker.returnCurHp() < attacker.returnMaxHp() * .25)
		{
			damage = ((attacker.returnStr() * 5.15) - target.returnDefense() + rand() % 15 + 1);
		}

		else if (attacker.returnCurHp() < attacker.returnMaxHp() * .15)
		{
			damage = ((attacker.returnStr() * 7.45) + rand() % 15 + 1);
			avoc = 0;
		}

		system("cls");
		Display(target, sup1, sup2, attacker, sup3);

		cout << attacker.returnName() << " unleashes Vengeance!" << endl;
		Sleep(1000);

		if (attacker.returnCurHp() < attacker.returnMaxHp() * .15)
		{
			cout << "'This one's gonna hurt!'" << endl;
			Sleep(1000);
		}

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());
	}

	if (attacker.returnSkill() == 4)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 3) + (rand() % 125 + 1));

		damage = ((attacker.returnStr() * 9.15) - target.returnDefense() + rand() % 15 + 1);

		system("cls");
		Display(target, sup1, sup2, attacker, sup3);

		cout << attacker.returnName() << " prepares to unleash a Devastating shot!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());
	}

	if (attacker.returnSkill() == 5)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 9) + (rand() % 95 + 1));

		damage = (((attacker.returnDefense()+attacker.returnStr()) * 2.15) - target.returnDefense() + rand() % 15 + 1);

		system("cls");
		Display(target, sup1, sup2, attacker, sup3);

		cout << attacker.returnName() << " performs a Shield Bash!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

		attacker.setDefend();
		attacker.setAggro();
	}

	if (attacker.returnSkill() == 6)
	{
		critc = 5 + (attacker.returnLuck() / 2);
		crita = (target.returnLuck() / 12) + (rand() % 65 + 1);
		avoc = ((target.returnSpeed() / 12) + (rand() % 85 + 1));

		damage = ((attacker.returnStr() * 3.05) - target.returnDefense() + rand() % 15 + 1);

		system("cls");
		Display(target, sup1, sup2, attacker, sup3);

		cout << attacker.returnName() << " gets into position and prepares to unleash a deadly barrage upon the enemy!" << endl;
		Sleep(1000);
		cout << "The Inexhaustible's Ultimate Technique: Arrow Rain!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

		crita = (target.returnLuck() / 2) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 12) + (rand() % 85 + 1));

		damage = ((attacker.returnStr() * 3.15) - target.returnDefense() + rand() % 15 + 1);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

		crita = (target.returnLuck() / 2) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 12) + (rand() % 85 + 1));

		damage = ((attacker.returnStr() * 3.25) - target.returnDefense() + rand() % 15 + 1);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

		crita = (target.returnLuck() / 2) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 12) + (rand() % 85 + 1));

		damage = ((attacker.returnStr() * 3.35) - target.returnDefense() + rand() % 15 + 1);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());
	}
}

void UseClaudeSkills(Boss& target, Party& attacker, Party& sup1, Party& sup2, Party& sup3)
{
	int damage, heal;
	bool subdued=false;
	unsigned seed;
	seed = time(0);
	srand(seed);
	int critc, crita;
	int avoc, hit;
	critc = 5 + (attacker.returnLuck() / 5);
	hit = 75 + ((attacker.returnSpeed() / 5) + (rand() % 10 + 1));

	if (attacker.returnSkill() == 1)
	{
		int c;
		bool choicepass = false;


		system("cls");
		Display(target, sup1, sup2, sup3, attacker);

		cout << "Select a target:" << endl;
		cout << "1." << attacker.returnName() << endl;
		cout << "2." << sup1.returnName() << endl;
		cout << "3." << sup2.returnName() << endl;
		cout << "4." << sup3.returnName() << endl;
		cout << "5.Back" << endl;

		while (choicepass == false)
		{
			try
			{
				c = NumCheck();

				if (c != 1 and c != 2 and c != 3 and c != 4 and c != 5)
				{
					throw 1;
				}
				else
				{
					choicepass = true;
				}


			}
			catch (int)
			{
				cout << "Invalid input" << endl;

			}
		}

		if (c == 1)
		{
			if (PlayerUHCheck(attacker,"Spd") == true)
			{
				return;
			}
			
		}

		else if (c == 2)
		{
			if (PlayerHCheck(sup1, attacker, "Spd") == true)
			{
				return;
			}
		}

		else if (c == 3)
		{
			if (PlayerHCheck(sup2, attacker, "Spd") == true)
			{
				return;
			}
		}

		else if (c == 4)
		{
			if (PlayerHCheck(sup3, attacker, "Spd") == true)
			{
				return;
			}
		}

		else if (c == 5)
		{
			attacker.setSkillChoice(7);
			return;
		}

		Sleep(1000);

		system("cls");
		Display(target, sup1, sup2, sup3, attacker);

		cout << attacker.returnName() << " uses Rally Speed!" << endl;
		Sleep(1000);

		if (c == 1)
		{
			attacker.setSpdUp();
		}

		else if (c == 2)
		{
			sup1.setSpdUp();
		}

		else if (c == 3)
		{
			sup2.setSpdUp();
		}

		else if (c == 4)
		{
			sup3.setSpdUp();
		}

	}

	if (attacker.returnSkill() == 2)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = 0;

		damage = (((attacker.returnSpeed()+attacker.returnStr() )* 2.35) - target.returnDefense() + rand() % 15 + 1);

		system("cls");
		Display(target, sup1, sup2, sup3, attacker);

		cout << attacker.returnName() << " performs a Windsweep!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());
	}

	if (attacker.returnSkill() == 3)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 10) + (rand() % 70 + 1));

		damage = ((attacker.returnStr() * 1.15) - target.returnDefense() + rand() % 15 + 1);

		if (target.returnCurHp() < target.returnMaxHp() * .75)
		{
			damage = ((attacker.returnStr() * 2.12) - target.returnDefense() + rand() % 15 + 1);
		}

		else if (target.returnCurHp() < target.returnMaxHp() * .50)
		{
			damage = ((attacker.returnStr() * 3.25) - target.returnDefense() + rand() % 15 + 1);
		}

		else if (target.returnCurHp() < target.returnMaxHp() * .25)
		{
			damage = ((attacker.returnStr() * 4.15) - target.returnDefense() + rand() % 15 + 1);
		}

		else if (target.returnCurHp() < target.returnMaxHp() * .10)
		{
			damage = ((attacker.returnStr() * 6.45) + rand() % 15 + 1);
			avoc = 0;
		}

		system("cls");
		Display(target, sup1, sup2, sup3, attacker);

		cout << attacker.returnName() << " attempts to subdue the enemy!" << endl;
		Sleep(1000);

		if (target.returnInv() == true)
		{
			AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());
		}
		else
		{
			if (target.returnCurHp() == 1 and hit > avoc)
			{
				damage = 0;

				cout << "The target is already subdued!" << endl;
				Sleep(1000);
			}

			else if (target.SubdueCheck(damage) == true and hit > avoc)
			{
				damage = target.returnCurHp() - 1;

				cout << "The enemy has been succesfully subdued!" << endl;
				Sleep(1000);

				subdued = true;
			}

			AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

			if (subdued == true)
			{
				cout << "'Everyone, go for the killing blow!'" << endl;
				Sleep(1000);
			}
		}
		
	}

	if (attacker.returnSkill() == 4)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = 0;

		critc= 5 + (attacker.returnLuck() / 2);
		damage = ((attacker.returnStr() * 3.15) - target.returnDefense() + rand() % 15 + 1);

		system("cls");
		Display(target, sup1, sup2, sup3, attacker);

		cout << attacker.returnName() << " prepares to unleash a deadly accurate shot!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());
	}

	if (attacker.returnSkill() == 5)
	{
		crita = (target.returnLuck() / 5) + (rand() % 100 + 1);
		avoc = ((target.returnSpeed() / 10) + (rand() % 85 + 1));

		critc += attacker.returnSpeed()/4;
		damage = ((attacker.returnStr() * 4.15) + rand() % 15 + 1);

		system("cls");
		Display(target, sup1, sup2, sup3, attacker);

		cout << attacker.returnName() << " unleashes a powerful shot that soars through the skies and right into the enemy's vitals!" << endl;
		Sleep(1000);
		cout << attacker.returnName() << " Signature Technique: Wind God!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());
	}

	if (attacker.returnSkill() == 6)
	{
		crita = (target.returnLuck() / 12) + (rand() % 65 + 1);
		avoc = ((target.returnSpeed() / 12) + (rand() % 75 + 1));

		damage = ((attacker.returnStr() * 8.05) - target.returnDefense() + rand() % 15 + 1);

		system("cls");
		Display(target, sup1, sup2, sup3, attacker);

		cout << attacker.returnName() << " unleahes a powerful shot that pierces the heavens!" << endl;
		Sleep(1000);
		cout << attacker.returnName() << " uses Failnaught's ultimate technique: Fallen Star!" << endl;
		Sleep(1000);

		AttackCheck(target, damage, hit, avoc, critc, crita, attacker.returnIndicator());

		if (PlayerUHACheck(attacker, "Str") != true )
		{
			attacker.setStrUp();
		}

		if (PlayerUHACheck(attacker, "Spd") != true )
		{
			attacker.setSpdUp();
		}

		if (PlayerUHACheck(attacker, "Def") != true )
		{
			attacker.setDefUp();
		}

		if (attacker.returnInv() == false)
		{
			attacker.setInv();
		}
	}
}

void AttackCheck(Boss& target, int dmg, int hit, int avoid, int crtc, int crta, int chara)
{
	if (dmg <= 0)
	{
		dmg = 0;
	}

	if (hit < avoid)
	{
		cout << "Miss!" << endl;
		Sleep(1000);
		cout << target.returnName() << " takes no damage!" << endl;
		Sleep(1000);
		return;
	}

	else if (target.returnInv() == true)
	{
		cout << "But the attack bounces off "<<target.returnName()<<" harmlessly!" << endl;
		Sleep(1000);
		return;
	}

	else if (crta <= crtc)
	{
		dmg *= 3;

		if (chara == 1)
		{
			cout << "'My blood compels me!'" << endl;
			Sleep(1000);
		}

		else if (chara == 2)
		{
			cout << "'I have no time for mercy!'" << endl;
			Sleep(1000);
		}

		else if (chara == 3)
		{
			cout << "'I'll make you proud, Jeralt!'" << endl;
			Sleep(1000);
		}

		else if (chara == 4)
		{
			cout << "'Sorry, but I must!'" << endl;
			Sleep(1000);
		}

		cout << "CRITICAL HIT!!!!!!!" << endl;
		Sleep(1000);

		if (target.returnDefend() == true)
		{
			dmg /= 2;
		}

		cout << target.returnName() << " takes " << dmg << " points of damage!!!" << endl;
		target.takeDamage(dmg);

		if (dmg > 0)
		{
			target.IncreaseRage(dmg / 50);
		}
		
		Sleep(1000);
		return;
	}

	else if (target.returnDefend() == true)
	{
		dmg /= 2;
	}

	cout << target.returnName() << " takes " << dmg << " points of damage!" << endl;
	target.takeDamage(dmg);

	if (dmg > 0)
	{
		target.IncreaseRage(dmg / 50);
	}

	Sleep(1000);
	return;

}

void BAttackCheck(Party* target, int dmg, int hit, int avoid, int crtc, int crta)
{
	if (dmg <= 0)
	{
		dmg = 0;
	}

	if (hit < avoid)
	{
		cout << "Miss!" << endl;
		Sleep(1000);
		cout << target->returnName() << " takes no damage!" << endl;
		Sleep(1000);
		return;
	}

	else if (target->returnInv() == true)
	{
		cout << "But the attack bounces off "<<target->returnName()<<" harmlessly!" << endl;
		Sleep(1000);
		return;
	}

	else if (crta <= crtc)
	{
		dmg *= 3;

		cout << "'That's enough!'" << endl;
		Sleep(1000);

		cout << "CRITICAL HIT!!!!!!!" << endl;
		Sleep(1000);

		if (target->returnDefend() == true)
		{
			dmg /= 2;
		}

		cout << target->returnName() << " takes " << dmg << " points of damage!!!" << endl;
		target->takeDamage(dmg);
		Sleep(1000);
		return;
	}

	else if (target->returnDefend() == true)
	{
		dmg /= 2;
	}

	cout << target->returnName() << " takes " << dmg << " points of damage!" << endl;
	target->takeDamage(dmg);
	Sleep(1000);
	return;

}

bool PlayerHCheck(Party &target, Party& User, string search)
{
	if (search == "Spd")
	{
		if (target.returnSpdUp() == true)
		{
			cout << target.returnName() << "'s speed can't go any higher!" << endl;
			User.setSkillChoice(7);
			User.recoverMp(User.returnUsedMp());
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Str")
	{
		if (target.returnStrUp() == true)
		{
			cout << target.returnName() << "'s offenses can't go any higher!" << endl;
			User.setSkillChoice(7);
			User.recoverMp(User.returnUsedMp());
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Def")
	{
		if (target.returnDefenseUp() == true)
		{
			cout << target.returnName() << "'s defenses can't go any higher!" << endl;
			User.setSkillChoice(7);
			User.recoverMp(User.returnUsedMp());
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Hp")
	{
		if (target.returnFullHp() == true)
		{
			cout << target.returnName() << " is already at full health!" << endl;
			User.setSkillChoice(7);
			User.recoverMp(User.returnUsedMp());
			Sleep(1000);
			return true;
		}

		else if (target.returnStatus() == false)
		{
			cout << target.returnName() << " is already dead!" << endl;
			User.setSkillChoice(7);
			User.recoverMp(User.returnUsedMp());
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Alive")
	{
		if (target.returnStatus() == true)
		{
			cout << target.returnName() << " is already alive!" << endl;
			User.setSkillChoice(7);
			User.recoverMp(User.returnUsedMp());
			Sleep(1000);
			return true;
		}
	}
	return false;
}

bool PlayerUHCheck(Party& target, string search)
{
	if (search == "Spd")
	{
		if (target.returnSpdUp() == true)
		{
			cout << target.returnName() << "'s speed can't go any higher!" << endl;
			target.setSkillChoice(7);
			target.recoverMp(target.returnUsedMp());
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Str")
	{
		if (target.returnStrUp() == true)
		{
			cout << target.returnName() << "'s offenses can't go any higher!" << endl;
			target.setSkillChoice(7);
			target.recoverMp(target.returnUsedMp());
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Def")
	{
		if (target.returnDefenseUp() == true)
		{
			cout << target.returnName() << "'s defenses can't go any higher!" << endl;
			target.setSkillChoice(7);
			target.recoverMp(target.returnUsedMp());
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Hp")
	{
		if (target.returnFullHp() == true)
		{
			cout << target.returnName() << " is already at full health!" << endl;
			target.setSkillChoice(7);
			target.recoverMp(target.returnUsedMp());
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Hpall")
	{
		if (target.returnFullHp() == true)
		{
			return true;
		}
	}

	else if (search == "downall")
	{
		if (target.returnDefDown() == false and target.returnSpdDown() == false and target.returnStrDown() == false)
		{
			return true;
		}
	}

	return false;
}

bool BossHCheck(Boss& target, string search)
{
	if (search == "Spd")
	{
		if (target.returnSpdUp() == true)
		{
			cout << target.returnName() << "'s speed can't go any higher!" << endl;
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Str")
	{
		if (target.returnStrUp() == true)
		{
			cout << target.returnName() << "'s offenses can't go any higher!" << endl;
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Def")
	{
		if (target.returnDefenseUp() == true)
		{
			cout << target.returnName() << "'s defenses can't go any higher!" << endl;
			Sleep(1000);
			return true;
		}
	}
	return false;
}

bool PlayerUHACheck(Party& target, string search)
{
	if (search == "Spd")
	{
		if (target.returnSpdUp() == true)
		{
			cout << target.returnName() << "'s speed can't go any higher!" << endl;
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Str")
	{
		if (target.returnStrUp() == true)
		{
			cout << target.returnName() << "'s offenses can't go any higher!" << endl;
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Def")
	{
		if (target.returnDefenseUp() == true)
		{
			cout << target.returnName() << "'s defenses can't go any higher!" << endl;
			Sleep(1000);
			return true;
		}
	}
	return false;
}

bool BossLCheck(Boss& target, string search)
{
	if (search == "Spd")
	{
		if (target.returnSpdDown() == true)
		{
			cout << target.returnName() << "'s speed can't go any lower!" << endl;
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Str")
	{
		if (target.returnStrDown() == true)
		{
			cout << target.returnName() << "'s offenses can't go any lower!" << endl;
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Def")
	{
		if (target.returnDefDown() == true)
		{
			cout << target.returnName() << "'s defenses can't go any lower!" << endl;
			Sleep(1000);
			return true;
		}
	}
	return false;
}

bool PlayerLCheck(Party* target, string search)
{
	if (search == "Spd")
	{
		if (target->returnSpdDown() == true)
		{
			cout << target->returnName() << "'s speed can't go any lower!" << endl;
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Str")
	{
		if (target->returnStrDown() == true)
		{
			cout << target->returnName() << "'s offenses can't go any lower!" << endl;
			Sleep(1000);
			return true;
		}
	}

	else if (search == "Def")
	{
		if (target->returnDefDown() == true)
		{
			cout << target->returnName() << "'s defenses can't go any lower!" << endl;
			Sleep(1000);
			return true;
		}
	}
	return false;
}

void AvoAndCritAvoSet(Party* target, int& critavo, int& avo, int skill)
{
	if (skill == 1)
	{
		critavo = 30 + (target->returnLuck() / 5) + (rand() % 100 + 1);
		avo = ((target->returnSpeed() / 5) + (rand() % 85 + 1));
	}

	else if (skill == 2 or skill == 3 or skill == 4)
	{
		critavo = 30 + (target->returnLuck() / 5) + (rand() % 100 + 1);
		avo = ((target->returnSpeed() / 8) + (rand() % 85 + 1));
	}

	else if (skill == 5 or skill == 6 or skill == 7)
	{
		critavo = 30 + (target->returnLuck() / 5) + (rand() % 100 + 1);
		avo = ((target->returnSpeed() / 7) + (rand() % 85 + 1));
	}

	else if (skill == 8 or skill == 9 or skill == 10)
	{
		critavo = 1000;
		avo = ((target->returnSpeed() / 7) + 30);
	}

	else if (skill == 11 or skill == 12 or skill == 13)
	{
		critavo = 30 + (target->returnLuck() / 5) + (rand() % 100 + 1);
		avo = ((target->returnSpeed() / 8) + (rand() % 85 + 1));
	}


}

bool IsTargetAlive(Party receiver1, Party receiver2, Party receiver3, Party receiver4, int target)
{
	bool alive = false;

	if (target == 1)
	{
		if (receiver1.returnStatus() == true)
		{
			alive = true;
			return alive;
		}
		else
		{
			return alive;
		}
	}

	else if (target == 2)
	{
		if (receiver2.returnStatus() == true)
		{
			alive = true;
			return alive;
		}
		else
		{
			return alive;
		}
	}

	else if (target == 3)
	{
		if (receiver3.returnStatus() == true)
		{
			alive = true;
			return alive;
		}
		else
		{
			return alive;
		}
	}

	else if (target == 4)
	{
		if (receiver4.returnStatus() == true)
		{
			alive = true;
			return alive;
		}
		else
		{
			return alive;
		}
	}

	return alive;
}

bool IsTargetAggro(Party receiver1, Party receiver2, Party receiver3, Party receiver4, int& t)
{
	if (receiver1.returnAggro() == true)
	{
		t = 1;
		return true;
	}

	else if (receiver2.returnAggro() == true)
	{
		t = 2;
		return true;
	}

	else if (receiver3.returnAggro() == true)
	{
		t = 3;
		return true;
	}

	else if (receiver4.returnAggro() == true)
	{
		t = 4;
		return true;
	}
	return false;
}

Party* Ctarget(Party& receiver1, Party& receiver2, Party& receiver3, Party& receiver4)
{
	int target;
	do
	{
		if (IsTargetAggro(receiver1, receiver2, receiver3, receiver4, target) != true)
		{
			target = rand() % 4 + 1;
		}

	} while (IsTargetAlive(receiver1, receiver2, receiver3, receiver4, target) == false);

	if (target == 1)
	{
		return &receiver1;
	}

	else if (target == 2)
	{
		return &receiver2;
	}

	else if (target == 3)
	{
		return &receiver3;
	}

	else
	{
		return &receiver4;
	}
}





