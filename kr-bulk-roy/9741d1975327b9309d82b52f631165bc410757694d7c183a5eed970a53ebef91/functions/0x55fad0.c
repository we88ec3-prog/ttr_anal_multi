
void FUN_0055fad0(void)

{
  int *unaff_ESI;
  undefined1 auStack_38 [8];
  longlong local_30;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ae0c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*unaff_ESI != 0) {
    if (unaff_ESI[0xb] != 0) {
      if ((DAT_00fe2740 & 1) == 0) {
        DAT_00fe2740 = DAT_00fe2740 | 1;
        local_c = 0;
        FUN_0055e680(DAT_00d61f20 ^ (uint)auStack_38);
        _atexit((_func_4879 *)&DAT_00bcf2a0);
      }
      local_c = 0xffffffff;
      local_28 = (float)unaff_ESI[0xc] * 0.03125 + 2.0;
      local_24 = (float)unaff_ESI[0xd] * 0.03125 + 2.0;
      local_30 = (longlong)ROUND((float)unaff_ESI[0x16] * 255.0);
      (**(code **)(*DAT_00fe2744 + 0x24))
                (0xffffffe0,0xffffffe0,0,&local_28,0,0,(int)(void *)local_30 << 0x18 | 0xffffff);
      ExceptionList = (void *)local_30;
      return;
    }
    if ((DAT_00fe2740 & 1) == 0) {
      DAT_00fe2740 = DAT_00fe2740 | 1;
      local_c = 1;
      FUN_0055e680(DAT_00d61f20 ^ (uint)auStack_38);
      _atexit((_func_4879 *)&DAT_00bcf2a0);
    }
    local_c = 0xffffffff;
    local_20 = (float)unaff_ESI[0xc] * 0.03125 + 2.0;
    local_1c = (float)unaff_ESI[0xd] * 0.03125 + 2.0;
    (**(code **)(*DAT_00fe2744 + 0x24))(0xffffffe0,0xffffffe0,0,&local_20,0,0,0xffffffff);
  }
  ExceptionList = local_14;
  return;
}

