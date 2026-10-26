
void FUN_006b38a0(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  uint local_18;
  byte *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092c22a;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb7324 & 1) == 0) {
    DAT_00fb7324 = DAT_00fb7324 | 1;
    local_8 = 0;
    FUN_0081b920(uVar3);
    _atexit((_func_4879 *)&LAB_00bcd080);
  }
  local_8 = 0xffffffff;
  pbVar4 = (byte *)FUN_0081bb60(&param_1);
  local_14 = pbVar4;
  if (pbVar4 == (byte *)0x0) {
    iVar5 = *(int *)(in_ECX + 0x8c);
    if (((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) &&
       (iVar6 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar6 == 0xbf6b)) {
      iVar5 = *(int *)(iVar5 + 0x94);
      iVar6 = *(int *)(iVar5 + 0x10);
      if (iVar6 != 0) {
        piVar2 = *(int **)(iVar6 + 8);
        if (piVar2 != (int *)0x0) {
          piVar1 = piVar2 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar2 + 0x28))();
          }
        }
        *(undefined4 *)(iVar5 + 0x10) = 0;
      }
    }
    FUN_00757710();
  }
  else {
    if ((DAT_00fb7324 & 1) == 0) {
      DAT_00fb7324 = DAT_00fb7324 | 1;
      local_8 = 1;
      FUN_0081b920(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd080);
      local_8 = 0xffffffff;
    }
    param_1._3_1_ = FUN_0081c9e0(&param_1);
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 2;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    local_18 = (uint)*pbVar4;
    FUN_0082ef00(&local_18);
    iVar5 = *(int *)(in_ECX + 0x8c);
    if (((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) &&
       (iVar5 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
      FUN_0077b200();
    }
    FUN_00757710();
  }
  FUN_00757710();
  FUN_00757710();
  (**(code **)(**(int **)(in_ECX + 0x8c) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x90) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x84) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x88) + 200))();
  ExceptionList = local_10;
  return;
}

