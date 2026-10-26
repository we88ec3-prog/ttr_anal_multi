
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054d640(float param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *unaff_EBX;
  int *piVar5;
  int local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_44;
  undefined1 local_40 [8];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [20];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009365c8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_5c;
  ExceptionList = &local_14;
  if (DAT_00fbab18 != 0) {
    _DAT_00fbab24 = _DAT_00fbab24 - param_1;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 0;
      FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffff98);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    piVar1 = DAT_00fb76e8;
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    local_5c = DAT_00fbab1c;
    FUN_0082ef00(&local_5c);
    if (local_44 == DAT_00fab13c) {
      local_5c = 0;
    }
    else {
      local_5c = *(int *)((int)local_44 + 0x10);
    }
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 2;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    local_44 = DAT_00fbab20;
    FUN_0082ef00(&local_44);
    if (local_58 == DAT_00fab13c) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)((int)local_58 + 0x10);
    }
    if ((local_5c != 0) && (piVar5 != (int *)0x0)) {
      local_58 = 0.0;
      local_54 = 0;
      local_50 = 0x3f800000;
      puVar2 = (undefined4 *)(**(code **)(*piVar5 + 0x50))(local_40);
      puVar3 = (undefined4 *)(**(code **)(*unaff_EBX + 0x50))(auStack_38);
      FUN_00798500(piVar1,*puVar3,puVar3[1],puVar3[2],*puVar2,puVar2[1],puVar2[2],unaff_EBX,local_5c
                   ,local_58);
      piVar1[9] = 0x41200000;
      piVar1[0x33] = 0;
      (**(code **)(*piVar5 + 0x50))(auStack_30);
      iVar4 = (**(code **)(*piVar5 + 0x4c))();
      if (20.0 < (float)(double)CONCAT44(local_54,local_58) - *(float *)(iVar4 + 8)) {
        piVar1[0x33] = 0;
        if (*piVar1 != 0) {
          local_58 = (float)piVar1[0x2f] * 1.1780972;
          *(float *)(*piVar1 + 0x74) = local_58;
        }
      }
    }
    if (((_DAT_00fbab24 <= 0.0) || (local_5c == 0)) || (piVar5 == (int *)0x0)) {
      DAT_00fbab18 = 0;
      DAT_00fbab1c = 0;
      DAT_00fbab20 = 0.0;
      _DAT_00fbab24 = 0.0;
      _DAT_00fbab28 = 0;
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 3;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_c = 0xffffffff;
      }
      FUN_007986e0(DAT_00fb76e8,"Behold");
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_5c);
  return;
}

