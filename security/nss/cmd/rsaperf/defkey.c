/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is the Netscape security libraries.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998-2000
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

/* This key is the 1024-bit test key used for speed testing of RSA private 
** key ops.
*/
#include "seccomon.h"
#include "secoidt.h"
#include "lowkeyti.h"

#undef CONST
#define CONST

static CONST unsigned char default_n1024[128] = {
0xc2,0xae,0x96,0x89,0xaf,0xce,0xd0,0x7b,0x3b,0x35,0xfd,0x0f,0xb1,0xf4,0x7a,0xd1,
0x3c,0x7d,0xb5,0x86,0xf2,0x68,0x36,0xc9,0x97,0xe6,0x82,0x94,0x86,0xaa,0x05,0x39,
0xec,0x11,0x51,0xcc,0x5c,0xa1,0x59,0xba,0x29,0x18,0xf3,0x28,0xf1,0x9d,0xe3,0xae,
0x96,0x5d,0x6d,0x87,0x73,0xf6,0xf6,0x1f,0xd0,0x2d,0xfb,0x2f,0x7a,0x13,0x7f,0xc8,
0x0c,0x7a,0xe9,0x85,0xfb,0xce,0x74,0x86,0xf8,0xef,0x2f,0x85,0x37,0x73,0x0f,0x62,
0x4e,0x93,0x17,0xb7,0x7e,0x84,0x9a,0x94,0x11,0x05,0xca,0x0d,0x31,0x4b,0x2a,0xc8,
0xdf,0xfe,0xe9,0x0c,0x13,0xc7,0xf2,0xad,0x19,0x64,0x28,0x3c,0xb5,0x6a,0xc8,0x4b,
0x79,0xea,0x7c,0xce,0x75,0x92,0x45,0x3e,0xa3,0x9d,0x64,0x6f,0x04,0x69,0x19,0x17
};

static CONST unsigned char default_e1024[3] = { 0x01,0x00,0x01 };

static CONST unsigned char default_d1024[128] = {
0x13,0xcb,0xbc,0xf2,0xf3,0x35,0x8c,0x6d,0x7b,0x6f,0xd9,0xf3,0xa6,0x9c,0xbd,0x80,
0x59,0x2e,0x4f,0x2f,0x11,0xa7,0x17,0x2b,0x18,0x8f,0x0f,0xe8,0x1a,0x69,0x5f,0x6e,
0xac,0x5a,0x76,0x7e,0xd9,0x4c,0x6e,0xdb,0x47,0x22,0x8a,0x57,0x37,0x7a,0x5e,0x94,
0x7a,0x25,0xb5,0xe5,0x78,0x1d,0x3c,0x99,0xaf,0x89,0x7d,0x69,0x2e,0x78,0x9d,0x1d,
0x84,0xc8,0xc1,0xd7,0x1a,0xb2,0x6d,0x2d,0x8a,0xd9,0xab,0x6b,0xce,0xae,0xb0,0xa0,
0x58,0x55,0xad,0x5c,0x40,0x8a,0xd6,0x96,0x08,0x8a,0xe8,0x63,0xe6,0x3d,0x6c,0x20,
0x49,0xc7,0xaf,0x0f,0x25,0x73,0xd3,0x69,0x43,0x3b,0xf2,0x32,0xf8,0x3d,0x5e,0xee,
0x7a,0xca,0xd6,0x94,0x55,0xe5,0xbd,0x25,0x34,0x8d,0x63,0x40,0xb5,0x8a,0xc3,0x01
};

static CONST unsigned char default_p1024[64] = {
0xf6,0x3c,0x3f,0x56,0x58,0x4f,0xb3,0x82,0x0c,0xf0,0x5b,0x42,0x36,0x1c,0x93,0xde,
0x9b,0x32,0x01,0xb1,0x48,0xf8,0x00,0x57,0x9b,0xc1,0xbe,0x66,0xc2,0xbb,0xea,0x7c,
0x75,0x29,0x2c,0x22,0xaa,0x7c,0xaf,0xbd,0x0d,0x3f,0xb0,0x64,0x97,0xf0,0x88,0x25,
0xcb,0x8d,0xc7,0x19,0x0a,0x75,0x44,0xa4,0x5a,0xc3,0xb5,0xb9,0x85,0xea,0x27,0xa7
};

