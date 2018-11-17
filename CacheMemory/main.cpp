//
//  main.cpp
//  CacheMemory
//
//  Created by Bishal Blue on 17/11/18.
//  Copyright © 2018 Bishal Blue. All rights reserved.
//

#include <iostream>
#include<fstream>
#define CACHE_SIZE 10

using namespace std;

static int counter[CACHE_SIZE];
static string cacheMem[CACHE_SIZE];

int main() {
    
    ifstream infile;
    infile.open("afile.dat");
    /*The file afile.dat should be in format of strings only
     *Like -
     *bishal
     *jeevan
     *subrat
     *and so on
     */
    cout<<"Reading from file"<<endl;

    
    //read each line
    for(string str ; getline(infile, str);){
        
        bool counted=false;
        int i,j;
        for(i=0;i<CACHE_SIZE;i++){
            
            //compare string
            if (str == cacheMem[i]) {
                counter[i]++;   //if matched increment counter
                counted = true;
                break;
            }
        }
        
         if (!counted) {
            //new entry
            for(i=0;i<CACHE_SIZE;i++){
                //new cache
                if(cacheMem[i] == ""){
                    goto assign;
                }
            }
                //replace cache
            if(i==CACHE_SIZE){
                //Set initial least and replaceindex
                int least=100,rindex = 0;
                for(j =0; j<CACHE_SIZE;j++){
                    if(counter[j]< least){
                        least = counter[j]; //update least value
                        rindex = j; //update the index that is to be replaced
                    }
                }
                //Replace the least recently used into cache
                cacheMem[rindex] = str;
                counter[rindex] = 1;
                counted=true;
            }
        }
        assign:
        if(!counted){
            cacheMem[i] = str;
            counter[i] = 1;
        }

   }
    infile.close();
    cout<<"Cache \tCounter"<<endl;
    for(int i = 0; i < CACHE_SIZE; i++){
        cout<<cacheMem[i]<<"\t"<<counter[i]<<endl;
    }
    return 0;
}
