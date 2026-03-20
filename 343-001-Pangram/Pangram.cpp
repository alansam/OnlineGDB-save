
#include <print>
#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <vector>
#include <array>
#include <cctype>    // Required for ::tolower, ::isalpha

using namespace std::string_literals;       // for ""s suffix
using namespace std::string_view_literals;  // for ""sv suffix

//  compiler macro for allocation of letters present array
#define LETTER_ARRAY_SZ 26

namespace pang {

// program information
constexpr
struct pgm_info {
  static constexpr std::uint16_t ver { 0u };
  static constexpr std::uint16_t rel { 1u };
  static constexpr std::uint16_t mod { 0u };
  static constexpr std::string_view pgm { "Pangram"sv };
} vi;

/**
 * a vector of sample pangrams
 */
inline
static
std::vector<std::string_view> pangrams {
  "The quick brown fox jumps over the lazy dog"sv,
  "A quick brown fox jumps over the lazy dog"sv,
  "The quick brown fox jumps over a lazy dog"sv,
  "The kuick brown fox jumps over the lazy dog"sv,  // should fail
  "The quick brown fox jumped over the lazy dog"sv, // common error
  "Thë qüïck bröwñ föx jümps övër ä läzy dög"sv,    // contains accented letters, should fail
  "\n"sv,

  /*
   * - A Plethora of Pangrams
   *   Note: A pangram, or holoalphabetic sentence, is a sentence that contains every letter of the alphabet at least once.
   *   Each of the following sentences uses each letter of the alphabet at least once and makes sense (more or less). At the
   *   end of each sentence, the number in parentheses is the total number each took to include all 26 letters. Can you top
   *   the famous first one?
   *
   *   A quick brown fox jumps over the lazy dog OR The quick brown fox jumps over a lazy dog.
   *   At 33 letters, the most famous, BUT make sure one of them id an “a;” they cannot both be a “the.”
   *
   * @see <a href="https://mseffie.com/assignments/calligraphy/Plethora%20of%20Pangrams.pdf">Plethora of Pangrams</a>
   */
  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  "Blowzy night-frumps vex'd Jack Q"sv, // (26)
  "Glum Schwartzkopf vex'd by NJ IQ"sv, // (26)
  "Jived fox nymph grabs quick waltz"sv, // (28)
  "Glib jocks quiz nymph to vex dwarf"sv, // (28)
  "Waltz, bad nymph, for quick jigs vex"sv, // (28)
  "Sphinx of black quartz, judge my vow"sv, // (29) Used by Adobe InDesign to display font samples.
  "Quick zephyrs blow, vexing daft Jim"sv, // (29)
  "How vexingly quick daft zebras jump"sv, // (30)
  "The five boxing wizards jump quickly"sv, // (31)
  "Jackdaws love my big sphinx of quartz"sv, // (31) Similarly, used by Windows XP for some fonts.
  "Pack my box with five dozen liquor jugs"sv, // (32) According to Wikipedia, this one is used on NASA’s Space Shuttle.
  "Big Fuji waves pitch enzymed kex liquor"sv, // (33)
  "A quick brown fox jumps over the lazy dog"sv, // (33) >>> added back in
  "The quick brown fox jumps over a lazy dog"sv, // (33) >>> added back in
  "The quick brown fox jumps over the lazy dog"sv, // (35) >>> added back in
#ifdef AS_INCLUDE_KNOWN_ERRORS
  "The quick brown fox jumped over the lazy dog"sv, // (36) common error
#endif
  "Fix problem quickly with galvanized jets"sv, // (35)
  "Heavy boxes perform quick waltzes and jigs"sv, // (36)
  "Jinxed wizards pluck ivy from the big quilt"sv, // (36)
  "Watch Jeopardy!, Alex Trebek’s fun TV quiz game"sv, // (37)

#ifdef AS_INCLUDE_KNOWN_ERRORS
  "Adjusting quiver and bow, Zompye killed the fox"sv, // (39) oops!
#endif
  "Adjusting quiver and bow, Czompye killed the fox"sv, // fixed

  "Amazingly few discotheques provide jukeboxes"sv, // (40)
  "Cozy lummox gives smart squid who asks for job pen"sv, // (41) More modern Mac tester sentence.

#ifdef AS_INCLUDE_KNOWN_ERRORS
  "The vixen jumped quickly on her foe, barking with zeal"sv, // (44) oops!
#endif
  "The vixen jumped so quickly on her foe, barking with zeal"sv, // fixed

  "Fat wealthy diva became rocking jazz saxophone queen"sv, // (45)

#ifdef AS_INCLUDE_KNOWN_ERRORS
  "Mad Brother Farvis was quickly axed for crazy praying"sv, // (45) oops!
#endif
  "Mad Brother Jarvis was quickly axed for crazy praying"sv, // fixed

  "Back home after jiving so, he expired with quizzicality"sv, // (46
  "Sixty zippers were quickly picked from the woven jute bag"sv, // (48)
  "Crazy Fredericka bought many very exquisite opal jewels"sv, // (48)
  "Grumpy wizards make toxic brew for the evil queen and jack"sv, // (48)
  "How razorback-jumping frogs can level six piqued gymnasts!"sv, // (49) Not going to win any brevity awards at 49 letters long, but old-time Mac users will recognize it.
  "The wizard quickly jinxed the gnomes before they vaporized"sv, // (50)
  "All questions asked by five watched experts amaze the judge"sv, // (50)
  "The July sun caused a fragment of black pine wax to ooze on the velvet quilt"sv, // (51)
  "Anxious Al waved back his pa from the zinc quarry just sighted"sv, // (51)

#ifdef AS_INCLUDE_KNOWN_ERRORS
  "Intoxicated Queen Elizabeth vows Mick Jagger is perfection"sv, // (51) oops!
#endif
  "Intoxicated Queen Elizabeth vows Mick Jagger is very perfection"sv, // fixed

  "The girl loved a joyful boy who quickly fixed her zany problems"sv, // (52)
  "A quart jar of oil mixed with zinc oxide makes a very bright paint"sv, // (53)
  "Whenever the black fox jumped, the squirrel gazed suspiciously"sv, // (53)
  "Alfredo just must bring very exciting news to the plaza quickly"sv, // (53)

#ifdef AS_INCLUDE_KNOWN_ERRORS
  "Joe was pleased over our gift of quail, mink, zebra, and clever oryx"sv, // (53) oops!
#endif
  "Joe H. was pleased over our gift of quail, mink, zebra, and clever oryx"sv, // fixed

  "If I give you cloth with quartz beads -- onyx, jasper, amethyst -- keep it"sv, // (54)
  "The job requires extra pluck and zeal from every young wage earner"sv, // (54)
  "Picking just six quinces, the new farmhand proves strong but lazy"sv, // (54)
  "A mad boxer shot a quick, gloved jab to the jaw of his dizzy opponent"sv, // (54)
  "The job requires extra pluck and zeal from every young wage earner"sv, // (55)
  "Jaded zombies acted quaintly but kept driving their oxen forward"sv, // (55)
  "While making deep excavations, we found some quaint bronze jewelry"sv, // (56)

#ifdef AS_INCLUDE_KNOWN_ERRORS
  "Engelbert Humperinck’s exquisitely frothy & vacuous waltz is a joy"sv, // (56) oops!
#endif
  "Engelbert Humpedrinck’s exquisitely frothy & vacuous waltz is a joy"sv, // fixed

  "Six big juicy steaks sizzled in a pan as five workmen left the quarry"sv, // (56)
  "The soprano took Mozart’s joyful quavers with grace and exuberance"sv, // (56)
  "We quickly seized the black axle and just saved it from going past him"sv, // (57)
  "If Grieg or Dvorak, for example, wrote jazz, it would be quaint and cheesy"sv, // (58)
  "While Suez sailors wax parquet decks, Afghan Jews vomit jauntily abaft"sv, // (59)
  "We promptly judged antique ivory buckles for the next prize"sv, // (59)
  "Venerable Will played jazz sax ‘til 3 o’clock in the morning before he quit"sv, // (60)
  "The querulous snoozing taxi driver jumped crossly, woken by the foghorn"sv, // (60)
  "The public was amazed to view the quickness and dexterity of the juggler"sv, // (60)
  "The July sun caused a fragment of black pine wax to ooze on the velvet quilt"sv, // (61)
  "The explorer was frozen in his big kayak just after making queer discoveries"sv, // (64)
  "Six javelins thrown by the quick savages whizzed forty paces beyond the mark"sv, // (64)
  "As we explored the gulf in Zanzibar, we quickly moved closer to the jutting rocks"sv, // (66)
  "Traveling beneath the azure sky in our jolly ox-cart, we often hit bumps quite hard"sv, // (68)
  "For civilization, Marxist thought just must be quickly replaced by ways of freedom"sv, // (69)
  "Ebenezer unexpectedly bagged two tranquil aardvarks with his jiffy vacuum cleaner"sv, // (71)
  "William said that everything about his jacket was in quite good condition except for the zipper"sv, // (80)
  "A foxy, quick, clever cat in Switzerland was hit by a fancy sports job with bumpy seats and a grumpy driver"sv, // (85)
  "Jelly-like above the high wire, six quaking pachyderms kept the climax of the extravaganza in a dazzling state of flux"sv, // (96)
  "No kidding -- Lorenzo called off his trip to visit Mexico City just because they told him the conquistadores were extinct"sv, // (99)
  "Forsaking monastic tradition, twelve jovial friars gave up their vocation for a questionable existence on the flying trapeze"sv, // (106)
  "\n"sv,

  "Cwm fjord bank glyphs vext quiz"sv, // Amazingly, this 26-word-long sentence uses every letter only once,
                                       // though it uses some pretty archaic words; translates to
                                       // “Carved symbols in a mountain hollow on the
                                       // bank of an inlet irritated an eccentric person.”
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -   List of pangrams
   *
   * -   Perfect pangrams in English (26 letters)
   * Without abbreviations, acronyms, contractions, initialisms, isolated letters,
   * proper nouns, Roman numerals
   *
   * @see: https://clagnut.com/blog/2380
   */
  "Cwm fjord veg balks nth pyx quiz"sv, // (Relaxing in basins at the end of inlets terminates the endless tests from the box.)
  "Cwm fjord bank glyphs vext quiz"sv, // (Carved symbols in a mountain hollow on the bank of an inlet irritated an eccentric person.)[1]
  "Jink cwm, zag veldt, fob qursh pyx"sv, // (Cross valley and plain to steal coins from Saudi mint. – created by Stephen Wagner)
  "Junky qoph-flags vext crwd zimb"sv, // (An Abyssinian fly playing a Celtic violin was annoyed by trashy flags on which were the Hebrew letter qoph.)
  "Squdgy fez, blank jimp crwth vox"sv, // (A short brimless felt hat barely blocks out the sound of a Celtic violin. – created by Claude Shannon)
  "Veldt jynx grimps waqf zho buck"sv, // (A grass-plains wryneck climbs upon a male yak-cattle hybrid that was donated under Islamic law.)
  "Bortz waqf glyphs vex muck djin"sv, // (Signage indicating endowments for industrial diamonds annoy filth-spreading genies. – created by Ed Spargo)
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Danish
   */
  "Danish.                   qwertyuiop asdfghjkl zxcvbnm"sv,
  "Høj bly gom vandt fræk sexquiz på wc"sv, // (Each letter exactly once) Tall shy groom won dirty sex quiz on W.C.
  "Quizdeltagerne spiste jordbær med fløde, mens cirkusklovnen Walther spillede på xylofon"sv, // The quiz contestants ate strawberry with cream while Walter the circus clown played the xylophone.
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  French
   */
  "French.                   qwertyuiop asdfghjkl zxcvbnm"sv,
  "Buvez de ce whisky que le patron juge fameux"sv, // (36) Drink some of this whisky which the boss finds excellent.
  "Portez ce vieux whisky au juge blond qui fume"sv, // Take this old whisky to the blond smoking judge
  "Portez ce vieux whisky au juge blond qui a fumé"sv, // (variant with “é”) Take this old whisky to the blond judge who has smoked.
  "Bâchez la queue du wagon-taxi avec les pyjamas du fakir"sv, // Tarpaulin up the taxi-railcar tail with the fakir’s pajamas
  "Voyez le brick géant que j’examine près du wharf"sv, // See the giant brig which I examine near the wharf
  "Voix ambiguë d’un cœur qui au zéphyr préfère les jattes de kiwi"sv, // Ambiguous voice of a heart which prefers kiwi bowls to a zephyr
  "Monsieur Jack, vous dactylographiez bien mieux que votre ami Wolf"sv, // Mister Jack, you typed much better than your friend Wolf [was used in the Swiss army to check the keyboard of typewriters before teletransmission]
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  German
   */
  "German                    qwertyuiop asdfghjkl zxcvbnm"sv,
  "Sylvia wagt quick den Jux bei Pforzheim"sv, // (no umlauts or ß): Sylvia dares quickly the joke near Pforzheim
  "Franz jagt im komplett verwahrlosten Taxi quer durch Bayern"sv, // (no umlauts or ß): Franz chases in the completely shabby cab straight through Bavaria
  "Victor jagt zwölf Boxkämpfer quer über den großen Sylter Deich"sv, // (with umlauts and ß): Victor chases twelve boxers across the great dam of Sylt
  "“Fix, Schwyz!” quäkt Jürgen blöd vom Paß"sv, // (with umlauts and ß, each letter exactly once, according to the pre-1996 spelling rules): “Quick, Schwyz!” Jürgen squawks zanily from the pass
  "Falsches Üben von Xylophonmusik quält jeden größeren Zwerg"sv, // (used by KDE) - Wrong practising of xylophone music bothers every larger dwarf
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Irish
   */
  "Irish                     qwertyuiop asdfghjkl zxcvbnm"sv,
  "D’fhuascail Íosa Úrmhac na hÓighe Beannaithe pór Éava agus Ádhaimh"sv,
  "D’ḟuascail Íosa Úrṁac na hÓiġe Beannaiṫe pór Éaḃa agus Áḋaiṁ"sv, // Jesus, Son of the blessed Virgin, redeemed the seed of Eve and Adam.
  "Ċuaiġ bé ṁórṡáċ le dlúṫspád fíorḟinn trí hata mo ḋea-ṗorcáin ḃig"sv, // A greatly satisfied woman went with a truly white dense spade through the hat of my good little well-fattened pig (uses both regular and lenited (with dot above) letters)
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Scottish Gaelic
   */
  "Scottish Gaelic           qwertyuiop asdfghjkl zxcvbnm"sv,
  "Mus d’fhàg Cèit-Ùna ròp Ì le ob"sv, // Before Kate-Una left the Iona cattle auction with hops.
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Welsh
   */
  "Welsh                    qwertyuiop asdfghjkl zxcvbnm"sv,
  "Parciais fy jac codi baw hud llawn dŵr ger tŷ Mabon"sv, // I parked my magic JCB [digger] full of water near Mabon’s house
  "\n"sv,
  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  // extra bits ...
  "ab-cd-"sv  // note: continued strings. do not insert commas!
  "ef-gh-"sv
  "ij-kl-"sv
  "mn-op-"sv
  "qr-st-"sv
  "uv-wx-"sv
  "yz"sv,

  "012345678901234567890123456789"sv, // no alphabetics at all!
  ""sv, // empty string

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  // Utter bollox from FaceBook:
  "This sentence contains all the letters of the alphabet except one, "sv
  "find the letter if you are smart."sv,
  "Below it is the sentence: "sv,
  "The quick brown fox jumps over a lazy dog"sv,
  "\n"sv,
};

/**
 *  Function prototypes
 */
inline
bool isPangram(std::string_view const & ps, std::string & missing);
inline
void perform_pangram();

} // end of namespace pang

