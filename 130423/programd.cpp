#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct GasBill
{
    string subscriber_name;
    int num_registered;
    double amount_paid;
};

struct WaterBill
{
    string subscriber_name;
    int last_reading;
    int amount_water;
    double amount_paid;
};

bool compare_gas_bills(const GasBill &gb1, const GasBill &gb2)
{
    return gb1.num_registered > gb2.num_registered;
}

bool compare_water_bills(const WaterBill &wb1, const WaterBill &wb2)
{
    return wb1.subscriber_name < wb2.subscriber_name;
}

bool compare_large_water_bills(const WaterBill &wb1, const WaterBill &wb2)
{
    return wb1.amount_paid > wb2.amount_paid;
}
int main()
{
    deque<GasBill> gas_bills;
    deque<WaterBill> water_bills;

    try
    {
        ifstream input_file("bills.txt");
        string line;

        while (getline(input_file, line))
        {
            string type = line.substr(0, line.find_first_of(" "));
            if (type == "gas")
            {
                GasBill gb;
                gb.subscriber_name = line.substr(line.find_first_of(" ") + 1, line.find_last_of(" ") - line.find_first_of(" ") - 3);
                gb.num_registered = stoi(line.substr(line.find_last_of(" ") + 1));
                gb.amount_paid = stod(line.substr(line.find_first_of(" ", line.find_first_of(" ") + 1) + 1));
                gas_bills.push_back(gb);
            }
            else if (type == "water")
            {
                WaterBill wb;
                wb.subscriber_name = line.substr(line.find_first_of(" ") + 1, line.find_first_of(" ", line.find_first_of(" ") + 1) - line.find_first_of(" ") - 1);
                wb.last_reading = stoi(line.substr(line.find_first_of(" ", line.find_first_of(" ") + 1) + 1, line.find_last_of(" ", line.find_last_of(" ") - 1) - line.find_first_of(" ", line.find_first_of(" ") + 1)));
                wb.amount_water = stoi(line.substr(line.find_last_of(" ", line.find_last_of(" ") - 1) + 1, line.find_last_of(" ") - line.find_last_of(" ", line.find_last_of(" ") - 1) - 1));
                wb.amount_paid = stod(line.substr(line.find_last_of(" ") + 1));
                water_bills.push_back(wb);
            }
        }

        input_file.close();
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    // Сортування газових рахунків за числом прописаних людей
    sort(gas_bills.begin(), gas_bills.end(), compare_gas_bills);
    ofstream gas_file("gas_bills.txt");

    copy(gas_bills.begin(), gas_bills.end(), ostream_iterator<GasBill>(gas_file, "\n"));

    gas_file.close();

    // Сортування водяних рахунків за іменем
    sort(water_bills.begin(), water_bills.end(), compare_water_bills);

    ofstream water_file("water_bills.txt");

    copy(water_bills.begin(), water_bills.end(), ostream_iterator<WaterBill>(water_file, "\n"));

    water_file.close();

    // Сортування по оплаті топ 5
    ofstream largest_water_file("largest_water_bills.txt");
    sort(water_bills.begin(), water_bills.end(), compare_large_water_bills);
    deque<WaterBill> largest_water_bills;

    if (water_bills.size() >= 5)
    {
        largest_water_bills.assign(water_bills.begin(), water_bills.begin() + 5);
    }
    else
    {
        largest_water_bills = water_bills;
    }
    return 0;
}