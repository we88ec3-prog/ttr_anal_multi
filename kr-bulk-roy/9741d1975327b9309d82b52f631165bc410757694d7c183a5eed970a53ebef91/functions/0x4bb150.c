
undefined4 FUN_004bb150(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int *in_ECX;
  int iVar4;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936a1e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_004adb10(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  if (in_ECX[0x17ac] == 0) {
    iVar4 = 0;
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 0;
        FUN_004dec90();
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_20 = iVar4;
      FUN_0082ef00(&local_20);
      if ((local_1c != DAT_00fab13c) && (piVar1 = *(int **)(local_1c + 0x10), piVar1 != (int *)0x0))
      {
        (**(code **)(piVar1[0x3c] + 8))(0x14);
        if (in_ECX[0x17af] == 0) {
          iVar3 = FUN_0089289d();
          iVar3 = iVar3 % 3 + 0x18;
        }
        else {
          iVar3 = FUN_0089289d();
          iVar3 = iVar3 % 3 + 0x15;
        }
        (**(code **)(*piVar1 + 0x68))(iVar3,0x3f800000);
      }
      iVar4 = iVar4 + 1000;
    } while (iVar4 < 3000);
  }
  in_ECX[0x17ac] = in_ECX[0x17ac] + -1;
  if (in_ECX[0x17ad] != 0) {
    if (in_ECX[0x17ae] != 0) {
      in_ECX[0x17ae] = in_ECX[0x17ae] + -1;
      ExceptionList = local_14;
      return 0;
    }
    pcVar2 = *(code **)(*in_ECX + 0x34);
    in_ECX[0x17ad] = 0;
    (*pcVar2)();
  }
  ExceptionList = local_14;
  return 0;
}

