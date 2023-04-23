#include <iostream>
#include <vector>
#include <array>

using std::cin;
using std::cout;
using std::string;

struct food_price {
    string burger = "Cheeseburger and Fries $";
    double burger_price = 9.97;
    string veggie_burger = "Vegetarian Burger $";
    double veggie_price = 9.96;
    string hotdog = "Hotdog and Fries $";
    double hotdog_price = 6.69;
    string mozz_sticks = "Mozzarella Sticks and Marinara $";
    double mozz_price = 4.32;
    string quesadillas = "Quesadillas $";
    double quesadillas_price = 7.87;
    string bagel = "Toasted Bagel with Cream Cheese $";
    double bagel_price = 1.44;
    string grilled_cheese = "Grilled Cheese $";
    double grilled_cheese_price = 6.88;
    string soup_of_day = "Soup of the Day $";
    double soup_price = 3.36;
    string house_salad = "House Salad $";
    double house_salad_price = 5.49;
    string chx_wrap = "Chicken Salad Wrap $";
    double chx_wrap_price = 7.93;
    string drink_cup = "Fountain Soda $";
    double drink_price = 2.74;
};

struct order {
    int burger = 0;
    int veggie_burger = 0;
    int hotdog = 0;
    int mozz_sticks = 0;
    int quesadillas = 0;
    int bagel = 0;
    int grilled_cheese = 0;
    int soup_of_day = 0;
    int house_salad = 0;
    int chx_wrap = 0;
    int drink_cup = 0;
};

bool check_for_exit() {
    // Ask if they want to leave and leave on "n"
    // Returns true if they want to exit, false if still want to continue
    std::string leave = "n";
    std::cout << "\nDo you have more to your order? ";
    std::cin >> leave;
    if (leave[0] == 'n' || leave[0] == 'N') {
        return true;
    }
    return false;
}

// creates vectors for the menu and users order
std::vector<food_price> menu {};
std::vector<order> user_order{};

void menu_output(){
    //outputs menu to user
    food_price price{};
    menu.push_back(price);

    for (const auto& f : menu) {
        std::cout << "\nHere is our menu: \n1. " << f.burger << f.burger_price << "\n2. " << f.veggie_burger << f.veggie_price << "\n3. " << f.hotdog << f.hotdog_price << "\n4. " << f.mozz_sticks << f.mozz_price << "\n5. " << f.quesadillas << f.quesadillas_price << "\n6. " << f.bagel << f.bagel_price << "\n7. " << f.grilled_cheese << f.grilled_cheese_price << "\n8. " << f.soup_of_day << f.soup_price << "\n9. " << f.house_salad << f.house_salad_price << "\n10. " << f.chx_wrap << f.chx_wrap_price << "\n11. " << f.drink_cup << f.drink_price << "\n\n";
    }
}

int get_verified_choice() {
    // Gets user choice and ensures it is between 0 & max size
    // returns negative if error
    int raw_choice = 0;

    cin >> raw_choice;

    if (raw_choice < 0 || raw_choice < menu.size()-1) {
        return -1;
    }
    int users_choice = raw_choice - 1;
    return users_choice;
}

double ask_discount(){
    // asks users if they qualify for any discounts
    int user_choice;
    double discount = 0;
    const std::array<std::string,5> possible_discount = {"Senior", "Preferred Member", "Educator", "Veteran", "No"};

    cout << "Do you qualify for any of the following discounts: ";
    for (int i=0; i<=possible_discount.size()-1; i++) {
        cout << "\n\t[" << i + 1 << "] " << possible_discount[i];
    }

    cout << "\nEnter selection [ ]\b\b";
    cin >> user_choice;
    switch (user_choice-1) {
        case 0: cout << "Thank you! a 5% discount will be taken from your total";
            discount = 0.05;
            break;
        case 1: cout << "Thank you for being a Preferred Member. You will recieve 8% off your order.";
            discount = 0.08;
            break;
        case 2: cout << "Thank you for educating. You will recieve a 2.5% Discount.";
            discount = 0.025;
            break;
        case 3: cout << "Thank you for your service. A 4% Discount will be taken off your order.";
            discount = 0.04;
            break;
        case 4: break;
    }
    return discount;
}

