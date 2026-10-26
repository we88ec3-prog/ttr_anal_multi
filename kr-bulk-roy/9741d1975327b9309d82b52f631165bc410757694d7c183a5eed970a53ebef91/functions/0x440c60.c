
void FUN_00440c60(void)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint in_ECX;
  uint *unaff_EDI;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905012;
  local_10 = *unaff_FS_OFFSET;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  uVar1 = unaff_EDI[1];
  if ((in_ECX < uVar1) && (uVar2 = *unaff_EDI, uVar2 <= in_ECX)) {
    if (uVar1 == unaff_EDI[2]) {
      FUN_00440be0(uVar4);
    }
    in_ECX = *unaff_EDI + ((int)(in_ECX - uVar2) / 0x1c) * 0x1c;
    puVar3 = (undefined1 *)unaff_EDI[1];
    local_8 = 0;
  }
  else {
    if (uVar1 == unaff_EDI[2]) {
      FUN_00440be0(uVar4);
    }
    puVar3 = (undefined1 *)unaff_EDI[1];
    local_8 = 1;
  }
  if (puVar3 != (undefined1 *)0x0) {
    *(undefined4 *)(puVar3 + 0x14) = 0xf;
    *(undefined4 *)(puVar3 + 0x10) = 0;
    *puVar3 = 0;
    FUN_00403040(in_ECX,0,0xffffffff);
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x1c;
  *unaff_FS_OFFSET = local_10;
  return;
}

