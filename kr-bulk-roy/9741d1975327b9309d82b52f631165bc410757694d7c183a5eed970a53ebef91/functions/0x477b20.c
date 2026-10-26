
void FUN_00477b20(void)

{
  code *pcVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int *unaff_ESI;
  int iStack_28;
  float local_24;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00945052;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar3);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 1;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590(uVar3);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar3 = (uint)DAT_00f942c8;
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 3;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
  }
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 4;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
  }
  local_24 = (float)uVar3 / (float)DAT_00fb936c;
  if (1.0 <= local_24) {
    local_24 = 1.0;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 5;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar2 = DAT_00f942c8;
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 6;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
  }
  local_c = 0xffffffff;
  iVar4 = FUN_00822660(uVar2);
  (**(code **)(*(int *)unaff_ESI[0x58] + 0x90))(iVar4 != 0);
  pcVar1 = *(code **)(*(int *)unaff_ESI[0x49] + 0x128);
  ((int *)unaff_ESI[0x49])[0x34] = iStack_28;
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)unaff_ESI[0x4a] + 0x128);
  ((int *)unaff_ESI[0x4a])[0x34] = (int)local_24;
  (*pcVar1)();
  FUN_00476e10(unaff_ESI);
  FUN_004778b0();
  (**(code **)(*unaff_ESI + 200))();
  ExceptionList = pvStack_18;
  return;
}