static CONST unsigned char default_q1024[64] = {
0xca,0x66,0xfa,0x18,0x6a,0x46,0x36,0x1c,0x46,0xfe,0x47,0xe9,0x7e,0x52,0x83,0x8a,
0xbb,0x72,0x13,0xcc,0x83,0x56,0x3d,0x64,0x22,0xdd,0xfa,0x7c,0x61,0x99,0xea,0xa4,
0xb3,0x0e,0x8f,0x79,0x10,0xab,0xba,0x4a,0x73,0xd1,0x48,0x40,0x34,0x34,0xd3,0xd2,
0x54,0x92,0xbe,0xf5,0xc8,0xc4,0x60,0x5f,0xd3,0xf7,0xce,0xbe,0x60,0x3e,0xb1,0x11
};

static CONST unsigned char default_dModP1024[64] = {
0x8e,0x80,0xbf,0x87,0x11,0x04,0xcf,0x36,0x6c,0x96,0x8d,0xb9,0xfb,0xe6,0xfe,0x0c,
0xce,0x74,0x5a,0x56,0x67,0x8c,0x5f,0x66,0x54,0x56,0x04,0x03,0x24,0x9f,0xec,0x4c,
0xaa,0xe1,0x71,0x11,0x7e,0xe9,0x3a,0x2b,0x87,0x07,0x5c,0xe6,0x5a,0xa8,0x71,0xa2,
0xad,0xf3,0x17,0x4e,0x7e,0xa6,0xef,0x5a,0xce,0xcc,0x84,0xd7,0x21,0x91,0x29,0xf1
};

static CONST unsigned char default_dModQ1024[64] = {
0x87,0x60,0x1d,0x02,0xdb,0x82,0x1e,0x8b,0x07,0x48,0xe8,0x5c,0x59,0xeb,0x62,0xa4,
0x15,0xff,0x95,0x12,0x82,0xfd,0xd9,0x8d,0xf2,0x6c,0x3a,0x2f,0x9b,0x30,0x51,0x6a,
0xdb,0x80,0x6f,0xa1,0xef,0xee,0x8c,0x69,0x63,0xd1,0xa4,0xdb,0x9c,0x8f,0x80,0xe5,
0xfb,0x3f,0x33,0x8e,0x3d,0x3c,0x6b,0xa1,0x6c,0xab,0x20,0x92,0xe0,0xd8,0xcd,0xa1
};

static CONST unsigned char default_qInvModP1024[64] = {
0xce,0xcf,0x5a,0xad,0xc4,0x8c,0x44,0x91,0x3a,0xbc,0x7b,0xf8,0x80,0xf8,0x53,0xf5,
0x12,0x84,0x8c,0x9c,0x6b,0x33,0x93,0x0d,0xa1,0x11,0xea,0xfa,0x4a,0xc1,0xeb,0x48,
0xdc,0x44,0x86,0x93,0x1b,0x98,0xc7,0x82,0x22,0x68,0x30,0x44,0xd7,0x62,0x1b,0x90,
0x54,0x07,0x4b,0x66,0xa7,0xc5,0x75,0x5a,0x72,0x77,0x92,0xdd,0x6c,0xf3,0x37,0xab
};

