
void FUN_00403b10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  FUN_00744ca0(param_1);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0xcb) {
    iVar1 = *in_ECX;
    uVar2 = (**(code **)(iVar1 + 0x1a0))();
    (**(code **)(iVar1 + 0x50))(uVar2);
    return;
  }
  if (iVar1 == 0xcc) {
    (**(code **)(*in_ECX + 0x54))();
    return;
  }
  if (iVar1 == 100) {
    iVar1 = *(int *)(in_ECX[9] + 0x3d4);
    if ((((iVar1 == 1) || (iVar1 == 2)) || (iVar1 = *(int *)(in_ECX[9] + 0x404), iVar1 == 1)) ||
       (iVar1 == 2)) {
      FUN_00403b90();
    }
  }
  return;
}

