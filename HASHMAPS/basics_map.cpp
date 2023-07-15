#include <bits/stdc++.h>

using namespace std;
// usage of maps

int main(){
    
// creation
unordered_map<string,int> m;

// INSERTION

// TYPE 1
    pair<string, int> p = make_pair("Flash", 3);
    m.insert(p);

// TYPE 2
    pair<string, int> pair2("Allen", 2);
    m.insert(pair2);

// TYPE 3
    m["Barry"] = 1; 


// Search for key

    cout<< m["Flash"]<< endl;
    cout<< m.at("Barry")<<endl;
    // cout<< m.at("UnknownKey")<<endl; //this will give error
    cout<< m["UnknownKey"]<<endl; //will create a new entry with 0
    cout<< m.at("UnknownKey")<<endl; // now it will display 0

// Total Size
    cout<<"Total Count:  "<<m.size()<<endl;

// To check presence
    cout<<m.count("Bruce") <<endl;  // 0 -> not present
    cout<<m.count("Barry") <<endl;  // 1 -> present


// To erase;
     
    m.erase("Allen");
    cout<<"After erase the count is: "<< m.size() << endl;


// ITERATOR
    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()) {
        cout<< it-> first << " " << it->second<<endl;
        it++;
    } 

    return 0;
}