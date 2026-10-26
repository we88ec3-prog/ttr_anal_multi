
void FUN_00778660(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  *(undefined4 *)(in_ECX + 0x2dc) = param_1;
  *(undefined4 *)(in_ECX + 0x2e0) = param_2;
  *(undefined4 *)(in_ECX + 0x2e4) = param_3;
  *(undefined4 *)(in_ECX + 0x2e8) = param_4;
  if (*(int *)(in_ECX + 8) != 0) {
    uVar3 = 0;
    piVar4 = (int *)(in_ECX + 600);
    do {
      if (uVar3 / 3 == 0) {
        piVar4[-2] = 0;
        iVar1 = *(int *)(in_ECX + 0x2e0);
      }
      else {
        if (uVar3 / 3 == 1) {
          piVar4[-2] = *(int *)(in_ECX + 0x2e0);
          iVar2 = *(int *)(in_ECX + 8);
          iVar1 = *(int *)(iVar2 + 0x14) - *(int *)(in_ECX + 0x2e8);
        }
        else {
          piVar4[-2] = (*(int *)(*(int *)(in_ECX + 8) + 0x14) - *(int *)(in_ECX + 0x2e8)) -
                       *(int *)(*(int *)(in_ECX + 8) + 0xc);
          iVar2 = *(int *)(in_ECX + 8);
          iVar1 = *(int *)(iVar2 + 0x14);
        }
        iVar1 = iVar1 - *(int *)(iVar2 + 0xc);
      }
      *piVar4 = iVar1;
      if (uVar3 % 3 == 0) {
        piVar4[-3] = 0;
        piVar4[-1] = *(int *)(in_ECX + 0x2dc);
      }
      else {
        if (uVar3 % 3 == 1) {
          piVar4[-3] = *(int *)(in_ECX + 0x2dc);
          iVar1 = *(int *)(in_ECX + 8);
          iVar2 = *(int *)(iVar1 + 0x10) - *(int *)(in_ECX + 0x2e4);
        }
        else {
          piVar4[-3] = (*(int *)(*(int *)(in_ECX + 8) + 0x10) - *(int *)(in_ECX + 0x2e4)) -
                       *(int *)(*(int *)(in_ECX + 8) + 8);
          iVar1 = *(int *)(in_ECX + 8);
          iVar2 = *(int *)(iVar1 + 0x10);
        }
        piVar4[-1] = iVar2 - *(int *)(iVar1 + 8);
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 4;
    } while ((int)uVar3 < 9);
  }
  return;
}

