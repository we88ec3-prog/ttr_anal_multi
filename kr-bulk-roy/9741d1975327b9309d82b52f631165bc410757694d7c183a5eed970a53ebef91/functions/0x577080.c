
void FUN_00577080(void)

{
  uint uVar1;
  uint unaff_EBX;
  int unaff_EDI;
  undefined1 auStack_58 [12];
  undefined4 uStack_4c;
  uint uStack_48;
  uint auStack_40 [4];
  undefined4 uStack_30;
  uint uStack_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0091b030;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_58;
  ExceptionList = &local_14;
  if ((*(int *)(unaff_EDI + 0x80) == 0) && (*(int *)(unaff_EDI + 0x78) != 0)) {
    (**(code **)(**(int **)(*(int *)(unaff_EDI + 4) + 8) + 0x38))
              (0xffffffff,0xffffffff,DAT_00d61f20 ^ (uint)&stack0xffffffa0);
    uStack_48 = 0xf;
    uStack_4c = 0;
    uVar1 = unaff_EBX >> 8;
    FUN_0040b310("Icon2");
    local_14 = (void *)0x0;
    FUN_005756d0(&stack0xffffffa4);
    local_14 = (void *)0xffffffff;
    if (0xf < uStack_48) {
      FUN_0089120c(uVar1 << 8);
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    FUN_0040b310("Icon0");
    local_14 = (void *)0x1;
    FUN_005756d0(&stack0xffffffa4);
    local_14 = (void *)0xffffffff;
    if (0xf < uStack_48) {
      FUN_0089120c(uVar1 << 8);
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    FUN_0040b310("Icon1");
    local_14 = (void *)0x2;
    FUN_005756d0(&stack0xffffffa4);
    local_14 = (void *)0xffffffff;
    if (0xf < uStack_48) {
      FUN_0089120c(uVar1 << 8);
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    FUN_0040b310("Icon2");
    local_14 = (void *)0x3;
    FUN_005756d0(&stack0xffffffa4);
    local_14 = (void *)0xffffffff;
    if (0xf < uStack_48) {
      FUN_0089120c(uVar1 << 8);
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    FUN_0040b310("Icon0");
    local_14 = (void *)0x4;
    FUN_005756d0(&stack0xffffffa4);
    local_14 = (void *)0xffffffff;
    if (0xf < uStack_48) {
      FUN_0089120c(uVar1 << 8);
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    auStack_40[0] = auStack_40[0] & 0xffffff00;
    FUN_0040b310("Icon1");
    local_14 = (void *)0x5;
    FUN_005756d0(auStack_40);
    local_14 = (void *)0xffffffff;
    if (0xf < uStack_2c) {
      FUN_0089120c(auStack_40[0]);
    }
    uStack_2c = 0xf;
    uStack_30 = 0;
    auStack_40[0] = auStack_40[0] & 0xffffff00;
    (**(code **)(**(int **)(*(int *)(unaff_EDI + 4) + 8) + 0x3c))();
    *(undefined4 *)(unaff_EDI + 0x80) = 1;
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_58);
  return;
}

