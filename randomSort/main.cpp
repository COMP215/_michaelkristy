//
//  main.cpp
//  randomSort
//
//  Created by Michael Kristy on 9/5/16.
//  Copyright © 2016 Michael Kristy. All rights reserved.
//

using namespace std;

#include <iostream>
#include <random>
#include <fstream>
#include <ctime>
#include <algorithm>


int RUNAMOUNT = 600;

void createRandomStrings();
string* sortingMess();
void runAgain(string*);

int main(int argc, const char * argv[]) {
    srand ( time(NULL) );
    
    createRandomStrings();
    sortingMess();
    
    
    return 0;
}

void createRandomStrings(){
    
    fstream stringStore;
    stringStore.open("stringKeeper.txt", fstream::out);
    
    char alphabet [] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    string *wordHolder = new string[RUNAMOUNT];
    
    int letterPick = 0;
    int howLongString = 0;
    
    string wordMaker = "";
    
    for (int i = 0; i < RUNAMOUNT; i++){
        howLongString = rand() % 20;
        wordMaker = "";
        
            for(int h = 0; h <= howLongString; h++){
                    letterPick = rand() % 26;
                    wordMaker = wordMaker + alphabet[letterPick];
                }
        
        wordHolder[i] = wordMaker;
        cout << wordHolder[i] << endl;
        stringStore << wordHolder[i] << endl;
    }
}

string* sortingMess(){
    
    int i = 0;
    
    string arrayElement = "";
    string *impArrayElement = new string[RUNAMOUNT];
    
    fstream stringLooker;
    stringLooker.open("stringKeeper.txt", fstream::in);
    
    while ( getline (stringLooker,arrayElement)){
        impArrayElement[i] = arrayElement;
        i++;
    }
    
    int x = 1;

    while(x >= 1){
        int j = 0;
        x = 0;
        for(int i = 0; i <= RUNAMOUNT; i++){
            if(j == RUNAMOUNT - 1){
                j = 0;
            }
            if(impArrayElement[j] < impArrayElement[j+1]){
                j++;
            }
            else if(impArrayElement[j] > impArrayElement[j+1]){
                runAgain(impArrayElement);
                x++;
            }
        
        }
    }
    return(impArrayElement);

}
    void runAgain(string* impArrayElement){
        int k = 0;
        for (int i = 0; i < RUNAMOUNT - 1; i++){
            
            string word1 = impArrayElement[i];
            string word2 = impArrayElement[i+1];
            
            if(word1 > word2){
                impArrayElement[i] = word2;
                impArrayElement[i + 1] = word1;
            }
            
            else if(word1 < word2){
                for(int i = 0; i < RUNAMOUNT - 1 ; i++){
                    if(word1 < word2){
                    word1 = impArrayElement[i];
                    word2 = impArrayElement[i+1];
                    }
                }
            }

            else if(word1[k] == word2[k]){
                while(word1[k] == word2[k]){
                    k++;
                if(word1[k] > word2[k]){
                    impArrayElement[i] = word2;
                    impArrayElement[i+1] = word1;
                    }
                }

            }
        }
    
    
    cout << "-------------------------" << endl;
    
    
    for(int j = 0; j < RUNAMOUNT; j++){
        cout << impArrayElement[j] << endl;
    }
}
