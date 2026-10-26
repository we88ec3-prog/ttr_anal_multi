
void FUN_005273c0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090b188;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)unaff_EDI[1];
  if ((in_ECX < puVar1) && (puVar2 = (undefined4 *)*unaff_EDI, puVar2 <= in_ECX)) {
    if (puVar1 == (undefined4 *)unaff_EDI[2]) {
      FUN_00527670(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar1 = (undefined4 *)unaff_EDI[1];
    in_ECX = (undefined4 *)(*unaff_EDI + (((int)in_ECX - (int)puVar2) / 0x24) * 0x24);
    local_8 = 0;
    if (puVar1 == (undefined4 *)0x0) goto LAB_00527492;
    *puVar1 = *in_ECX;
    FUN_004fcd00(puVar1 + 1,in_ECX + 1);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  else {
    if (puVar1 == (undefined4 *)unaff_EDI[2]) {
      FUN_00527670(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar1 = (undefined4 *)unaff_EDI[1];
    local_8 = 2;
    if (puVar1 == (undefined4 *)0x0) goto LAB_00527492;
    *puVar1 = *in_ECX;
    FUN_004fcd00(puVar1 + 1,in_ECX + 1);
    local_8 = CONCAT31(local_8._1_3_,3);
  }
  FUN_007e8a90(puVar1 + 5,in_ECX + 5);
LAB_00527492:
  unaff_EDI[1] = unaff_EDI[1] + 0x24;
  ExceptionList = local_10;
  return;
}

