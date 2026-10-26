
undefined4 FUN_007181a0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xc) == (int *)0x0) {
    FID_conflict__wprintf("File is not opened!\n");
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x007181bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x30))();
  return uVar1;
}

