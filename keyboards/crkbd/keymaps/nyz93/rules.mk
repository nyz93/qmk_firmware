LTO_ENABLE = yes
MOUSEKEY_ENABLE     = yes
MAGIC_ENABLE     = no
SPACE_CADET_ENABLE     = no
RAW_ENABLE          = yes
DYNAMIC_KEYMAP_ENABLE = no
MUSIC_ENABLE = no
TAP_DANCE_ENABLE = yes
RGB_MATRIX_ENABLE = yes
RGBLIGHT_ENABLE = no
OLED_ENABLE = yes
SPLIT_OLED_ENABLE = yes
SRC += rgb_init.c shift.c per_host.c host.c process_record.c tapdance.c oled.c alt_cleanup.c
