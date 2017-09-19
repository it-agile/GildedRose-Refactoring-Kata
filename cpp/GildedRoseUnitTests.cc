#include <gtest/gtest.h>
#include <sstream>
#include "GoldenMaster.h"

TEST(GildedRoseTest, Foo) {
    vector<Item> items;
    items.push_back(Item("Foo", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("fixme", app.items[0].name);
}

TEST(GildedRoseTest, GoldenMaster) {
    stringstream actualStream;
    createGoldenMasterStream(actualStream);
    ifstream infile(goldenMasterFile.c_str());
    string expected;
    while (getline(infile, expected)) {
        string actual;
        getline(actualStream, actual);
        EXPECT_EQ(expected, actual);
    }
}

void example() {

    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    items.push_back(Item("Conjured Mana Cake", 3, 6));
    GildedRose app(items);
    app.updateQuality();
}
