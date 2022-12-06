#include "booktask.h"

using namespace std;

void PrintBook(const BOOK& book) {
	printf("author: %s\n", book.author.c_str());
	printf("header: %s\n", book.header.c_str());
	printf("year of publication: %i\n", book.year);
	printf("price: %i\n", book.price);
	printf("category: %s\n", book.category.c_str());
}

int CheckYear(int year) {
	if (year < 2022 && year > 0)
		return year;
	printf("Ooops, error! :'(\n");
	return 2021;
}

int CheckPrice(int price) {
	if (price > 0)
		return price;

	printf("Ooops, error! :'(\n");
	return 100;
}

string CheckCategory(char* category) {
	string list[4] = { "fantasy", "manga", "classic", "roman" };
	while (true){
		for (int i = 0; i < 4; i++){
			if (!list[i].compare(category)){
				return category;
			}
		}

		printf("Sorry, but choose category from list: fantasy, manga, classic, roman:'(\n");
		scanf("%s", category);
	}
}

BOOK ScanBook(){
	
	BOOK book;
	char st[100] = {0};
	int year, price;
	string category;

	printf("author: ");
	scanf("%s", st);
	book.author = st;

	printf("header: ");
	scanf("%s", st);
	book.header = st;

	printf("year of publication: ");
	scanf("%i", &year);
	book.year = CheckYear(year);
	
	printf("price: ");
	scanf("%i", &price);
	book.price = CheckPrice(price);
	
	printf("Choose category from list: fantasy, manga, classic, roman\n");
	scanf("%s", st);
	book.category = CheckCategory(st);
	
	return book;
}

BOOK bookglobal = { "Masashi Kishimoto", "Naruto", 23, 840, "manga" };

void BookTask() {

	BOOK booklocal = { "Masashi Kishimoto", "Naruto", 23, 840, "manga" };
	static BOOK bookstat = { "Masashi Kishimoto", "Naruto", 23, 840, "manga" };
	BOOK* bookdynamic = new BOOK{ "Masashi Kishimoto", "Naruto", 23, 840, "manga" };

	printf("%i\n", (int)sizeof(bookglobal));
	printf("%i\n", (int)sizeof(booklocal));
	printf("%i\n", (int)sizeof(bookstat));
	printf("%i\n", (int)sizeof(bookdynamic));

	PrintBook(bookglobal);
	PrintBook(booklocal);
	PrintBook(bookstat);
	PrintBook(*bookdynamic);

	BOOK bookTest = ScanBook();
}