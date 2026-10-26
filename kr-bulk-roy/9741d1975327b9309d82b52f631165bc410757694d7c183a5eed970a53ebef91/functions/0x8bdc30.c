
undefined4 FUN_008bdc30(undefined4 *param_1,char *param_2)

{
  FILE *_File;
  long lVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0x28;
  }
  param_1[3] = 0;
  param_1[4] = param_2;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  _File = _fopen(param_2,"rb");
  if (_File == (FILE *)0x0) {
    return 1;
  }
  _fseek(_File,0,2);
  lVar1 = _ftell(_File);
  param_1[1] = lVar1;
  if (lVar1 == 0) {
    _fclose(_File);
    return 0x51;
  }
  _fseek(_File,0,0);
  param_1[3] = _File;
  param_1[5] = FUN_008bdbe0;
  param_1[6] = FUN_008bdbc0;
  return 0;
}

