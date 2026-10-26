
undefined4 * FUN_005e0050(int param_1,undefined4 *param_2)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  short *psVar5;
  short *psVar6;
  undefined4 uVar7;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0091a8e7;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = local_8 & 0xffffff00;
  }
  local_14 = 0x1a8;
  FUN_005740f0(&local_14);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    puVar4 = (undefined4 *)(*pcVar2)();
    return puVar4;
  }
  psVar6 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar6 = *(short **)psVar6;
  }
  param_2[5] = 7;
  param_2[4] = 0;
  *(undefined2 *)param_2 = 0;
  psVar5 = psVar6;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
  local_8 = 0;
  switch(*(undefined4 *)(param_1 + 0x29c)) {
  case 1:
    uVar7 = 0x1a9;
    FUN_00585620(0x1a9,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 2:
    uVar7 = 0x1aa;
    FUN_00585620(0x1aa,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 3:
    uVar7 = 0x1ab;
    FUN_00585620(0x1ab,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 4:
    uVar7 = 0x1ac;
    FUN_00585620(0x1ac,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 5:
    uVar7 = 0x1ad;
    FUN_00585620(0x1ad,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 6:
    uVar7 = 0x1ae;
    FUN_00585620(0x1ae,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 7:
    uVar7 = 0x1af;
    FUN_00585620(0x1af,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 8:
    uVar7 = 0x1b0;
    FUN_00585620(0x1b0,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 9:
    uVar7 = 0x1b1;
    FUN_00585620(0x1b1,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 10:
    uVar7 = 0x1b6;
    FUN_00585620(0x1b6,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 0xb:
    uVar7 = 0x1b7;
    FUN_00585620(0x1b7,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 0xc:
    uVar7 = 0x1b2;
    FUN_00585620(0x1b2,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 0xd:
    uVar7 = 0x1b3;
    FUN_00585620(0x1b3,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 0xe:
    uVar7 = 0x1b4;
    FUN_00585620(0x1b4,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  case 0xf:
    uVar7 = 0x1b5;
    FUN_00585620(0x1b5,uVar3);
    FUN_00585330(uVar7);
    FUN_00404420(param_2);
    break;
  default:
    param_2[4] = 0;
    puVar4 = param_2;
    if (7 < (uint)param_2[5]) {
      puVar4 = (undefined4 *)*param_2;
    }
    *(undefined2 *)puVar4 = 0;
  }
  ExceptionList = local_10;
  return param_2;
}

