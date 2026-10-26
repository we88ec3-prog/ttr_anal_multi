
void FUN_007edbf0(int *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 local_12c [56];
  char local_f4 [127];
  char cStack_75;
  char local_74 [64];
  char local_34 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091872b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (*param_1 != 0) {
    __splitpath(param_2,(char *)0x0,local_f4,local_74,local_34);
    pcVar3 = local_34;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar4 = (int)pcVar3 - (int)local_34;
    pcVar3 = &cStack_75;
    do {
      pcVar6 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar6 != '\0');
    pcVar6 = local_34;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar3 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar3 = pcVar3 + 1;
    }
    FUN_007ed8d0(local_12c,local_74);
    local_8 = 0;
    FUN_007edcd0(uVar2);
    FUN_007ee080();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

