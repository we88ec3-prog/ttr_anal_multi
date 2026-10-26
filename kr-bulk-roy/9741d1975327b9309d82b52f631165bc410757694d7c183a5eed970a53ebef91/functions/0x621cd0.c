
void FUN_00621cd0(int param_1)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092d7c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX == (int *)0x0) {
LAB_00621d23:
    in_ECX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_00621d23;
    }
  }
  piVar2 = (int *)in_ECX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105b9) goto LAB_00621d4e;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_00621d4e:
  if (in_ECX[5] == 0x6a7) {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8 = 0xffffffff;
    }
    DAT_00fb92e5 = *(byte *)(piVar2 + 5);
    if (DAT_00fb92e7 < *(byte *)(piVar2 + 5)) {
      DAT_00fb92e5 = DAT_00fb92e7;
    }
    if (DAT_00fb92e5 < DAT_00fb92e6) {
      DAT_00fb92e5 = DAT_00fb92e6;
    }
    (**(code **)(*(int *)(DAT_00fb1318 + 8) + 0xc))(DAT_00fb1318 + 8);
    (**(code **)(*(int *)(DAT_00fb1318 + 8) + 0x10))(DAT_00fb1318 + 8);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 1;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8 = 0xffffffff;
    }
    if (DAT_00fb92e5 == 0) {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 3;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      DAT_00fb774c = 0;
    }
    else {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 2;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      DAT_00fb774c = 3;
    }
    (**(code **)(*(int *)(DAT_00fb1318 + 8) + 4))(DAT_00fb1318 + 8);
    (**(code **)(*(int *)(DAT_00fb1318 + 8) + 8))(DAT_00fb1318 + 8);
  }
  else {
    if (piVar2[5] == 3) {
      piVar2 = *(int **)(param_1 + 0x114);
    }
    else {
      piVar2 = *(int **)(param_1 + 0x110);
    }
    (**(code **)(*piVar2 + 0xa0))(1);
  }
  FUN_006221d0();
  ExceptionList = local_10;
  return;
}

