
int * FUN_00539690(int param_1)

{
  char cVar1;
  int **ppiVar2;
  int **ppiVar3;
  uint uVar4;
  int *piVar5;
  int in_ECX;
  uint uVar6;
  uint local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009232be;
  local_10 = ExceptionList;
  uVar6 = 0;
  uVar4 = *(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28) >> 2;
  local_18 = 0xffffffff;
  if (uVar4 != 0) {
    local_14 = *(int **)(in_ECX + 0x28);
    do {
      cVar1 = *(char *)(*local_14 + 10);
      if (cVar1 == '\0') {
LAB_005396ed:
        local_18 = uVar6;
      }
      else {
        if (*(int *)*local_14 == param_1) {
          return *(int **)(*(int *)(in_ECX + 0x28) + uVar6 * 4);
        }
        if (cVar1 == '\0') goto LAB_005396ed;
      }
      local_14 = local_14 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar4);
    if (local_18 != 0xffffffff) {
      piVar5 = *(int **)(*(int *)(in_ECX + 0x28) + local_18 * 4);
      ExceptionList = &local_10;
      goto LAB_005397a5;
    }
  }
  ExceptionList = &local_10;
  piVar5 = (int *)FUN_00891268(0xc,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    *piVar5 = 0;
    piVar5[1] = 0;
    piVar5[2] = 0x10000;
  }
  ppiVar2 = *(int ***)(in_ECX + 0x2c);
  local_14 = piVar5;
  if ((&local_14 < ppiVar2) && (ppiVar3 = *(int ***)(in_ECX + 0x28), ppiVar3 <= &local_14)) {
    if (ppiVar2 == *(int ***)(in_ECX + 0x30)) {
      FUN_004deab0();
    }
    if (*(undefined4 **)(in_ECX + 0x2c) != (undefined4 *)0x0) {
      **(undefined4 **)(in_ECX + 0x2c) =
           *(undefined4 *)(*(int *)(in_ECX + 0x28) + ((int)&local_14 - (int)ppiVar3 >> 2) * 4);
    }
  }
  else {
    if (ppiVar2 == *(int ***)(in_ECX + 0x30)) {
      FUN_004deab0();
    }
    if (*(undefined4 **)(in_ECX + 0x2c) != (undefined4 *)0x0) {
      **(undefined4 **)(in_ECX + 0x2c) = piVar5;
    }
  }
  *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 4;
LAB_005397a5:
  uVar4 = DAT_00faadd4 & 1;
  *piVar5 = param_1;
  *(undefined1 *)((int)piVar5 + 10) = 1;
  if (uVar4 == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4404);
  ExceptionList = local_10;
  return piVar5;
}

