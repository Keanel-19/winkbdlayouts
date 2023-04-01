//---------------------------------------------------------------------------
// French Apple Keyboard Layout
//---------------------------------------------------------------------------

// European/American "Enhanced 101/102-key" keyboard type. Used in kbd.h.
#define KBD_TYPE 4

#include <windows.h>
#include <kbd.h>
#include <dontuse.h>

#pragma data_seg(".data")


//---------------------------------------------------------------------------
// The table below defines the virtual keys for various keyboard types where
// the keyboard differ from the US keyboard.
//---------------------------------------------------------------------------

// _EQ() : all keyboard types have the same virtual key for this scancode
// _NE() : different virtual keys for this scancode, depending on kbd type
//
//    +------+ +----------+----------+----------+----------+----------+----------+
//    | Scan | |    kbd   |    kbd   |    kbd   |    kbd   |    kbd   |    kbd   |
//    | code | |   type 1 |   type 2 |   type 3 |   type 4 |   type 5 |   type 6 |
//    +------+_+----------+----------+----------+----------+----------+----------+

#undef  T29
#define T29 _EQ(                                      OEM_7                      )
#undef  T0C
#define T0C _EQ(                                      OEM_4                      )
#undef  T0D
#define T0D _EQ(                                  OEM_MINUS                      )
#undef  T10
#define T10 _EQ(                                        'A'                      )
#undef  T11
#define T11 _EQ(                                        'Z'                      )
#undef  T1A
#define T1A _EQ(                                      OEM_6                      )
#undef  T1B
#define T1B _EQ(                                      OEM_1                      )
#undef  T1E
#define T1E _EQ(                                        'Q'                      )
#undef  T27
#define T27 _EQ(                                        'M'                      )
#undef  T28
#define T28 _EQ(                                      OEM_3                      )
#undef  T2B
#define T2B _EQ(                                      OEM_5                      )
#undef  T56
#define T56 _EQ(                                    OEM_102                      )
#undef  T2C
#define T2C _EQ(                                        'W'                      )
#undef  T32
#define T32 _EQ(                                  OEM_COMMA                      )
#undef  T33
#define T33 _EQ(                                 OEM_PERIOD                      )
#undef  T34
#define T34 _EQ(                                      OEM_2                      )
#undef  T35
#define T35 _EQ(                                   OEM_PLUS                      )
#undef  T6A
#define T6A _EQ(                                        '*'                      ) // F19 generates '*' to check the keyboard

//---------------------------------------------------------------------------
// Scan Code to Virtual Key conversion tables
//---------------------------------------------------------------------------

static USHORT ausVK[] = {
    T00, T01, T02, T03, T04, T05, T06, T07,
    T08, T09, T0A, T0B, T0C, T0D, T0E, T0F,
    T10, T11, T12, T13, T14, T15, T16, T17,
    T18, T19, T1A, T1B, T1C, T1D, T1E, T1F,
    T20, T21, T22, T23, T24, T25, T26, T27,
    T28, T29, T2A, T2B, T2C, T2D, T2E, T2F,
    T30, T31, T32, T33, T34, T35,

    // Right-hand Shift key must have KBDEXT bit set.
    T36 | KBDEXT,

    T37 | KBDMULTIVK,   // numpad_* + Shift/Alt -> SnapShot

    T38, T39, T3A, T3B, T3C, T3D, T3E,
    T3F, T40, T41, T42, T43, T44,

    // NumLock Key:
    //     KBDEXT     - VK_NUMLOCK is an Extended key
    //     KBDMULTIVK - VK_NUMLOCK or VK_PAUSE (without or with CTRL)
    T45 | KBDEXT | KBDMULTIVK,

    T46 | KBDMULTIVK,

    // Number Pad keys:
    //     KBDNUMPAD  - digits 0-9 and decimal point.
    //     KBDSPECIAL - require special processing by Windows
    T47 | KBDNUMPAD | KBDSPECIAL,   // Numpad 7 (Home)
    T48 | KBDNUMPAD | KBDSPECIAL,   // Numpad 8 (Up),
    T49 | KBDNUMPAD | KBDSPECIAL,   // Numpad 9 (PgUp),
    T4A,
    T4B | KBDNUMPAD | KBDSPECIAL,   // Numpad 4 (Left),
    T4C | KBDNUMPAD | KBDSPECIAL,   // Numpad 5 (Clear),
    T4D | KBDNUMPAD | KBDSPECIAL,   // Numpad 6 (Right),
    T4E,
    T4F | KBDNUMPAD | KBDSPECIAL,   // Numpad 1 (End),
    T50 | KBDNUMPAD | KBDSPECIAL,   // Numpad 2 (Down),
    T51 | KBDNUMPAD | KBDSPECIAL,   // Numpad 3 (PgDn),
    T52 | KBDNUMPAD | KBDSPECIAL,   // Numpad 0 (Ins),
    T53 | KBDNUMPAD | KBDSPECIAL,   // Numpad . (Del),

    T54, T55, T56, T57, T58, T59, T5A, T5B,
    T5C, T5D, T5E, T5F, T60, T61, T62, T63,
    T64, T65, T66, T67, T68, T69, T6A, T6B,
    T6C, T6D, T6E, T6F, T70, T71, T72, T73,
    T74, T75, T76, T77, T78, T79, T7A, T7B,
    T7C, T7D, T7E
};

