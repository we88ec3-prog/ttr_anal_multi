
void FUN_00635bd0(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_0046b6f0(1000);
  FUN_0043c570(0x44c);
  FUN_0043c570(0x4b0);
  FUN_0046b6f0(2000);
  FUN_0046b6f0(0x834);
  FUN_0046b6f0(3000);
  iVar1 = *(int *)(in_ECX + 0xd0);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0xd4);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
                    /* WARNING: Could not recover jumptable at 0x00635c8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xbc) + 0x10))();
  return;
}

