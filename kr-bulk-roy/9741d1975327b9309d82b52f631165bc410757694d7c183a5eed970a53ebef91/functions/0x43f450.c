
void FUN_0043f450(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *in_ECX;
  int *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905012;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined1 *)unaff_EDI[1];
  if ((in_ECX < puVar2) && (puVar1 = (undefined1 *)*unaff_EDI, puVar1 <= in_ECX)) {
    if (puVar2 == (undefined1 *)unaff_EDI[2]) {
      FUN_0043f600(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar2 = (undefined1 *)unaff_EDI[1];
    in_ECX = (undefined1 *)(((int)in_ECX - (int)puVar1 & 0xffffffe0U) + *unaff_EDI);
    local_8 = 0;
  }
  else {
    if (puVar2 == (undefined1 *)unaff_EDI[2]) {
      FUN_0043f600(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar2 = (undefined1 *)unaff_EDI[1];
    local_8 = 1;
  }
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = *in_ECX;
    *(undefined4 *)(puVar2 + 0x18) = 7;
    *(undefined4 *)(puVar2 + 0x14) = 0;
    *(undefined2 *)(puVar2 + 4) = 0;
    FUN_004026e0(in_ECX + 4,0,0xffffffff);
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x20;
  ExceptionList = local_10;
  return;
}

