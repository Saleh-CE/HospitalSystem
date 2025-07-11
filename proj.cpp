#include "proj.h"
#include <iostream>
#include <string>
using namespace std;

// مصفوفات عامة لتخزين الأطباء والمرضى
Doctor doctors[MAX_DOCTORS];
patient patients[MAX_PATIENTS];
clinic cd[MAX_DOCTORS];

int doctorCount = 0;  // عدد الأطباء المضافين
int patientCount = 0;  // عدد المرضى المضافين


Person::Person() {
    Name = "";
    NationalID = "";
    age = 0;
    DateOfBirth = "";
    gender = "";
    PhoneNumber="";
}
Person::Person(string name, string id, int age, string dob, string gender, string phone)
    : Name(name), NationalID(id), age(age), DateOfBirth(dob), gender(gender), PhoneNumber(phone) {}
    
    void Person::setName(string newName) { Name = newName;}
    void Person::setNationalID(string newID) { NationalID = newID;}
    void Person::setAge(int newAge) { age = newAge;}
    void Person::setDateOfBirth(string newDOB) { DateOfBirth = newDOB;}
    void Person::setGender(string newGender) { gender = newGender;}
    void Person::setPhoneNumber(string newPhone) { PhoneNumber = newPhone;}
    
    string Person::getName() { return Name; }
    string Person::getNationalID() { return NationalID; }
    int Person::getAge() { return age; }
    string Person::getDateOfBirth() { return DateOfBirth; }
    string Person::getGender() { return gender; }
    string Person::getPhoneNumber() { return PhoneNumber; }
    
    
    address::address()
    {
        city = "";
        Area = "";
        StreetName = "";
        BuildingNo = "";
        ZipCode = "";
    }
address::address(string c, string a, string s, string b, string z)
    : city(c), Area(a), StreetName(s), BuildingNo(b), ZipCode(z){}
    
    void address::setCity(string newCity) {city = newCity;}
    void address::setArea(string newArea) {Area = newArea;}
    void address::setStreetName(string newStreet) {StreetName = newStreet;}
    void address::setBuildingNo(string newBuilding) {BuildingNo = newBuilding;}
    void address::setZipCode(string newZip) {ZipCode = newZip;}

    string address::getCity() { return city; }
    string address::getArea() { return Area; }
    string address::getStreetName() { return StreetName; }
    string address::getBuildingNo() { return BuildingNo; }
    string address::getZipCode() { return ZipCode; }
    
// تنفيذ فئة المريض
patient::patient() : Person() , address() {
    medicalID = 0;
    Height = 0.0;
    Weight = 0.0;
}

patient::patient(string name, string id, int age, string dob, string gender, string phone, string city, string area, string street, string building, string zip, int medID, float h, float w)
    : Person(name, id , age , dob , gender , phone) , address(city , area , street , building , zip) , medicalID(medID) , Height(h) , Weight(w){}

void patient::setMedicalID(int newMedicalID) { medicalID = newMedicalID; }
void patient::setHeight(float newHeight) { Height = newHeight; }
void patient::setWeight(float newWeight) { Weight = newWeight; }

int patient::getMedicalID() { return medicalID; }
float patient::getHeight() { return Height; }
float patient::getWeight() { return Weight; }

void patient::DisplayInfo() {
    cout << "===================" << endl;
    cout << "Patient Info:" << endl;
    cout << "Name: " << Name << ", Age: " << age << ", Gender: " <<gender <<endl;
    cout << "National ID: " << NationalID << ", Phone: " << PhoneNumber << endl;
    cout << "Address: " << city << ", " << Area << ", " << StreetName << ", " << BuildingNo << ", ZIP: " << ZipCode << endl;
    cout << "Medical ID: " << medicalID << ", Height: " << Height << ", Weight: " << Weight << endl;
         
}


// وظيفة للتحقق من صحة الاسم المدخل (يسمح فقط بالأحرف والمسافات
bool isValidName(const string& Name) {
    for (char c : Name) {
 // التحقق مما إذا كانت الأحرف ليست أحرفًا أو مسافا   
 if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')) {
            return false; 
        }
    }
    return true;
}

