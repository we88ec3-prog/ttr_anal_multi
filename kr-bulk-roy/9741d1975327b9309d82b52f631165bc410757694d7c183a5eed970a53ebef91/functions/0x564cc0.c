
/* WARNING: Removing unreachable block (ram,0x00564d61) */

void FUN_00564cc0(char *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00932c16;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uVar5 = uVar2;
  FUN_0040b310(param_1);
  local_8 = 0;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_0080a3a0(uVar5);
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  piVar4 = (int *)FUN_0080ab00(&DAT_00fab028);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x14))();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

