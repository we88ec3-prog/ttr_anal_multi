
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00546d50(char *param_1)

{
  HWND pHVar1;
  char cVar2;
  char cVar3;
  HWND pHVar4;
  int iVar5;
  float10 fVar6;
  float local_2c;
  float local_28;
  int local_24;
  int local_20;
  void *pvStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0092eefe;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 0;
    FUN_006d0750(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  local_c = 0xffffffff;
  if (DAT_00fb8830 == 0) {
    pHVar1 = *(HWND *)(DAT_00fb1318 + 0x10);
    pHVar4 = GetForegroundWindow();
    if (pHVar4 == pHVar1) {
      local_24 = 0;
      local_20 = 0;
      if ((_DAT_00fc1a6c & 1) == 0) {
        _DAT_00fc1a6c = _DAT_00fc1a6c | 1;
        _atexit((_func_4879 *)&DAT_00bce3b0);
      }
      FUN_006f3350(0);
      local_2c = (float)local_24;
      local_28 = (float)local_20;
      fVar6 = (float10)FUN_008ff870();
      if (10240.0 < (float)fVar6) {
        D3DXVec2Normalize(&local_2c,&local_2c);
        fVar6 = (float10)FUN_008fedca();
        cVar2 = FUN_004bb450(3.1415927 - ((float)fVar6 + 1.5707964));
        iVar5 = FUN_00434740();
        cVar3 = FUN_004bb450(*(undefined4 *)(*(int *)(iVar5 + 0x40) + 0x20));
        *param_1 = cVar3 + cVar2;
        ExceptionList = pvStack_1c;
        return 1;
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}