static CONST unsigned char default_n2048[256] = {
0xb3,0x9b,0x57,0x2c,0x15,0xdf,0x6c,0x6b,0xfc,0x04,0x83,0x02,0xf5,0xb3,0x2c,0x87,
0x1b,0x9c,0xbf,0x6c,0x46,0x1d,0xdd,0xe2,0xc0,0x6d,0xfe,0xf9,0x00,0xd1,0x85,0x91,
0x17,0x0d,0x43,0x67,0xa1,0x1f,0x8b,0xcd,0x22,0x8a,0x93,0xdc,0x9f,0xf0,0x45,0x9e,
0x58,0x0f,0x99,0x87,0xe6,0x60,0xdf,0x8c,0x1a,0xa3,0x8f,0xc3,0x6c,0xa0,0x49,0x3a,
0xdb,0x7f,0xd0,0xda,0x48,0x47,0xe3,0xd6,0x1f,0x29,0xcb,0xf2,0x1d,0xf3,0x81,0xd0,
0x4d,0xf1,0x64,0xcf,0x42,0x8e,0x0f,0xe0,0x10,0x18,0x4c,0x75,0xce,0x96,0x09,0x2e,
0x52,0xa6,0x96,0xa9,0xe1,0xab,0x3e,0x6f,0xa5,0xd3,0xee,0xd8,0xb2,0x4f,0x17,0x08,
0x6d,0x43,0xd4,0xb3,0x1c,0x8a,0x4a,0x43,0x06,0xb5,0xab,0xfb,0xf4,0x34,0x2f,0x2f,
0xe1,0x43,0x7b,0xe0,0x93,0xd0,0xaa,0x42,0xa3,0xb7,0xb7,0x43,0x52,0xeb,0xf3,0x64,
0x9a,0xbc,0xa7,0xf2,0x39,0xad,0xe4,0x62,0x7d,0xbc,0x31,0x8f,0xbf,0x59,0x93,0x62,
0x88,0xc5,0xd1,0x62,0x2d,0xe3,0xc7,0x75,0xf9,0xb8,0x00,0x96,0xe0,0x05,0x87,0x35,
0x86,0x5d,0xeb,0x7c,0x20,0xf6,0xb2,0xb1,0x65,0x1f,0xdc,0x74,0xec,0xf4,0x0e,0xd1,
0xf2,0x2d,0x06,0x47,0x02,0xc5,0x18,0xdb,0x19,0xb9,0x1b,0x40,0x90,0xc8,0x74,0x5c,
0xf6,0xe8,0x17,0x64,0xf4,0xcf,0xd3,0x17,0xeb,0xd6,0x0d,0x2b,0xec,0x2a,0x9b,0xcf,
0xc4,0xf5,0xcc,0x9a,0xc3,0x5c,0x2e,0xf1,0x98,0x25,0x2b,0xe4,0x01,0x02,0x15,0x36,
0xe1,0xe0,0x2b,0xbe,0xdf,0x23,0xf1,0xde,0x2f,0x1b,0xbb,0x44,0xa7,0x12,0x2c,0x9d
};

static CONST unsigned char default_e2048[3] = { 0x01,0x00,0x01 };

static CONST unsigned char default_d2048[256] = {
0x0f,0x03,0x3f,0x08,0x1a,0x53,0xf0,0x96,0x1e,0x1c,0xaa,0x6e,0xc6,0xe6,0xd1,0x24,
0x01,0xf4,0xda,0x33,0x4c,0xb1,0x16,0x68,0xeb,0xb8,0xc6,0x05,0x3e,0x42,0x45,0x2d,
0xd9,0x85,0x6c,0x4a,0xef,0x36,0xd9,0xd2,0xad,0xbe,0x73,0x99,0x8f,0x6c,0xe0,0x04,
0xda,0x4b,0x83,0x83,0xce,0x87,0xee,0x67,0xa1,0x9a,0x66,0x5b,0xe9,0x6a,0x84,0x74,
0x7d,0x00,0x74,0x0e,0xaa,0xd8,0x07,0x7d,0x50,0x61,0x88,0x00,0x96,0xec,0x51,0xbf,
0x7d,0xa4,0x5d,0xce,0xcd,0x3b,0x5e,0xac,0x55,0xec,0x12,0x08,0x0e,0xda,0x8f,0xad,
0xe5,0x8e,0xb3,0x2d,0x44,0x05,0xb2,0x54,0x56,0xc2,0x1e,0x46,0xd2,0xb0,0xb5,0xb6,
0x28,0x9b,0xf0,0xdd,0x7f,0xd7,0x37,0x59,0xde,0xe7,0xb4,0x96,0x7c,0xd5,0x17,0xd4,
0x7e,0xe0,0xcb,0xb3,0x3c,0x5f,0x72,0x30,0xbe,0x3c,0x81,0x82,0x8e,0xb9,0xc6,0xa7,
0x23,0x71,0xf5,0x6f,0xd7,0x56,0xe4,0xee,0x3b,0x2d,0x8f,0x3e,0x43,0x98,0xc8,0xe8,
0x95,0xfd,0xc3,0x73,0xd3,0x8e,0x38,0x01,0xa5,0xc6,0xbe,0x0c,0x6b,0x6b,0x4f,0x13,
0x2f,0x66,0x8b,0x85,0xe3,0x9e,0x12,0xc0,0x52,0x60,0xec,0x4a,0xcb,0xfa,0x7e,0x7c,
0x20,0x9a,0x11,0x16,0x1a,0xb7,0x96,0xd6,0x00,0x7a,0x04,0x7b,0x17,0xcc,0x4c,0x43,
0xdc,0xd0,0x64,0x45,0x45,0xd3,0x21,0x06,0x8b,0xd6,0xb0,0xf0,0xbf,0x20,0x56,0xfd,
0x11,0x9c,0x1d,0x82,0xcd,0x34,0x16,0x75,0x63,0xac,0x51,0xd5,0x55,0xb4,0x35,0x0a,
0xc3,0x8c,0x47,0x01,0x8e,0x99,0x95,0xc5,0x99,0x21,0x79,0x66,0x1a,0xa6,0xb0,0xe9
};

