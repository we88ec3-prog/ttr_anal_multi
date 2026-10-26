
void FUN_0070d7c0(void)

{
  undefined4 uVar1;
  int *unaff_ESI;
  
  if (*(int *)(*unaff_ESI + 0x3c) == 0) {
    uVar1 = FUN_006f7c30(unaff_ESI[4],"main function has more than %d %s");
  }
  else {
    uVar1 = FUN_006f7c30(unaff_ESI[4],"function at line %d has more than %d %s",
                         *(int *)(*unaff_ESI + 0x3c));
  }
                    /* WARNING: Subroutine does not return */
  FUN_006ff130(unaff_ESI[3],uVar1,0);
}

