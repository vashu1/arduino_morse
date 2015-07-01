
#ifdef _ALL_LETERS_
#define _ETAIMN_
#define _O_
#define _S_
#define _R_
#define _H_
#define _D_
#define _L_
#define _U_
#define _C_
#define _F_
#define _W_
#define _Y_
#define _G_
#define _P_
#define _B_
#define _V_
#define _K_
#define _X_
#define _Q_
#define _J_
#define _Z_
#endif

const int VOCABULARY_MAX_WORD_SIZE = 5;

prog_uchar vocabulary2[] PROGMEM="abcdefghijklmnop";

const char PROGMEM vocabulary[]=
#ifdef _ETAIMN_
// a, i, e, m, n, t
"in   " "it   " "at   " "an   " "me   " "am   " "man  " "ten  " "men  " "eat  " "net  " "aim  " "ant  " "inn  " "int  "
"name " "mean " "main " "meet " "time " "team "
"amen " "anna " "ante " "anti " "emit " "item " "main " "mama " "mane " "mate " "meat " "meta " "mime " "mine " "neat " "tame " "teen " "tent " "tint " 
"mania" "anime" "enema" "inane" "titan" 
#endif

#ifdef _O_
//+o ---
"to   " "on   " "no   "
"one  " "toe  "
"note " "moon " "tone " "noon " "atom "
#endif

#ifdef _S_
//+s ...
"is   " "as   " "so   "
"see  " "sit  " "sat  " "son  " "set  " "sea  " "sos  "
"some " "most " "same " "seem " "ease " "soon " "test " "miss " "east " "sent " "nose " "mass " "seat " "moss "
#endif

#ifdef _R_
//+r .-.
"or   " 
"are  " "air  " "ran  " "ear  " "nor  " "art  " "arm  "
"more " "near " "tree " "room " "area " "rain " "star " "rest " "tire " "root " "iron " "rise " "rose " "term " "riot "
#endif

#ifdef _H_
//+h ....
"he   " "oh   "
"has  " "hat  " "her  " "him  " "his  " "hit  " "hot  " "hot  " "she  " "the  "
"hair " "hear " "heat " "here " "home " "shoe " "than " "that " "them " "then " "thin " "this "
#endif

#ifdef _D_
//+d -..
"do   "
"add  " "and  " "dad  " "did  " "die  " "end  " "had  "
"dead " "does " "done " "hand " "head " "idea " "made " "mind " "need " "said " "sand " "seed " "send " "side "
#endif

#ifdef _L_
//+l .-..
"all  " "led  " "let  " "lie  " "lot  " "oil  " "old  " 
"also " "deal " "else " "held " "hill " "hold " "hole " "land " "last " "late " "lead " "less " "line "
"list " "lone " "lost " "mile " "sail " "salt " "sell " "soil " "tail " "tall " "tell " "told " "tool "
#endif

#ifdef _U_
//+u ..-
"us   " "out  " "sun  " "use  "
"hunt " "loud " "must " "noun " "suit " "thus " "unit "
#endif

#ifdef _C_
//+c -.-.
"act  " "can  " "car  " "cat  " "cut  " "ice  "
"call " "came " "card " "care " "case " "cell " "cent " "coat " "cold " "come " 
"cool " "corn " "cost " "each " "inch " "much " "once " "race " "rich " "such "
#endif

#ifdef _F_
//+f ..-.
"if   " "of   "
"far  " "fat  " "fit  " "for  " "fun  " "off  " 
"face " "fact " "fair " "fall " "farm " "fast " "fear " "feed " "feel " "feet " "fell " "felt " "fill " "find " "fine " "fire "
"fish " "flat " "food " "foot " "form " "four " "free " "from " "full " "half " "left " "life " "lift " "safe " "self " "soft "
#endif

#ifdef _W_
//+w .--
"we   "
"cow  " "few  " "how  " "law  " "low  " "new  " "now  " "own  " "row  " "saw  " "two  " "war  " "was  " "who  " "win  "
"down " "draw " "flow " "show " "slow " "snow " "swim " "town " "wait " "wall " "want " 
"warm " "wash " "wear " "well " "went " "were " "west " "what " "when " "wide " "wife " 
"wild " "will " "wind " "wire " "wish " "with " "wood " "word "
#endif

#ifdef _Y_
//y -.--
"my   "
"any  " "aye  " "cry  " "day  " "dry  " "dye  " "eye  " "fly  " "fry  " "icy  " "may  " "ray  " "say  " "shy  " "toy  " "way  " "why  "
"army " "city " "clay " "deny " "duty " "fury " "lady " "stay " "sync " "they " "tidy " "tiny " "tray " "yard " "yawn " "year " "yell " "your "
#endif