// وظيفة لإضافة مريض
void addPatient() {
    string Name , NationalID , DateOfBirth , gender , PhoneNumber , city , Area , StreetName , BuildingNo , ZipCode ;
    int age, medicalID;
    float Height , Weight;

  // إدخال الاسم مع التحقق من صلاحيته
    while (true) {
        cout << "Enter Patient Name: ";
        cin.ignore(); // لتفريغ المدخلات السابقة
        getline(cin, Name);

     // تحقق من صحة الاسم
        if (!isValidName(Name)) {
            cout << "Invalid name! Please enter a name with only letters and spaces." << endl;
        } else {
            break; // الخروج عند إدخال اسم صالح
        }
    }
 
        cout << "Enter National ID (numbers only): ";
        getline(cin, NationalID);
    

    // التحقق من صحة العمر
    while (true) {
        cout << "Enter Age (must be a number between 1 and 99): ";
        cin >> age;

        if (cin.fail() || age <= 0 || age >= 100) {
            cout << "Invalid age! Please enter a valid number between 1 and 99." << endl;
            cin.clear(); 
            cin.ignore(); 
        } else {
            break; // الخروج عند إدخال صالح
        }
    }
    
    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    cin.ignore(); 
    getline(cin, DateOfBirth);

    cout << "Enter Gender (M/F): ";
    getline(cin, gender);

    cout << "Enter Phone Number: ";
    getline(cin, PhoneNumber);
    
    cout << "Enter City: ";
    getline(cin, city);

    cout << "Enter Area: ";
    getline(cin, Area);

    cout << "Enter Street Name: ";
    getline(cin, StreetName);

    cout << "Enter Building Number: ";
    getline(cin, BuildingNo);

    cout << "Enter ZIP Code: ";
    getline(cin, ZipCode);
    
        // التحقق من صحة الرقم الطبي
    while (true) {
        cout << "Enter Medical ID (numbers only): ";
        cin >> medicalID;

        if (cin.fail() || medicalID <= 0) {
            cout << "Invalid Medical ID! Please enter a positive number." << endl;
            cin.clear(); 
            cin.ignore(); 
        } else {
            break; // الخروج عند إدخال صالح
        }
    }
    
    while (true) {
        cout << "Enter Height (in centimeters): ";
        cin >> Height;

        if (cin.fail() || Height <= 0) {
            cout << "Invalid height! Please enter a positive value." << endl;
            cin.clear();
            cin.ignore();
        } else {
            break;
        }
    }
    
        while (true) {
        cout << "Enter Weight (in kilograms): ";
        cin >> Weight;

        if (cin.fail() || Weight <= 0) {
            cout << "Invalid weight! Please enter a positive value." << endl;
            cin.clear();
            cin.ignore();
        } else {
            break;
        }
    }
    patients[patientCount++] = patient(Name, NationalID, age, DateOfBirth, gender, PhoneNumber,
                       city, Area, StreetName, BuildingNo, ZipCode,
                       medicalID, Height, Weight);
    cout << "Patient added successfully!" << endl;
    cout << "========================" << endl;

}




// تنفيذ فئة الطبيب
Doctor::Doctor(): Person() , address()  {
    specialization = "";
    DoctorID = 0;
    for (int i = 0; i < MAX_PATIENTS; i++) {
        assignedPatients[i] = 0;
    }
}

Doctor::Doctor(string name, string id, int age, string dob, string gender, string phone, string city, string area, string street, string building, string zip, string sp, int d_id)
    : Person(name, id , age , dob , gender , phone) , address(city , area , street , building , zip) , specialization(sp), DoctorID(d_id) {
    for (int i = 0; i < MAX_PATIENTS; i++) {
        assignedPatients[i] = 0;
    }
}

void Doctor::setSpecialization(string sp) { specialization = sp; }
void Doctor::setEmployeeID(int id) { DoctorID = id; }

string Doctor::getSpecialization() { return specialization; }
int Doctor::getEmployeeID() { return DoctorID; }





// وظيفة للتحقق من صحة الاسم المدخل (يسمح فقط بالأحرف والمسافات
bool isValidNameD(const string& Name) {
    for (char c :  Name) {
 // التحقق مما إذا كانت الأحرف ليست أحرفًا أو مسافا   
 if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')) {
            return false; 
        }
    }
    return true;
}



// وظيفة لإسناد مريض لطبيب
void Doctor::assignPatient(patient &p) {
    for (int i = 0; i < MAX_PATIENTS; i++) {
        if (assignedPatients[i] == 0) {
            assignedPatients[i] = p.getMedicalID();
            cout << "Patient " << p.getName() << " (ID: " << p.getMedicalID() 
                 << ") assigned to Doctor " << Name << "." << endl;
            return;
        }
    }
    cout << "No available slots for patients." << endl;
}

