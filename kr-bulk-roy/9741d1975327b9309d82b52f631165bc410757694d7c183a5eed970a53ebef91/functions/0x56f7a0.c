
void FUN_0056f7a0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x1c) + 0x18))();
    uVar3 = FUN_008fed10((float)iVar2 / *(float *)(unaff_ESI + 100));
    piVar1 = *(int **)(unaff_ESI + 0x1c);
    *unaff_EDI = uVar3;
    iVar2 = (**(code **)(*piVar1 + 0x18))();
    (**(code **)(**(int **)(unaff_ESI + 0x1c) + 0x18))((float)iVar2 / *(float *)(unaff_ESI + 100));
    uVar3 = FUN_008fed10();
    unaff_EDI[1] = uVar3;
    return;
  }
  *unaff_EDI = 0;
  unaff_EDI[1] = 0;
  return;
}