static VSC_VK aE0VscToVk[] = {
    {0x10, X10 | KBDEXT              },  // Speedracer: Previous Track
    {0x19, X19 | KBDEXT              },  // Speedracer: Next Track
    {0x1D, X1D | KBDEXT              },  // RControl
    {0x20, X20 | KBDEXT              },  // Speedracer: Volume Mute
    {0x21, X21 | KBDEXT              },  // Speedracer: Launch App 2
    {0x22, X22 | KBDEXT              },  // Speedracer: Media Play/Pause
    {0x24, X24 | KBDEXT              },  // Speedracer: Media Stop
    {0x2E, X2E | KBDEXT              },  // Speedracer: Volume Down
    {0x30, X30 | KBDEXT              },  // Speedracer: Volume Up
    {0x32, X32 | KBDEXT              },  // Speedracer: Browser Home
    {0x35, X35 | KBDEXT              },  // Numpad Divide
    {0x37, X37 | KBDEXT              },  // Snapshot
    {0x38, X38 | KBDEXT              },  // RMenu
    {0x47, X47 | KBDEXT              },  // Home
    {0x48, X48 | KBDEXT              },  // Up
    {0x49, X49 | KBDEXT              },  // Prior
    {0x4B, X4B | KBDEXT              },  // Left
    {0x4D, X4D | KBDEXT              },  // Right
    {0x4F, X4F | KBDEXT              },  // End
    {0x50, X50 | KBDEXT              },  // Down
    {0x51, X51 | KBDEXT              },  // Next
    {0x52, X52 | KBDEXT              },  // Insert
    {0x53, X53 | KBDEXT              },  // Delete
    {0x5B, X5B | KBDEXT              },  // Left Win
    {0x5C, X5C | KBDEXT              },  // Right Win
    {0x5D, X5D | KBDEXT              },  // Application
    {0x5F, X5F | KBDEXT              },  // Speedracer: Sleep
    {0x65, X65 | KBDEXT              },  // Speedracer: Browser Search
    {0x66, X66 | KBDEXT              },  // Speedracer: Browser Favorites
    {0x67, X67 | KBDEXT              },  // Speedracer: Browser Refresh
    {0x68, X68 | KBDEXT              },  // Speedracer: Browser Stop
    {0x69, X69 | KBDEXT              },  // Speedracer: Browser Forward
    {0x6A, X6A | KBDEXT              },  // Speedracer: Browser Back
    {0x6B, X6B | KBDEXT              },  // Speedracer: Launch App 1
    {0x6C, X6C | KBDEXT              },  // Speedracer: Launch Mail
    {0x6D, X6D | KBDEXT              },  // Speedracer: Launch Media Selector
    {0x1C, X1C | KBDEXT              },  // Numpad Enter
    {0x46, X46 | KBDEXT              },  // Break (Ctrl + Pause)
    {0,      0                       }
};

