
size_t FUN_008bdbe0(int param_1,uint param_2,void *param_3,size_t param_4)

{
  FILE *_File;
  size_t sVar1;
  
  if ((param_4 == 0) && (*(uint *)(param_1 + 4) < param_2)) {
    return 1;
  }
  _File = *(FILE **)(param_1 + 0xc);
  if (*(uint *)(param_1 + 8) != param_2) {
    _fseek(_File,param_2,0);
  }
  sVar1 = _fread(param_3,1,param_4,_File);
  return sVar1;
}

