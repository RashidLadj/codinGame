#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/******** Methods ********/
string morse(const string& word);
long solve(const string &sequence, const int &start, const unordered_map<string, int> &morseWords, vector<long> &resultTemp);

/******** Variables ********/
int max_ = 0;
int min_ = 80;  /** max 20 word * 4 caracter in morse encoder **/

/******** Main program ********/
int main(){

    unordered_map<string, int> morseWords;

    string morseSequence; // sequence morse
    cin >> morseSequence; cin.ignore();

    vector<long> resultTemp  = vector<long> (morseSequence.length() + 1, -1);

    int dictionarySize ; // number of words in dictionary
    cin >> dictionarySize ; cin.ignore();


    for (int i = 0; i < dictionarySize ; ++i) {
        string morseWord ;
        cin >> morseWord ; cin.ignore();
        morseWord = morse(morseWord);
        

        /******** Update min and max ********/
            if (morseWord.length() > max_)
                max_ = morseWord.length();

            if (morseWord.length() < min_)
                min_ = morseWord.length();
        /************************************/


        /****************************************************************************************************************
        ** This is for optimization in solve method                                                                    **
        ** if x different word have same morse code, we just give value "x" to the key "morseWord"                     **
        ** the goal is to avoid looping multiple times on equivalent words when we can just do a simple multiplication **
        ****************************************************************************************************************/
        if (morseWords[morseWord])
            ++morseWords[morseWord];
        else 
            morseWords[morseWord] = 1;
    }

    cout << solve(morseSequence, 0, morseWords, resultTemp) << endl;

}

string morse(const string& word){
    std::vector<string> morse = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
        "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
        "-.--", "--.."
    };

    string result = "";
    for (int i = 0; i < word.length(); ++i){
        result += morse[word[i] - 65];
    }
    return result;
}


long solve(const string &sequence, const int &start, const unordered_map<string, int> &morseWords, vector<long> &resultTemp){
    if ( start == sequence.length()){
        return 1;
    }

    if (resultTemp [start] != -1)
        return resultTemp [start];

    long cpt = 0;

    /** less optimized **/
    // for (const auto & word : morseWords ){
    //     if (word.second>0)
    //         if (word.first == sequence.substr(start, word.first.length())){
    //             cpt += word.second * solve_(sequence, start + word.first.length());
    //         }
    // }

    /** More optimized **/
    for (int i = min_ ; i <= max_  && start + i  <= sequence.length(); ++i){
        string s =  sequence.substr(start, i);
        int occ = 0;
        try {
            occ = morseWords.at(s);      // unordered_map::at throws an out-of-range if key odn't exsit
            if (occ > 0){
                cpt += occ * solve(sequence, start + i, morseWords, resultTemp);
            }
        }catch(const std::out_of_range& oor) {
        }
    } 
    
    return  resultTemp [start] = cpt; 
}