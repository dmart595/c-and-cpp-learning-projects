# C/C++ Learning Projects

This is my personal projects repository to work on C and C++. Concepts to be explored here include:
* Memory Allocation with the Heap and Stack (Malloc, Calloc, Free)
* Pointers through using * (dereference symbol) and & (address symbol)
* Typedef structs/structs for constructor management and proprietary container types.

## Projects So Far

### RPG Inventory Manager

This project was used to learn structs/constructors. The purpose of the struct came into play when I was creating a type for items. I made a new struct called items where each item would have a name, rarity, and value.

Names are based in a size 32 char array, making sure the player does not input a name above a 32 character limit.
Rarity is set by an integer from values 1-4.
Value is set by default to the `rarity * 100` if the item was found. If not then the user can input the value themselves.

**This project implements 3 crucial functions.**

1. Add an Item
2. Sell an Item
3. View your catalogue.

* The add item function goes through the entire process of giving a new item all of its characteristics. After the item is added, it can be viewed with the view catalog function.

* The sell item function enables the user to sell an item by displaying their current inventory and giving them an offer. The offer will always be the greatest possible offer. For example, if you found an object that is worth 400 coins because the rarity is 4, then the offer will be for 400. After the item is sold, it is removed from the array of items. This is done through a for loop which starts at the current item being sold which then shifts all the items to the left 1 and overrides the items slot.

* The view catalog function allows the user to view their current inventory, only displaying the slots that are being used up. For example, if 5 slots are occupied only those 5 will be printed.