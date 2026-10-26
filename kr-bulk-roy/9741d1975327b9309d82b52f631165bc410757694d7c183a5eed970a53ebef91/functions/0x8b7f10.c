
int FUN_008b7f10(int param_1,int param_2)

{
  longlong lVar1;
  
  lVar1 = (longlong)param_1 * (longlong)param_2 +
          (ulonglong)((int)((longlong)param_1 * (longlong)param_2 >> 0x3f) + 0x8000);
  return ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
}