static CONST unsigned char default_p2048[128] = {
0xd7,0xaa,0xb4,0x8d,0xb1,0x23,0x67,0x80,0x7b,0x98,0xf7,0xe6,0xfd,0x6d,0x5c,0x98,
0x34,0x89,0x97,0xbd,0xa8,0x88,0xdd,0xb3,0xe6,0xbc,0x5f,0xb8,0xd6,0xa5,0x14,0x00,
0x4a,0x54,0x1a,0xbf,0x65,0x64,0x7d,0x39,0x55,0xff,0x27,0x0f,0x2f,0x99,0x57,0xe6,
0x69,0x89,0x1c,0xc4,0x89,0xff,0xe4,0x1f,0xa5,0x47,0xea,0x1e,0x47,0x07,0xf7,0x46,
0xa5,0x3a,0x25,0x70,0x9e,0x6d,0xe3,0x83,0xc1,0x9d,0x75,0xf5,0x67,0xb5,0x7f,0x5c,
0xf8,0x24,0xff,0x85,0x11,0x53,0xff,0x0e,0xbc,0x57,0x6f,0xc7,0x2a,0x36,0xbd,0xdd,
0x0b,0xe5,0x25,0x04,0x1f,0x48,0xbc,0xdd,0xd6,0x13,0xb8,0xe9,0xfd,0x00,0xba,0x37,
0x13,0x63,0xc2,0xd4,0x70,0xf8,0x4b,0x09,0x71,0xa8,0xbe,0xca,0x0d,0x68,0x16,0x5f
};

static CONST unsigned char default_q2048[128] = {
0xd5,0x32,0x38,0x82,0x14,0xed,0xd1,0x90,0x51,0xef,0x17,0xa2,0x9b,0xc3,0xb0,0x45,
0x86,0x64,0xbe,0xce,0x8f,0x85,0x78,0x18,0x7a,0xf8,0x3a,0xb7,0x17,0x7b,0x5d,0xf3,
0xe9,0xd7,0x9d,0xb3,0x2f,0x96,0x35,0x96,0x60,0x38,0xe7,0x96,0xc3,0x08,0xe6,0xf1,
0xb8,0x16,0xc0,0x1d,0xc9,0x6f,0xd3,0x99,0x14,0x8e,0xd3,0x6a,0x2b,0x6c,0x4d,0xd1,
0x71,0x1c,0x4c,0x38,0x72,0x18,0x23,0xf9,0xd1,0x6c,0xa2,0x87,0xfe,0x33,0xc2,0x9d,
0x6e,0xd0,0x80,0x62,0x44,0x7b,0x3a,0x4d,0x2f,0xff,0x5f,0x73,0xe5,0x53,0x32,0x18,
0x14,0xb2,0xdb,0x6b,0x25,0x7b,0xac,0xb4,0x3b,0x1e,0x5e,0xcd,0xec,0x01,0x99,0xdb,
0x0c,0x1f,0xc2,0xa6,0x50,0x1d,0x6d,0x7b,0x58,0x75,0x04,0x89,0x5d,0x87,0x86,0x83
};

