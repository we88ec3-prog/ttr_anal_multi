
void FUN_00508a20(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint in_ECX;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910581;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = unaff_EDI[1];
  if ((in_ECX < uVar2) && (uVar3 = *unaff_EDI, uVar3 <= in_ECX)) {
    if (uVar2 == unaff_EDI[2]) {
      FUN_005316e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar1 = (undefined4 *)(*unaff_EDI + ((int)(in_ECX - uVar3) / 0x28) * 0x28);
    puVar4 = (undefined4 *)unaff_EDI[1];
    local_8 = 0;
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = *puVar1;
      puVar4[1] = puVar1[1];
      puVar4[2] = puVar1[2];
      puVar4[8] = 7;
      puVar4[7] = 0;
      *(undefined2 *)(puVar4 + 3) = 0;
      FUN_004026e0(puVar1 + 3,0,0xffffffff);
      unaff_EDI[1] = unaff_EDI[1] + 0x28;
      ExceptionList = local_10;
      return;
    }
  }
  else {
    if (uVar2 == unaff_EDI[2]) {
      FUN_005316e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    FUN_00531930(unaff_EDI[1]);
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x28;
  ExceptionList = local_10;
  return;
}