static VSC_VK aE1VscToVk[] = {
    {0x1D, Y1D                       },  // Pause
    {0,    0                       }
};

//---------------------------------------------------------------------------
// Map character modifier bits to modification number
//---------------------------------------------------------------------------

// Associate a Virtual Key with a Modifier bitmask.
//   Vk : Virtual key (eg: VK_SHIFT, VK_RMENU, VK_CONTROL etc.)
//   ModBits : Combination of KBDALT, KBDCTRL, KBDSHIFT and kbd - specific bits
//
// The languages that use AltGr (VK_RMENU) to shift keys convert it to
// CTRL + ALT with the KBDSPECIAL bit in the ausVK[] entry for VK_RMENU
// and by having an entry in aVkToPfnOem[] to simulate the right Vk sequence.

static VK_TO_BIT vk_to_bits[] = {
    {.Vk = VK_SHIFT,   .ModBits = KBDSHIFT},
    {.Vk = VK_CONTROL, .ModBits = KBDCTRL},
    {.Vk = VK_MENU,    .ModBits = KBDALT},
    {.Vk = 0,          .ModBits = 0} // end of table
};

// Table to map shift bits to enumerated shift states.
// Maps all possible shifter key combinations to an enumerated shift state.
// The size of the table depends on the value of the highest order bit used
// in aCharModifiers[*].ModBits
//
// Special values for aModification
//   SHFT_INVALID - no characters produced with this shift state.
//   SHFT_CTRL    - standard control character production (all keyboards must
//                  be able to produce CTRL-C == 0x0003 etc.)
//   Other        - enumerated shift state (not less than 0)
//
// This table is indexed by the Modifier Bits to obtain an Modification Number.
//
//                        CONTROL MENU SHIFT
//    aModification[] = {
//        0,            //   0     0     0     = 000  <none>
//        1,            //   0     0     1     = 001  SHIFT
//        SHFT_INVALID, //   0     1     0     = 010  ALT
//        2,            //   0     1     1     = 011  SHIFT ALT
//        3,            //   1     0     0     = 100  CTRL
//        4,            //   1     0     1     = 101  SHIFT CTRL
//        5,            //   1     1     0     = 110  CTRL ALT
//        SHFT_INVALID  //   1     1     1     = 111  SHIFT CTRL ALT
//    };

static MODIFIERS char_modifiers = {
    vk_to_bits,
    6,
    {
    //  Modification# //  Keys Pressed
    //  ============= // =============
        0,            // 
        1,            // Shift 
        2,            // Control 
        4,            // Shift + Control 
        SHFT_INVALID, // Menu 
        SHFT_INVALID, // Shift + Menu 
        3             // Control + Menu 
    }
};

//---------------------------------------------------------------------------
// aVkToWch2[]  - Virtual Key to WCHAR translation for 2 shift states
// aVkToWch3[]  - Virtual Key to WCHAR translation for 3 shift states
// aVkToWch4[]  - Virtual Key to WCHAR translation for 4 shift states
// aVkToWch5[]  - Virtual Key to WCHAR translation for 5 shift states
//
// Table attributes: Unordered Scan, null-terminated
//
// Search this table for an entry with a matching Virtual Key to find the
// corresponding unshifted and shifted WCHAR characters.
//
// Special values for VirtualKey (column 1)
//     0xff          - dead chars for the previous entry
//     0             - terminate the list
//
// Special values for Attributes (column 2)
//     CAPLOK bit    - CAPS-LOCK affect this key like SHIFT
//
// Special values for wch[*] (column 3 & 4)
//     WCH_NONE      - No character
//     WCH_DEAD      - Dead Key (diaresis) or invalid (US keyboard has none)
//     WCH_LGTR      - Ligature (generates multiple characters)
//
//---------------------------------------------------------------------------

