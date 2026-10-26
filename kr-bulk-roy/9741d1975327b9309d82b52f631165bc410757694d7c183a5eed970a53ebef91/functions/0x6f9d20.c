
/* WARNING: Removing unreachable block (ram,0x006f9d5b) */

void FUN_006f9d20(undefined4 param_1)

{
  undefined4 *puVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  puVar1 = (undefined4 *)FUN_006f9c50();
  *(undefined1 *)(unaff_EDI + 6) = 0;
  if (puVar1 == &DAT_00c0bfc8) {
    if (*(int *)(unaff_ESI + 8) == 0) {
      FUN_006f8b60(param_1,"table index is nil");
    }
    FUN_006f9a60(param_1);
  }
  return;
}

