
void FUN_00539060(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  int *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_0090d022;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)unaff_EDI[1];
  if ((in_ECX < puVar2) && (puVar1 = (undefined4 *)*unaff_EDI, puVar1 <= in_ECX)) {
    if (puVar2 == (undefined4 *)unaff_EDI[2]) {
      FUN_004123e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar2 = (undefined4 *)unaff_EDI[1];
    in_ECX = (undefined4 *)(((int)in_ECX - (int)puVar1 & 0xfffffff0U) + *unaff_EDI);
  }
  else {
    if (puVar2 == (undefined4 *)unaff_EDI[2]) {
      FUN_004123e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar2 = (undefined4 *)unaff_EDI[1];
  }
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[2] = 0;
    puVar2[1] = 0;
    *puVar2 = 0;
    if (puVar2 != in_ECX) {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      *puVar2 = *in_ECX;
      puVar2[1] = in_ECX[1];
      puVar2[2] = in_ECX[2];
      *in_ECX = 0;
      in_ECX[2] = 0;
      in_ECX[1] = 0;
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x10;
  ExceptionList = local_10;
  return;
}

