
undefined4 FUN_00874a70(int param_1)

{
  int *piVar1;
  int in_ECX;
  uint unaff_EBX;
  int unaff_EDI;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iStack_24;
  undefined4 uStack_1c;
  int local_18 [5];
  
  FUN_00784fd0(param_1);
  local_18[0] = *(int *)(in_ECX + 0x34) - *(int *)(in_ECX + 0x30) >> 2;
  if (in_ECX + 0x40 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x40,0x14,0);
  }
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),local_18,4,0);
  uVar5 = 0;
  if (unaff_EBX != 0) {
    do {
      piVar1 = (int *)(*(int *)(in_ECX + 0x30) + uVar5 * 4);
      uStack_1c = *(undefined4 *)*piVar1;
      iVar4 = *piVar1;
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),&uStack_1c,4,0);
      iStack_24 = *(int *)(in_ECX + 0x40);
      if (((iStack_24 != 0) && (iVar2 = *(int *)(iVar4 + 4), iVar2 != 0)) && (0 < iStack_24)) {
        do {
          FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar2,0xc,0);
          iVar2 = iVar2 + 0xc;
          iStack_24 = iStack_24 + -1;
          in_ECX = unaff_EDI;
        } while (iStack_24 != 0);
      }
      iStack_24 = *(int *)(in_ECX + 0x44);
      if (((iStack_24 != 0) && (iVar2 = *(int *)(iVar4 + 8), iVar2 != 0)) && (0 < iStack_24)) {
        do {
          FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar2,0xc,0);
          iVar2 = iVar2 + 0xc;
          iStack_24 = iStack_24 + -1;
          in_ECX = unaff_EDI;
        } while (iStack_24 != 0);
      }
      iVar2 = *(int *)(in_ECX + 0x48);
      if (((iVar2 != 0) && (iVar3 = *(int *)(iVar4 + 0xc), iVar3 != 0)) && (0 < iVar2)) {
        do {
          FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar3,0xc,0);
          iVar3 = iVar3 + 0xc;
          iVar2 = iVar2 + -1;
          in_ECX = unaff_EDI;
        } while (iVar2 != 0);
      }
      iVar2 = *(int *)(in_ECX + 0x4c);
      if (((iVar2 != 0) && (iVar3 = *(int *)(iVar4 + 0x10), iVar3 != 0)) && (0 < iVar2)) {
        do {
          FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar3,0xc,0);
          iVar3 = iVar3 + 0xc;
          iVar2 = iVar2 + -1;
          in_ECX = unaff_EDI;
        } while (iVar2 != 0);
      }
      iVar2 = *(int *)(in_ECX + 0x50);
      if (((iVar2 != 0) && (iVar4 = *(int *)(iVar4 + 0x14), iVar4 != 0)) && (0 < iVar2)) {
        do {
          FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar4,0xc,0);
          iVar4 = iVar4 + 0xc;
          iVar2 = iVar2 + -1;
          in_ECX = unaff_EDI;
        } while (iVar2 != 0);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < unaff_EBX);
  }
  return 1;
}

