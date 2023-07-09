#include <iostream>
#include <vector>
#include <limits>

class Person{
    private:
        std::string name;
        std::string phone;

    public:
        Person(std::string n, std::string p)
        {
            this->name = n;
            this->phone = p;
        }

        void display()
        {
            std::cout<<name<<" "<<phone;
        }




};




class BanquetOrder{
    private:
        Person customer;
        int guestNum;
        std::string roomChoice;
        float roomPrice;
        float tablePrice;
        float totalFoodPrice;
        float equipmentPrice;
        std::vector <std::string> equipment;
        static std::string rooms[5];
        static float prices[5];
        static std::string equipmentType[5];

        bool validateRoomChoice()
        {
            while (roomChoice != "Cozy Cabin" && roomChoice != "Deluxe Dining" && roomChoice != "Purple Parlor" && roomChoice != "Big Ballroom" && roomChoice != "Grand Guestroom" )
            {
                return false;
            }
            return true;
        }

    public:
        BanquetOrder(std::string n, std::string p, int gn):
            customer(n,p)
        {
            this->guestNum = gn;
            tablePrice = (guestNum/10)+2;

        }

        void availableRooms()
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            if (guestNum <= 25 && guestNum >= 15)
                std::cout<<"\nBased on the number of guests, you have the choice of the following rooms:\n Cozy Cabin \n Purple Parlor \n Deluxe Dining \n Big Ballroom \n Grand Guestroom";
            else if (guestNum <= 75 && guestNum >= 15)
                std::cout<<"\nBased on the number of guests, you have the choice of the following rooms:\n Purple Parlor \n Deluxe Dining \n Big Ballroom \n Grand Guestroom";
            else if (guestNum <= 125 && guestNum >= 50)
                std::cout<<"\nBased on the number of guests, you have the choice of the following rooms:\n Deluxe Dining \n Big Ballroom \n Grand Guestroom";
            else if (guestNum <= 150 && guestNum >= 50)
                std::cout<<"\nBased on the number of guests, you have the choice of the following rooms:\n Big Ballroom \n Grand Guestroom";
            else if (guestNum <= 250 && guestNum >= 100)
                std::cout<<"\nBased on the number of guests, you have the choice of the following rooms:\n Grand Guestroom";

          std::cout<<"\nPlease choose from the available rooms above: --> ";
          getline(std::cin,roomChoice);

          while ( validateRoomChoice() == false )
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Invalid ! please try again";
                std::cout<<"\nPlease choose from the available rooms above: --> ";
                getline(std::cin,roomChoice);
            }




        }

        void determineRoomPrice()
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            if (roomChoice == "Cozy Cabin")
                roomPrice = 250.00;
            else if (roomChoice == "Deluxe Dining")
                roomPrice = 500.00;
            else if (roomChoice == "Big Ballroom")
                roomPrice = 500.00;
            else if (roomChoice == "Purple Parlor")
                roomPrice = 250.00;
            else if (roomChoice == "Grand Guestroom")
                roomPrice = 750.00;
        }

        void userEnteree()
        {
            int numOfEnterees;
            int dessert;
            float pricePerPerson;

            std::cout<<"\nWould you like one main entree or two?";
            std::cin>>numOfEnterees;

            while (numOfEnterees < 1 && numOfEnterees > 2)
            {
                std::cout<<"Invalid input! please try again!";
                std::cout<<"\nWould you like one main entree or two?";
                std::cin>>numOfEnterees;
            }

            if (numOfEnterees == 1)
                pricePerPerson = 17.00;
            else if (numOfEnterees == 2)
                pricePerPerson = 19.50;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            std::cout<<"\nWould you like dessert 1.Yes/2.No?";
            std::cin>>dessert;

            if (dessert == 1)
                pricePerPerson = pricePerPerson + 2.00;


            totalFoodPrice = guestNum * pricePerPerson;


        }

        void equipemntSelection()
        {
            int choice;
            float price;

            while (choice != 0)
            {
                int y = 1;
                for (int x = 0 ; x < 5; x++)
                {
                    std::cout<<"\n"<<y<<" - "<<equipmentType[x]<<"     $"<<prices[x];
                    y++;
                }
                std::cout<<"\nEnter a choice or 0 to quit: ";
                std::cin>>choice;
                if (choice == 1)
                {
                    price = 100.00;
                    equipment.push_back(equipmentType[0]);
                }
                else if (choice == 2)
                {
                    price = 25.00;
                    equipment.push_back(equipmentType[1]);
                }
                else if (choice == 3)
                {
                    price = 50.00;
                    equipment.push_back(equipmentType[2]);
                }
                else if (choice == 4)
                {
                    price = 10.00;
                    equipment.push_back(equipmentType[3]);
                }
                else if (choice == 5)
                {
                    price = 5.00;
                    equipment.push_back(equipmentType[4]);
                }

                equipmentPrice += price;

                std::cout<<"\nYour equipment cost is currently: $"<<equipmentPrice;
            }
        }

        void displayOrder()
        {
            float finalPrice = roomPrice + tablePrice + totalFoodPrice + equipmentPrice;
            float serviceFee = finalPrice * 0.21;
            std::cout<<"\n\nQuote for ";
            customer.display();
            std::cout<<" to rent the "<<roomChoice<<" for "<<guestNum<<" guests will be:";
            std::cout<<"\nRoom Price: $"<<roomPrice;
            std::cout<<"\nTable Price: $"<<tablePrice;
            std::cout<<"\nFood Price: $"<<totalFoodPrice;
            std::cout<<"\nEquipment Needed: ";
            for(int x =0 ; x < equipment.size(); x++)
                std::cout<<"\n"<<equipment[x];
            std::cout<<"\nTotal Equipment Price : $"<<equipmentPrice;
            std::cout<<"\nService fee: $"<<serviceFee;
            std::cout<<"\nFinal Price: $"<< finalPrice + serviceFee;

        }







};



std::string BanquetOrder::rooms[5] = {"Cozy Cabin", "Purple Parlor", "Deluxe Dining", "Big Ballroom", "Grand Guestroom"};
float  BanquetOrder::prices[5] = {100.00, 25.00, 50.00, 10.00, 5.00};
std::string  BanquetOrder::equipmentType[5] = {"Projector", "Screen", "Sound Box ","8-foot Table","Easel"};



void askUserInformation(std::string& n, std::string& p);
void askForNumOfGuests(int& num);
int main()
{
    std::string name;
    std::string phone;
    int numOfGuests;
    std::cout<<"Welcome to Holiday Banquet Center!";

    askUserInformation(name,phone);

    askForNumOfGuests(numOfGuests);

    BanquetOrder oneOrder(name,phone,numOfGuests);

    oneOrder.availableRooms();

    oneOrder.userEnteree();

    oneOrder.determineRoomPrice();

    oneOrder.equipemntSelection();

    oneOrder.displayOrder();


    return 0;
}

void askUserInformation(std::string& n, std::string& p)
{


    std::cout<<"\nEnter the Customers Name:";
    getline(std::cin, n);

    std::cout<<"\nEnter the Customers phone:";
    getline(std::cin, p);


}

void askForNumOfGuests(int& num)
{

    std::cout<<"\nHow many guests do you expect :";
    std::cin>>num;

    while (num >250 || num < 15)
    {
        std::cout<<"Invalid input!!";
        std::cout<<"\nHow many guests do you expect :";
        std::cin>>num;
    }
}
