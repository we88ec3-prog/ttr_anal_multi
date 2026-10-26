
void FUN_00717280(int *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  char *pcVar5;
  undefined1 auStack_44 [8];
  uint auStack_3c [4];
  undefined4 uStack_2c;
  uint uStack_28;
  int *piStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00919718;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_44;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x118) == 0) {
    *(int **)(in_ECX + 0x118) = param_1;
  }
  else {
    *(int **)(*(int *)(in_ECX + 0x11c) + 8) = param_1;
  }
  *(int **)(in_ECX + 0x11c) = param_1;
  param_1[1] = in_ECX;
  *(int *)(in_ECX + 0x130) = *(int *)(in_ECX + 0x130) + 1;
  pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(uVar2);
  uStack_28 = 0xf;
  uStack_2c = 0;
  auStack_3c[0] = auStack_3c[0] & 0xffffff00;
  pcVar5 = pcVar3;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b310(pcVar3);
  piStack_20 = param_1;
  uStack_c = 0;
  uVar4 = FUN_005435c0(auStack_3c);
  FUN_0080c560(in_ECX + 0x120,auStack_44,uVar4);
  if (0xf < uStack_28) {
    FUN_0089120c(auStack_3c[0]);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_44);
  return;
}

