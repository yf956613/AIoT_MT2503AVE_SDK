/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
#include "MMIDataType.h"
#include "NetsetSrvProt.h"

const U32 plmn_mccmnc_bcd[]=
{
/* Do NOT modify the following line. It is a keyword for the PLMN automatic create tool */
/* PLMN BCD */
/* DONE */
   0x00f064,
   0x20f064,
   0x70f064,
   0x10f064,
   0x10f664,
   0x88f664,
   0x98f664,
   0x29f664,
   0x39f664,
   0x79f664,
   0x99f664,
   0x00f454,
   0x20f454,
   0x81f454,
   0x30f454,
   0x40f454,
   0x60f454,
   0x01f454,
   0x21f454,
   0x51f454,
   0x61f454,
   0x91f454,
   0x00f554,
   0x10f554,
   0x40f554,
   0x30f554,
   0x50f554,
   0x10f404,
   0x20f404,
   0x30f404,
   0x40f404,
   0x50f404,
   0x70f404,
   0x01f404,
   0x11f404,
   0x21f404,
   0x31f404,
   0x41f404,
   0x51f404,
   0x71f404,
   0x81f404,
   0x91f404,
   0x02f404,
   0x12f404,
   0x22f404,
   0x42f404,
   0x52f404,
   0x72f404,
   0x82f404,
   0x92f404,
   0x13f404,
   0x33f404,
   0x43f404,
   0x53f404,
   0x73f404,
   0x83f404,
   0x04f404,
   0x14f404,
   0x24f404,
   0x34f404,
   0x44f404,
   0x54f404,
   0x64f404,
   0x94f404,
   0x15f404,
   0x35f404,
   0x45f404,
   0x55f404,
   0x65f404,
   0x75f404,
   0x85f404,
   0x95f404,
   0x06f404,
   0x26f404,
   0x46f404,
   0x66f404,
   0x86f404,
   0x96f404,
   0x07f404,
   0x17f404,
   0x27f404,
   0x37f404,
   0x47f404,
   0x57f404,
   0x67f404,
   0x77f404,
   0x87f404,
   0x97f404,
   0x08f404,
   0x18f404,
   0x28f404,
   0x48f404,
   0x68f404,
   0x78f404,
   0x88f404,
   0x98f404,
   0x09f404,
   0x19f404,
   0x29f404,
   0x39f404,
   0x49f404,
   0x59f404,
   0x69f404,
   0x79f404,
   0x89f404,
   0x03f404,
   0x10f504,
   0x50f504,
   0x60f504,
   0x70f504,
   0x90f504,
   0x01f504,
   0x11f504,
   0x31f504,
   0x51f504,
   0x81f504,
   0x91f504,
   0x02f504,
   0x12f504,
   0x22f504,
   0x15f504,
   0x25f504,
   0x35f504,
   0x45f504,
   0x55f504,
   0x65f504,
   0x66f504,
   0x76f504,
   0x07f504,
   0x205504,
   0x207504,
   0x209504,
   0x300504,
   0x301504,
   0x302504,
   0x304504,
   0x305504,
   0x306504,
   0x307504,
   0x308504,
   0x309504,
   0x401504,
   0x402504,
   0x403504,
   0x404504,
   0x405504,
   0x406504,
   0x407504,
   0x570504,
   0x571504,
   0x572504,
   0x573504,
   0x574504,
   0x575504,
   0x576504,
   0x979504,
   0x080504,
   0x081504,
   0x083504,
   0x085504,
   0x089504,
   0x180504,
   0x181504,
   0x582504,
   0x193504,
   0x10f214,
   0x02f214,
   0x04f214,
   0x05f214,
   0x10f074,
   0x20f074,
   0x30f074,
   0x40f074,
   0x70f074,
   0x10f624,
   0x20f624,
   0x11f204,
   0x77f204,
   0x20f825,
   0x11f825,
   0x10f654,
   0x20f654,
   0x40f654,
   0x50f654,
   0x81f654,
   0x20f415,
   0x10f015,
   0x80f015,
   0x01f015,
   0x11f015,
   0x12f015,
   0x98f015,
   0x11f234,
   0x41f234,
   0x91f234,
   0x23f234,
   0x53f234,
   0x50f814,
   0x02f814,
   0x10f524,
   0x50f524,
   0x20f524,
   0x30f524,
   0x00f044,
   0x01f044,
   0x02f044,
   0x10f614,
   0x30f614,
   0x77f614,
   0x20f054,
   0x80f054,
   0x50f054,
   0x20f914,
   0x30f914,
   0x10f734,
   0x50f734,
   0x10f754,
   0x20f754,
   0x30f754,
   0x80f754,
   0x10f514,
   0x21f205,
   0x31f205,
   0x61f205,
   0x81f205,
   0x91f205,
   0x10f274,
   0x20f274,
   0x88f824,
   0x99f824,
   0x10f414,
   0x10f924,
   0x20f924,
   0x20f224,
   0x30f224,
   0x10f014,
   0x30f014,
   0x40f014,
   0x60f014,
   0x70f014,
   0x10f515,
   0x20f515,
   0x30f515,
   0x50f515,
   0x81f515,
   0x10f724,
   0x10f024,
   0x30f024,
   0x10f525,
   0x20f525,
   0x30f525,
   0x50f525,
   0x10f314,
   0x20f314,
   0x30f314,
   0x50f314,
   0x80f314,
   0x10f714,
   0x20f714,
   0x10f634,
   0x20f634,
   0x21f634,
   0x30f634,
   0x40f634,
   0x50f634,
   0x10f025,
   0x01f025,
   0x99f025,
   0x51f025,
   0x81f025,
   0x32f025,
   0x10f682,
   0x20f682,
   0x30f682,
   0x20f424,
   0x30f424,
   0x10f254,
   0x20f254,
   0x40f254,
   0x10f124,
   0x20f124,
   0x10f672,
   0x20f672,
   0x30f672,
   0x30f312,
   0x10f382,
   0x50f382,
   0x10f232,
   0x30f232,
   0x50f232,
   0x70f232,
   0x01f232,
   0x21f232,
   0x10f004,
   0x20f004,
   0x40f004,
   0x10f752,
   0x20f752,
   0x40f752,
   0x10f602,
   0x01f602,
   0x02f602,
   0x30f812,
   0x50f812,
   0x09f812,
   0x10f482,
   0x30f482,
   0x50f482,
   0x10f912,
   0x20f912,
   0x01f912,
   0x10f082,
   0x01f082,
   0x10f032,
   0x20f032,
   0x30f032,
   0x10f832,
   0x20f832,
   0x60f832,
   0x02f832,
   0x77f832,
   0x10f842,
   0x20f842,
   0x30f842,
   0x10f882,
   0x20f882,
   0x30f442,
   0x21f442,
   0x50f442,
   0x41f442,
   0x19f442,
   0x10f802,
   0x01f802,
   0x02f802,
   0x10f282,
   0x20f282,
   0x40f282,
   0x10f262,
   0x20f262,
   0x30f262,
   0x70f262,
   0x80f262,
   0x10f662,
   0x10f202,
   0x50f202,
   0x01f202,
   0x10f092,
   0x10f612,
   0x03f612,
   0x07f612,
   0x10f472,
   0x20f472,
   0x40f472,
   0x70f472,
   0x80f472,
   0x11f472,
   0x10f272,
   0x20f272,
   0x30f272,
   0x50f272,
   0x10f222,
   0x01f222,
   0x88f222,
   0x99f222,
   0x10f104,
   0x20f104,
   0x77f104,
   0x10f742,
   0x20f742,
   0x50f742,
   0x10f592,
   0x20f592,
   0x50f592,
   0x77f592,
   0x10f642,
   0x20f642,
   0x30f642,
   0x10f072,
   0x77f072,
   0x99f072,
   0x10f492,
   0x20f492,
   0x30f492,
   0x10f872,
   0x12f872,
   0x77f872,
   0x10f952,
   0x20f952,
   0x40f952,
   0x40f402,
   0x80f402,
   0x21f402,
   0x61f402,
   0x02f402,
   0x10f242,
   0x20f242,
   0x30f242,
   0x50f242,
   0x10f062,
   0x20f062,
   0x30f062,
   0x60f062,
   0x71f062,
   0x10f862,
   0x30f862,
   0x60f862,
   0x10f622,
   0x30f622,
   0x50f622,
   0x01f622,
   0x10f052,
   0x20f052,
   0x40f052,
   0x50f052,
   0x70f052,
   0x01f052,
   0x21f052,
   0x31f052,
   0x51f052,
   0x61f052,
   0x71f052,
   0x91f052,
   0x02f052,
   0x82f052,
   0x53f052,
   0x93f052,
   0x99f052,
   0x10f022,
   0x20f022,
   0x30f022,
   0x40f022,
   0x50f022,
   0x10f132,
   0x20f132,
   0x60f132,
   0x04f392,
   0x14f392,
   0x46f392,
   0x07f392,
   0x10f412,
   0x30f412,
   0x40f412,
   0x70f412,
   0x10f042,
   0x20f042,
   0x40f042,
   0x50f042,
   0x70f042,
   0x80f042,
   0x01f042,
   0x10f822,
   0x20f822,
   0x30f822,
   0x70f822,
   0x80f822,
   0x10f552,
   0x20f552,
   0x30f552,
   0x50f552,
   0x60f552,
   0x70f552,
   0x10f432,
   0x01f432,
   0x51f432,
   0x02f432,
   0x03f432,
   0x13f432,
   0x23f432,
   0x33f432,
   0x40f434,
   0x50f434,
   0x70f434,
   0x10f834,
   0x300443,
   0x290443,
   0x390443,
   0x70f227,
   0x43f227,
   0x130227,
   0x10f363,
   0x76f207,
   0x10f053,
   0x20f053,
   0x10f637,
   0x20f637,
   0x30f637,
   0x20f427,
   0x30f427,
   0x40f427,
   0x50f427,
   0x60f427,
   0x01f427,
   0x11f427,
   0x32f427,
   0x51f427,
   0x61f427,
   0x42f427,
   0x13f427,
   0x23f427,
   0x33f427,
   0x43f427,
   0x530203,
   0x730203,
   0x830203,
   0x270203,
   0x10f037,
   0x20f037,
   0x30f037,
   0x011237,
   0x013237,
   0x213237,
   0x10f217,
   0x10f863,
   0x10f073,
   0x20f073,
   0x00f047,
   0x10f047,
   0x10f607,
   0x20f607,
   0x30f607,
   0x001807,
   0x20f807,
   0x500833,
   0x810833,
   0x10f043,
   0x20f043,
   0x02f043,
   0x200433,
   0x30f433,
   0x300253,
   0x110253,
   0x10f407,
   0x20f407,
   0x30f407,
   0x10f837,
   0x10f273,
   0x15f263,
   0x96f263,
   0x591263,
   0x12f017,
   0x37f017,
   0x10f417,
   0x10f447,
   0x20f447,
   0x60f617,
   0x01f617,
   0x110653,
   0x110853,
   0x10f803,
   0x110063,
   0x20f647,
   0x21f473,
   0x62f013,
   0x13f013,
   0x610013,
   0x020013,
   0x120013,
   0x220013,
   0x320013,
   0x420013,
   0x520013,
   0x620013,
   0x720013,
   0x660013,
   0x510013,
   0x710013,
   0x830013,
   0x140013,
   0x300013,
   0x310013,
   0x980013,
   0x70f847,
   0x01f847,
   0x20f437,
   0x40f437,
   0x500433,
   0x10f505,
   0x20f505,
   0x30f505,
   0x60f505,
   0x10f845,
   0x10f245,
   0x02f745,
   0x90f545,
   0x10f055,
   0x10f645,
   0x10f035,
   0x50f035,
   0x08f255,
   0x10f735,
   0x72f945,
   0x10f045,
   0x10f935,
   0x10f145,
   0x10f306,
   0x20f306,
   0x20f136,
   0x20f616,
   0x30f616,
   0x40f616,
   0x50f616,
   0x10f256,
   0x20f256,
   0x20f316,
   0x10f246,
   0x20f246,
   0x30f246,
   0x10f426,
   0x20f426,
   0x10f526,
   0x20f326,
   0x40f326,
   0x10f226,
   0x001456,
   0x10f926,
   0x01f926,
   0x10f036,
   0x50f036,
   0x10f836,
   0x10f206,
   0x20f206,
   0x30f206,
   0x10f636,
   0x10f726,
   0x10f826,
   0x20f826,
   0x30f826,
   0x10f706,
   0x20f706,
   0x10f026,
   0x20f026,
   0x30f026,
   0x20f116,
   0x20f216,
   0x30f216,
   0x50f216,
   0x20f936,
   0x30f936,
   0x10f156,
   0x20f156,
   0x10f606,
   0x10f646,
   0x20f646,
   0x10f056,
   0x01f056,
   0x10f016,
   0x20f016,
   0x10f906,
   0x01f906,
   0x10f716,
   0x01f716,
   0x00f406,
   0x10f406,
   0x10f346,
   0x40f346,
   0x10f946,
   0x10f416,
   0x20f416,
   0x30f416,
   0x02f126,
   0x03f126,
   0x04f126,
   0x05f126,
   0x06f126,
   0x00f746,
   0x20f746,
   0x01f746,
   0x01f536,
   0x10f626,
   0x10f806,
   0x20f806,
   0x10f336,
   0x01f336,
   0x10f916,
   0x20f916,
   0x10f736,
   0x40f736,
   0x01f736,
   0x03f736,
   0x28f736,
   0x10f556,
   0x70f556,
   0x01f556,
   0x10f436,
   0x20f436,
   0x01f356,
   0x20f046,
   0x30f046,
   0x40f046,
   0x50f046,
   0x10f516,
   0x30f516,
   0x20f506,
   0x30f506,
   0x10f146,
   0x01f146,
   0x11f146,
   0x22f146,
   0x10f546,
   0x20f546,
   0x10f846,
   0x30f846,
   0x40f846,
   0x20f447,
   0x40f447,
   0x50f447,
   0x10f447,
   0 // dummy one
};

