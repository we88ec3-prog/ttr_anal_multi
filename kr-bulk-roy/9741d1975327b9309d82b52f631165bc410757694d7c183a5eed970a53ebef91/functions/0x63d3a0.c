
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063d3a0(void)

{
  int iVar1;
  int *unaff_EDI;
  
  iVar1 = unaff_EDI[0x3d];
  if (*(char *)(iVar1 + 0x141) != '\0') {
    FUN_006edb10("Not supported operation");
  }
  if (*(int *)(iVar1 + 0x118) != 0) {
    iVar1 = unaff_EDI[0x3d];
    if (*(char *)(iVar1 + 0x141) != '\0') {
      FUN_006edb10("Not supported operation");
    }
    if (*(uint *)(iVar1 + 0x11c) < 8) {
      iVar1 = iVar1 + 0x108;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x108);
    }
    if ((_DAT_00fd94dc & 1) == 0) {
      _DAT_00fd94dc = _DAT_00fd94dc | 1;
      FUN_004f10f0();
      _atexit((_func_4879 *)&LAB_00bce260);
    }
    iVar1 = FUN_004f2db0(iVar1);
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0063d433. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*unaff_EDI + 0xd4))();
      return;
    }
  }
  return;
}

