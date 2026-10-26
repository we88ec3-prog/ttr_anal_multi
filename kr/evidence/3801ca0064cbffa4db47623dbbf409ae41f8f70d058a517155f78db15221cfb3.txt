
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b85a0(void)

{
  int *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined2 local_8;
  undefined1 local_6;
  undefined1 local_5;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105ba) goto LAB_005b85d1;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005b85d1:
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  _local_8 = CONCAT13(1,CONCAT12((char)in_EAX[5],0x42));
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,4);
  }
  puVar2 = (undefined4 *)FUN_00891268(0x14);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = FoxUI::FXUIEvent::vftable;
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0xf4389;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

