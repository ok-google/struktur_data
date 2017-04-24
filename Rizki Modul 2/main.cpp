#include "user.h"
#include "admin.h"
#include "non_admin.h"

int main()
{
    do{
    if(logout == true ){
        aksi_login();
    }
    if(sukses_login == 1){
        menu_admin();
    }
    else if(sukses_login == 2){
        menu_user();
    }
    }while(logout == true);
}
