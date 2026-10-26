
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00636e10(void)

{
  int iVar1;
  undefined4 in_ECX;
  int *unaff_ESI;
  int *unaff_EDI;
  undefined4 local_8;
  
  local_8 = in_ECX;
  if (unaff_ESI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_ESI + 4))();
    if (iVar1 == 0x105bd) goto LAB_00636e42;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_00636e42:
  if (unaff_ESI[5] == 0x6a7) {
    if (unaff_EDI[0x22] == 0) {
      return;
    }
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_8 = CONCAT22(*(undefined2 *)unaff_EDI[0x22],0x36);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,4);
      (**(code **)(*unaff_EDI + 0xd4))();
      return;
    }
  }
  else if (unaff_ESI[5] != 0x6a8) {
    return;
  }
  (**(code **)(*unaff_EDI + 0xd4))();
  return;
}

