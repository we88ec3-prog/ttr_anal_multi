
void FUN_006c8840(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910642;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)unaff_EDI[1];
  if ((in_ECX < puVar1) && (puVar2 = (undefined4 *)*unaff_EDI, puVar2 <= in_ECX)) {
    if (puVar1 == (undefined4 *)unaff_EDI[2]) {
      FUN_006c8950(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar3 = (undefined4 *)unaff_EDI[1];
    puVar1 = (undefined4 *)(*unaff_EDI + (((int)in_ECX - (int)puVar2) / 0x28) * 0x28);
    local_8 = 0;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = *puVar1;
      puVar3[5] = 0;
      puVar3[6] = 7;
      *(undefined2 *)(puVar3 + 1) = 0;
      FUN_004026e0(puVar1 + 1,0,0xffffffff);
      *(undefined1 *)(puVar3 + 8) = *(undefined1 *)(puVar1 + 8);
      puVar3[9] = puVar1[9];
    }
  }
  else {
    if (puVar1 == (undefined4 *)unaff_EDI[2]) {
      FUN_006c8950(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar1 = (undefined4 *)unaff_EDI[1];
    local_8 = 1;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *in_ECX;
      puVar1[5] = 0;
      puVar1[6] = 7;
      *(undefined2 *)(puVar1 + 1) = 0;
      FUN_004026e0(in_ECX + 1,0,0xffffffff);
      *(undefined1 *)(puVar1 + 8) = *(undefined1 *)(in_ECX + 8);
      puVar1[9] = in_ECX[9];
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x28;
  ExceptionList = local_10;
  return;
}

