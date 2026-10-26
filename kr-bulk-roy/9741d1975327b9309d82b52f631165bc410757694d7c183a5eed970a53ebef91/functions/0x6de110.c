
uint FUN_006de110(int *param_1,char param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f418;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) {
    if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x3c) != 0) {
      FUN_006de0c0();
    }
    if ((param_2 == '\0') && ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 1) != 0)) {
      uVar2 = FUN_004318d0(&param_2);
      local_8 = 0;
      iVar3 = FUN_006de510(uVar2);
      FUN_004327c0();
      local_8 = 1;
      piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
      if ((*(int *)piVar1[8] == 0) || (*(int *)piVar1[0xc] < 1)) {
        uVar4 = (**(code **)(*piVar1 + 0x18))();
      }
      else {
        uVar4 = (uint)**(byte **)piVar1[8];
      }
      while( true ) {
        if (uVar4 == 0xffffffff) {
          FUN_00431a90(0);
          local_8 = 0xffffffff;
          uVar4 = FUN_006de251();
          return uVar4;
        }
        if ((*(byte *)(*(int *)(iVar3 + 0x10) + (uVar4 & 0xff) * 2) & 0x48) == 0) break;
        uVar4 = FUN_006de6d0();
      }
      local_8 = 0xffffffff;
      uVar4 = FUN_006de251();
      return uVar4;
    }
    if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) == 0) {
      ExceptionList = local_10;
      return CONCAT31((int3)((uint)*param_1 >> 8),1);
    }
  }
  uVar4 = FUN_00431a90(0);
  ExceptionList = local_10;
  return uVar4 & 0xffffff00;
}

