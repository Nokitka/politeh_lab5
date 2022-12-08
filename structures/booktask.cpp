#include "booktask.h"

using namespace std;

void PrintBook(const BOOK& book) {
	printf("author: %s\n", book.author);
	printf("header: %s\n", book.header);
	printf("year of publication: %i\n", book.year);
	printf("price: %i\n", book.price);
	printf("category: %s\n", book.category);
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

char * CheckCategory(char* category) {
	char list[4][BUFFER_SIZE] = {"fantasy", "manga", "classic", "roman"};
	while (true){
		for (int i = 0; i < 4; i++){
			if (strcmp(list[i], category) == 0){
				return category;
			}
		}

		printf("Sorry, but choose category from list: fantasy, manga, classic, roman:'(\n");
		scanf("%s", category);
	}
}

BOOK ScanBook(){
	
	BOOK book;
	char st[BUFFER_SIZE] = {0};
	int year, price;

	printf("author: ");
	scanf("%s", st);
	strcpy(book.author, st);

	printf("header: ");
	scanf("%s", st);
	strcpy(book.header, st);

	printf("year of publication: ");
	scanf("%i", &year);
	book.year = CheckYear(year);
	
	printf("price: ");
	scanf("%i", &price);
	book.price = CheckPrice(price);
	
	printf("Choose category from list: fantasy, manga, classic, roman\n");
	scanf("%s", st);
	strcpy(book.category, CheckCategory(st));
	
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
	PrintBook(bookTest);
}