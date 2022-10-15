
// Created By: Toton Liantoro
// Update : 30 June 2022


#include<string>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

const int PRODUCTNUM = 21;
const int PRODUCTMAX = 25;
void insertBook(string arr1[], string arr2[], string arr3[], char arr4[], double arr5[], int arr6[], double arr7[]);
void deleteBook(string arr1[], string arr2[], string arr3[], char arr4[], double arr5[], int arr6[], double arr7[]);
void viewReport(string arr1[], string arr2[], string arr3[], char arr4[], double arr5[], int arr6[], double arr7[]);
void displayBook(string arr1[], string arr2[], string arr3[], char arr4[], double arr5[], int arr6[], double arr7[]);
void writeReport(string arr1[], string arr2[], string arr3[], char arr4[], double arr5[], int arr6[], double arr7[]);



//Class Product
class Product {
	string isbn, title, surname;
public:
	Product() {};
	Product(string inIsbn, string inTitle, string inSurname) {
		isbn = inIsbn;
		title = inTitle;
		surname = inSurname;
	}
	~Product() {};

	void setProducts(string inIsbn, string inTitle, string inSurname) {
		isbn = inIsbn;
		title = inTitle;
		surname = inSurname;
	}

	string getIsbn() {
		return isbn;
	}

	string getTitle() {
		return title;
	}

	string getSurname() {
		return surname;
	}
};


//Class BookFormat
class BookFormat {
	char format;
public:
	//char format;
	BookFormat() {
		format = '\0';
	};

	BookFormat(char inFormat) {
		format = inFormat;
	}

	~BookFormat() {};

	void setFormat(char inFormat) {
		format = inFormat;
	}
	char getFormat() {
		return format;
	}
};



class Stock {
	Product* theProduct;
	BookFormat theFormat;
	int stockLevel{ 0 };
	double wholePrice{ 0 }, retailPrice{ 0 };

public:
	Stock() {
		this->theProduct = theProduct;
		theFormat = '\0';
		wholePrice = 0;
	};


	Stock(Product* theProduct, double inWholePrice, char inFormat) {
		this->theProduct = theProduct;
		theFormat.setFormat(inFormat);
		wholePrice = inWholePrice;
	}


	~Stock() {};

	//Get aggregation to add product and composition to add BookFormat 
	void setStock(Product* theProduct, double inWholePrice, char inFormat, int inStockLevel) {
		this->theProduct = theProduct;
		theFormat.setFormat(inFormat);
		stockLevel = inStockLevel;
		wholePrice = inWholePrice;

	}


	string getProductIsbn() {
		return theProduct->getIsbn();
	}

	string getProductTitle() {
		return theProduct->getTitle();
	}
	string getProductSurname() {
		return theProduct->getSurname();
	}

	char getBookFormat() {
		return theFormat.getFormat();
	}

	void setWholePrice(double inWholePrice) {
		wholePrice = inWholePrice;
	}


	double getWholePrice() {
		return wholePrice;
	}


	int getStockLevel() {
		return stockLevel;
	}



	//Set The retail Price
	void setRetailPrice(double wholePrice) {
		if (getBookFormat() == 'a') {
			retailPrice = (wholePrice + (0.43 * wholePrice));
		}
		if (getBookFormat() == 'e') {
			retailPrice = (wholePrice + (0.08 * wholePrice));
		}
		if (getBookFormat() == 'h') {
			retailPrice = (wholePrice + (0.45 * wholePrice));
		}
		if (getBookFormat() == 's') {
			retailPrice = (wholePrice + (0.27 * wholePrice));
		}
	}


	double getRetailPrice() {
		return retailPrice;
	}
};




int PRODDUCTNUM = 21;

