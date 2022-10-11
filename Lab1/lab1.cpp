#include<bits/stdc++.h>
using namespace std;

bool is_alpha(char ch){
    if((ch>='A' && ch<='Z') || (ch>='a' && ch<= 'z'))
        return true;
    else
        return false;
}
bool is_digit(char x){
    string s="0123456789";
    for(int i=0;i<s.length();i++){
        if(s[i]==x){
            return true;
        }
    }
    return false;
}
string Is_operator(string s){
    vector<string>v={"+","-","","/","++","--","!","%","!=","=","==","+=","-=","/=","=",
    "<","<=",">",">=","%=","^","^=","&","&=","&&","||"};
    for(int i=0;i<v.size();i++){
        if(v[i]==s){
            return "operator";
        }
    }
    return "Not_an_operator";
}
string Is_identifier(string s){
    int flag=1;
    if(is_alpha(s[0])||s[0]=='_'){
        flag=1;
    }else{
        flag=0;
    }
    if(flag==1){
        for(int i=1;i<s.size();i++){
            if(!(is_alpha(s[i])||is_digit(s[i])||s[i]=='_')){
                flag=0;
                break;
            }
        }
    }
    if(flag==0){
        return "Invalid identifier";
    }
    return "identifier";
}

string Is_keyword(string s){
    vector<string>v={"asm", "new", "double", "switch", "auto", "else", "operator", "template", "break", "enum","private", "throw", "catch", "this", "case", "extern", "protected", "throw", "catch", "float", "public", "try", "char", "for", "register", "typedef", "class", "friend", "return", "union", "const", "goto", "short", "unsigned", "continue", "if", "signed", "virtual", "default", "inline", "sizeof", "void", "delete", "int", "static", "volatile", "do", "long", "struct", "while"};
    int flag=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==s){
            flag=1;
            break;
        }
    }
    if(flag==0){
        return "Not a keyword";
    }
    return "keyword";
}

int main(){
    string t;
    ifstream myfile("example.txt");
    if(myfile.is_open()){
        while(getline(myfile,t)){
            stringstream x(t);
            string s;
            while(getline(x,s,' ')){
                cout<<s<<endl;
                int flag=0;
                string o=Is_operator(s);
                if(o=="operator"){
                    cout<<s<<" : "<<o<<endl;
                    flag=1;
                }

                if(flag==0){
                    string k=Is_keyword(s);
                    if(k=="keyword"){
                        cout<<s<<" : "<<k<<endl;
                        flag=1;
                    }
                }

                if(flag==0){
                    string i=Is_identifier(s);
                    if(i=="identifier"){
                        cout<<s<<" : "<<i<<endl;
                        flag=1;
                    }
                }
    
                if(flag==0){
                    cout<<s<<" : "<<"constant"<<endl;
                }
            }
        }
    }
    return 0;
}