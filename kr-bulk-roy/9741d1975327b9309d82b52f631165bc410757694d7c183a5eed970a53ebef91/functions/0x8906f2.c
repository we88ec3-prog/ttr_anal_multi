
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008906f2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,double param_7)

{
  bool bVar1;
  int iVar2;
  money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_> *in_ECX;
  int iVar3;
  uint local_5c;
  undefined1 local_58 [16];
  undefined4 local_48;
  undefined4 local_44;
  char local_3c [52];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  bVar1 = param_7 < 0.0;
  if (bVar1) {
    param_7 = -param_7;
  }
  local_5c = 0;
  if (!NAN(param_7) && 1e+35 < param_7 != (param_7 == 1e+35)) {
    do {
      if (4999 < local_5c) break;
      local_5c = local_5c + 10;
      param_7 = param_7 / 10000000000.0;
    } while (1e+35 <= param_7);
  }
  local_44 = 0xf;
  local_48 = 0;
  local_58[0] = 0;
  local_8 = 0;
  iVar2 = _sprintf_s(local_3c,0x28,"%.0Lf");
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      FUN_00429630();
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  FUN_00429630();
  FUN_00403130(local_58);
  std::money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::_Putmfld
            (in_ECX,param_1,param_2,param_3,param_4,param_5,param_6,bVar1);
  FUN_00402f30();
  FUN_0089dbbc();
  return;
}

