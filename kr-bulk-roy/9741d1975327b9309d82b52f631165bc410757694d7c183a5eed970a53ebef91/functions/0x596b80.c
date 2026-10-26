
/* WARNING: Removing unreachable block (ram,0x00596c45) */

void FUN_00596b80(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 local_4c;
  uint local_38;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f92e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar3 = (char *)FUN_0047f540(param_1,uVar2);
  local_8 = 0;
  pcVar5 = pcVar3;
  if (0xf < *(uint *)(pcVar3 + 0x14)) {
    pcVar3 = *(char **)pcVar3;
    pcVar5 = pcVar3;
  }
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_0040b310(pcVar5);
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8._0_1_ = 2;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  piVar4 = (int *)FUN_0080ab00(&DAT_00fab028);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x14))();
  }
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

