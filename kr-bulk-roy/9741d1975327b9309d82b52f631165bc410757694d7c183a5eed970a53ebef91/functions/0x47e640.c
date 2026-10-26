
undefined4 FUN_0047e640(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  void **ppvVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar4 = (int)param_3;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908ab8;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (param_2 == 0) {
    return 0;
  }
  puVar1 = *(undefined4 **)(param_1 + 4);
  param_3 = (undefined4 *)*puVar1;
  ppvVar5 = &local_10;
  local_10 = ExceptionList;
  while( true ) {
    ExceptionList = ppvVar5;
    if (param_3 == puVar1) {
      ExceptionList = local_10;
      return 0;
    }
    iVar2 = param_3[4];
    FUN_0052ced0(&param_2);
    if (param_1 != *(int *)(iVar2 + 0x38)) break;
    FUN_0049e6a0();
    ppvVar5 = ExceptionList;
  }
  FUN_007e8a90(&local_20,param_1 + 0x14);
  local_8 = 0;
  uVar8 = local_1c - local_20 >> 2;
  uVar7 = 0;
  if (uVar8 != 1) {
    do {
      if (uVar8 <= uVar7) {
LAB_0047e716:
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      if (iVar4 == *(int *)(local_20 + uVar7 * 4)) {
        if (uVar7 + 1 < uVar8) {
          uVar3 = *(undefined4 *)(local_20 + (uVar7 + 1) * 4);
          if (local_20 != 0) {
            FUN_0089120c(local_20,uVar6);
          }
          ExceptionList = local_10;
          return uVar3;
        }
        goto LAB_0047e716;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar8 - 1);
  }
  if (local_20 != 0) {
    FUN_0089120c(local_20,uVar6);
  }
  ExceptionList = local_10;
  return 0;
}

