
/* WARNING: Removing unreachable block (ram,0x007dcc51) */
/* WARNING: Removing unreachable block (ram,0x007dcc5f) */

void FUN_007dcc30(int param_1)

{
  int iVar1;
  int unaff_EDI;
  undefined4 local_8;
  
  local_8 = *(undefined4 *)(unaff_EDI + 4);
  iVar1 = *(int *)(unaff_EDI + 0x10);
  if (iVar1 != *(int *)(unaff_EDI + 0x14)) {
    *(int *)(unaff_EDI + 0x14) = iVar1;
  }
  FUN_007dcc90(*(int *)(unaff_EDI + 0x10),&local_8);
  *(int *)(unaff_EDI + 0x24) = param_1;
  *(int *)(unaff_EDI + 0x20) = param_1 + -1;
  return;
}

