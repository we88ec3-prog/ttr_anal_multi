
void FUN_0062e490(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  code *pcVar5;
  uint *puVar6;
  undefined4 *puVar7;
  short *psVar8;
  undefined4 uVar9;
  uint local_58 [4];
  undefined4 local_48;
  uint local_44;
  int local_3c;
  uint local_38;
  uint *local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00948cce;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 0;
    FUN_004ffe60(uVar1);
    _atexit((_func_4879 *)&LAB_00bccf00);
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_00500fd0(&DAT_00fab2a0);
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 1;
    FUN_004ffe60(uVar1);
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
  }
  local_38 = FUN_005013a0(&DAT_00fab2a0);
  local_38 = local_38 & 0xffff;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 2;
    FUN_004ffe60(uVar1);
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
  }
  iVar4 = DAT_00fb114c;
  local_34 = (uint *)(uVar2 & 0xffff);
  FUN_00503d20(&local_34);
  if (local_3c == *(int *)(iVar4 + 4)) {
    local_34 = (uint *)0x0;
  }
  else {
    local_34 = (uint *)(local_3c + 0x10);
  }
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 3;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
    iVar4 = DAT_00fb114c;
  }
  FUN_00503d20(&local_38);
  if (local_3c == *(int *)(iVar4 + 4)) {
    iVar4 = 0;
  }
  else {
    iVar4 = local_3c + 0x10;
  }
  if (local_34 == (uint *)0x0) {
    if (iVar4 == 0) {
      FUN_00757710();
    }
    else {
      local_34 = (uint *)(iVar4 + 0x4c);
      if (7 < *(uint *)(iVar4 + 0x60)) {
        local_34 = (uint *)*local_34;
      }
      local_38 = 0x157;
      iVar4 = FUN_00585620();
      FUN_005740f0(&local_38);
      if (local_3c == *(int *)(iVar4 + 4)) {
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
      FUN_00483f00(local_34);
      iVar4 = *(int *)(param_1 + 0x108);
      local_8 = 5;
      FUN_007578f0();
      FUN_00759ed0(iVar4 + 0xe8,local_58,0x7b,0x7d);
      local_8 = 0xffffffff;
      if (7 < local_44) {
        FUN_0089120c(local_58[0]);
      }
    }
    (**(code **)(**(int **)(param_1 + 0x108) + 200))();
  }
  else {
    puVar6 = local_34 + 0x13;
    if (7 < local_34[0x18]) {
      puVar6 = (uint *)*puVar6;
    }
    local_44 = 7;
    local_48 = 0;
    local_58[0] = local_58[0] & 0xffff0000;
    puVar3 = puVar6;
    do {
      uVar1 = *puVar3;
      puVar3 = (uint *)((int)puVar3 + 2);
    } while ((short)uVar1 != 0);
    FUN_00402160(puVar6,(int)puVar3 - (int)((int)puVar6 + 2) >> 1);
    iVar4 = *(int *)(param_1 + 0x108);
    local_8 = 4;
    FUN_007578f0();
    FUN_00759ed0(iVar4 + 0xe8,local_58,0x7b,0x7d);
    local_8 = 0xffffffff;
    if (7 < local_44) {
      FUN_0089120c(local_58[0]);
    }
    (**(code **)(**(int **)(param_1 + 0x108) + 200))();
  }
  iVar4 = *(int *)(param_1 + 0xf4);
  if (iVar4 == 0) {
    FUN_0062f640(param_1);
  }
  else if (iVar4 == 1) {
    FUN_0062f4c0(param_1);
  }
  else if (iVar4 == 2) {
    FUN_0062f580(param_1);
  }
  FUN_0062f1f0();
  if ((*(uint *)(*(int *)(param_1 + 0x124) + 0x28) >> 8 & 1) == 0) {
    if ((*(uint *)(*(int *)(param_1 + 0x128) + 0x28) >> 8 & 1) != 0) {
      FUN_006340e0();
    }
  }
  else {
    puVar7 = *(undefined4 **)(param_1 + 0x114);
    uVar1 = *(int *)(param_1 + 0x118) - (int)puVar7 >> 2;
    uVar2 = 0;
    if (uVar1 != 0) {
      do {
        if (*(int *)(*(int *)(param_1 + 0x124) + 0xfc) == *(int *)*puVar7) goto LAB_0062e7ed;
        uVar2 = uVar2 + 1;
        puVar7 = puVar7 + 1;
      } while (uVar2 < uVar1);
    }
    (**(code **)(**(int **)(param_1 + 0x124) + 0xd4))();
  }
LAB_0062e7ed:
  local_34 = (uint *)0x0;
  psVar8 = &DAT_00fb1170;
  do {
    if ((DAT_00fab29c & 1) == 0) {
      DAT_00fab29c = DAT_00fab29c | 1;
      local_8 = 6;
      FUN_004ffe60();
      _atexit((_func_4879 *)&LAB_00bccf00);
      local_8 = 0xffffffff;
    }
    if (*psVar8 != 0) {
      local_34 = (uint *)((int)local_34 + 1);
    }
    psVar8 = psVar8 + 1;
  } while ((int)psVar8 < 0xfb1198);
  iVar4 = *(int *)(param_1 + 0xf4);
  if ((iVar4 == 1) || (iVar4 == 2)) {
    pcVar5 = *(code **)(**(int **)(param_1 + 0x100) + 0x90);
    uVar9 = 0;
LAB_0062e885:
    (*pcVar5)(uVar9);
    uVar9 = 1;
  }
  else {
    if (iVar4 != 0) goto LAB_0062e899;
    pcVar5 = *(code **)(**(int **)(param_1 + 0x100) + 0x90);
    if (local_34 != (uint *)0x0) {
      uVar9 = 1;
      goto LAB_0062e885;
    }
    (*pcVar5)(0);
    uVar9 = 0;
  }
  (**(code **)(**(int **)(param_1 + 0xfc) + 0x90))(uVar9);
LAB_0062e899:
  uVar9 = FUN_0040e460(&DAT_00bf2bf8);
  local_8 = 7;
  FUN_00757800(uVar9);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  local_30 = local_30 & 0xffff0000;
  local_1c = 7;
  local_20 = 0;
  (**(code **)(**(int **)(param_1 + 300) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

