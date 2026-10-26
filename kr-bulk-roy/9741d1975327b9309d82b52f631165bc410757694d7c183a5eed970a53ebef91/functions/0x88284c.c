
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0088284c(void)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  uint unaff_EDI;
  
  iVar1 = *(int *)(unaff_EBP + 0xc);
  if (iVar1 != 0) {
    puVar2 = unaff_ESI;
    if (7 < (uint)unaff_ESI[5]) {
      puVar2 = (undefined4 *)*unaff_ESI;
    }
    FID_conflict__memcpy(*(void **)(unaff_EBP + 8),puVar2,iVar1 * 2);
  }
  FID_conflict__Tidy(1,0);
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  *unaff_ESI = puVar2;
  unaff_ESI[5] = unaff_EDI;
  unaff_ESI[4] = iVar1;
  if (unaff_EDI < 8) {
    puVar2 = unaff_ESI;
  }
  *(undefined2 *)((int)puVar2 + iVar1 * 2) = 0;
  return;
}

