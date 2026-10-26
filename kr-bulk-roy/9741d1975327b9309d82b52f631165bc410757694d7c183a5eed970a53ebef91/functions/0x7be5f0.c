
undefined4 FUN_007be5f0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *unaff_ESI;
  
  if ((int *)*unaff_ESI == (int *)0x0) {
    return 0;
  }
  piVar1 = (int *)(*(int *)*unaff_ESI + 0x60);
  *piVar1 = *piVar1 + -1;
  puVar2 = (undefined4 *)*unaff_ESI;
  if ((puVar2[0x1d] != 0) && (puVar2[0x1e] != 0)) {
    FUN_007dd1a0(*puVar2,puVar2);
    *unaff_ESI = 0;
    return 1;
  }
  if (0 < (int)puVar2[0x1d]) {
    FUN_007be0f0(puVar2);
  }
  iVar3 = *unaff_ESI;
  if (iVar3 != 0) {
    FUN_007bd850();
    FUN_0089120c(iVar3);
    *unaff_ESI = 0;
  }
  *unaff_ESI = 0;
  return 1;
}

