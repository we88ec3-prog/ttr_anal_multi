
void FUN_008daf80(int param_1)

{
  char *_Str1;
  char *_Str;
  char *pcVar1;
  char *_Str1_00;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int in_ECX;
  int *unaff_ESI;
  char *pcVar6;
  char *local_11c;
  int local_118;
  char local_114 [10];
  char local_10a [258];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _memset(unaff_ESI,0,100);
  (*(code *)**(undefined4 **)(param_1 + 4))();
  unaff_ESI[0x12] = in_ECX;
  iVar2 = FUN_008b9850();
  iVar3 = FUN_008babe0();
  if (iVar3 == 0) {
    iVar3 = _strncmp(*(char **)(in_ECX + 0x20),"%!PS-Adobe-3.0 Resource-CIDFont",0x1f);
    FUN_008baca0();
    if (iVar3 == 0) {
LAB_008db020:
      local_11c = local_114;
      iVar3 = 0x10a;
      local_118 = FUN_008b9850(in_ECX);
      while( true ) {
        iVar4 = FUN_008b9850(in_ECX);
        iVar4 = *(int *)(in_ECX + 4) - iVar4;
        if (iVar4 == 0) {
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
        if (iVar4 <= iVar3) {
          iVar3 = iVar4;
        }
        iVar4 = FUN_008bab70(in_ECX,local_11c,iVar3);
        if (iVar4 != 0) break;
        if (iVar3 < 0x100) {
          local_11c[iVar3] = '\0';
        }
        for (pcVar6 = local_114; pcVar6 < local_11c + iVar3 + -10; pcVar6 = pcVar6 + 1) {
          if ((*pcVar6 == 'S') && (iVar4 = _strncmp(pcVar6,"StartData",9), iVar4 == 0)) {
            iVar3 = (local_118 + 10) - (int)local_114;
LAB_008db134:
            pcVar6 = pcVar6 + iVar3;
            iVar4 = (int)pcVar6 - iVar2;
            iVar3 = FUN_008b97e0(in_ECX,iVar2);
            if ((iVar3 != 0) || (iVar3 = FUN_008bc7a0(in_ECX,iVar4,unaff_ESI + 0x13), iVar3 != 0))
            goto LAB_008db2ee;
            _Str1 = (char *)unaff_ESI[0x13];
            unaff_ESI[0x15] = (int)pcVar6;
            unaff_ESI[0x14] = iVar4;
            unaff_ESI[1] = (int)_Str1;
            *unaff_ESI = (int)_Str1;
            unaff_ESI[2] = (int)(_Str1 + iVar4);
            unaff_ESI[0x18] = -1;
            (*(code *)unaff_ESI[8])();
            (*(code *)unaff_ESI[7])();
            _Str = (char *)*unaff_ESI;
            (*(code *)unaff_ESI[8])();
            (*(code *)unaff_ESI[7])();
            pcVar1 = (char *)unaff_ESI[2];
            _Str1_00 = (char *)*unaff_ESI;
            goto joined_r0x008db1d3;
          }
          if ((pcVar6[1] == 's') && (iVar4 = _strncmp(pcVar6,"/sfnts",6), iVar4 == 0)) {
            iVar3 = (local_118 + 7) - (int)local_114;
            goto LAB_008db134;
          }
        }
        FID_conflict__memcpy(local_114,pcVar6,10);
        iVar3 = 0x100;
        local_11c = local_10a;
        local_118 = local_118 + 0x100;
      }
    }
  }
LAB_008db2ee:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
joined_r0x008db1d3:
  if (pcVar1 <= _Str1_00) goto LAB_008db245;
  if (unaff_ESI[3] != 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((*_Str1_00 == 'S') && (iVar3 = _strncmp(_Str1_00,"StartData",9), iVar3 == 0)) {
    iVar2 = _strncmp(_Str1,"(Hex)",5);
    if (iVar2 == 0) {
      lVar5 = _atol(_Str);
      unaff_ESI[0x16] = lVar5;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    goto LAB_008db2ee;
  }
  if ((_Str1_00[1] == 's') && (iVar3 = _strncmp(_Str1_00,"/sfnts",6), iVar3 == 0))
  goto LAB_008db2ee;
  (*(code *)unaff_ESI[8])();
  (*(code *)unaff_ESI[7])();
  _Str1 = _Str;
  _Str = _Str1_00;
  _Str1_00 = (char *)*unaff_ESI;
  goto joined_r0x008db1d3;
LAB_008db245:
  FUN_008bab90(in_ECX,unaff_ESI + 0x13);
  iVar3 = FUN_008b97e0(in_ECX,pcVar6);
  if (iVar3 != 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  goto LAB_008db020;
}

