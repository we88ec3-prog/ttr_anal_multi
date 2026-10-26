
void FUN_0045acd0(void)

{
  int *piVar1;
  int in_ECX;
  int unaff_EDI;
  
  if (*(int *)(in_ECX + 0x14) == 0xf43a5) {
    *(undefined4 *)(*(int *)(*(int *)(unaff_EDI + 0xf0) + *(int *)(unaff_EDI + 0x100) * 4) + 0x2a8)
         = *(undefined4 *)(in_ECX + 0x18);
    FUN_00459f20();
    piVar1 = (int *)FUN_00408810();
                    /* WARNING: Could not recover jumptable at 0x0045ad23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 200))();
    return;
  }
  if (*(int *)(in_ECX + 0x14) == 0xf43a6) {
    FUN_0045a210(*(undefined4 *)(*(int *)(unaff_EDI + 0xf0) + *(int *)(unaff_EDI + 0x100) * 4));
    piVar1 = (int *)FUN_00408810();
                    /* WARNING: Could not recover jumptable at 0x0045ad5d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 200))();
    return;
  }
  return;
}

