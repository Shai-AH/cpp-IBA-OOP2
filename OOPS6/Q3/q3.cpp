#include <iostream>

using namespace std;

class Logger{
public:
    void log(string message){
        cout << "LOG";
    }
};

class FileManager : private Logger{
public:
    void saveFile(string filename){
        log("Save Action");
        cout << "File Saved: " << filename;
    }
};

int main(){
    FileManager f1;
    f1.saveFile("text.exe");
//    f1.Logger :: log("Save");
//error: 'class Logger Logger::Logger' is inaccessible within this context
//Basically log become private in Filemanager object
}
