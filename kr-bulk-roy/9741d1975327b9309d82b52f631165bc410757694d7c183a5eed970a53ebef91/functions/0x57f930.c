
void FUN_0057f930(void)

{
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  if (*(int **)(unaff_EDI + 0x54) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EDI + 0x54) + 4))();
  }
  *(undefined4 **)(unaff_EDI + 0x54) = unaff_ESI;
  if (unaff_ESI != (undefined4 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0057f94b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)*unaff_ESI)();
    return;
  }
  return;
}

