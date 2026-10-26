
void FUN_004845a0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0x3ed) {
    if (uVar1 == 0x3ec) {
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
        (**(code **)(**(int **)(in_ECX + 0x108) + 0x90))(0);
        (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
        return;
      }
    }
    else if (uVar1 == 0x3ea) {
      iVar2 = *(int *)(param_1 + 8);
      if ((((iVar2 == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) ||
           (iVar2 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20))) ||
          (iVar2 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20))) ||
         (iVar2 == *(int *)(*(int *)(in_ECX + 0x100) + 0x20))) {
        iVar2 = *(int *)(in_ECX + 0x24);
        *(undefined4 *)(iVar2 + 0x13dc) = 0;
        *(undefined1 *)(iVar2 + 0x13d9) = 1;
        return;
      }
    }
    else if (uVar1 == 0x3eb) {
      iVar2 = *(int *)(param_1 + 8);
      iVar3 = *(int *)(in_ECX + 0xf4);
      if (iVar2 == *(int *)(iVar3 + 0x20)) {
        iVar2 = *(int *)(in_ECX + 0x24);
        *(int *)(iVar2 + 0x13dc) = *(int *)(in_ECX + 0xf8);
        *(undefined1 *)(iVar2 + 0x13d9) = 1;
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
        iVar2 = *(int *)(in_ECX + 0x24);
        *(undefined4 *)(iVar2 + 0x13dc) = *(undefined4 *)(in_ECX + 0xfc);
        *(undefined1 *)(iVar2 + 0x13d9) = 1;
      }
      else {
        if (iVar2 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
          iVar2 = *(int *)(in_ECX + 0x24);
          *(undefined4 *)(iVar2 + 0x13dc) = *(undefined4 *)(in_ECX + 0x100);
          *(undefined1 *)(iVar2 + 0x13d9) = 1;
          return;
        }
        if (iVar2 == *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
          iVar2 = *(int *)(in_ECX + 0x24);
          *(undefined1 *)(iVar2 + 0x13d9) = 1;
          *(int *)(iVar2 + 0x13dc) = iVar3;
          return;
        }
      }
    }
  }
  else if (uVar1 == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
      FUN_00484920();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
      FUN_00484740();
      return;
    }
  }
  return;
}

