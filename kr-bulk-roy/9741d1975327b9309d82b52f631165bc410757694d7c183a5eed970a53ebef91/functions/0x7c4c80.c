
void FUN_007c4c80(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  undefined4 local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009388e8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_007c5600(local_30);
  local_8 = 0;
  iVar3 = *(int *)(unaff_EDI + 0x28);
  if (iVar3 != *(int *)(unaff_EDI + 0x2c)) {
    do {
      iVar2 = FUN_007c4b70(uVar1);
      if (iVar2 == 0) {
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        goto LAB_007c4cfc;
      }
      iVar3 = iVar3 + 0x68;
    } while (iVar3 != *(int *)(unaff_EDI + 0x2c));
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
LAB_007c4cfc:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

