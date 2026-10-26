
void FUN_00581090(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b79e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00580fe0(param_1);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  piVar2 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  iVar3 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 8) + 0x38))(0xffffffff,0xffffffff);
  if (iVar3 != 0) {
    (**(code **)(*piVar2 + 0xac))(piVar2,0,0,1,0,0x3f800000,0);
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 8) + 0x3c))();
  }
  iVar3 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0xc) + 0x38))(0xffffffff,0xffffffff);
  if (iVar3 != 0) {
    (**(code **)(*piVar2 + 0xac))(piVar2,0,0,1,0,0x3f800000,0);
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0xc) + 0x3c))();
  }
  ExceptionList = local_10;
  return;
}

