
void FUN_007dfb60(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905012;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)unaff_EDI[1];
  if ((in_ECX < puVar2) && (puVar1 = (undefined4 *)*unaff_EDI, puVar1 <= in_ECX)) {
    if (puVar2 == (undefined4 *)unaff_EDI[2]) {
      FUN_007dfd30(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    in_ECX = (undefined4 *)(*unaff_EDI + (((int)in_ECX - (int)puVar1) / 0x14) * 0x14);
    puVar2 = (undefined4 *)unaff_EDI[1];
    local_8 = 0;
    if (puVar2 == (undefined4 *)0x0) goto LAB_007dfc0b;
    *puVar2 = *in_ECX;
  }
  else {
    if (puVar2 == (undefined4 *)unaff_EDI[2]) {
      FUN_007dfd30(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar2 = (undefined4 *)unaff_EDI[1];
    local_8 = 1;
    if (puVar2 == (undefined4 *)0x0) goto LAB_007dfc0b;
    *puVar2 = *in_ECX;
  }
  FUN_007e01e0(puVar2 + 1,in_ECX + 1);
LAB_007dfc0b:
  unaff_EDI[1] = unaff_EDI[1] + 0x14;
  ExceptionList = local_10;
  return;
}

