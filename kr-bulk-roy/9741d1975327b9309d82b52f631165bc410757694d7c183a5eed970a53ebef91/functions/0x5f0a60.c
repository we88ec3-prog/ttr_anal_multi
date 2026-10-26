
void FUN_005f0a60(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  short *psVar6;
  undefined4 uVar7;
  int in_ECX;
  short *psVar8;
  int iVar9;
  undefined4 ***pppuVar10;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e0fe;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  psVar8 = *(short **)(in_ECX + 0x180);
  if (psVar8 == (short *)0x0) {
    iVar2 = *(int *)(in_ECX + 0x184);
    if (*(uint *)(iVar2 + 0xac) < 8) {
      psVar8 = (short *)(iVar2 + 0x98);
    }
    else {
      psVar8 = *(short **)(iVar2 + 0x98);
    }
  }
  else if (7 < *(uint *)(psVar8 + 10)) {
    psVar8 = *(short **)psVar8;
  }
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  psVar6 = psVar8;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  local_14 = uVar5;
  FUN_00402160(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if ((*(int *)(in_ECX + 0x180) == 0) || (*(int *)(*(int *)(in_ECX + 0x180) + 0x40) == 0)) {
    pppuVar10 = (undefined4 ***)local_30[0];
    if (local_1c < 8) {
      pppuVar10 = local_30;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8._0_1_ = 0;
    local_54 = 0x18;
    FUN_005740f0(&local_54);
    if (local_50 == DAT_00fe5ac8) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    uVar7 = FUN_00483f00(pppuVar10,uVar5);
    local_8._0_1_ = 2;
    FUN_00757800(uVar7);
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  else {
    FUN_00757800(local_30);
  }
  iVar2 = *(int *)(in_ECX + 0x180);
  if (iVar2 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (uint)*(byte *)(iVar2 + 0x4c);
  }
  iVar3 = *(int *)(in_ECX + 0x188);
  if (iVar3 == 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = *(int *)(iVar3 + 0x10);
  }
  if (iVar9 < (int)uVar5) {
    if (iVar2 != 0) {
      uVar5 = (uint)*(byte *)(iVar2 + 0x4c);
      goto LAB_005f0c0d;
    }
  }
  else if (iVar3 != 0) {
    uVar5 = *(uint *)(iVar3 + 0x10);
    goto LAB_005f0c0d;
  }
  uVar5 = 0;
LAB_005f0c0d:
  if (*(int *)(*(int *)(in_ECX + 0x184) + 8) == 0xf) {
    uVar7 = 0xffcccccc;
  }
  else {
    switch(uVar5) {
    case 0:
      uVar7 = 0xffffffff;
      break;
    case 1:
      uVar7 = 0xffffff00;
      break;
    case 2:
      uVar7 = 0xff5aff78;
      break;
    case 3:
      uVar7 = 0xff00bbdd;
      break;
    case 4:
      uVar7 = 0xffe243ff;
      break;
    case 5:
      uVar7 = 0xffb41010;
      break;
    default:
      uVar7 = 0xff6600;
    }
  }
  *(undefined4 *)(*(int *)(in_ECX + 400) + 0x154) = uVar7;
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

