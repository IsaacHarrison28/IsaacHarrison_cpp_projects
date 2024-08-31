#include <iostream>
#include <vector>
#include <string>

using namespace std;

//ANSI color codes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

//person definition. Each person must follow this structure
struct person_details{
    string full_name;
    int age;
    bool leader;
    string education_level;
    bool working;
    string family;
    vector<string> suspected_genetic_illnesses;  //every person of the same family will have similar genetic data attached as a vector just in case they can be more than one and for dynamic behaviour of vector as opposed to array
};

struct Family_details{
  string family_name;
  int family_size;
  vector<string> family_genetic_diseases; 
};


//function that handles the family addition logic
void add_family_genetic_disease(vector<string>& diseases_record){
    string user_choice;
    string disease;
    
    do{
        cout << "Enter a disease: ";
        cin.ignore();
        getline(cin, disease);
        diseases_record.push_back(disease);
        cout << GREEN << "\nDisease successfully recorded." << RESET << endl;
        cout << "Is there another disease you want to add? (Y, N) ";
        cin >> user_choice;
        cout << " " << endl;
    } while(user_choice[0] == 'Y' || user_choice[0] == 'y');
};

class Family{
    public:
        Family_details family;
        void setFamily_details(){
            cout << BLUE << "We advice that you provide as accurate information as possible below: " << RESET << endl;
            cout << "What is the name of the family? ";
            getline(cin, family.family_name);
            cout << "How many members does the family currently have? ";
            cin >> family.family_size;
            cout << "Does any of the family members have a genetic disease? (Yes, No) ";
            string user_choice;
            cin.ignore();
            cin >> user_choice;

            //check if the first letter is "N" or "n" for "NO" or "Y" or "y" for "YES"
            if(user_choice[0] == 'Y' || user_choice[0] == 'y'){
                add_family_genetic_disease(family.family_genetic_diseases);
            }

            cout << GREEN << "Thank you. Family data has been successfully added." << RESET << endl;
        }

        void getFamily_details(){
            cout << BLUE << "Family Name: " << RESET << family.family_name << endl;
            cout << BLUE << "Family Size: " << RESET << family.family_size << endl;
            if (!family.family_genetic_diseases.empty()) {
                cout << BLUE << "Genetic Diseases: " << RESET;
                for (const auto& disease : family.family_genetic_diseases) {
                    cout << "'" << disease << "'" << " ";
                }
                cout << endl;
            } else {
                cout << "No genetic diseases reported." << endl;
            }
        }
};




int main(void)
{
    return 0;
}