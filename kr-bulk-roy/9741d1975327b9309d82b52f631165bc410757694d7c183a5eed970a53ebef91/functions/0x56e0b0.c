
/* WARNING: Removing unreachable block (ram,0x0056e16a) */
/* WARNING: Removing unreachable block (ram,0x0056e170) */

void FUN_0056e0b0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00921d69;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = param_1 + 0x15;
  local_8 = 3;
  FUN_0056fb70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 4;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8 = CONCAT31(local_8._1_3_,3);
  }
  local_14 = param_1[0x1c];
  FUN_00736180(&local_14);
  if ((local_18 != DAT_00fb7b80) &&
     (iVar3 = (**(code **)(*DAT_00fb7b78 + 0x2c))(*(undefined4 *)(local_18 + 0xc)), iVar3 != 0)) {
    FUN_00735ed0(&DAT_00fb7b7c,&local_18,local_18);
  }
  if (param_1[0x1d] != param_1[0x1e]) {
    param_1[0x1e] = param_1[0x1d];
  }
  if ((undefined4 *)param_1[0x18] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x18])(1);
    param_1[0x18] = 0;
  }
  if (param_1[0x1d] != 0) {
    FUN_0089120c(param_1[0x1d]);
  }
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  piVar2 = (int *)*piVar1;
  piVar4 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(int *)(*piVar1 + 4) = *piVar1;
  param_1[0x16] = 0;
  if (piVar4 != (int *)*piVar1) {
    do {
      piVar2 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar2;
    } while (piVar2 != (int *)*piVar1);
  }
  FUN_0089120c(*piVar1);
  local_8 = local_8 & 0xffffff00;
  FUN_0056fc70(param_1 + 8);
  if (0xf < (uint)param_1[5]) {
    FUN_0089120c(*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  ExceptionList = local_10;
  return;
}

