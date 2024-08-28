#include<iostream>
using namespace std;
#include<fstream>
#include<conio.h>
#include<cstring>
int sn=0;
struct emp{
    int salary;
    char id[15];
    int exp;
    char name[30];
    char dob[10];
    int fid;
    char grade[3];
};
void NewEmployee(){
    ofstream ofs("employee.bin",ios_base::app | ios_base::binary);
    emp e;
    cout<<"Give Relevant Information of Employee :: "<<endl;
    cout<<"***********"<<endl;
    cout<<"Give I'D Card No of Employee // Format is (XXXXX-XXXXXXX-X)"<<endl;
    cin>>e.id;
    cout<<"Give Name Of Employee "<<endl;
    cin>>e.name;
    cout<<"Give Date Of Birth of Employee // Format is (DD-MM-YYYY)"<<endl;
    cin>>e.dob;
    cout<<"Give Past Working Experience Of Employee if Any : "<<endl;
    cout<<"1.Yes"<<endl;
    cout<<"2.No"<<endl;
    int y;
    cin>>y;
    while(true){
    if(y==1){
        cout<<"Give Experience(in Years)"<<endl;
        cin>>e.exp;
        break;
    }
    else if(y==2){
        cout<<"Okie"<<endl;
        e.exp=0;
        break;
    }
    else{
        cout<<"Invalid Input"<<endl;
        break;
    }
    }
    cout<<"Choose Salary Of Employee"<<endl;
    cin>>e.salary;
    sn++;
    cout<<"Chose Grade Of Employee"<<endl;
    cin>>e.grade;
    cout<<"Give Company I'D Number Of Employee"<<endl;
    cin>>e.fid;
    ofs.write(reinterpret_cast<char*>(&e),(sizeof(e)));
    ofs.close();
    cout<<"Data Stored"<<endl;
}
void DisplayData(){
    emp e;
    ifstream ifs("employee.bin",ios_base::binary);
    while(ifs.read(reinterpret_cast<char*>(&e),(sizeof(e)))){
        cout<<"Employee Name : "<<e.name<<endl;
        cout<<"Employee CNIC Number : "<<e.id<<endl;
        cout<<"Date Of birth Of Employee : "<<e.dob<<endl;
        cout<<"Salary : "<<e.salary<<endl;
        cout<<"Salary Taken Times : "<<sn<<endl;
        cout<<"Grade Of Employee : "<<e.grade<<endl;
        cout<<"Past Experience Of Employee : "<<e.exp<<endl;
        cout<<"Company I'D Number Of Employee : "<<e.fid<<endl;
        cout<<"*******************************************************"<<endl;
    }
    ifs.close();
}
void DeleteAll(){
    cout<<"ATTENTION ! Do You Want To Proceed For Removal Of All Data Records"<<endl;
    cout<<"1.Yes"<<endl;
    cout<<"2.No"<<endl;
    char del;
    cin>>del;
    if(del=='1'){
        string password="166615744635";
        cout<<"Give Password"<<endl;
        string inpas;
        cin>>inpas;
        if(inpas==password){

        ofstream ofs("employee.bin",ios_base::binary | ios_base::trunc);
        cout<<"Data Deleted Successfully"<<endl;
        ofs.close();
        return ;
        }
        else{
            cout<<"Wrong Password"<<endl;
            return ;
        }
    }
}
void ModifyData(){
    emp e;
    int r;
    cout<<"Give Company I'D Number Of Employee For Modifying Data"<<endl;
    cin>>r;
    ifstream ifs("employee.bin",ios_base::binary);
    ofstream ofs("temp3.bin",ios_base::binary);
    while(ifs.read(reinterpret_cast<char*>(&e),sizeof(e))){
        if(r==e.fid){
            cout<<"Give New Data Of Employee"<<endl;
            cout<<"******"<<endl;
            cout<<"Give Relevant Information of Employee :: "<<endl;
    cout<<"***********"<<endl;
    cout<<"Give I'D Card No of Employee // Format is (XXXXX-XXXXXXX-X)"<<endl;
    cin>>e.id;
    cout<<"Give Name Of Employee "<<endl;
    cin>>e.name;
    cout<<"Give Date Of Birth of Employee // Format is (XX-XX-XXXX)"<<endl;
    cin>>e.dob;
    cout<<"Give Past Working Experience Of Employee if Any : "<<endl;
    cout<<"1.Yes"<<endl;
    cout<<"2.No"<<endl;
    int y;
    cin>>y;
    while(true){
    if(y==1){
        cout<<"Give Experience(in Years)"<<endl;
        cin>>e.exp;
        break;
    }
    else if(y==2){
        cout<<"Okie"<<endl;
        e.exp=0;
        break;
    }
    else{
        cout<<"Invalid Input"<<endl;
    }
    }
    cout<<"Choose Salary Of Employee"<<endl;
    cin>>e.salary;
    sn++;
    cout<<"Chose Grade Of Employee"<<endl;
    cin>>e.grade;
    cout<<"Give Company I'D Number Of Employee"<<endl;
    cin>>e.fid;

        }
        ofs.write(reinterpret_cast<char*>(&e),sizeof(e));
    }
    ofs.close();
    ifs.close();
    ofstream ofs2("employee.bin",ios_base::binary);
    ifstream ifs2("temp3.bin",ios_base::binary);
    while(ifs2.read(reinterpret_cast<char*>(&e),sizeof(e))){
        ofs2.write(reinterpret_cast<char*>(&e),sizeof(e));
    }
    cout<<"Data Modified"<<endl;
    ofs2.close();
    ifs2.close();

}
void DeleteData(){
    emp e;
    int r;
    cout<<"Give Company I'D Number Of Employee Whom Data You Want To Be Deleted"<<endl;
    cin>>r;
    ofstream ofs("temp3.bin",ios_base::binary);
    ifstream ifs("employee.bin",ios_base::binary);
    while(ifs.read(reinterpret_cast<char*>(&e),sizeof(e))){
        if(r!=e.fid){
            ofs.write(reinterpret_cast<char*>(&e),sizeof(e));
        }
    }
    ofs.close();
    ifs.close();
    ifstream ifs2("temp3.bin",ios_base::binary);
    ofstream ofs2("employee.bin",ios_base::binary);
    while(ifs2.read(reinterpret_cast<char*>(&e),sizeof(e))){
        ofs2.write(reinterpret_cast<char*>(&e),sizeof(e));
    }
    ofs2.close();
    ifs2.close();
    cout<<"Data Deleted"<<endl;
}
void HighestSalary(){
    emp e;
    int count=0;
    ifstream ifs("employee.bin",ios_base::binary);
    while(ifs.read(reinterpret_cast<char*>(&e),sizeof(e))){
        count++;
    }
    ifs.close();
    emp *a=new emp[count];
    ifstream ifs2("employee.bin",ios_base::binary);
    int i=0;
    while(ifs2.read(reinterpret_cast<char*>(&e),sizeof(e))){
        a[i]=e;
        i++;
    }
    ifs2.close();
    int large=a[0].salary;
    int loc=0;
    for(i=0;i<count;i++){
        if(a[i].salary>large){
            large=a[i].salary;
            loc=i;
        }
    }
    cout<<"Data Of Employee Having Highest Salary is :: "<<endl;
        cout<<"Employee Name : "<<a[loc].name<<endl;
        cout<<"Employee CNIC Number : "<<a[loc].id<<endl;
        cout<<"Date Of birth Of Employee : "<<a[loc].dob<<endl;
        cout<<"Salary : "<<a[loc].salary<<endl;
        cout<<"Grade Of Employee : "<<a[loc].grade<<endl;
        cout<<"Past Experience Of Employee : "<<a[loc].exp<<endl;
        cout<<"Company I'D Number Of Employee : "<<a[loc].fid<<endl;
        cout<<"********************"<<endl;
        delete[] a;
}
void HighestExperience(){
    emp e;
    int count=0;
    ifstream ifs("employee.bin",ios_base::binary);
    while(ifs.read(reinterpret_cast<char*>(&e),sizeof(e))){
        count++;
    }
    ifs.close();
    emp *a=new emp[count];
    ifstream ifs2("employee.bin",ios_base::binary);
    int i=0;
    while(ifs2.read(reinterpret_cast<char*>(&e),sizeof(e))){
        a[i]=e;
        i++;
    }
    ifs2.close();
    int large=a[0].exp;
    int loc=0;
    for(i=0;i<count;i++){
        if(a[i].exp>large){
            large = a[i].exp;
            loc=i;
        }
    }
    cout<<"Data Of Employee Having Highest Experience is :: "<<endl;
        cout<<"Employee Name : "<<a[loc].name<<endl;
        cout<<"Employee CNIC Number : "<<a[loc].id<<endl;
        cout<<"Date Of birth Of Employee : "<<a[loc].dob<<endl;
        cout<<"Salary : "<<a[loc].salary<<endl;
        cout<<"Grade Of Employee : "<<a[loc].grade<<endl;
        cout<<"Past Experience Of Employee : "<<a[loc].exp<<endl;
        cout<<"Company I'D Number Of Employee : "<<a[loc].fid<<endl;
        cout<<"********************"<<endl;
        delete [] a;
}
void Aplus(){
    emp e;
    int count=0;
    ifstream ifs("employee.bin",ios_base::binary);
    while(ifs.read(reinterpret_cast<char*>(&e),sizeof(e))){
        count++;
    }
    ifs.close();
    emp *a=new emp[count];
    ifstream ifs2("employee.bin",ios_base::binary);
    int i=0;
    while(ifs2.read(reinterpret_cast<char*>(&e),sizeof(e))){
        a[i]=e;
        i++;
    }
    ifs2.close();
    for(i=0;i<count;i++){
        if(strcmp(a[i].grade,"A+")==0 || strcmp(a[i].grade,"a+")==0){
                cout<<"Data Of Employee Having A+ Grade is/are :: "<<endl;
        cout<<"Employee Name : "<<a[i].name<<endl;
        cout<<"Employee CNIC Number : "<<a[i].id<<endl;
        cout<<"Date Of birth Of Employee : "<<a[i].dob<<endl;
        cout<<"Salary : "<<a[i].salary<<endl;
        cout<<"Grade Of Employee : "<<a[i].grade<<endl;
        cout<<"Past Experience Of Employee : "<<a[i].exp<<endl;
        cout<<"Company I'D Number Of Employee : "<<a[i].fid<<endl;
        cout<<"***************************"<<endl;
        }
    }
    delete[] a;
}
void Agrade(){
    emp e;
    int count=0;
    ifstream ifs("employee.bin",ios_base::binary);
    while(ifs.read(reinterpret_cast<char*>(&e),sizeof(e))){
        count++;
    }
    ifs.close();
    emp *a=new emp[count];
    ifstream ifs2("employee.bin",ios_base::binary);
    int i=0;
    while(ifs2.read(reinterpret_cast<char*>(&e),sizeof(e))){
        a[i]=e;
        i++;
    }
    ifs2.close();
    for(i=0;i<count;i++){
        if(strcmp(a[i].grade,"A")==0 || strcmp(a[i].grade,"a")==0){
        cout<<"Data Of Employee Having A Grade is/are :: "<<endl;
        cout<<"Employee Name : "<<a[i].name<<endl;
        cout<<"Employee CNIC Number : "<<a[i].id<<endl;
        cout<<"Date Of birth Of Employee : "<<a[i].dob<<endl;
        cout<<"Salary : "<<a[i].salary<<endl;
        cout<<"Grade Of Employee : "<<a[i].grade<<endl;
        cout<<"Past Experience Of Employee : "<<a[i].exp<<endl;
        cout<<"Company I'D Number Of Employee : "<<a[i].fid<<endl;
        cout<<"***************************"<<endl;
        }
    }
    delete[] a;
}
void mainn(){
        char oper;
    while(1){
        cout<<"1.Add New Employee Information to System "<<endl;
        cout<<"2.Show Data Of All Employees"<<endl;
        cout<<"3.Modify  Data Of Employee"<<endl;
        cout<<"4.Delete Data Of Employee"<<endl;
        cout<<"5.Show Data Of Employee With Highest Salary"<<endl;
        cout<<"6.Show Data Of Employee With Most Experience"<<endl;
        cout<<"7.Show Data Of A+ Grade Employees"<<endl;
        cout<<"8.Show Data Of A Grade Employees"<<endl;
        cout<<"9.Delete All Data"<<endl;
        cout<<"e.Exit"<<endl;
        oper=getche();
        cout<<endl;
        if(oper=='1'){
            NewEmployee();
        }
        else if(oper=='2'){
            DisplayData();
        }
        else if(oper=='3'){
            ModifyData();
        }
        else if(oper=='4'){
            DeleteData();
        }
        else if(oper=='5'){
            HighestSalary();
        }
        else if(oper=='6'){
            HighestExperience();
        }
        else if(oper=='7'){
            Aplus();
        }
        else if(oper=='8'){
            Agrade();
        }
        else if(oper=='9'){
            DeleteAll();
        }
        else if(oper=='e'){
            break;
        }
        else{
            cout<<"Invalid Input"<<endl;
        }
        getch();
        system("cls");
    }
}
void pasword(){
    string password2;
    string inpass2="166615744635123";
    char b;
    cout<<"Proceed Further"<<endl;
    cout<<"1.Yes"<<endl;
    cout<<"2.No"<<endl;
    cin>>b;
    if(b=='1'){
        cout<<"1.Enter Password "<<endl;
        cout<<"2.Change Password"<<endl;
        char c;
        cin>>c;
        if(c=='1'){
            cout<<"Give Password"<<endl;

        char ch;
        while ((ch = _getch()) != 13) {
            password2.push_back(ch);
            cout << '*';
        }
            system("cls");
            if(password2==inpass2){
                mainn();
            }
            else{
                cout<<"Wrong Password"<<endl;
                cout<<"**********"<<endl;
                cout<<"1.Enter Password Again"<<endl;
                cout<<"2.Exit"<<endl;
                char h;
                cin>>h;
                if(h=='1'){
                    pasword();
                }
                else if(h=='2'){
                    exit;
                }
                else{
                    cout<<"Invalid Choice...\"Exiting\""<<endl;
                    exit;
                }

            }
        }

         else if (c=='2'){
                cout<<"Enter old Password Password"<<endl;
                string oldpas;
                cin>>oldpas;
                if(oldpas==inpass2){
                    cout<<"Give New Password"<<endl;
                    cin>>inpass2,ios_base::app;
                }
                else{
                    cout<<"Wrong Password"<<endl;
                    return ;
                }
            }
    }
    else if(b=='2'){
        return ;
    }
}
int main(){
    cout<<"Welcome To Employee Management System "<<endl;
    cout<<"Developed By :: \"M Hamza\""<<endl;
    pasword();
    return 0;
}