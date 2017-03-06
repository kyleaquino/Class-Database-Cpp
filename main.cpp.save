
//Class Database Project of Kyle Aquino For Data Structures Subject.

/*
Error Handling
1. Same subject code and student id
2. confirmation dialogs
3. cancel inputs
4.
*/

#include <iostream>
#include <MenuComponents.h>
#include <ClassDatabase.h>

using namespace std;

ClassDatabase DB;

// String Variables for ease of printing
string headerElements[]={"CLASS RECORD PROJECT By: Kyle Aquino\n\n", "<< Add Student Data >>\n","<< Edit Student Data >>\n",
                            "<< Delete Student Data >>\n", "<< Search Student Data >>\n", "<< View Student Data >>\n",
                            "<< Add Subject Code>>\n", "<< Edit Subject Code >>\n","<< Delete Subject Code >>\n",
                            "<< Search Subject Code >>\n", "<< View Subject Code>>\n",">>INSERT SUCCESS!",">>DELETE SUCESS",
                            ">>EDIT SUCESS","<< View All Data >>\n"};
string errorElements[]={"\n>>ERROR: Student Database Full<<", "\n>>ERROR: Class Database Full<<", "\n>>ERROR: Student Database Empty<<\n",
                            "\n>>ERROR: Class Database Empty<<\n","\n>>ERROR: Wrong Input<<\n","\n>>ERROR: Data Not Found<<",
                            "\n>>ERROR: ID number already used <<","\n>>ERROR: Subject Code already used <<"};
string insertElements[]={"Insert Name: ","Insert ID Number: ", "Insert Course: ", "Insert Subject Code: ", "Insert Quiz Score: ",
                            "Insert Assignment Score: ", "Insert Term Exam Score: ", "Insert Project Score: "};
string searchElements[]={"Search Subject Code: ", "Search Student Data"};

void system_clear(){// Cross-Platform clear
    #ifdef WINDOWS
        system("cls");
    #else
        system ("clear");
    #endif
}

void system_pause(){// Cross-Platform pause
    cin.get(); cin.get();
}


void addStudentModule(string subjectCode,int indexSC){
    string name, id, course;
    int quiz, assignment, termExam, project;

    system_clear();
    cout << headerElements[0] << headerElements[1] << "Subject Code: " + subjectCode << endl;
    cout << insertElements[0];
    cin >> name;
    cout << insertElements[1];
    cin >> id;
    cout << insertElements[2];
    cin >> course;
    cout << insertElements[4];
    cin >> quiz;
    cout << insertElements[5];
    cin >> assignment;
    cout << insertElements[6];
    cin >> termExam;
    cout << insertElements[7];
    cin >> project;
    DB.addStudentData(indexSC,name,id,course,quiz,project,termExam,assignment);


}

void addStudent(){
    int indexSC;
    string subjectCode;

    system_clear();
    cout << headerElements[0] << headerElements[1];
    if (DB.isClassRecordEmpty()){// Check if class record is Empty
        cout << errorElements[3];
        system_pause();
    }else{
        cout << searchElements[0];
        cin >> subjectCode;
        indexSC = DB.searchSubCode(subjectCode);
        if(indexSC == -1){ // Check if the Subject Code is in the system
            cout << errorElements[5];
            system_pause();
        }else{
            if(DB.isStudentNodeFull(indexSC)){ // Check if the student database is full
                cout << errorElements[0];
                system_pause();
            }else{ // Main Function for add student
                addStudentModule(subjectCode,indexSC);
                cout << headerElements[11];
                system_pause();
            }
        }
    }

};

void editStudentModule(string subjectCode, string studentID, int indexSC, int indexST){
    string name,course;
    int quiz, assignment, termExam, project;

    system_clear();
    cout << headerElements[0] << headerElements[2] << ">> Subject Code: " + subjectCode << "\n>> Student ID: " + studentID << endl;
    cout << insertElements[0];
    cin >> name;
    cout << insertElements[2];
    cin >> course;
    cout << insertElements[4];
    cin >> quiz;
    cout << insertElements[5];
    cin >> assignment;
    cout << insertElements[6];
    cin >> termExam;
    cout << insertElements[7];
    cin >> project;
    DB.editStudentData(indexSC,indexST,name,course,quiz,project,termExam,assignment);
}

void editStudent(){
    int indexSC,indexST;
    string subjectCode,querryID;

    system_clear();
    cout << headerElements[0] << headerElements[2];
    if (DB.isClassRecordEmpty()){// Check if class record is Empty
        cout << errorElements[3];
        system_pause();
    }else{
        cout << searchElements[0];
        cin >> subjectCode;
        indexSC = DB.searchSubCode(subjectCode);
        if(indexSC == -1){ // Check if the Subject Code is in the system
            cout << errorElements[5];
            system_pause();
        }else{
            if(DB.isStudentNodeEmpty(indexSC)){ // Check if the student database is Empty
                cout << errorElements[2];
                system_pause();
            }else{
                cout << insertElements[1];
                cin >> querryID;
                indexST = DB.searchStudentData(querryID,indexSC);
                if (indexST == -1){// Check if student data is in the subject code
                    cout << errorElements[5];
                }else{ // Main Function for Edit student data
                    editStudentModule(subjectCode,querryID,indexSC,indexST);
                    cout << headerElements[11];
                    system_pause();
                }
            }
        }
    }
}

