#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) :
        items(items) {
}

void updateQuality(Item& item) {
    if (item.name != "Aged Brie"
            && item.name != "Backstage passes to a TAFKAL80ETC concert") {
        if (item.quality > 0) {
            if (item.name != "Sulfuras, Hand of Ragnaros") {
                item.quality = item.quality - 1;
            }
        }
    } else {
        if (item.quality < 50) {
            item.quality = item.quality + 1;

            if (item.name == "Backstage passes to a TAFKAL80ETC concert") {
                if (item.sellIn < 11) {
                    if (item.quality < 50) {
                        item.quality = item.quality + 1;
                    }
                }

                if (item.sellIn < 6) {
                    if (item.quality < 50) {
                        item.quality = item.quality + 1;
                    }
                }
            }
        }
    }

    if (item.name != "Sulfuras, Hand of Ragnaros") {
        item.sellIn = item.sellIn - 1;
    }

    if (item.sellIn < 0) {
        if (item.name != "Aged Brie") {
            if (item.name != "Backstage passes to a TAFKAL80ETC concert") {
                if (item.quality > 0) {
                    if (item.name != "Sulfuras, Hand of Ragnaros") {
                        item.quality = item.quality - 1;
                    }
                }
            } else {
                item.quality = item.quality - item.quality;
            }
        } else {
            if (item.quality < 50) {
                item.quality = item.quality + 1;
            }
        }
    }
}

void updateQualityDexterityVest(Item& item) {
    updateQuality(item);
}
void updateQualityAgedBrie(Item& item) {
    updateQuality(item);
}
void updateQualityElixirOfTheMongoose(Item& item) {
    updateQuality(item);
}
void updateQualitySulfuras(Item& item) {
    updateQuality(item);
}
void updateQualityBackstagePasses(Item& item) {
    updateQuality(item);
}
void updateQualityConjuredManaCake(Item& item) {
    updateQuality(item);
}

void GildedRose::updateQuality() {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].name == "+5 Dexterity Vest") {
            updateQualityDexterityVest(items[i]);
        } else if (items[i].name == "Aged Brie") {
            updateQualityAgedBrie(items[i]);
        } else if (items[i].name == "Elixir of the Mongoose") {
            updateQualityElixirOfTheMongoose(items[i]);
        } else if (items[i].name == "Sulfuras, Hand of Ragnaros") {
            updateQualitySulfuras(items[i]);
        } else if (items[i].name
                == "Backstage passes to a TAFKAL80ETC concert") {
            updateQualityBackstagePasses(items[i]);
        }
    }
}
