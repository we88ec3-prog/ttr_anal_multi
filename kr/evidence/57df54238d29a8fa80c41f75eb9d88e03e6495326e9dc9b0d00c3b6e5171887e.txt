
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b9d50(void)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  undefined2 local_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 local_a;
  undefined2 uStack_8;
  undefined1 local_6;
  
  if (in_EAX == (int *)0x0) {
LAB_005b9d89:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_005b9d89;
    }
  }
  piVar2 = (int *)in_EAX[6];
  if (piVar2 == (int *)0x0) {
LAB_005b9db2:
    piVar2 = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 != 0x105b9) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_005b9db2;
    }
  }
  if (in_EAX[5] == 0x6a7) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    uStack_e = 1;
  }
  else {
    if (in_EAX[5] != 0x6a8) goto LAB_005b9e44;
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    uStack_e = 0;
  }
  uStack_c = 0;
  local_6 = 0;
  local_a = (undefined2)piVar2[5];
  uStack_8 = (undefined2)((uint)piVar2[5] >> 0x10);
  local_10 = 0x56;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_10,0xb);
  }
LAB_005b9e44:
  FUN_005c2210(&local_10,piVar2 + 5);
  FUN_005540c0(CONCAT22(uStack_e,local_10),CONCAT22(local_a,uStack_c));
  return;
}

