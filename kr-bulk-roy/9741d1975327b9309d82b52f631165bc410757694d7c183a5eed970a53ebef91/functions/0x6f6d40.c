
undefined * FUN_006f6d40(undefined4 param_1,int *param_2,size_t *param_3)

{
  int iVar1;
  size_t sVar2;
  
  if (*param_2 != 0) {
    *param_2 = 0;
    *param_3 = 1;
    return &DAT_00c411c0;
  }
  iVar1 = _feof((FILE *)param_2[1]);
  if (iVar1 != 0) {
    return (undefined *)0x0;
  }
  sVar2 = _fread(param_2 + 2,1,0x200,(FILE *)param_2[1]);
  *param_3 = sVar2;
  return (undefined *)(-(uint)(sVar2 != 0) & (uint)(param_2 + 2));
}

