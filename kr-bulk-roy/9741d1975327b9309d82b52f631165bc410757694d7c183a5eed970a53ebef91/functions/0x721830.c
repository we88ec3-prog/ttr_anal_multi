
undefined4 FUN_00721830(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int local_20 [3];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00935621;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  FUN_007215b0(local_20,param_3);
  local_8 = 1;
  FUN_007218e0(local_20);
  local_8 = local_8 & 0xffffff00;
  local_14 = 1;
  if (local_20[0] != 0) {
    iVar1 = **(int **)(local_20[0] + 4);
    piVar3 = *(int **)(local_20[0] + 4);
    while (iVar1 != 0) {
      piVar2 = (int *)*piVar3;
      (*(code *)PTR_FUN_00d63d4c)(piVar3,uVar4);
      piVar3 = piVar2;
      iVar1 = *piVar2;
    }
    (*(code *)PTR_FUN_00d63d4c)(local_20[0]);
  }
  ExceptionList = local_10;
  return param_2;
}

