#include <string>
#include <cstdlib>
#include <ctime>  
#include <sstream>
#include <list>
#include <vector>
#include <iostream>
using namespace std;
////////--------````````,,,,,,,,--------********>>>>>>>>////////
#define NOFSUI 4  // number of suits
#define NOFVLU 13 // number of values
#define DECLEN 52 // deck length
////////""""""""''''''''AAAAAAAAaaaaaaaa!!!!!!!!11111111%%%%%%%%
typedef size_t         offset_t;
typedef const offset_t coffset_t;
typedef const size_t   cize_t;
typedef int            slot_t; // table positions
typedef const slot_t   clot_t;
//      //      //      //      //      //      //      //      //
struct Card; // forward declaration
namespace glob { ///////--------<<<<<<<<========::::::::````````
    const char suiNom[] = {'s','c','d','h'};
    const char vluNom[] = {'1','2','3','4','5','6','7','8','9',
                           'T','J','Q','K'};
    Card *cards = nullptr;
    void init(void);
    bool match(offset_t i, offset_t j);
} //////________<<<<<<<<11111111........<<<<<<<<########""""""""
struct Card { //________QQQQQQQQ<<<<<<<<11111111========zzzzzzzz
    offset_t sui;
    offset_t vlu;
    string   nom;
    Card(coffset_t& sui, coffset_t& vlu): sui(sui), vlu(vlu)
    {   nom.push_back(glob::vluNom[vlu]);
        nom.push_back(glob::suiNom[sui]);
    }
    Card(void): Card(0, 0) {} // default constructor (As)
    bool FaceCard(void) { // face card predicate
        return (9 < vlu);
    }
}; /////********11111111@@@@@@@@********88888888GGGGGGGGgggggggg
void glob::init(void) {
    // initialize random generator
    srand((unsigned) time(NULL));
    // set-up cards
    cards = new Card [DECLEN];
    for (offset_t j = 0, s = 0; s < NOFSUI; s++)
    {   for (offset_t v = 0; v < NOFVLU; v++)
        {   cards[j++] = Card(s, v);
        }
    }
} //////--------11111111<<<<<<<<\\\\\\\\........>>>>>>>>GGGGGGGG
template <template <typename...> typename T> // wtf?
struct Cont { // container
    size_t cols; // for oufut 
    T<offset_t> offset;
    friend ostream& operator << (ostream& strm, const Cont& cont)
    {   cize_t& cols = cont.cols;
        stringstream sstrm;
        size_t cntr = 1;

        for (const auto& j: cont.offset)
        {   string sep = (cntr++ % cols)? ",": "\n";
            sstrm << (glob::cards[j]).nom << sep;
        }
        string const str = sstrm.str();

        return strm << str.substr(0, str.size() - 1);
    } //        --------        --------        ````````,,,,,,,,
	bool empty(void) {
		return offset.empty();
	}
}; /////********>>>>>>>>________::::::::--------,,,,,,,,""""""""
struct Dec: Cont<list>
{   Dec(void);
    void shfle(void);
    offset_t detach(void);
    void attach(offset_t j) 
    {   offset.push_front(j);
    }
}; /////--------````````        ________********        >>>>>>>>
Dec::Dec(void)
{   cols = NOFVLU;
    for (offset_t j = 0; j < DECLEN; j++)
    {   offset.push_back(j);
    }
} //////--------        ********````````--------        ________
void Dec::shfle(void) 
{   offset_t* copy = new offset_t [offset.size()];
    int i = 0;

    for (coffset_t& j: offset)
    {   copy[i++] = j;
    }
    while (--i > 0) // i = -1 for empty deck
    {   coffset_t j = rand() % (i + 1); // [0:i]
        swap(copy[i], copy[j]);
    }
    for (offset_t& j: offset)
    {   j = copy[i++];
    }
    delete[] copy;
} //////        ********........        --------::::::::>>>>>>>>
offset_t Dec::detach(void) // pop an offset from ze rear
{   offset_t i = offset.back();

    offset.pop_back();

    return i;
} //////        ********________````````<<<<<<<<,,,,,,,,////////
struct Tab: Cont<vector> // Table
{   size_t size;
    Tab(size_t rows, size_t cols) 
    {   this->cols = cols;
        size = rows*cols;
        offset.resize(size);
    }
    offset_t& operator [] (clot_t j)
    {   return offset[j];
    }
}; /////        --------********========        ::::::::>>>>>>>>
struct Croupier {
    Dec dec;
    Tab tab;
    list<slot_t> box; // solo candidates
    list<slot_t> ck;  // checked pairs
    Croupier(const Dec& dec, const Tab& tab):
		dec(dec), tab(tab) {}
    void preflop(void) 
    {   dec.shfle();
    }
    void flop(void);
    void dunf(bool dec, bool tab);
    slot_t matchbox(slot_t& j);
    void turn(void);
    void river(void);
	void play(void);
}; /////--------\\\\\\\\        %%%%%%%%........''''''''""""""""
void Croupier::flop(void)
{   for (slot_t j = 0; j != tab.size;) 
    {   offset_t i = dec.detach();
        if ((glob::cards[i]).FaceCard())
        {   dec.attach(i);
            continue;
        }
        tab[j++] = i;
    }
} //////========        ,,,,,,,,llllllll--------\\\\\\\\[[[[[[[[
void Croupier::dunf(bool dec, bool tab)
{   if (dec and !(this->dec).empty()) {
        cout << this->dec << "\n\n";
    }
    if (tab and !(this->tab).empty()) {
        cout << this->tab << "\n\n";
    }
} //////........````````========''''''''********////////++++++++
//// ck if the corresponding cards sum to 10 (8) or if botha T's
bool glob::match(offset_t i, offset_t j)
{   if ((cards[i].vlu + cards[j].vlu) == 8)
    {   return true;
    }
    if ((cards[i].vlu == 9) and (cards[j].vlu == 9))
    {   return true;
    }
    return false;
} //////--------$$$$$$$$::::::::        >>>>>>>>''''''''________
slot_t Croupier::matchbox(slot_t& j)
{   for (clot_t& i: box) 
    {   if (glob::match(tab[j], tab[i]))
        {   return i;
        }
    }
    return -1;
} //////        --------,,,,,,,,````````>>>>>>>>////////________
void Croupier::turn(void)
{   for (slot_t j = 0; j != tab.size; j++)
    {   slot_t i = matchbox(j);
        if (i != -1)
        {   ck.push_back(i);
            ck.push_back(j);
            box.remove(i);
        } else
        {   box.push_back(j);
        }
    }
} //////********========________````````<<<<<<<<++++++++@@@@@@@@
void Croupier::river(void)
{   while (true)
    {   box.clear();    
        ck.clear();
        turn();
        if (ck.empty())
        {   return; // we ar don!
        }
        for (clot_t& i: ck)
        {   offset_t j = dec.detach();
            tab[i] = j;
        }
        dunf(1,1);
    }
} //////        ________========::::::::>>>>>>>>````````________
void Croupier::play(void)
{   dunf(1,1);
    preflop();
    dunf(1,0);
    flop();
    dunf(1,1);
    river();
} //////--------________^^^^^^^^********========\\\\\\\\;;;;;;;;
int main(void) {
    glob::init();

    Dec dec;
    Tab tab(3,4);
	
    Croupier(dec, tab).play();

    return 0;
} //////--------        <<<<<<<<--------````````,,,,,,,,;;; log:
