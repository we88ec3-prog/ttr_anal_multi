
void FUN_00717bc0(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  char ****_Filename;
  FILE *_File;
  char *in_ECX;
  char *in_EDX;
  undefined4 *puVar6;
  char ***local_50 [4];
  undefined4 local_40;
  uint local_3c;
  char local_34 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915c28;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_3c = 0xf;
  local_40 = 0;
  local_50[0] = (char ***)((uint)local_50[0] & 0xffffff00);
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_8 = 0;
  _strcpy_s(local_34,0x20,in_EDX);
  if ((*in_EDX == 'w') || (*in_EDX == 'W')) {
    _strcat_s(local_34,0x20,"8");
  }
  iVar4 = FUN_00728990(local_34,uVar2);
  if (iVar4 == 0) {
    FUN_00401fc0(&PTR_LAB_00c44404,3);
    iVar4 = FUN_00728990(local_34);
    if (iVar4 == 0) {
      if (0xf < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      goto LAB_00717d28;
    }
  }
  puVar5 = (undefined4 *)FUN_00891268(0x10);
  puVar6 = (undefined4 *)0x0;
  if (puVar5 != (undefined4 *)0x0) {
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    *puVar5 = StdCompressedFile::vftable;
    puVar6 = puVar5;
  }
  puVar6[1] = iVar4;
  if ((*in_EDX == 'r') || (*in_EDX == 'R')) {
    _Filename = (char ****)local_50[0];
    if (local_3c < 0x10) {
      _Filename = local_50;
    }
    _File = _fopen((char *)_Filename,"rb");
    if (_File != (FILE *)0x0) {
      _fseek(_File,-4,2);
      _fread(puVar6 + 3,4,1,_File);
      _fclose(_File);
    }
  }
  if (0xf < local_3c) {
    FUN_0089120c(local_50[0]);
  }
LAB_00717d28:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

