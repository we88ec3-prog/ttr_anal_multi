
void FUN_00701450(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  puVar2 = *(undefined4 **)(unaff_ESI + 8);
  *puVar2 = &DAT_00c081df;
  puVar2[2] = 2;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  puVar2 = (undefined4 *)FUN_006f9c50();
  iVar1 = *(int *)(unaff_ESI + 8);
  *(undefined4 *)(iVar1 + -0x10) = *puVar2;
  *(undefined4 *)(iVar1 + -0xc) = puVar2[1];
  *(undefined4 *)(iVar1 + -8) = puVar2[2];
  puVar2 = (undefined4 *)(*(int *)(unaff_ESI + 8) + -0x10);
  if ((puVar2 == &DAT_00c0bfc8) || (*(int *)(*(int *)(unaff_ESI + 8) + -8) != 5)) {
    *(undefined4 **)(unaff_ESI + 8) = puVar2;
    if (*(uint *)(*(int *)(unaff_ESI + 0x10) + 0x40) <= *(uint *)(*(int *)(unaff_ESI + 0x10) + 0x44)
       ) {
      FUN_006fb3a0();
    }
    puVar2 = *(undefined4 **)(unaff_ESI + 8);
    uVar3 = FUN_006f99a0();
    *puVar2 = uVar3;
    puVar2[2] = 5;
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
    puVar2 = *(undefined4 **)(unaff_ESI + 8);
    *puVar2 = &DAT_00c081df;
    puVar2[2] = 2;
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
    puVar2 = *(undefined4 **)(unaff_ESI + 8);
    *puVar2 = puVar2[-8];
    puVar2[1] = puVar2[-7];
    puVar2[2] = puVar2[-6];
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
    FUN_006f57f0();
  }
  return;
}