const U16 plmn_index[]=
{
/* Do NOT modify the following line. It is a keyword for the PLMN automatic create tool */
/* PLMN INDEX */
   0,
   0,
   0,
   1,
   2,
   3,
   4,
   5,
   6,
   7,
   8,
   9,
   9,
   9,
   10,
   10,
   11,
   12,
   13,
   11,
   14,
   14,
   11,
   15,
   15,
   16,
   16,
   17,
   18,
   18,
   19,
   17,
   19,
   18,
   17,
   19,
   17,
   20,
   17,
   21,
   22,
   19,
   17,
   23,
   19,
   19,
   21,
   17,
   21,
   21,
   18,
   21,
   24,
   21,
   21,
   24,
   18,
   21,
   21,
   17,
   20,
   18,
   17,
   18,
   24,
   24,
   24,
   24,
   19,
   24,
   24,
   24,
   17,
   24,
   24,
   24,
   25,
   25,
   26,
   24,
   24,
   24,
   24,
   24,
   24,
   24,
   19,
   24,
   24,
   24,
   19,
   17,
   17,
   19,
   17,
   19,
   18,
   21,
   18,
   18,
   18,
   18,
   18,
   18,
   18,
   17,
   22,
   22,
   22,
   22,
   22,
   22,
   22,
   22,
   22,
   22,
   22,
   22,
   22,
   22,
   18,
   18,
   18,
   18,
   18,
   18,
   17,
   17,
   19,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   27,
   17,
   17,
   17,
   17,
   17,
   17,
   17,
   19,
   21,
   21,
   21,
   21,
   21,
   21,
   21,
   19,
   28,
   29,
   30,
   31,
   32,
   33,
   34,
   35,
   36,
   37,
   38,
   39,
   40,
   41,
   40,
   42,
   43,
   44,
   45,
   46,
   47,
   48,
   49,
   50,
   51,
   52,
   49,
   53,
   54,
   55,
   56,
   57,
   58,
   59,
   60,
   61,
   61,
   62,
   63,
   64,
   65,
   66,
   67,
   68,
   69,
   70,
   70,
   71,
   72,
   73,
   74,
   75,
   76,
   77,
   78,
   79,
   80,
   81,
   82,
   83,
   84,
   85,
   86,
   87,
   88,
   89,
   90,
   91,
   92,
   93,
   94,
   95,
   96,
   97,
   98,
   99,
   100,
   101,
   102,
   103,
   104,
   105,
   106,
   107,
   108,
   108,
   109,
   110,
   111,
   112,
   113,
   114,
   115,
   116,
   31,
   117,
   118,
   118,
   119,
   120,
   121,
   122,
   123,
   123,
   124,
   125,
   126,
   127,
   128,
   129,
   28,
   130,
   131,
   132,
   133,
   134,
   135,
   136,
   137,
   138,
   139,
   140,
   141,
   142,
   143,
   144,
   145,
   146,
   144,
   147,
   148,
   149,
   150,
   151,
   152,
   153,
   154,
   155,
   156,
   157,
   158,
   159,
   160,
   161,
   162,
   163,
   164,
   165,
   31,
   166,
   167,
   168,
   169,
   170,
   171,
   172,
   170,
   173,
   174,
   163,
   175,
   176,
   177,
   177,
   178,
   179,
   180,
   181,
   182,
   183,
   184,
   185,
   121,
   186,
   187,
   188,
   189,
   189,
   190,
   191,
   192,
   193,
   194,
   195,
   196,
   197,
   198,
   17,
   199,
   200,
   201,
   202,
   203,
   204,
   205,
   206,
   207,
   208,
   209,
   210,
   211,
   212,
   213,
   214,
   215,
   216,
   217,
   218,
   219,
   220,
   221,
   222,
   163,
   223,
   224,
   225,
   226,
   227,
   228,
   229,
   230,
   231,
   232,
   233,
   234,
   235,
   236,
   237,
   238,
   239,
   240,
   241,
   242,
   243,
   244,
   245,
   246,
   247,
   248,
   249,
   250,
   251,
   252,
   253,
   254,
   255,
   256,
   257,
   258,
   259,
   260,
   261,
   262,
   263,
   264,
   265,
   266,
   267,
   268,
   269,
   270,
   266,
   269,
   271,
   272,
   273,
   274,
   275,
   276,
   277,
   278,
   279,
   111,
   280,
   281,
   282,
   61,
   283,
   284,
   285,
   286,
   287,
   288,
   289,
   290,
   291,
   292,
   293,
   61,
   294,
   163,
   295,
   121,
   296,
   297,
   298,
   299,
   300,
   301,
   302,
   303,
   304,
   304,
   304,
   61,
   305,
   306,
   307,
   308,
   309,
   310,
   311,
   284,
   312,
   313,
   314,
   315,
   311,
   316,
   317,
   318,
   319,
   320,
   320,
   320,
   313,
   321,
   321,
   321,
   321,
   322,
   323,
   324,
   325,
   326,
   326,
   326,
   327,
   328,
   329,
   330,
   331,
   284,
   332,
   284,
   333,
   334,
   335,
   336,
   61,
   337,
   284,
   338,
   339,
   311,
   340,
   341,
   342,
   311,
   310,
   343,
   344,
   311,
   345,
   284,
   311,
   310,
   346,
   333,
   284,
   311,
   334,
   347,
   348,
   349,
   350,
   350,
   351,
   352,
   313,
   284,
   353,
   310,
   310,
   354,
   310,
   355,
   310,
   162,
   162,
   162,
   162,
   162,
   162,
   162,
   162,
   162,
   162,
   162,
   162,
   356,
   356,
   356,
   356,
   357,
   358,
   359,
   284,
   360,
   361,
   284,
   362,
   363,
   364,
   365,
   53,
   366,
   367,
   368,
   369,
   370,
   371,
   372,
   373,
   374,
   310,
   375,
   376,
   377,
   378,
   371,
   379,
   88,
   380,
   31,
   381,
   382,
   383,
   61,
   384,
   385,
   386,
   387,
   388,
   389,
   390,
   319,
   391,
   384,
   392,
   384,
   393,
   394,
   395,
   396,
   397,
   398,
   28,
   399,
   400,
   393,
   319,
   384,
   401,
   402,
   31,
   403,
   333,
   404,
   405,
   61,
   406,
   407,
   384,
   408,
   409,
   410,
   384,
   411,
   412,
   384,
   413,
   414,
   415,
   416,
   417,
   418,
   419,
   420,
   421,
   422,
   423,
   424,
   384,
   425,
   426,
   427,
   428,
   429,
   28,
   61,
   430,
   431,
   135,
   432,
   433,
   434,
   435,
   18,
   384,
   436,
   437,
   438,
   391,
   439,
   440,
   441,
   442,
   443,
   384,
   135,
   135,
   111,
   444,
   422,
   384,
   445,
   446,
   447,
   448,
   384,
   135,
   449,
   99,
   384,
   135,
   450,
   319,
   409,
   313,
   451,
   312,
   452,
   0 // dummy one
};