static VK_TO_WCHARS2 aVkToWch2[] = {
    //                    |         |  Shift  |
    //                    |=========|=========|
    {VK_OEM_7     ,0      ,0x00b2   ,WCH_NONE },
    {'1'          ,CAPLOK ,'&'      ,'1'      },
    {'A'          ,CAPLOK ,'a'      ,'A'      },
    {'Z'          ,CAPLOK ,'z'      ,'Z'      },
    {'R'          ,CAPLOK ,'r'      ,'R'      },
    {'T'          ,CAPLOK ,'t'      ,'T'      },
    {'Y'          ,CAPLOK ,'y'      ,'Y'      },
    {'U'          ,CAPLOK ,'u'      ,'U'      },
    {'I'          ,CAPLOK ,'i'      ,'I'      },
    {'O'          ,CAPLOK ,'o'      ,'O'      },
    {'P'          ,CAPLOK ,'p'      ,'P'      },
    {'Q'          ,CAPLOK ,'q'      ,'Q'      },
    {'S'          ,CAPLOK ,'s'      ,'S'      },
    {'D'          ,CAPLOK ,'d'      ,'D'      },
    {'F'          ,CAPLOK ,'f'      ,'F'      },
    {'G'          ,CAPLOK ,'g'      ,'G'      },
    {'H'          ,CAPLOK ,'h'      ,'H'      },
    {'J'          ,CAPLOK ,'j'      ,'J'      },
    {'K'          ,CAPLOK ,'k'      ,'K'      },
    {'L'          ,CAPLOK ,'l'      ,'L'      },
    {'M'          ,CAPLOK ,'m'      ,'M'      },
    {VK_OEM_3     ,CAPLOK ,0x00f9   ,'%'      },
    {'W'          ,CAPLOK ,'w'      ,'W'      },
    {'X'          ,CAPLOK ,'x'      ,'X'      },
    {'C'          ,CAPLOK ,'c'      ,'C'      },
    {'V'          ,CAPLOK ,'v'      ,'V'      },
    {'B'          ,CAPLOK ,'b'      ,'B'      },
    {'N'          ,CAPLOK ,'n'      ,'N'      },
    {VK_OEM_COMMA ,CAPLOK ,','      ,'?'      },
    {VK_OEM_PERIOD,CAPLOK ,';'      ,'.'      },
    {VK_OEM_2     ,CAPLOK ,':'      ,'/'      },
    {VK_OEM_8     ,CAPLOK ,'!'      ,0x00a7   },
    {VK_DECIMAL   ,0      ,'.'      ,'.'      },
    {VK_TAB       ,0      ,'\t'     ,'\t'     },
    {VK_ADD       ,0      ,'+'      ,'+'      },
    {VK_DIVIDE    ,0      ,'/'      ,'/'      },
    {VK_MULTIPLY  ,0      ,'*'      ,'*'      },
    {VK_SUBTRACT  ,0      ,'-'      ,'-'      },
    {0            ,0      ,0        ,0        }
};

static VK_TO_WCHARS3 aVkToWch3[] = {
    //                    |         |  Shift  |  Ctrl   |
    //                    |=========|=========|=========|
    {VK_OEM_6     ,CAPLOK ,WCH_DEAD ,WCH_DEAD ,0x001b   },
    {0xff         ,0      ,'^'      ,0x00a8   ,WCH_NONE },
    {VK_OEM_5     ,CAPLOK ,'*'      ,0x00b5   ,0x001c   },
    {VK_OEM_102   ,0      ,'<'      ,'>'      ,0x001c   },
    {VK_BACK      ,0      ,'\b'     ,'\b'     ,0x007f   },
    {VK_ESCAPE    ,0      ,0x001b   ,0x001b   ,0x001b   },
    {VK_RETURN    ,0      ,'\r'     ,'\r'     ,'\n'     },
    {VK_SPACE     ,0      ,' '      ,' '      ,' '      },
    {VK_CANCEL    ,0      ,0x0003   ,0x0003   ,0x0003   },
    {0            ,0      ,0        ,0        ,0        }
};