int main() {
    // program to display menu, take a users order, and take the users paymenet
    cout << "Welcome to Jay's Eatery!";
    menu_output();

    double subtotal = 0.0;

    // do while takes users order while the exit statement returns false
    do {
        order items{};
        food_price price{};

        cout << "What would you like to order? (1-11) [ ]\b\b";

        int user_choice = get_verified_choice();
        if (user_choice < 0) {
            exit(1);
        }

        switch(user_choice) {
            case 0: cout << "How many cheeseburgers would you like? ";
                cin >> items.burger;
                user_order.push_back(items);
                subtotal += items.burger * price.burger_price;
                break;
            case 1: cout << "How many Vegetarian Burgers would you like? ";
                cin >> items.veggie_burger;
                subtotal += items.veggie_burger * price.veggie_price;
                break;
            case 2: cout << "How many Hotdog and Fries would you like? ";
                cin >> items.hotdog;
                subtotal += items.hotdog * price.hotdog_price;
                break;
            case 3: cout << "How many Mozzarella Sticks and Marinara would you like? ";
                cin >> items.mozz_sticks;
                subtotal += items.mozz_sticks * price.mozz_price;
                break;
            case 4: cout << "How many Quesadillas would you like? ";
                cin >> items.quesadillas;
                subtotal += items.quesadillas * price.quesadillas_price;
                break;
            case 5: cout << "How many Toasted Bagel with Cream Cheeses would you like? ";
                cin >> items.bagel;
                subtotal += items.bagel * price.bagel_price;
                break;
            case 6: cout << "How many Grilled Cheeses would you like? ";
                cin >> items.grilled_cheese;
                subtotal += items.grilled_cheese * price.grilled_cheese_price;
                break;
            case 7: cout << "How many Soup of the Days would you like? ";
                cin >> items.soup_of_day;
                subtotal += items.soup_of_day * price.soup_price;
                break;
            case 8: cout << "How many House Salads would you like? ";
                cin >> items.house_salad;
                subtotal += items.house_salad * price.house_salad_price;
                break;
            case 9: cout << "How many Chicken Salad Wraps would you like? ";
                cin >> items.chx_wrap;
                subtotal += items.chx_wrap * price.chx_wrap_price;
                break;
            case 10: cout << "How many Fountain Sodas would you like? ";
                cin >> items.drink_cup;
                subtotal += items.drink_cup * price.drink_price;
                break;
            default: menu_output();
                break;
        }
        cout << "\nYour current total is: $" << subtotal;


    } while (check_for_exit());

    cout << "\n\n\n\nPayment Center\n";
    double discount = ask_discount();

    // Calculates discount, tax, and final total
    double tip_amount;
    double tax_amount;

    cout.precision(2);
    cout << "\n\nYour Subtotal is: $" << std::fixed << subtotal << "\n";
    discount = subtotal * discount ;
    cout << "Discount: $" << discount << "\n";
    tax_amount = subtotal * 0.089;
    cout << "Tax(x0.089): $" << tax_amount << "\n";
    subtotal = subtotal + tax_amount + discount;
    cout << "Total: $" << subtotal;

    // calculates tip for staff
    cout << "\nHow Much would you like to tip our staff?: $";
    cin >> tip_amount;
    subtotal += tip_amount;

    cout << "$" << subtotal;

    double payment_amount;
    bool pay = true;
    while (pay == true){
        //determines if user has paid the right ammount for their food
        cout << "\n\nPlease enter payment amount: $";
        cin >> payment_amount;

        if (payment_amount < subtotal){
            subtotal = subtotal - payment_amount;
            cout << "Remaining Balance: $" << subtotal;
        }
        else if (payment_amount > subtotal){
            subtotal = payment_amount - subtotal;
            cout << "Thank you! You're owed total is: $" << subtotal << "\nHave a lovely rest of your day!";
            pay = false;
        }
        else{
            cout << "Thank you! Have a lovely rest of your day!";
            pay = false;
        }
    }
}