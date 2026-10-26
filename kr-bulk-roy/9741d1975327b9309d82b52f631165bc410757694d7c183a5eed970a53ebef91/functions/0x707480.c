
undefined4 FUN_00707480(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(ushort *)(param_1 + 0x36) < *(ushort *)(param_1 + 0x34)) {
    FUN_006f8b60(param_1,"attempt to yield across metamethod/C-call boundary");
  }
  *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 8) - (iVar1 - iVar2 & 0xfffffff0U);
  *(undefined1 *)(param_1 + 6) = 1;
  return 0xffffffff;
}

