#include "uniLegacyEncoding.h"
const int uniKoi8RGlyphUnicodes[256] = {
	-1, /*    0				*/
	-1, /*    1				*/
	-1, /*    2				*/
	-1, /*    3				*/
	-1, /*    4				*/
	-1, /*    5				*/
	-1, /*    6				*/
	-1, /*    7				*/
	-1, /*    8				*/
	-1, /*    9				*/
	-1, /*   10				*/
	-1, /*   11				*/
	-1, /*   12				*/
	-1, /*   13				*/
	-1, /*   14				*/
	-1, /*   15				*/
	-1, /*   16				*/
	-1, /*   17				*/
	-1, /*   18				*/
	-1, /*   19				*/
	-1, /*   20				*/
	-1, /*   21				*/
	-1, /*   22				*/
	-1, /*   23				*/
	-1, /*   24				*/
	-1, /*   25				*/
	-1, /*   26				*/
	-1, /*   27				*/
	-1, /*   28				*/
	-1, /*   29				*/
	-1, /*   30				*/
	-1, /*   31				*/
	0x0020, /*   32= 0x20: space		*/
	0x0021, /*   33= 0x21: exclam		*/
	0x0022, /*   34= 0x22: quotedbl		*/
	0x0023, /*   35= 0x23: numbersign	*/
	0x0024, /*   36= 0x24: dollar		*/
	0x0025, /*   37= 0x25: percent		*/
	0x0026, /*   38= 0x26: ampersand	*/
	0x0027, /*   39= 0x27: quotesingle	*/
	0x0028, /*   40= 0x28: parenleft	*/
	0x0029, /*   41= 0x29: parenright	*/
	0x002A, /*   42= 0x2a: asterisk		*/
	0x002B, /*   43= 0x2b: plus		*/
	0x002C, /*   44= 0x2c: comma		*/
	0x002D, /*   45= 0x2d: hyphen		*/
	0x002E, /*   46= 0x2e: period		*/
	0x002F, /*   47= 0x2f: slash		*/
	0x0030, /*   48= 0x30: zero		*/
	0x0031, /*   49= 0x31: one		*/
	0x0032, /*   50= 0x32: two		*/
	0x0033, /*   51= 0x33: three		*/
	0x0034, /*   52= 0x34: four		*/
	0x0035, /*   53= 0x35: five		*/
	0x0036, /*   54= 0x36: six		*/
	0x0037, /*   55= 0x37: seven		*/
	0x0038, /*   56= 0x38: eight		*/
	0x0039, /*   57= 0x39: nine		*/
	0x003A, /*   58= 0x3a: colon		*/
	0x003B, /*   59= 0x3b: semicolon	*/
	0x003C, /*   60= 0x3c: less		*/
	0x003D, /*   61= 0x3d: equal		*/
	0x003E, /*   62= 0x3e: greater		*/
	0x003F, /*   63= 0x3f: question		*/
	0x0040, /*   64= 0x40: at		*/
	0x0041, /*   65= 0x41: A		*/
	0x0042, /*   66= 0x42: B		*/
	0x0043, /*   67= 0x43: C		*/
	0x0044, /*   68= 0x44: D		*/
	0x0045, /*   69= 0x45: E		*/
	0x0046, /*   70= 0x46: F		*/
	0x0047, /*   71= 0x47: G		*/
	0x0048, /*   72= 0x48: H		*/
	0x0049, /*   73= 0x49: I		*/
	0x004A, /*   74= 0x4a: J		*/
	0x004B, /*   75= 0x4b: K		*/
	0x004C, /*   76= 0x4c: L		*/
	0x004D, /*   77= 0x4d: M		*/
	0x004E, /*   78= 0x4e: N		*/
	0x004F, /*   79= 0x4f: O		*/
	0x0050, /*   80= 0x50: P		*/
	0x0051, /*   81= 0x51: Q		*/
	0x0052, /*   82= 0x52: R		*/
	0x0053, /*   83= 0x53: S		*/
	0x0054, /*   84= 0x54: T		*/
	0x0055, /*   85= 0x55: U		*/
	0x0056, /*   86= 0x56: V		*/
	0x0057, /*   87= 0x57: W		*/
	0x0058, /*   88= 0x58: X		*/
	0x0059, /*   89= 0x59: Y		*/
	0x005A, /*   90= 0x5a: Z		*/
	0x005B, /*   91= 0x5b: bracketleft	*/
	0x005C, /*   92= 0x5c: backslash	*/
	0x005D, /*   93= 0x5d: bracketright	*/
	0x005E, /*   94= 0x5e: asciicircum	*/
	0x005F, /*   95= 0x5f: underscore	*/
	0x0060, /*   96= 0x60: grave		*/
	0x0061, /*   97= 0x61: a		*/
	0x0062, /*   98= 0x62: b		*/
	0x0063, /*   99= 0x63: c		*/
	0x0064, /*  100= 0x64: d		*/
	0x0065, /*  101= 0x65: e		*/
	0x0066, /*  102= 0x66: f		*/
	0x0067, /*  103= 0x67: g		*/
	0x0068, /*  104= 0x68: h		*/
	0x0069, /*  105= 0x69: i		*/
	0x006A, /*  106= 0x6a: j		*/
	0x006B, /*  107= 0x6b: k		*/
	0x006C, /*  108= 0x6c: l		*/
	0x006D, /*  109= 0x6d: m		*/
	0x006E, /*  110= 0x6e: n		*/
	0x006F, /*  111= 0x6f: o		*/
	0x0070, /*  112= 0x70: p		*/
	0x0071, /*  113= 0x71: q		*/
	0x0072, /*  114= 0x72: r		*/
	0x0073, /*  115= 0x73: s		*/
	0x0074, /*  116= 0x74: t		*/
	0x0075, /*  117= 0x75: u		*/
	0x0076, /*  118= 0x76: v		*/
	0x0077, /*  119= 0x77: w		*/
	0x0078, /*  120= 0x78: x		*/
	0x0079, /*  121= 0x79: y		*/
	0x007A, /*  122= 0x7a: z		*/
	0x007B, /*  123= 0x7b: braceleft	*/
	0x007C, /*  124= 0x7c: bar		*/
	0x007D, /*  125= 0x7d: braceright	*/
	0x007E, /*  126= 0x7e: asciitilde	*/
	-1, /*  127				*/
#if 0
    0x2500,		/*  128= 0x80: SF100000		*/
    0x2502,		/*  129= 0x81: SF110000		*/
    0x250C,		/*  130= 0x82: SF010000		*/
    0x2510,		/*  131= 0x83: SF030000		*/
    0x2514,		/*  132= 0x84: SF020000		*/
    0x2518,		/*  133= 0x85: SF040000		*/
    0x251C,		/*  134= 0x86: SF080000		*/
    0x2524,		/*  135= 0x87: SF090000		*/
    0x252C,		/*  136= 0x88: SF060000		*/
    0x2534,		/*  137= 0x89: SF070000		*/
    0x253C,		/*  138= 0x8a: SF050000		*/
    0x2580,		/*  139= 0x8b: upblock		*/
    0x2584,		/*  140= 0x8c: dnblock		*/
    0x2588,		/*  141= 0x8d: block		*/
    0x258C,		/*  142= 0x8e: lfblock		*/
    0x2590,		/*  143= 0x8f: rtblock		*/
    0x2591,		/*  144= 0x90: ltshade		*/
    0x2592,		/*  145= 0x91: shade		*/
    0x2593,		/*  146= 0x92: dkshade		*/
    0x2320,		/*  147= 0x93: integraltp	*/
    0x25A0,		/*  148= 0x94: filledbox	*/
    0x2219,		/*  149= 0x95: _0x95		*/
    0x221A,		/*  150= 0x96: radical		*/
    0x2248,		/*  151= 0x97: approxequal	*/
    0x2264,		/*  152= 0x98: lessequal	*/
    0x2265,		/*  153= 0x99: greaterequal	*/
    -1,			/*  154= 0x9a: nobreakspace	*/
    0x2321,		/*  155= 0x9b: integralbt	*/
#else
	-1, /*  128= 0x80: SF100000		*/
	-1, /*  129= 0x81: SF110000		*/
	-1, /*  130= 0x82: SF010000		*/
	-1, /*  131= 0x83: SF030000		*/
	-1, /*  132= 0x84: SF020000		*/
	-1, /*  133= 0x85: SF040000		*/
	-1, /*  134= 0x86: SF080000		*/
	-1, /*  135= 0x87: SF090000		*/
	-1, /*  136= 0x88: SF060000		*/
	-1, /*  137= 0x89: SF070000		*/
	-1, /*  138= 0x8a: SF050000		*/
	-1, /*  139= 0x8b: upblock		*/
	-1, /*  140= 0x8c: dnblock		*/
	-1, /*  141= 0x8d: block		*/
	-1, /*  142= 0x8e: lfblock		*/
	-1, /*  143= 0x8f: rtblock		*/
	-1, /*  144= 0x90: ltshade		*/
	-1, /*  145= 0x91: shade		*/
	-1, /*  146= 0x92: dkshade		*/
	-1, /*  147= 0x93: integraltp	*/
	-1, /*  148= 0x94: filledbox	*/
	-1, /*  149= 0x95: _0x95		*/
	-1, /*  150= 0x96: radical		*/
	-1, /*  151= 0x97: approxequal	*/
	-1, /*  152= 0x98: lessequal	*/
	-1, /*  153= 0x99: greaterequal	*/
	-1, /*  154= 0x9a: nobreakspace	*/
	-1, /*  155= 0x9b: integralbt	*/
#endif
	0x00B0, /*  156= 0x9c: degree		*/
	-1, /*  157= 0x9d: twosuperior	*/
	-1, /*  158= 0x9e: periodcentered	*/
	0x00F7, /*  159= 0x9f: divide		*/
#if 0
    0x2550,		/*  160= 0xa0: SF430000		*/
    0x2551,		/*  161= 0xa1: SF240000		*/
    0x2552,		/*  162= 0xa2: SF510000		*/
#else
	-1, /*  160= 0xa0: SF430000		*/
	-1, /*  161= 0xa1: SF240000		*/
	-1, /*  162= 0xa2: SF510000		*/
#endif
	0x0451, /*  163= 0xa3: afii10071	*/
#if 0
    0x2553,		/*  164= 0xa4: SF520000		*/
    0x2554,		/*  165= 0xa5: SF390000		*/
    0x2555,		/*  166= 0xa6: SF220000		*/
    0x2556,		/*  167= 0xa7: SF210000		*/
    0x2557,		/*  168= 0xa8: SF250000		*/
    0x2558,		/*  169= 0xa9: SF500000		*/
    0x2559,		/*  170= 0xaa: SF490000		*/
    0x255A,		/*  171= 0xab: SF380000		*/
    0x255B,		/*  172= 0xac: SF280000		*/
    0x255C,		/*  173= 0xad: SF270000		*/
    0x255D,		/*  174= 0xae: SF260000		*/
    0x255E,		/*  175= 0xaf: SF360000		*/
    0x255F,		/*  176= 0xb0: SF370000		*/
    0x2560,		/*  177= 0xb1: SF420000		*/
    0x2561,		/*  178= 0xb2: SF190000		*/
#else
	-1, /*  164= 0xa4: SF520000		*/
	-1, /*  165= 0xa5: SF390000		*/
	-1, /*  166= 0xa6: SF220000		*/
	-1, /*  167= 0xa7: SF210000		*/
	-1, /*  168= 0xa8: SF250000		*/
	-1, /*  169= 0xa9: SF500000		*/
	-1, /*  170= 0xaa: SF490000		*/
	-1, /*  171= 0xab: SF380000		*/
	-1, /*  172= 0xac: SF280000		*/
	-1, /*  173= 0xad: SF270000		*/
	-1, /*  174= 0xae: SF260000		*/
	-1, /*  175= 0xaf: SF360000		*/
	-1, /*  176= 0xb0: SF370000		*/
	-1, /*  177= 0xb1: SF420000		*/
	-1, /*  178= 0xb2: SF190000		*/
#endif
	0x0401, /*  179= 0xb3: afii10023	*/
#if 0
    0x2562,		/*  180= 0xb4: SF200000		*/
    0x2563,		/*  181= 0xb5: SF230000		*/
    0x2564,		/*  182= 0xb6: SF470000		*/
    0x2565,		/*  183= 0xb7: SF480000		*/
    0x2566,		/*  184= 0xb8: SF410000		*/
    0x2567,		/*  185= 0xb9: SF450000		*/
    0x2568,		/*  186= 0xba: SF460000		*/
    0x2569,		/*  187= 0xbb: SF400000		*/
    0x256A,		/*  188= 0xbc: SF540000		*/
    0x256B,		/*  189= 0xbd: SF530000		*/
    0x256C,		/*  190= 0xbe: SF440000		*/
#else
	-1, /*  180= 0xb4: SF200000		*/
	-1, /*  181= 0xb5: SF230000		*/
	-1, /*  182= 0xb6: SF470000		*/
	-1, /*  183= 0xb7: SF480000		*/
	-1, /*  184= 0xb8: SF410000		*/
	-1, /*  185= 0xb9: SF450000		*/
	-1, /*  186= 0xba: SF460000		*/
	-1, /*  187= 0xbb: SF400000		*/
	-1, /*  188= 0xbc: SF540000		*/
	-1, /*  189= 0xbd: SF530000		*/
	-1, /*  190= 0xbe: SF440000		*/
#endif
	-1, /*  191= 0xbf: copyright	*/
	0x044E, /*  192= 0xc0: afii10096	*/
	0x0430, /*  193= 0xc1: afii10065	*/
	0x0431, /*  194= 0xc2: afii10066	*/
	0x0446, /*  195= 0xc3: afii10088	*/
	0x0434, /*  196= 0xc4: afii10069	*/
	0x0435, /*  197= 0xc5: afii10070	*/
	0x0444, /*  198= 0xc6: afii10086	*/
	0x0433, /*  199= 0xc7: afii10068	*/
	0x0445, /*  200= 0xc8: afii10087	*/
	0x0438, /*  201= 0xc9: afii10074	*/
	0x0439, /*  202= 0xca: afii10075	*/
	0x043A, /*  203= 0xcb: afii10076	*/
	0x043B, /*  204= 0xcc: afii10077	*/
	0x043C, /*  205= 0xcd: afii10078	*/
	0x043D, /*  206= 0xce: afii10079	*/
	0x043E, /*  207= 0xcf: afii10080	*/
	0x043F, /*  208= 0xd0: afii10081	*/
	0x044F, /*  209= 0xd1: afii10097	*/
	0x0440, /*  210= 0xd2: afii10082	*/
	0x0441, /*  211= 0xd3: afii10083	*/
	0x0442, /*  212= 0xd4: afii10084	*/
	0x0443, /*  213= 0xd5: afii10085	*/
	0x0436, /*  214= 0xd6: afii10072	*/
	0x0432, /*  215= 0xd7: afii10067	*/
	0x044C, /*  216= 0xd8: afii10094	*/
	0x044B, /*  217= 0xd9: afii10093	*/
	0x0437, /*  218= 0xda: afii10073	*/
	0x0448, /*  219= 0xdb: afii10090	*/
	0x044D, /*  220= 0xdc: afii10095	*/
	0x0449, /*  221= 0xdd: afii10091	*/
	0x0447, /*  222= 0xde: afii10089	*/
	0x044A, /*  223= 0xdf: afii10092	*/
	0x042E, /*  224= 0xe0: afii10048	*/
	0x0410, /*  225= 0xe1: afii10017	*/
	0x0411, /*  226= 0xe2: afii10018	*/
	0x0426, /*  227= 0xe3: afii10040	*/
	0x0414, /*  228= 0xe4: afii10021	*/
	0x0415, /*  229= 0xe5: afii10022	*/
	0x0424, /*  230= 0xe6: afii10038	*/
	0x0413, /*  231= 0xe7: afii10020	*/
	0x0425, /*  232= 0xe8: afii10039	*/
	0x0418, /*  233= 0xe9: afii10026	*/
	0x0419, /*  234= 0xea: afii10027	*/
	0x041A, /*  235= 0xeb: afii10028	*/
	0x041B, /*  236= 0xec: afii10029	*/
	0x041C, /*  237= 0xed: afii10030	*/
	0x041D, /*  238= 0xee: afii10031	*/
	0x041E, /*  239= 0xef: afii10032	*/
	0x041F, /*  240= 0xf0: afii10033	*/
	0x042F, /*  241= 0xf1: afii10049	*/
	0x0420, /*  242= 0xf2: afii10034	*/
	0x0421, /*  243= 0xf3: afii10035	*/
	0x0422, /*  244= 0xf4: afii10036	*/
	0x0423, /*  245= 0xf5: afii10037	*/
	0x0416, /*  246= 0xf6: afii10024	*/
	0x0412, /*  247= 0xf7: afii10019	*/
	0x042C, /*  248= 0xf8: afii10046	*/
	0x042B, /*  249= 0xf9: afii10045	*/
	0x0417, /*  250= 0xfa: afii10025	*/
	0x0428, /*  251= 0xfb: afii10042	*/
	0x042D, /*  252= 0xfc: afii10047	*/
	0x0429, /*  253= 0xfd: afii10043	*/
	0x0427, /*  254= 0xfe: afii10041	*/
	0x042A, /*  255= 0xff: afii10044	*/
};
