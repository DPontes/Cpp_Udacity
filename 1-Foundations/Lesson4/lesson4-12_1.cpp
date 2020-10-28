// Maps
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::string;

int main() {
    // Create strings to use in the hash table
    string key = "word";
    string def_1 = "A unit of language, consisting of one or more spoken sounds or their written representation, that functions as a principal carrier of meaning";
    string def_2 = "Speech or talk: to express one's emotion in words";
    string def_3 = "A short talk or conversation: 'Marston, I'd like a word with you.'";
    string def_4 = "An expression or utterance: a word of warning";
    unordered_map <string, vector<string>> my_dict;

    // Check if key is in the hash table
    if (my_dict.find(key) == my_dict.end()) {
        cout << "The key 'word' is nto in the dictionary." << endl;
        cout << "Inserting a key-value pair into the dictionary." << endl;
        cout << endl;
        // Set the value for the key
        my_dict[key] = vector<string> {def_1,def_2, def_3, def_4};
    }

    /*
        The key should now be in the hash table. You can access the value
        corresponding to the key with square brackets [].
        Here, the value my_dict[key] is a vector of strings.
        We iterate over the vector and print the strings
    */
    cout << key << ": " << endl;
    auto definitions = my_dict[key];
    for (string definition : definitions) {
        cout << definition << endl;
    }

    return 0;
}
