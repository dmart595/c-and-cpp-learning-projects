#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#define MAX_INV_SIZE 8 

typedef struct{
        int value;
        char rarity;
        char name[32];
    } items;

//initializes inventory and it's slots used up to 0
items inventory[MAX_INV_SIZE] = {0}; 
int slotsUsed = 0;

//player money
int coins = 0;

//Main menu Function
int mainMenu(){
    printf("\n<======== Welcome to your RPG Inventory ========>\n");
    printf("\nWhat can we do for you today?         Coins: %i \n", coins);

    printf("A: Add an Item! \n");
    printf("B: Sell an Item \n");
    printf("C: Look through your catalog \n");
    printf("\nD: Exit\n");
}

//Add Item Function
int addItem(){
    items newItem; //creates new item from items type

    //=========Quanitity Section=========///
    if(slotsUsed >= 8){
        printf("<====Inventory Full!====>\n");
        return 0;
    }

    
    //======NAMING SECTION======//
    char itemName[] = "Invalid"; //invalid by default
    newItem.rarity = 0;

    while(strcmp(itemName, "Invalid") == 0){
        char invalid[] = "Invalid";
        
        printf("\nName it! (No Spaces or Numbers)\n");
        scanf("%s", &itemName);
        
        if(strlen(itemName) > 32){ //character limit is 32
            printf("Too long. Please try again. \n");
            strcpy(itemName, invalid);
        }
    }
    strcpy(newItem.name, itemName); 

    printf("You named it: %s\n", newItem.name);
    
    
    //======RARITY SECTION======//
    int rarityInput;
    while(newItem.rarity == 0){
        
        printf("\nPick a rarity! (1,2,3,4)\n");
        printf("1: Common\n 2: Rare\n 3: Magical\n 4: Cosmic\n");
        scanf("%i", &rarityInput);
        if(rarityInput > 5){
            printf("Try Again.\n");
            newItem.rarity = 0;
        }
        newItem.rarity = rarityInput;
    }

    //======VALUE SECTION======//
    int valueInput;
    newItem.value = 0;
    int baseValue = 100;
    int rarityMultiplier = newItem.rarity * baseValue;
    while(newItem.value == 0){
        
        printf("How much did you pay for this? If found or scavanged, type 0.\n");
        scanf("%i", &valueInput);
        if(valueInput == 0){
            printf("Since it's Rarity Level %i, it's default value will be %i Coins!\n", newItem.rarity, rarityMultiplier);
            newItem.value = rarityMultiplier;
        }else if(valueInput > 0){
            newItem.value = valueInput;
        }

    }
    //Adds the item to the inventory and Completes Addition
    inventory[slotsUsed] = newItem;
    slotsUsed += 1;
    

    printf(" _________________\n");
    printf("|                 |\n");
    printf("|   ITEM ADDED!   |\n");
    printf("|_________________|\n");

    Sleep(2500);
    return 0;
}

int sellItem(){
    int sellInput;
    char confirm = 'N';
    int sellValue;
    printf("Which item would you like to sell?\n");
    for(int i = 0; i<slotsUsed; i++){
        printf("[%i] %s\n",i,inventory[i].name);
    }
    scanf(" %i", &sellInput);
    
    //handles sell value and makes items bought at low price default to sell at their rarity base price
    sellValue = inventory[sellInput].value;
    if(sellValue < 100 * inventory[sellInput].rarity){
        sellValue = 100 * inventory[sellInput].rarity;
    }

    printf("At a price of %i Coins, Confirm Sell for %s?\n",sellValue, inventory[sellInput].name);
    printf("[  Y or N  ]\n");
    scanf(" %c", &confirm);
    
    //Explanation for condition below: if the player confirms sell, then it loops through the items,
    //And copies over the item next door into the current spot. Basically shifts everything down starting
    //at the item you sell.
    
    if(confirm == 'Y'){
        for(int i = sellInput; i<slotsUsed; i++){  //THIS IS GENIUS RIGHT HERE!!!
            inventory[i] = inventory[i+1];         

        }
        slotsUsed--;
        printf("==== SOLD ====");
        coins = coins + sellValue;
        Sleep(1000);
        return 0;
    }else if(confirm == 'N'){
        printf("Okay taking you to Main menu.\n");
        Sleep(1000);
        return 0;
    }
}

int catalogView(){
    bool runningViewer = true;
    int exitInput;
    if(slotsUsed == 0){
        printf("Nothing in Inventory\n");
        Sleep(1000);
        return 0;
    }
    while(runningViewer == true){
        printf("--------------INVENTORY------------\n\n");    
        printf("-----------------------------------\n");
        for(int i = 0; i<slotsUsed; i++){
            printf("%s - %i Coins\n", inventory[i].name, inventory[i].value);
            printf("-----------------------------------\n");
        
        }
        printf("Type 0 to exit.");
        scanf(" %i", &exitInput);
        if(exitInput == 0){
            runningViewer = false;
        }
    }
    return 0;
}

int main(){
    char userSelection;
    bool playing = true;
    while(playing){
        
        mainMenu();
        //checks for user selection and stores it in memory
        scanf(" %c", &userSelection); 
        
        if(userSelection == 'A'){
            addItem();
        }else if(userSelection == 'B'){
            sellItem();
        }else if(userSelection == 'C'){
            catalogView();
        }else if(userSelection == 'D'){
            playing = false;
        }
        
    }
    return 0;
}


