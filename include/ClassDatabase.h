#ifndef CLASSDATABASE_H
#define CLASSDATABASE_H
#include <iostream>
#include <fstream>
#include <sstream>
#define MAX 100

using namespace std;

typedef struct studentNode{
    string id,name,course;
    float quiz,assignment,project,termExam;
}STUDENT_NODE;

typedef struct subjectCode{
    STUDENT_NODE sn[MAX];
    string subject;
    int indexSC = 0;
}SUBJECT_CODE;

typedef struct classRecord{
    SUBJECT_CODE sc[MAX];
    int indexCR = 0;
}CLASS_RECORD;


class ClassDatabase
{
    public:
        ClassDatabase();
        virtual ~ClassDatabase();

        CLASS_RECORD CR;

        void upload(){
            ofstream outFile;

            outFile.open("ClassRecordDataBase.dat");
            outFile.clear();
            // Format of saving is Subject Code / ID number / Course / Quiz / Assignment / Term Exam / Project
            for (int x=0;x<=CR.indexCR;x++){
                for(int y=0 ; y<=CR.sc[x].indexSC ; y++){
                    // This saves the subject code on the start of the line
                    outFile << CR.sc[x].subject << "\n";
                    // This saves all student data under the subject code
                    outFile << CR.sc[x].sn[y].name << "\n" << CR.sc[x].sn[y].id << "\n" << CR.sc[x].sn[y].course << "\n"
                    << CR.sc[x].sn[y].quiz << "\n" << CR.sc[x].sn[y].assignment << "\n" << CR.sc[x].sn[y].termExam << "\n"
                    << CR.sc[x].sn[y].project <<endl;
                }
            }
            outFile << "END";
            outFile.close();
        }

        void download(){
            ifstream inFile;
            string subject,name,id,course,next;
            int quiz, assignment, termExam,project;

            inFile.open("ClassRecordDataBase.dat");
                inFile >> subject;
                again:
                inFile >> name;
                inFile >> id;
                inFile >> course;
                inFile >> quiz;
                inFile >> assignment;
                inFile >> termExam;
                inFile >> project;
                addSubCodeDownload(subject,name,id,course,quiz,assignment,termExam,project);
                inFile >> next;
                if(next != "END"){
                    subject = next;
                    goto again;
                }
            inFile.close();
        }

        void addSubCodeDownload(string subCode,string nme, string idNumber, string course, int quiz, int assignment,int term, int project){
            int indexSC;

            again:
            indexSC = searchSubCode(subCode);
            if(indexSC == -1){
                addSubCode(subCode);
                goto again;
            }else{
                addStudentData(indexSC,nme,idNumber,course,quiz,project,term,assignment);
            }
        }

        void makeNULLSC(){
            CR.indexCR = -1;
        }

        void makeNULLST(){
            for (int i=0 ; i<MAX ; i++){
                CR.sc[i].indexSC=-1;
            }
        }

        bool isClassRecordEmpty(){
            return (CR.indexCR == -1);
        }

        bool isStudentNodeEmpty(int subCode){
            return (CR.sc[subCode].indexSC == -1);
        }

        bool isClassRecordFull(){
            return (CR.indexCR == MAX);
        }

        bool isStudentNodeFull(int subCode){
            return (CR.sc[subCode].indexSC == MAX);
        }


        void addSubCode(string subCode){
            CR.indexCR++;
            CR.sc[CR.indexCR].subject = subCode;
        }

        void editSubCode(int scIndex, string subcode){
            CR.sc[scIndex].subject=subcode;
        }

        void deleteSubCode(int scIndex){
            int i;
            for (i = CR.indexCR ; i <= MAX ; i++)
                CR.sc[i].subject = CR.sc[i++].subject;
            CR.indexCR--;
        }

        int searchSubCode(string querrySC){
            for (int i=0 ; i<=CR.indexCR; i++){
                if ( querrySC == CR.sc[i].subject )
                    return i;
            } return -1;
        }

        void addStudentData(int crIndex, string nme,string ident,string crse, int qz, int proj, int tExam, int assgn){
            CR.sc[crIndex].indexSC++;
            CR.sc[crIndex].sn[CR.sc[crIndex].indexSC].name = nme;
            CR.sc[crIndex].sn[CR.sc[crIndex].indexSC].id = ident;
            CR.sc[crIndex].sn[CR.sc[crIndex].indexSC].course = crse;
            CR.sc[crIndex].sn[CR.sc[crIndex].indexSC].quiz = qz;
            CR.sc[crIndex].sn[CR.sc[crIndex].indexSC].project = proj;
            CR.sc[crIndex].sn[CR.sc[crIndex].indexSC].termExam = tExam;
            CR.sc[crIndex].sn[CR.sc[crIndex].indexSC].assignment = assgn;
        }

