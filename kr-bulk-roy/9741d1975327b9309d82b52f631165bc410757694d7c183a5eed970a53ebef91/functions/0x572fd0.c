
void FUN_00572fd0(int *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  undefined1 **ppuVar3;
  undefined1 local_bc [16];
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  char *local_84;
  char *pcStack_80;
  uint uStack_7c;
  undefined1 *local_6c;
  undefined1 *local_68;
  int *local_64;
  char *local_60;
  undefined4 local_5c;
  uint local_48;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b138;
  local_10 = ExceptionList;
  uStack_7c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcStack_80 = (char *)0x0;
  local_84 = (char *)0x0;
  local_88 = 0;
  uStack_8c = 0;
  uStack_90 = 0;
  local_64 = param_1;
  local_68 = local_bc;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_a8 = 0xf;
  local_ac = 0;
  local_94 = 0;
  local_bc[0] = 0;
  local_14 = uStack_7c;
  FUN_00402a70(&DAT_00bf2375,0);
  FUN_005750f0();
  local_8 = 0;
  pcStack_80 = (char *)0x573061;
  FUN_00572f70();
  local_8 = 0xffffffff;
  if (0xf < local_48) {
    pcStack_80 = (char *)local_5c;
    local_84 = (char *)0x573077;
    FUN_0089120c();
  }
  iVar1 = *local_64;
  pcStack_80 = local_60;
  local_84 = (char *)0x57308a;
  local_6c = (undefined1 *)FUN_006cf160();
  if (local_6c != *(undefined1 **)(iVar1 + 4)) {
    pcStack_80 = (char *)0x57309c;
    cVar2 = FUN_005436a0();
    if (cVar2 == '\0') {
      ppuVar3 = &local_6c;
      goto LAB_005730ae;
    }
  }
  local_68 = *(undefined1 **)(iVar1 + 4);
  ppuVar3 = &local_68;
LAB_005730ae:
  if (*ppuVar3 != *(undefined1 **)(*local_64 + 4)) {
    pcStack_80 = (char *)0x5730c4;
    FUN_00572aa0();
    if (*(int *)(param_2 + 0x34) == 6) {
      if (0xf < *(uint *)(local_60 + 0x14)) {
        local_60 = *(char **)local_60;
      }
      pcStack_80 = local_60;
      do {
        cVar2 = *pcStack_80;
        pcStack_80 = pcStack_80 + 1;
      } while (cVar2 != '\0');
      pcStack_80 = pcStack_80 + -(int)(local_60 + 1);
      local_88 = 0x5730f2;
      local_84 = local_60;
      FUN_00402a70();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

