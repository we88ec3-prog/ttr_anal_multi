
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00508520(void)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined2 local_8;
  undefined1 local_6;
  undefined1 local_5;
  
  iVar1 = *(int *)(unaff_EDI + 8);
  if ((unaff_ESI < *(int *)(unaff_EDI + 0xc) - iVar1 >> 3) && (-1 < unaff_ESI)) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    _local_8 = CONCAT13(*(undefined1 *)(iVar1 + unaff_ESI * 8),
                        CONCAT12(*(undefined1 *)(unaff_EDI + 0x18),0x45));
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,4);
    }
  }
  return;
}

