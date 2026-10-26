
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0089891c(byte *param_1,undefined4 *param_2,localeinfo_struct *param_3)

{
  int *piVar1;
  uint uVar2;
  FLT p_Var3;
  byte *_Str;
  localeinfo_struct local_38;
  int local_30;
  char local_2c;
  double local_28;
  _flt local_20;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_38,param_3);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_1;
  }
  _Str = param_1;
  if (param_1 == (byte *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    if (local_2c != '\0') {
      *(uint *)(local_30 + 0x70) = *(uint *)(local_30 + 0x70) & 0xfffffffd;
    }
    goto LAB_00898a30;
  }
  while( true ) {
    if ((int)(local_38.locinfo)->locale_name[3] < 2) {
      uVar2 = *(ushort *)(local_38.locinfo[1].lc_category[0].locale + (uint)*_Str * 2) & 8;
    }
    else {
      uVar2 = __isctype_l((uint)*_Str,8,&local_38);
    }
    if (uVar2 == 0) break;
    _Str = _Str + 1;
  }
  p_Var3 = __fltin2(&local_20,(char *)_Str,&local_38);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = _Str + p_Var3->nbytes;
  }
  uVar2 = p_Var3->flags;
  if ((uVar2 & 0x240) == 0) {
    if ((uVar2 & 0x81) == 0) {
      if (((uVar2 & 0x100) == 0) || (local_28 = 0.0, p_Var3->dval != 0.0)) {
        local_28 = p_Var3->dval;
        goto LAB_00898a20;
      }
    }
    else {
      local_28 = _DAT_00d61ef0;
      if (*_Str == 0x2d) {
        local_28 = -_DAT_00d61ef0;
      }
    }
    piVar1 = __errno();
    *piVar1 = 0x22;
  }
  else {
    local_28 = 0.0;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
  }
LAB_00898a20:
  if (local_2c != '\0') {
    *(uint *)(local_30 + 0x70) = *(uint *)(local_30 + 0x70) & 0xfffffffd;
  }
LAB_00898a30:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

