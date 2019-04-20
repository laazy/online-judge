#include "trading.h"
#include "../util.h"
#include "../main.h"

#define null 0

void test_find_settlement_date(){
    cout << find_settlement_date("05022020", {"02012020", "27062020"})
        << endl;
    cout << find_settlement_date("26062025", {"02012025", "27062025"})
        << endl;
    cout << find_settlement_date("25242019", {"02012020", "27062020"})
        << endl;

}

int func(){
    test_find_settlement_date();
    return 0;
}
