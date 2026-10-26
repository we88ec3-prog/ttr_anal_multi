
undefined4 * FUN_008271c0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte *in_EDX;
  undefined4 *puVar4;
  int unaff_EDI;
  byte local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  int local_3c [4];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009071c0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar4 = *(undefined4 **)(unaff_EDI + 4);
  if (*(char *)((int)puVar4[1] + 0x29) == '\0') {
    puVar2 = (undefined4 *)puVar4[1];
    do {
      if (*(byte *)(puVar2 + 3) < *in_EDX) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        puVar4 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x29) == '\0');
  }
  if ((puVar4 == *(undefined4 **)(unaff_EDI + 4)) || (*in_EDX < *(byte *)(puVar4 + 3))) {
    local_2c = 0;
    local_28 = 0x7fffffff;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_8 = 0;
    local_48[0] = *in_EDX;
    local_40 = 0x7fffffff;
    local_44 = 0;
    FUN_007e8a90(local_3c,&local_24);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00827c70(local_48);
    FUN_008274a0(unaff_EDI,puVar4);
    puVar4 = local_14;
    if (local_3c[0] != 0) {
      FUN_0089120c(local_3c[0],uVar1);
    }
  }
  ExceptionList = local_10;
  return puVar4 + 4;
}