const srv_netset_plmn_group_struct plmn_group_index[]=
{
/* Do NOT modify the following line. It is a keyword for the PLMN automatic create tool */
/* PLMN GROUP */
   {0x00f064, 0},
   {0x20f064, 0},
   {0x70f064, 0},
   {0x00f454, 1},
   {0x20f454, 1},
   {0x81f454, 1},
   {0x30f454, 2},
   {0x40f454, 2},
   {0x61f454, 3},
   {0x91f454, 3},
   {0x10f554, 4},
   {0x40f554, 4},
   {0x30f554, 5},
   {0x50f554, 5},
   {0x20f054, 6},
   {0x80f054, 6},
   {0x10f525, 7},
   {0x20f525, 7},
   {0x20f634, 8},
   {0x21f634, 8},
   {0x01f025, 9},
   {0x99f025, 9},
   {0x70f262, 10},
   {0x80f262, 10},
   {0x03f432, 11},
   {0x13f432, 11},
   {0x23f432, 11},
   {0x20f427, 12},
   {0x30f427, 12},
   {0x40f427, 12},
   {0x60f427, 13},
   {0x01f427, 13},
   {0x11f427, 13},
   {0x32f427, 13},
   {0x23f427, 14},
   {0x33f427, 14},
   {0x43f427, 14},
   {0x62f013, 15},
   {0x13f013, 15},
   {0x610013, 15},
   {0x020013, 15},
   {0x120013, 15},
   {0x220013, 15},
   {0x320013, 15},
   {0x420013, 15},
   {0x520013, 15},
   {0x620013, 15},
   {0x720013, 15},
   {0x660013, 15},
   {0x510013, 16},
   {0x710013, 16},
   {0x830013, 16},
   {0x140013, 16},
   {0, 0} // dummy one
};