// وظيفة لعرض قائمة المرضى المسندين إلى الطبيب
void Doctor::listAssignedPatients() {
    bool hasPatients = false;
    cout << "Patients assigned to Doctor " << Name << ":" << endl;
    for (int i = 0; i < MAX_PATIENTS; i++) {
        if (assignedPatients[i] != 0) {
            cout << "Patient ID: " << assignedPatients[i] << endl;
            hasPatients = true;
        }
    }
    if (!hasPatients) {
        cout << "No patients assigned." << endl;
    }
}

// وظيفة لعرض معلومات الطبيب
void Doctor::DisplayInfo() {
    cout << "===================" << endl;
    cout << "Doctor Info:" << endl;
    cout << "Name: " << Name << ", National ID: " << NationalID << ", Age: " << age << ", Date of birth: " << DateOfBirth << ", Gender: " << gender << endl;
    cout << ", Phone: " << PhoneNumber << endl;
    cout << "Address: " << city << ", " << Area << ", " << StreetName << ", " << BuildingNo << ", ZIP: " << ZipCode << endl;
    cout << "Specialization: " << specialization << ", Doctor ID: " << DoctorID << endl;
}

// وظيفة لعرض معلومات الطبيب
clinic::clinic() {
    clinic_name = "";
    work_time = "";
    room_number = 0;
}

clinic::clinic(string clinic_n, string wor, int room)
    : clinic_name(clinic_n), work_time(wor), room_number(room) {}


// وظيفة لإضافة طبيب إلى العيادة

void clinic::addDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        cout << "Maximum doctor limit reached!" << endl;
        return;
    }

    string Name, specialization, gender, phone, city, area, street, building, zip,DateOfBirth, NationalID;
    int DoctorID,age;
  int clinicChoice;
  
  
    while (true) {
       cout << "Enter Doctor Name: ";
        cin.ignore(); // لتفريغ المدخلات السابقة
        getline(cin, Name);

     // تحقق من صحة الاسم
        if (!isValidNameD(Name)) {
            cout << "Invalid name! Please enter a name with only letters and spaces." << endl;
        } else {
            break; // الخروج عند إدخال اسم صالح
        }
    }
    
    
    
      cout << "Enter National ID: ";
    getline(cin, NationalID);
    


    cout << "Enter Doctor ID: ";
    cin >> DoctorID;
    
    
// عند إدخال تاريخ الميلاد والجنس
cout << "Enter Age (must be a number between 1 and 99): ";
while (true) {
    cin >> age;

    if (cin.fail() || age <= 0 || age >= 100) {
        cout << "Invalid age! Please enter a valid number between 1 and 99." << endl;
        cin.clear();            // إعادة تدفق الإدخال لوضعه الطبيعي
        cin.ignore(100, '\n');  // تنظيف المخزن المؤقت
    } else {
        cin.ignore(100, '\n');  // تنظيف المخزن المؤقت بعد الإدخال الصحيح
        break;
    }
}

cout << "Enter Date of Birth (DD/MM/YYYY): ";
getline(cin, DateOfBirth); 

