
void FUN_005f25f0(void)

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
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  uint local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e0b6;
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
  local_30 = local_30 & 0xffff0000;
  local_1c = 7;
  local_20 = 0;
  psVar6 = psVar8;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  local_14 = uVar5;
  FUN_00402160(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
  local_8._1_3_ = 0;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_8._0_1_ = 0;
  local_6c = 0xc;
  FUN_005740f0(&local_6c);
  if (local_70 == DAT_00fe5ac8) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  FUN_004068f0(uVar5);
  local_8._0_1_ = 2;
  uVar7 = FUN_005f2840();
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_00757800(uVar7);
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  uVar5 = 0;
  local_38 = 7;
  local_3c = 0;
  local_4c = local_4c & 0xffff0000;
  if (7 < local_54) {
    FUN_0089120c(local_68);
  }
  iVar2 = *(int *)(in_ECX + 0x180);
  if (iVar2 != 0) {
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
      goto LAB_005f279c;
    }
  }
  else if (iVar3 != 0) {
    uVar5 = *(uint *)(iVar3 + 0x10);
    goto LAB_005f279c;
  }
  uVar5 = 0;
LAB_005f279c:
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
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

