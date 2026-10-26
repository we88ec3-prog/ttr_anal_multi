
void FUN_00512ca0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  undefined4 uVar3;
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
      FUN_00512d70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    in_ECX = (undefined4 *)(*unaff_EDI + (((int)in_ECX - (int)puVar1) / 0x18) * 0x18);
    puVar2 = (undefined4 *)unaff_EDI[1];
    local_8 = 0;
    if (puVar2 == (undefined4 *)0x0) goto LAB_00512d54;
    *puVar2 = *in_ECX;
    uVar3 = in_ECX[1];
  }
  else {
    if (puVar2 == (undefined4 *)unaff_EDI[2]) {
      FUN_00512d70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar2 = (undefined4 *)unaff_EDI[1];
    local_8 = 1;
    if (puVar2 == (undefined4 *)0x0) goto LAB_00512d54;
    *puVar2 = *in_ECX;
    uVar3 = in_ECX[1];
  }
  puVar2[1] = uVar3;
  FUN_004fcd00(puVar2 + 2,in_ECX + 2);
LAB_00512d54:
  unaff_EDI[1] = unaff_EDI[1] + 0x18;
  ExceptionList = local_10;
  return;
}

