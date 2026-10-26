
void FUN_00581190(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093387c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = DAT_00fb79e8 & 1;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0xc) + 4) + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(in_ECX + 0x30);
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  if (uVar1 == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  piVar3 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  iVar4 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 8) + 0x38))(0xffffffff,0xffffffff);
  if (iVar4 != 0) {
    (**(code **)(*piVar3 + 0xac))(piVar3,0,0,1,0,0x3f800000,0);
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 8) + 0x3c))();
  }
  iVar4 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0xc) + 0x38))(0xffffffff,0xffffffff);
  if (iVar4 != 0) {
    (**(code **)(*piVar3 + 0xac))(piVar3,0,0,1,0,0x3f800000,0);
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0xc) + 0x3c))();
  }
  if ((DAT_00fb72a4 & 1) == 0) {
    DAT_00fb72a4 = DAT_00fb72a4 | 1;
    local_8 = 1;
    FUN_0049f850();
    _atexit((_func_4879 *)&LAB_00bccfe0);
    local_8 = 0xffffffff;
  }
  FUN_004a03f0(&DAT_00fb72a8,0);
  ExceptionList = local_10;
  return;
}