//Function to allow clerk to insert book;
void insertBook(string arr1[], string arr2[], string arr3[], char arr4[], double arr5[], int arr6[], double arr7[]) {
	string inputIsbn, inputTitle, inputSurname;
	double inputWholePrice, inputRetailPrice{ 0 };
	int inputStockLevel;
	char inputFormat;
	char answer;
	cout << "Would you like enter a new book ? (Y/N)" << endl;
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {
		cout << "What is the ISBN: \n";
		cin >> inputIsbn;
		cout << "What is the book title: \n";
		cin >> inputTitle;
		cout << "What is the surname of the author: \n";
		cin >> inputSurname;
		cout << "What is the format of the book: (a,e,h,s)\n";
		cin >> inputFormat;
		cout << "How much the whole price: \n";
		cin >> inputWholePrice;
		cout << "How many stock level: \n";
		cin >> inputStockLevel;

		if (inputFormat == 'a') {
			inputRetailPrice = (inputWholePrice + (0.43 * inputWholePrice));
		}
		if (inputFormat == 'e') {
			inputRetailPrice = (inputWholePrice + (0.08 * inputWholePrice));
		}
		if (inputFormat == 'h') {
			inputRetailPrice = (inputWholePrice + (0.45 * inputWholePrice));
		}
		if (inputFormat == 's') {
			inputRetailPrice = (inputWholePrice + (0.27 * inputWholePrice));
		}


		for (int i = 0; i < PRODDUCTNUM; i++) {
			arr1[PRODDUCTNUM] = arr1[0];
			arr2[PRODDUCTNUM] = arr2[0];
			arr3[PRODDUCTNUM] = arr3[0];
			arr4[PRODDUCTNUM] = arr4[0];
			arr5[PRODDUCTNUM] = arr5[0];
			arr6[PRODDUCTNUM] = arr6[0];
			arr7[PRODDUCTNUM] = arr7[0];
		}

		PRODDUCTNUM++;

		for (int i = 0; i < PRODDUCTNUM; i++) {
			arr1[0] = inputIsbn;
			arr2[0] = inputTitle;
			arr3[0] = inputSurname;
			arr4[0] = inputFormat;
			arr5[0] = inputWholePrice;
			arr6[0] = inputStockLevel;
			arr7[0] = inputRetailPrice;

		}

	}

	else {
		false;
	}

}


//Function the Clerk allow to delete the book
void deleteBook(string arr1[], string arr2[], string arr3[], char arr4[], double arr5[], int arr6[], double arr7[]) {
	int found{ 0 };
	char answer;
	string deleteIsbn, deleteSurname;
	char deleteFormat;
	cout << "\nWould you like to delete the book collection ? (Y/N)" << endl;
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {
		cout << "What is the ISBN: \n";
		cin >> deleteIsbn;
		cout << "What is the surname of the author: \n";
		cin >> deleteSurname;
		cout << "What is the format of the book: (a,e,h,s)\n";
		cin >> deleteFormat;

		for (int i = 0; i < PRODDUCTNUM; i++) {
			if (arr1[i] == deleteIsbn && arr3[i] == deleteSurname && arr4[i] == deleteFormat) {

				arr1[i] = arr1[PRODDUCTNUM - 1];
				arr2[i] = arr2[PRODDUCTNUM - 1];
				arr3[i] = arr3[PRODDUCTNUM - 1];
				arr4[i] = arr4[PRODDUCTNUM - 1];
				arr5[i] = arr5[PRODDUCTNUM - 1];
				arr6[i] = arr6[PRODDUCTNUM - 1];
				arr7[i] = arr7[PRODDUCTNUM - 1];
				found++;
				PRODDUCTNUM--;

			}
		}
		if (found == 0) {
			cout << "\nThe Book is not found in the book colection" << endl;
		}
		else
			cout << "\nThe book has been deleted successfully" << endl;
	}


}


