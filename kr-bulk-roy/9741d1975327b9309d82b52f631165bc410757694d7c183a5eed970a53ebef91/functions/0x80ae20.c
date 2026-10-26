
void FUN_0080ae20(void)

{
  undefined4 *puVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar2;
  undefined4 *puVar3;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091849c;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = FUN_00891268(0x2c,local_14);
  puVar1 = (undefined4 *)uVar2;
  local_8 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffffff00;
    puVar3 = puVar1;
    FUN_0040b310(&DAT_00bf2375);
    local_8 = 2;
    *puVar1 = CSound::vftable;
    puVar1[1] = 0;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
    FUN_0040b0b0(local_30,0);
    uVar2 = CONCAT44(extraout_EDX,puVar3);
    DAT_00fba864 = DAT_00fba864 + 1;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[1] = puVar1[1] + 1;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
      uVar2 = CONCAT44(extraout_EDX_00,puVar3);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie
            (local_14 ^ (uint)&stack0xfffffffc,(int)((ulonglong)uVar2 >> 0x20),(int)uVar2);
  return;
}

