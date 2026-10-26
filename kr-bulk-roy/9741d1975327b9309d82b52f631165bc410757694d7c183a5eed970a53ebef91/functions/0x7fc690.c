
void FUN_007fc690(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x40);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {
    FUN_005366c0(in_ECX + 0x3c);
    if (in_ECX != *(int *)(iVar1 + 4)) {
      if (*(int *)(in_ECX + 0x2c) == 0) {
        *(undefined4 *)(in_ECX + 0x4c) = 0;
      }
      else {
        if (*(int *)(in_ECX + 0x4c) == 0) {
          *(undefined4 *)(in_ECX + 0x4c) = 1;
          FUN_007dbb40(*(undefined4 *)(in_ECX + 0x38),0);
        }
        FUN_007dbb40(*(undefined4 *)(in_ECX + 0x38),param_1);
      }
    }
    iVar1 = *(int *)(in_ECX + 0x34);
    if (iVar1 != 0) {
      if (*(int *)(iVar1 + 0x20) != 0) {
        iVar1 = **(int **)(iVar1 + 0x10);
        uVar2 = FUN_008fed10();
        (**(code **)(iVar1 + 0x1c))(uVar2);
      }
      FUN_007d3bd0(*(undefined4 *)(in_ECX + 0x34));
    }
  }
  return;
}

