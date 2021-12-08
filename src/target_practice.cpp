/*******************************
Programmer: Adam La Fleur
Assignment: #5 - Target Practice
Sources: None
*******************************/

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>

using namespace std;

// Function firePhaser. No parameters. Returns the amount of damage,
// 0 for a miss, 15-30 for a phaser hit.
int firePhaser();

// Function fireTorpedo. No parameters. Returns the amount of damage,
// 0 for a miss, 35-50 for a torpedo hit.
int fireTorpedo();

int main(){
	//Initiialize variables
	char weaponChoice;
	int damage = 0;
	int dronePoints = 100;
	int pCounter = 0, tCounter = 0, pmCounter = 0, tmCounter = 0;
	int pMiss = 0, tMiss = 0, pHits = 0, tHits = 0;
	srand(time(NULL));
	
	//Start program
	cout << "Commencing target practice. A target drone has been released." << endl;
	
	//Loops choice and menu until dronePoints is 0
	while (dronePoints > 0)
	{
		// Give user a choice
		cout << "What would you like to do? Fire (p)hasers, fire a (t)orpedo, or (q)uit?: ";
		cin >> weaponChoice;

	//Menu
		//Weapon Choice: Phaser
		if (weaponChoice == 'p')
		{
			cout << "Firing phasers." << endl;
			damage = firePhaser();
			
			//Number of Phaser Shots, Phaser Misses and Total Hits
			++pCounter;
			if (damage == 0){
				++pMiss;
			}
			pHits = pCounter - pMiss;
			
			//Drone health after firing Phaser
			dronePoints -= damage;
			if (dronePoints >= 0)
			{
				cout << "The drone is now at " << dronePoints << " percent functionality." << endl;
			}
			else
			{
				cout << "The drone has been destroyed." << endl;
			}
		}
		//Weapon Choice: Torpedo
		else if (weaponChoice == 't')
		{
			cout << "Firing torpedos." << endl;
			damage = fireTorpedo();
			
			//Number of Torpedo Shots, Torpedo Misses and Total Hits
			++tCounter;
			if (damage == 0){
				++tMiss;
			}
			tHits = tCounter - tMiss;

			//Drone health after firing Torpedo
			dronePoints -= damage;
			if (dronePoints >= 0)
			{
				cout << "The drone is now at " << dronePoints << " percent functionality." << endl;
			}
			else
			{
				cout << "The drone has been destroyed." << endl; 
			}

		}
		//Quit target pratice
		else if (weaponChoice == 'q')
		{
			cout << "Target practice terminated. Sending self-destruct signal to drone." << endl;
			system("pause");
			return 0;
		}

		// Handle an error message.
		else
		{
			cout << "Error, please enter a valid selection." << endl;
		}	
	}
	//couts the total number of player shots and hits
	cout << "There were " << pCounter << " phaser shots and " << pHits << " phaser hits." << endl;
	cout << "There were " << tCounter << " torpedo shots and " << tHits << " torpedo hits." << endl;
	cout << "Target practice complete." << endl;
	return 0;
}

//Phaser Function
int firePhaser()
{
	int damage = 0;
	int hitOrMiss;
	hitOrMiss = rand() % 100 + 1;
	if (hitOrMiss <= 75)
	{
		damage = rand() % 16 + 15;
		cout << "Phasers are on target. Damage to the drone is " << damage << "." << endl;
	}
	else
	{
		cout << "Phasers off target. No damage to the drone." << endl;
	}
	return damage;
}

//Torpedo function
int fireTorpedo()
{
	int damage = 0;
	int hitOrMiss;
	hitOrMiss = rand() % 100 + 1;
	if (hitOrMiss <= 50)
	{
		damage = rand() % 16 + 35;
		cout << "Torpedoes are on target. Damage to the drone is " << damage << "." << endl;
	}
	else
	{
		cout << "Torpedoes off target. No damage to the drone." << endl;
	}
	return damage;
}