/**
 *  Program main entry point
 */
int main([[maybe_unused]] int const argc, [[maybe_unused]] char const * const argv[]) {
  int RC { 0 };
  std::print("Program         : {0}\n"
             "Version [V.R.M] : {1:02}.{2:02}.{3:02}\n\n",
             pang::vi.pgm,
             pang::vi.ver,
             pang::vi.rel,
             pang::vi.mod);

  std::print("<<< Begin Run. >>>\n");

  pang::perform_pangram();

  std::print("<<< End Run. >>>\n");

  return RC;
}

namespace pang {

/*
 *  Function to perform the work
 */
inline
void perform_pangram() {

// control how 'missing' is allocated via a compiler macro. default is 'auto'
#ifdef AS_USE_EXPLICIT
  std::string missing;  // explicitly defined as a std::string
#else
  auto missing = ""s;   // auto defined as a std::string via the ""s suffix
#endif

  // loop through the sample data checking each entry for pangrams
  std::for_each(pangrams.cbegin(), pangrams.cend(), [&missing](auto const & pg) {
    if (pg[0] == '\n') {
      std::print("\n"); // 1st char is newline, print and skip
    }
    else {
      auto is_pangram = isPangram(pg, missing); //  call the pangram function

      // report
      std::print("{0:>8} : «{1}»\n", is_pangram, pg);
      if (!is_pangram) {
        if (pg.length() < LETTER_ARRAY_SZ) {
          std::print("{0:>8} : {1}\n", "error", "string too short");
        }
        else {
          std::print("{0:>8} : «{1}»\n", "missing", missing);
        }
      }
    }
  });

  return;
}

/**
 *  Function to determine if the input string is a pangram
 */
inline
bool isPangram(std::string_view const & ps, std::string & missing) {
  auto is_pangram { true };

  missing.clear();  // make sure the 'missing' string is empty

  if (ps.length() < LETTER_ARRAY_SZ) { // less than 26 letters in the string mean it's not a pangram
    is_pangram = false; // and we're done!
  }
  else {
    // Create a boolean array, of size 26. Distinct letter indices will be set to true
    std::array<bool, LETTER_ARRAY_SZ> present = { false };
    std::uint16_t distinct = 0u; // counter of number of distinct letters

    // loop over the input string_view argument and examine individual letters
    for (auto tc : ps) {
      if (std::isalpha(static_cast<unsigned char>(tc))) { // is the char alphabetic?
        // Convert to lowercase to handle case-insensitivity.
        auto lc = static_cast<char>(std::tolower(static_cast<unsigned char>(tc)));
        // Calculate the index (0-25) for the letter.
        std::size_t idx = lc - 'a';

        // Mark the letter as present if not already marked.
        if (!present[idx]) {
          present[idx] = true;
          distinct++;
        }
      }

      if (distinct >= present.size()) { break; } // we got 26 different letters, quit the for loop
    }

    // set the return value to 'true' if we got 26 different letters (default is 'false')
    is_pangram = (distinct == present.size());  // assign result of the boolean == operation

    //  if it's not a pangram, create the list of missing letters
    if (!is_pangram) {
      //  loop over the letters present array and collect missing letters in the missing string
      for (auto ix = 0u; ix < present.size(); ++ix) {
        if (!present[ix]) {
          auto mc = static_cast<char>(ix + 'a');
          missing += mc;    // append this letter
          missing += " "s;  // append a space
        }
      }

      // remove trailing space
      if (!missing.empty() && missing.back() == ' ') {
        missing.pop_back();
      }
    }
  }

  return is_pangram;
}

} // end of namespace pang
