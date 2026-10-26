
int FUN_008f8120(int param_1)

{
  int *piVar1;
  int *unaff_EBX;
  int unaff_EDI;
  int local_8;
  
  piVar1 = (int *)FUN_008baee0(*(undefined4 *)(unaff_EDI + 100),*(int *)(unaff_EDI + 0x10) + 0xd0,
                               &local_8);
  if (local_8 == 0) {
    *piVar1 = unaff_EDI;
    piVar1[1] = *(int *)(unaff_EDI + 0x10);
    piVar1[2] = (int)(piVar1 + 0x34);
    piVar1[0x33] = param_1;
    local_8 = FUN_008f7f60(piVar1);
    if (local_8 != 0) {
      FUN_008f3f40(piVar1);
      piVar1 = (int *)0x0;
    }
    piVar1[3] = 0;
  }
  *unaff_EBX = (int)piVar1;
  return local_8;
}

