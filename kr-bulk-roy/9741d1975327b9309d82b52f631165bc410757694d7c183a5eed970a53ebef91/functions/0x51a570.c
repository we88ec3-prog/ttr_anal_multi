
undefined4 * FUN_0051a570(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *unaff_EDI;
  undefined1 local_a0 [68];
  undefined1 local_5c [4];
  undefined1 local_58 [68];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e1a5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar4 = DAT_00fe3704;
  if (*(char *)((int)DAT_00fe3704[1] + 0x55) == '\0') {
    puVar2 = (undefined4 *)DAT_00fe3704[1];
    do {
      if ((int)puVar2[3] < *unaff_EDI) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        puVar4 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x55) == '\0');
  }
  if ((puVar4 == DAT_00fe3704) || (*unaff_EDI < (int)puVar4[3])) {
    FUN_0051a430(local_a0);
    local_8 = 0;
    FUN_0051bd70(local_5c,unaff_EDI);
    local_8._0_1_ = 1;
    FUN_0051bc10(uVar1);
    FUN_0051b830(puVar4);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0051a4e0(local_58);
    local_8 = 0xffffffff;
    FUN_0051a4e0(local_a0);
    puVar4 = local_14;
  }
  ExceptionList = local_10;
  return puVar4 + 4;
}

