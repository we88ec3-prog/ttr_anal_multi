
void FUN_006de0c0(void)

{
  bool bVar1;
  int iVar2;
  int *unaff_ESI;
  
  bVar1 = false;
  if (((*(byte *)(*(int *)(*unaff_ESI + 4) + 0xc + (int)unaff_ESI) & 6) == 0) &&
     (iVar2 = (**(code **)(**(int **)(*(int *)(*unaff_ESI + 4) + 0x38 + (int)unaff_ESI) + 0x34))(),
     iVar2 == -1)) {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_00431a90(0);
  }
  return;
}

