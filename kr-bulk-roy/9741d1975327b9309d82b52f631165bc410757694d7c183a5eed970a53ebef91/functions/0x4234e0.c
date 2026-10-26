
void FUN_004234e0(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_005b87b0();
  if (((uint)(*(int **)(in_ECX + 0x2f8))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x2f8) + 0x16c))();
  }
  iVar1 = *(int *)(in_ECX + 0x300);
  if ((iVar1 != 0) && ((*(uint *)(iVar1 + 0x28) >> 8 & 1) != 0)) {
    FUN_0064c710(iVar1);
  }
  if (((uint)(*(int **)(in_ECX + 0x2fc))[10] >> 8 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0042353b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x2fc) + 0x170))();
    return;
  }
  return;
}

