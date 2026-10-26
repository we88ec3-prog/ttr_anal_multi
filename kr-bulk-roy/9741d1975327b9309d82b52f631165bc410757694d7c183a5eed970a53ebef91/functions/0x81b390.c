
undefined4 FUN_0081b390(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((((*(int *)(param_1 + 0xc) != 0) &&
       (iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 8),
       *(uint *)(iVar1 + 8) == (uint)*(ushort *)(in_ECX + 8))) &&
      ((*(byte *)(in_ECX + 10) == 0 || (*(byte *)(in_ECX + 10) <= *(byte *)(iVar1 + 0xc))))) &&
     ((*(byte *)(in_ECX + 0xb) == 0 || (*(byte *)(iVar1 + 0xc) <= *(byte *)(in_ECX + 0xb))))) {
    return 1;
  }
  return 0;
}