static VK_TO_WCHARS4 aVkToWch4[] = {
    //                    |         |  Shift  |  Ctrl   |  Ctl+Alt|
    //                    |=========|=========|=========|=========|
    {'2'          ,CAPLOK ,0x00e9   ,'2'      ,WCH_NONE ,WCH_DEAD },
    {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'~'      },
    {'3'          ,CAPLOK ,'\"'     ,'3'      ,WCH_NONE ,'#'      },
    {'4'          ,CAPLOK ,'\''     ,'4'      ,WCH_NONE ,'{'      },
    {'7'          ,CAPLOK ,0x00e8   ,'7'      ,WCH_NONE ,WCH_DEAD },
    {0xff         ,0      ,WCH_NONE ,WCH_NONE ,WCH_NONE ,'`'      },
    {'0'          ,CAPLOK ,0x00e0   ,'0'      ,0x0000   ,'@'      },
    {VK_OEM_4     ,CAPLOK ,')'      ,0x00b0   ,WCH_NONE ,']'      },
    {VK_OEM_PLUS  ,CAPLOK ,'='      ,'+'      ,WCH_NONE ,'}'      },
    {'E'          ,CAPLOK ,'e'      ,'E'      ,WCH_NONE ,0x20ac   },
    {VK_OEM_1     ,CAPLOK ,'$'      ,0x00a3   ,0x001d   ,0x00a4   },
    {0            ,0      ,0        ,0        ,0        ,0        }
};

static VK_TO_WCHARS5 aVkToWch5[] = {
    //                    |         |  Shift  |  Ctrl   |  Ctl+Alt|S+Ctrl   |
    //                    |=========|=========|=========|=========|=========|
    {'5'          ,CAPLOK ,'('      ,'5'      ,WCH_NONE ,'['      ,0x001b   },
    {'6'          ,CAPLOK ,'-'      ,'6'      ,WCH_NONE ,'|'      ,0x001f   },
    {'8'          ,CAPLOK ,'_'      ,'8'      ,WCH_NONE ,'\\'     ,0x001c   },
    {'9'          ,CAPLOK ,0x00e7   ,'9'      ,WCH_NONE ,'^'      ,0x001e   },
    {0            ,0      ,0        ,0        ,0        ,0        ,0        }
};

// Put this last so that VkKeyScan interprets number characters
// as coming from the main section of the kbd (aVkToWch2 and
// aVkToWch5) before considering the numpad (aVkToWch1).

static VK_TO_WCHARS1 aVkToWch1[] = {
    {VK_NUMPAD0, 0, '0'},
    {VK_NUMPAD1, 0, '1'},
    {VK_NUMPAD2, 0, '2'},
    {VK_NUMPAD3, 0, '3'},
    {VK_NUMPAD4, 0, '4'},
    {VK_NUMPAD5, 0, '5'},
    {VK_NUMPAD6, 0, '6'},
    {VK_NUMPAD7, 0, '7'},
    {VK_NUMPAD8, 0, '8'},
    {VK_NUMPAD9, 0, '9'},
    {0,          0, '\0'}
};

static VK_TO_WCHAR_TABLE aVkToWcharTable[] = {
    {(PVK_TO_WCHARS1)aVkToWch3, 3, sizeof(aVkToWch3[0])},
    {(PVK_TO_WCHARS1)aVkToWch4, 4, sizeof(aVkToWch4[0])},
    {(PVK_TO_WCHARS1)aVkToWch5, 5, sizeof(aVkToWch5[0])},
    {(PVK_TO_WCHARS1)aVkToWch2, 2, sizeof(aVkToWch2[0])},
    {(PVK_TO_WCHARS1)aVkToWch1, 1, sizeof(aVkToWch1[0])},
    {NULL,                      0, 0},
};

//---------------------------------------------------------------------------
// Virtual Scancode to Key Name tables
//
// Table attributes: Ordered Scan (by scancode), null-terminated
//
// Only the names of Extended, NumPad, Dead and Non-Printable keys are here.
// (Keys producing printable characters are named by that character)
//---------------------------------------------------------------------------

