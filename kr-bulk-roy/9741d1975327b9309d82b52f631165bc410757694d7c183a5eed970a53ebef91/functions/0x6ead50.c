
int FUN_006ead50(wchar_t *param_1,wchar_t *param_2)

{
  uint _Count;
  int iVar1;
  uint uVar2;
  uint in_ECX;
  
  iVar1 = 0;
  if ((in_ECX == 0) || (0x7fffffff < in_ECX)) {
    iVar1 = -0x7ff8ffa9;
  }
  if (-1 < iVar1) {
    _Count = in_ECX - 1;
    iVar1 = 0;
    uVar2 = __vsnwprintf(param_1,_Count,param_2,&stack0x0000000c);
    if (((int)uVar2 < 0) || (_Count < uVar2)) {
      param_1[_Count] = L'\0';
      iVar1 = -0x7ff8ff86;
    }
    else if (uVar2 == _Count) {
      param_1[_Count] = L'\0';
      return 0;
    }
  }
  return iVar1;
}