//Function to view report book availability against order
void viewReport(string arr1[], string arr2[], string arr3[], char arr4[], double arr5[], int arr6[], double arr7[]) {
	char answer{ '\0' };
	string notAva, notAva1;

	cout << "\nWould you like to view the book availabilty against the order? (Y/N)" << endl;
	cin >> answer;

	if (answer == 'Y' || answer == 'y') {
		int orderNum[5]{ 0 };
		string orderTitle[5]{ };
		ifstream inFile("orders.txt");
		if (!inFile) {
			cout << "Can not open the file. \n";
			false;
		}


		for (int i = 0; i < 5; i++) {
			inFile >> orderNum[i] >> orderTitle[i];

		}


		cout << "\n" << setw(100) << setfill('#') << "\n";
		cout << setw(55) << setfill(' ') << "ORDER REPORT";
		cout << "\n" << setw(100) << setfill('#') << "\n";





		for (int i = 0; i < PRODDUCTNUM; i++) {
			for (int j = 0; j < 5; j++) {
				if (orderTitle[j] == arr2[i] && orderNum[j] <= arr6[i]) {

					cout << orderTitle[j] << " is available at Biblidon and there is enough stock to fulfill your order" << endl;
				}

				if (orderTitle[j] == arr2[i] && orderNum[j] > arr6[i]) {
					cout << orderTitle[j] << " is available at Biblidon but there is not enough stock to fulfill your order" << endl;

				}

				if (orderTitle[j] != arr2[i]) {
					notAva = orderTitle[j];
					notAva1 = orderTitle[3];
				}

			}

		}

		cout << notAva << " is not avalaible at Biblidon" << endl;
		cout << notAva1 << " is not avalaible at Biblidon" << endl;

	}



}



//Function that allow clerk see books in the store
void displayBook(string arr1[], string arr2[], string arr3[], char arr4[], double arr5[], int arr6[], double arr7[]) {
	char answer;
	cout << "\nWould you like to see the book colection ? (Y/N)" << endl;
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {
		cout << setw(70) << setfill('#') << "\n" << endl;

		for (int i = 0; i < PRODDUCTNUM; i++) {
			cout << arr1[i] << " " << arr4[i] << " " << arr2[i] << " " << arr5[i] << " " << arr3[i] << " " << arr6[i] << endl;

		}

	}

}



//Function allow the clerk to create a report 
void writeReport(string arr1[], string arr2[], string arr3[], char arr4[], double arr5[], int arr6[], double arr7[]) {
	char answer{ '\0' };
	string notAva, notAva1;

	cout << "\nWould you like create the report? (Y/N)" << endl;
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {
		ofstream outFile;
		outFile.open("report.txt");
		outFile << left << setw(160) << setfill('-') << "\n";
		outFile << "\n" << right << setw(90) << setfill(' ') << " << Biblioden Books >> " << endl;
		outFile << setw(160) << setfill('-') << "\n";
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		outFile << "Audiobooks:" << endl;
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		outFile << "\n" << setw(30) << setfill(' ') << "ISBN" << setw(40) << "Title" << setw(30) << "Author" << setw(30) << "Retail Price" << setw(30) << "Stock Level" << endl;
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		for (int i = 0; i < PRODUCTMAX; i++) {
			if (arr4[i] == 'a') {
				outFile << setw(30) << setfill(' ') << arr1[i] << setw(40) << arr2[i] << setw(30) << arr3[i] << "$" << setw(30) << setprecision(2) << fixed << arr7[i] << setw(30) << arr6[i] << endl;
			}
		}
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		outFile << "eBooks:" << endl;
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		outFile << "\n" << setw(30) << setfill(' ') << "ISBN" << setw(40) << "Title" << setw(30) << "Author" << setw(30) << "Retail Price" << setw(30) << "Stock Level" << endl;
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		for (int i = 0; i < PRODUCTMAX; i++) {
			if (arr4[i] == 'e') {
				outFile << setw(30) << setfill(' ') << arr1[i] << setw(40) << arr2[i] << setw(30) << arr3[i] << "$" << setw(30) << setprecision(2) << fixed << arr7[i] << setw(30) << arr6[i] << endl;
			}
		}
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		outFile << "Hardcover:" << endl;
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		outFile << "\n" << setw(30) << setfill(' ') << "ISBN" << setw(40) << "Title" << setw(30) << "Author" << setw(30) << "Retail Price" << setw(30) << "Stock Level" << endl;
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		for (int i = 0; i < PRODUCTMAX; i++) {
			if (arr4[i] == 'h') {
				outFile << setw(30) << setfill(' ') << arr1[i] << setw(40) << arr2[i] << setw(30) << arr3[i] << "$" << setw(30) << setprecision(2) << fixed << arr7[i] << setw(30) << arr6[i] << endl;
			}
		}
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		outFile << "Softcover:" << endl;
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		outFile << "\n" << setw(30) << setfill(' ') << "ISBN" << setw(40) << "Title" << setw(30) << "Author" << setw(30) << "Retail Price" << setw(30) << "Stock Level" << endl;
		outFile << left << setw(160) << setfill('-') << "\n" << endl;
		for (int i = 0; i < PRODUCTMAX; i++) {
			if (arr4[i] == 's') {
				outFile << setw(30) << setfill(' ') << arr1[i] << setw(40) << arr2[i] << setw(30) << arr3[i] << "$" << setw(30) << setprecision(2) << fixed << arr7[i] << setw(30) << arr6[i] << endl;
			}
		}

		outFile.close();
		cout << "\nReport has been created succesfuylly to the file report.txt" << endl;
	}
}




