
void FUN_00685900(void)

{
  int unaff_ESI;
  
  *(undefined4 *)(*(int *)(unaff_ESI + 0x24c) + 0x154) = 0xffff0000;
  (**(code **)(**(int **)(unaff_ESI + 0x24c) + 200))();
  *(undefined4 *)(*(int *)(unaff_ESI + 0x250) + 0x154) = 0xffff0000;
                    /* WARNING: Could not recover jumptable at 0x0068593e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_ESI + 0x250) + 200))();
  return;
}

