
/* WARNING: Removing unreachable block (ram,0x007efa48) */

void FUN_007ef940(void)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int in_ECX;
  char *pcVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937786;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)(in_ECX + 0x38);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    if ((DAT_00fe1ac0 & 1) == 0) {
      DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
      local_8 = 0;
      FUN_007bb970(uVar3);
      _atexit((_func_4879 *)&LAB_00bceac0);
    }
    local_8 = 0xffffffff;
    FUN_007bcf60();
    pcVar5 = (char *)(in_ECX + 0xb4);
    if (0xf < *(uint *)(in_ECX + 200)) {
      pcVar5 = *(char **)pcVar5;
    }
    pcVar4 = pcVar5;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    FUN_00402a70(pcVar5,(int)pcVar4 - (int)(pcVar5 + 1));
    local_8 = 1;
    FUN_00401fc0("mesh/",5);
    if (*(uint *)(in_ECX + 0x58) < 0x10) {
      pcVar5 = (char *)(in_ECX + 0x44);
    }
    else {
      pcVar5 = *(char **)(in_ECX + 0x44);
    }
    pcVar4 = pcVar5;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    FUN_00401fc0(pcVar5,(int)pcVar4 - (int)(pcVar5 + 1));
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

