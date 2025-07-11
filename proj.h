#ifndef PROJ_H
#define PROJ_H

#include <string>
using namespace std;

// الثوابت
const int MAX_DOCTORS = 20;  // الحد الأقصى لعدد الأطباء
const int MAX_PATIENTS = 100; ;  // الحد الأقصى لعدد المرضى

class Person {
protected:
    string Name;         
    string NationalID;    
    int age;              
    string DateOfBirth;  
    string gender;        
    string PhoneNumber;   
    
    public:
    Person();
    Person(string name, string id, int age, string dob, string gender, string phone);

    void setName(string newName);
    void setNationalID(string newID);
    void setAge(int newAge);
    void setDateOfBirth(string newDOB);
    void setGender(string newGender);
    void setPhoneNumber(string newPhone);

    string getName();
    string getNationalID();
    int getAge();
    string getDateOfBirth();
    string getGender();
    string getPhoneNumber();
};

class address {
protected:
    string city;        
    string Area;        
    string StreetName;   
    string BuildingNo;   
    string ZipCode;      

public:
    address();
    address(string city, string area, string street, string building, string zip);

    void setCity(string newCity);
    void setArea(string newArea);
    void setStreetName(string newStreet);
    void setBuildingNo(string newBuilding);
    void setZipCode(string newZip);

    string getCity();
    string getArea();
    string getStreetName();
    string getBuildingNo();
    string getZipCode();
};

// فئة المريض
class patient : public Person , public address {
private:
    int medicalID; // الرقم الطبي للمريض
    float Height;
    float Weight;
    
public:
    patient();
    patient(string name, string id, int age, string dob, string gender, string phone,string city, string area, string street, string building, string zip, int medicalID, float height, float weight);

    void setMedicalID(int newMedicalID);
    void setHeight(float newHeight);
    void setWeight(float newWeight);

    int getMedicalID();
    float getHeight();
    float getWeight();
    
    void DisplayInfo();  //عرض معلومات المريض 
};

// فئة الدكتور
class Doctor : public Person , public address  {
private:
    string specialization;
    int DoctorID;
    int assignedPatients[MAX_PATIENTS];  // قائمة المرضى المسندين لهذا الطبيب

public:
    Doctor();
    Doctor(string name, string id, int age, string dob, string gender, string phone, string city, string area, string street, string building, string zip, string specialization, int doctorid);

    void setSpecialization(string sp);
    void setEmployeeID(int id);

    string getSpecialization();
    int getEmployeeID();

    void assignPatient(patient &p); // إسناد مريض للطبيب
    void listAssignedPatients();     // عرض قائمة المرضى المسندين
    void DisplayInfo();           // عرض تفاصيل الطبيب
};

// فئة العيادة
class clinic: protected patient,protected Doctor {
private:
    string clinic_name;
    string work_time;
    int room_number;

public:
    clinic();
    clinic(string clinic_n, string wor, int room);

    void addDoctor();           // إضافة طبيب للعيادة
    void DisplayInfoclinic();    // عرض تفاصيل العيادة
};

// دوال الوظائف
void addPatient();   // إضافة مريض
void assignPatientToDoctor();  // إسناد مريض إلى طبيب
void menu();   // عرض القائمة الرئيسية

#endif
