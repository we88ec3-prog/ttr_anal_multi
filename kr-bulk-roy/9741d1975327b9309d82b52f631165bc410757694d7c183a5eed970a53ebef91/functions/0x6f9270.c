
undefined4 FUN_006f9270(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  double *in_ECX;
  int *piVar4;
  int iVar5;
  
  iVar2 = FUN_006f9190();
  iVar5 = *(int *)(param_1 + 0x1c);
  iVar2 = iVar2 + 1;
  if (iVar2 < iVar5) {
    piVar4 = (int *)(*(int *)(param_1 + 0xc) + 8 + iVar2 * 0x10);
    do {
      if (*piVar4 != 0) {
        *(undefined4 *)(in_ECX + 1) = 3;
        *in_ECX = (double)(iVar2 + 1);
        puVar3 = (undefined4 *)(iVar2 * 0x10 + *(int *)(param_1 + 0xc));
        *(undefined4 *)(in_ECX + 2) = *puVar3;
        *(undefined4 *)((int)in_ECX + 0x14) = puVar3[1];
        *(undefined4 *)(in_ECX + 3) = puVar3[2];
        return 1;
      }
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 4;
    } while (iVar2 < iVar5);
  }
  iVar2 = iVar2 - iVar5;
  iVar5 = 1 << (*(byte *)(param_1 + 7) & 0x1f);
  if (iVar2 < iVar5) {
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(iVar2 * 0x20 + 8 + iVar1);
    do {
      if (*piVar4 != 0) {
        iVar2 = iVar2 * 0x20;
        *(undefined4 *)in_ECX = *(undefined4 *)(iVar1 + 0x10 + iVar2);
        *(undefined4 *)((int)in_ECX + 4) = *(undefined4 *)(iVar1 + 0x14 + iVar2);
        *(undefined4 *)(in_ECX + 1) = *(undefined4 *)(iVar1 + 0x18 + iVar2);
        iVar5 = *(int *)(param_1 + 0x10) + iVar2;
        *(undefined4 *)(in_ECX + 2) = *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar2);
        *(undefined4 *)((int)in_ECX + 0x14) = *(undefined4 *)(iVar5 + 4);
        *(undefined4 *)(in_ECX + 3) = *(undefined4 *)(iVar5 + 8);
        return 1;
      }
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 8;
    } while (iVar2 < iVar5);
  }
  return 0;
}