static VSC_LPWSTR aKeyNames[] = {
    {0x01, L"ECHAP"},
    {0x0e, L"RET.ARR"},
    {0x0f, L"TAB"},
    {0x1c, L"ENTREE"},
    {0x1d, L"CTRL"},
    {0x2a, L"MAJ"},
    {0x36, L"MAJ DROITE"},
    {0x37, L"* (PAVE NUM.)"},
    {0x38, L"ALT"},
    {0x39, L"ESPACE"},
    {0x3a, L"VERR.MAJ"},
    {0x3b, L"F1"},
    {0x3c, L"F2"},
    {0x3d, L"F3"},
    {0x3e, L"F4"},
    {0x3f, L"F5"},
    {0x40, L"F6"},
    {0x41, L"F7"},
    {0x42, L"F8"},
    {0x43, L"F9"},
    {0x44, L"F10"},
    {0x45, L"Pause"},
    {0x46, L"DEFIL"},
    {0x47, L"7 (PAVE NUM.)"},
    {0x48, L"8 (PAVE NUM.)"},
    {0x49, L"9 (PAVE NUM.)"},
    {0x4a, L"- (PAVE NUM.)"},
    {0x4b, L"4 (PAVE NUM.)"},
    {0x4c, L"5 (PAVE NUM.)"},
    {0x4d, L"6 (PAVE NUM.)"},
    {0x4e, L"+ (PAVE NUM.)"},
    {0x4f, L"1 (PAVE NUM.)"},
    {0x50, L"2 (PAVE NUM.)"},
    {0x51, L"3 (PAVE NUM.)"},
    {0x52, L"0 (PAVE NUM.)"},
    {0x53, L". (PAVE NUM.)"},
    {0x57, L"F11"},
    {0x58, L"F12"},
    {0x00, NULL}
};

static VSC_LPWSTR aKeyNamesExt[] = {
    {0x1c, L"ENTREE (PAVE NUM.)"},
    {0x1d, L"CTRL DROITE"},
    {0x35, L"/ (PAVE NUM.)"},
    {0x37, L"Impr.Ecran"},
    {0x38, L"ALT DROITE"},
    {0x45, L"Ver.Num"},
    {0x46, L"ATTN"},
    {0x47, L"ORIGINE"},
    {0x48, L"HAUT"},
    {0x49, L"PG.PREC"},
    {0x4b, L"GAUCHE"},
    {0x4d, L"DROITE"},
    {0x4f, L"FIN"},
    {0x50, L"BAS"},
    {0x51, L"PG.SUIV"},
    {0x52, L"INS"},
    {0x53, L"SUPPR"},
    {0x54, L"<00>"},
    {0x56, L"AIDE"},
    {0x5b, L"WINDOWS GAUCHE"},
    {0x5c, L"WINDOWS DROITE"},
    {0x5d, L"APPLICATION"},
    {0x00, NULL}
};

static DEADKEY_LPWSTR aKeyNamesDead[] = {
    L"^"      L"ACCENT CIRCONFLEXE",
    L"\x00a8" L"TREMA",
    L"~"      L"TILDE",
    L"`"      L"GRAVE",
    NULL
};

