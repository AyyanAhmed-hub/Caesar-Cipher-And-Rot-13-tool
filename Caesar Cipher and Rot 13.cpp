#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encryptC(const string &text, int shift) {
    string result = "";
    for (size_t i = 0; i < text.length(); i++) {
        char c = text[i];
        
        if (isupper(c)) {
            result += char(int(c + shift - 'A') % 26 + 'A');
        }
       
        else if (islower(c)) {
            result += char(int(c + shift - 'a') % 26 + 'a');
        }
        
        else {
            result += c;
        }
    }
    return result;
}

string decryptC(const string &text, int shift) 
{
    return encryptC(text, 26 - shift); 
}

char encryptChar(char ch, int key) {
    if (isalpha(ch)) {
        char offset = isupper(ch) ? 'A' : 'a';
        return (ch - offset + key) % 26 + offset;
    } else if (isdigit(ch)) {
        return (ch - '0' + key) % 10 + '0';
    }
    return ch;
}

char decryptChar(char ch, int key) {
    if (isalpha(ch)) {
        char offset = isupper(ch) ? 'A' : 'a';
        return (ch - offset - key + 26) % 26 + offset;
    } else if (isdigit(ch)) {
        return (ch - '0' - key + 10) % 10 + '0';
    }
    return ch;
}

string encrypt(string text, int key) {
    string result = "";
    for (char ch : text) {
        result += encryptChar(ch, key);
    }
    return result;
}

string decrypt(string text, int key) {
    string result = "";
    for (char ch : text) {
        result += decryptChar(ch, key);
    }
    return result;
}

void encryptToFile(const string& data, int key, const string& outputFile) {
    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    string encryptedData = encrypt(data, key);
    outFile << encryptedData;
    outFile.close();
    	cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
    cout << "\t\t\t\tData encrypted and saved to " << outputFile << endl;
    	cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
}

