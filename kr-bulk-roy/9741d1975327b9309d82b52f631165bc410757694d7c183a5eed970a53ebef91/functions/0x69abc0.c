
void FUN_0069abc0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar3 = param_2;
  puStack_c = &LAB_0092b49e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  iVar4 = FUN_0051d700(*piVar3);
  uVar6 = 0;
  uVar5 = *(int *)(param_1 + 0x168) - *(int *)(param_1 + 0x164) >> 2;
  if (uVar5 != 0) {
    do {
      if ((*(int *)(iVar4 + 8) == 0x1e) &&
         (**(int **)(*(int *)(param_1 + 0x164) + uVar6 * 4) == *piVar3)) {
        *(int **)(*(int *)(param_1 + 0x164) + uVar6 * 4) = piVar3;
        goto LAB_0069acfa;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar5);
  }
  puVar1 = *(undefined4 **)(param_1 + 0x168);
  if ((&param_2 < puVar1) && (puVar2 = *(undefined4 **)(param_1 + 0x164), puVar2 <= &param_2)) {
    if (puVar1 == *(undefined4 **)(param_1 + 0x16c)) {
      FUN_004deab0();
    }
    if (*(undefined4 **)(param_1 + 0x168) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x168) =
           *(undefined4 *)(*(int *)(param_1 + 0x164) + ((int)&param_2 - (int)puVar2 >> 2) * 4);
    }
  }
  else {
    if (puVar1 == *(undefined4 **)(param_1 + 0x16c)) {
      FUN_004deab0();
    }
    if (*(undefined4 **)(param_1 + 0x168) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x168) = piVar3;
    }
  }
  *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 4;
  (**(code **)(**(int **)(param_1 + 0xbc) + 0x90))
            (*(int *)(param_1 + 0x164) != *(int *)(param_1 + 0x168));
LAB_0069acfa:
  FUN_0069a050(param_1);
  ExceptionList = local_10;
  return;
}