        void editStudentData(int scIndex, int stIndex, string nme, string crse, int qz, int proj, int tExam, int assgn ){
            CR.sc[scIndex].sn[stIndex].name = nme;
            CR.sc[scIndex].sn[stIndex].course = crse;
            CR.sc[scIndex].sn[stIndex].quiz = qz;
            CR.sc[scIndex].sn[stIndex].project = proj;
            CR.sc[scIndex].sn[stIndex].termExam = tExam;
            CR.sc[scIndex].sn[stIndex].assignment = assgn;
        }

        void deleteStudentData(int scIndex, int stIndex){
            for (int i = CR.sc[scIndex].indexSC ; i < MAX ; i++)
            {
                CR.sc[scIndex].sn[i].name = CR.sc[scIndex].sn[i++].name;
                CR.sc[scIndex].sn[i].id = CR.sc[scIndex].sn[i++].id;
                CR.sc[scIndex].sn[i].course = CR.sc[scIndex].sn[i++].course;
                CR.sc[scIndex].sn[i].quiz = CR.sc[scIndex].sn[i++].quiz;
                CR.sc[scIndex].sn[i].assignment = CR.sc[scIndex].sn[i++].assignment;
                CR.sc[scIndex].sn[i].termExam = CR.sc[scIndex].sn[i++].termExam;
                CR.sc[scIndex].sn[i].project = CR.sc[scIndex].sn[i++].project;
            }
            CR.sc[scIndex].indexSC--;
        }

        int searchStudentData(string querryST,int indexSC){
            for (int i=0 ; i<=CR.sc[indexSC].indexSC ; i++){
                if ( querryST == CR.sc[indexSC].sn[i].id )
                    return i;
            } return -1;
        }

        void viewStudentData(int indexSC, int indexST ){
            cout << viewSTDataElements [0] << CR.sc[indexSC].subject << endl;
            cout << viewSTDataElements [1] << CR.sc[indexSC].sn[indexST].id << endl;
            cout << viewSTDataElements [2] << CR.sc[indexSC].sn[indexST].name << endl;
            cout << viewSTDataElements [3] << CR.sc[indexSC].sn[indexST].course << endl;
            cout << viewSTDataElements [4] << grade(indexSC,indexST)<< endl;
        }

        void viewSubjectCodeData(int indexSC){
            cout << viewSCDataElements[0] << CR.sc[indexSC].subject <<" || "<<viewSCDataElements[1] << CR.sc[indexSC].indexSC +1 << endl;
            cout << "\n" << viewSCDataElements[2] << endl;
            for (int i=0 ; i<=CR.sc[indexSC].indexSC ; i++){
                cout << i+1 << ".) " << CR.sc[indexSC].sn[i].name << " / " << CR.sc[indexSC].sn[i].id << " / " <<
                    CR.sc[indexSC].sn[i].course << " / " << grade(indexSC,i) << endl;
            }
        }

        void viewAllData(){
            for (int x=0;x<=CR.indexCR;x++){
                system_clear();
                cout <<viewAllDataElements[0] << CR.sc[x].subject <<" || "<<viewAllDataElements[1] << CR.sc[x].indexSC +1 << endl;
                cout << viewAllDataElements[2] << endl;

                for(int y=0 ; y<=CR.sc[x].indexSC ; y++){
                    cout << y+1 << ".) " << CR.sc[x].sn[y].name << " / " << CR.sc[x].sn[y].id << " / " <<
                    CR.sc[x].sn[y].course << " / " << grade(x,y) << endl;
                }
                cout <<viewAllDataElements[3];
                system_pause();
            }
        }

    protected:
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

        float grade(int indexSC, int indexST){
            return (CR.sc[indexSC].sn[indexST].quiz*.20)+(CR.sc[indexSC].sn[indexST].assignment*.10)+
                (CR.sc[indexSC].sn[indexST].project*.30)+(CR.sc[indexSC].sn[indexST].termExam*.40);
        }

    private:
        string viewSCDataElements[3]={"Subject Code: ", "Number of Students: ","<< Name / ID Number / Course / Grade >>"};
        string viewSTDataElements[5]={"Subject Code: ", "ID Number: ","Name: ", "Course: ", "Grade: "};
        string viewAllDataElements[4]={"Subject Code: ", "Number of Students: ","<< Name / ID Number / Course / Grade >>",
                                        "Press Enter key to continue"};
};

#endif // CLASSDATABASE_H
