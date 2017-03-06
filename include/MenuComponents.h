#ifndef MENUCOMPONENTS_H
#define MENUCOMPONENTS_H
#include <iostream>

using namespace std;

class MenuComponents
{
    public:
        MenuComponents();
        virtual ~MenuComponents();

        int runMenu(){
            again:
            system_clear();

            for(int i=0 ; i<=6 ; i++)
                cout << menuElements[i];
            cin >> choice;

            switch (choice)
            {
                case 1:{ retChoice=insertMenu();
                    if (retChoice!=-1)
                        return retChoice;
                    else
                        goto again;
                    break;
                };
                case 2:{ retChoice=editMenu();
                    if (retChoice!=-1)
                        return retChoice;
                    else
                        goto again;
                    break;
                };
                case 3:{ retChoice=deleteMenu();
                    if (retChoice!=-1)
                        return retChoice;
                    else
                        goto again;
                    break;
                };
                case 4:{ retChoice=viewMenu();
                    if (retChoice!=-1)
                        return retChoice;
                    else
                        goto again;
                    break;
                };
                case 5: return 10; break;
                default: goto again; break;
            }
        }

    protected:
        void system_clear(){// Cross-Platform clear
            #ifdef WINDOWS
                system("cls");
            #else
                system ("clear");
            #endif
        };

        void system_pause(){// Cross-Platform pause
            cin.get(); cin.get();
        };

        int insertMenu(){
            again:
            system_clear();

            for(int i=0 ; i<=5 ; i++)
                cout << insertmenuElements[i];
            cin >> choice;

            switch (choice){
                case 1: return 1; break;
                case 2: return 2; break;
                case 3: return -1; break;
                default: goto again; break;

            }
        };

        int editMenu(){
            again:
            system_clear();

            for(int i=0 ; i<=5 ; i++)
                cout << editmenuElements[i];
            cin >> choice;

            switch (choice){
                case 1: return 3; break;
                case 2: return 4 ;break;
                case 3: return -1 ;break;
                default: goto again; break;

            }
        };

        int deleteMenu(){
            again:
            system_clear();

            for(int i=0 ; i<=5 ; i++)
                cout << deletemenuElements[i];
            cin >> choice;

            switch (choice){
                case 1: return 5; break;
                case 2: return 6; break;
                case 3: return -1; break;
                default: goto again; break;

            }
        };

        int viewMenu(){
            again:
            system_clear();

            for(int i=0 ; i<=6 ; i++)
                cout << viewmenuElements[i];
            cin >> choice;

            switch (choice){
                case 1: return 7; break;
                case 2: return 8; break;
                case 3: return 9; break;
                case 4: return -1; break;
                default: goto again; break;

            }
        };

    private:
        string menuElements[7]={"CLASS RECORD PROJECT\nBy: Kyle Aquino\n\n","1. Insert Data\n",
                                    "2. Edit Data\n","3. Delete Data\n","4. View Data\n","5. Exit Program\n\n",
                                    "Choice: "};
        string insertmenuElements[7]={"CLASS RECORD PROJECT\nBy: Kyle Aquino\n\n","Insert Data: \n",
                                        "1. Add Subject Code\n","2. Add Student Data\n","3. Cancel\n\n",
                                        "Choice: "};
        string editmenuElements[7]={"CLASS RECORD PROJECT\nBy: Kyle Aquino\n\n","Edit Data: \n",
                                        "1. Edit Subject Code\n","2. Edit Student Data\n",
                                        "3. Cancel\n\n","Choice: "};
        string deletemenuElements[7]={"CLASS RECORD PROJECT\nBy: Kyle Aquino\n\n","Edit Data: \n","1. Delete Subject Code\n",
                                        "2. Delete Student Data\n","3. Cancel\n\n","Choice: "};
        string viewmenuElements[7]={"CLASS RECORD PROJECT\nBy: Kyle Aquino\n\n","View Data: \n","1. View Subject Code\n",
                                        "2. View Student Data\n","3. View All Data\n","4. Cancel\n\n","Choice: "};
        int choice,retChoice;
};

#endif // MENUCOMPONENTS_H
