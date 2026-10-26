
void FUN_004f3060(undefined1 param_1,ushort param_2,char param_3)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  undefined2 *unaff_EDI;
  undefined4 uVar7;
  int local_a4 [29];
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091e2e9;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar3 = (uint)param_2;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8 = 0;
  switch(param_1) {
  case 0:
    uVar7 = 0xad;
    break;
  case 1:
    uVar7 = 0x43;
    goto LAB_004f30d3;
  case 2:
    uVar7 = 0x133;
    break;
  case 3:
    uVar7 = 0x134;
    goto LAB_004f30d3;
  case 4:
    uVar7 = 0x135;
    break;
  case 5:
    uVar7 = 0x136;
    goto LAB_004f30d3;
  case 6:
    uVar7 = 0x137;
    break;
  case 7:
    local_a4[0] = uVar3 + 1;
    uVar7 = 0x13b;
    FUN_00585620(0x13b,local_14);
    FUN_00585330(uVar7);
    uVar7 = FUN_004068f0();
    local_8._0_1_ = 1;
    FUN_00402800(uVar7);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004fa440();
    goto LAB_004f3266;
  case 8:
    uVar7 = 0x139;
    goto LAB_004f30d3;
  case 9:
    uVar7 = 0x13a;
    break;
  default:
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 5;
      local_8._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    local_a4[0] = 0x140;
    FUN_005740f0(local_a4);
    if (DAT_00fe5ac8 == 0) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar6 = (short *)0x10;
    if (7 < uRam00000024) {
      psVar6 = psRam00000010;
    }
    psVar5 = psVar6;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
    *(undefined4 *)(unaff_EDI + 10) = 7;
    *(undefined4 *)(unaff_EDI + 8) = 0;
    *unaff_EDI = 0;
    FUN_00402800(local_30);
    if (local_1c < 8) goto LAB_004f33d6;
    goto LAB_004f33ce;
  case 0xb:
    uVar7 = 0x138;
    goto LAB_004f30d3;
  case 0x15:
    local_a4[0] = uVar3 + 1;
    uVar7 = 0x13d;
    FUN_00585620(0x13d,local_14);
    FUN_00585330(uVar7);
    uVar7 = FUN_004068f0();
    local_8._0_1_ = 4;
    FUN_00402800(uVar7);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004fa440();
    goto LAB_004f3266;
  case 0x17:
    local_a4[0] = uVar3 + 1;
    uVar7 = 0x13c;
    FUN_00585620(0x13c,local_14);
    FUN_00585330(uVar7);
    uVar7 = FUN_004068f0();
    local_8._0_1_ = 2;
    FUN_00402800(uVar7);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004fa440();
    goto LAB_004f3266;
  case 0x18:
    local_a4[0] = uVar3 + 1;
    uVar7 = 0x13c;
    FUN_00585620(0x13c,local_14);
    FUN_00585330(uVar7);
    uVar7 = FUN_004068f0();
    local_8._0_1_ = 3;
    FUN_00402800(uVar7);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_004fa440();
    goto LAB_004f3266;
  case 0x1a:
    uVar7 = 0x46;
    break;
  case 0x1b:
    uVar7 = 0x13e;
LAB_004f30d3:
    FUN_00585620(uVar7,local_14);
    FUN_00585330(uVar7);
    goto LAB_004f325f;
  case 0x1c:
    uVar7 = 0x13f;
  }
  FUN_00585620(uVar7,local_14);
  FUN_00585330(uVar7);
LAB_004f325f:
  FUN_0041f490(local_30);
LAB_004f3266:
  if (param_3 == '\0') {
    uVar7 = 0x141;
    FUN_00585620(0x141);
    psVar4 = (short *)FUN_00585330(uVar7);
    psVar6 = psVar4 + 1;
    psVar5 = psVar4;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
LAB_004f32e1:
    FUN_00404300(psVar4,(int)psVar5 - (int)psVar6 >> 1);
  }
  else {
    if (param_3 == '\x01') {
      uVar7 = 0x142;
      FUN_00585620(0x142);
      psVar4 = (short *)FUN_00585330(uVar7);
      psVar6 = psVar4 + 1;
      psVar5 = psVar4;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      goto LAB_004f32e1;
    }
    if (param_3 == '\x02') {
      uVar7 = 0x143;
      FUN_00585620(0x143);
      psVar4 = (short *)FUN_00585330(uVar7);
      psVar6 = psVar4 + 1;
      psVar5 = psVar4;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      goto LAB_004f32e1;
    }
  }
  *(undefined4 *)(unaff_EDI + 10) = 7;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  *unaff_EDI = 0;
  FUN_00402800(local_30);
  if (7 < local_1c) {
LAB_004f33ce:
    FUN_0089120c(local_30[0]);
  }
LAB_004f33d6:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

