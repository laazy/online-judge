#include "trading.h"
#include <sstream>
#include <unordered_set>
#include <iomanip>
#include <queue>

struct MarsDate{
    int year;
    int month;
    int day;

    MarsDate(const string &trade_date){
        stringstream st;
        st << trade_date.substr(0,2) << " ";
        st << trade_date.substr(2,2) << " ";
        st << trade_date.substr(4,4);
        st >> day;
        st >> month;
        st >> year;
    }

    bool leapyear(){
        return year % 2 == 1 || year % 10 == 0;
    }

    void next_day(){
        if (day < 27){
            day++;
            return;
        }
        if (month < 24){
            if ((day == 27 && month % 6 == 0) || 
                (day == 28 && month % 6 != 0)){
                day = 1;
                month++;
                return;
            }
            if (day == 27 && month % 6 != 0){
                day++;
                return;
            }
            throw exception();
        }
        if (month == 24){
            if (leapyear()){
                if (day == 27){
                    day++;
                }else if (day == 28){
                    month = 1;
                    day = 1;
                    year++;
                }else{
                    throw exception();
                }
            }else{
                month = 1;
                day = 1;
                year++;
            }
            return;
        }
    }

    bool is_weekend(){
        switch (day)
        {
            case 1:case 7:case 8:case 14:
            case 15:case 21:case 22:case 28:
                return true;
            default:
                return false;
        }
    }

    string to_string(){
        stringstream st;
        string ans;
        st << setw(2) << setfill('0') << day << setw(2) << setfill('0') << month << year;
        st >> ans;
        return ans;
    }
};

string find_settlement_date(string trade_date, vector<string> holidays) {
    unordered_set<string> holidays_set;
    for (auto i : holidays){
        holidays_set.insert(i);
    }

    // string tmp_date = trade_date;
    MarsDate date = MarsDate(trade_date);  

    for (int i = 0; i < 3;){
        date.next_day();
        if (!date.is_weekend() && 
            holidays_set.find(date.to_string()) == holidays_set.end()){
            i++;
        }
    }
    return date.to_string();
}

struct Order {
    unsigned long id = 0;
    char side = ' ';
    unsigned short price = 0;
};
struct cmp1
{
    bool operator() (const Order& o1, const Order& o2){
        if (o1.price != o2.price){
        return o1.price < o2.price;
        }else{
            return o1.id < o2.id;
        }
    }
};
struct cmp2
{
    bool operator() (const Order& o1, const Order& o2){
        if (o1.price != o2.price){
        return o1.price > o2.price;
        }else{
            return o1.id > o2.id;
        }
    }
};


class MatchingEngine
{
public:
    MatchingEngine()
    {
        
    }

    /* Return the id of the matching order, if any, otherwise return 0. */
    unsigned long insert(Order& order)
    {
        unsigned long ans = 0;
        if (order.side == 'B'){
            if (sell_orders.empty()){
                buy_orders.push(order);
            }else{
                if (sell_orders.top().price <= order.price){
                    ans = sell_orders.top().id;
                    sell_orders.pop();
                }else{
                    buy_orders.push(order);
                }
            }

        }
        if (order.side == 'A'){
            if (buy_orders.empty()){
                sell_orders.push(order);
            }else{
                if (buy_orders.top().price >= order.price){
                    ans = buy_orders.top().id;
                    buy_orders.pop();
                }else{
                    sell_orders.push(order);
                }
            }
        }
        return ans;
    }
private:
    priority_queue<Order,vector<Order>, cmp1> buy_orders;
    priority_queue<Order,vector<Order>, cmp2> sell_orders;
};