#ifndef GOLDENMASTER_H_
#define GOLDENMASTER_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "GildedRose.h"

using namespace std;

string goldenMasterFile = "GOLDENMASTER.txt";

inline ostream& operator<<(ostream& s, Item& item) {
    s << item.name << ", " << item.sellIn << ", " << item.quality;
    return s;
}

inline void insertInGoldenMaster(vector<Item> items, GildedRose app,
        ostream& outStream) {
    outStream << "OMGHAI!" << endl;
    for (int day = 0; day <= 30; day++) {
        outStream << "-------- day " << day << " --------" << endl;
        outStream << "name, sellIn, quality" << endl;
        for (vector<Item>::iterator i = items.begin(); i != items.end(); i++) {
            outStream << *i << endl;
        }
        outStream << endl;
        app.updateQuality();
    }
}

inline vector<Item> createTestItems() {
    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", -1, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 49));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 49));
    return items;
}

inline void createGoldenMasterStream(ostream& outfile) {
    vector<Item> items = createTestItems();
    GildedRose app(items);
    insertInGoldenMaster(items, app, outfile);
}

#endif
