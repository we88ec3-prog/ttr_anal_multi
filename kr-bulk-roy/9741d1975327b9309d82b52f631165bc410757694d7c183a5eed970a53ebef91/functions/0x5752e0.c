
void FUN_005752e0(int *param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  char cVar3;
  char *pcVar4;
  undefined1 **ppuVar5;
  char *in_ECX;
  undefined2 local_b8 [6];
  undefined4 uStack_ac;
  int local_a8;
  int *local_a4;
  undefined4 ***pppuStack_a0;
  uint uStack_9c;
  undefined1 auStack_8c [4];
  int local_88;
  int iStack_84;
  undefined1 *local_80;
  undefined1 *local_7c;
  undefined4 ***local_78 [4];
  undefined4 local_68;
  uint local_64;
  undefined4 ***local_5c;
  uint uStack_48;
  undefined4 ***pppuStack_40;
  uint uStack_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009272a3;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_8c;
  uStack_9c = DAT_00d61f20 ^ (uint)&stack0xffffff68;
  ExceptionList = &local_14;
  local_88 = param_2;
  if (0xf < *(uint *)(in_ECX + 0x14)) {
    in_ECX = *(char **)in_ECX;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78[0] = (undefined4 ***)((uint)local_78[0] & 0xffffff00);
  pcVar4 = in_ECX;
  do {
    cVar3 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar3 != '\0');
  local_a4 = (int *)0x57535b;
  pppuStack_a0 = (undefined4 ***)in_ECX;
  FUN_0040b310();
  local_c = 0;
  iVar1 = *param_1;
  pppuStack_a0 = local_78;
  local_a4 = (int *)0x575374;
  local_7c = (undefined1 *)FUN_00575df0();
  if (local_7c != *(undefined1 **)(iVar1 + 4)) {
    pppuStack_a0 = (undefined4 ****)0x575389;
    cVar3 = FUN_005436a0();
    if (cVar3 == '\0') {
      ppuVar5 = &local_7c;
      goto LAB_0057539e;
    }
  }
  local_80 = *(undefined1 **)(iVar1 + 4);
  ppuVar5 = &local_80;
LAB_0057539e:
  puVar2 = *ppuVar5;
  local_c = 0xffffffff;
  if (0xf < local_64) {
    pppuStack_a0 = local_78[0];
    local_a4 = (int *)0x5753bc;
    FUN_0089120c();
  }
  if (puVar2 == *(undefined1 **)(*param_1 + 4)) {
    local_80 = (undefined1 *)local_b8;
    local_a4 = (int *)0x7;
    local_a8 = 0;
    local_b8[0] = 0;
    FUN_004026e0(local_88,0,0xffffffff);
    FUN_0047f6b0();
    pppuStack_a0 = (undefined4 ***)0x48;
    local_c = 1;
    local_a4 = (int *)0x575411;
    local_88 = FUN_00891268();
    local_c._0_1_ = 2;
    if (local_88 == 0) {
      iStack_84 = 0;
    }
    else {
      pppuStack_a0 = (undefined4 ***)0x57542b;
      iStack_84 = FUN_00734010();
    }
    local_c._0_1_ = 1;
    pppuStack_a0 = (undefined4 ***)0x575444;
    (**(code **)(*(int *)(iStack_84 + 4) + 4))();
    pppuStack_a0 = (undefined4 ***)0x57544f;
    (**(code **)(*(int *)(iStack_84 + 8) + 4))();
    local_a4 = (int *)0x575466;
    pppuStack_a0 = (undefined4 ***)iStack_84;
    FUN_007340c0();
    local_88 = 1;
    local_a4 = (int *)0x575480;
    pppuStack_a0 = (undefined4 ***)FUN_00575e70();
    local_c = CONCAT31(local_c._1_3_,3);
    iVar1 = *param_1;
    local_a4 = (int *)0x575495;
    pppuStack_a0 = (undefined4 ***)FUN_00576210();
    local_a4 = &local_88;
    uStack_ac = 0x5754a1;
    local_a8 = iVar1;
    FUN_00575f10();
    if (0xf < uStack_2c) {
      pppuStack_a0 = pppuStack_40;
      local_a4 = (int *)0x5754b6;
      FUN_0089120c();
    }
    if (0xf < uStack_48) {
      pppuStack_a0 = local_5c;
      local_a4 = (int *)0x5754c9;
      FUN_0089120c();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_8c);
  return;
}

