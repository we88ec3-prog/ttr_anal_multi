
undefined4 FUN_00500e00(int param_1,int param_2,undefined4 *param_3)

{
  short sVar1;
  void *_Dst;
  uint uVar2;
  int iVar3;
  short *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936d4e;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  _Dst = (void *)*param_3;
  if (_Dst != (void *)param_3[1]) {
    FID_conflict__memcpy(_Dst,(void *)param_3[1],0);
    param_3[1] = _Dst;
  }
  local_2c = (short *)(param_1 + 0x5ed0);
  local_28 = 0x14;
  do {
    sVar1 = *local_2c;
    if (sVar1 != 0) {
      iVar3 = *(int *)(param_1 + 0x5eac);
      local_24 = (int)sVar1;
      FUN_00503d20(&local_24);
      if (((local_20 != *(int *)(iVar3 + 4)) && (local_20 != -0x10)) &&
         (*(int *)(local_20 + 0x3c) == param_2)) {
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 0;
          FUN_004dec90(uVar2);
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        for (iVar3 = *(int *)(DAT_00fab134 + 0x10); iVar3 != *(int *)(DAT_00fab134 + 0x14);
            iVar3 = iVar3 + 0x18) {
          if ((*(short *)(iVar3 + 0x14) == sVar1) && (*(short *)(iVar3 + 8) < *(short *)(iVar3 + 6))
             ) goto LAB_00500f5e;
        }
        iVar3 = *(int *)(param_1 + 0x5eac);
        local_24 = (int)sVar1;
        FUN_00503d20(&local_24);
        if (local_1c == *(int *)(iVar3 + 4)) {
          local_24 = 0;
        }
        else {
          local_24 = local_1c + 0x10;
        }
        if ((local_24 != 0) && (*(int *)(local_24 + 4) != 2)) {
          FUN_00443d10();
        }
      }
    }
LAB_00500f5e:
    local_2c = local_2c + 1;
    local_28 = local_28 + -1;
    if (local_28 == 0) {
      ExceptionList = local_14;
      return 1;
    }
  } while( true );
}

