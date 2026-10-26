
undefined1 FUN_00717b60(void)

{
  undefined1 uVar1;
  char *in_EAX;
  FILE *_File;
  size_t sVar2;
  undefined2 local_8 [2];
  
  uVar1 = 0;
  _File = _fopen(in_EAX,"rb");
  if (_File != (FILE *)0x0) {
    sVar2 = _fread(local_8,2,1,_File);
    if (((sVar2 != 0) && ((char)local_8[0] == '\x1f')) && ((char)((ushort)local_8[0] >> 8) == -0x75)
       ) {
      uVar1 = 1;
    }
    _fclose(_File);
  }
  return uVar1;
}

