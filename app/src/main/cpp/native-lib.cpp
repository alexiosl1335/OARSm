#include <jni.h>
#include <string>

using namespace std;
class User{
private:
    string email;
    string name;
    string gender;
    string lastname;
    string birthdate;
    string provider_id;
    string username;
public:
    User(string my_name,string mylastname,string my_provider_id,string my_birthdate,string my_username,string my_gender,string my_email);
    User(string my_name,string my_provider_id,string my_username,string my_lastname);
    User();
    ~User();
    string getUsername();
    string getLastName();
    string getName();
    string getProvider();
    string getBirthdate();
    string getEmail();
    string getGender();
    void setUsername(string a);
    void setLastName(string a);
    void setName(string a);
    void setProvider(string a);
    void setBirthdate(string a);
    void setEmail(string a);
    void setGender(string a);
};

User::User (string my_name,string mylastname,string my_provider_id,string my_birthdate,string my_username,string my_gender ,string my_email){

    this->name = my_name;
    this->birthdate = my_birthdate;
    this->provider_id = my_provider_id;
    this->email = my_email;
    this->username = my_username;
    this->lastname = mylastname;
    this->gender = my_gender;

}
//destructor run at logout
User::~User() {
    delete this;
}
User::User(){
    this->name = "";
    this->birthdate = "";
    this->provider_id = "";
    this->email = "";
    this->username = "";
    this->lastname = "";
    this->gender = "";
}
//small constructor
User::User(string my_name,string my_provider_id,string my_username, string my_lastname){

    this->name = my_name;
    this->provider_id = my_provider_id;
    this->username = my_username;
    this->lastname = my_lastname;
    this->gender = "";
    this->email = "";
    this->birthdate = "";



}

string User::getName(){
    return this->name.c_str();
}
string User::getLastName(){
    return this->lastname.c_str();
}
string User::getUsername(){
    return this->username.c_str();
}
string User::getGender(){
    return this->gender.c_str();
}
string User::getEmail(){
    return this->email.c_str();
}
string User::getBirthdate(){
    return this->birthdate.c_str();
}
string User::getProvider(){
    return this->provider_id.c_str();
}

void User::setName(string a){
    this->name= a;
}
void User::setLastName(string a){
    this->lastname = a;
}
void User::setUsername(string a){
    this->username =a;
}
void User::setGender(string a){
    this->gender = a;
}
void User::setEmail(string a){
    this->email = a;
}
void User::setBirthdate(string a){
    this->birthdate = a;
}
void User::setProvider(string a){
    this->provider_id= a;
}


static User current= User();
extern "C" JNIEXPORT void JNICALL Java_com_q2i_q2iprov_DatahubCASA_CreateUser(JNIEnv *env, jobject /* this */ ,string my_name,string my_provider_id,string my_username, string my_lastname) {
    User n = User(my_name,my_provider_id,my_username,my_lastname);
    current =  n;
}

extern "C" JNIEXPORT void JNICALL Java_com_q2i_q2iprov_DatahubCASA_UpdateUser(JNIEnv *env, jobject) {


}
extern "C" JNIEXPORT jstring JNICALL Java_com_q2i_q2iprov_DatahubCASA_getName(JNIEnv *env, jobject){

    string a = current.getName();
    return env->NewStringUTF(a.c_str());
}
extern "C" JNIEXPORT jstring JNICALL Java_com_q2i_q2iprov_DatahubCASA_getLastName(JNIEnv *env, jobject){
    string b =  current.getLastName();
    return env->NewStringUTF(b.c_str());


}
extern "C" JNIEXPORT jstring JNICALL Java_com_q2i_q2iprov_DatahubCASA_Email(JNIEnv *env, jobject ){

    string a =  current.getEmail();
    return env->NewStringUTF(a.c_str());

}
extern "C" JNIEXPORT jstring JNICALL Java_com_q2i_q2iprov_DatahubCASA_Username(JNIEnv *env, jobject ){
    string a =  current.getUsername();

    return env->NewStringUTF(a.c_str());

}
extern "C" JNIEXPORT jstring JNICALL Java_com_q2i_q2iprov_DatahubCASA_getGender( JNIEnv *env, jobject /* this */){

    string a = current.getGender();
    return env->NewStringUTF(a.c_str());

}
extern "C" JNIEXPORT jstring JNICALL Java_com_q2i_q2iprov_DatahubCASA_getBirthdate(JNIEnv *env, jobject ){

    string a =  current.getBirthdate();
    return env->NewStringUTF(a.c_str());

}
extern "C" JNIEXPORT jstring JNICALL Java_com_q2i_q2iprov_DatahubCASA_getProvider_id(JNIEnv *env, jobject ){

    string a =  current.getProvider();
    return env->NewStringUTF(a.c_str());

}


