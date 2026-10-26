
undefined4 FUN_0047e890(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  void **ppvVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908ab8;
  uVar9 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar3 = (undefined4 *)*puVar2;
  ppvVar7 = &local_10;
  local_10 = ExceptionList;
  while( true ) {
    ExceptionList = ppvVar7;
    if (puVar3 == puVar2) {
      ExceptionList = local_10;
      return 0;
    }
    iVar4 = puVar3[4];
    FUN_0052ced0(&stack0x00000008);
    if (param_1 != *(int *)(iVar4 + 0x38)) break;
    ppvVar7 = ExceptionList;
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x15);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar8 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar8, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar8 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  FUN_007e8a90(&local_20,param_1 + 0x14);
  local_8 = 0;
  if (local_1c - (int)local_20 >> 2 != 0) {
    uVar6 = *local_20;
    FUN_0089120c(local_20,uVar9);
    ExceptionList = local_10;
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db7d("invalid vector<T> subscript");
}

