
void FUN_00579ec0(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *_Str2;
  uint uVar5;
  int **ppiVar6;
  int in_ECX;
  int *_MaxCount;
  char ****ppppcVar7;
  int *local_58;
  int *local_54;
  int *local_50;
  char ***local_4c [4];
  int *local_3c;
  uint local_38;
  char ***local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091fbd6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x70) = 1;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  *(undefined4 *)(in_ECX + 0x94) = 0;
  *(undefined4 *)(in_ECX + 200) = 0;
  if (param_1 == 0) {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
    FUN_0040b310("LUCKYBOX_OPENBOX");
    local_8 = 0;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    piVar3 = (int *)FUN_0080ab00(&DAT_00fab028);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x14))();
    }
    local_8 = 0xffffffff;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x10) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 200) = 0xc;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x10) = 0xffffffff;
    FUN_006df330(local_14);
    FUN_007b6d70();
  }
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0x41a00000;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0x41a00000;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0x41a00000;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0xe4) = 0x43c80000;
  *(undefined4 *)(in_ECX + 0xe8) = 0x42c80000;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  FUN_0040b310("StartButton");
  local_8 = 2;
  local_54 = *(int **)(in_ECX + 8);
  piVar3 = (int *)*local_54;
  local_50 = piVar3;
  local_58 = (int *)FUN_006cf160(local_30);
  uVar5 = local_20;
  if (local_58 == (int *)piVar3[1]) {
LAB_0057a0c6:
    local_50 = (int *)piVar3[1];
    ppiVar6 = &local_50;
  }
  else {
    uVar1 = local_58[7];
    piVar3 = local_58 + 3;
    if (0xf < (uint)local_58[8]) {
      piVar3 = (int *)*piVar3;
    }
    uVar4 = local_20;
    if (uVar1 <= local_20) {
      uVar4 = uVar1;
    }
    ppppcVar7 = (char ****)local_30[0];
    if (local_1c < 0x10) {
      ppppcVar7 = local_30;
    }
    uVar4 = __strnicmp((char *)ppppcVar7,(char *)piVar3,uVar4);
    if (uVar4 == 0) {
      if (uVar5 < uVar1) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar5 != uVar1);
      }
    }
    piVar3 = local_50;
    if ((int)uVar4 < 0) goto LAB_0057a0c6;
    ppiVar6 = &local_58;
  }
  if (*ppiVar6 != *(int **)(*local_54 + 4)) {
    *(undefined4 *)((*ppiVar6)[10] + 0x48) = 1;
  }
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_38 = 0xf;
  local_3c = (int *)0x0;
  local_4c[0] = (char ***)((uint)local_4c[0] & 0xffffff00);
  FUN_0040b310("StopButton");
  local_8 = 3;
  local_58 = *(int **)(in_ECX + 8);
  iVar2 = *local_58;
  local_50 = (int *)FUN_006cf160(local_4c);
  if (local_50 != *(int **)(iVar2 + 4)) {
    piVar3 = (int *)local_50[7];
    _Str2 = local_50 + 3;
    if (0xf < (uint)local_50[8]) {
      _Str2 = (int *)*_Str2;
    }
    local_54 = local_3c;
    _MaxCount = local_3c;
    if (piVar3 <= local_3c) {
      _MaxCount = piVar3;
    }
    ppppcVar7 = (char ****)local_4c[0];
    if (local_38 < 0x10) {
      ppppcVar7 = local_4c;
    }
    uVar5 = __strnicmp((char *)ppppcVar7,(char *)_Str2,(size_t)_MaxCount);
    if (uVar5 == 0) {
      if (local_54 < piVar3) goto LAB_0057a18d;
      uVar5 = (uint)(local_54 != piVar3);
    }
    if (-1 < (int)uVar5) {
      ppiVar6 = &local_50;
      goto LAB_0057a196;
    }
  }
LAB_0057a18d:
  local_54 = *(int **)(iVar2 + 4);
  ppiVar6 = &local_54;
LAB_0057a196:
  if (*ppiVar6 != *(int **)(*local_58 + 4)) {
    *(undefined4 *)((*ppiVar6)[10] + 0x48) = 0;
  }
  if (0xf < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