static CONST unsigned char default_dModP2048[128] = {
0xc0,0xba,0x16,0x1b,0xc1,0x3e,0xc8,0x51,0xb3,0x22,0x21,0xf7,0x54,0x66,0x14,0xa7,
0x17,0xdc,0x15,0xb4,0x31,0x16,0x0e,0x39,0xa4,0x6a,0x96,0x88,0x11,0x98,0xf7,0xe4,
0xc2,0x87,0xa2,0x57,0x83,0xfe,0x67,0x41,0x83,0xae,0x3e,0x73,0x7d,0xaf,0xe5,0x33,
0x4d,0x00,0x70,0xaa,0xda,0x3f,0xc8,0xd6,0xd6,0xd7,0x0b,0x4a,0xff,0x63,0x09,0x01,
0x22,0xca,0x71,0x86,0xd0,0xad,0x96,0xf1,0xb9,0x66,0x43,0x71,0x88,0xba,0x53,0x14,
0xfb,0xd3,0xe4,0x5c,0x3f,0xfd,0xf6,0x22,0x6f,0x01,0x1c,0x2c,0xb9,0x76,0xad,0xf9,
0x09,0x96,0x3e,0x9c,0x0e,0x70,0xec,0x06,0xba,0x36,0x69,0xbb,0x00,0x93,0x53,0xd5,
0xc0,0x08,0x18,0xa5,0xcc,0x46,0xb6,0x97,0xbb,0xf0,0x76,0x7f,0x0d,0xb8,0x04,0xb5
};

static CONST unsigned char default_dModQ2048[128] = {
0xa9,0x18,0xfd,0x43,0x07,0xf0,0x9d,0x50,0x77,0xfc,0x48,0xe5,0xdb,0xe0,0x39,0xd6,
0xdb,0x42,0xdb,0x28,0xa1,0x23,0x7e,0xdf,0x03,0xe2,0x11,0x48,0x19,0xa2,0xeb,0x21,
0x44,0xaf,0x95,0x50,0x83,0x85,0x03,0x99,0xf3,0x56,0x0f,0x32,0x40,0x1d,0xb6,0x77,
0xb0,0xc8,0xb2,0xb6,0xad,0x88,0x39,0xef,0xe8,0x23,0x64,0xc2,0x88,0x10,0x8e,0x24,
0x7a,0x2f,0xb4,0xb0,0xec,0xa6,0x03,0x1a,0xe9,0xa5,0xdd,0xc0,0x39,0xba,0xba,0x38,
0xfe,0xa4,0xf7,0xbf,0x79,0x8b,0xb7,0xf1,0x73,0x09,0x7d,0x9f,0x42,0x1c,0x5b,0xd6,
0x47,0xcc,0x99,0x46,0x81,0xe3,0x77,0x57,0x38,0xb0,0xdd,0x07,0x3d,0x93,0x03,0x82,
0x7f,0x3a,0x4d,0xbc,0x76,0x3c,0xf1,0x12,0x6d,0x55,0xdb,0x34,0x4c,0xef,0xea,0x9b
};

static CONST unsigned char default_qInvModP2048[128] = {
0x77,0xd9,0x45,0xd4,0xd2,0xd1,0x46,0xa8,0xaf,0x57,0x8f,0x5e,0x4f,0x6b,0x24,0x0f,
0xb4,0xaa,0xff,0x92,0x86,0x78,0xa8,0xc1,0x69,0x9c,0x54,0xe9,0x81,0xa1,0x9c,0x26,
0x11,0x5d,0xfa,0xff,0x70,0x9e,0xa3,0xf3,0xe3,0x78,0x41,0x2b,0x31,0x35,0x09,0xa2,
0x5c,0x5f,0x6e,0x4d,0xad,0xeb,0x4a,0xe0,0xb1,0xce,0x2c,0x22,0x59,0x72,0x4c,0x17,
0xad,0x71,0x5c,0x25,0xca,0x4f,0x00,0xc6,0xee,0x63,0x10,0x8e,0xf7,0xbe,0xa4,0x55,
0x22,0x0d,0x2c,0xb9,0xe5,0xa9,0x72,0x07,0xa2,0xb1,0x29,0xf2,0x4a,0x9f,0xde,0x70,
0x0c,0x28,0xb7,0x60,0x12,0x9d,0x4b,0x04,0xd7,0xe3,0xd7,0xc5,0x71,0xdf,0x5c,0xc0,
0x65,0x75,0x6e,0xfb,0xc6,0x3e,0x61,0x4c,0xc2,0xdf,0xb3,0xd3,0xba,0x17,0x36,0x24
};

static struct NSSLOWKEYPrivateKeyStr rsaPriv;

