
void FUN_0049e530(void)

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
      FUN_0049e620(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    in_ECX = (undefined4 *)(*unaff_EDI + (((int)in_ECX - (int)puVar1) / 0x24) * 0x24);
    puVar2 = (undefined4 *)unaff_EDI[1];
    local_8 = 0;
    if (puVar2 == (undefined4 *)0x0) goto LAB_0049e601;
    *puVar2 = *in_ECX;
    puVar2[1] = in_ECX[1];
  }
  else {
    if (puVar2 == (undefined4 *)unaff_EDI[2]) {
      FUN_0049e620(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar2 = (undefined4 *)unaff_EDI[1];
    local_8 = 1;
    if (puVar2 == (undefined4 *)0x0) goto LAB_0049e601;
    *puVar2 = *in_ECX;
    puVar2[1] = in_ECX[1];
  }
  puVar2[7] = 7;
  puVar2[6] = 0;
  *(undefined2 *)(puVar2 + 2) = 0;
  FUN_004026e0(in_ECX + 2,0,0xffffffff);
LAB_0049e601:
  unaff_EDI[1] = unaff_EDI[1] + 0x24;
  ExceptionList = local_10;
  return;
}

