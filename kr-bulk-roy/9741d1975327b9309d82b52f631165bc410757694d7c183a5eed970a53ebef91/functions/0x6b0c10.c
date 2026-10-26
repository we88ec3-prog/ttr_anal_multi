
bool FUN_006b0c10(int param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = *(ushort *)(param_2 + 4) < *(ushort *)(param_1 + 4);
  if (*(ushort *)(param_2 + 4) == *(ushort *)(param_1 + 4)) {
    bVar1 = *(ushort *)(param_1 + 8) < *(ushort *)(param_2 + 8);
  }
  return bVar1;
}

