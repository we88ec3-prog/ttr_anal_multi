
void Catch_All_00741da4(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  if (7 < (uint)puVar1[5]) {
    FUN_0089120c(*puVar1);
  }
  puVar1[5] = 7;
  puVar1[4] = 0;
  *(undefined2 *)puVar1 = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

