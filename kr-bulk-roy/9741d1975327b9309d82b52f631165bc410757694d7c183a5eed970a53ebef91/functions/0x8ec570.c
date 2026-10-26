
int FUN_008ec570(int param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = FUN_008ec480();
  lVar1 = (longlong)*(int *)(*(int *)(param_1 + 0x180) + param_2 * 4) * (longlong)iVar2;
  lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
  return ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
}

