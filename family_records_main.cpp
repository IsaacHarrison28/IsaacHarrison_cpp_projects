#include <iostream>
#include <vector>

using namespace std;

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
    
}




int main(void)
{
    return 0;
}