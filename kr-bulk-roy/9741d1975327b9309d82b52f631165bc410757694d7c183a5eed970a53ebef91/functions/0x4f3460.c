
void FUN_004f3460(undefined1 param_1,ushort param_2)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  undefined2 *unaff_EDI;
  undefined4 uVar6;
  int local_90;
  int local_88 [29];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0091e280;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar3 = (uint)param_2;
  *(undefined4 *)(unaff_EDI + 10) = 7;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  *unaff_EDI = 0;
  local_8 = 0;
  switch(param_1) {
  case 0:
    uVar6 = 0xad;
    FUN_00585620(0xad,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  case 1:
    uVar6 = 0x43;
    FUN_00585620(0x43,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  case 2:
    uVar6 = 0x133;
    FUN_00585620(0x133,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  case 3:
    uVar6 = 0x134;
    FUN_00585620(0x134,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  case 4:
    uVar6 = 0x135;
    FUN_00585620(0x135,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  case 5:
    uVar6 = 0x136;
    FUN_00585620(0x136,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  case 6:
    uVar6 = 0x137;
    FUN_00585620(0x137,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  case 7:
    local_88[0] = uVar3 + 1;
    uVar6 = 0x13b;
    FUN_00585620(0x13b,local_14);
    FUN_00585330(uVar6);
    uVar6 = FUN_004068f0();
    local_8 = 1;
    FUN_00402800(uVar6);
    FUN_004fa440();
    break;
  case 8:
    uVar6 = 0x139;
    FUN_00585620(0x139,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  case 9:
    uVar6 = 0x13a;
    FUN_00585620(0x13a,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  default:
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 5;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = local_8 & 0xffffff00;
    }
    local_88[0] = 0x140;
    FUN_005740f0(local_88);
    if (local_90 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)(local_90 + 0x10);
    if (7 < *(uint *)(local_90 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    psVar4 = psVar5;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
    break;
  case 0xb:
    uVar6 = 0x138;
    FUN_00585620(0x138,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  case 0x15:
    local_88[0] = uVar3 + 1;
    uVar6 = 0x13d;
    FUN_00585620(0x13d,local_14);
    FUN_00585330(uVar6);
    uVar6 = FUN_004068f0();
    local_8 = 2;
    FUN_00402800(uVar6);
    FUN_004fa440();
    break;
  case 0x17:
    local_88[0] = uVar3 + 1;
    uVar6 = 0x13c;
    FUN_00585620(0x13c,local_14);
    FUN_00585330(uVar6);
    uVar6 = FUN_004068f0();
    local_8 = 3;
    FUN_00402800(uVar6);
    FUN_004fa440();
    break;
  case 0x18:
    local_88[0] = uVar3 + 1;
    uVar6 = 0x13c;
    FUN_00585620(0x13c,local_14);
    FUN_00585330(uVar6);
    uVar6 = FUN_004068f0();
    local_8 = 4;
    FUN_00402800(uVar6);
    FUN_004fa440();
    break;
  case 0x1a:
    uVar6 = 0x46;
    FUN_00585620(0x46,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  case 0x1b:
    uVar6 = 0x13e;
    FUN_00585620(0x13e,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
    break;
  case 0x1c:
    uVar6 = 0x13f;
    FUN_00585620(0x13f,local_14);
    FUN_00585330(uVar6);
    FUN_0041f490(unaff_EDI);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

