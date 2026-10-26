
void FUN_0074f000(void)

{
  int *piVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  
  if (*(int *)(in_ECX + 0x13c4) == 0) {
    FUN_00753890();
  }
  else if (*(int *)(in_ECX + 0x146c) != 0) {
    do {
      piVar1 = (int *)FUN_00542210();
      if ((int *)*piVar1 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)*piVar1;
      }
      uVar2 = (uint)piVar1[2] >> 2;
      if (*(uint *)(iVar3 + 8) <= uVar2) {
        uVar2 = uVar2 - *(uint *)(iVar3 + 8);
      }
      piVar1 = *(int **)(*(int *)(*(int *)(iVar3 + 4) + uVar2 * 4) + (piVar1[2] & 3U) * 4);
      (**(code **)(**(int **)(in_ECX + 0x13c4) + 0x15c))(piVar1);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))(1);
      }
      if (*(int *)(in_ECX + 0x146c) != 0) {
        *(int *)(in_ECX + 0x1468) = *(int *)(in_ECX + 0x1468) + 1;
        if ((uint)(*(int *)(in_ECX + 0x1464) * 4) <= *(uint *)(in_ECX + 0x1468)) {
          *(undefined4 *)(in_ECX + 0x1468) = 0;
        }
        iVar3 = *(int *)(in_ECX + 0x146c) + -1;
        *(int *)(in_ECX + 0x146c) = iVar3;
        if (iVar3 == 0) {
          *(undefined4 *)(in_ECX + 0x1468) = 0;
        }
      }
    } while (*(int *)(in_ECX + 0x146c) != 0);
    return;
  }
  return;
}

