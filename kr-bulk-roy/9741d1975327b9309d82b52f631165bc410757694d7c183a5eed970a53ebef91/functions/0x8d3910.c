
void FUN_008d3910(undefined4 *param_1)

{
  undefined4 uVar1;
  char *_Str1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined1 *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar1 = *param_1;
  puVar4 = (undefined1 *)param_1[2];
  local_34 = 0xa0;
  local_38 = 0;
  local_2c = puVar4;
  if (puVar4 == (undefined1 *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  _Str1 = (char *)FUN_008d1210(1,&local_30);
  if (((_Str1 == (char *)0x0) || (local_30 != 0x10)) ||
     (iVar2 = _strncmp(_Str1,"StartFontMetrics",0x10), iVar2 != 0)) {
LAB_008d3b6b:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar2 = FUN_008d1210(1,&local_30);
  do {
    if (iVar2 == 0) {
LAB_008d39f6:
      FUN_008b9f80(uVar1,*(undefined4 *)(puVar4 + 0x1c));
      *(undefined4 *)(puVar4 + 0x1c) = 0;
      *(undefined4 *)(puVar4 + 0x20) = 0;
      FUN_008b9f80(uVar1,*(undefined4 *)(puVar4 + 0x24));
      *(undefined4 *)(puVar4 + 0x24) = 0;
      *(undefined4 *)(puVar4 + 0x28) = 0;
      *puVar4 = 0;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    uVar3 = FUN_008d12a0();
    switch(uVar3) {
    case 0:
      local_28 = 2;
      iVar2 = FUN_008d3350(param_1,1);
      puVar4 = local_2c;
      if (iVar2 != 1) goto LAB_008d39f6;
      *(undefined4 *)(local_2c + 0x14) = local_24;
      break;
    case 0xe:
      local_28 = 2;
      iVar2 = FUN_008d3350(param_1,1);
      puVar4 = local_2c;
      if (iVar2 != 1) goto LAB_008d39f6;
      *(undefined4 *)(local_2c + 0x18) = local_24;
      break;
    case 0x14:
      goto switchD_008d39bd_caseD_14;
    case 0x1a:
      local_28 = 2;
      local_20 = 2;
      local_18 = 2;
      local_10 = 2;
      iVar2 = FUN_008d3350(param_1,4);
      puVar4 = local_2c;
      if (iVar2 != 4) goto LAB_008d39f6;
      *(undefined4 *)(local_2c + 4) = local_24;
      *(undefined4 *)(local_2c + 8) = local_1c;
      *(undefined4 *)(local_2c + 0xc) = local_14;
      *(undefined4 *)(local_2c + 0x10) = local_c;
      break;
    case 0x1e:
      local_28 = 4;
      iVar2 = FUN_008d3350(param_1,1);
      puVar4 = local_2c;
      if (iVar2 != 1) goto LAB_008d39f6;
      *local_2c = (undefined1)local_24;
      break;
    case 0x28:
      iVar2 = FUN_008d3490(&local_38);
      puVar4 = local_2c;
      if (iVar2 != 0) goto LAB_008d39f6;
      if ((local_38 != 0) && (local_38 != 2)) {
        local_34 = 7;
        goto LAB_008d39f6;
      }
      break;
    case 0x2d:
      local_3c = 0;
      iVar2 = FUN_008d3490(&local_3c);
      puVar4 = local_2c;
      if (iVar2 != 0) goto LAB_008d39f6;
      local_34 = FUN_008d1370(0x11);
      if (local_34 != 0) goto LAB_008d3b6b;
      break;
    case 0x31:
      local_34 = FUN_008d3840();
      puVar4 = local_2c;
      if (local_34 == 0) {
switchD_008d39bd_caseD_14:
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      goto LAB_008d39f6;
    }
    iVar2 = FUN_008d1210(1,&local_30);
    puVar4 = local_2c;
  } while( true );
}

