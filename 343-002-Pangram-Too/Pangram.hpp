#pragma once

#include <vector>
#include <string_view>

using namespace std::string_view_literals;  // for ""sv suffix

namespace pang {

/**
 * a vector of sample pangrams
 */
inline
static
std::vector<std::string_view> pangrams {
  "Quick brown fox jumps over the lazy dog"sv,
  "The quick brown fox jumps over the lazy dog"sv,
  "A quick brown fox jumps over the lazy dog"sv,
  "The quick brown fox jumps over a lazy dog"sv,
  "The kuick brown fox jumps over the lazy dog"sv,  // should fail
  "The quick brown fox jumped over the lazy dog"sv, // common error
  "The quick brown fox jumped over the lazy dogs"sv,
  "Thë qüïck bröwñ föx jümps övër ä läzy dög"sv,  // contains accented letters, should fail
//FIXME  "ThÃ« qÃ¼Ã¯ck brÃ¶wÃ± fÃ¶x jÃ¼mps Ã¶vÃ«r Ã¤ lÃ¤zy dÃ¶g"sv,    // contains accented letters, should fail
  "\n"sv,

  /*
   * - A Plethora of Pangrams
   *   Note: A pangram, or holoalphabetic sentence, is a sentence that contains every letter of the alphabet at least once.
   *   Each of the following sentences uses each letter of the alphabet at least once and makes sense (more or less). At the
   *   end of each sentence, the number in parentheses is the total number each took to include all 26 letters. Can you top
   *   the famous first one?
   *
   *   A quick brown fox jumps over the lazy dog OR The quick brown fox jumps over a lazy dog.
   *   At 33 letters, the most famous, BUT make sure one of them id an "a" they cannot both be a "the".
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
  "Pack my box with five dozen liquor jugs"sv, // (32) According to Wikipedia, this one is used on NASA's Space Shuttle.
  "Big Fuji waves pitch enzymed kex liquor"sv, // (33)
  "A quick brown fox jumps over the lazy dog"sv, // (33) >>> added back in
  "The quick brown fox jumps over a lazy dog"sv, // (33) >>> added back in
  "The quick brown fox jumps over the lazy dog"sv, // (35) >>> added back in
#ifdef AS_INCLUDE_KNOWN_ERRORS
  "The quick brown fox jumped over the lazy dog"sv, // (36) common error
#endif
  "The quick brown fox jumped over the lazy dogs"sv, // (37) fixed
  "Fix problem quickly with galvanized jets"sv, // (35)
  "Heavy boxes perform quick waltzes and jigs"sv, // (36)
  "Jinxed wizards pluck ivy from the big quilt"sv, // (36)
  "Watch Jeopardy!, Alex Trebek's fun TV quiz game"sv, // (37)

#ifdef AS_INCLUDE_KNOWN_ERRORS
  "Adjusting quiver and bow, Zompye killed the fox"sv, // (39) oops!
#endif
  "Adjusting quiver and bow, Czompye killed the fox"sv, // fixed

  "Amazingly few discotheques provide jukeboxes"sv, // (40)
  "Cozy lummox gives smart squid who asks for job pen"sv, // (41) More modern Mac tester sentence.

#ifdef AS_INCLUDE_KNOWN_ERRORS
  "The vixen jumped quickly on her foe, barking with zeal"sv, // (44) oops!
#endif
  "The vixen jumped quickly on her foes, barking with zeal"sv, // fixed

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
  "Engelbert Humperinck's exquisitely frothy & vacuous waltz is a joy"sv, // (56) oops!
#endif
  "Engelbert Humperdinck's exquisitely frothy & vacuous waltz is a joy"sv, // fixed

  "Six big juicy steaks sizzled in a pan as five workmen left the quarry"sv, // (56)
  "The soprano took Mozart's joyful quavers with grace and exuberance"sv, // (56)
  "We quickly seized the black axle and just saved it from going past him"sv, // (57)
  "If Grieg or Dvorak, for example, wrote jazz, it would be quaint and cheesy"sv, // (58)
  "While Suez sailors wax parquet decks, Afghan Jews vomit jauntily abaft"sv, // (59)
  "We promptly judged antique ivory buckles for the next prize"sv, // (59)
  "Venerable Will played jazz sax 'til 3 o'clock in the morning before he quit"sv, // (60)
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
                                       // "Carved symbols in a mountain hollow on the
                                       // bank of an inlet irritated an eccentric person."
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
   *
   * -  Engish
   */
  "clagnut.com               qwertyuiop asdfghjkl zxcvbnm"sv,
  "\n"sv,
  "English                   qwertyuiop asdfghjkl zxcvbnm"sv,
  "Cwm fjord veg balks nth pyx quiz"sv, // (Relaxing in basins at the end of inlets terminates the endless tests from the box.)
  "Cwm fjord bank glyphs vext quiz"sv, // (Carved symbols in a mountain hollow on the bank of an inlet irritated an eccentric person.)[1]
  "Jink cwm, zag veldt, fob qursh pyx"sv, // (Cross valley and plain to steal coins from Saudi mint. â created by Stephen Wagner)
  "Junky qoph-flags vext crwd zimb"sv, // (An Abyssinian fly playing a Celtic violin was annoyed by trashy flags on which were the Hebrew letter qoph.)
  "Squdgy fez, blank jimp crwth vox"sv, // (A short brimless felt hat barely blocks out the sound of a Celtic violin. â created by Claude Shannon)
  "Veldt jynx grimps waqf zho buck"sv, // (A grass-plains wryneck climbs upon a male yak-cattle hybrid that was donated under Islamic law.)
  "Bortz waqf glyphs vex muck djin"sv, // (Signage indicating endowments for industrial diamonds annoy filth-spreading genies. â created by Ed Spargo)
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * With abbreviations, acronyms, initialisms or proper nouns, all restricted
   * to dictionary words
   */
  "Jumbling vext frowzy hacks PDQ"sv, // (Being bounced around quickly annoyed the disheveled taxi drivers. â all words in high school dictionary)
  "PR flacks quiz gym: TV DJ box when?"sv, // (Public relations agent asks sports room, when do television disc jockeys fight?)
  "Zing, dwarf jocks vex lymph, Qutb"sv, // (Making a high-pitched sound, short athletes annoy their white blood plasma and an Islamic saint. â created by Peter M. Lella)
  "Zing, vext cwm fly jabs Kurd qoph"sv, // (Making a high-pitched sound, annoyed mountain basin insect sticks Hebrew letter.)
  "Kat veld zubr gif cwm jynx qophs"sv, // (European bison of a shrubby African plain make digital image files of Semitic letters from valley wrynecks. â discovered by Da-Shih Hu)
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * With abbreviations, acronyms, contractions, initialisms, isolated letters,
   * proper nouns, Roman Numerals and not restricted to Dictionary Words
   */
  "A zenith of Xvurj's cwm KL Gybdpq"sv, // AS001 - added 'p'
  "Zombies play crwth, quj FDG xvnk"sv,
  "Blowzy night-frumps vex'd Jack Q"sv,
  "Dwarf mobs quiz lynx.jpg, kvetch!"sv, // (Crowd of midgets question picture of wildcat, then complain.)
  "Frowzy things plumb vex'd Jack Q"sv,
  "G.B. fjords vex quick waltz nymph"sv,
  "Glum Schwartzkopf vexâ'd by NJ IQ"sv,
  "Gym DJ Beck vows phiz tranq flux"sv, // (Beck, the gymnasium DJ, promises a change in facial tranquilizers.)
  "Jerk gawps foxy Qum Blvd. chintz"sv,
  "JFK got my VHS, PC and XLR web quiz"sv,
  "Jocks find quartz glyph, vex BMW"sv,
  "J.Q. Vandz struck my big fox whelp"sv,
  "J.Q. Schwartz flung D.V. Pike my box"sv,
  "Jump dogs, why vex Fritz Blank QC?"sv,
  "Mr. Jock, TV quiz PhD, bags few lynx"sv,
  "New job: fix Mr. Gluck's hazy TV, PDQ!"sv, // (includes 5 punctuation symbols)
  "Quartz glyph job vex'd cwm finks"sv, // (The act of carving symbols into quartz irritated ruffians from a Welsh river valley.)
  "Quartz jock vends BMW glyph fix"sv,
  "The glib czar junks my VW Fox PDQ"sv,
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * Longer pangrams in English (in order of fewest letters used)
   */
  "Nymphs blitz quick vex dwarf jog"sv, // (27 letters)
  "DJs flock by when MTV ax quiz prog"sv, // (27 letters) (2 acronyms, 1 abbreviation and a US spelling)
  "Big fjords vex quick waltz nymph"sv, // (27 letters)
  "Bawds jog, flick quartz, vex nymph"sv, // (27 letters)
  "Waltz job vexed quick frog nymphs"sv, // (28 letters) (new variation on 29 letter version)
  "Junk MTV quiz graced by fox whelps"sv, // (28 letters) (Includes abbreviation)
  "Bawds jog, flick quartz, vex nymphs"sv, // (28 letters)
  "Waltz, bad nymph, for quick jigs vex!"sv, // (28 letters)
  "Waltz, nymph, for quick jigs vex Bud!"sv, // (28 letters) (Includes proper noun)
  "Fox nymphs grab quick-jived waltz"sv, // (28 letters)
  "Brick quiz whangs jumpy veldt fox"sv, // (28 letters)
  "Glib jocks quiz nymph to vex dwarf"sv, // (28 letters)
  "Bright vixens jump; dozy fowl quack"sv, // (29 letters)
  "Vexed nymphs go for quick waltz job"sv, // (29 letters)
  "Quick wafting zephyrs vex bold Jim"sv, // (29 letters) (Includes proper noun)
  "Quick zephyrs blow, vexing daft Jim"sv, // (29 letters) (Includes proper noun)
  "Quick blowing zephyrs vex daft Jim"sv, // (29 letters) (Includes proper noun)
  "Sphinx of black quartz, judge my vow!"sv, // (29 letters) (Used by Adobe InDesign when providing samples of all fonts.)
  "Sex-charged fop blew my junk TV quiz"sv, // (29 letters) (Includes abbreviation)
  "Both fickle dwarves jinx my pig quiz"sv, // (30 letters)
  "Fat hag dwarves quickly zap jinx mob"sv, // (30 letters)
  "Hick dwarves jam blitzing foxy quip"sv, // (30 letters)
  "Fox dwarves chop my talking quiz job"sv, // (30 letters)
  "Public junk dwarves quiz mighty fox"sv, // (30 letters)
  "Jack fox bids ivy-strewn phlegm quiz"sv, // (30 letters) (Includes proper noun)
  "How quickly daft jumping zebras vex"sv, // (30 letters)
  "Two driven jocks help fax my big quiz"sv, // (30 letters)
  "“Now fax quiz Jack!” my brave ghost pled"sv, // (30 letters) (Includes proper noun)
//FIXME  "âNow fax quiz Jack!â my brave ghost pled"sv, // (30 letters) (Includes proper noun)
  "Jack, love my big wad of sphinx quartz!"sv, // (30 letters) (Includes proper noun)
  "Do wafting zephyrs quickly vex Jumbo?"sv, // (31 letters) (Includes proper noun)
  "Go, lazy fat vixen; be shrewd, jump quick"sv, // (31 letters)
  "Fickle jinx bog dwarves spy math quiz"sv, // (31 letters)
  "Big dwarves heckle my top quiz of jinx"sv, // (31 letters)
  "Fickle bog dwarves jinx empathy quiz"sv, // (31 letters)
  "Public junk dwarves hug my quartz fox"sv, // (31 letters)
  "Jumping hay dwarves flock quartz box"sv, // (31 letters)
  "Five jumping wizards hex bolty quick"sv, // (31 letters)
  "Five hexing wizard bots jump quickly"sv, // (31 letters)
  "Quick fox jumps nightly above wizard"sv, // (31 letters)
  "Vamp fox held quartz duck just by wing"sv, // (31 letters)
  "Five quacking zephyrs jolt my wax bed"sv, // (31 letters) (Used by Mac OSX when previewing TrueType fonts.)
  "The five boxing wizards jump quickly"sv, // (31 letters) (Used by XXDiff as sample text)
  "Jackdaws love my big sphinx of quartz"sv, // (31 letters) (Used by Microsoft Windows XP when previewing some non-TrueType/OpenType fonts. It is interesting that the set of digits afterwards omits the numeral 7.)
  "Show mangled quartz flip vibe exactly"sv, // (32 letters)
  "My jocks box, get hard, unzip, quiver, flow"sv, // (32 letters)
  "Kvetching, flummoxed by job, W. zaps Iraq"sv, // (32 letters) (Includes proper nouns)
  "My ex pub quiz crowd gave joyful thanks"sv, // (32 letters)
  "Cozy sphinx waves quart jug of bad milk"sv, // (32 letters)
  "A very bad quack might jinx zippy fowls"sv, // (32 letters) (Contains all 26 letters in lower case)
  "Pack my box with five dozen liquor jugs"sv, // (32 letters) (Used for font samples in the catalog of the Kelsey Press Company, by Beagle Bros and in Space Shuttle; featured in Ella Minnow Pea)
  "Few quips galvanized the mock jury box"sv, // (32 letters)
  "Quick brown fox jumps over the lazy dog"sv, // (32 letters) (Not attested as frequently as the traditional, and better-formed, The quick brown foxâ¦, below)
  "Quilt frenzy jackdaw gave them best pox"sv, // (33 letters)
  "Jumpy halfling dwarves pick quartz box"sv, // (33 letters)
  "Schwarzkopf vexed Iraq big-time in July"sv, // (33 letters) (Includes proper nouns)
  "Vex quest wizard, judge my backflop hand"sv, // (33 letters)
  "The jay, pig, fox, zebra and my wolves quack!"sv, // (33 letters)
  "Blowzy red vixens fight for a quick jump"sv, // (33 letters)
  "Sex prof gives back no quiz with mild joy"sv, // (33 letters) (Includes abbreviation)
  "The quick brown fox jumps over a lazy dog"sv, // (33 letters) (A variant of the better-known, but longer, version with the in place of a, below.)
  "A quick brown fox jumps over the lazy dog"sv, // (33 letters) (This variation contains all 26 letters in lower case)
  "Quest judge wizard bonks foxy chimp love"sv, // (34 letters)
  "Boxers had zap of gay jock love, quit women"sv, // (34 letters, each consonant used only once)
  "Joaquin Phoenix was gazed by MTV for luck"sv, // (34 letters) (Includes proper nouns and abbreviation)
  "JCVD might pique a sleazy boxer with funk"sv, // (34 letters) (Includes abbreviation of proper noun)
  "Quizzical twins proved my hijack-bug fix"sv, // (34 letters)
  "Fix problem quickly with galvanized jets"sv, // (35 letters)
  "The quick brown fox jumps over the lazy dog"sv, // (35 letters) (Used to test typewriters and computer keyboards, and as sample text; famous for its coherency, dating back to 1888. Sometimes erroneously quoted with âjumpedâ, omitting the letter s.)
  "Waxy and quivering, jocks fumble the pizza"sv, // (35 letters)
  "When zombies arrive, quickly fax judge Pat"sv, // (35 letters) (Includes proper noun)
  "Heavy boxes perform quick waltzes and jigs"sv, // (36 letters)
  "A wizard's job is to vex chumps quickly in fog"sv, // (36 letters)
  "Sympathizing would fix Quaker objectives"sv, // (36 letters) (Includes proper noun)
  "Pack my red box with five dozen quality jugs"sv, // (36 letters)
  "BlewJ's computer quiz favored proxy hacking"sv, // (37 letters) (Includes proper noun)
  "Quads of blowzy fjord ignite map vex'd chicks"sv, // (37 letters)
  "Fake bugs put in wax jonquils drive him crazy"sv, // (37 letters)
  "Watch Jeopardy!, Alex Trebek’s fun TV quiz game"sv, // (37 letters) (Includes
//FIXME  "Watch âJeopardy!â, Alex Trebek's fun TV quiz game"sv, // (37 letters) (Includes proper nouns and abbreviation)
  "GQ jock wears vinyl tuxedo for showbiz promo"sv, // (37 letters) (Includes abbreviation)
  "The quick brown fox jumped over the lazy dogs"sv, // (37 letters)
  "Who packed five dozen old quart jugs in my box?"sv, // (37 letters)
  "Woven silk pyjamas exchanged for blue quartz"sv, // (38 letters) (Used for font samples by Scribus)
  "Brawny gods just flocked up to quiz and vex him"sv, // (38 letters)
  "Twelve ziggurats quickly jumped a finch box"sv, // (38 letters)
  "Prating jokers quizzically vexed me with fibs"sv, // (39 letters)
  "My faxed joke won a pager in the cable TV quiz show"sv, // (39 letters) (Includes abbreviation)
  "The quick onyx goblin jumps over the lazy dwarf"sv, // (39 letters) (From flavor text in a card in the Magic: the Gathering card game[3])
  "The lazy major was fixing Cupid's broken quiver"sv, // (39 letters) (Includes proper noun)
  "Amazingly few discotheques provide jukeboxes"sv, // (40 letters) (only 5 words â fewer than all others in this list)
  "Jacky can now give six big tips from the old quiz"sv, // (40 letters)
  "Lovak won the squad prize cup for sixty big jumps"sv, // (40 letters)
  "J. Fox made five quick plays to win the big prize"sv, // (40 letters)
  "Foxy diva Jennifer Lopez wasn't baking my quiche"sv, // (41 letters) (Includes proper noun)
  "Cozy lummox gives smart squid who asks for job pen"sv, // (41 letters) (Used for font samples by the Macintosh, post-System 7, as well as on certain Palm products)
  "By Jove, my quick study of lexicography won a prize"sv, // (41 letters) (Includes proper noun)
  "Levi Lentz packed my bag with six quarts of juice"sv, // (41 letters)
  "Painful zombies quickly watch a jinxed graveyard"sv, // (42 letters)
  "Fax back Jim's Gwyneth Paltrow video quiz"sv, // (42 letters) (Includes proper nouns)
  "As quirky joke, chefs won't pay devil magic zebra tax"sv, // (42 letters)
  "My girl wove six dozen plaid jackets before she quit"sv, // (43 letters)
  "Then a cop quizzed Mick Jagger's ex-wives briefly"sv, // (43 letters) (Includes proper noun)
  "Six big devils from Japan quickly forgot how to waltz"sv, // (44 letters) (Includes proper noun)
  "“Who am taking the ebonics quiz?”, the prof jovially axed"sv, // (44 letters)
//FIXME  "âWho am taking the ebonics quiz?â, the prof jovially axed"sv, // (44 letters)
  "Why shouldn't a quixotic Kazakh vampire jog barefoot?"sv, // (44 letters) (Includes proper noun)
  "Grumpy wizards make a toxic brew for the jovial queen"sv, // (44 letters)
  "Sixty zips were quickly picked from the woven jute bag"sv, // (45 letters)
  "Big July earthquakes confound zany experimental vow"sv, // (45 letters) (Includes proper noun)
  "Foxy parsons quiz and cajole the lovably dim wiki-girl"sv, // (45 letters)
  "Cute, kind, jovial, foxy physique, amazing beauty? Wowser!"sv, // (45 letters)
  "Have a pick: twenty-six letters - no forcing a jumbled quiz!"sv, // (46 letters)
//FIXME  "Have a pick: twenty-six letters â no forcing a jumbled quiz!"sv, // (46 letters)
  "A very big box sailed up then whizzed quickly from Japan"sv, // (46 letters)
  "Battle of Thermopylae: Quick javelin grazed wry Xerxes"sv, // (46 letters) (Includes proper nouns)
  "Jack quietly moved up front and seized the big ball of wax"sv, // (47 letters) (Includes proper noun)
  "Few black taxis drive up major roads on quiet hazy nights"sv, // (47 letters)
  "Just poets wax boldly as kings and queens march over fuzz"sv, // (47 letters)
  "Bored? Craving a pub quiz fix? Why, just come to the Royal Oak!"sv, // (47 letters) (Used to advertise a pub quiz in Bowness-on-Windermere)
  "Quincy Pondexter blocked five jams against the Wizards!"sv, // (47 letters) (Includes proper nouns)
  "Crazy Frederick bought many very exquisite opal jewels"sv, // (48 letters) (Includes proper noun)
  "A quivering Texas zombie fought republic linked jewelry"sv, // (48 letters) (Includes proper noun)
  "Grumpy wizards make toxic brew for the evil queen and jack"sv, // (48 letters) (Used by Google Fonts)
  "The job of waxing linoleum frequently peeves chintzy kids"sv, // (49 letters)
  "Back in June we delivered oxygen equipment of the same size"sv, // (49 letters) (Includes proper noun)
  "Just keep examining every low bid quoted for zinc etchings"sv, // (49 letters) (Used in many type specimen books for letterpress printers)
  "How razorback-jumping frogs can level six piqued gymnasts!"sv, // (49 letters) (Used for font samples by the Macintosh, System 7 era)
  "A quick movement of the enemy will jeopardize six gunboats"sv, // (49 letters)
  "All questions asked by five watched experts amaze the judge"sv, // (49 letters)
  "Bobby Klun awarded Jayme sixth place for her very high quiz"sv, // (50 letters)
  "The wizard quickly jinxed the gnomes before they vaporized"sv, // (50 letters)
  "Zelda might fix the job growth plans very quickly on Monday"sv, // (50 letters)
  "Zack Gappow saved the job requirement list for the six boys"sv, // (50 letters)
  "Jackie will budget for the most expensive zoology equipment"sv, // (51 letters)
  "Quirky spud boys can jam after zapping five worthy Polysixes"sv, // (51 letters) (Includes proper noun)
  "Jim quickly realized that the beautiful gowns are expensive"sv, // (51 letters)
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * A few other expressive pangrams
   * (Thanks to Eyad Al-Samman)
   */
  "A waxy gent chuckled over my fab jazzy quips"sv, // (36 letters) (Contains all 26 letters in lower case)
  "Waxy gents chalked over my fab jazzy quip"sv, // (35 letters) (New variation on 36-letter version)
  "A puny lazy squad jokes of a worthy moving xebec"sv, // (39 letters) (Contains all 26 letters in lower case)
  "Puny lazy squads joke of a worthy moving xebec"sv, // (38 letters) (New variation on 39-letter version)
  "A hot fowl amazed by quacked ravens jinxing a pub"sv, // (40 letters) (Contains all 26 letters in lower case)
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * English phonetic pangrams
   * Pangrams which use all the phonemes, or phones, of English (rather than
   * alphabetic characters):
   */
  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  "With tenure, Suzie'd have all the more leisure for yachting, but her publications are no good"sv, // (for certain US accents and phonological analyses)
  "Shaw, those twelve beige hooks are joined if I patch a young, gooey mouth"sv, // (perfect for certain accents with the cot-caught merger)
  "Are those shy Eurasian footwear, cowboy chaps, or jolly earthmoving headgear?"sv, // (perfect for certain Received Pronunciation accents)
  "The beige hue on the waters of the loch impressed all, including the French queen, " // ~ continued on next line
  "before she heard that symphony again, just as young Arthur wanted"sv, // (a phonetic, not merely phonemic, pangram. It contains both nasals [m] and [É±] (as in âsymphonyâ), the fricatives [x] (as in âlochâ) and [Ã§] (as in âhueâ), and the âdark Lâ [É«] (as in âallâ) â in other words, it contains different allophones.)
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * Other languages
   */

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Danish
   */
  "Danish                    qwertyuiop asdfghjkl zxcvbnm"sv,
  "Høj bly gom vandt fræk sexquiz på wc"sv, // (Each letter exactly once) Tall shy
//FIXME  "HÃ¸j bly gom vandt frÃ¦k sexquiz pÃ¥ wc"sv, // (Each letter exactly once) Tall shy groom won dirty sex quiz on W.C.
  "Tall shy groom won dirty sex quiz on W.C. - [b f j k p v]"sv,
  "Quizdeltagerne spiste jordbær med fløde, mens cirkusklovnen Walther spillede på xylofon"sv, // The quiz contestants ate strawberry with cream while Walter the circus clown played the xylophone.
//FIXME  "Quizdeltagerne spiste jordbÃ¦r med flÃ¸de, mens cirkusklovnen Walther spillede pÃ¥ xylofon"sv, // The quiz contestants ate strawberry with cream while Walter the circus clown played the xylophone.
  "The quiz contestants ate strawberry with cream while Walter the circus clown played the xylophone - [f g j k v]"sv,
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  French
   */
  "French                    qwertyuiop asdfghjkl zxcvbnm"sv,
  "Buvez de ce whisky que le patron juge fameux"sv, // (36) Drink some of this whisky which the boss finds excellent. 
  "Drink some of this whisky which the boss finds excellent - [a g j p q u v z]"sv,
  "Portez ce vieux whisky au juge blond qui fume"sv, // Take this old whisky to the blond smoking judge
  "Take this old whisky to the blond smoking judge - [c f p q r v x z]"sv,
  "Portez ce vieux whisky au juge blond qui a fumé"sv, // (variant with "é") 
//FIXME  "Portez ce vieux whisky au juge blond qui a fumÃ©"sv, // (variant with âÃ©â) 
  "Take this old whisky to the blond judge who has smoked - [c f p q r v x z]"sv,
  "Bâchez la queue du wagon-taxi avec les pyjamas du fakir"sv, // Tarpaulin up the taxi-railcar tail with the fakir's pajamas
//FIXME  "BÃ¢chez la queue du wagon-taxi avec les pyjamas du fakir"sv, // Tarpaulin up the taxi-railcar tail with the fakirâs pajamas
  "Tarpaulin up the taxi-railcar tail with the fakir's pajamas - [b d g o q v y z]"sv,
  "Voyez le brick géant que j’examine près du wharf"sv, // See the giant brig which I examine near the wharf
//FIXME  "Voyez le brick gÃ©ant que 'examine prÃ¨s du wharf"sv, // See the giant brig which I examine near the wharf
  "See the giant brig which I examine near the wharf - [d j k l o p q u v y z]"sv,
  "Voix ambiguë d’un cœur qui au zéphyr préfère les jattes de kiwi"sv, // Ambiguous voice of a heart which prefers kiwi bowls to a zephyr
//FIXME  "Voix ambiguÃ« 'un cÅur qui au zÃ©phyr prÃ©fÃ¨re les jattes de kiwi"sv, // Ambiguous voice of a heart which prefers kiwi bowls to a zephyr
  "Ambiguous voice of a heart which prefers kiwi bowls to a zephyr - [d j n q x]"sv,
  "Monsieur Jack, vous dactylographiez bien mieux que votre ami Wolf"sv, // Mister Jack, you typed much better than your friend Wolf [was used in the Swiss army to check the keyboard of typewriters before teletransmission]
  "Mister Jack, you typed much better than your friend Wolf - [g q v x z]"sv,
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  German
   */
  "German                    qwertyuiop asdfghjkl zxcvbnm"sv,
  "Sylvia wagt quick den Jux bei Pforzheim"sv, // (no umlauts or ß): Sylvia dares quickly the joke near Pforzheim
  "Sylvia dares quickly the joke near Pforzheim - [b g w x]"sv,
  "Franz jagt im komplett verwahrlosten Taxi quer durch Bayern"sv, // (no umlauts or ß): Franz chases in the completely shabby cab straight through Bavaria
  "Franz chases in the completely shabby taxi straight through Bavaria - [d j k q w]"sv,
  "Victor jagt zwölf Boxkämpfer quer über den großen Sylter Deich"sv, // (with umlauts and ß): Victor chases twelve boxers across the great dam of Sylt
//FIXME  "Victor jagt zwÃ¶lf BoxkÃ¤mpfer quer Ã¼ber den groÃen Sylter Deich"sv, // (with umlauts and Ã): Victor chases twelve boxers across the great dam of Sylt
  "Victor chases twelve boxers across the great dam of Sylt - j k n p q u z]"sv,
  "“Fix, Schwyz!” quäkt Jürgen blöd vom Paß"sv, // (with umlauts and ß, each letter exactly once, according to the pre-1996 spelling rules): “Quick, Schwyz!” Jürgen squawks zanily from the pass - [b d v x]
//FIXME  "âFix, Schwyz!â quÃ¤kt JÃ¼rgen blÃ¶d vom PaÃ"sv, // (with umlauts and Ã, each letter exactly once, according to the pre-1996 spelling rules): âQuick, Schwyz!â JÃ¼rgen squawks zanily from the pass
  "“Quick, Schwyz!” Jürgen squawks zanily from the pass - [b d v x]"sv, 
//FIXME  "âQuick, Schwyz!â JÃ¼rgen squawks zanily from the pass - [b d v x]"sv,
  "Falsches Üben von Xylophonmusik quält jeden größeren Zwerg"sv, // (used by KDE) - Wrong practising of xylophone music bothers every larger dwarf
//FIXME  "Falsches Ãben von Xylophonmusik quÃ¤lt jeden grÃ¶Ãeren Zwerg"sv, // (used by KDE) - Wrong practising of xylophone music bothers every larger dwarf
  "Wrong practising of xylophone music bothers every larger dwarf - [j k q z]"sv,
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Icelandic
   */
  "Icelandic                 qwertyuiop asdfghjkl zxcvbnm"sv,
  "Kæmi ný öxi hér, ykist þjófum nú bæði víl og ádrepa"sv,
//FIXME  "KÃ¦mi nÃ½ Ã¶xi hÃ©r, ykist Ã¾jÃ³fum nÃº bÃ¦Ã°i vÃ­l og Ã¡drepa"sv,
  "If a new axe were here, thieves would feel increasing deterrence and punishment - [b j k q y z]"sv,
  "Svo hölt, yxna kýr þegði jú um dóp í fé á bæ"sv, // (each letter exactly once)
//FIXME  "Svo hÃ¶lt, yxna kÃ½r Ã¾egÃ°i jÃº um dÃ³p Ã­ fÃ© Ã¡ bÃ¦"sv, // (each letter exactly once)
  "A cow in heat with such a limp would admittedly keep silent about drugs in sheep on a farm - [j q v x z]"sv,
  "Þú dazt á hnéð í vök og yfir blóm sexý pæju"sv, //(each letter exactly once, with z (obsolete spelling))
//FIXME  "ÃÃº dazt Ã¡ hnÃ©Ã° Ã­ vÃ¶k og yfir blÃ³m sexÃ½ pÃ¦ju"sv, //(each letter exactly once, with z (obsolete spelling))
  "You fell on the knee in a hole in the ice and over a sexy girl's flower - [b j m p q z]"sv,
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Irish
   */
  "Irish                     qwertyuiop asdfghjkl zxcvbnm"sv,
  "D’fhuascail Íosa Úrmhac na hÓighe Beannaithe pór Éava agus Ádhaimh"sv,
//FIXME  "Dâfhuascail Ãosa Ãrmhac na hÃighe Beannaithe pÃ³r Ãava agus Ãdhaimh"sv,
  "D’ḟuascail Íosa Úrṁac na hÓiġe Beannaiṫe pór Éaḃa agus Áḋaiṁ"sv, // Jesus, Son of the blessed Virgin, redeemed the seed of Eve and Adam.
//FIXME  "Dâá¸uascail Ãosa Ãrá¹ac na hÃiÄ¡e Beannaiá¹«e pÃ³r Ãaá¸a agus Ãá¸aiá¹"sv, // Jesus, Son of the blessed Virgin, redeemed the seed of Eve and Adam.
  "Jesus, Son of the blessed Virgin, redeemed the seed of Eve and Adam - [c k p q w x y z]"sv,
  "Ċuaiġ bé ṁórṡáċ le dlúṫspád fíorḟinn trí hata mo ḋea-ṗorcáin ḃig"sv, // A greatly satisfied woman went with a truly white dense spade through the hat of my good little well-fattened pig (uses both regular and lenited (with dot above) letters)
//FIXME  "ÄuaiÄ¡ bÃ© á¹Ã³rá¹¡Ã¡Ä le dlÃºá¹«spÃ¡d fÃ­orá¸inn trÃ­ hata mo á¸ea-á¹orcÃ¡in á¸ig"sv, // A greatly satisfied woman went with a truly white dense spade through the hat of my good little well-fattened pig (uses both regular and lenited (with dot above) letters)
  "A greatly satisfied woman went with a truly white dense spade through the hat of my good little well-fattened pig - [b c j k q v x z]"sv,
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Italian
   *
   * Pangrams in Italian normally omit the foreign letters j, k, w, x, and y.
   */
  "Italian                   qwertyuiop asdfghjkl zxcvbnm"sv,
  "Quel fez sghembo copre davanti"sv,
  "That slanted fez covers the front - [b g i j k m p q u w x y]"sv,
  "Ma la volpe, col suo balzo, ha raggiunto il quieto Fido"sv,
  "But the fox with her leap has reached the still Fido - [g j k m n q v y z]"sv, // [*âFidoâ is a name commonly given to dogs.*]
  "Quel vituperabile xenofobo zelante assaggia il whisky ed esclama: alleluja!"sv,
  "That blameworthy, zealous xenophobe tastes his whisky and exclaims: Alleluja! - [f g q v]"sv,
  "Pranzo d'acqua fa volti sghembi"sv,
  "Lunch of water makes lopsided faces - [b g j q v x y z]"sv,
  "O templi, quarzi, vigne, fidi boschi!"sv,
  "O temples, quartzes, vines, faithful woods! - [b c g j k x y]"sv,
  "Che tempi brevi, zio, quando solfeggi"sv,
  "Such short times, uncle, when you sol-fa - [b d g j k p q v x z]"sv,
  "Qualche notizia pavese mi fa sbadigliare"sv,
  "Some news from Pavia makes me yawn - [b c d g h j l q t u x z]"sv,
  "In quel campo si trovan funghi in abbondanza"sv,
  "In that field, mushrooms are to be found in abundance - [g j k p q v w x y z]"sv,
  "Qualche vago ione tipo zolfo, bromo, sodio"sv,
  "Some vague ions, like sulfur, bromine, sodium - [c h j p q t w x y z]"sv,
  "Berlusconi? Quiz, tv, paghe da fame"sv, // (Umberto Eco)
  "Tv? Quiz, Br, Flm, Dc… Oh, spenga!"sv, // (Umberto Eco, 1979, without foreign
//FIXME  "Tv? Quiz, Br, Flm, Dcâ¦ Oh, spenga!"sv, // (Umberto Eco, 1979, without foreign letters)
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Latin
   */
  "Latin                     qwertyuiop asdfghjkl zxcvbnm"sv,
  // Includes the letters k, y and z, used for words derived from Greek,
  // but not the letters j, v or w, consonants that evolved from the vowels i and u.
  "Sic fugiens, dux, zelotypos, quam Karus haberis"sv,
  "Thus fleeing, O leader, you are regarded with jealousy like Karus - [b c m p q v x z]"sv,

  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Norwegian
   *
   * Since Norwegian orthography does not include c, q, w, x or z, except in
   * foreign borrowings that haven't been naturalised, the possible pangrams
   * including all the 29 letters of the Norwegian alphabet will require using
   * two or more words with a distinctly foreign spelling.
   */
  "Norwegian                 qwertyuiop asdfghjkl zxcvbnm"sv,
  "Vår sære Zulu fra badeøya spilte jo whist og quickstep i min taxi»"sv,
//FIXME  "VÃ¥r sÃ¦re Zulu fra badeÃ¸ya spilte jo whist og quickstep i min taxi"sv,
  "Our strange Zulu from the bathing island actually played whist and quickstep in my taxi - [j v]"sv,
  "Høvdingens kjære squaw får litt pizza i Mexico by"sv,
//FIXME  "HÃ¸vdingens kjÃ¦re squaw fÃ¥r litt pizza i Mexico by"sv,
  "The chief's dear squaw gets a little pizza in Mexico City = [b j k v]"sv,
  "IQ-løs WC-boms uten hørsel skjærer god pizza på xylofon"sv,
//FIXME  "IQ-lÃ¸s WC-boms uten hÃ¸rsel skjÃ¦rer god pizza pÃ¥ xylofon"sv,
  "IQ-less WC-bum without hearing cuts good pizza on xylophone - [f j k v]"sv,
  "Sær golfer med kølle vant sexquiz på wc i hjemby"sv,
//FIXME  "SÃ¦r golfer med kÃ¸lle vant sexquiz pÃ¥ wc i hjemby"sv,
  "Strange golfer with club won sex quiz on W.C. in hometown - [d j k p v y]"sv,
  "Jeg begynte å fortære en sandwich mens jeg kjørte taxi på vei til quiz"sv,
//FIXME  "Jeg begynte Ã¥ fortÃ¦re en sandwich mens jeg kjÃ¸rte taxi pÃ¥ vei til quiz"sv,
  "I started to devour a sandwich while I was riding a taxi on the way to the quiz - [b f j k m p]"sv,
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Scottish Gaelic
   */
  "Scottish Gaelic           qwertyuiop asdfghjkl zxcvbnm"sv,
  "Mus d’fhàg Cèit-Ùna ròp Ì le ob"sv, // Before Kate-Una left the Iona cattle auction with hops.
//FIXME  "Mus d'fhÃ g CÃ¨it-Ãna rÃ²p Ã le ob"sv, // Before Kate-Una left the Iona cattle auction with hops.
  "Before Kate-Una left the Iona cattle auction with hops - [d g j m q v x y z]"sv,
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Spanish
   */
  "Spanish                   qwertyuiop asdfghjkl zxcvbnm"sv,
  "Benjamín pidió una bebida de kiwi y fresa; Noé, sin vergüenza, la más exquisita champaña del menú"sv, // (with all letters and diacritics, single sentence)
//FIXME  "BenjamÃ­n pidiÃ³ una bebida de kiwi y fresa; NoÃ©, sin vergÃ¼enza, la mÃ¡s exquisita champaÃ±a del menÃº"sv, // (with all letters and diacritics, single sentence)
  "Benjamin ordered a kiwi and strawberry beverage; Noah, without shame, the most exquisite champagne on the menu - [f l z]"sv,
  "José compró una vieja zampoña en Perú. Excusándose, Sofía tiró su whisky al desagüe de la banqueta"sv, // (with all letters and diacritics, two sentences) 
//FIXME  "JosÃ© comprÃ³ una vieja zampoÃ±a en PerÃº. ExcusÃ¡ndose, SofÃ­a tirÃ³ su whisky al desagÃ¼e de la banqueta"sv, // (with all letters and diacritics, two sentences)
  "José bought an old panpipe in Peru. Excusing herself, Sofía threw her whiskey on the sink of the sidewalk - [m q v z]"sv,
//FIXME  "JosÃ© bought an old panpipe in Peru. Excusing herself, SofÃ­a threw her whiskey on the sink of the sidewalk - [m q v z]"sv,
  "El veloz murciélago hindú comía feliz cardillo y kiwi. La cigüeña tocaba el saxofón detrás del palenque de paja"sv, // (with all letters and diacritics, two sentences) (Used in Windows as sample text)
//FIXME  "El veloz murciÃ©lago hindÃº comÃ­a feliz cardillo y kiwi. La cigÃ¼eÃ±a tocaba el saxofÃ³n detrÃ¡s del palenque de paja"sv, // (with all letters and diacritics, two sentences) (Used in Windows as sample text)
  "The quick Hindu bat was happily eating golden thistle and kiwi. The stork was playing the saxophone behind the straw arena - [f j m v z]"sv,
  "El pingüino Wenceslao hizo kilómetros bajo exhaustiva lluvia y frío; añoraba a su querido cachorro"sv, // (with ch, ñ, rr and ll)
//FIXME  "El pingÃ¼ino Wenceslao hizo kilÃ³metros bajo exhaustiva lluvia y frÃ­o; aÃ±oraba a su querido cachorro"sv, // (with ch, Ã±, rr and ll)
  "Wenceslao the penguin traveled kilometers under exhaustive rain and cold; he longed for his dear puppy - [b j q z]"sv,
  "La niña, viéndose atrapada en el áspero baúl índigo y sintiendo asfixia, lloró de vergüenza; mientras que la frustrada madre llamaba a su hija diciendo: “¿Dónde estás Waleska?”"sv,
//FIXME  "La niÃ±a, viÃ©ndose atrapada en el Ã¡spero baÃºl Ã­ndigo y sintiendo asfixia, llorÃ³ de vergÃ¼enza; mientras que la frustrada madre llamaba a su hija diciendo: âÂ¿DÃ³nde estÃ¡s Waleska?â"sv,
  "The girl, finding herself trapped inside the rough blue-violet chest and feeling suffocation, cried out of shame; whilst the frustrated mother called her daughter saying: “Where are you Waleska?”"sv,
//FIXME  "The girl, finding herself trapped inside the rough blue-violet chest and feeling suffocation, cried out of shame; whilst the frustrated mother called her daughter saying: âWhere are you Waleska?â - [j q x z]"sv,
  "Jovencillo emponzoñado de whisky: ¡qué figurota exhibe!"sv,
//FIXME  "Jovencillo emponzoÃ±ado de whisky: Â¡quÃ© figurota exhibe!"sv,
  "Whisky-intoxicated youngster – what a figure he’s showing! - [b j l m p q v z]"sv,
//FIXME  "Whisky-intoxicated youngster â what a figure he's showing! - [b j l m p q v z]"sv,
  "se libro explica en su epígrafe las hazañas y aventuras de Don Quijote de la Mancha en Kuwait"sv,
//FIXME  "Ese libro explica en su epÃ­grafe las hazaÃ±as y aventuras de Don Quijote de la Mancha en Kuwait"sv,
  "That book explains in its epigraph the deeds and adventures of Don Quijote de la Mancha in Kuwait - [y z]"sv,
  "Queda gazpacho, fibra, látex, jamón, kiwi y viñas"sv,
//FIXME  "Queda gazpacho, fibra, lÃ¡tex, jamÃ³n, kiwi y viÃ±as"sv,
  "There are still gazpacho, fibre, latex, ham, kiwi and vineyards - [j q u]"sv,
  "Whisky bueno: ¡excitad mi frágil pequeña vejez!"sv,
//FIXME  "Whisky bueno: Â¡excitad mi frÃ¡gil pequeÃ±a vejez!"sv,
  "Good whisky, excite my frail, little old age! - [b j n p q u v z]"sv,
  "Es extraño mojar queso en la cerveza o probar whisky de garrafa"sv,
//FIXME  "Es extraÃ±o mojar queso en la cerveza o probar whisky de garrafa"sv,
  "It is strange to dip cheese in beer or to try a whisky out of a carafe - [j l m q v x z]"sv,
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Swedish
   */
  "Swedish                   qwertyuiop asdfghjkl zxcvbnm"sv,
  "Flygande bäckasiner söka hwila på mjuka tuvor"sv, // (lacks q, x and z, old spelling âhwâ) (Sometimes âstraxâ is added to include X.)
//FIXME  "Flygande bÃ¤ckasiner sÃ¶ka hwila pÃ¥ mjuka tuvor"sv, // (lacks q, x and z, old spelling âhwâ) (Sometimes âstraxâ is added to include X.)
  "Flying snipes seek rest on soft tufts [of grass] = [b c d h j m q v w x z]"sv,
  "Yxskaftbud, ge vår WC-zonmö IQ-hjälp"sv, // (each letter exactly once)
//FIXME  "Yxskaftbud, ge vÃ¥r WC-zonmÃ¶ IQ-hjÃ¤lp"sv, // (each letter exactly once)
  "Axe handle courier, give our WC zone maiden IQ help - [b f j k s t y]"sv,
  "Gud hjälpe Zorns mö qvickt få byxa"sv, // (each letter once, old spelling âqvâ, lacks foreign letter âwâ)
//FIXME  "Gud hjÃ¤lpe Zorns mÃ¶ qvickt fÃ¥ byxa"sv, // (each letter once, old spelling âqvâ, lacks foreign letter âwâ) 
  "God help Zorn's maiden get trousers quickly - [b f j v w x]"sv,
  "Byxfjärmat föl gick på duvshowen"sv, // (lacks q and z, extra f to include common ligatures fö and fj)
//FIXME  "ByxfjÃ¤rmat fÃ¶l gick pÃ¥ duvshowen"sv, // (lacks q and z, extra f to include common ligatures fÃ¶ and fj)
  "Trouser-estranged foal went to the pigeon show - [b c j k m q v x y z]"sv,
  "\n"sv,

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  /*
   * - Clagnut
   * -  Welsh
   */
  "Welsh                     qwertyuiop asdfghjkl zxcvbnm"sv,
  "Parciais fy jac codi baw hud llawn dŵr ger tŷ Mabon"sv, // I parked my magic JCB [digger] full of water near Mabon's house
//FIXME  "Parciais fy jac codi baw hud llawn dÅµr ger tÅ· Mabon"sv, // I parked my magic JCB [digger] full of water near Mabon's house
  "I parked my magic JCB [digger] full of water near Mabon's house - [q v x z]"sv,
  "\n"sv,
  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8

  /*
   * - The Daily Pangram
   * @see https://dailypangram.tumblr.com
   */
  "After writing exactly 2k a-z sentences, I've quit the Daily Pangram job"sv, // (56 letters)
  "\n"sv,
  
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
  "qwertyuiop asdfghjkl zxcvbnm "sv, // TODO: AS000 - weirdness with gcc 15.2.0_ - empty string
  " "sv, // TODO: AS000 - weirdness with gcc 15.2.0_ - empty string
  ""sv, // TODO: AS000 - weirdness with gcc 15.2.0_ - empty string

  //+....1....+....2....+....3....+....4....+....5....+....6....+....7....+....8
  // Utter bollox from FaceBook:
  "This sentence contains all the letters of the alphabet except one, "sv
  "find the letter if you are smart."sv,
  "Below it is the sentence: "sv,
  "The quick brown fox jumps over a lazy dog"sv,
  "\n"sv,
};

} // end of namespace pang

