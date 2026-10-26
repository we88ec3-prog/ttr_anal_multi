
void FUN_008451d0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *unaff_ESI;
  int *unaff_EDI;
  
  puVar2 = (undefined4 *)*unaff_ESI;
  if (puVar2 != (undefined4 *)0x0) {
    piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  *unaff_ESI = (int)unaff_EDI;
  if (unaff_EDI != (int *)0x0) {
    iVar3 = (**(code **)(*unaff_EDI + 8))();
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*(int *)*unaff_ESI + 0xc))();
      *unaff_ESI = iVar3;
    }
    *(int *)(*unaff_ESI + 4) = *(int *)(*unaff_ESI + 4) + 1;
  }
  return;
}

