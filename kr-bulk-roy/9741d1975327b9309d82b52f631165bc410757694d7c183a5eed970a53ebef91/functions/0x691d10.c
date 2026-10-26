
void FUN_00691d10(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint in_ECX;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910642;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = unaff_EDI[1];
  if ((in_ECX < uVar2) && (uVar3 = *unaff_EDI, uVar3 <= in_ECX)) {
    if (uVar2 == unaff_EDI[2]) {
      FUN_00691e10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar4 = (undefined2 *)unaff_EDI[1];
    iVar1 = *unaff_EDI + ((int)(in_ECX - uVar3) / 0x24) * 0x24;
    local_8 = 0;
    if (puVar4 != (undefined2 *)0x0) {
      *(undefined4 *)(puVar4 + 10) = 7;
      *(undefined4 *)(puVar4 + 8) = 0;
      *puVar4 = 0;
      FUN_004026e0(iVar1,0,0xffffffff);
      *(undefined4 *)(puVar4 + 0xe) = *(undefined4 *)(iVar1 + 0x1c);
      *(undefined4 *)(puVar4 + 0x10) = *(undefined4 *)(iVar1 + 0x20);
    }
  }
  else {
    if (uVar2 == unaff_EDI[2]) {
      FUN_00691e10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar4 = (undefined2 *)unaff_EDI[1];
    local_8 = 1;
    if (puVar4 != (undefined2 *)0x0) {
      *(undefined4 *)(puVar4 + 10) = 7;
      *(undefined4 *)(puVar4 + 8) = 0;
      *puVar4 = 0;
      FUN_004026e0(in_ECX,0,0xffffffff);
      *(undefined4 *)(puVar4 + 0xe) = *(undefined4 *)(in_ECX + 0x1c);
      *(undefined4 *)(puVar4 + 0x10) = *(undefined4 *)(in_ECX + 0x20);
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x24;
  ExceptionList = local_10;
  return;
}

