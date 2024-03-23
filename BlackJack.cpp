#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Declare the functions
//Create the 52 cards in this function
void createCard(int CARD_NUMBER, string cardList[]);

// Generate a random number, then we can pick the card according by this number
string randomCard(string cardList[], int deskCard[]);

// calculate the point you have
void calculatePoint(string card, int& totalPoint, bool isDealer, bool dealerIsBiggerThan11);

// choose the value of A
int chooseValue();

void printResult(int yourPoint, int dealerPoint, int dealerCardNumber);

void printResult(int yourPoint, int dealerPoint, int dealerCardNumber)
{
    if (yourPoint > 21 && dealerPoint > 21)
    {
    cout << "You have more then 21 point." << endl;
    cout << "Dealer has " << dealerCardNumber << " cards." << endl;
    cout << "Dealer has more then 21 points." << endl;
    cout << "Draw!" << endl;
    }else if (yourPoint < 21 && dealerPoint > 21)
    {
    cout << "You win." << endl;
    cout << "Dealer totally have " << dealerCardNumber << " cards." << endl;
    cout << "Dealer has more then points." << endl;
    cout << "You have " << yourPoint << " point." << endl;
    }else if (yourPoint > 21 && dealerPoint < 21)
    {
    cout << "You have more then 21 point." << endl;
    cout << "Dealer has " << dealerCardNumber << " cards." << endl;
    cout << "Dealer wins!" << endl;
    }else
    {
        if (dealerPoint > yourPoint )
        {
        cout << "The dealer wins." << endl;
        cout << "Dealer totally have " << dealerCardNumber << " cards." << endl;
        cout << "The dealer has " << dealerPoint << " points." << endl;
        cout << "You lose!" << endl;
        }else if (dealerPoint == yourPoint)
        {
        cout << "You have " << yourPoint << " point." << endl;
        cout << "Dealer totally have " << dealerCardNumber << " cards." << endl;
        cout << "The dealer has " << dealerPoint << " points." << endl;
        cout << "Draw!" << endl;
        }
        else if (dealerPoint < yourPoint)
        {
        cout << "You win." << endl;
        cout << "Dealer totally have " << dealerCardNumber << " cards." << endl;
        cout << "The dealer has " << dealerPoint << " points." << endl;
        cout << "You have " << yourPoint << " point." << endl;
        } 
    }
}

// continue run the programm
void continueRun(int& yourPoint, int& dealerPoint, string cardList[], int deskCard[],int& yourCardNumber, int& dealerCardNumber, bool isPlayer, bool isDealer, bool dealerIsBiggerThan11);

void continueRun(int& yourPoint, int& dealerPoint, string cardList[], int deskCard[],int& yourCardNumber, int& dealerCardNumber, bool isPlayer, bool isDealer, bool dealerIsBiggerThan11)
{
    // Continue to pick the card
    while (true)
    {
        // Ask to the user whether wants to continue
        string continuePick;
        cout << endl;
        cout << "Do you want continue to pick a card? (Y/N): ";
        cin >> continuePick;

        // Check the input of user is Y/N
        while (continuePick != "Y" && continuePick != "N")
        {
            cout << "Do you want continue to pick a card? (Y/N): ";
            cin >> continuePick;
        }
        cout << endl;

        // When the user input Yes, continue the game
        if(continuePick == "Y")
        {   // Player pick a card
            cout << "Player: " << endl;
            string card = randomCard(cardList, deskCard);
            calculatePoint(card, yourPoint, isPlayer, dealerIsBiggerThan11);
            yourCardNumber++;

            // Print player's card
            cout << "You totally have " << yourCardNumber << " cards." << endl;
            cout << "You totally have " << yourPoint << " point." << endl;


            // Dealer pick a card, if is less than 17 point, pick the card
            cout << endl;
            cout << "The delaer: " << endl;
            if(dealerPoint < 17)
            {
                card = randomCard(cardList, deskCard);
                calculatePoint(card, dealerPoint, isDealer, dealerIsBiggerThan11);
                cout << endl;
                dealerCardNumber++;
                if(dealerPoint >= 11)
                {
                    dealerIsBiggerThan11 = true;
                }
            }

            // Print deealer's card
            cout << "Dealer totally have " << dealerCardNumber << " cards." << endl;
        }else
        {   // When I input No continue the programm
            // Check the condition of dealer
            while (dealerPoint < 17)
            {
                string card = randomCard(cardList, deskCard);
                calculatePoint(card, dealerPoint, isPlayer, dealerIsBiggerThan11);
                dealerCardNumber++;
                cout << "Dealer totally have " << dealerCardNumber << " cards." << endl;

                // Check the dealer whether is dead
                if(dealerPoint > 21)
                {
                    cout << "Dealer are dead! He have more than 21 points! You win!" << endl;
                    break;
                }
            }
             // Print the result
            printResult(yourPoint, dealerPoint, dealerCardNumber);
            break;
            
        }
    }
    
}

