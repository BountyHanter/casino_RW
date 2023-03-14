#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "windows.h"
#include "BinaryTree.h"
#include <ctime>
using namespace std;
int getRandom() {
	int r = rand() % 38; // generate a random number between 0 and 37
	if (r < 18) { // if the number is less than 18, return 1
		return 1;
	}
	else { // otherwise, return 0
		return 0;
	}
}

bool game(int player_chip, int casino_chip, BinaryTree tree)
{
	int min = 0, max = 38,x;
	while (player_chip != 0 && casino_chip != 0)
	{
		x = min + rand() % (max - min + 1);
		//cout << x << " ";
		int a = tree.SearchInSubTree(x);
		//cout << a;
		if (a == -1)
		{
			player_chip--;
			casino_chip++;
			//cout << "He lose round: player chip = " << player_chip << " , casino chip = " << casino_chip << endl;
		}
		else
		{
			player_chip++;
			casino_chip--;
			//cout << "He win round: player chip = " << player_chip << " , casino chip = " << casino_chip << endl;
		}
		//Sleep(1000);
	}
	if (player_chip == 0)
	{
		return false;
	}
	else if (casino_chip == 0)
	{
		return true; 
	}
}

void main()
{
	srand(time(NULL));
	BinaryTree tree;
	// Установить начальную точку генерирования последовательности
	// использовать функцию time(NULL)
	const int len = 18;
	int red [len] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
	for (int i = 0; i < len; i++)
	{
		tree.AddToTree(red[i]);
	}
	int player_chip = 100000000, casino_chip = 1000, i = 0; // от 1 до 36 простые числа, 37 и 38 принимаем за 0 и 00
	//while (!game(player_chip, casino_chip, tree))
	//{
	//	i++;
	//	if (i % 2 == 0)
	//		cout << "player lost " << i << "times" << endl;
	//}
	//cout << "player won on " << i << "try";
	int count = 0, x,a;
	double elapsed_time;
	double time = 0;
	for (int i = 0; i < 10; i++)
	{
		std::clock_t start_time = std::clock();
		while (count < 10000000)
		{
			x = 0 + rand() % (38 - 0 + 1);
			//cout << x << " ";
			a = tree.SearchInSubTree(x);
			count++;
		}
		std::clock_t end_time = std::clock();
		elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;
		time = time + elapsed_time;
	}
	time = time / 10;
	cout << time;
	/*count = 0;
	auto start_time = std::chrono::high_resolution_clock::now();
	while (count < 1000000)
	{
		getRandom();
		count++;
	}
	auto end_time = std::chrono::high_resolution_clock::now();
	double elapsed_time = std::chrono::duration<double>(end_time - start_time).count();
	std::cout << "Elapsed time: " << elapsed_time << " seconds\n";*/
}