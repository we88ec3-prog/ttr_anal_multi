
undefined4 FUN_004b28d0(int param_1,uint param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  ushort *local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936d1c;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if (param_2 < 4) {
    local_34 = 0;
  }
  else {
    local_34 = param_2 - 4 >> 1;
  }
  if (local_34 != 0) {
    local_38 = (ushort *)(param_1 + 4);
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 0;
        FUN_004dec90(uVar3);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_30 = (uint)*local_38;
      FUN_0082ef00(&local_30);
      if ((local_2c == DAT_00fab13c) || (iVar1 = *(int *)(local_2c + 0x10), iVar1 == 0)) {
        FUN_006edb60("DeleteObjPack: Cannot Found In CharList");
      }
      else {
        cVar2 = (char)*(undefined2 *)(iVar1 + 4);
        if ((((cVar2 == '\x01') || (cVar2 == '\x06')) || (cVar2 == '\0')) || (cVar2 == '\a')) {
          local_28 = 0x3f800000;
          local_24 = 0x3f800000;
          local_20 = 0x3f800000;
          local_1c = 0x3f800000;
          if ((*(int *)(iVar1 + 0x15c) != 0) && (*(int *)(iVar1 + 0x370) != 0)) {
            FUN_007a7cc0(*(int *)(iVar1 + 0x15c),0);
            FUN_007a7bf0(local_28,local_24,local_20,local_1c);
          }
        }
        cVar2 = (char)*(undefined2 *)(iVar1 + 4);
        if ((((cVar2 == '\x02') || (cVar2 == '\b')) || (cVar2 == '\t')) &&
           (((*(int *)(iVar1 + 0xf4) != 0 && (*(int *)(iVar1 + 0x124) == 0)) &&
            (0.6 < *(float *)(iVar1 + 0x134) / *(float *)(iVar1 + 0x130))))) {
          FUN_004cc8b0();
        }
        iVar4 = 0;
        piVar5 = DAT_00fba7a4;
        do {
          piVar5 = piVar5 + 3;
          if ((*piVar5 != 0) && (*(short *)(*piVar5 + 4) == *(short *)(iVar1 + 4))) {
            if (iVar4 != -1) {
              (**(code **)(*DAT_00fba7a4 + 0x14))();
            }
            break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 3);
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 1;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        FUN_004dfbc0(*local_38);
      }
      local_38 = local_38 + 1;
      local_34 = local_34 - 1;
    } while (local_34 != 0);
  }
  ExceptionList = local_14;
  return 0;
}