#ifdef _G_
//g --.
"go   "
"age  " "ago  " "dog  " "egg  " "fig  " "gas  " "get  " "got  " "gun  " "leg  " "log  "
"edge " "game " "girl " "glad " "gold " "gone " "good " "gray " "grew "
"grow " "high " "huge " "long " "ring " "sign " "sing " "song " "wing "
#endif

#ifdef _P_
////p .--.
"up   " 
"map  " "pay  " "put  " "top  " 
"camp " "copy " "crop " "deep " "drop " "help " "hope " "open " "page " 
"pair " "part " "pass " "past " "path " "plan " "play " "poem " "poor " 
"port " "pose " "post " "pull " "push " "rope " "ship " "shop " "slip " 
"spot " "step " "stop " "trip " "type " 
#endif

#ifdef _B_
//b -...
"be   " "by   " 
"bad  " "bar  " "bat  " "bed  " "big  " "bit  " "boy  " "but  " "buy  " "rub  " 
"able " "baby " "ball " "band " "base " "bear " "beat " "been " "bell " 
"best " "bird " "blow " "blue " "boat " "body " "bone " "born " "both " 
"burn " "busy " "tube " 
#endif

#ifdef _V_
//v ...-
"even " "ever " "five " "gave " "give " "have " "live " "love " 
"move " "over " "save " "vary " "verb " "very " "view " "wave " 
"above" "cover" "drive" "event" "every" "favor" "heavy" 
"leave" "level" "never" "prove" "river" "serve" "seven" 
"slave" "solve" "value" "visit" "voice" "vowel" 
#endif

#ifdef _K_
//k -.-
"ask  " "key  " "sky  " 
"back " "bank " "book " "cook " "dark " "duck " "keep " "kept " 
"kill " "kind " "king " "knew " "know " "lake " "like " "look " 
"make " "mark " "milk " "neck " "pick " "rock " "skin " "take " 
"talk " "took " "walk " "week " "work " 
#endif

#ifdef _X_
//x -..-
"aux  " "axe  " "box  " "ext  " "fax  " "fox  " "max  " "sex  " "six  " "wax  " 
"apex " "axis " "coax " "exam " "exec " "exit " "flak " "lynx " 
"next " "onyx " "pixy " "sexy " "taxi " "text " "unix " "xmas " 
#endif

#ifdef _Q_
//q --.-
"qty  " 
"aqua " "iraq " "quit " 
"equal" "equip" "quark" "queen" "queer" "query" "quest" 
"quick" "quiet" "quilt" "quite" "quota" "quote" "squad" 
"squat" "squaw" "squib" "squid" 
#endif

#ifdef _J_
//j .---
"jap  " "jar  " "jaw  " "jet  " "jew  " "job  " "jog  " "joy  " 
"dojo " "fuji " "jack " "jail " "jane " "java " "jeep " "jerk " 
"jest " "jobs " "jock " "john " "join " "joke " "jolt " "jota " 
"judo " "july " "jump " "junk " "jury " "just " "raja "
#endif

#ifdef _Z_
////z --..
"zag  " "zen  " "zig  " "zip  " "zoo  " 
"buzz " "cozy " "daze " "doze " "gaze " "haze " "jazz " "maze " "nazi " "quiz " "ritz " 
"size " "suez " "tzar " "whiz " "zero " "zeta " "zeus " "zinc " "zone " "zoom " 
"amaze" "aztec" "azure" "bazar" "blitz" "booze" "craze" "crazy" "czech" "dazed" 
"dozed" "dozen" "froze" "fuzed" "fuzzy" "hazel" "klutz" "maize" "mezzo" "nazis" 
"ozone" "pizza" "plaza" "prize" "razor" "seize" "sizes" "unzip" "vizir" "vizor" 
"waltz" "whizz" "woozy" "zebra" "zendo" "zeros" "zombi" "zonal"
#endif
;

const int VOCABULARY_WORD_COUNT = sizeof(vocabulary) / VOCABULARY_MAX_WORD_SIZE;

void getVocabularyWord(int wordNum, char *dest) {
  for(int i = 0 ; i < VOCABULARY_MAX_WORD_SIZE ; i++) {
    dest[i] = pgm_read_byte(vocabulary + wordNum*VOCABULARY_MAX_WORD_SIZE + i);
    if(dest[i] == ' ')
      dest[i] = 0;
  }
  dest[VOCABULARY_MAX_WORD_SIZE] = 0;
};

void getVocabularyWord(char *dest) {
  getVocabularyWord(random(0, VOCABULARY_WORD_COUNT), dest);
};
