
/* WARNING: Type propagation algorithm not settling */

void FUN_004fa8e0(undefined4 *param_1)

{
  short sVar1;
  FILE *_File;
  wchar_t *pwVar2;
  short *psVar3;
  int in_ECX;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_40c;
  wchar_t local_408;
  undefined1 local_406 [510];
  short local_208;
  undefined1 auStack_206 [2];
  undefined1 local_204 [508];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_408 = L'\0';
  _memset(local_406,0,0x1fe);
  _File = (FILE *)*param_1;
  iVar5 = 0;
  puVar4 = (undefined4 *)(in_ECX + 0x2c);
  do {
    pwVar2 = _fgetws(&local_408,0xff,_File);
    if (pwVar2 == (wchar_t *)0x0) break;
    _local_208 = 0;
    _memset(local_204,0,0x1fc);
    local_40c = 0;
    FID_conflict__swscanf(&local_408,L"%s\t%d",&local_208,0x100,&local_40c);
    psVar3 = &local_208;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_00402160(&local_208,(int)psVar3 - (int)auStack_206 >> 1);
    *puVar4 = local_40c;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 8;
  } while (iVar5 < 10);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

