
undefined4 FUN_006fe1c0(int param_1)

{
  int iVar1;
  int *in_EAX;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  
  if (in_EAX[2] != 6) {
    in_EAX = (int *)FUN_006fe0e0();
  }
  iVar5 = *(int *)(in_ECX + 0x20);
  iVar1 = *in_EAX;
  *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0xc) = *(undefined4 *)(in_ECX + 0x18);
  if (*(char *)(iVar1 + 6) == '\0') {
    iVar1 = *(int *)(iVar1 + 0x10);
    if (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 8) <=
        (int)((uint)*(byte *)(iVar1 + 0x4b) * 0x10)) {
      FUN_006fdcb0();
    }
    iVar6 = (int)in_EAX + (*(int *)(in_ECX + 0x20) - iVar5);
    if (*(char *)(iVar1 + 0x4a) == '\0') {
      iVar3 = iVar6 + 0x10;
      uVar2 = (uint)*(byte *)(iVar1 + 0x49) * 0x10 + iVar3;
      if (uVar2 < *(uint *)(in_ECX + 8)) {
        *(uint *)(in_ECX + 8) = uVar2;
      }
    }
    else {
      iVar3 = FUN_006fdec0();
      iVar6 = (int)in_EAX + (*(int *)(in_ECX + 0x20) - iVar5);
    }
    if (*(int *)(in_ECX + 0x14) == *(int *)(in_ECX + 0x24)) {
      piVar4 = (int *)FUN_006fdd90();
    }
    else {
      piVar4 = (int *)(*(int *)(in_ECX + 0x14) + 0x18);
      *(int **)(in_ECX + 0x14) = piVar4;
    }
    piVar4[1] = iVar6;
    *piVar4 = iVar3;
    *(int *)(in_ECX + 0xc) = iVar3;
    piVar4[2] = (uint)*(byte *)(iVar1 + 0x4b) * 0x10 + iVar3;
    *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(iVar1 + 0xc);
    piVar4[5] = 0;
    piVar4[4] = param_1;
    uVar2 = *(uint *)(in_ECX + 8);
    if (uVar2 < (uint)piVar4[2]) {
      do {
        *(undefined4 *)(uVar2 + 8) = 0;
        uVar2 = uVar2 + 0x10;
      } while (uVar2 < (uint)piVar4[2]);
    }
    *(int *)(in_ECX + 8) = piVar4[2];
    if ((*(byte *)(in_ECX + 0x38) & 1) != 0) {
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 4;
      FUN_006fdde0(0xffffffff);
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + -4;
    }
    return 0;
  }
  if (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 8) < 0x141) {
    FUN_006fdcb0();
  }
  if (*(int *)(in_ECX + 0x14) == *(int *)(in_ECX + 0x24)) {
    piVar4 = (int *)FUN_006fdd90();
  }
  else {
    piVar4 = (int *)(*(int *)(in_ECX + 0x14) + 0x18);
    *(int **)(in_ECX + 0x14) = piVar4;
  }
  iVar5 = (int)in_EAX + (*(int *)(in_ECX + 0x20) - iVar5);
  piVar4[1] = iVar5;
  iVar5 = iVar5 + 0x10;
  *piVar4 = iVar5;
  *(int *)(in_ECX + 0xc) = iVar5;
  piVar4[2] = *(int *)(in_ECX + 8) + 0x140;
  piVar4[4] = param_1;
  if ((*(byte *)(in_ECX + 0x38) & 1) != 0) {
    FUN_006fdde0(0xffffffff);
  }
  iVar5 = (**(code **)(**(int **)(*(int *)(in_ECX + 0x14) + 4) + 0x10))();
  if (iVar5 < 0) {
    return 2;
  }
  FUN_006fe4c0();
  return 1;
}

