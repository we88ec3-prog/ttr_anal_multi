
undefined4 FUN_00799ba0(undefined4 *param_1)

{
  FILE *_File;
  int _FileHandle;
  size_t _ElementSize;
  void *_DstBuf;
  undefined4 uVar1;
  undefined4 local_8;
  
  local_8 = 0;
  _File = _fopen("Material/Char_Skin.obj","rb");
  if (_File == (FILE *)0x0) {
    return 0;
  }
  _FileHandle = __fileno(_File);
  _ElementSize = __filelength(_FileHandle);
  _DstBuf = (void *)FUN_0087dc3d(_ElementSize);
  _fread(_DstBuf,_ElementSize,1,_File);
  _fclose(_File);
  uVar1 = (**(code **)(*(int *)*param_1 + 0x78))
                    ("Material/Char_Skin.obj",_DstBuf,_ElementSize,&local_8);
  FUN_00891d3d(_DstBuf);
  return uVar1;
}

