#include <iostream>
#include <vector>
#include <string>

using namespace std;

//ANSI definition of some colors used in the project
#define BLUE    "\033[34m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

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
        cout << "\nDisease successfully recorded." << GREEN << endl;
        cout << "Is there another disease you want to add? (Y, N) ";
        cin >> user_choice;
    } while(user_choice[0] == 'Y' || user_choice[0] == 'y');
};

class Family{
    public:
        Family_details family;
        int setFamily_details(){
            cout << "We advice that you provide as accurate information as possible below: " << BLUE << endl;
            cout << "What is the name of the family? ";
            getline(cin, family.family_name);
            cout << " " << endl;
            cout << "How many members does the family currently have? ";
            cin.ignore();
            cin >> family.family_size;
            cout << " " << endl;
            cout << "Does any of the family members have a genetic disease? (Yes, No) ";
            string user_choice;
            cin.ignore();
            cin >> user_choice;
            cout << " " << endl;

            //check if the first letter is "N" or "n" for "NO" or "Y" or "y" for "YES"
            if(user_choice[0] == 'Y' || user_choice[0] == 'y'){
                add_family_genetic_disease(family.family_genetic_diseases);
            }
        }
};




int main(void)
{
    return 0;
}