#include <iostream>
#include<thread>
using namespace std;
bool getRandom() {
	int r = rand() % 19; // generate a random number between 0 and 37
	if (r < 9)  // if the number is less than 18, return 1
		return true;
	else // otherwise, return 0
		return false;
}

bool game(int player_chip, int casino_chip)
{
	int i = 0;
	while (player_chip != 0 && casino_chip != 0)
	{
		if (!getRandom())
		{
			player_chip--;
			casino_chip++;
			//printf("player chip %d, casino chip %d\n", player_chip, casino_chip);
		}
		else
		{
			player_chip++;
			casino_chip--;
			//printf("player chip %d, casino chip %d\n", player_chip, casino_chip);
		}
		i++;
	}
	if (player_chip == 0)
		return false;
	else
		return true;
	
}

void start()
{
	int player_chip = 100, casino_chip = 1000, i = 0, count = 0;
	while (i == 0)
	{
		if (game(player_chip, casino_chip) == true)
			i++;
		count++;
		//if (count % 10000 == 0)
			//cout << count << ", thread id = " << this_thread::get_id() << endl;
	}
	printf("Player wins after %d attempts", count);
}

void main()
{
	cout << "Delo poshlo";
	thread th1(start);
	thread th2(start);
	thread th3(start);
	thread th4(start);
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	cout << "delo zakonchilos'";
}