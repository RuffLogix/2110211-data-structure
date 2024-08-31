#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

class Letter{
    public:
        string name;
        string address;
        string province;
        string district;
        int zip;

        bool operator < (const Letter& other) const {
            if (zip == other.zip) {
                if (address == other.address) {
                    if (district+province == other.district+other.province) return name < other.name;
                    return district+province < other.district+other.province;
                }
                return address < other.address;
            }
            return zip < other.zip;
        }
};

class ZipInfo{
    public:
        int zip;
        string province;
        string district;
};

map<pair<string, string>, int> postalcodes;

void correctZipAndSortLetters(vector<ZipInfo>& zipinfo, vector<Letter>& letters) {
    for (ZipInfo zi: zipinfo) {
        postalcodes[{zi.province, zi.district}] = zi.zip;
    }

    for (Letter& l: letters) {
        l.zip = postalcodes[{l.province, l.district}];
    }

    sort(letters.begin(), letters.end());
}

int main() {
    int nzip;
    cin >> nzip;
    vector<ZipInfo> zipinfo;
    for (int i = 0; i < nzip; i++) {
        ZipInfo z;
        cin>>z.zip>>z.district>>z.province;
        zipinfo.push_back(z);
    }
    int n;
    cin>>n;
    vector<Letter> letters;
    for (int i = 0; i < n; i++) {
        Letter l;
        cin>>l.name>>l.address>>l.district>>l.province>>l.zip;
        letters.push_back(l);
    }

    correctZipAndSortLetters(zipinfo, letters);

    for (auto& l:letters) {
        cout<<l.name<<" "<<l.address<<" "<<l.district<<" "<<l.province<<" "<<l.zip<<endl;
    }
}
