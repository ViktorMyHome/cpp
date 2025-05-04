#include <iostream>
#include <assert.h>
#include <vector>
#include <math.h>
using namespace std;

// virtual = run-time polymorphism, dynamic/late binding
// non-virtual = compile time polymorphism, static/early binding
// allowing us to write generic code (process(shapes)), without knowing exact children
// extensibility/flexibility/code reuse

bool isSubstring(const string& str1, const string& str2){
    for(int i=0; i<str1.size(); i++){
        if(str1[i] == str2[0]){
            ++i;
            for(int j=1; j<str2.size(); j++,i++){
                if(str1[i]!=str2[j]){
                    return false;
                } else if(j==str2.size()-1){
                    return true;
                }
            }
        }
    }
}

int convert(const string& str){
    int sum = 0;
    for(int i=str.size()-1; i>=0; --i){
        int temp = str[i] - '0';
        temp = temp * pow(10, str.size()-1-i);
        //cout<<str[i]<<" "<<temp<<endl;
        sum += temp;
    }
    return sum;
}

string divide(const string& str){
    string strout{""};
    bool prev = false;
    for(int i=0;i<str.size()-1;++i){
        if(str[i]==str[i+1]){
            strout+=str[i];
            prev = true;
        } else if(prev == true){
            strout+=str[i];
            strout+=" ";
            prev = false;
        }
    }
    return strout;
}

string compress(const string& str){
    string strout{""};
    int counter=0;
    for(int i=1; i<str.size()+1; i++){
        if(str[i]==str[i-1]){
            if(i==1)
                counter=2;
            else
                counter++;
        } else {
            strout+=str[i-1];
            strout+=to_string(counter);
            strout+="_";
            counter = 0;
        }
    }
    return strout;
}


string add(const string& str1, const string& str2){
    int s1=0;
    int s2=0;
    int s3=0;
    s1 = convert(str1);
    s2 = convert(str2);
    s3 = s1+s2;
    return to_string(s3);

}

int main(){

cout<<isSubstring("ABCDEFG", "DEF")<<endl;
cout<<isSubstring("ABCDEFG", "ABC")<<endl;
cout<<isSubstring("ABCDEFG", "ABCEF")<<endl;

cout<<convert("0200")<<endl;

cout<<divide("AAAHHHkkkk")<<endl;
string str;
cin>>str;
cout<<compress(str)<<endl;

string str1, str2;
cin>>str1;
cin>>str2;
cout<<add(str1, str2);


return 0;
}
