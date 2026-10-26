
void FUN_007cf480(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  char *in_ECX;
  int in_EDX;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009284c8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar4 = in_ECX;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  local_38 = in_EDX;
  local_14 = uVar3;
  FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
  local_8 = 0;
  local_3c = FUN_007b6f30(local_30);
  if (local_3c != *(int *)(in_EDX + 0x14)) {
    cVar2 = FUN_0049ae30(uVar3);
    if (cVar2 == '\0') {
      piVar5 = &local_3c;
      goto LAB_007cf50d;
    }
  }
  local_34 = *(int *)(in_EDX + 0x14);
  piVar5 = &local_34;
LAB_007cf50d:
  iVar1 = *piVar5;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  if ((iVar1 != *(int *)(in_EDX + 0x14)) &&
     (iVar6 = *(int *)(*(int *)(iVar1 + 0x28) + 4) + -1,
     *(int *)(*(int *)(iVar1 + 0x28) + 4) = iVar6, iVar6 == 0)) {
    FUN_007ee1c0();
    FUN_007ee180();
    FUN_007ee410();
    if (*(int *)(iVar1 + 0x28) != 0) {
      FUN_007cf5b0();
      *(undefined4 *)(iVar1 + 0x28) = 0;
    }
    FUN_007c2e30(in_EDX + 0x10,&local_34,iVar1);
    in_EDX = local_38;
  }
  FUN_007cf170(in_EDX);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

