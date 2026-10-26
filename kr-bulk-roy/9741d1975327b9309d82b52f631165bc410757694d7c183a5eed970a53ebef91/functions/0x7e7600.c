
void FUN_007e7600(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cb15;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_008380b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  FUN_007f74f0(*(undefined4 *)(in_ECX + 0x24));
  iVar1 = *(int *)(in_ECX + 0x24);
  piVar2 = *(int **)(iVar1 + 8);
  local_14 = 0;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x2c))(piVar2,0,0,&local_14,0x2000);
    uVar3 = FUN_007ffbc0(0,local_14);
    *(undefined4 *)(iVar1 + 0x10) = uVar3;
    (**(code **)(**(int **)(iVar1 + 8) + 0x30))(*(int **)(iVar1 + 8));
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  FUN_00837fd0();
  PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
  ExceptionList = local_10;
  return;
}

