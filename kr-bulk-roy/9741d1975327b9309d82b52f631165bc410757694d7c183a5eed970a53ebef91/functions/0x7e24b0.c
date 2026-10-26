
void FUN_007e24b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  int *piVar6;
  char *in_ECX;
  int *unaff_EDI;
  int local_3c;
  int local_38;
  int *local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914bf8;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar5 = in_ECX;
  do {
    cVar3 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar3 != '\0');
  local_14 = uVar4;
  FUN_00402a70(in_ECX,(int)pcVar5 - (int)(in_ECX + 1));
  local_34 = unaff_EDI + 2;
  local_8 = 0;
  local_3c = FUN_007b6f30(local_30);
  if ((local_3c == unaff_EDI[3]) || (cVar3 = FUN_0049ae30(uVar4), cVar3 != '\0')) {
    local_38 = unaff_EDI[3];
    piVar6 = &local_38;
  }
  else {
    piVar6 = &local_3c;
  }
  iVar1 = *piVar6;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  if (((iVar1 != unaff_EDI[3]) &&
      (**(int **)(iVar1 + 0x28) = **(int **)(iVar1 + 0x28) + -1, unaff_EDI[1] == 0)) &&
     (**(int **)(iVar1 + 0x28) == 0)) {
    if (0 < *unaff_EDI) {
      (**(code **)(*(int *)(*(int **)(iVar1 + 0x28))[1] + 0x10))();
    }
    puVar2 = *(undefined4 **)(*(int *)(iVar1 + 0x28) + 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
      *(undefined4 *)(*(int *)(iVar1 + 0x28) + 4) = 0;
    }
    if (*(int *)(iVar1 + 0x28) != 0) {
      FUN_0089120c(*(int *)(iVar1 + 0x28));
      *(undefined4 *)(iVar1 + 0x28) = 0;
    }
    FUN_007c2e30(local_34,&local_34,iVar1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

