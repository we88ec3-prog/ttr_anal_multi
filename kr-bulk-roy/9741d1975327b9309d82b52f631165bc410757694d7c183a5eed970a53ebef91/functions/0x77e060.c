
void FUN_0077e060(wchar_t *param_1,undefined4 param_2,undefined4 param_3)

{
  FILE *_File;
  size_t _ElementSize;
  void *_DstBuf;
  int iVar1;
  undefined1 local_8 [4];
  
  _File = __wfopen(param_1,L"rb");
  if (_File != (FILE *)0x0) {
    _fseek(_File,0,2);
    _ElementSize = _ftell(_File);
    _fseek(_File,0,0);
    _DstBuf = (void *)FUN_0087dc3d(_ElementSize);
    _fread(_DstBuf,_ElementSize,1,_File);
    _fclose(_File);
    param_1 = param_1 + 0x104;
    iVar1 = D3DXCreateEffect(param_2,_DstBuf,_ElementSize,0,0,0,param_3,param_1,local_8);
    if (iVar1 < 0) {
      param_1[0] = L'\0';
      param_1[1] = L'\0';
    }
    FUN_00891d3d(_DstBuf);
  }
  return;
}

