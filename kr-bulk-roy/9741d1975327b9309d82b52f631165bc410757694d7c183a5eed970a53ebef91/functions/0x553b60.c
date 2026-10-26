
void FUN_00553b60(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_c;
  
  switch(*(undefined4 *)(in_ECX + 0x34)) {
  case 0:
    *(undefined4 *)(in_ECX + 0x14) = 0;
    return;
  case 1:
    if (0 < *(int *)(in_ECX + 0x24)) {
      *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + -1;
      return;
    }
    *(undefined4 *)(in_ECX + 0x34) = 2;
  case 2:
    if (*(int *)(in_ECX + 0x28) < 1) {
      *(undefined1 *)(in_ECX + 0x38) = 0xff;
      *(undefined4 *)(in_ECX + 0x34) = 3;
      return;
    }
    iVar1 = *(int *)(in_ECX + 0x28) + -1;
    *(int *)(in_ECX + 0x28) = iVar1;
    local_c = (undefined1)
              (int)ROUND(255.0 - ((double)iVar1 / (double)*(int *)(in_ECX + 0x1c)) * 255.0);
    *(undefined1 *)(in_ECX + 0x38) = local_c;
    return;
  case 3:
    iVar1 = *(int *)(in_ECX + 0x30);
    if (0 < iVar1) {
      *(int *)(in_ECX + 0x30) = iVar1 + -1;
      return;
    }
    if (iVar1 == 0) {
      *(undefined4 *)(in_ECX + 0x34) = 4;
      return;
    }
    break;
  case 4:
    if (0 < *(int *)(in_ECX + 0x2c)) {
      iVar1 = *(int *)(in_ECX + 0x2c) + -1;
      *(int *)(in_ECX + 0x2c) = iVar1;
      local_c = (undefined1)(int)ROUND(((double)iVar1 / (double)*(int *)(in_ECX + 0x20)) * 255.0);
      *(undefined1 *)(in_ECX + 0x38) = local_c;
      return;
    }
    *(undefined1 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 0;
  }
  return;
}

