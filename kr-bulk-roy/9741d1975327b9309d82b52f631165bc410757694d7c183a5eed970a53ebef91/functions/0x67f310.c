
void FUN_0067f310(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int in_ECX;
  int *piVar6;
  uint uVar7;
  char cVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 local_5c;
  int local_54;
  int *local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00932cc2;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 0x120) == -1) || (*(int *)(in_ECX + 0x124) == -1)) {
    (**(code **)(**(int **)(in_ECX + 0xf8) + 0x19c))(0xffffffff,0xffffffff,0,0,local_14);
    FUN_00757710();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xf8) + 0x19c))
              (*(undefined4 *)(in_ECX + 0x120),*(undefined4 *)(in_ECX + 0x124),
               *(undefined4 *)(in_ECX + 0x128),*(undefined4 *)(in_ECX + 300));
    FUN_00757800(in_ECX + 0x130);
  }
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  (**(code **)(**(int **)(in_ECX + 0xfc) + 200))();
  local_50 = (int *)(in_ECX + 0x17c);
  bVar2 = false;
  puVar9 = (undefined4 *)(in_ECX + 0x100);
  local_54 = 3;
  do {
    if ((local_50[-1] == -1) || (*local_50 == -1)) {
      (**(code **)(*(int *)*puVar9 + 0x19c))(0xffffffff,0xffffffff,0,0);
      FUN_00757710();
      (**(code **)(*(int *)*puVar9 + 200))();
    }
    else {
      (**(code **)(*(int *)*puVar9 + 0x19c))(local_50[-1],*local_50,local_50[1],local_50[2]);
      FUN_00444090();
      (**(code **)(*(int *)*puVar9 + 200))();
      bVar2 = true;
    }
    local_50 = local_50 + 0x16;
    puVar9 = puVar9 + 1;
    local_54 = local_54 + -1;
  } while (local_54 != 0);
  local_5c = 0;
  if (((*(int *)(in_ECX + 0x120) == -1) || (*(int *)(in_ECX + 0x124) == -1)) || (!bVar2)) {
    (**(code **)(**(int **)(in_ECX + 0x114) + 0x94))(0);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 9;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_54 = 0x1a;
    FUN_005740f0(&local_54);
    if (local_50 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar4 = FUN_004068f0();
    local_8 = 10;
    FUN_00757800(uVar4);
    local_8 = 0xffffffff;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    local_4c = local_4c & 0xffff0000;
    local_38 = 7;
    local_3c = 0;
    (**(code **)(**(int **)(in_ECX + 0x10c) + 200))();
    goto LAB_0067f8e1;
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
  }
  iVar3 = FUN_0051d700(*(undefined4 *)(in_ECX + 0x124));
  if (iVar3 == 0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 6;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_54 = 0x1a;
    FUN_005740f0(&local_54);
    if (local_50 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar4 = FUN_004068f0();
    local_8 = 7;
LAB_0067f6ee:
    FUN_00757800(uVar4);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    (**(code **)(**(int **)(in_ECX + 0x10c) + 200))();
  }
  else {
    if ((DAT_00fe3008 & 1) == 0) {
      DAT_00fe3008 = DAT_00fe3008 | 1;
      local_8 = 1;
      FUN_00513fa0();
      _atexit((_func_4879 *)&LAB_00bcff80);
      local_8 = 0xffffffff;
    }
    iVar3 = FUN_00515630(&DAT_00fe3010,*(undefined4 *)(iVar3 + 0x5c));
    if (iVar3 != 0) {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 2;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      local_54 = 0x1a;
      FUN_005740f0(&local_54);
      if (local_50 == DAT_00fe5ac8) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar4 = FUN_004068f0();
      local_8 = 3;
      goto LAB_0067f6ee;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 4;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_54 = 0x1a;
    FUN_005740f0(&local_54);
    if (local_50 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar4 = FUN_004068f0();
    local_8 = 5;
    FUN_00757800(uVar4);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    (**(code **)(**(int **)(in_ECX + 0x10c) + 200))();
  }
  local_50 = (int *)0x0;
  local_54 = 0;
  piVar6 = (int *)(in_ECX + 0x1a4);
  iVar3 = 3;
  cVar8 = '\x03';
  do {
    if (*piVar6 == 9) {
      local_54 = local_54 + 1;
LAB_0067f754:
      cVar8 = cVar8 + -1;
    }
    else if (*piVar6 == 0xb) {
      local_50 = (int *)((int)local_50 + 1);
      goto LAB_0067f754;
    }
    piVar6 = piVar6 + 0x16;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if ((DAT_00fe3008 & 1) == 0) {
    DAT_00fe3008 = DAT_00fe3008 | 1;
    local_8 = 8;
    FUN_00513fa0();
    _atexit((_func_4879 *)&LAB_00bcff80);
    local_8 = 0xffffffff;
  }
  uVar7 = DAT_00fe3024 - DAT_00fe3020 >> 2;
  uVar10 = 0;
  if (uVar7 != 0) {
    pcVar5 = (char *)(DAT_00fe3020 + 2);
    do {
      if ((((char)local_50 == pcVar5[-2]) && ((char)local_54 == pcVar5[-1])) && (cVar8 == *pcVar5))
      break;
      uVar10 = uVar10 + 1;
      pcVar5 = pcVar5 + 4;
    } while (uVar10 < uVar7);
  }
  FUN_007597b0(0);
  (**(code **)(**(int **)(in_ECX + 0x114) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x114) + 0x94))(1);
  local_5c = 1;
LAB_0067f8e1:
  (**(code **)(**(int **)(in_ECX + 0x110) + 0x90))(local_5c);
  (**(code **)(**(int **)(in_ECX + 0x110) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

