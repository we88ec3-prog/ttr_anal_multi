
/* WARNING: Removing unreachable block (ram,0x00660e7d) */
/* WARNING: Removing unreachable block (ram,0x00660e88) */
/* WARNING: Removing unreachable block (ram,0x00660e8e) */
/* WARNING: Removing unreachable block (ram,0x00660e96) */
/* WARNING: Removing unreachable block (ram,0x00660e9a) */
/* WARNING: Removing unreachable block (ram,0x00660ea7) */
/* WARNING: Removing unreachable block (ram,0x00660ead) */

void FUN_00660530(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 uVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d3a6;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x1ac) != -1) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffb8);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (((*(uint *)(in_ECX + 0x1a8) < 10) &&
        (iVar2 = *(uint *)(in_ECX + 0x1a8) * 0x210 + DAT_00f94304, *(int *)(iVar2 + 0x5c) != 0)) &&
       (iVar2 != 0)) {
      switch(*(undefined4 *)(in_ECX + 0x1ac)) {
      case 0:
        puVar1 = *(undefined4 **)(in_ECX + 0x150);
        uVar3 = 0x248;
        FUN_00585620(0x248);
        FUN_00585330(uVar3);
        FUN_00661510(*puVar1);
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x249;
        FUN_00585620(0x249);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 4));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x24a;
        FUN_00585620(0x24a);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 8));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x24b;
        FUN_00585620(0x24b);
        FUN_00585330(uVar3);
        FUN_006618d0(*(undefined4 *)(iVar2 + 0xc));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x24c;
        FUN_00585620(0x24c);
        FUN_00585330(uVar3);
        FUN_00661cb0(*(undefined4 *)(iVar2 + 0x10));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x24d;
        FUN_00585620(0x24d);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0x14));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x24e;
        FUN_00585620(0x24e);
        FUN_00585330(uVar3);
        FUN_006618d0(*(undefined4 *)(iVar2 + 0x18));
        iVar2 = *(int *)(in_ECX + 0x150);
        FUN_008fed10();
        uVar3 = 0x24f;
        FUN_00585620(0x24f);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0x1c));
        ExceptionList = local_14;
        return;
      case 1:
        puVar1 = *(undefined4 **)(in_ECX + 0x150);
        uVar3 = 0x256;
        FUN_00585620(0x256);
        FUN_00585330(uVar3);
        FUN_00661510(*puVar1);
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 599;
        FUN_00585620(599);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 4));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 600;
        FUN_00585620(600);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 8));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x259;
        FUN_00585620(0x259);
        FUN_00585330(uVar3);
        FUN_00662080(*(undefined4 *)(iVar2 + 0xc));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x25a;
        FUN_00585620(0x25a);
        FUN_00585330(uVar3);
        FUN_00662080(*(undefined4 *)(iVar2 + 0x10));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x25b;
        FUN_00585620(0x25b);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0x14));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x25c;
        FUN_00585620(0x25c);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0x18));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x25d;
        FUN_00585620(0x25d);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0x1c));
        ExceptionList = local_14;
        return;
      case 2:
        puVar1 = *(undefined4 **)(in_ECX + 0x150);
        uVar3 = 0x278;
        FUN_00585620(0x278);
        FUN_00585330(uVar3);
        FUN_00661510(*puVar1);
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x279;
        FUN_00585620(0x279);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 4));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x27a;
        FUN_00585620(0x27a);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 8));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x27b;
        FUN_00585620(0x27b);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0xc));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x27c;
        FUN_00585620(0x27c);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0x10));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x27d;
        FUN_00585620(0x27d);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0x14));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x250;
        FUN_00585620(0x250);
        FUN_00585330(uVar3);
        FUN_00661cb0(*(undefined4 *)(iVar2 + 0x18));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x251;
        FUN_00585620(0x251);
        FUN_00585330(uVar3);
        FUN_00661cb0(*(undefined4 *)(iVar2 + 0x1c));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x252;
        FUN_00585620(0x252);
        FUN_00585330(uVar3);
        FUN_00661cb0(*(undefined4 *)(iVar2 + 0x20));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x253;
        FUN_00585620(0x253);
        FUN_00585330(uVar3);
        FUN_00661cb0(*(undefined4 *)(iVar2 + 0x24));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x254;
        FUN_00585620(0x254);
        FUN_00585330(uVar3);
        FUN_00661cb0(*(undefined4 *)(iVar2 + 0x28));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x255;
        FUN_00585620(0x255);
        FUN_00585330(uVar3);
        FUN_00661cb0(*(undefined4 *)(iVar2 + 0x2c));
        ExceptionList = local_14;
        return;
      case 3:
        FUN_00404ba0();
        FUN_00404ba0();
        FUN_00404ba0();
        puVar1 = *(undefined4 **)(in_ECX + 0x150);
        uVar3 = 0x263;
        FUN_00585620(0x263);
        FUN_00585330(uVar3);
        FUN_00661510(*puVar1);
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x264;
        FUN_00585620(0x264);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 4));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x265;
        FUN_00585620(0x265);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 8));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x266;
        FUN_00585620(0x266);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0xc));
        FUN_00404ba0();
        FUN_00404ba0();
        FUN_00404ba0();
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x267;
        FUN_00585620(0x267);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0x10));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x268;
        FUN_00585620(0x268);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0x14));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x269;
        FUN_00585620(0x269);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0x18));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x26a;
        FUN_00585620(0x26a);
        FUN_00585330(uVar3);
        FUN_00661510(*(undefined4 *)(iVar2 + 0x1c));
        ExceptionList = local_14;
        return;
      case 4:
        FUN_00404ba0();
        local_c = 1;
        FUN_00462840(1);
        puVar1 = *(undefined4 **)(in_ECX + 0x150);
        uVar3 = 0x26b;
        FUN_00585620(0x26b);
        FUN_00585330(uVar3);
        FUN_006618d0(*puVar1);
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x26c;
        FUN_00585620(0x26c);
        FUN_00585330(uVar3);
        FUN_00661cb0(*(undefined4 *)(iVar2 + 4));
        FUN_007838f0();
        ExceptionList = local_14;
        return;
      case 5:
        puVar1 = *(undefined4 **)(in_ECX + 0x150);
        uVar3 = 0x26d;
        FUN_00585620(0x26d);
        FUN_00585330(uVar3);
        FUN_00662440(*puVar1);
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x26e;
        FUN_00585620(0x26e);
        FUN_00585330(uVar3);
        FUN_00662440(*(undefined4 *)(iVar2 + 4));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x26f;
        FUN_00585620(0x26f);
        FUN_00585330(uVar3);
        FUN_00662440(*(undefined4 *)(iVar2 + 8));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x270;
        FUN_00585620(0x270);
        FUN_00585330(uVar3);
        FUN_00662440(*(undefined4 *)(iVar2 + 0xc));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x271;
        FUN_00585620(0x271);
        FUN_00585330(uVar3);
        FUN_00662440(*(undefined4 *)(iVar2 + 0x10));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x272;
        FUN_00585620(0x272);
        FUN_00585330(uVar3);
        FUN_00662440(*(undefined4 *)(iVar2 + 0x14));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x273;
        FUN_00585620(0x273);
        FUN_00585330(uVar3);
        FUN_00662440(*(undefined4 *)(iVar2 + 0x18));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x274;
        FUN_00585620(0x274);
        FUN_00585330(uVar3);
        FUN_00662440(*(undefined4 *)(iVar2 + 0x1c));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x275;
        FUN_00585620(0x275);
        FUN_00585330(uVar3);
        FUN_00662440(*(undefined4 *)(iVar2 + 0x20));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x276;
        FUN_00585620(0x276);
        FUN_00585330(uVar3);
        FUN_00662440(*(undefined4 *)(iVar2 + 0x24));
        iVar2 = *(int *)(in_ECX + 0x150);
        uVar3 = 0x277;
        FUN_00585620(0x277);
        FUN_00585330(uVar3);
        FUN_00662440(*(undefined4 *)(iVar2 + 0x28));
      }
    }
  }
  ExceptionList = local_14;
  return;
}

