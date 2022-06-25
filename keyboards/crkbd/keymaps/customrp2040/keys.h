#define LAYOUT_ben_split_3x5_3(                                             \
                            L00, L01, L02, L03, L04,            \
                            L10, L11, L12, L13, L14,           \
                            L20, L21, L22, L23, L24,            \
                            L30, L31, L32,   \
    R00, R01, R02, R03, R04, \
    R10, R11, R12, R13, R14, \
    R20, R21, R22, R23, R24, \
    R30, R31, R32 \
                            )                                           \
    {                                                                   \
        { KC_NO, L00, L01, L02, L03, L04 },                         \
        { KC_NO, L10, L11, L12, L13, L14 },                             \
        { KC_NO, L20, L21, L22, L23, L24 },                             \
        { KC_NO, KC_NO, KC_NO, L30, L31, L32 },                         \
        { KC_NO, R04, R03, R02, R01, R00 },                             \
        { KC_NO, R14, R13, R12, R11, R10 },                             \
        { KC_NO, R24, R23, R22, R21, R20 },                             \
        { KC_NO, KC_NO, KC_NO, R32, R31, R30 }                          \
    }

enum custom_combo {
    CUSTOM_QU = SAFE_RANGE + 5,
    CUSTOM_AUML,
    CUSTOM_UUML,
    CUSTOM_OUML,
    CUSTOM_BSPACE,
    CUSTOM_REPEAT,
    CUSTOM_END_CAPS,
    CUSTOM_ESC,
    CUSTOM_ENTER,
    CUSTOM_LAST
};

enum custom_ext {
    LLOCK = CUSTOM_LAST,
};