NSSLOWKEYPrivateKey *
getDefaultRSAPrivateKey(int keysize)
{
    if (rsaPriv.keyType != NSSLOWKEYRSAKey) {

	/* leaving arena uninitialized. It isn't used in this test. */

	rsaPriv.keyType                     = NSSLOWKEYRSAKey;

	/* leaving arena   uninitialized. It isn't used. */
	/* leaving version uninitialized. It isn't used. */

        if (keysize == 2048) {
	    rsaPriv.u.rsa.modulus.data          =        default_n2048;
	    rsaPriv.u.rsa.modulus.len           = sizeof default_n2048;
	    rsaPriv.u.rsa.publicExponent.data   =        default_e2048;
	    rsaPriv.u.rsa.publicExponent.len    = sizeof default_e2048;
	    rsaPriv.u.rsa.privateExponent.data  =        default_d2048;
	    rsaPriv.u.rsa.privateExponent.len   = sizeof default_d2048;
	    rsaPriv.u.rsa.prime1.data           =        default_p2048;
	    rsaPriv.u.rsa.prime1.len            = sizeof default_p2048;
	    rsaPriv.u.rsa.prime2.data           =        default_q2048;
	    rsaPriv.u.rsa.prime2.len            = sizeof default_q2048;
	    rsaPriv.u.rsa.exponent1.data        =        default_dModP2048;
	    rsaPriv.u.rsa.exponent1.len         = sizeof default_dModP2048;
	    rsaPriv.u.rsa.exponent2.data        =        default_dModQ2048;
	    rsaPriv.u.rsa.exponent2.len         = sizeof default_dModQ2048;
	    rsaPriv.u.rsa.coefficient.data      =        default_qInvModP2048;
	    rsaPriv.u.rsa.coefficient.len       = sizeof default_qInvModP2048;
	} else {
	    rsaPriv.u.rsa.modulus.data          =        default_n1024;
	    rsaPriv.u.rsa.modulus.len           = sizeof default_n1024;
	    rsaPriv.u.rsa.publicExponent.data   =        default_e1024;
	    rsaPriv.u.rsa.publicExponent.len    = sizeof default_e1024;
	    rsaPriv.u.rsa.privateExponent.data  =        default_d1024;
	    rsaPriv.u.rsa.privateExponent.len   = sizeof default_d1024;
	    rsaPriv.u.rsa.prime1.data           =        default_p1024;
	    rsaPriv.u.rsa.prime1.len            = sizeof default_p1024;
	    rsaPriv.u.rsa.prime2.data           =        default_q1024;
	    rsaPriv.u.rsa.prime2.len            = sizeof default_q1024;
	    rsaPriv.u.rsa.exponent1.data        =        default_dModP1024;
	    rsaPriv.u.rsa.exponent1.len         = sizeof default_dModP1024;
	    rsaPriv.u.rsa.exponent2.data        =        default_dModQ1024;
	    rsaPriv.u.rsa.exponent2.len         = sizeof default_dModQ1024;
	    rsaPriv.u.rsa.coefficient.data      =        default_qInvModP1024;
	    rsaPriv.u.rsa.coefficient.len       = sizeof default_qInvModP1024;
	}
    }
    return &rsaPriv;
}

static struct NSSLOWKEYPublicKeyStr rsaPub;

NSSLOWKEYPublicKey *
getDefaultRSAPublicKey(int keysize)
{
    if (rsaPub.keyType != NSSLOWKEYRSAKey) {

	rsaPub.keyType			   = NSSLOWKEYRSAKey;

        if (keysize == 2048) {
	    rsaPub.u.rsa.modulus.data          =        default_n2048;
	    rsaPub.u.rsa.modulus.len           = sizeof default_n2048;

	    rsaPub.u.rsa.publicExponent.data   =        default_e2048;
	    rsaPub.u.rsa.publicExponent.len    = sizeof default_e2048;
	} else {
	    rsaPub.u.rsa.modulus.data          =        default_n1024;
	    rsaPub.u.rsa.modulus.len           = sizeof default_n1024;

	    rsaPub.u.rsa.publicExponent.data   =        default_e1024;
	    rsaPub.u.rsa.publicExponent.len    = sizeof default_e1024;
	}
    }
    return &rsaPub;
}

