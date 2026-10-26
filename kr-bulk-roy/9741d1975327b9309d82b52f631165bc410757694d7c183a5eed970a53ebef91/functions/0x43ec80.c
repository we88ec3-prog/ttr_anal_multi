
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043ec80(undefined4 param_1,byte param_2)

{
  int iVar1;
  undefined2 *unaff_ESI;
  int unaff_EDI;
  
  FUN_00835c70(&param_1);
  if ((*(int *)(unaff_EDI + 4) != 0) && ((uint)param_2 < (uint)(_DAT_00000014 - iRam00000010 >> 5)))
  {
    iVar1 = (uint)param_2 * 0x20 + iRam00000010;
    *(undefined4 *)(unaff_ESI + 10) = 7;
    *(undefined4 *)(unaff_ESI + 8) = 0;
    *unaff_ESI = 0;
    FUN_004026e0(iVar1 + 4,0,0xffffffff);
    return;
  }
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  FUN_00402160(&DAT_00bed1fc,0);
  return;
}

