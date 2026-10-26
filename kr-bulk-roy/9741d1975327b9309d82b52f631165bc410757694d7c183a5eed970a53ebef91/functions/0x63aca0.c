
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063aca0(void)

{
  int iVar1;
  int unaff_EDI;
  undefined1 local_6 [2];
  
  *(int *)(unaff_EDI + 0x108) = *(int *)(unaff_EDI + 0x108) + 1;
  if (0x96 < *(int *)(unaff_EDI + 0x108)) {
    if ((*(int *)(*(int *)(unaff_EDI + 0xf8) + 0xcc) != 0) &&
       (*(int *)(*(int *)(unaff_EDI + 0xf8) + 0xd8) != 0)) {
      iVar1 = FUN_005f55a0();
      if (iVar1 == 0) {
        if ((_DAT_00fb1314 & 1) == 0) {
          _DAT_00fb1314 = _DAT_00fb1314 | 1;
          _atexit((_func_4879 *)&DAT_00bccf10);
        }
        if (DAT_00fba798 == 0) {
          (**(code **)(*DAT_00fba854 + 0x10))(2,local_6,2);
          *(undefined4 *)(unaff_EDI + 0x108) = 0;
          return;
        }
      }
      else {
        if (iVar1 == 1) {
          FUN_00414680();
          FUN_004a40b0();
          *(undefined4 *)(unaff_EDI + 0x108) = 0;
          return;
        }
        if (iVar1 == 2) {
          FUN_00414680();
          FUN_004a4080();
        }
      }
    }
    *(undefined4 *)(unaff_EDI + 0x108) = 0;
  }
  return;
}

