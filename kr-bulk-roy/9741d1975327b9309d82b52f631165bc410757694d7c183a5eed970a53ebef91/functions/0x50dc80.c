
undefined4 * FUN_0050dc80(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *in_EDX;
  undefined4 *puVar5;
  int unaff_EDI;
  int local_58 [3];
  int local_4c [4];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d4b0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar5 = *(undefined4 **)(unaff_EDI + 4);
  if (*(char *)((int)puVar5[1] + 0x31) == '\0') {
    puVar2 = (undefined4 *)puVar5[1];
    do {
      if ((int)puVar2[3] < *in_EDX) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        puVar5 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x31) == '\0');
  }
  if ((puVar5 == *(undefined4 **)(unaff_EDI + 4)) || (*in_EDX < (int)puVar5[3])) {
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_8 = 0;
    local_58[0] = *in_EDX;
    FUN_007e8a90(local_4c,&local_2c);
    local_3c = local_1c;
    local_38 = local_18;
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar4 = FUN_0050fe60(local_58);
    FUN_0050f320(puVar5,uVar4);
    puVar5 = local_14;
    if (local_4c[0] != 0) {
      FUN_0089120c(local_4c[0],uVar1);
    }
  }
  ExceptionList = local_10;
  return puVar5 + 4;
}

