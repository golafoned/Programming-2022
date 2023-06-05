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

    ifstream input_file("bills.txt");
    string line;

    try
    {
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
            else
            {
                throw invalid_argument("Invalid bill type!");
            }
        }
    }
    catch (const invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    input_file.close();

    sort(gas_bills.begin(), gas_bills.end(), compare_gas_bills);
    ofstream gas_file("gas_bills.txt");

    for (auto it = gas_bills.begin(); it != gas_bills.end(); it++)
    {
        gas_file << it->subscriber_name << " " << it->num_registered << " " << it->amount_paid << endl;
    }

    gas_file.close();

    sort(water_bills.begin(), water_bills.end(), compare_water_bills);

    ofstream water_file("water_bills.txt");

    for (WaterBill wb : water_bills)
    {
        water_file << wb.subscriber_name << " " << wb.last_reading << " " << wb.amount_water << " " << wb.amount_paid << endl;
    }

    water_file.close();

    ofstream largest_water_file("largest_water_bills.txt");
    sort(water_bills.begin(), water_bills.end(), compare_large_water_bills);
    water_bills.resize(5);

    for (WaterBill wb : water_bills)
    {
        largest_water_file << wb.subscriber_name << " " << wb.last_reading << " " << wb.amount_water << " " << wb.amount_paid << endl;
    }

    largest_water_file.close();

    return 0;
}