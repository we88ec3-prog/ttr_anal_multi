
void FUN_008c03a0(char *param_1,undefined4 param_2,undefined4 param_3,undefined **param_4,
                 uint *param_5)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  void *_Src;
  ushort uVar6;
  char *pcVar7;
  ushort uVar8;
  size_t _Size;
  undefined **local_94;
  uint local_90;
  int local_8c;
  char local_88 [128];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_94 = param_4;
  local_90 = 0;
  local_8c = 0;
  if (param_5[8] != 0) {
    local_90 = *(uint *)(param_5[8] + 0x44088);
  }
  iVar3 = _strncmp(param_1,"COMMENT",7);
  if (iVar3 == 0) {
    if ((*(int *)(param_5[9] + 8) != 0) && (param_5[8] != 0)) {
      pcVar7 = param_1 + 7;
      if (*pcVar7 != '\0') {
        pcVar7 = param_1 + 8;
      }
      FUN_008be980(pcVar7);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_008c0598:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((*param_5 & 1) == 0) {
    uVar4 = param_5[0x880e];
    local_90 = uVar4;
    iVar3 = _strncmp(param_1,"STARTFONT",9);
    if (iVar3 != 0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    *param_5 = 1;
    param_5[8] = 0;
    uVar4 = FUN_008baee0(uVar4,0x440a4,&local_8c);
    if (local_8c == 0) {
      param_5[8] = uVar4;
      *(uint *)(uVar4 + 0x44088) = param_5[0x880e];
      param_5[0x880e] = 0;
      local_8c = FUN_008bde40();
      if (local_8c == 0) {
        uVar4 = 0;
        local_94 = &PTR_s_ADD_STYLE_NAME_00bd74f0;
        do {
          local_8c = 0;
          local_8c = FUN_008bded0(uVar4,local_90);
          if (local_8c != 0) goto LAB_008c0598;
          local_94 = local_94 + 4;
          uVar4 = uVar4 + 1;
        } while (uVar4 < 0x53);
        uVar5 = FUN_008baee0(local_90,0x10,&local_8c);
        *(undefined4 *)(param_5[8] + 0x80) = uVar5;
        if ((local_8c == 0) && (local_8c = FUN_008bde40(), local_8c == 0)) {
          *(undefined4 *)(param_5[8] + 0x1c) = *(undefined4 *)(param_5[9] + 0xc);
          *(undefined4 *)(param_5[8] + 0x24) = 0xffffffff;
        }
      }
    }
    goto LAB_008c0598;
  }
  iVar3 = _strncmp(param_1,"STARTPROPERTIES",0xf);
  if (iVar3 == 0) {
    if ((*param_5 & 8) == 0) {
LAB_008c05c6:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_8c = FUN_008be0f0(param_1,param_2);
    if (local_8c == 0) {
      uVar4 = FUN_008be520(0,10);
      *(uint *)(param_5[8] + 0x48) = uVar4;
      param_5[1] = uVar4;
      uVar5 = FUN_008bc7d0(local_90,0x10,0,uVar4,0,&local_8c);
      *(undefined4 *)(param_5[8] + 0x50) = uVar5;
      if (local_8c == 0) {
        *param_5 = *param_5 | 0x10;
        *local_94 = FUN_008c0170;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      *(undefined4 *)(param_5[8] + 0x48) = 0;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    goto LAB_008c0598;
  }
  iVar3 = _strncmp(param_1,"FONTBOUNDINGBOX",0xf);
  if (iVar3 == 0) {
    if ((*param_5 & 4) == 0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_8c = FUN_008be0f0(param_1,param_2);
    if (local_8c == 0) {
      uVar2 = FUN_008be700(0,10);
      *(undefined2 *)(param_5[8] + 4) = uVar2;
      uVar2 = FUN_008be700(0,10);
      *(undefined2 *)(param_5[8] + 6) = uVar2;
      uVar2 = FUN_008be700(0,10);
      *(undefined2 *)(param_5[8] + 8) = uVar2;
      uVar2 = FUN_008be700(0,10);
      *(undefined2 *)(param_5[8] + 10) = uVar2;
      uVar4 = param_5[8];
      *(short *)(uVar4 + 0xc) = *(short *)(uVar4 + 10) + *(short *)(uVar4 + 6);
      *(short *)(param_5[8] + 0xe) = -*(short *)(param_5[8] + 10);
      *param_5 = *param_5 | 8;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    goto LAB_008c0598;
  }
  iVar3 = _strncmp(param_1,"FONT",4);
  if (iVar3 == 0) {
    local_8c = FUN_008be0f0(param_1,param_2);
    if (local_8c == 0) {
      FUN_008be040();
      _Src = (void *)FUN_008be080(0x20,&local_94);
      uVar4 = local_90;
      if (_Src == (void *)0x0) goto LAB_008c07df;
      FUN_008b9f80(local_90,*(undefined4 *)param_5[8]);
      _Size = (int)local_94 + 1;
      *(undefined4 *)param_5[8] = 0;
      uVar5 = FUN_008bc7d0(uVar4,1,0,_Size,0,&local_8c);
      *(undefined4 *)param_5[8] = uVar5;
      if (local_8c == 0) {
        FID_conflict__memcpy(*(void **)param_5[8],_Src,_Size);
        iVar3 = FUN_008be9f0(param_5[9]);
        if (iVar3 == 0) {
          *param_5 = *param_5 | 2;
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
    goto LAB_008c0598;
  }
  iVar3 = _strncmp(param_1,"SIZE",4);
  if (iVar3 != 0) {
    iVar3 = _strncmp(param_1,"CHARS",5);
    if (iVar3 != 0) {
LAB_008c07df:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if ((*param_5 & 8) == 0) goto LAB_008c05c6;
    *(int *)(param_5[8] + 0x28) = (int)*(short *)(param_5[8] + 0xc);
    _sprintf(local_88,"%hd",(int)*(short *)(param_5[8] + 0xc));
    local_8c = FUN_008bec60("FONT_ASCENT",local_88);
    if (local_8c == 0) {
      *(int *)(param_5[8] + 0x2c) = (int)*(short *)(param_5[8] + 0xe);
      _sprintf(local_88,"%hd",(int)*(short *)(param_5[8] + 0xe));
      iVar3 = FUN_008bec60("FONT_DESCENT",local_88);
      if (iVar3 == 0) {
        *(undefined2 *)(param_5[8] + 0x44084) = 1;
        *local_94 = FUN_008bef80;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    goto LAB_008c0598;
  }
  if ((*param_5 & 2) == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_8c = FUN_008be0f0(param_1,param_2);
  if (local_8c != 0) goto LAB_008c0598;
  uVar5 = FUN_008be520(0,10);
  *(undefined4 *)(param_5[8] + 0x10) = uVar5;
  uVar5 = FUN_008be520(0,10);
  *(undefined4 *)(param_5[8] + 0x14) = uVar5;
  uVar5 = FUN_008be520(0,10);
  *(undefined4 *)(param_5[8] + 0x18) = uVar5;
  if (param_5[0x880c] != 5) {
    *(undefined2 *)(param_5[8] + 0x44086) = 1;
    goto LAB_008c09e8;
  }
  uVar2 = FUN_008be700(0,10);
  *(undefined2 *)(param_5[8] + 0x44086) = uVar2;
  uVar1 = *(ushort *)(param_5[8] + 0x44086);
  local_90 = (uint)uVar1;
  uVar6 = 0;
  uVar8 = 0;
  if (uVar1 == 0) {
LAB_008c099b:
    local_90 = (uint)(ushort)(1 << ((byte)uVar6 & 0x1f));
  }
  else {
    do {
      if ((local_90 & 1) != 0) {
        uVar6 = uVar8;
      }
      local_90 = local_90 >> 1;
      uVar8 = uVar8 + 1;
    } while ((short)local_90 != 0);
    if (uVar6 < 4) goto LAB_008c099b;
    local_90 = 8;
  }
  uVar6 = (ushort)local_90;
  if ((uVar6 < uVar1) || (uVar1 != uVar6)) {
    *(ushort *)(param_5[8] + 0x44086) = uVar6 * 2;
    *param_5 = *param_5 | 4;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_008c09e8:
  *param_5 = *param_5 | 4;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

