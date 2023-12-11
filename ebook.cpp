#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {
	//структура для храниния пользователя и прочитанных страниц
	vector<int> users(1000001, 0);
	//структура для хранения кол-ва пользователей дочитавших до страницы n
	vector<int> users_count(1001, 0);
	int count = 0; 
	//считаем кол-во запросов
	int queries_count;
	cin >> queries_count;
	//обработаем запросы
	for (int query_number = 0; query_number < queries_count; ++query_number) {
		string type_query;
		cin >> type_query;

		int user_id;
		cin >> user_id;

		if (type_query == "READ")
		{	
			int pages_count;
			cin >> pages_count;
			
			if (pages_count == 0)
			{
				continue;
			}
			if (users[user_id] == 0)
			{
				++count;
			}else
            {
                users_count[users[user_id]] -= 1;
            }
			
			users[user_id] = pages_count;	
			users_count[pages_count] +=1;
			
		}else if (type_query == "CHEER"){
			if (users[user_id] == 0)
			{
				cout << 0 << endl;
			}else if (count == 1)
			{
				cout << 1 << endl;
			}else 
			{
				int page = users[user_id];
				auto count_user = accumulate(users_count.begin(), users_count.begin()+page,0.0); // количество пользователей прочитавших меньше страниц
				double dolya = count_user / static_cast<double>(count-1);
				cout << dolya << endl;
			}
			
			
			
		}
		
		
	}
}