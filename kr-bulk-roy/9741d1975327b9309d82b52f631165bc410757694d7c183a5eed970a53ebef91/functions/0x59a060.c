
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059a060(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uStack_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  piVar2 = DAT_00fba7a4;
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093f7dc;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fba7a4 != (int *)0x0) &&
     (iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))(DAT_00d61f20 ^ (uint)&stack0xffffffd0), iVar3 != 0
     )) {
    iVar3 = (**(code **)(*piVar2 + 0x20))();
    uVar1 = *(undefined4 *)(iVar3 + 0x9c);
    iVar3 = FUN_0040f060();
    uStack_20 = uVar1;
    FUN_008438c0(&uStack_20);
    if ((iStack_1c != *(int *)(iVar3 + 0x1c)) && (*(int *)(iStack_1c + 0x10) != 0)) {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        uStack_c = 0;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        uStack_c = 0xffffffff;
      }
      switch(DAT_00f9392c) {
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 0x17:
      case 0x18:
        if (DAT_00fe2c80 == 0) {
          DAT_00fba830 = 0;
          iVar3 = FUN_00489fe0();
          *(undefined4 *)(iVar3 + 0xbc) = 0;
          DAT_00fe2c80 = 1;
          ExceptionList = local_14;
          return;
        }
        if (DAT_00fe2c80 == 1) {
          iVar3 = FUN_00489f40();
          *(undefined4 *)(iVar3 + 0x4d4c) = 0;
          DAT_00fe2c80 = 2;
          ExceptionList = local_14;
          return;
        }
        if (DAT_00fe2c80 != 2) {
          ExceptionList = local_14;
          return;
        }
        iVar3 = FUN_00489f40();
        *(undefined4 *)(iVar3 + 0x4d4c) = 1;
        iVar3 = FUN_00489fe0();
        *(undefined4 *)(iVar3 + 0xbc) = 1;
        break;
      default:
        if ((DAT_00fcde44 & 1) == 0) {
          DAT_00fcde44 = DAT_00fcde44 | 1;
          uStack_c = 1;
          FUN_0055b8a0();
          _atexit(FUN_00bcdef0);
        }
        _DAT_00fd2b94 = 1;
      }
      DAT_00fe2c80 = 0;
      DAT_00fba830 = 1;
    }
  }
  ExceptionList = local_14;
  return;
}

