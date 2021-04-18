
// iostream for cin and cout
#include <iostream>
// used for manipulators like setprecision
#include <iomanip>
using namespace std;

//Function to include in the assignment
void showUsage();
void makePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalX);
void displayPurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalX);
void displayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, int iTotalX);

int main() {
	//Main Welcome Banner.
	cout << "**************************************************************" << endl;
	cout << "****** Welcome to my Johnny Utah's PointBreak Surf Shop ******" << endl;
	cout << "**************************************************************" << endl;

	// Choices for the user input
	char choice = '\\';
	cout << "To show program usage 'S'" << endl;
	cout << "To purchase a surfboard press 'P' " << endl;
	cout << "To display current purchases press 'C' " << endl;
	cout << "To display total amount due press 'T' " << endl;
	cout << "To quit the program press 'Q" << endl;

	// Blank Spaces between the banner and the function.
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	// Declaring the variables - user input of quantity per size. 
	int smallSize = 0;
	int mediumSize = 0;
	int largeSize = 0;
	int xSize = 0;

	// A loop that continuosly asks the user to make a selection until they're done (entering 'Q' to quit)
	while (1) {
		cout << "\nPlease enter selection: ";
		cin >> choice;

		// Showing the program usage

		// If the user wants to show the program usage, they enter 'S'
		switch (choice) {
		case 'S':
		case 's':
			showUsage();
			break;
			// If the user wants to make a purchase, they enter 'P'
		case 'P':
		case 'p':
			makePurchase(smallSize, mediumSize, largeSize, xSize);
			break;
			// If the user wants to display the current purchase, they enter 'C'
		case 'C':
		case 'c':
			displayPurchase(smallSize, mediumSize, largeSize, xSize);
			break;
			// If the user wishes to see the total, they enter 'T'
		case 'T':
		case 't':
			displayTotal(smallSize, mediumSize, largeSize, xSize);
			break;
			// If the user wants to quit the program, they enter 'Q'
		case 'Q':
		case 'q':
			cout << "Thank You" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}

// This is displayed when the user enters 'S' - describing the program and offering info to the user (ex the price per surfboard size)
void showUsage() {
	cout << endl << "In this program, the user can purchase SURFBOARDDS. Follow the directions in the top of the program to make sure your using it correctly. Detailed options include: " <<
		"Pricing of the SURFBOARDS: \n\tLarge: $200\n\tMedium: $190\n\tSmall: $175\n\t\XXXS (for Squirrel Surfing): $150\n" << endl <<
		"When you're done, you can check your total by entering the correct prompt, and review your purchases prior to check out";
}

// When the user selects 'P' to make a purchase, the information to describe how and what to purchase outputs:
void makePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalX) {
	int quantity = 0;
	char size = '\0';

	cout << "Please enter the quantity and type ";
	cout << "(S=small, M=medium, L=large, X=xxxs [for Squirrel Surfers]) of ";
	cout << "surfboard you would like to purchase:";
	cin >> quantity >> size;

	// If the user picks a small with the quanitity, the data gets recorded and added to their 'cart'
	if (tolower(size) == 's' || toupper(size) == 'S') {
		iTotalSmall = iTotalSmall + quantity;
	}
	// If the user picks a meidum with the quanitity, the data gets recorded and added to their 'cart'

	else if (tolower(size) == 'm' || toupper(size) == 'M') {
		iTotalMedium = iTotalMedium + quantity;
	}
	// If the user picks a large with the quanitity, the data gets recorded and added to their 'cart'

	else if (tolower(size) == 'l' || toupper(size) == 'L') {
		iTotalLarge = iTotalLarge + quantity;
	}

	else if (tolower(size) == 'x' || toupper(size) == 'X') {
		iTotalX = iTotalX + quantity;
	}
}
//when the user selects 'C', they display whats currently in their cart
void displayPurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalX) {
	if (iTotalSmall > 0) {
		cout << "The total number of small ";
		cout << "surfboards is " << iTotalSmall;
		cout << endl;
	}

	// If these sizes were ordered, it will be displayed
	if (iTotalMedium > 0) {
		cout << "The total number of medium ";
		cout << "surfboards is " << iTotalMedium;
		cout << endl;
	}

	if (iTotalLarge > 0) {
		cout << "The total number of large ";
		cout << "surfboards is " << iTotalLarge;
		cout << endl;
	}
	if (iTotalX > 0) {
		cout << "The total number of XXXS for Squirrel Surfing ";
		cout << "surfboards is " << iTotalX;
		cout << endl;
	}
	if (iTotalSmall == 0 && iTotalLarge == 0 && iTotalMedium == 0 && iTotalX == 0) {
		cout << "No purchases made yet" << endl;
	}
}
// when the user enters 't' - they will see the combined total due
void displayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalX) {
	double amountSmall;
	double amountMedium;
	double amountLarge;
	double amountX;
	double due;

	amountSmall = amountMedium = amountLarge = amountX = due = 0;

	// Each size's indivisual cost
	const int smallCost = 175;
	const int mediumCost = 190;
	const int largeCost = 200;
	const int squirrelCost = 150;

	cout << fixed << setprecision(2);

	// Formula for the final output when the user enters 'T' for the total of the overall order. JJ

   // if the user ordered small surfboards:
	if (iTotalSmall > 0) {
		amountSmall = iTotalSmall * smallCost;

		cout << "The total number of small surfboards ";
		cout << "is " << iTotalSmall;
		cout << " at a total of $";
		cout << amountSmall << endl;

		due += amountSmall;
	}
	// if the user ordered medium surfboards:
	if (iTotalMedium > 0) {
		amountMedium = iTotalMedium * mediumCost;

		cout << "The total number of medium ";
		cout << "surfboards is " << iTotalMedium;
		cout << " at a total of $";
		cout << amountMedium << endl;

		due += amountMedium;
	}

	// if the user ordered large surfboards:

	if (iTotalLarge > 0) {
		amountLarge = iTotalLarge * largeCost;

		cout << "The total number of large ";
		cout << "surfboards is " << iTotalLarge;
		cout << " at a total of $";

		cout << amountLarge << endl;

		due += amountLarge;

	}

	if (iTotalX > 0) {
		amountX = iTotalX * squirrelCost;

		cout << "The total number of XXXS Surfrboards for Squirrel Surfing ";
		cout << "surfboards is " << iTotalX;
		cout << " at a total of $";

		cout << amountX << endl;

		due += amountX;

	}

	// In the case that the user hasnt ordered anything yet...
	if (iTotalLarge == 0 && iTotalMedium == 0 && iTotalSmall == 0 && iTotalX == 0)
	{
		cout << "No purchases made yet." << endl;
		return;
	}

	// Total overall cost. This will display no matter what items the user ordered.
	cout << "Amount due: $" << due << endl;
}