void decryptFromFile(const string& inputFile, int key) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    string encryptedData((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    string decryptedData = decrypt(encryptedData, key);
	cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
    cout << "\t\t\t\tEncrypted data from file : " << encryptedData << endl;
    cout << "\t\t\t\tDecrypted data : " << decryptedData << endl;
	cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
    inFile.close();
}

int main() {
    int technique;
    do { 
    
    
    cout<<"\t\t\t______________________________________________________________________\n\n\n";
	cout<<"\t\t\t                          Welcome To Our Tool                        \n\n\n";
	cout<<"\t\t\t _____________________________    Menu    ____________________________  \n\n";
	cout<<"\t\t\t                                                                         \n\n";
	cout<<"\t\t\t\t\t _________________________________________\n";
	cout<<"\t\t\t\t\t|                                         |\n";
	cout<<"\t\t\t\t\t|       -> Press 1 For Caesar cipher      |\n ";
	cout<<"\t\t\t\t\t|       -> Press 2 For Rot 13             |\n";
	cout<<"\t\t\t\t\t|       -> Press 3 For Exit               |\n";
	cout<<"\t\t\t\t\t|_________________________________________|\n\n\n";
	cout<<"\t\t\t\t\t Enter Your Choice :  ";
	cin>>technique;
    
        

        switch (technique) {
            case 1: {
                int choice = 0;
                string filename, text, encryptedText, decryptedText;
                int shift;

                while (choice != 3) {
                   
                   system("cls");
	 cout<<"\t\t\t______________________________________________________________________\n\n\n";
	cout<<"\t\t\t                        Welcome To Ceaser Cipher                         \n\n\n";
	cout<<"\t\t\t _____________________________    Tool    ____________________________  \n\n";
	cout<<"\t\t\t                                                                         \n\n";
	cout<<"\t\t\t\t\t _________________________________________\n";
	cout<<"\t\t\t\t\t|                                         |\n";
	cout<<"\t\t\t\t\t|       -> Press 1 For Encryption         |\n ";
	cout<<"\t\t\t\t\t|       -> Press 2 For Decryption         |\n";
	cout<<"\t\t\t\t\t|       -> Press 3 For Exit               |\n";
	cout<<"\t\t\t\t\t|_________________________________________|\n\n\n";
	cout<<"\t\t\t\t\t Enter Your Choice :  ";
					cin >> choice;

                    if (choice == 1) { 
                    
                    	cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
                        cout << "\t\t\t\t\tEnter the file name to save the encrypted data: ";
                        cin >> filename;
                        cout << "\t\t\t\t\tEnter the text to encrypt: ";
                        cin.ignore(); 
                        getline(cin, text);
                        cout << "\t\t\t\t\tEnter the shift value: ";
                        cin >> shift;
                        cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";

                        encryptedText = encryptC(text, shift);

                        ofstream outFile(filename.c_str()); 
                        if (outFile.is_open()) {
                            outFile << encryptedText;
                            cout << "\t\t\t\t\tEncrypted text saved to " << filename << endl;
                            cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
                            outFile.close(); 
                            system("pause");
                        } else {
                            cerr << "Error opening file for writing!" << endl;
                        }

                    } else if (choice == 2) { 
                    	cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
                        cout << "\t\t\t\t\tEnter the file name containing encrypted data: ";
                        cin >> filename;
                        cout << "\t\t\t\t\tEnter the shift value used for encryption: ";
                        cin >> shift;
						cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
                        ifstream inFile(filename.c_str()); 
                        if (inFile.is_open()) {
                            getline(inFile, encryptedText);
                            decryptedText = decryptC(encryptedText, shift);
                            cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
                            cout << "\t\t\t\t\tEncrypted Text: " << encryptedText << endl;
                            cout << "\t\t\t\t\tDecrypted Text: " << decryptedText << endl;
                            cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
                            system("pause");
                            inFile.close(); 
                        } else {
                            cerr << "Error opening file for reading!" << endl;
                        }

                    } else if (choice == 3) { 
                        cout << "Exiting program. Goodbye!" << endl;
                    } else { 
                        cout << "Invalid choice! Please try again." << endl;
                    }
                }
                break;
            }

            case 2: {
                char choice;
                do {
                    char mode;
                    
                    system("cls");
                     cout<<"\t\t\t______________________________________________________________________\n\n\n";
					 cout<<"\t\t\t                          Welcome To Our Tool                        \n\n\n";
					 cout<<"\t\t\t _____________________________    ROT 13    ____________________________  \n\n";
					 cout<<"\t\t\t                                                                         \n\n";
					 cout<<"\t\t\t\t\t _________________________________________\n";
					 cout<<"\t\t\t\t\t|                                         |\n";
					 cout<<"\t\t\t\t\t|       -> Press 1 For Encryption         |\n ";
					 cout<<"\t\t\t\t\t|       -> Press 2 For Decryption         |\n";
				 	 cout<<"\t\t\t\t\t|       -> Press 3 For Exit               |\n";
					 cout<<"\t\t\t\t\t|_________________________________________|\n\n\n";
					 cout<<"\t\t\t\t\t Enter Your Choice :  ";
						cin>>mode;	

                    if (mode == '1') 
					
					{
                        cin.ignore(); // Clear the input buffer
                        string data, outputFile;
                        int key;

					cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
                        cout << "\t\t\t\tEnter the data to encrypt: ";
                        getline(cin, data);
                        key=13;
                        cout << "\t\t\t\tEnter the file to save encrypted data: ";
                        cin >> outputFile;
					cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
                        encryptToFile(data, key, outputFile);

                    }
					 else if (mode == '2')
					 {
                        string inputFile;
                        int key;

					cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
                        cout << "\t\t\t\tEnter the file to decrypt: ";
                        cin >> inputFile;
                        cout << "\t\t\t\tEnter the key: ";
                        cin >> key;
					cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
                        decryptFromFile(inputFile, key);
                    } 
					else
					 {
                     
					    cout << "Invalid choice. Please enter 'e' for encryption or 'd' for decryption." << endl;
                     
					 }

        cout << "Do you want to perform another operation? (y/n): ";
            cin >> choice;
                    
    } 
				while (choice == 'y' || choice == 'Y');
				
	cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";
                cout << "Program terminated. Goodbye!" << endl;
    	cout<<"\n\n\t\t\t\t*******************************************************************\n\n\n";            
                break;
            }

            case 3:
                cout << "Exiting...." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (technique != 3);

    return 0;
}