int main()
{


	Product newProduct[PRODUCTNUM];
	Stock newStock[PRODUCTNUM];

	string theIsbn, theTitle, theSurname;
	char theForm;
	double theWholePrice, retailPrice{ 0 };
	int theStockLevel;


	//Creating array to store item
	string arrIsbn[PRODUCTMAX], arrTitle[PRODUCTMAX], arrSurname[PRODUCTMAX];
	char arrFormat[PRODUCTMAX];
	double arrWholePrice[PRODUCTMAX], arrRetailPrice[PRODUCTMAX];
	int arrStockLevel[PRODUCTMAX];


	ifstream inFile("products.txt");
	if (!inFile) {
		cout << "Can not open the file. \n";
		return 1;
	}

	for (int i = 0; i < PRODUCTNUM; i++) {
		inFile >> theIsbn >> theForm >> theTitle >> theWholePrice >> theSurname >> theStockLevel;
		newProduct[i].setProducts(theIsbn, theTitle, theSurname);
		newStock[i].setStock(&newProduct[i], theWholePrice, theForm, theStockLevel);
		newStock[i].setRetailPrice(theWholePrice);

		//Inputing the elements to array:
		arrIsbn[i] = newStock[i].getProductIsbn();
		arrTitle[i] = newStock[i].getProductTitle();
		arrSurname[i] = newStock[i].getProductSurname();
		arrFormat[i] = newStock[i].getBookFormat();
		arrWholePrice[i] = newStock[i].getWholePrice();
		arrRetailPrice[i] = newStock[i].getRetailPrice();
		arrStockLevel[i] = newStock[i].getStockLevel();


	}

	inFile.close();


	//Here are the functions available in the program:
	//Clerk would insert book
	insertBook(arrIsbn, arrTitle, arrSurname, arrFormat, arrWholePrice, arrStockLevel, arrRetailPrice);
	//Clerk can see the array after insert the book
	displayBook(arrIsbn, arrTitle, arrSurname, arrFormat, arrWholePrice, arrStockLevel, arrRetailPrice);



	//Clerk would delete the book
	deleteBook(arrIsbn, arrTitle, arrSurname, arrFormat, arrWholePrice, arrStockLevel, arrRetailPrice);
	//Clerk can see the array after delete the book
	displayBook(arrIsbn, arrTitle, arrSurname, arrFormat, arrWholePrice, arrStockLevel, arrRetailPrice);


	//Clerk can check the availability book based on the order
	viewReport(arrIsbn, arrTitle, arrSurname, arrFormat, arrWholePrice, arrStockLevel, arrRetailPrice);


	/*Function to write report to file : report.txt*/
	writeReport(arrIsbn, arrTitle, arrSurname, arrFormat, arrWholePrice, arrStockLevel, arrRetailPrice);
}

