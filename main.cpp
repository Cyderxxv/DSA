#include "SortingAlgorithms.h"

int main(int argc, char* argv[]) 
{ 
	int Convert_element = ConvertToNum(argc, argv);
	if (Convert_element == -1) 
	{
		cout << " Error! Check input parameter again" << endl;
		return 0;
	}
	if (strcmp(argv[1], "-a") == 0) 
	{
		cout << "ALGORITHM MODE" << endl;
	}
	else 
	{
		cout << "COMPARISONS MODE" << endl;
	}
	switch (Convert_element)
		{
			case 1:{
				Command_line1(argc, argv);
				break;
			}
			case 2:{
				Command_line2(argc, argv);;
				break;
			}
			case 3:{
				Command_line3(argc, argv);;
				break;
			}
			case 4:{
				Command_line4(argc, argv);;
				break;
			}
			case 5:{
				Command_line5(argc, argv);;
				break;
			}
	
		}

    return 0;
}
