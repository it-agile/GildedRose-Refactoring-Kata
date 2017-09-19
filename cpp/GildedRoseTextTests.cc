#include "GildedRose.h"

int main() {
    ofstream outfile(goldenMasterFile.c_str());

    createGoldenMasterStream(outfile);

    outfile.close();
}
