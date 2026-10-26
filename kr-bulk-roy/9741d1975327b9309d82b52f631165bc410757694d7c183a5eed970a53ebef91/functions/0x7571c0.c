
void FUN_007571c0(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  
  puVar1 = (undefined1 *)*unaff_ESI;
  if (puVar1 != (undefined1 *)0x0) {
    for (iVar2 = unaff_ESI[1] * 2; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    FUN_00891d3d(*unaff_ESI);
    *unaff_ESI = 0;
    unaff_ESI[2] = 0;
  }
  FUN_0089120c();
  return;
}