static DEADKEY aDeadKey[] = {
    DEADTRANS(L'a', L'^',   0x00e2, 0x0000),
    DEADTRANS(L'e', L'^',   0x00ea, 0x0000),
    DEADTRANS(L'i', L'^',   0x00ee, 0x0000),
    DEADTRANS(L'o', L'^',   0x00f4, 0x0000),
    DEADTRANS(L'u', L'^',   0x00fb, 0x0000),
    DEADTRANS(L'A', L'^',   0x00c2, 0x0000),
    DEADTRANS(L'E', L'^',   0x00ca, 0x0000),
    DEADTRANS(L'I', L'^',   0x00ce, 0x0000),
    DEADTRANS(L'O', L'^',   0x00d4, 0x0000),
    DEADTRANS(L'U', L'^',   0x00db, 0x0000),
    DEADTRANS(L' ', L'^',   L'^',   0x0000),

    DEADTRANS(L'a', 0x00a8, 0x00e4, 0x0000),
    DEADTRANS(L'e', 0x00a8, 0x00eb, 0x0000),
    DEADTRANS(L'i', 0x00a8, 0x00ef, 0x0000),
    DEADTRANS(L'o', 0x00a8, 0x00f6, 0x0000),
    DEADTRANS(L'u', 0x00a8, 0x00fc, 0x0000),
    DEADTRANS(L'y', 0x00a8, 0x00ff, 0x0000),
    DEADTRANS(L'A', 0x00a8, 0x00c4, 0x0000),
    DEADTRANS(L'E', 0x00a8, 0x00cb, 0x0000),
    DEADTRANS(L'I', 0x00a8, 0x00cf, 0x0000),
    DEADTRANS(L'O', 0x00a8, 0x00d6, 0x0000),
    DEADTRANS(L'U', 0x00a8, 0x00dc, 0x0000),
    DEADTRANS(L' ', 0x00a8, 0x00a8, 0x0000),

    DEADTRANS(L'a', L'~',   0x00e3, 0x0000),
    DEADTRANS(L'A', L'~',   0x00c3, 0x0000),
    DEADTRANS(L'n', L'~',   0x00f1, 0x0000),
    DEADTRANS(L'N', L'~',   0x00d1, 0x0000),
    DEADTRANS(L'o', L'~',   0x00f5, 0x0000),
    DEADTRANS(L'O', L'~',   0x00d5, 0x0000),
    DEADTRANS(L' ', L'~',   L'~',   0x0000),

    DEADTRANS(L'a', L'`',   0x00e0, 0x0000),
    DEADTRANS(L'e', L'`',   0x00e8, 0x0000),
    DEADTRANS(L'i', L'`',   0x00ec, 0x0000),
    DEADTRANS(L'o', L'`',   0x00f2, 0x0000),
    DEADTRANS(L'u', L'`',   0x00f9, 0x0000),
    DEADTRANS(L'A', L'`',   0x00c0, 0x0000),
    DEADTRANS(L'E', L'`',   0x00c8, 0x0000),
    DEADTRANS(L'I', L'`',   0x00cc, 0x0000),
    DEADTRANS(L'O', L'`',   0x00d2, 0x0000),
    DEADTRANS(L'U', L'`',   0x00d9, 0x0000),
    DEADTRANS(L' ', L'`',   L'`',   0x0000),

    {0, 0, 0}
};

//---------------------------------------------------------------------------
// Synthesis of all keyboard tables.
//---------------------------------------------------------------------------

static KBDTABLES KbdTables = {
    .pCharModifiers  = &char_modifiers,  // Modifier keys
    .pVkToWcharTable = aVkToWcharTable,  // Characters tables
    .pDeadKey        = aDeadKey,         // Diacritics ("dead keys")
    .pKeyNames       = aKeyNames,        // Names of Keys
    .pKeyNamesExt    = aKeyNamesExt,     // "
    .pKeyNamesDead   = aKeyNamesDead,    // "
    .pusVSCtoVK      = ausVK,            // Scan codes to Virtual Keys
    .bMaxVSCtoVK     = ARRAYSIZE(ausVK), // and number of entries
    .pVSCtoVK_E0     = aE0VscToVk,       // Scancode with E0 prefix
    .pVSCtoVK_E1     = aE1VscToVk,       // Scancode with E1 prefix
    .fLocaleFlags    = MAKELONG(KLLF_ALTGR, KBD_VERSION),  // Locale-specific processing
    .nLgMax          = 0,                // Ligatures
    .cbLgEntry       = 0,
    .pLigature       = NULL
};

//---------------------------------------------------------------------------
// DLL entry point.
//---------------------------------------------------------------------------

__declspec(dllexport) PKBDTABLES KbdLayerDescriptor(void)
{
    return &KbdTables;
}
