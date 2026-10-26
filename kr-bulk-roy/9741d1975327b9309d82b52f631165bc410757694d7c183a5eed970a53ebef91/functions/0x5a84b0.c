
void FUN_005a84b0(void)

{
  int iVar1;
  int unaff_ESI;
  
  (**(code **)(**(int **)(unaff_ESI + 0x138) + 0xd0))();
  iVar1 = *(int *)(unaff_ESI + 0x138);
  (**(code **)(**(int **)(iVar1 + 0xf0) + 0x90))(1);
  (**(code **)(**(int **)(iVar1 + 0xf4) + 0x90))(1);
  (**(code **)(**(int **)(iVar1 + 0xf8) + 0x90))(1);
  (**(code **)(**(int **)(unaff_ESI + 0x15c) + 0xd4))();
  (**(code **)(**(int **)(unaff_ESI + 0x160) + 0xd4))();
                    /* WARNING: Could not recover jumptable at 0x005a852c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_ESI + 0x164) + 0xd4))();
  return;
}

