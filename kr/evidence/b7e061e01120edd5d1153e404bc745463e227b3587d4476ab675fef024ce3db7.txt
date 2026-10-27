
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b6770(void)

{
  int iVar1;
  int in_ECX;
  int *unaff_EDI;
  void *pvStack_20;
  undefined2 uStack_1c;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f9392c == 0x17) {
    (**(code **)(**(int **)(in_ECX + 0x22c) + 0xd4))();
    (**(code **)(**(int **)(in_ECX + 0x230) + 0xd4))();
    ExceptionList = local_14;
    return;
  }
  (**(code **)(**(int **)(in_ECX + 0x21c) + 0xd4))();
  if (unaff_EDI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_EDI + 4))();
    if (iVar1 == 0x105ba) goto LAB_005b681d;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_EDI = (int *)0x0;
LAB_005b681d:
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  uStack_1a = (undefined1)unaff_EDI[5];
  uStack_19 = (undefined1)unaff_EDI[6];
  uStack_1c = 0x42;
  if (DAT_00fba798 != 0) {
    ExceptionList = local_14;
    return;
  }
  (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_1c,4);
  ExceptionList = pvStack_20;
  return;
}

