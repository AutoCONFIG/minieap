#ifndef _MINIEAP_PACKET_PLUGIN_RJV3_PRIV_H
#define _MINIEAP_PACKET_PLUGIN_RJV3_PRIV_H

#include <stdint.h>

#define RJV3_TYPE_DHCP      0x18 /* 4 byte, DHCP disabled = 0, DHCP enabled = 0x00000001 MSB */
#define RJV3_SIZE_DHCP      0x04

#define RJV3_TYPE_MAC       0x2d /* Binary representation */
#define RJV3_SIZE_MAC       0x06

#define RJV3_TYPE_MISC_1    0x2f
#define RJV3_SIZE_MISC_1    0x10

#define RJV3_TYPE_IP        0x76 /* Can be primary IPv6 also, in ASCII */
/* Var size */

#define RJV3_TYPE_MISC_2    0x35 /* 0x03 */
#define RJV3_SIZE_MISC_2    0x01

#define RJV3_TYPE_MISC_3    0x36 /* Full zero */
#define RJV3_SIZE_MISC_3    0x10

#define RJV3_TYPE_LL_IPV6   0x38 /* Link-local IPv6 in binary */
#define RJV3_SIZE_LL_IPV6   0x10

#define RJV3_TYPE_GLB_IPV6  0x4e /* Global IPv6 in binary */
#define RJV3_SIZE_GLB_IPV6  0x10

#define RJV3_TYPE_V3_HASH   0x4d /* ASCII */
#define RJV3_SIZE_V3_HASH   0x80

#define RJV3_TYPE_SERVICE   0x39 /* Service name in ASCII (GBK) */
#define RJV3_SIZE_SERVICE   0x20 /* Fixed size char array, filled by 0 */

#define RJV3_TYPE_HDD_SER   0x54 /* Primary hard disk serial number in ASCII */
#define RJV3_SIZE_HDD_SER   0x40 /* Fixed size char array, filled by 0 */

#define RJV3_TYPE_MISC_6    0x55
#define RJV3_SIZE_MISC_6    0x00 /* Null field */

#define RJV3_TYPE_MISC_7    0x62 /* 0x00 */
#define RJV3_SIZE_MISC_7    0x01

#define RJV3_TYPE_MISC_8    0x70 /* 0x40 */
#define RJV3_SIZE_MISC_8    0x01

#define RJV3_TYPE_VER_STR   0x6f /* Client version string */
/* Var size */

typedef enum _rj_broadcast_addr {
    BROADCAST_STANDARD,
    BROADCAST_RJ,
    BROADCAST_CER
} DOT1X_BCAST_ADDR;

typedef enum _rj_dhcp_type {
    DHCP_NONE,
    DHCP_DOUBLE_AUTH,
    DHCP_AFTER_AUTH,
    DHCP_BEFORE_AUTH
} DHCP_TYPE;

typedef struct _rj_prop_header1 {
    uint8_t header_type;
    uint8_t header_len;
    uint8_t magic_2[4];
} RJ_PROP_HEADER1;

typedef struct _rj_prop_header2 {
    uint8_t type;
    uint8_t len;
} RJ_PROP_HEADER2;

typedef struct _rj_prop {
    RJ_PROP_HEADER1 header1;
    RJ_PROP_HEADER2 header2;
    uint8_t* content; /* Length is included in header */
} RJ_PROP;

#endif