void deleteStudent(){
    int indexSC,indexST;
    string subjectCode,querryID;

    system_clear();
    cout << headerElements[0] << headerElements[3];
    if (DB.isClassRecordEmpty()){// Check if class record is Empty
        cout << errorElements[3];
        system_pause();
    }else{
        cout << searchElements[0];
        cin >> subjectCode;
        indexSC = DB.searchSubCode(subjectCode);
        if(indexSC == -1){ // Check if the Subject Code is in the system
            cout << errorElements[5];
            system_pause();
        }else{
            if(DB.isStudentNodeEmpty(indexSC)){ // Check if the student database is Empty
                cout << errorElements[2];
                system_pause();
            }else{
                cout << insertElements[1];
                cin >> querryID;
                indexST = DB.searchStudentData(querryID,indexSC);
                if (indexST == -1){// Check if student data is in the subject code
                    cout << errorElements[5];
                }else{ // Main Function for Edit student data
                    DB.deleteStudentData(indexSC,indexST);
                    cout << headerElements[12];
                    system_pause();
                }
            }
        }
    }
}

void addSubject(){
    string subjectCode;

    system_clear();

    if(DB.isClassRecordFull()){ // Check if class database is full
        cout << headerElements[0] << headerElements[6] << errorElements[1];
    }else{
        cout << headerElements[0] << headerElements[6];
        cout << insertElements[3];
        cin >> subjectCode;
        DB.addSubCode(subjectCode);
        cout << headerElements[11];
        system_pause();
    }
}

void editSubject(){
    string subjectCode;
    int indexSC;

    system_clear();

    if(DB.isClassRecordEmpty()){ // Check if the database is empty
        cout << headerElements[0] << headerElements[7] << errorElements[3];
        system_pause();
    }else{
        cout << headerElements[0] << headerElements[7];
        cout << insertElements[3];
        cin >> subjectCode;
        indexSC = DB.searchSubCode(subjectCode);
        if (indexSC == -1){ // Check if subject code is in the database
            cout << errorElements[5];
            system_pause();
        }else{
            cout << insertElements[3] << "(New Data): ";
            cin >> subjectCode;
            DB.editSubCode(indexSC,subjectCode);
            cout << headerElements[13];
            system_pause();
        }
    }
};

void deleteSubject(){
    string subjectCode;
    int indexSC;

    system_clear();

    if(DB.isClassRecordEmpty()){ // Check if the database is empty
        cout << headerElements[0] << headerElements[8] << errorElements[3];
        system_pause();
    }else{
        cout << headerElements[0] << headerElements[8];
        cout << insertElements[3];
        cin >> subjectCode;
        indexSC = DB.searchSubCode(subjectCode);
        if (indexSC == -1){ // Check if subject code is in the database
            cout << errorElements[5];
            system_pause();
        }else{
            DB.deleteSubCode(indexSC);
            cout << headerElements[12];
            system_pause();
        }
    }
};

void viewStudent(){
    int indexSC,indexST;
    string subjectCode,querryID;

    system_clear();
    cout << headerElements[0] << headerElements[5];
    if (DB.isClassRecordEmpty()){// Check if class record is Empty
        cout << errorElements[3];
        system_pause();
    }else{
        cout << searchElements[0];
        cin >> subjectCode;
        indexSC = DB.searchSubCode(subjectCode);
        if(indexSC == -1){ // Check if the Subject Code is in the system
            cout << errorElements[5];
            system_pause();
        }else{
            if(DB.isStudentNodeEmpty(indexSC)){ // Check if the student database is Empty
                cout << errorElements[2];
                system_pause();
            }else{
                cout << insertElements[1];
                cin >> querryID;
                indexST = DB.searchStudentData(querryID,indexSC);
                if (indexST == -1){// Check if student data is in the subject code
                    cout << errorElements[5];
                }else{ // Main Function for View student data
                    system_clear();
                    cout << headerElements[0] << headerElements[5];
                    DB.viewStudentData(indexSC,indexST);
                    system_pause();
                }
            }
        }
    }
}

void viewSubject(){
    string subjectCode;
    int indexSC;

    system_clear();

    if(DB.isClassRecordEmpty()){ // Check if the database is empty
        cout << headerElements[0] << headerElements[10] << errorElements[3];
        system_pause();
    }else{
        cout << headerElements[0] << headerElements[10];
        cout << insertElements[3];
        cin >> subjectCode;
        indexSC = DB.searchSubCode(subjectCode);
        if (indexSC == -1){ // Check if subject code is in the database
            cout << errorElements[5];
            system_pause();
        }else{
            system_clear();
            cout << headerElements[0] << headerElements[10];
            DB.viewSubjectCodeData(indexSC);
            system_pause();
        }
    }
}

void viewAll(){
    system_clear();
    if(DB.isClassRecordEmpty()){ // Check if the database is empty
        cout << headerElements[0] << headerElements[14] << errorElements[3];
        system_pause();
    }else{
        cout << headerElements[0] << headerElements[14];
        DB.viewAllData();
    }
}

int main(){

    MenuComponents menu;
    int menuOption;

    DB.makeNULLSC();
    DB.makeNULLST();
    DB.download();
    while(1)
    {
        system_clear();
        menuOption=menu.runMenu();
        switch (menuOption){
            case 1: addSubject(); system_clear(); break; // Add Subject Code
            case 2: addStudent(); system_clear(); break; // Add Student Data
            case 3: editSubject(); system_clear(); break; // Edit Subject Code
            case 4: editStudent(); system_clear(); break; // Edit Student Data
            case 5: deleteSubject(); system_clear(); break; // Delete Subject Code
            case 6: deleteStudent(); system_clear(); break; // Delete Student Data
            case 7: viewSubject(); system_clear(); break; // View Subject Code
            case 8: viewStudent(); system_clear(); break; // View Student Data
            case 9: viewAll(); system_clear(); break; // View All Data
            case 10: DB.upload(); system_clear(); exit(0); break; // Exit Program

        }
    }

}
