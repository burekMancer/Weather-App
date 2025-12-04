#include <iostream> 
#include <string>
using namespace std;
class City //city Class creation
{
public:
	string name; 
	int temp;
	City(string cName = "", int cTemp = 0)
	{
		name = cName;
		temp = cTemp;
	}
	void showInfo() const // this will be called in later on to show what city matches to inputed temp
	{
		cout << "City name: " << name << endl;
		cout << "City temperature: " << temp << endl;
	}
	string sTemp(int temp) //converting temp to string with to_string method
	{
		string sTemp = to_string(temp);
		return sTemp;
	}
	string sName(string name)
	{
		return name;
	}
};
void bubblesort(City cityarray[4], int arrSize, int temp);
void tempCheck(City cityarray[4], int temp);
static int linSearch(City cityarray[4], int temp); //calling the function here since it will be called in main but constructing it later on 
void hTemp(City cityarray[4]);     
void lTemp(City cityarray[4]);
static int binSearch(City cityarray[4]);
int main()
{
	City cityarray[4];// making an array for the cities
	int temp = 0; //initializing temp so the consol can stop giving me warnings
	for (int i = 0; i < 4; i++)
	{
		cout << "Input city name: ";
		cin >> cityarray[i].name;
		cout << "Input city temperature: ";
		cin >> cityarray[i].temp;
	}
	tempCheck(cityarray, temp);
	int arrSize = 4;
	bubblesort(cityarray,arrSize, temp);
	int i = linSearch(cityarray, temp); //Assigning "i" value to equal returned value from linSearch for the next if-statement
	if (i == -1)
	{//Answer in case inputed temp didnt exist in a city
		cout << "No City temperature matches input provided by user. " << endl;
	}
	else
	{
		cout << "The following city matches your input\n";
		cityarray[i].showInfo(); //using showInfo to show them the values of the city that was found
	}
	cout << "==========================" << endl;
	cout << "--Warmest/Coldest cities--" << endl;
	hTemp(cityarray);
	lTemp(cityarray);
	int b = binSearch(cityarray); //Assigning "i" value to equal returned value from linSearch for the next if-statement
	if (b == -1)
	{//Answer in case inputed temp didnt exist in a city
		cout << "No City temperature matches input provided by user. " << endl;
	}
	else
	{
		cout << "The following city matches your input\n";
		cityarray[b].showInfo(); //using showInfo to show them the values of the city that was found
	}
	cout << "Thank you for your time. ";
	return 0;
}
static int linSearch(City cityarray[4], int temp)
{
	cout << "==========================" << endl;
	int kTemp; //making a "key" for the temp 
	cout << "Input Temperature you would want to search for\n" << "Input: ";
	cin >> kTemp;
	for (int i = 0; i < 4; i++) //make a simple loop that returns a value if the temp value is equal to key Temp
	{
		if (cityarray[i].temp == kTemp)
			return i;
	}
	return -1;
}
void bubblesort(City cityarray[4], int arrSize, int temp)
{
	for (int n = 0; n < arrSize; n++) 
	{
		int nrLeft = arrSize - n -1; //numbers left in array is array size -1 (for index) minus "n"
		for (int j = 0; j < nrLeft; j++)
		{
			if (cityarray[j].temp > cityarray[j + 1].temp)
			{
				City sortCity = cityarray[j + 1]; // making a sorting loop to move the vars into the next index until the smallest is in the first index
				cityarray[j + 1] = cityarray[j];
				cityarray[j] = sortCity;
			}
		}
	}
	cout << "==========================" << endl;
	for (int p = 0; p < 4; p++)
	{
		cout << cityarray[p].name << ", " << cityarray[p].temp << endl;
	}
}
void tempCheck(City cityarray[4], int temp) //basic check to make sure the inputs are valid
{
	while (true)
	{
		for (int c = 0; c < 4; c++)
		{
			while (cityarray[c].temp >= 60 || cityarray[c].temp <= -60) 
			{
				cout << cityarray[c].name << " has been assigned an invalid temperature, try again " << endl;
				cout << "Temperature input for: " << cityarray[c].name << endl;
				cout << "Input: " << endl;
				cin >> cityarray[c].temp;
			}

		}
		break;
	}
}
void hTemp(City cityarray[4]) //printing highest temp by calling the last index since the array is sorted from smallest to biggest
{
	cout << "City: " << cityarray[3].name << " Has the highest temperature of: " << cityarray[3].temp << endl;;
}
void lTemp(City cityarray[4]) // doing the opposite of hTemp
{
	cout << "City: " << cityarray[0].name << " Has the lowest temperature of: " << cityarray[0].temp << endl;
}
static int binSearch(City cityarray[4])
{
	cout << "==========================" << endl;
	cout << "      Binary Search       " << endl;
	cout << "==========================" << endl;
	cout << endl;
	cout << "Please input the temperature you want to search for." << endl;
	cout << "Input: ";
	int key = 0; //key for user input
	cin >> key;
	int first = 0; //first and last index 
	int last = 3;
	int mid = 0; //setting mid to 0 now 
	while (first <= last) 
	{
		mid = (first + last) / 2;  //getting middle value of array
		if (key > cityarray[mid].temp)
			first = mid + 1; //if input is higher ignore the lower part of the array 
		else if (key < cityarray[mid].temp) //vice versa
			last = mid - 1;
		else
			return mid;
	}
	return -1;
}