/*  modPop = 536, privPop = 531, ex1Pop = 261, ex2Pop = 257
 *  After 46 tries, found this key:
 *  Version: 0 (0x0)
 *  Modulus:
 *      c2:ae:96:89:af:ce:d0:7b:3b:35:fd:0f:b1:f4:7a:d1:3c:7d:b5:
 *      86:f2:68:36:c9:97:e6:82:94:86:aa:05:39:ec:11:51:cc:5c:a1:
 *      59:ba:29:18:f3:28:f1:9d:e3:ae:96:5d:6d:87:73:f6:f6:1f:d0:
 *      2d:fb:2f:7a:13:7f:c8:0c:7a:e9:85:fb:ce:74:86:f8:ef:2f:85:
 *      37:73:0f:62:4e:93:17:b7:7e:84:9a:94:11:05:ca:0d:31:4b:2a:
 *      c8:df:fe:e9:0c:13:c7:f2:ad:19:64:28:3c:b5:6a:c8:4b:79:ea:
 *      7c:ce:75:92:45:3e:a3:9d:64:6f:04:69:19:17
 *  Public Exponent: 65537 (0x10001)
 *  Private Exponent:
 *      13:cb:bc:f2:f3:35:8c:6d:7b:6f:d9:f3:a6:9c:bd:80:59:2e:4f:
 *      2f:11:a7:17:2b:18:8f:0f:e8:1a:69:5f:6e:ac:5a:76:7e:d9:4c:
 *      6e:db:47:22:8a:57:37:7a:5e:94:7a:25:b5:e5:78:1d:3c:99:af:
 *      89:7d:69:2e:78:9d:1d:84:c8:c1:d7:1a:b2:6d:2d:8a:d9:ab:6b:
 *      ce:ae:b0:a0:58:55:ad:5c:40:8a:d6:96:08:8a:e8:63:e6:3d:6c:
 *      20:49:c7:af:0f:25:73:d3:69:43:3b:f2:32:f8:3d:5e:ee:7a:ca:
 *      d6:94:55:e5:bd:25:34:8d:63:40:b5:8a:c3:01
 *  Prime 1:
 *      f6:3c:3f:56:58:4f:b3:82:0c:f0:5b:42:36:1c:93:de:9b:32:01:
 *      b1:48:f8:00:57:9b:c1:be:66:c2:bb:ea:7c:75:29:2c:22:aa:7c:
 *      af:bd:0d:3f:b0:64:97:f0:88:25:cb:8d:c7:19:0a:75:44:a4:5a:
 *      c3:b5:b9:85:ea:27:a7
 *  Prime 2:
 *      ca:66:fa:18:6a:46:36:1c:46:fe:47:e9:7e:52:83:8a:bb:72:13:
 *      cc:83:56:3d:64:22:dd:fa:7c:61:99:ea:a4:b3:0e:8f:79:10:ab:
 *      ba:4a:73:d1:48:40:34:34:d3:d2:54:92:be:f5:c8:c4:60:5f:d3:
 *      f7:ce:be:60:3e:b1:11
 *  Exponent 1:
 *      8e:80:bf:87:11:04:cf:36:6c:96:8d:b9:fb:e6:fe:0c:ce:74:5a:
 *      56:67:8c:5f:66:54:56:04:03:24:9f:ec:4c:aa:e1:71:11:7e:e9:
 *      3a:2b:87:07:5c:e6:5a:a8:71:a2:ad:f3:17:4e:7e:a6:ef:5a:ce:
 *      cc:84:d7:21:91:29:f1
 *  Exponent 2:
 *      87:60:1d:02:db:82:1e:8b:07:48:e8:5c:59:eb:62:a4:15:ff:95:
 *      12:82:fd:d9:8d:f2:6c:3a:2f:9b:30:51:6a:db:80:6f:a1:ef:ee:
 *      8c:69:63:d1:a4:db:9c:8f:80:e5:fb:3f:33:8e:3d:3c:6b:a1:6c:
 *      ab:20:92:e0:d8:cd:a1
 *  Coefficient:
 *      ce:cf:5a:ad:c4:8c:44:91:3a:bc:7b:f8:80:f8:53:f5:12:84:8c:
 *      9c:6b:33:93:0d:a1:11:ea:fa:4a:c1:eb:48:dc:44:86:93:1b:98:
 *      c7:82:22:68:30:44:d7:62:1b:90:54:07:4b:66:a7:c5:75:5a:72:
 *      77:92:dd:6c:f3:37:ab
 */