cout << "Enter Gender (M/F): ";
getline(cin, gender); 


    cout << "Enter Phone Number: ";
    getline(cin, phone);

    cout << "Enter City: ";
    getline(cin, city);

    cout << "Enter Area: ";
    getline(cin, area);

    cout << "Enter Street Name: ";
    getline(cin, street);

    cout << "Enter Building Number: ";
    getline(cin, building);

    cout << "Enter ZIP Code: ";
    getline(cin, zip);

    cout << "Enter Specialization: ";
    getline(cin, specialization);
    
  
    clinic clinics[] = {
        clinic("Bone", "8:00-12:00", 1),
        clinic("Heart", "9:00-12:00", 13),
        clinic("ENT", "8:00-11:30", 5),
        clinic("Children", "8:30-1:00", 7),
        clinic("Internal", "9:00-1:00", 3),
        clinic("Eye", "9:00-2:00", 15)
    };

       cout << "========================" << endl;
    cout << "Select Clinic to assign the doctor to:\n" << endl;
    for (int i = 0; i < 6; i++) {
        cout << i + 1 << ". " << clinics[i].clinic_name << " Clinic" << endl;
    }
     
     do{
      // cout << "========================\n" << endl;
  
    cout << "\n\nEnter clinic number (1-6): \n";
     cin >> clinicChoice;
     
       if (clinicChoice < 7 && clinicChoice > 0)
        {
   
       cout << "========================\n" << endl;
       
     
    if (clinicChoice < 7 && clinicChoice > 0) {
        doctors[doctorCount] = Doctor(Name, NationalID, age, DateOfBirth, gender, phone,
                                          city, area, street, building, zip, specialization, DoctorID);
        cd[doctorCount] = clinics[clinicChoice - 1];
        doctorCount++;

        cout << "Doctor added successfully!" << endl;
        cout << "Doctor " << Name << " assigned to the " 
             << clinics[clinicChoice - 1].clinic_name << " Clinic ^_^ !!\n\n" << endl;
             break;
    }
    else {}
    

    }else
     cout<<"\n\n========================(  Please Enter number from 1 to 6  (x_x) !! )=============================\n\n";  
    
       
        } while (clinicChoice != 0);
     
}

// وظيفة لعرض معلومات العيادة
void clinic::DisplayInfoclinic() {
    cout << "===================" << endl;
    cout << "Clinic Info:" << endl;
    cout << "Clinic Name: " << clinic_name 
         << ", Working Time: " << work_time 
         << ", Room Number: " << room_number << endl;
}

// وظيفة لإسناد مريض إلى طبيب
void assignPatientToDoctor() {
    if (doctorCount == 0 || patientCount == 0) {
        cout << "Please add doctors and patients first!" << endl;
        return;
    }

    cout << "Available Doctors:" << endl;
    for (int i = 0; i < doctorCount; i++) {
        cout << i + 1 << ". " << doctors[i].getName() << endl;
    }
    cout << "Select Doctor (by number): ";
    int doctorIndex;
    cin >> doctorIndex;

    if (doctorIndex < 1 || doctorIndex > doctorCount) {
        cout << "Invalid selection." << endl;
        return;
    }

    cout << "Available Patients:" << endl;
    for (int i = 0; i < patientCount; i++) {
        cout << i + 1 << ". " << patients[i].getName() << endl;
    }
    cout << "Select Patient (by number): ";
    int patientIndex;
    cin >> patientIndex;

    if (patientIndex < 1 || patientIndex > patientCount) {
        cout << "Invalid selection." << endl;
        return;
    }

    doctors[doctorIndex - 1].assignPatient(patients[patientIndex - 1]);
}

// وظيفة عرض القائمة
void menu() {
    int choice;
    clinic c;
    
          cout << "\n================ Welcome to University Hospital ^_^ ============" << endl;
        
        cout << "\nPlease choose what you want using the number in front of it : \n" << endl;
        
         cout << "========================\n" << endl;
    do {
  
        
       
        cout << "\n\n1. Add Doctor" << endl;
        cout << "2. Add Patient" << endl;
        cout << "3. Assign Patient to Doctor" << endl;
        cout << "4. Display Doctor Info" << endl;
        cout << "5. Display Patient Info" << endl;
        cout << "6. Exit\n" << endl;
           cout << "========================\n" << endl;
        cout << "Enter your choice: \n";
        
        cin >> choice;
        
        if (choice < 7 && choice > 0)
        {

        switch (choice) {
        case 1:
            c.addDoctor();
            break;
        case 2:
            addPatient();
            break;
        case 3:
            assignPatientToDoctor();
            break;
        case 4:
        if(doctorCount != 0){
            for (int i = 0; i < doctorCount; i++) {
                doctors[i].DisplayInfo();
                doctors[i].listAssignedPatients();
                cd[i].DisplayInfoclinic();
            }
        }
        else
        cout<<"There are No Dctors (x_x) !!!";
        
            break;
        case 5:
              if(patientCount != 0){
            for (int i = 0; i < patientCount; i++) {
                patients[i].DisplayInfo();
            }
        }
        else
        cout<<"There are No Patients (x_x) !!!";
            break;
            
        case 6:
            cout << "Exiting program. Thanks AND Goodbye! (OvO) " << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
  
        }
        else{
            
        cout<<"\n\n========================(  Please Enter number from 1 to 6  (x_x) !! )=============================\n\n";
        }
      
   
        } while (choice != 6);
    
}

