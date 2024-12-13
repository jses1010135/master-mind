// master mind.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

void setanswer(int answer[4])
{
	bool repeat;
	for (int i = 0; i < 4; i++)
	{
		answer[i] = rand() % 10;
		repeat = false;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (answer[i] == answer[j])
			{
				repeat = true;
			}
		}
	}
	if (repeat == true)
	{
		setanswer(answer);
	}
	for (int i = 0; i < 4; i++)
	{
		answer[i] = rand() % 10;
	}
}
int main()
{
	srand(time(NULL));
	int answer[4];
	setanswer(answer);
	for (int i = 0; i < 4; i++)
	{
		std::cout << answer[i];
	}
	std::cout << std::endl;
	int guess[4];
	int a = 0, b = 0;
	while (a != 4)
	{
		a = 0;
		b = 0;
		std::cin >> guess[0] >> guess[1] >> guess[2] >> guess[3];
		for (int i = 0; i < 4; i++)
		{
			if (guess[i] == answer[i])
			{
				a++;
			}
			for (int j = 0; j < 4; j++)
			{
				if (guess[i] == answer[j])
				{
					b++;
				}
			}
		}
		b -= a;
		std::cout << a << "A" << b << "B" << std::endl;
	}
	std::cout << "You win!" << std::endl;
	return 0;

			
		
	
	
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
