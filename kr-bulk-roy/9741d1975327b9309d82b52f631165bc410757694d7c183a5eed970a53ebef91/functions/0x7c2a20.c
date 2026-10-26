
void FUN_007c2a20(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char cVar4;
  uint uVar5;
  char *pcVar6;
  int *piVar7;
  char *in_ECX;
  int unaff_EDI;
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
  puStack_c = &LAB_00917838;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar6 = in_ECX;
  do {
    cVar4 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar4 != '\0');
  local_14 = uVar5;
  FUN_00402a70(in_ECX,(int)pcVar6 - (int)(in_ECX + 1));
  local_8 = 0;
  local_38 = FUN_007b6f30(local_30);
  if (local_38 != *(int *)(unaff_EDI + 4)) {
    cVar4 = FUN_0049ae30(uVar5);
    if (cVar4 == '\0') {
      piVar7 = &local_38;
      goto LAB_007c2aa6;
    }
  }
  local_34 = *(int *)(unaff_EDI + 4);
  piVar7 = &local_34;
LAB_007c2aa6:
  iVar1 = *piVar7;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  if (iVar1 != *(int *)(unaff_EDI + 4)) {
    iVar2 = *(int *)(iVar1 + 0x28);
    puVar3 = *(undefined4 **)(iVar2 + 0x1c);
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(1);
      *(undefined4 *)(iVar2 + 0x1c) = 0;
    }
    if (*(int *)(iVar1 + 0x28) != 0) {
      FUN_007c2b30();
      *(undefined4 *)(iVar1 + 0x28) = 0;
    }
    FUN_007c2e30(unaff_EDI,&local_34,iVar1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

