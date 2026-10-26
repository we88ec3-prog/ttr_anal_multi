
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b91d0(void)

{
  int iVar1;
  int *in_ECX;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093602b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 == 0x105bd) goto LAB_005b9225;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_005b9225:
  iVar1 = DAT_00fe1bd0;
  if (in_ECX[5] == 0x6a7) {
    iVar1 = in_ECX[6];
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_14._0_3_ = CONCAT12(*(undefined1 *)(iVar1 + 0x18),0x5d);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_14,3);
      ExceptionList = local_10;
      return;
    }
  }
  else if (in_ECX[5] == 0x6a8) {
    local_14 = *(undefined4 *)(in_ECX[6] + 0x14);
    FUN_008438c0(&local_14);
    if (((local_18 != *(int *)(iVar1 + 0xc)) && (iVar1 = *(int *)(local_18 + 0x10), iVar1 != 0)) &&
       (*(int *)(iVar1 + 0x40) != *(int *)(iVar1 + 0x44))) {
      local_18 = FUN_00891268(0x1c);
      local_8 = 0;
      if (local_18 == 0) {
        local_18 = 0;
      }
      else {
        iVar1 = FUN_0040f060();
        local_18 = FUN_00753f80(*(undefined4 *)(iVar1 + 0x8c));
      }
      local_8 = 0xffffffff;
      FUN_00404aa0();
      FUN_00804260(&local_18);
    }
  }
  ExceptionList = local_10;
  return;
}

