
void FUN_0070ae00(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  int iVar3;
  
  iVar3 = 2;
  if (1 < param_1) {
    do {
      puVar2 = (undefined4 *)FUN_006f50f0();
      puVar1 = *(undefined4 **)(unaff_ESI + 8);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
      puVar1 = *(undefined4 **)(unaff_ESI + 8);
      *puVar1 = puVar1[-8];
      puVar1[1] = puVar1[-7];
      puVar1[2] = puVar1[-6];
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
      FUN_006fe550();
      iVar3 = iVar3 + 1;
    } while (iVar3 <= param_1);
  }
  return;
}

