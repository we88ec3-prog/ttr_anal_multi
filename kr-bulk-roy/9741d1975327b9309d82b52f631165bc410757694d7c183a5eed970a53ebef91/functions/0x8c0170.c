
void FUN_008c0170(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_90;
  undefined4 *local_8c;
  char local_88 [128];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_8c = param_4;
  iVar3 = _strncmp(param_1,"ENDPROPERTIES",0xd);
  if (iVar3 == 0) {
    uVar1 = param_5[8];
    iVar3 = FUN_008bfab0();
    if (iVar3 == 0) {
      *(int *)(uVar1 + 0x28) = (int)*(short *)(uVar1 + 0xc);
      _sprintf(local_88,"%hd",(int)*(short *)(param_5[8] + 0xc));
      iVar3 = FUN_008bec60("FONT_ASCENT",local_88);
      if (iVar3 != 0) goto LAB_008c0280;
      *(undefined2 *)(param_5[8] + 0x44084) = 1;
    }
    uVar1 = param_5[8];
    iVar3 = FUN_008bfab0();
    if (iVar3 == 0) {
      *(int *)(uVar1 + 0x2c) = (int)*(short *)(uVar1 + 0xe);
      _sprintf(local_88,"%hd",(int)*(short *)(param_5[8] + 0xe));
      iVar3 = FUN_008bec60("FONT_DESCENT",local_88);
      if (iVar3 != 0) goto LAB_008c0280;
      *(undefined2 *)(param_5[8] + 0x44084) = 1;
    }
    *param_5 = *param_5 & 0xffffffef;
    *local_8c = FUN_008bef80;
  }
  else {
    iVar3 = _strncmp(param_1,"_XFREE86_GLYPH_RANGES",0x15);
    if (iVar3 != 0) {
      iVar3 = _strncmp(param_1,"COMMENT",7);
      if (iVar3 == 0) {
        pcVar4 = param_1 + 7;
        if (param_1[7] != '\0') {
          *pcVar4 = '\0';
          pcVar4 = param_1 + 8;
        }
        FUN_008bec60(param_1,pcVar4);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      iVar3 = FUN_008beb90(param_2,&local_8c,param_5[8]);
      if (iVar3 != 0) {
        FUN_008bec60(local_90,local_8c);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      iVar3 = FUN_008be0f0(param_1,param_2);
      if (iVar3 == 0) {
        uVar2 = *(undefined4 *)param_5[0x880a];
        FUN_008be040();
        uVar5 = FUN_008be080(0x20,&local_90);
        FUN_008bec60(uVar2,uVar5);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
LAB_008c0280:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

