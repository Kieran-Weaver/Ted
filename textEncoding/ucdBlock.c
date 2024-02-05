/************************************************************************/
/*									*/
/*  The blocks in the UCD database.					*/
/*									*/
/************************************************************************/

#include "ucdBlock.h"
const UcdBlock UCD_Blocks[] = {
	{
		0x0,
		0x7f,
		/*   128 */ "Basic Latin",
	},
	{
		0x80,
		0xff,
		/*   128 */ "Latin-1 Supplement",
	},
	{
		0x100,
		0x17f,
		/*   128 */ "Latin Extended-A",
	},
	{
		0x180,
		0x24f,
		/*   208 */ "Latin Extended-B",
	},
	{
		0x250,
		0x2af,
		/*    96 */ "IPA Extensions",
	},
	{
		0x2b0,
		0x2ff,
		/*    80 */ "Spacing Modifier Letters",
	},
	{
		0x300,
		0x36f,
		/*   112 */ "Combining Diacritical Marks",
	},
	{
		0x370,
		0x3ff,
		/*   144 */ "Greek and Coptic",
	},
	{
		0x400,
		0x4ff,
		/*   256 */ "Cyrillic",
	},
	{
		0x500,
		0x52f,
		/*    48 */ "Cyrillic Supplement",
	},
	{
		0x530,
		0x58f,
		/*    96 */ "Armenian",
	},
	{
		0x590,
		0x5ff,
		/*   112 */ "Hebrew",
	},
	{
		0x600,
		0x6ff,
		/*   256 */ "Arabic",
	},
	{
		0x700,
		0x74f,
		/*    80 */ "Syriac",
	},
	{
		0x750,
		0x77f,
		/*    48 */ "Arabic Supplement",
	},
	{
		0x780,
		0x7bf,
		/*    64 */ "Thaana",
	},
	{
		0x7c0,
		0x7ff,
		/*    64 */ "NKo",
	},
	{
		0x800,
		0x83f,
		/*    64 */ "Samaritan",
	},
	{
		0x840,
		0x85f,
		/*    32 */ "Mandaic",
	},
	{
		0x8a0,
		0x8ff,
		/*    96 */ "Arabic Extended-A",
	},
	{
		0x900,
		0x97f,
		/*   128 */ "Devanagari",
	},
	{
		0x980,
		0x9ff,
		/*   128 */ "Bengali",
	},
	{
		0xa00,
		0xa7f,
		/*   128 */ "Gurmukhi",
	},
	{
		0xa80,
		0xaff,
		/*   128 */ "Gujarati",
	},
	{
		0xb00,
		0xb7f,
		/*   128 */ "Oriya",
	},
	{
		0xb80,
		0xbff,
		/*   128 */ "Tamil",
	},
	{
		0xc00,
		0xc7f,
		/*   128 */ "Telugu",
	},
	{
		0xc80,
		0xcff,
		/*   128 */ "Kannada",
	},
	{
		0xd00,
		0xd7f,
		/*   128 */ "Malayalam",
	},
	{
		0xd80,
		0xdff,
		/*   128 */ "Sinhala",
	},
	{
		0xe00,
		0xe7f,
		/*   128 */ "Thai",
	},
	{
		0xe80,
		0xeff,
		/*   128 */ "Lao",
	},
	{
		0xf00,
		0xfff,
		/*   256 */ "Tibetan",
	},
	{
		0x1000,
		0x109f,
		/*   160 */ "Myanmar",
	},
	{
		0x10a0,
		0x10ff,
		/*    96 */ "Georgian",
	},
	{
		0x1100,
		0x11ff,
		/*   256 */ "Hangul Jamo",
	},
	{
		0x1200,
		0x137f,
		/*   384 */ "Ethiopic",
	},
	{
		0x1380,
		0x139f,
		/*    32 */ "Ethiopic Supplement",
	},
	{
		0x13a0,
		0x13ff,
		/*    96 */ "Cherokee",
	},
	{
		0x1400,
		0x167f,
		/*   640 */ "Unified Canadian Aboriginal Syllabics",
	},
	{
		0x1680,
		0x169f,
		/*    32 */ "Ogham",
	},
	{
		0x16a0,
		0x16ff,
		/*    96 */ "Runic",
	},
	{
		0x1700,
		0x171f,
		/*    32 */ "Tagalog",
	},
	{
		0x1720,
		0x173f,
		/*    32 */ "Hanunoo",
	},
	{
		0x1740,
		0x175f,
		/*    32 */ "Buhid",
	},
	{
		0x1760,
		0x177f,
		/*    32 */ "Tagbanwa",
	},
	{
		0x1780,
		0x17ff,
		/*   128 */ "Khmer",
	},
	{
		0x1800,
		0x18af,
		/*   176 */ "Mongolian",
	},
	{
		0x18b0,
		0x18ff,
		/*    80 */ "Unified Canadian Aboriginal Syllabics Extended",
	},
	{
		0x1900,
		0x194f,
		/*    80 */ "Limbu",
	},
	{
		0x1950,
		0x197f,
		/*    48 */ "Tai Le",
	},
	{
		0x1980,
		0x19df,
		/*    96 */ "New Tai Lue",
	},
	{
		0x19e0,
		0x19ff,
		/*    32 */ "Khmer Symbols",
	},
	{
		0x1a00,
		0x1a1f,
		/*    32 */ "Buginese",
	},
	{
		0x1a20,
		0x1aaf,
		/*   144 */ "Tai Tham",
	},
	{
		0x1b00,
		0x1b7f,
		/*   128 */ "Balinese",
	},
	{
		0x1b80,
		0x1bbf,
		/*    64 */ "Sundanese",
	},
	{
		0x1bc0,
		0x1bff,
		/*    64 */ "Batak",
	},
	{
		0x1c00,
		0x1c4f,
		/*    80 */ "Lepcha",
	},
	{
		0x1c50,
		0x1c7f,
		/*    48 */ "Ol Chiki",
	},
	{
		0x1cc0,
		0x1ccf,
		/*    16 */ "Sundanese Supplement",
	},
	{
		0x1cd0,
		0x1cff,
		/*    48 */ "Vedic Extensions",
	},
	{
		0x1d00,
		0x1d7f,
		/*   128 */ "Phonetic Extensions",
	},
	{
		0x1d80,
		0x1dbf,
		/*    64 */ "Phonetic Extensions Supplement",
	},
	{
		0x1dc0,
		0x1dff,
		/*    64 */ "Combining Diacritical Marks Supplement",
	},
	{
		0x1e00,
		0x1eff,
		/*   256 */ "Latin Extended Additional",
	},
	{
		0x1f00,
		0x1fff,
		/*   256 */ "Greek Extended",
	},
	{
		0x2000,
		0x206f,
		/*   112 */ "General Punctuation",
	},
	{
		0x2070,
		0x209f,
		/*    48 */ "Superscripts and Subscripts",
	},
	{
		0x20a0,
		0x20cf,
		/*    48 */ "Currency Symbols",
	},
	{
		0x20d0,
		0x20ff,
		/*    48 */ "Combining Diacritical Marks for Symbols",
	},
	{
		0x2100,
		0x214f,
		/*    80 */ "Letterlike Symbols",
	},
	{
		0x2150,
		0x218f,
		/*    64 */ "Number Forms",
	},
	{
		0x2190,
		0x21ff,
		/*   112 */ "Arrows",
	},
	{
		0x2200,
		0x22ff,
		/*   256 */ "Mathematical Operators",
	},
	{
		0x2300,
		0x23ff,
		/*   256 */ "Miscellaneous Technical",
	},
	{
		0x2400,
		0x243f,
		/*    64 */ "Control Pictures",
	},
	{
		0x2440,
		0x245f,
		/*    32 */ "Optical Character Recognition",
	},
	{
		0x2460,
		0x24ff,
		/*   160 */ "Enclosed Alphanumerics",
	},
	{
		0x2500,
		0x257f,
		/*   128 */ "Box Drawing",
	},
	{
		0x2580,
		0x259f,
		/*    32 */ "Block Elements",
	},
	{
		0x25a0,
		0x25ff,
		/*    96 */ "Geometric Shapes",
	},
	{
		0x2600,
		0x26ff,
		/*   256 */ "Miscellaneous Symbols",
	},
	{
		0x2700,
		0x27bf,
		/*   192 */ "Dingbats",
	},
	{
		0x27c0,
		0x27ef,
		/*    48 */ "Miscellaneous Mathematical Symbols-A",
	},
	{
		0x27f0,
		0x27ff,
		/*    16 */ "Supplemental Arrows-A",
	},
	{
		0x2800,
		0x28ff,
		/*   256 */ "Braille Patterns",
	},
	{
		0x2900,
		0x297f,
		/*   128 */ "Supplemental Arrows-B",
	},
	{
		0x2980,
		0x29ff,
		/*   128 */ "Miscellaneous Mathematical Symbols-B",
	},
	{
		0x2a00,
		0x2aff,
		/*   256 */ "Supplemental Mathematical Operators",
	},
	{
		0x2b00,
		0x2bff,
		/*   256 */ "Miscellaneous Symbols and Arrows",
	},
	{
		0x2c00,
		0x2c5f,
		/*    96 */ "Glagolitic",
	},
	{
		0x2c60,
		0x2c7f,
		/*    32 */ "Latin Extended-C",
	},
	{
		0x2c80,
		0x2cff,
		/*   128 */ "Coptic",
	},
	{
		0x2d00,
		0x2d2f,
		/*    48 */ "Georgian Supplement",
	},
	{
		0x2d30,
		0x2d7f,
		/*    80 */ "Tifinagh",
	},
	{
		0x2d80,
		0x2ddf,
		/*    96 */ "Ethiopic Extended",
	},
	{
		0x2de0,
		0x2dff,
		/*    32 */ "Cyrillic Extended-A",
	},
	{
		0x2e00,
		0x2e7f,
		/*   128 */ "Supplemental Punctuation",
	},
	{
		0x2e80,
		0x2eff,
		/*   128 */ "CJK Radicals Supplement",
	},
	{
		0x2f00,
		0x2fdf,
		/*   224 */ "Kangxi Radicals",
	},
	{
		0x2ff0,
		0x2fff,
		/*    16 */ "Ideographic Description Characters",
	},
	{
		0x3000,
		0x303f,
		/*    64 */ "CJK Symbols and Punctuation",
	},
	{
		0x3040,
		0x309f,
		/*    96 */ "Hiragana",
	},
	{
		0x30a0,
		0x30ff,
		/*    96 */ "Katakana",
	},
	{
		0x3100,
		0x312f,
		/*    48 */ "Bopomofo",
	},
	{
		0x3130,
		0x318f,
		/*    96 */ "Hangul Compatibility Jamo",
	},
	{
		0x3190,
		0x319f,
		/*    16 */ "Kanbun",
	},
	{
		0x31a0,
		0x31bf,
		/*    32 */ "Bopomofo Extended",
	},
	{
		0x31c0,
		0x31ef,
		/*    48 */ "CJK Strokes",
	},
	{
		0x31f0,
		0x31ff,
		/*    16 */ "Katakana Phonetic Extensions",
	},
	{
		0x3200,
		0x32ff,
		/*   256 */ "Enclosed CJK Letters and Months",
	},
	{
		0x3300,
		0x33ff,
		/*   256 */ "CJK Compatibility",
	},
	{
		0x3400,
		0x4dbf,
		/*  6592 */ "CJK Unified Ideographs Extension A",
	},
	{
		0x4dc0,
		0x4dff,
		/*    64 */ "Yijing Hexagram Symbols",
	},
	{
		0x4e00,
		0x9fff,
		/* 20992 */ "CJK Unified Ideographs",
	},
	{
		0xa000,
		0xa48f,
		/*  1168 */ "Yi Syllables",
	},
	{
		0xa490,
		0xa4cf,
		/*    64 */ "Yi Radicals",
	},
	{
		0xa4d0,
		0xa4ff,
		/*    48 */ "Lisu",
	},
	{
		0xa500,
		0xa63f,
		/*   320 */ "Vai",
	},
	{
		0xa640,
		0xa69f,
		/*    96 */ "Cyrillic Extended-B",
	},
	{
		0xa6a0,
		0xa6ff,
		/*    96 */ "Bamum",
	},
	{
		0xa700,
		0xa71f,
		/*    32 */ "Modifier Tone Letters",
	},
	{
		0xa720,
		0xa7ff,
		/*   224 */ "Latin Extended-D",
	},
	{
		0xa800,
		0xa82f,
		/*    48 */ "Syloti Nagri",
	},
	{
		0xa830,
		0xa83f,
		/*    16 */ "Common Indic Number Forms",
	},
	{
		0xa840,
		0xa87f,
		/*    64 */ "Phags-pa",
	},
	{
		0xa880,
		0xa8df,
		/*    96 */ "Saurashtra",
	},
	{
		0xa8e0,
		0xa8ff,
		/*    32 */ "Devanagari Extended",
	},
	{
		0xa900,
		0xa92f,
		/*    48 */ "Kayah Li",
	},
	{
		0xa930,
		0xa95f,
		/*    48 */ "Rejang",
	},
	{
		0xa960,
		0xa97f,
		/*    32 */ "Hangul Jamo Extended-A",
	},
	{
		0xa980,
		0xa9df,
		/*    96 */ "Javanese",
	},
	{
		0xaa00,
		0xaa5f,
		/*    96 */ "Cham",
	},
	{
		0xaa60,
		0xaa7f,
		/*    32 */ "Myanmar Extended-A",
	},
	{
		0xaa80,
		0xaadf,
		/*    96 */ "Tai Viet",
	},
	{
		0xaae0,
		0xaaff,
		/*    32 */ "Meetei Mayek Extensions",
	},
	{
		0xab00,
		0xab2f,
		/*    48 */ "Ethiopic Extended-A",
	},
	{
		0xabc0,
		0xabff,
		/*    64 */ "Meetei Mayek",
	},
	{
		0xac00,
		0xd7af,
		/* 11184 */ "Hangul Syllables",
	},
	{
		0xd7b0,
		0xd7ff,
		/*    80 */ "Hangul Jamo Extended-B",
	},
	{
		0xd800,
		0xdb7f,
		/*   896 */ "High Surrogates",
	},
	{
		0xdb80,
		0xdbff,
		/*   128 */ "High Private Use Surrogates",
	},
	{
		0xdc00,
		0xdfff,
		/*  1024 */ "Low Surrogates",
	},
	{
		0xe000,
		0xf8ff,
		/*  6400 */ "Private Use Area",
	},
	{
		0xf900,
		0xfaff,
		/*   512 */ "CJK Compatibility Ideographs",
	},
	{
		0xfb00,
		0xfb4f,
		/*    80 */ "Alphabetic Presentation Forms",
	},
	{
		0xfb50,
		0xfdff,
		/*   688 */ "Arabic Presentation Forms-A",
	},
	{
		0xfe00,
		0xfe0f,
		/*    16 */ "Variation Selectors",
	},
	{
		0xfe10,
		0xfe1f,
		/*    16 */ "Vertical Forms",
	},
	{
		0xfe20,
		0xfe2f,
		/*    16 */ "Combining Half Marks",
	},
	{
		0xfe30,
		0xfe4f,
		/*    32 */ "CJK Compatibility Forms",
	},
	{
		0xfe50,
		0xfe6f,
		/*    32 */ "Small Form Variants",
	},
	{
		0xfe70,
		0xfeff,
		/*   144 */ "Arabic Presentation Forms-B",
	},
	{
		0xff00,
		0xffef,
		/*   240 */ "Halfwidth and Fullwidth Forms",
	},
	{
		0xfff0,
		0xffff,
		/*    16 */ "Specials",
	},
	{
		0x10000,
		0x1007f,
		/*   128 */ "Linear B Syllabary",
	},
	{
		0x10080,
		0x100ff,
		/*   128 */ "Linear B Ideograms",
	},
	{
		0x10100,
		0x1013f,
		/*    64 */ "Aegean Numbers",
	},
	{
		0x10140,
		0x1018f,
		/*    80 */ "Ancient Greek Numbers",
	},
	{
		0x10190,
		0x101cf,
		/*    64 */ "Ancient Symbols",
	},
	{
		0x101d0,
		0x101ff,
		/*    48 */ "Phaistos Disc",
	},
	{
		0x10280,
		0x1029f,
		/*    32 */ "Lycian",
	},
	{
		0x102a0,
		0x102df,
		/*    64 */ "Carian",
	},
	{
		0x10300,
		0x1032f,
		/*    48 */ "Old Italic",
	},
	{
		0x10330,
		0x1034f,
		/*    32 */ "Gothic",
	},
	{
		0x10380,
		0x1039f,
		/*    32 */ "Ugaritic",
	},
	{
		0x103a0,
		0x103df,
		/*    64 */ "Old Persian",
	},
	{
		0x10400,
		0x1044f,
		/*    80 */ "Deseret",
	},
	{
		0x10450,
		0x1047f,
		/*    48 */ "Shavian",
	},
	{
		0x10480,
		0x104af,
		/*    48 */ "Osmanya",
	},
	{
		0x10800,
		0x1083f,
		/*    64 */ "Cypriot Syllabary",
	},
	{
		0x10840,
		0x1085f,
		/*    32 */ "Imperial Aramaic",
	},
	{
		0x10900,
		0x1091f,
		/*    32 */ "Phoenician",
	},
	{
		0x10920,
		0x1093f,
		/*    32 */ "Lydian",
	},
	{
		0x10980,
		0x1099f,
		/*    32 */ "Meroitic Hieroglyphs",
	},
	{
		0x109a0,
		0x109ff,
		/*    96 */ "Meroitic Cursive",
	},
	{
		0x10a00,
		0x10a5f,
		/*    96 */ "Kharoshthi",
	},
	{
		0x10a60,
		0x10a7f,
		/*    32 */ "Old South Arabian",
	},
	{
		0x10b00,
		0x10b3f,
		/*    64 */ "Avestan",
	},
	{
		0x10b40,
		0x10b5f,
		/*    32 */ "Inscriptional Parthian",
	},
	{
		0x10b60,
		0x10b7f,
		/*    32 */ "Inscriptional Pahlavi",
	},
	{
		0x10c00,
		0x10c4f,
		/*    80 */ "Old Turkic",
	},
	{
		0x10e60,
		0x10e7f,
		/*    32 */ "Rumi Numeral Symbols",
	},
	{
		0x11000,
		0x1107f,
		/*   128 */ "Brahmi",
	},
	{
		0x11080,
		0x110cf,
		/*    80 */ "Kaithi",
	},
	{
		0x110d0,
		0x110ff,
		/*    48 */ "Sora Sompeng",
	},
	{
		0x11100,
		0x1114f,
		/*    80 */ "Chakma",
	},
	{
		0x11180,
		0x111df,
		/*    96 */ "Sharada",
	},
	{
		0x11680,
		0x116cf,
		/*    80 */ "Takri",
	},
	{
		0x12000,
		0x123ff,
		/*  1024 */ "Cuneiform",
	},
	{
		0x12400,
		0x1247f,
		/*   128 */ "Cuneiform Numbers and Punctuation",
	},
	{
		0x13000,
		0x1342f,
		/*  1072 */ "Egyptian Hieroglyphs",
	},
	{
		0x16800,
		0x16a3f,
		/*   576 */ "Bamum Supplement",
	},
	{
		0x16f00,
		0x16f9f,
		/*   160 */ "Miao",
	},
	{
		0x1b000,
		0x1b0ff,
		/*   256 */ "Kana Supplement",
	},
	{
		0x1d000,
		0x1d0ff,
		/*   256 */ "Byzantine Musical Symbols",
	},
	{
		0x1d100,
		0x1d1ff,
		/*   256 */ "Musical Symbols",
	},
	{
		0x1d200,
		0x1d24f,
		/*    80 */ "Ancient Greek Musical Notation",
	},
	{
		0x1d300,
		0x1d35f,
		/*    96 */ "Tai Xuan Jing Symbols",
	},
	{
		0x1d360,
		0x1d37f,
		/*    32 */ "Counting Rod Numerals",
	},
	{
		0x1d400,
		0x1d7ff,
		/*  1024 */ "Mathematical Alphanumeric Symbols",
	},
	{
		0x1ee00,
		0x1eeff,
		/*   256 */ "Arabic Mathematical Alphabetic Symbols",
	},
	{
		0x1f000,
		0x1f02f,
		/*    48 */ "Mahjong Tiles",
	},
	{
		0x1f030,
		0x1f09f,
		/*   112 */ "Domino Tiles",
	},
	{
		0x1f0a0,
		0x1f0ff,
		/*    96 */ "Playing Cards",
	},
	{
		0x1f100,
		0x1f1ff,
		/*   256 */ "Enclosed Alphanumeric Supplement",
	},
	{
		0x1f200,
		0x1f2ff,
		/*   256 */ "Enclosed Ideographic Supplement",
	},
	{
		0x1f300,
		0x1f5ff,
		/*   768 */ "Miscellaneous Symbols And Pictographs",
	},
	{
		0x1f600,
		0x1f64f,
		/*    80 */ "Emoticons",
	},
	{
		0x1f680,
		0x1f6ff,
		/*   128 */ "Transport And Map Symbols",
	},
	{
		0x1f700,
		0x1f77f,
		/*   128 */ "Alchemical Symbols",
	},
	{
		0x20000,
		0x2a6df,
		/* 42720 */ "CJK Unified Ideographs Extension B",
	},
	{
		0x2a700,
		0x2b73f,
		/*  4160 */ "CJK Unified Ideographs Extension C",
	},
	{
		0x2b740,
		0x2b81f,
		/*   224 */ "CJK Unified Ideographs Extension D",
	},
	{
		0x2f800,
		0x2fa1f,
		/*   544 */ "CJK Compatibility Ideographs Supplement",
	},
	{
		0xe0000,
		0xe007f,
		/*   128 */ "Tags",
	},
	{
		0xe0100,
		0xe01ef,
		/*   240 */ "Variation Selectors Supplement",
	},
	{
		0xf0000,
		0xfffff,
		/* 65536 */ "Supplementary Private Use Area-A",
	},
	{
		0x100000,
		0x10ffff,
		/* 65536 */ "Supplementary Private Use Area-B",
	},
};

const int UCD_BlockCount = sizeof(UCD_Blocks) / sizeof(UcdBlock);

int ucdGetBlock(int sym)
{
	int l = 0, r = UCD_BlockCount, m = (l + r) / 2;

	while (l < m) {
		if (UCD_Blocks[m].ubFirst <= sym) {
			l = m;
		} else {
			r = m;
		}

		m = (l + r) / 2;
	}

	if (sym < UCD_Blocks[m].ubFirst) {
		return m - 1;
	} else {
		return m;
	}
}
