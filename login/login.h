#include <vector>
#include <string.h>

struct data_user{
    char username[100];
    char password[100];
};

data_user value(char user[100], char password[100]){
    data_user add_user;
    strcpy(add_user.username, user);
    strcpy(add_user.password, password);
    return add_user;
}

std::vector<data_user> data_akun;
data_user active_user;

bool add_account(char user[100], char password[100]){
    if(data_akun.size() > 1){
        for(int i=0; i<data_akun.size(); i++){
            if(strcmp(user, data_akun[i].username)==1){
                data_akun.push_back(value(user, password));
                return true;
            }
            else if(data_akun.size()-1 == i){
                return false;
            }
        }
    }
    else{
        data_akun.push_back(value(user, password));
        return true;
    }
}

int count_user(){
    return data_akun.size();
}

std::string active_username(){
    strcpy(active_user.username, active_user.username);
    return active_user.username;
}

bool login(char user[100], char password[100]){
    for(int i=0; i<data_akun.size(); i++){
        if((strcmp(user, data_akun[i].username)==0) && (strcmp(password, data_akun[i].password)==0)){
            strcpy(active_user.username, data_akun[i].username);
            strcpy(active_user.password, data_akun[i].password);
            return true;
        }
        else if(i==data_akun.size()-1){
            return false;
        }
    }
}

bool delete_user(char user[100]){
    for(int i=0; i<data_akun.size(); i++){
        if((strcmp(user, data_akun[i].username)==0)){
            if(data_akun.size()-1 == i){
                data_akun.pop_back();
            }
            else{
                data_akun.erase(data_akun.begin()+i);
            }
            return true;
        }
        else if(i==data_akun.size()-1){
            return false;
        }
    }
}

bool logout(){
    char out[100]= {'\0'};
    strcpy(active_user.username, out);
    strcpy(active_user.password, out);
    return true;
}
