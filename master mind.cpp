// master mind.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <ctime>
//設定答案
void setanswer(int answer[4])
{
	bool used[10] = { false };//用來記錄0-9有沒有被使用過
	int count = 0;//count是用來計算目前有幾個數字
	while (count < 4)//count < 4代表還沒有4個數字
	{
		int num = rand() % 10;//rand() % 10 代表0-9的隨機數
		if (!used[num])//如果used[num] = false，代表num還沒被使用過
		{
			used[num] = true;//used[num] = true代表num已經被使用過
			answer[count++] = num;//count++是先用count的值，再加1；++count是先加1，再用count的值 //將num存放在answer[count]中，並且count加1
		}
	}
}
//輸入數字與答案比對
int main()
{
	srand(time(NULL));//設定亂數種子
	int answer[4];//answer是用來存放答案的陣列[0]~[3]
	setanswer(answer);//呼叫setanswer函式，將答案存放在answer陣列中
	int guess[4];//guess是用來存放猜測的數字的陣列[0]~[3]
	int a = 0, b = 0;//a是用來存放A的數量，b是用來存放B的數量
	int n = 0;//n是用來存放輸入的數字

	while (a != 4)//當a不等於4時，代表還沒猜對，繼續執行迴圈
	{
		a = 0;
		b = 0;
		std::cout << "請輸入 4 個不重複的數字（0-9）：";
		std::cin >> n;
		guess[0] = n / 1000;//n / 1000代表取n的千位數
		guess[1] = (n % 1000) / 100;//(n % 1000) / 100代表取n的百位數
		guess[2] = (n % 100) / 10;//(n % 100) / 10代表取n的十位數
		guess[3] = n % 10;//n % 10代表取n的個位數

		for (int i = 0; i < 4; i++)//i從0開始，i < 4代表i小於4，i++代表i加1
		{
			if (guess[i] == answer[i])//如果guess[i]等於answer[i]
			{
				a++;// a加1
			}
			else//否則
			{
				for (int j = 0; j < 4; j++)//j從0開始，j < 4代表j小於4，j++代表j加1
				{
					if (guess[i] == answer[j])//如果guess[i]等於answer[j]
					{
						b++;//b加1
						break;//跳出迴圈
					}
				}
			}
		}
		std::cout << a << "A" << b << "B" << std::endl;//輸出A和B的數量
	}
	std::cout << "恭喜你，猜對了！" << std::endl;
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