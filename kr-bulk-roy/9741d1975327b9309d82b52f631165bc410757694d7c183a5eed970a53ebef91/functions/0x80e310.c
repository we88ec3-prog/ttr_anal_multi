
void FUN_0080e310(char *param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined1 extraout_DL;
  undefined1 extraout_DL_00;
  undefined1 extraout_DL_01;
  undefined1 uVar5;
  undefined4 *puVar6;
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
  bVar2 = false;
  if (param_1 == (char *)0x0) {
    param_1 = "";
  }
  puVar3 = (undefined4 *)FUN_00891268(0x2c,local_14);
  local_8 = 0;
  uVar5 = extraout_DL;
  if (puVar3 != (undefined4 *)0x0) {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffffff00;
    pcVar4 = param_1;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    puVar6 = puVar3;
    FUN_0040b310(param_1);
    bVar2 = true;
    local_8 = 2;
    *puVar3 = CSound::vftable;
    puVar3[1] = 0;
    puVar3[7] = 0xf;
    puVar3[6] = 0;
    *(undefined1 *)(puVar3 + 2) = 0;
    FUN_0040b0b0(local_30,0);
    DAT_00fba864 = DAT_00fba864 + 1;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3[1] = puVar3[1] + 1;
    uVar5 = extraout_DL_00;
    puVar3 = puVar6;
  }
  if ((bVar2) && (0xf < local_1c)) {
    FUN_0089120c(local_30[0]);
    uVar5 = extraout_DL_01;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar5,puVar3);
  return;
}