int chooseValue()
{
    int value;
    cout << "You have an 'A', please chood a value of your 'A'(1 or 11): ";
    cin >> value;
    while (value != 1 && value != 11)
    {
        cout << "Please choose only 1 or 11: ";
        cin >> value;
    }
    return value;
}

void calculatePoint(string card, int& totalPoint, bool isPlayer, bool dealerIsBiggerThan11){
    int point;

    if(card.at(0) == 'A')
    {
        if(isPlayer)
        {
            point = chooseValue();
        }else
        {
            if(dealerIsBiggerThan11)
            {
               point = 1; 
            }
            else
            {
                point = 11; 
            }
        }
        
    }else if(card.at(0) == '2')
    {
        point = 2;
    }else if(card.at(0) == '3')
    {
        point = 3;
    }else if(card.at(0) == '4')
    {
        point = 4;
    }else if(card.at(0) == '5')
    {
        point = 5;
    }else if(card.at(0) == '6')
    {
        point = 6;
    }else if(card.at(0) == '7')
    {
        point = 7;
    }else if(card.at(0) == '8')
    {
        point = 8;
    }else if(card.at(0) == '9')
    {
        point = 9;
    }else{
        point = 10;
    }

    if (isPlayer)
    {
        cout << card << "This card value "<< point << " point." << endl;
    }
    
    
    totalPoint += point;
}


string randomCard(string cardList[], int deskCard[])
{
    // define the random time
    srand(time(0));
    int randomNumber;

    // when the number is not empty, give a random number
    do
    {
        randomNumber = rand() % 52;
    } while (deskCard[randomNumber] == 0);
    
    // give the card according the random number
    string yourCard = cardList[randomNumber];
    // set the already picked number of card to 0
    // so this card will cannot be picked next time
    deskCard[randomNumber] = 0;
    
    return yourCard;
}

void createCard(int CARD_NUMBER, string cardList[])
{
    string cardValues[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "Tens", "Jack", "Queen", "King"};
    string cardSuit[] = {"Spade", "Heart", "Club", "Dianmond"};

    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 13; ++i) {
            cardList[i * 4 + j] = cardValues[i] + " " + cardSuit[j];
        }
    }
}

int main()
{
    // define the cards and points
    const int CARD_NUMBER = 52;
    int deskCard[CARD_NUMBER];
    string cardList[CARD_NUMBER];
    int yourCardNumber = 0;
    int dealerCardNumber = 0;
    int yourPoint = 0;
    int dealerPoint = 0;
    bool isPlayer = true;
    bool isDealer = false;
    int dealerIsBiggerThan11 = false;
    
    createCard(CARD_NUMBER, cardList);
    for(int i = 0; i < 52; i++)
    {
        deskCard[i] = i;
    }
    
    // Initial the programm, in the beginning, we have two card
    // These three sentence relize the action of pick a card
    cout << "Player: " << endl;
    string card1 = randomCard(cardList, deskCard);
    calculatePoint(card1, yourPoint, isPlayer, dealerIsBiggerThan11);
    yourCardNumber++;

    string card2 = randomCard(cardList, deskCard);
    calculatePoint(card2, yourPoint, isPlayer, dealerIsBiggerThan11);
    yourCardNumber++;

    cout << "You totally have " << yourCardNumber << " cards." << endl;
    cout << "You totally have " << yourPoint << " point." << endl;
    cout << endl;

    // Dealer pick two initial cards
    string card3 = randomCard(cardList, deskCard);
    cout << "The delaer: " << endl;
    calculatePoint(card3, dealerPoint, isDealer, dealerIsBiggerThan11);
    dealerCardNumber++;
    if(dealerPoint >= 11)
    {
        dealerIsBiggerThan11 = true;
    }

    string card4 = randomCard(cardList, deskCard);
    calculatePoint(card4, dealerPoint, isDealer, dealerIsBiggerThan11);
    dealerCardNumber++;
    if(dealerPoint >= 11)
    {
        dealerIsBiggerThan11 = true;
    }

    cout << "Dealer totally have " << yourCardNumber << " cards." << endl;
    
    // ask to the user whether wants to continue to play the game
    continueRun(yourPoint, dealerPoint, cardList, deskCard, yourCardNumber, dealerCardNumber, isPlayer, isDealer, dealerIsBiggerThan11);

    system("pause");
    return 0;
}